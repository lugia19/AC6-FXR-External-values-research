# FXR external values in Armored Core VI

Research from 2026-10-30 on AC6 **1.09.1** (regulation 10910042): what the external values that FXR modifiers
and state conditions read actually are, how the game delivers them, and the tools used to find out. Addresses are
for the 1.09.1 exe (image base 0x140000000, no ASLR). The de-Arxaned copy used in Ghidra is byte-identical at
every function listed here.

## Summary

- **An external value has no global meaning.** The code that spawns an effect (a "spawner": the thruster system,
  pulse armor, the bullet system...) creates a value block with *its own* list of IDs, fills in the values, and
  attaches the block to the effects it spawns. The same ID can mean different things depending on the spawner.
- **An effect only receives the IDs its FXR header declares,** and only if its spawner provides them. Anything
  else reads as 0. This is why most of these IDs were documented as `UnkN`: the FXR files can't tell you what
  they are, and spawning an effect any other way (a different weapon, an animation event, a debug tool) gives 0.
- Several AC6 IDs are now identified (table below). Others were seen at runtime, but their meaning is still open.

## How the game delivers external values

### The pieces

| Function | Signature (as used) | Role |
|---|---|---|
| `0x142b56080` | `block = register(int *ids, int count, manager)` | A spawner creates a value block for its ID list |
| `0x142b566d0` | `set(block, int id, float value)` | Writes a value; does nothing if `id` isn't in the block. The float arrives as raw bits in R8D |
| `0x1416246f0` | `spawn(manager, handle_out, int *fxr_id, transform, block, ...)` | Creates an effect by FXR ID (via `0x14269af20` → `0x1426a1ea0`) and attaches `block` |
| `0x142b50b00` | `attach(handle, block)` | Handle `+8` = effect instance, calls `0x142b5ce00` |
| `0x142b5ce00` | `attach_instance(instance, block)` | First call builds the instance's own blocks; every call copies matching values in |
| `0x142b5d540` | (recursive) | Reads the FXR header's ID lists for the instance's FXR and its child FXRs |
| `0x142b56630` | `copy(dst_block, src_block)` | Copies values for IDs present in both blocks (its set call returns to `0x142b566c0`) |
| `0x142b56480` | `float *get(block, float *out, int id)` | How effects read a value; writes 0 if the block lacks the ID. Called from the modifier evaluators around `0x142b74xxx` / `0x142c3dxxx` |
| `0x142b56590` | `bool has(block, int id)` | |

### Data layouts

- **Value block** (0x20 bytes): `+0x08` pointer to a sorted `int` ID array, `+0x10` pointer to the `float` values,
  `+0x18` count.
- **Effect instance:** `+0x00` FXR ID (int), `+0x38` the FXR repository the header lookup uses, `+0x48` / `+0x50`
  the instance's own value blocks, built from the header's list 1 / list 2. `+0x80` bit `0x10` = those blocks exist.
- **FXR header** (version 5): `+0x70/+0x74` referenced child FXR IDs (offset/count), `+0x78/+0x7c` external value
  list 1, `+0x80/+0x84` external value list 2. `@cccode/fxr`'s writer fills both lists from the modifiers and state
  conditions it writes (`getReferences()`); its reader skips them.

### Flow

1. A spawner registers a block with its ID list (`register`) and keeps it.
2. It spawns an effect with an FXR ID from its param (e.g. `EquipParamWeapon.paOnSfxId`) and passes the block.
3. On the first attach, the game reads the FXR's header lists (recursing into child FXRs) and creates the
   instance's own blocks with exactly those IDs, all 0. It then copies over the values for IDs that both blocks have.
4. Each update, the spawner writes new values (`set`) and attaches again, which copies them over again.
5. Modifiers and state conditions read from the instance's blocks (`get`). IDs nobody provides stay 0.

Generic code paths also attach blocks to most effects: `0x141625930` provides `{2000}` and `0x141628270`
provides `{0, 10000, 30000, 30001, 3}`. That's why 2000 (camera distance) works almost everywhere.

**Termination (ID 0) reaches effect blocks some other way.** It doesn't go through `set`. A test override that
forced ID 0 to 0 whenever no `set` call had written it stopped effects from ever ending.

