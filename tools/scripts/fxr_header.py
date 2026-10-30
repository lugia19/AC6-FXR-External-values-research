"""Print an FXR's header lists the game reads: referenced FXRs (+0x70/+0x74), external values 1 (+0x78/+0x7c) and 2
(+0x80/+0x84). Usage: fxr_header.py <unpacked sfx dir> <fxr id>..."""
import glob, os, struct, sys
root = sys.argv[1]
for fid in sys.argv[2:]:
    paths = glob.glob(os.path.join(root, '*', 'effect', 'f%09d.fxr' % int(fid)))
    if not paths:
        print(fid, 'not found'); continue
    d = open(paths[0], 'rb').read()
    lists = []
    for o in (0x70, 0x78, 0x80):
        off, n = struct.unpack_from('<II', d, o)
        lists.append(list(struct.unpack_from('<%di' % n, d, off)) if n else [])
    print(fid, os.path.basename(os.path.dirname(os.path.dirname(paths[0]))).split('-')[0].replace('sfxbnd_', ''),
          'refs', lists[0], 'ext1', lists[1], 'ext2', lists[2])
