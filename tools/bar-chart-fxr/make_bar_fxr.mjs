// Builds "bar chart" test FXRs: one bar per external value, height = value mapped from [min, max] to [0, 1] (clamped),
// with a dim full-height bar behind it for scale. The same chart is written under several FXR IDs so each spawner's
// values can be checked in game. Usage: node make_bar_fxr.mjs <output dir> [full|slim]
import {
  AttachMode,
  BasicNode,
  BillboardEx,
  BlendMode,
  ExternalValue1Modifier,
  FXR,
  Game,
  Keyframe,
  LinearProperty,
  ParticleAttributes,
  PeriodicEmitter,
  State,
  StaticNodeTransform,
  ConstantProperty,
} from '@cccode/fxr'
import fs from 'node:fs'
import path from 'node:path'

// Bars left to right, as [id, min, max]. Groups are separated by a gap and share a color.
const PRESETS = {
  // Every ID of interest.
  full: [
    { color: [1, 1, 1, 1], bars: [[1, 0, 1], [3, 0, 1], [1000, 0, 1], [2000, 0, 100], [10000, -1, 1], [20000, 0, 200],
      [30000, 0, 1], [30001, 0, 1]] },
    { color: [1, 0.45, 0.05, 1], bars: [[40000, 0, 100], [40001, 0, 1], [40002, 0, 90]] },
    { color: [0.1, 1, 0.2, 1], bars: [[50000, 0, 100], [50001, 0, 100], [60000, 0, 800]] },
    { color: [0.1, 0.7, 1, 1], bars: [[70000, 0, 60], [70010, 0, 100], [70020, 0, 1000], [70030, 0, 1]] },
    { color: [0.8, 0.2, 1, 1], bars: [[70100, 0, 100], [70200, 0, 1000]] },
  ],
  // Only the identified IDs that change during normal play.
  slim: [
    { color: [1, 1, 1, 1], bars: [[2000, 0, 100]] },                          // camera distance (m)
    { color: [1, 0.45, 0.05, 1], bars: [[40000, 0, 100], [40001, 0, 1]] },    // booster output %, speed / max speed
    { color: [0.1, 1, 0.2, 1], bars: [[60000, 0, 800]] },                     // speed (km/h)
    { color: [0.1, 0.7, 1, 1], bars: [[70000, 0, 20]] },                      // pulse armor radius (m)
    { color: [0.8, 0.2, 1, 1], bars: [[70200, 0, 1000]] },                    // scan distance
  ],
}
const PRESET = process.argv[3] ?? 'full'
const GROUPS = PRESETS[PRESET]
if (!GROUPS) throw new Error(`Unknown preset '${PRESET}' (expected ${Object.keys(PRESETS).join(' or ')})`)

const BAR_WIDTH = 0.4
const BAR_STEP = 0.6
const GROUP_GAP = 0.6
const BAR_HEIGHT = 3
const CHART_ELEVATION = 12 // meters above the spawn point

// FXR ID -> seconds before the chart ends on its own (null = only when the spawner terminates it via ext 0).
const TARGETS = {
  300031: null, // TURNER bullets (test regulation). Other spawners' values reach it through the logger DLL's
                // mirror overrides (fxr_extvalues_overrides.txt), so no stock effect needs replacing.
}

function bars() {
  const out = []
  let x = 0
  for (const group of GROUPS) {
    for (const [id, min, max] of group.bars) {
      out.push({ id, min, max, color: group.color, x })
      x += BAR_STEP
    }
    x += GROUP_GAP
  }
  const center = (x - GROUP_GAP - BAR_STEP) / 2
  return out.map(b => ({ ...b, x: b.x - center }))
}

// Size multiplier from camera distance (external value 2000, meters) so the chart keeps roughly the same size on
// screen: 1x at 20 m, proportional beyond that, never below 0.5x.
const SCALE_REFERENCE_DISTANCE = 20
const distanceScale = () => new ExternalValue1Modifier(2000, new LinearProperty(false, [
  new Keyframe(0, 0.5),
  new Keyframe(SCALE_REFERENCE_DISTANCE / 2, 0.5),
  new Keyframe(2000, 2000 / SCALE_REFERENCE_DISTANCE),
]))

function barNode({ id, min, max, color, x }, background) {
  const baseWidth = background ? BAR_WIDTH * 1.5 : BAR_WIDTH
  const width = new ConstantProperty(baseWidth)
  width.modifiers = [distanceScale()]
  const height = new ConstantProperty(BAR_HEIGHT)
  height.modifiers = [distanceScale()]
  if (!background) {
    // Height multiplier follows the external value: min -> 0, max -> 1 (linear, clamped at the ends).
    height.modifiers.push(new ExternalValue1Modifier(id, new LinearProperty(false, [
      new Keyframe(min, 0),
      new Keyframe(max, 1),
    ])))
  }
  return new BasicNode([
    new StaticNodeTransform({ offset: [0, CHART_ELEVATION, 0] }),
    new PeriodicEmitter({ interval: 0.05, perInterval: 1 }),
    new ParticleAttributes({ duration: 0.1, attachment: AttachMode.Parent }),
    new BillboardEx({
      texture: 1, // solid white square
      blendMode: BlendMode.Normal,
      width,
      height,
      // Offsets are in units of the particle's size: center the bar on x, grow upward from the baseline.
      offsetX: x / baseWidth,
      offsetY: 0.5,
      color1: background ? [color[0] * 0.35, color[1] * 0.35, color[2] * 0.35, 0.35] : color,
    }),
  ])
}

const outDir = process.argv[2]
fs.mkdirSync(outDir, { recursive: true })
const layout = bars()
for (const [id, timeout] of Object.entries(TARGETS)) {
  const conditions = ['ext(0) >= 1 then terminate']
  if (timeout !== null) conditions.push(`time >= ${timeout} then terminate`)
  const fxr = new FXR(Number(id), [State.from(conditions)], [
    ...layout.map(b => barNode(b, true)),
    ...layout.map(b => barNode(b, false)),
  ])
  await fxr.saveAs(path.join(outDir, fxr.name), Game.ArmoredCore6)
}
console.log('bars (left to right):', layout.map(b => `${b.id}[${b.min}..${b.max}]`).join(' '))
console.log('wrote', Object.keys(TARGETS).length, 'FXRs to', outDir)
