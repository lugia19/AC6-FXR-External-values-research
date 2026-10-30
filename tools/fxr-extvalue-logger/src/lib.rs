//! Logs FXR external values in Armored Core VI 1.09.1 (see Research\FXR external values\notes.md).
//!
//! Hooks:
//! - 0x142b56080 register: a spawner creates a value block for a list of external value IDs
//! - 0x142b566d0 set: a value is written to a block
//! - 0x142b5ce00 attach: a block is attached to an effect instance (FXR ID at instance+0). The first attach builds
//!   the instance's own blocks (+0x48 / +0x50, from the FXR header's two external value lists), which get the values
//!   copied into them; those are tagged with the FXR ID too.
//! - 0x142b56480 get: an effect reads a value from its block (0 if the block doesn't have the ID). Overrides from
//!   fxr_extvalues_overrides.txt are applied here (see overrides.rs); by default every ID nothing provides to the
//!   effect is mirrored from what spawners set for it elsewhere (max over recent writers).
//!
//! Writes to Game\debug-logs\:
//! - fxr_extvalues_events.tsv: registrations, attaches, and value changes (throttled per block and ID)
//! - fxr_extvalues_summary.tsv: per (ID, registering caller, setting caller): FXRs, blocks, sets, min, max, last
//! - fxr_extvalues_overrides_served.tsv: per ID, the latest spawner value and how many overrides were served
//! Caller addresses are return addresses, so they point just after the call in the game code. Times are seconds since
//! the DLL loaded; the first line has the wall-clock start time (Unix ms) for syncing with recordings.

use std::collections::{BTreeSet, HashMap};
use std::fs::File;
use std::io::{BufWriter, Write};
use std::path::PathBuf;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::{Mutex, OnceLock};
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};

use retour::RawDetour;

mod overrides;

const REGISTER_ADDR: usize = 0x142b56080;
const SET_ADDR: usize = 0x142b566d0;
const ATTACH_ADDR: usize = 0x142b5ce00;
const GET_ADDR: usize = 0x142b56480;
// mov [rsp+18],r8 / mov [rsp+18],r8d / mov [rsp+10],rdx / mov [rsp+18],r8d
const REGISTER_PROLOGUE: [u8; 5] = [0x4c, 0x89, 0x44, 0x24, 0x18];
const SET_PROLOGUE: [u8; 5] = [0x44, 0x89, 0x44, 0x24, 0x18];
const ATTACH_PROLOGUE: [u8; 5] = [0x48, 0x89, 0x54, 0x24, 0x10];
const GET_PROLOGUE: [u8; 5] = [0x44, 0x89, 0x44, 0x24, 0x18];
// Return address of the set call in FUN_142b56630, the game's block-to-block copy: not a spawner's own write.
const COPY_SET_RET: usize = 0x142b566c0;

// Changes to the same (block, id) are logged at most this often, except flips to or from 0.
const EVENT_INTERVAL: f64 = 0.5;

static ORIG_REGISTER: AtomicUsize = AtomicUsize::new(0);
static ORIG_SET: AtomicUsize = AtomicUsize::new(0);
static ORIG_ATTACH: AtomicUsize = AtomicUsize::new(0);
static ORIG_GET: AtomicUsize = AtomicUsize::new(0);
static STATE: OnceLock<Mutex<State>> = OnceLock::new();

#[derive(Default)]
struct Block {
    reg_caller: usize,
    fxrs: BTreeSet<i32>,
    // id -> (last value bits, time last logged)
    last: HashMap<i32, (u32, f64)>,
}

struct Stat {
    fxrs: BTreeSet<i32>,
    blocks: u64,
    sets: u64,
    min: f32,
    max: f32,
    last: f32,
}

struct State {
    start: Instant,
    dir: PathBuf,
    events: BufWriter<File>,
    blocks: HashMap<usize, Block>,
    // instance address -> FXR ID
    instances: HashMap<usize, i32>,
    summary: HashMap<(i32, usize, usize), Stat>,
}

impl State {
    fn now(&self) -> f64 {
        self.start.elapsed().as_secs_f64()
    }

