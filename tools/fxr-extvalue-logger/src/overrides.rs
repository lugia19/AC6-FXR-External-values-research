//! External value overrides: the read hook (0x142b56480) can hand an effect a value its own block doesn't have.
//!
//! Rules come from Game\debug-logs\fxr_extvalues_overrides.txt, reloaded while the game runs:
//!   <id|*> mirror [max|min|latest]       value spawners set for that ID (copies between blocks ignored). Several
//!                                        blocks write most IDs (one per thruster, per character...): max/min take
//!                                        the largest/smallest over the blocks that wrote in the last 0.25 s
//!                                        (default max), latest the most recent write from any block.
//!   <id|*> const <value>
//!   <id|*> sweep <min> <max> <seconds>   triangle wave min -> max -> min
//!   <id|*> step <min> <max> <step> <seconds>   min, min + step, ... max, one step per <seconds>, looping
//! A rule applies when nothing has written the ID into the effect's block; add "force" at the end to apply it
//! always.
//! A specific ID's rule wins over "*", and "*" never covers ID 0 (terminate).

use std::collections::{HashMap, HashSet};
use std::path::Path;
use std::sync::atomic::{AtomicBool, AtomicI64, AtomicU32, AtomicU64, Ordering};
use std::sync::{Mutex, OnceLock, RwLock};
use std::time::{Instant, SystemTime};

const DEFAULT_RULES: &str = "\
# FXR external value overrides (fxr-extvalue-logger). Reloaded while the game runs.
# A rule applies when an effect asks for an ID its own value block doesn't have; add \"force\" to always apply it.
#   <id|*> mirror [max|min|latest]       value spawners set for that ID: max/min over the blocks that wrote it in
#                                        the last 0.25 s (default max), or the latest write from any block
#   <id|*> const <value>
#   <id|*> sweep <min> <max> <seconds>   triangle wave
#   <id|*> step <min> <max> <step> <seconds>   min, min + step, ... max, one step per <seconds>, looping
# A specific ID's rule wins over \"*\", and \"*\" never covers 0 (terminate). Lines starting with # are ignored.
* mirror
";

#[derive(Clone, Copy, Debug)]
enum Aggregate {
    Max,
    Min,
    Latest,
}

#[derive(Clone, Copy, Debug)]
enum Mode {
    Mirror(Aggregate),
    Const(f32),
    Sweep { min: f32, max: f32, period: f32 },
    Step { min: f32, max: f32, step: f32, interval: f32 },
}

#[derive(Clone, Copy, Debug)]
struct Rule {
    mode: Mode,
    force: bool,
}

#[derive(Default)]
struct Rules {
    by_id: HashMap<i32, Rule>,
    any: Option<Rule>,
}

static RULES: OnceLock<RwLock<Rules>> = OnceLock::new();
static HAVE_RULES: AtomicBool = AtomicBool::new(false);
static START: OnceLock<Instant> = OnceLock::new();

// Lock-free table of the mirrored values per ID (f32 bits), updated from the set hook and read by the get hook.
const SLOTS: usize = 1024;
const EMPTY: i64 = i64::MIN;
struct Slot {
    id: AtomicI64,
    latest: AtomicU32,
    max: AtomicU32,
    min: AtomicU32,
    seen: AtomicBool,
    served: AtomicU64,
}
static TABLE: OnceLock<Vec<Slot>> = OnceLock::new();

fn table() -> &'static [Slot] {
    TABLE.get_or_init(|| {
        (0..SLOTS)
            .map(|_| Slot {
                id: AtomicI64::new(EMPTY),
                latest: AtomicU32::new(0),
                max: AtomicU32::new(0),
                min: AtomicU32::new(0),
                seen: AtomicBool::new(false),
                served: AtomicU64::new(0),
            })
            .collect()
    })
}

// Recent writes per ID and source block, for max/min.
const FRESH: f32 = 0.25;
const FORGET: f32 = 1.0;
static SOURCES: OnceLock<Mutex<HashMap<i32, Vec<(usize, f32, Instant)>>>> = OnceLock::new();