## AC6 external values

"Spawner" is where the registration happens (return address in the logger output / function).
"Read by" are game FXRs that use the ID in a modifier or state condition (from the scan of all 5279 FXRs).

| ID | Meaning | Spawner | Range seen | Read by | Confidence |
|---|---|---|---|---|---|
| 0 | Terminate (known) | generic `0x141628270` | 0/1 | 3778 FXRs in state conditions, 437 in modifiers | known |
| **1** | **Character fade/opacity**, probably | `0x140927b60` registers `{60000, 1}`; value = `[[chr+0x58]+0x18]+0x234` (`0x1410f50f0`), 1.0 if `chr+0x58` is null | 0–1; 1 almost always, ramps 0→1 when the AC is placed at mission start | 600010/600011/632560/632561/890110/7032013-19 (colors); SpEffectVfx on PCA Light Cavalry, Xylem Flying MT | probable: the field isn't named in code |
| 3 | Global flag | `0x14162aca0`: 1.0 while a global float (`[0x144f30f38]+0x2d8`) is at or below a threshold, with hysteresis and a countdown | always 0 in our runs | 331 FXRs (`External(3) >= 1`): bullets, ricochets, hit effects, thrusters, asset breaks | mechanism known, meaning not |
| 1000 | ? | no setter found | – | 806000 only | unknown, maybe unused |
| 2000 | Camera distance in meters (known) | generic `0x141625930` | 7–468 | ~340 FXRs | confirmed |
| 10000 | ? (blood setting in other games) | generic `0x141628270` | always 0 | – | unknown |
| 20000 | Grass-related: `max(a, b)` of two floats | `0x14137a3a0` / `0x14137d953` | not seen | 800063 (GrassTypeParam[90]) | unknown |
| 30000, 30001 | ? | generic `0x141628270`; also `0x140c517d0` | always 1 | – | unknown |
| **40000** | **Booster output %** | thruster system `0x140937aa1` / `0x140937cc0`; thruster controller `+0x4a4` × 100 | 0–100 | 90303, 90311 (speed/size, orange→blue color) | confirmed (code + bar chart) |
| **40001** | **Speed ÷ max speed (0–1)** | same; controller `+0x4a8` from `0x140854c00` | 0–1; pins at 1 on jumps and quick boosts | – | confirmed (code + bar chart); which field is the max is a reading of the code |
| 40002 | Thruster angle in degrees (0–90) | same; controller `+0x4ac` × 57.2958 | always 0 | – | mechanism known, never seen non-zero |
| 50000, 50001 | ? (0–100) | foot system `0x140928494` / `0x140927b60`, attached to FootSfxParam effects | 0–100 | – | unknown |
| **60000** | **Character speed in km/h** | same as 50000 (also `{60000, 1}` above); `|v| × 60 × 60 / 1000` | 0–738 | – | confirmed |
| **70000** | **Pulse armor / shield radius in meters** (pulse armor spawners) | `0x1408a14b0`, `0x1408a74f0`, `0x1408a11c0` | 9.5 while up, 0 when broken | 990080-82, 990180-82 | confirmed: = `MakeCollisionPaOpenRadius` (Pulse Armor, Terminal Armor); Pulse Protection has `stayPa_Radius` 50 |
| 70000 | Capsule radius (capsule spawners, below) | `0x1406887c0` / `0x1406a16a0`, `0x140873610` / `0x14087aca0` | not seen | – | code only |
| 70010 | Capsule length between the end caps (length − 2 × radius) | same capsule spawners; also `0x14092ef27` | not seen | NPC `AtkParam.hit0_SfxId` effects (RaD Spider MT, Balteus, Sea Spider, Strider, IB-07...), 653000 | code only |
| 70020 | Speed in km/h (capsule spawner 1) | `0x1406a16a0` | not seen | 300031 (bomb projectile: spin speed) | code only |
| 70030 | Flag 0/1 (capsule spawner 2) | `0x14087aca0`; also `0x14092ef27` (constant 1.0) | not seen | – | code only |
| 70100 | ? | `0x14161ef60` / `0x14161f7f7` | not seen | – | unknown |
| 70200 | Scan distance (known) | `0x1408e92c8` / `0x1408e9d30` | 430 | 8000 | confirmed |

