"""Find param rows/fields that reference given FXR IDs. Usage: find_fxr_refs.py <param dir> <paramdex defs dir> id..."""
import glob
import os
import re
import struct
import sys
import xml.etree.ElementTree as ET

param_dir, defs_dir = sys.argv[1], sys.argv[2]
targets = {int(x) for x in sys.argv[3:]}

SIZES = {'s8': 1, 'u8': 1, 'dummy8': 1, 's16': 2, 'u16': 2, 's32': 4, 'u32': 4, 'f32': 4, 'angle32': 4, 'b32': 4,
         'f64': 8, 'fixstr': 1, 'fixstrW': 2}


def layout(def_path):
    """Return [(offset, name, type)] for non-bitfield fields."""
    fields = []
    off = 0
    bit_type, bit_used = None, 0
    for f in ET.parse(def_path).getroot().iter('Field'):
        d = f.get('Def')
        m = re.match(r'(\w+)\s+(\w+)(?::(\d+))?(?:\[(\d+)\])?', d)
        typ, name, bits, count = m.group(1), m.group(2), m.group(3), m.group(4)
        size = SIZES[typ]
        if bits is not None:
            bits = int(bits)
            if bit_type == size and bit_used + bits <= size * 8:
                bit_used += bits
                continue
            bit_type, bit_used = size, bits
            off += size
            continue
        bit_type = None
        n = int(count) if count else 1
        fields.append((off, name, typ))
        off += size * n
    return fields, off


defs = {}
for p in glob.glob(os.path.join(defs_dir, '*.xml')):
    t = ET.parse(p).getroot().findtext('ParamType')
    defs[t] = p

for path in sorted(glob.glob(os.path.join(param_dir, '*.param'))):
    data = open(path, 'rb').read()
    count = struct.unpack_from('<H', data, 0xA)[0]
    type_off = struct.unpack_from('<Q', data, 0x10)[0]
    if type_off < len(data):
        ptype = data[type_off:data.index(b'\0', type_off)].decode('ascii', 'replace')
    else:  # type name stored inline in the header
        ptype = data[0xC:data.index(b'\0', 0xC)].decode('ascii', 'replace')
    base = os.path.basename(path)[:-6]
    for cand in (base, re.sub(r'_(Npc|NPC|PC)$', '', base)):
        if ptype not in defs and os.path.exists(os.path.join(defs_dir, cand + '.xml')):
            ptype = ET.parse(os.path.join(defs_dir, cand + '.xml')).getroot().findtext('ParamType')
    rows = [struct.unpack_from('<iiQQ', data, 0x40 + i * 0x18) for i in range(count)]
    if count < 1:
        continue
    row_size = (rows[1][2] - rows[0][2]) if count > 1 else None
    fields, def_size = layout(defs[ptype]) if ptype in defs else ([], None)
    if row_size is None:
        row_size = def_size or 0
    by_off = {o: (n, t) for o, n, t in fields}
    for rid, _, doff, _ in rows:
        for o in range(0, row_size - 3, 4):
            v = struct.unpack_from('<i', data, doff + o)[0]
            if v in targets:
                name, typ = by_off.get(o, (f'+{o:#x}', '?'))
                if typ in ('f32', 'angle32'):
                    continue
                print(f'{v}\t{os.path.basename(path)}\t{rid}\t{name}')