    fn write_summary(&self) {
        let mut rows: Vec<_> = self.summary.iter().collect();
        rows.sort_by_key(|((id, reg, set), _)| (*id, *reg, *set));
        let mut out = String::from("id\treg_caller\tset_caller\tfxrs\tblocks\tsets\tmin\tmax\tlast\n");
        for ((id, reg, set), s) in rows {
            out += &format!(
                "{id}\t{reg:#x}\t{set:#x}\t{}\t{}\t{}\t{}\t{}\t{}\n",
                join(&s.fxrs),
                s.blocks,
                s.sets,
                s.min,
                s.max,
                s.last
            );
        }
        let _ = std::fs::write(self.dir.join("fxr_extvalues_summary.tsv"), out);
    }
}

fn join(set: &BTreeSet<i32>) -> String {
    set.iter().map(|f| f.to_string()).collect::<Vec<_>>().join(",")
}

fn state() -> Option<std::sync::MutexGuard<'static, State>> {
    STATE.get()?.lock().ok()
}

// Entry stubs: pass the return address as an extra argument (the first unused argument register) and tail-jump, so
// the impl returns straight to the game's caller.
#[unsafe(naked)]
unsafe extern "system" fn register_entry() {
    core::arch::naked_asm!("mov r9, [rsp]", "jmp {}", sym register_impl);
}

#[unsafe(naked)]
unsafe extern "system" fn set_entry() {
    core::arch::naked_asm!("mov r9, [rsp]", "jmp {}", sym set_impl);
}

#[unsafe(naked)]
unsafe extern "system" fn attach_entry() {
    core::arch::naked_asm!("mov r8, [rsp]", "jmp {}", sym attach_impl);
}

unsafe extern "system" fn get_impl(block: *mut u8, out: *mut u32, id: i32) -> *mut u32 {
    let orig: unsafe extern "system" fn(*mut u8, *mut u32, i32) -> *mut u32 =
        unsafe { std::mem::transmute(ORIG_GET.load(Ordering::Relaxed)) };
    let result = unsafe { orig(block, out, id) };
    if block.is_null() || out.is_null() || !overrides::have_rules() {
        return result;
    }
    // Some values reach effect blocks without going through the hooked setter (the terminate signal, ID 0, does),
    // so a non-zero value counts as provided too: unprovided slots stay 0.
    let present = unsafe { *out != 0 } || overrides::is_provided(block as usize, id);
    if let Some(v) = overrides::lookup(id, present) {
        unsafe { *out = v.to_bits() };
    }
    result
}

unsafe extern "system" fn register_impl(ids: *const i32, count: i32, manager: *mut u8, ret: usize) -> *mut u8 {
    let orig: unsafe extern "system" fn(*const i32, i32, *mut u8) -> *mut u8 =
        unsafe { std::mem::transmute(ORIG_REGISTER.load(Ordering::Relaxed)) };
    let block = unsafe { orig(ids, count, manager) };
    if block.is_null() || ids.is_null() || !(1..=64).contains(&count) {
        return block;
    }
    let id_list = unsafe { std::slice::from_raw_parts(ids, count as usize) }.to_vec();
    if let Some(mut st) = state() {
        let t = st.now();
        let ids_str: Vec<String> = id_list.iter().map(|i| i.to_string()).collect();
        let line = format!("{t:.3}\tREG\t{:#x}\t{ret:#x}\t\t\t{}\t\n", block as usize, ids_str.join(","));
        let _ = st.events.write_all(line.as_bytes());
        // A new block at a reused address starts over.
        st.blocks.insert(block as usize, Block { reg_caller: ret, ..Default::default() });
        overrides::forget_block(block as usize);
    }
    block
}

/// The IDs a value block holds. Layout: +8 sorted ID array, +0x18 count.
unsafe fn block_ids(block: *mut u8) -> Vec<i32> {
    unsafe {
        let ids = *(block.add(8) as *const *const i32);
        let count = *(block.add(0x18) as *const u32) as usize;
        if ids.is_null() || count > 4096 {
            return Vec::new();
        }
        std::slice::from_raw_parts(ids, count).to_vec()
    }
}