Also registered but never set in our runs: `{50001}` alone (`0x14088f564`, 16 blocks at a time during loads),
`{50000, 50001}` (`0x1409387ee`).

### Which systems spawn what

| System | IDs | Effects it spawns (param) |
|---|---|---|
| Thrusters | 40000, 40001, 40002 | ThrustersSfxIdParam_PC: 411001 continuous thrust, 411021 falling, 411031 end smoke, 441001/441011 assault boost, 451000 quick boost (the `sfxId1` = generator-specific variants) |
| Foot / ground | 50000, 50001, 60000 | FootSfxParam: 101001, 101011, 101031 |
| Character effects | 60000, 1 | 600010, 600020, 5041001 |
| Pulse armor | 70000 | EquipParamWeapon `paTurnOn/paOn/paBreakdownSfxId`, `stayPa_Launch/LaunchKeep/BreakSfxId` (990080-82); GeneratorTypeSfxIdRplace_PC swaps in 990180-82 |
| Scan | 70200 | 8000 |
| Generic | 0, 3, 2000, 10000, 30000, 30001 | almost everything |

Effects only take what their header declares. For example, the thruster flames 411001 declare `[0, 3]`, so they
ignore the thruster values even though those are attached to them.

## Method and tools

Everything is under `tools/`. Data from the runs is under `data/`.

### 1. Static scan of game FXRs: `tools/scripts/scan_ext.mjs`

Reads every FXR (unpacked `sfx/*.ffxbnd.dcx` with WitchyBND) with `@cccode/fxr` and lists every external value
used in `ExternalValue1/2` modifiers and state conditions, with context and the input range of the modifier
curves. Output: `data/ext_uses.json`.
`node scan_ext.mjs <unpacked sfx dir> <out.json>`

`tools/scripts/fxr_header.py <unpacked sfx dir> <fxr id>...` prints the header lists the game reads (child FXRs,
external value lists 1 and 2).

### 2. Which params reference an FXR: `tools/scripts/find_fxr_refs.py`

