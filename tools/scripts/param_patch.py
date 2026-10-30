"""Read or patch s32/f32 fields of rows in an unpacked .param file in place (no paramdef conversion).
Usage: param_patch.py <param file> <def xml> <row>:<field>[=<new value>] ..."""
import os
import struct
import sys


import re
import xml.etree.ElementTree as ET

SIZES = {'s8': 1, 'u8': 1, 'dummy8': 1, 's16': 2, 'u16': 2, 's32': 4, 'u32': 4, 'f32': 4, 'angle32': 4, 'b32': 4,
         'f64': 8, 'fixstr': 1, 'fixstrW': 2}


def layout(def_path):
    fields = {}
    off = 0
    bit_type, bit_used = None, 0
    for f in ET.parse(def_path).getroot().iter('Field'):
        m = re.match(r'(\w+)\s+(\w+)(?::(\d+))?(?:\[(\d+)\])?', f.get('Def'))
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
        fields[name] = (off, typ)
        off += size * (int(count) if count else 1)
    return fields


param_path, def_path = sys.argv[1], sys.argv[2]
data = bytearray(open(param_path, 'rb').read())
fields = layout(def_path)
count = struct.unpack_from('<H', data, 0xA)[0]
rows = {struct.unpack_from('<i', data, 0x40 + i * 0x18)[0]: struct.unpack_from('<Q', data, 0x40 + i * 0x18 + 8)[0]
        for i in range(count)}
changed = False
for spec in sys.argv[3:]:
    target, _, new = spec.partition('=')
    row, field = target.split(':')
    off, typ = fields[field]
    fmt = {'s32': '<i', 'f32': '<f'}[typ]
    pos = rows[int(row)] + off
    old = struct.unpack_from(fmt, data, pos)[0]
    if new:
        struct.pack_into(fmt, data, pos, float(new) if typ == 'f32' else int(new))
        changed = True
    print(f'{row}:{field} = {old}' + (f' -> {new}' if new else ''))
if changed:
    open(param_path, 'wb').write(data)
