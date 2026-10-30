// Scan all AC6 FXRs for external value usage (modifiers 38/39 and state conditions).
import { FXR, Game } from '@cccode/fxr'
import fs from 'node:fs'
import path from 'node:path'

const root = process.argv[2]
const out = process.argv[3]
const files = []
const walkDir = d => { for (const e of fs.readdirSync(d, { withFileTypes: true })) {
  const p = path.join(d, e.name)
  if (e.isDirectory()) walkDir(p); else if (e.name.endsWith('.fxr')) files.push(p)
} }
walkDir(root)

const uses = [] // {ext, kind, file, bnd, ctx, detail}
let failed = 0
for (const f of files) {
  let json
  try {
    const fxr = await FXR.read(fs.readFileSync(f), Game.ArmoredCore6)
    json = JSON.parse(JSON.stringify(fxr))
  } catch (e) { failed++; continue }
  const bnd = path.relative(root, f).split(path.sep)[0]
  const file = path.basename(f)
  const walk = (o, ctx) => {
    if (Array.isArray(o)) { o.forEach((v, i) => walk(v, ctx)); return }
    if (o && typeof o === 'object') {
      if ((o.type === 'ExternalValue1' || o.type === 'ExternalValue2') && 'externalValue' in o) {
        uses.push({ ext: o.externalValue, kind: o.type, bnd, file, ctx: ctx.join('.'), detail: o.factor })
      }
      let c = ctx
      if (typeof o.type === 'string' || typeof o.type === 'number') c = [...ctx, String(o.type)]
      for (const [k, v] of Object.entries(o)) walk(v, [...c, k])
      return
    }
    if (typeof o === 'string') {
      for (const m of o.matchAll(/External\((-?\d+)\)/g))
        uses.push({ ext: +m[1], kind: 'State', bnd, file, ctx: ctx.join('.'), detail: o })
    }
  }
  walk(json, [])
}
fs.writeFileSync(out, JSON.stringify(uses, null, 1))
const by = {}
for (const u of uses) { const k = `${u.ext}|${u.kind}`; (by[k] ??= new Set()).add(u.file) }
console.log(`files ${files.length}, failed ${failed}, uses ${uses.length}`)
for (const [k, s] of Object.entries(by).sort((a, b) => parseInt(a[0]) - parseInt(b[0]))) console.log(k, s.size)