Raw search of an unpacked regulation (WitchyBND `-s regulation.bin`) for int32 values, with field names from
WitchyBND's Paramdex defs. Output for the FXRs above: `data/fxr_refs.tsv`. Field names for `Bullet_Npc` and
`ThrustersParam_NPC` are unreliable (their layout doesn't match the defs).
`python find_fxr_refs.py <param dir> <Paramdex Defs dir> <id>...`

`tools/scripts/param_patch.py` reads or writes s32/f32 fields of rows in a raw `.param` file in place, so a
regulation can be edited without WitchyBND's param conversion (which has stale AC6 defs).
`python param_patch.py <file.param> <def.xml> <row>:<field>[=<value>]...`

### 3. Ghidra (headless) on the de-Arxaned exe: `tools/ghidra/`

- `FindScalars.java <out> <value>...`: every instruction using one of the constants, e.g. external value IDs or
  struct offsets. This found the first setter calls and the thruster controller fields.
- `DecompileWithCallers.java <address> [depth] [out]`: decompiles a function and its callers. Used for the
  setter/register callers (`data/setter_callers.c`, `data/register_callers.c`).
- `DumpAround.java <address> <bytes before> <bytes after> <out>`: disassembly (prologues for hooking).
- `CallerStrings.java <out> <depth> <address>...`: strings referenced along caller chains. It didn't help here:
  only generic asserts.

`tools/scripts/readva.py <exe> <address>:<count>...` reads int32 tables from the exe (several spawners keep their
ID lists in `.rdata`).

### 4. Runtime logger: `tools/fxr-extvalue-logger/` (Rust, me3 native DLL)

Build with `cargo +stable build --release` and load it as a me3 native. It checks the first bytes of each hooked
function and installs nothing on another game version. Hooks:

- **register:** logs the block, the registering code (return address) and the ID list.
- **set:** logs value changes (throttled to one per 0.5 s per block and ID, except changes to or from 0).
- **attach:** logs the FXR ID of the effect instance and its own blocks, so every value is tagged with the FXRs
  that received it.
- **get:** optional overrides (below).

Output in `Game\debug-logs\`:
- `fxr_extvalues_events.tsv`: the event log. The first line has the wall-clock start time (Unix ms) for syncing
  with a recording. It gets big: about 300 MB for a 13-minute mission.
- `fxr_extvalues_summary.tsv`: per (ID, registering caller, setting caller): FXRs, blocks, set count, min, max, last.
- `fxr_extvalues_overrides_served.tsv`: per ID, the mirrored values and how often an override was served.

**Overrides** (`Game\debug-logs\fxr_extvalues_overrides.txt`, reloaded while the game runs):

```
<id|*> mirror [max|min|latest]       value spawners set for that ID elsewhere: max/min over the blocks that wrote
                                     it in the last 0.25 s (default max), or the latest write
<id|*> const <value>
<id|*> sweep <min> <max> <seconds>   triangle wave
```

A rule only applies when nothing provides the ID to that effect: no `set` call wrote it into the effect's block
and the block's value is 0. Add `force` to a rule to always apply it. `*` never covers ID 0. With `* mirror`,
any effect can show any system's values, e.g. your thruster output on a bullet effect.

### 5. Bar chart test FXR: `tools/bar-chart-fxr/make_bar_fxr.mjs`

Generates an FXR with one bar per external value (20 bars in color groups). Each bar's height is the value mapped
from a fixed range through an `ExternalValue1Modifier`, and a dim bar behind it shows the full range. Everything
is scaled by camera distance (ID 2000) to stay readable. Bars are texture 1 (a solid white square). The chart
floats 12 m above the effect, and ends on ID 0. The legend is in `data/test_package_README.txt`.
`npm install && node make_bar_fxr.mjs <out dir>` (edit `TARGETS` to pick which FXR IDs to write).

### 6. Test setup in game

The me3 package `fxr-extvalue-test` (in `AC6_tools\me3`, profile `fxr-extvalues.me3`, together with the logger):
- **Regulation:** RF-024 TURNER bullets use FXR 300031 and are static (speed 0.01, life 600 s), so every shot
  leaves a chart hanging in the air. The pulse blade attacks 1/2 got `hit0_SfxId` 600030, which never spawned.
- **`sfxbnd_commoneffects`:** 300031 is replaced by the bar chart.

Values were matched to gameplay with screen recordings (a clock overlay helps). Video time = log time + (log
start − recording start).

## How we got here (dead ends included)

1. The scan listed which FXRs use which IDs, and their curve ranges.
2. Searching the exe for the ID constants found the set function and the spawners. The first instinct, a central
   lookup, was wrong: `0x1415a7ed0` maps part names (`LG_M_...`) to param IDs using the same 10000-step bases.
3. Param references named the spawning systems (pulse armor, thrusters, foot effects, NPC attacks).
4. Logger v1 (register + set) showed which systems run during normal play.
5. Swapping TURNER's bullet effect for 300031 showed that the bullet effect path registers nothing.
6. Logger v2 (attach) tagged blocks with FXR IDs. The FXR header lists showed that effects only get declared
   IDs, and that values attached to an effect aren't necessarily used by it.
7. The bar chart on several stock effects, then on TURNER only, with **mirroring** through the get hook,
   confirmed the meanings live. Bugs fixed along the way:
   - "Missing" has to mean "never written": the effect's block has a slot for every declared ID.
   - Mirroring the latest write flickered between thrusters and characters; the max over recent sources doesn't.
   - Mirroring or forcing ID 0 breaks effect termination.
8. A Balteus mission run found ID 1. It didn't find 70010: Balteus's `hit0_SfxId` effects never spawned.

## Open questions

- 70010/70020/70030 and the capsule spawners: which system they are (beam-shaped bullets? attack hitboxes?) and
  when `hit0_SfxId` effects spawn (only on hit?). The next step would be tracing callers of `0x140873610` /
  `0x1406887c0` in Ghidra.
- 3: what the global float at `[0x144f30f38]+0x2d8` is. 331 effects switch state on it.
- 50000/50001 (foot system, 0–100), 30000/30001 (always 1), 10000 (always 0), 40002 (always 0), 20000, 70100, 1000.
- Whether ID 1 is opacity: test with a cloaking or despawning character while the chart shows bar 1.
