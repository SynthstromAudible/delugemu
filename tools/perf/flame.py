#!/usr/bin/env python3
"""Exact call-stack instruction profile of Deluge firmware in the emulator, as folded stacks of function names.

Runs the firmware under the dzstack plugin, which charges every instruction to the shadow call stack it ran under,
from the first PlaybackHandler::playButtonPressed (the probe firmware presses PLAY by itself) for --insns
instructions. Writes <out>/stacks.folded ("main;Foo::bar;baz 1234" lines) for tools/perf/flamegraph.py. Host audio is
never connected.

  tools/perf/flame.py --elf probe.elf --out build/perf/flame-myad --icount 1 --insns 30000000000
"""
import argparse
import bisect
import collections
import os
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(REPO, "pylib"))
from delugemu import DelugeSession  # noqa: E402

NM = "arm-none-eabi-nm"


def functions(elf):
    """Sorted (start, end, name) of function symbols, names demangled."""
    out = subprocess.run([NM, "-n", "-S", "-C", "--defined-only", elf], check=True, capture_output=True,
                         text=True).stdout
    funcs = []
    for line in out.splitlines():
        parts = line.split(None, 3)
        if len(parts) >= 3 and len(parts[1]) == 1 and parts[1] in "TtWw":
            # No size (an assembly label such as irq_handler): it runs to the next symbol
            parts = [parts[0], None, parts[1], " ".join(parts[2:])]
        if len(parts) == 4 and len(parts[2]) == 1 and parts[2] in "TtWw":
            start = int(parts[0], 16) & ~1
            funcs.append([start, None if parts[1] is None else start + int(parts[1], 16), parts[3]])
    for i, f in enumerate(funcs):
        if f[1] is None:
            f[1] = funcs[i + 1][0] if i + 1 < len(funcs) else f[0] + 4
    return funcs


def symbol(elf, name):
    out = subprocess.run([NM, elf], check=True, capture_output=True, text=True).stdout
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[2] == name:
            return int(parts[0], 16) & ~1
    sys.exit("%s: no symbol %s" % (elf, name))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--elf", required=True)
    ap.add_argument("--sd", default=os.path.join(REPO, "build", "deluge_sd_32k.img"))
    ap.add_argument("--out", required=True)
    ap.add_argument("--insns", type=int, default=30_000_000_000, help="instructions to profile after PLAY")
    ap.add_argument("--icount", default="1", help="run.sh --icount shift (omit with --plugin for time control)")
    ap.add_argument("--timectl", default=None,
                    help="instead of --icount, time the guest with dzcache, e.g. timectl=1,cachesim=0,cpi=1.45")
    ap.add_argument("--timeout", type=float, default=7200)
    args = ap.parse_args()

    os.makedirs(args.out, exist_ok=True)
    out = os.path.abspath(args.out)
    funcs = functions(args.elf)
    with open(os.path.join(out, "funcs.txt"), "w") as f:
        for start, _, name in funcs:
            if ".cold" not in name:  # jumps into split-off cold code aren't tail calls
                f.write("%x\n" % start)

    ext = "dylib" if sys.platform == "darwin" else "so"
    raw = os.path.join(out, "stacks.raw")
    log = os.path.join(out, "plugin.log")
    if os.path.exists(raw):
        os.remove(raw)
    opts = ["out=" + raw, "funcs=" + os.path.join(out, "funcs.txt"), "irq=%#x" % symbol(args.elf, "irq_handler"),
            "fiq=%#x" % symbol(args.elf, "fiq_handler"),
            "start=%#x" % next(s for s, _, n in funcs if n.startswith("PlaybackHandler::playButtonPressed(")),
            "limit=%d" % args.insns]
    extra = ["-plugin", "%s,%s" % (os.path.join(REPO, "build", "plugins", "libdzstack." + ext), ",".join(opts))]
    icount = args.icount
    if args.timectl:
        icount = None
        extra += ["-plugin", "%s,%s" % (os.path.join(REPO, "build", "plugins", "libdzcache." + ext),
                                        "lean=1," + args.timectl)]
    extra += ["-d", "plugin", "-D", log]

    t0 = time.time()
    with DelugeSession.launch(firmware=os.path.abspath(args.elf), sd=args.sd, icount=icount, headless=True,
                              audio="none", sock="/tmp/dzflame_%d.sock" % os.getpid(),
                              run_log=os.path.join(out, "run.log"), boot_wait=5, extra_qemu=extra):
        while time.time() - t0 < args.timeout:
            time.sleep(5)
            if os.path.exists(log) and "dzstack: wrote" in open(log, errors="replace").read():
                break
    print("%s: %.0f s wall" % (args.out, time.time() - t0))
    if not os.path.exists(raw):
        sys.exit("no profile: see %s" % log)

    starts = [s for s, _, _ in funcs]

    def name(addr):
        i = bisect.bisect_right(starts, addr) - 1
        if i >= 0 and (addr < funcs[i][1] or funcs[i][0] == funcs[i][1]):
            return funcs[i][2]
        return "0x%x" % addr

    folded = collections.Counter()
    for line in open(raw):
        path, count = line.rsplit(" ", 1)
        frames = [] if path == "[root]" else [name(int(a, 16)) for a in path.split(";")]
        folded[";".join(f.replace(";", ",") for f in frames) or "[root]"] += int(count)
    with open(os.path.join(out, "stacks.folded"), "w") as f:
        for path, count in sorted(folded.items()):
            f.write("%s %d\n" % (path, count))
    print("%s/stacks.folded: %d stacks, %d instructions" % (args.out, len(folded), sum(folded.values())))


if __name__ == "__main__":
    main()