unsafe extern "system" fn attach_impl(instance: *mut u8, block: *mut u8, ret: usize) -> u8 {
    let orig: unsafe extern "system" fn(*mut u8, *mut u8) -> u8 =
        unsafe { std::mem::transmute(ORIG_ATTACH.load(Ordering::Relaxed)) };
    let result = unsafe { orig(instance, block) };
    if instance.is_null() || block.is_null() {
        return result;
    }
    let fxr = unsafe { *(instance as *const i32) };
    let internal = unsafe { [*(instance.add(0x48) as *const usize), *(instance.add(0x50) as *const usize)] };
    let Some(mut st) = state() else { return result };
    let t = st.now();
    let st = &mut *st;
    let b = st.blocks.entry(block as usize).or_default();
    if b.fxrs.insert(fxr) {
        let reg_caller = b.reg_caller;
        let line = format!(
            "{t:.3}\tATTACH\t{:#x}\t{reg_caller:#x}\t{ret:#x}\t{fxr}\tinternal={:#x},{:#x}\t\n",
            block as usize, internal[0], internal[1]
        );
        let _ = st.events.write_all(line.as_bytes());
    }
    // The instance's own blocks aren't created through the register function, so a reused address would keep the
    // previous effect's tag: start them over whenever a new (instance, FXR) pair shows up.
    let new_instance = st.instances.insert(instance as usize, fxr) != Some(fxr);
    for ib in internal {
        if ib != 0 {
            let entry = st.blocks.entry(ib).or_default();
            if new_instance {
                *entry = Block::default();
                // The first attach already copied the spawner's values in (inside orig): what was copied is every
                // ID both blocks have.
                overrides::forget_block(ib);
                let source = unsafe { block_ids(block) };
                for id in unsafe { block_ids(ib as *mut u8) } {
                    if source.contains(&id) {
                        overrides::mark_provided(ib, id);
                    }
                }
            }
            entry.fxrs.insert(fxr);
        }
    }
    result
}

unsafe extern "system" fn set_impl(block: *mut u8, id: i32, value: u32, ret: usize) {
    let orig: unsafe extern "system" fn(*mut u8, i32, u32) =
        unsafe { std::mem::transmute(ORIG_SET.load(Ordering::Relaxed)) };
    unsafe { orig(block, id, value) };
    if ret != COPY_SET_RET {
        overrides::record(block as usize, id, value);
    }
    overrides::mark_provided(block as usize, id);
    let Some(mut st) = state() else { return };
    let t = st.now();
    let st = &mut *st;
    let b = st.blocks.entry(block as usize).or_default();
    let reg_caller = b.reg_caller;
    let v = f32::from_bits(value);

    let first_for_block = !b.last.contains_key(&id);
    let log = match b.last.get(&id) {
        None => true,
        Some(&(prev, logged)) => {
            prev != value && (t - logged >= EVENT_INTERVAL || prev == 0 || value == 0 || prev == 0x8000_0000)
        }
    };
    match b.last.get_mut(&id) {
        Some(entry) if !log => entry.0 = value,
        _ => {
            b.last.insert(id, (value, t));
        }
    }
    let fxrs = b.fxrs.clone();
    if log {
        let line = format!(
            "{t:.3}\tSET\t{:#x}\t{reg_caller:#x}\t{ret:#x}\t{}\t{id}\t{v}\n",
            block as usize,
            join(&fxrs)
        );
        let _ = st.events.write_all(line.as_bytes());
    }

    let s = st.summary.entry((id, reg_caller, ret)).or_insert(Stat {
        fxrs: BTreeSet::new(),
        blocks: 0,
        sets: 0,
        min: f32::INFINITY,
        max: f32::NEG_INFINITY,
        last: 0.0,
    });
    s.fxrs.extend(fxrs);
    if first_for_block {
        s.blocks += 1;
    }
    s.sets += 1;
    s.min = s.min.min(v);
    s.max = s.max.max(v);
    s.last = v;
}

fn prologue_ok(addr: usize, expected: &[u8; 5]) -> bool {
    unsafe { std::slice::from_raw_parts(addr as *const u8, 5) == expected }
}

fn prologues_ok() -> bool {
    prologue_ok(REGISTER_ADDR, &REGISTER_PROLOGUE)
        && prologue_ok(SET_ADDR, &SET_PROLOGUE)
        && prologue_ok(ATTACH_ADDR, &ATTACH_PROLOGUE)
        && prologue_ok(GET_ADDR, &GET_PROLOGUE)
}