fn slot(id: i32) -> Option<&'static Slot> {
    let t = table();
    let mut i = (id as u32).wrapping_mul(2654435761) as usize % SLOTS;
    for _ in 0..SLOTS {
        let s = &t[i];
        let cur = s.id.load(Ordering::Acquire);
        if cur == id as i64 {
            return Some(s);
        }
        if cur == EMPTY {
            match s.id.compare_exchange(EMPTY, id as i64, Ordering::AcqRel, Ordering::Acquire) {
                Ok(_) => return Some(s),
                Err(other) if other == id as i64 => return Some(s),
                Err(_) => {}
            }
        }
        i = (i + 1) % SLOTS;
    }
    None
}

/// Called from the set hook for writes made by spawners (not the game's block-to-block copies).
pub fn record(block: usize, id: i32, value: u32) {
    let Some(s) = slot(id) else { return };
    s.latest.store(value, Ordering::Relaxed);
    let now = Instant::now();
    let v = f32::from_bits(value);
    let (mut max, mut min) = (v, v);
    if let Ok(mut sources) = SOURCES.get_or_init(|| Mutex::new(HashMap::new())).lock() {
        let list = sources.entry(id).or_default();
        list.retain(|&(b, _, t)| b != block && now.duration_since(t).as_secs_f32() < FORGET);
        for &(_, other, t) in list.iter() {
            if now.duration_since(t).as_secs_f32() < FRESH {
                max = max.max(other);
                min = min.min(other);
            }
        }
        list.push((block, v, now));
    }
    s.max.store(max.to_bits(), Ordering::Relaxed);
    s.min.store(min.to_bits(), Ordering::Relaxed);
    s.seen.store(true, Ordering::Release);
}

// Which IDs actually got written into each block. An effect's own block has a slot for every ID its FXR header
// declares, written or not, so "the block contains the ID" doesn't mean anything provides it.
static PROVIDED: OnceLock<RwLock<HashMap<usize, HashSet<i32>>>> = OnceLock::new();

fn provided_map() -> &'static RwLock<HashMap<usize, HashSet<i32>>> {
    PROVIDED.get_or_init(|| RwLock::new(HashMap::new()))
}

/// Called from the set hook for every write, copies included.
pub fn mark_provided(block: usize, id: i32) {
    let map = provided_map();
    if map.read().is_ok_and(|m| m.get(&block).is_some_and(|ids| ids.contains(&id))) {
        return;
    }
    if let Ok(mut m) = map.write() {
        m.entry(block).or_default().insert(id);
    }
}

/// Called when a block address starts belonging to something new (registration, new effect instance).
pub fn forget_block(block: usize) {
    if let Ok(mut m) = provided_map().write() {
        m.remove(&block);
    }
}

pub fn is_provided(block: usize, id: i32) -> bool {
    provided_map().read().is_ok_and(|m| m.get(&block).is_some_and(|ids| ids.contains(&id)))
}

pub fn have_rules() -> bool {
    HAVE_RULES.load(Ordering::Relaxed)
}

/// Returns the override for `id`, if a rule applies. `present` = something wrote the ID into the effect's block.
pub fn lookup(id: i32, present: bool) -> Option<f32> {
    if !HAVE_RULES.load(Ordering::Relaxed) {
        return None;
    }
    let rule = {
        let rules = RULES.get()?.read().ok()?;
        // "*" never covers 0: it's the terminate signal, and mirroring it would end effects whenever any other
        // effect ends. An explicit "0 ..." rule still applies.
        match rules.by_id.get(&id) {
            Some(rule) => *rule,
            None if id != 0 => *rules.any.as_ref()?,
            None => return None,
        }
    };
    if present && !rule.force {
        return None;
    }
    let value = match rule.mode {
        Mode::Mirror(aggregate) => {
            let s = slot(id)?;
            if !s.seen.load(Ordering::Acquire) {
                return None;
            }
            let bits = match aggregate {
                Aggregate::Max => &s.max,
                Aggregate::Min => &s.min,
                Aggregate::Latest => &s.latest,
            };
            f32::from_bits(bits.load(Ordering::Relaxed))
        }
        Mode::Const(v) => v,
        Mode::Sweep { min, max, period } => {
            let t = START.get_or_init(Instant::now).elapsed().as_secs_f32();
            let phase = (t / period.max(0.01)).fract();
            let tri = if phase < 0.5 { phase * 2.0 } else { 2.0 - phase * 2.0 };
            min + (max - min) * tri
        }
        Mode::Step { min, max, step, interval } => {
            // min, min + step, ... up to max (inclusive), one step per interval, then back to min.
            let t = START.get_or_init(Instant::now).elapsed().as_secs_f32();
            let steps = ((max - min) / step.max(f32::EPSILON)).floor() as u64 + 1;
            let index = (t / interval.max(0.01)) as u64 % steps;
            min + step * index as f32
        }
    };
    if let Some(s) = slot(id) {
        s.served.fetch_add(1, Ordering::Relaxed);
    }
    Some(value)
}

