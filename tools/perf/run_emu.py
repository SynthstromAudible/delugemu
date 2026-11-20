#!/usr/bin/env python3
"""Run the dz probe firmware in the emulator under the dzcache plugin and collect its reports.

The probe firmware loads and plays its song by itself, so no input is needed. Host audio is never connected.
Writes <out>/plugin.log (SLICE/MARK/R/SCOPE lines), <out>/probe.bin (the probe's window ring) and <out>/run.log.
With the tick probe (tools/perf/firmware/tick-probe.patch) it also writes <out>/renders.bin, its per-render ring
(dzRenders, ~8 s of renders), and with --all-renders <out>/renders_all.bin, the same ring dumped every poll and merged
so it covers the whole run (read either with tools/perf/ticks.py).

  tools/perf/run_emu.py --elf probe.elf --out runs/cpi145 --plugin timectl=1,cachesim=0,cpi=1.45 --lean
  tools/perf/run_emu.py --elf probe.elf --out runs/ic1 --icount 1 --plugin cachesim=0
"""
import argparse
import os
import struct
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(REPO, "pylib"))
sys.path.insert(0, HERE)
from delugemu import DelugeSession  # noqa: E402
import dzprobe  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--elf", required=True, help="probe firmware ELF")
    ap.add_argument("--sd", default=os.path.join(REPO, "build", "deluge_sd.img"))
    ap.add_argument("--out", required=True, help="output directory")
    ap.add_argument("--plugin", default="cachesim=0", help="extra dzcache options, comma-separated")
    ap.add_argument("--icount", default=None, help="run.sh --icount shift (omit for time control / host clock)")
    ap.add_argument("--slices", type=int, default=200, help="stop this many 100M-instruction slices after PLAY")
    ap.add_argument("--warm", type=int, default=5_000_000_000, help="SCOPE totals start this many instructions after PLAY")
    ap.add_argument("--timeout", type=float, default=3600)
    ap.add_argument("--hotblocks", action="store_true",
                    help="also run QEMU's libhotblocks, for a per-symbol instruction profile: scripts/dz_bucket.py "
                         "<out>/plugin.log <elf>")
    ap.add_argument("--lean", action="store_true",
                    help="fast flat-CPI timing (timectl=1,cachesim=0 in --plugin): no per-render/per-function accounting")
    ap.add_argument("--all-renders", action="store_true",
                    help="tick probe: dump the per-render ring every poll (the VM is stopped for each dump, which "
                         "time control and icount don't notice) and merge the dumps into <out>/renders_all.bin")
    ap.add_argument("--poll", type=float, default=10, help="seconds between checks (and ring dumps)")
    args = ap.parse_args()

    a = dzprobe.probe_addresses(args.elf)
    os.makedirs(args.out, exist_ok=True)
    log = os.path.abspath(os.path.join(args.out, "plugin.log"))
    lib = os.path.join(REPO, "build", "plugins", "libdzcache." + ("dylib" if sys.platform == "darwin" else "so"))
    opts = ["ttb=%#x" % a["ttb"], "l2c=0x3FFFF000", "mark=%#x" % a["mark"], "slice=100000000", "phasea=63"]
    if args.lean:
        opts.append("lean=1")
    else:
        opts += ["render=%#x" % a["render"], "timer=%#x" % a["timer"], "warm=%d" % args.warm]
        opts += ["s%d=%#x" % (i, addr) for i, addr in enumerate(a["scopes"])]
    if args.plugin:
        opts.append(args.plugin)
    sock = "/tmp/dzperf_%d.sock" % os.getpid()
    extra = ["-plugin", "%s,%s" % (lib, ",".join(opts))]
    if args.hotblocks:
        # Writes its report to the same log when QEMU quits
        hb = os.path.join(REPO, "qemu", "build", "contrib", "plugins",
                          "libhotblocks." + ("dylib" if sys.platform == "darwin" else "so"))
        extra += ["-plugin", hb + ",inline=on,limit=0"]
    extra += ["-d", "plugin", "-D", log]

    def slices_after_mark():
        try:
            text = open(log, errors="replace").read()
        except FileNotFoundError:
            return -1
        m = text.find("MARK")
        return text[m:].count("SLICE") if m >= 0 else -1

    dumps = []

    def memsave(dz, addr, size, path):
        dz.q.execute("memsave", val=addr, size=size, filename=os.path.abspath(path), **{"cpu-index": 0})

    def dump_ring(dz):
        path = os.path.join(args.out, "rings", "r%04d.bin" % len(dumps))
        os.makedirs(os.path.dirname(path), exist_ok=True)
        dz.q.execute("stop")
        try:
            memsave(dz, a["renders"], a["renders_size"], path)
        finally:
            dz.q.execute("cont")
        dumps.append(path)

    with DelugeSession.launch(firmware=args.elf, sd=args.sd, icount=args.icount, headless=True, audio="none",
                              sock=sock, run_log=os.path.join(args.out, "run.log"), boot_wait=5,
                              extra_qemu=extra) as dz:
        t0 = time.time()
        while slices_after_mark() < args.slices and time.time() - t0 < args.timeout:
            time.sleep(args.poll)
            if args.all_renders and a["tick_probe"] and slices_after_mark() >= 0:
                dump_ring(dz)
        dz.q.execute("stop")
        memsave(dz, a["probe"], a["probe_size"], os.path.join(args.out, "probe.bin"))
        if a["tick_probe"]:
            memsave(dz, a["renders"], a["renders_size"], os.path.join(args.out, "renders.bin"))
            if args.all_renders:
                dumps.append(os.path.join(args.out, "renders.bin"))
                merge_rings(dumps, os.path.join(args.out, "renders_all.bin"))
        print("%s: %d slices after PLAY, %.0f s wall" % (args.out, slices_after_mark(), time.time() - t0))


def merge_rings(paths, out):
    """Merge dumps of the per-render ring into one ring, in the same format, holding every render they cover."""
    entries = {}
    esize = None
    for p in paths:
        raw = open(p, "rb").read()
        magic, index, esize, n = struct.unpack_from("<IIII", raw)
        if magic != dzprobe.RENDER_MAGIC:
            continue
        for k in range(max(0, index - n), index):
            entries[k] = raw[16 + (k % n) * esize:16 + (k % n + 1) * esize]
    if not entries:
        return
    lo, hi = min(entries), max(entries)
    n = hi - lo + 1
    missing = n - len(entries)
    if missing:
        print("merge_rings: %d renders missing (poll less often than the ring wraps, or use --poll)" % missing)
    slots = [b"\0" * esize] * n
    for k, e in entries.items():
        slots[k % n] = e  # render k lives at slot k % n, as in the firmware's ring
    with open(out, "wb") as f:
        f.write(struct.pack("<IIII", dzprobe.RENDER_MAGIC, hi + 1, esize, n))
        f.write(b"".join(slots))
    print("merge_rings: renders %d..%d -> %s" % (lo, hi, out))


if __name__ == "__main__":
    main()