fn install_hooks() -> Result<(), String> {
    // The get hook needs no return address, so it goes straight to its impl.
    let hooks: [(usize, *const (), &AtomicUsize); 4] = [
        (REGISTER_ADDR, register_entry as *const (), &ORIG_REGISTER),
        (SET_ADDR, set_entry as *const (), &ORIG_SET),
        (ATTACH_ADDR, attach_entry as *const (), &ORIG_ATTACH),
        (GET_ADDR, get_impl as *const (), &ORIG_GET),
    ];
    let mut detours = Vec::new();
    for (target, detour, orig) in hooks {
        let d = unsafe { RawDetour::new(target as *const (), detour) }.map_err(|e| e.to_string())?;
        orig.store(d.trampoline() as *const () as usize, Ordering::Relaxed);
        detours.push(d);
    }
    for d in &detours {
        unsafe { d.enable() }.map_err(|e| e.to_string())?;
    }
    // Hooks stay installed for the life of the process.
    std::mem::forget(detours);
    Ok(())
}

fn log_line(msg: &str) {
    if let Some(mut st) = state() {
        let t = st.now();
        let _ = st.events.write_all(format!("{t:.3}\tINFO\t\t\t\t\t\t{msg}\n").as_bytes());
        let _ = st.events.flush();
    }
}

fn hook_when_ready() {
    // me3 normally loads natives before the game runs, so the first try should succeed. If the code isn't there yet
    // (or this is the wrong exe version), keep checking for a minute.
    let deadline = Instant::now() + Duration::from_secs(60);
    loop {
        if prologues_ok() {
            match install_hooks() {
                Ok(()) => log_line("hooks installed"),
                Err(e) => log_line(&format!("hook install failed: {e}")),
            }
            return;
        }
        if Instant::now() > deadline {
            log_line("prologues never matched (not 1.09.1?), no hooks installed");
            return;
        }
        std::thread::sleep(Duration::from_millis(250));
    }
}

fn init() {
    let dir = std::env::current_exe()
        .ok()
        .and_then(|p| p.parent().map(|p| p.join("debug-logs")))
        .unwrap_or_else(|| PathBuf::from("debug-logs"));
    let _ = std::fs::create_dir_all(&dir);
    let Ok(file) = File::create(dir.join("fxr_extvalues_events.tsv")) else { return };
    let mut events = BufWriter::new(file);
    let _ = events.write_all(b"time\tkind\tblock\treg_caller\tset_caller\tfxrs\tid\tvalue\n");
    let _ = STATE.set(Mutex::new(State {
        start: Instant::now(),
        dir,
        events,
        blocks: HashMap::new(),
        instances: HashMap::new(),
        summary: HashMap::new(),
    }));
    let unix_ms = SystemTime::now().duration_since(UNIX_EPOCH).map(|d| d.as_millis()).unwrap_or(0);
    log_line(&format!("start unix_ms={unix_ms}"));

    if prologues_ok() {
        match install_hooks() {
            Ok(()) => log_line("hooks installed at load"),
            Err(e) => log_line(&format!("hook install failed: {e}")),
        }
    } else {
        std::thread::spawn(hook_when_ready);
    }

    let rules_path = STATE.get().and_then(|s| s.lock().ok()).map(|s| s.dir.join("fxr_extvalues_overrides.txt"));
    let mut rules_modified = None;
    if let Some(msg) = rules_path.as_ref().and_then(|p| overrides::reload(p, &mut rules_modified)) {
        log_line(&msg);
    }

    std::thread::spawn(move || {
        let mut tick = 0u64;
        loop {
            std::thread::sleep(Duration::from_secs(1));
            tick += 1;
            if let Some(msg) = rules_path.as_ref().and_then(|p| overrides::reload(p, &mut rules_modified)) {
                log_line(&msg);
            }
            if tick % 2 == 0 {
                if let Some(mut st) = state() {
                    let _ = st.events.flush();
                    st.write_summary();
                    let _ = std::fs::write(st.dir.join("fxr_extvalues_overrides_served.tsv"), overrides::served_report());
                }
            }
        }
    });
}

#[unsafe(no_mangle)]
extern "system" fn DllMain(_module: *mut u8, reason: u32, _reserved: *mut u8) -> i32 {
    const DLL_PROCESS_ATTACH: u32 = 1;
    if reason == DLL_PROCESS_ATTACH {
        init();
    }
    1
}