fn parse(text: &str) -> (Rules, Vec<String>) {
    let mut rules = Rules::default();
    let mut errors = Vec::new();
    for line in text.lines() {
        let line = line.trim();
        if line.is_empty() || line.starts_with('#') {
            continue;
        }
        let mut words: Vec<&str> = line.split_whitespace().collect();
        let force = words.last() == Some(&"force");
        if force {
            words.pop();
        }
        let num = |i: usize| words.get(i).and_then(|w| w.parse::<f32>().ok());
        let mode = match (words.get(1).copied(), words.len()) {
            (Some("mirror"), 2) => Some(Mode::Mirror(Aggregate::Max)),
            (Some("mirror"), 3) => match words[2] {
                "max" => Some(Mode::Mirror(Aggregate::Max)),
                "min" => Some(Mode::Mirror(Aggregate::Min)),
                "latest" => Some(Mode::Mirror(Aggregate::Latest)),
                _ => None,
            },
            (Some("const"), 3) => num(2).map(Mode::Const),
            (Some("sweep"), 5) => match (num(2), num(3), num(4)) {
                (Some(min), Some(max), Some(period)) => Some(Mode::Sweep { min, max, period }),
                _ => None,
            },
            (Some("step"), 6) => match (num(2), num(3), num(4), num(5)) {
                (Some(min), Some(max), Some(step), Some(interval)) if step > 0.0 && max >= min => {
                    Some(Mode::Step { min, max, step, interval })
                }
                _ => None,
            },
            _ => None,
        };
        let Some(mode) = mode else {
            errors.push(line.to_string());
            continue;
        };
        let rule = Rule { mode, force };
        match words[0] {
            "*" => rules.any = Some(rule),
            w => match w.parse::<i32>() {
                Ok(id) => {
                    rules.by_id.insert(id, rule);
                }
                Err(_) => errors.push(line.to_string()),
            },
        }
    }
    (rules, errors)
}

/// Loads the rules file if it changed since `last` (creating it with the default rules if missing). Returns a log
/// message when something was (re)loaded.
pub fn reload(path: &Path, last: &mut Option<SystemTime>) -> Option<String> {
    START.get_or_init(Instant::now);
    if !path.exists() {
        let _ = std::fs::write(path, DEFAULT_RULES);
    }
    let modified = std::fs::metadata(path).and_then(|m| m.modified()).ok();
    if modified.is_some() && modified == *last {
        return None;
    }
    *last = modified;
    let text = std::fs::read_to_string(path).ok()?;
    let (rules, errors) = parse(&text);
    let summary = format!(
        "override rules loaded: {} by ID{}{}",
        rules.by_id.len(),
        if rules.any.is_some() { " + *" } else { "" },
        if errors.is_empty() { String::new() } else { format!(", ignored bad lines: {}", errors.join(" | ")) }
    );
    HAVE_RULES.store(!rules.by_id.is_empty() || rules.any.is_some(), Ordering::Relaxed);
    let lock = RULES.get_or_init(|| RwLock::new(Rules::default()));
    if let Ok(mut r) = lock.write() {
        *r = rules;
    }
    Some(summary)
}

/// TSV of every ID seen: the mirrored values (latest / max / min over fresh sources) and how many times an override
/// was served.
pub fn served_report() -> String {
    let mut rows: Vec<&Slot> = table().iter().filter(|s| s.id.load(Ordering::Relaxed) != EMPTY).collect();
    rows.sort_by_key(|s| s.id.load(Ordering::Relaxed));
    let mut out = String::from("id\tlatest\tmax\tmin\toverrides_served\n");
    for s in rows {
        let value = |a: &AtomicU32| {
            if s.seen.load(Ordering::Relaxed) {
                f32::from_bits(a.load(Ordering::Relaxed)).to_string()
            } else {
                String::from("-")
            }
        };
        out += &format!(
            "{}\t{}\t{}\t{}\t{}\n",
            s.id.load(Ordering::Relaxed),
            value(&s.latest),
            value(&s.max),
            value(&s.min),
            s.served.load(Ordering::Relaxed)
        );
    }
    out
}
