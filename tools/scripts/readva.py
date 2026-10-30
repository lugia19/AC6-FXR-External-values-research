import struct, sys
data = open(sys.argv[1], 'rb').read()
pe = struct.unpack_from('<I', data, 0x3c)[0]
nsec = struct.unpack_from('<H', data, pe + 6)[0]
optsz = struct.unpack_from('<H', data, pe + 20)[0]
base = struct.unpack_from('<Q', data, pe + 24 + 24)[0]
secs = []
for i in range(nsec):
    o = pe + 24 + optsz + i * 40
    vsz, va, rsz, raw = struct.unpack_from('<IIII', data, o + 8)
    secs.append((va, max(vsz, rsz), raw))
def off(addr):
    rva = addr - base
    for va, sz, raw in secs:
        if va <= rva < va + sz: return raw + rva - va
for a in sys.argv[2:]:
    addr, n = a.split(':')
    o = off(int(addr, 16))
    print(addr, struct.unpack_from('<%di' % int(n), data, o))
