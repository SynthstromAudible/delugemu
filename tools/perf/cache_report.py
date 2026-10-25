#!/usr/bin/env python3
"""Where the cache model's misses come from: functions ranked by modelled stall, and which data the misses hit.

  tools/perf/cache_report.py runs/cache/plugin.log --elf probe.elf

Uses the plugin's INSN lines (the instructions causing the most misses, phase A = first `phasea` slices after PLAY,
phase B = the rest) and HEAT lines (data misses per 64 KiB block after PLAY). Penalties are rough relative weights:
an L1 miss that hits L2 25 cycles, an L2 miss to internal RAM 40, to SDRAM 145, an I-cache miss 30.
"""
import argparse
import bisect
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import dzprobe  # noqa: E402

INSN = re.compile(r"INSN 0x([0-9a-f]+) l1d_miss=\d+,(\d+),(\d+) l2_miss=\d+,(\d+),(\d+) nc=\d+,(\d+),(\d+)"
                  r"(?: l1i_miss=\d+,(\d+),(\d+) l2_sdram=\d+,(\d+),(\d+))?")


def cost(c):
    return c["l1i"] * 30 + c["l1d"] * 25 + (c["l2"] - c["sd"]) * 15 + c["sd"] * 120 + c["nc"] * 100


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("log")
    ap.add_argument("--elf", required=True)
    ap.add_argument("--top", type=int, default=20)
    args = ap.parse_args()

    nm = subprocess.run(["arm-none-eabi-nm", "-C", "-n", args.elf], capture_output=True, text=True).stdout
    funcs = [(int(l[:8], 16), l[11:]) for l in nm.splitlines() if len(l) > 11 and l[9] in "tTwW"]
    keys = [a for a, _ in funcs]

    def func(a):
        i = bisect.bisect_right(keys, a) - 1
        return funcs[i][1] if i >= 0 else hex(a)

    text = open(args.log, errors="replace").read()
    by = collections.defaultdict(collections.Counter)
    for m in INSN.finditer(text):
        g = [int(x) if x else 0 for x in m.groups()[1:]]
        by[func(int(m[1], 16))].update(dict(l1d=g[0] + g[1], l2=g[2] + g[3], nc=g[4] + g[5], l1i=g[6] + g[7],
                                            sd=g[8] + g[9]))
    total = sum(cost(c) for c in by.values()) or 1
    print("functions by modelled stall after PLAY (share, I-cache misses, L1D misses, L2 misses internal/SDRAM, uncached)")
    for name, c in sorted(by.items(), key=lambda kv: -cost(kv[1]))[:args.top]:
        print("  %5.1f%%  %8d %8d %8d/%-8d %7d  %s" % (100 * cost(c) / total, c["l1i"], c["l1d"], c["l2"] - c["sd"],
                                                      c["sd"], c["nc"], name[:70]))

    # Data misses by 64 KiB block, labelled with the sections and biggest data symbols there
    sections = []
    for line in subprocess.run(["arm-none-eabi-objdump", "-h", args.elf], capture_output=True, text=True).stdout.splitlines():
        p = line.split()
        if len(p) > 4 and p[1].startswith("."):
            sections.append((int(p[3], 16), int(p[2], 16), p[1]))
    data = [(a, s, n) for n, (a, s) in dzprobe.symbols(args.elf).items() if s >= 1024]
    heat = [(int(a, 16), int(x), int(y)) for a, x, y in re.findall(r"HEAT 0x([0-9a-f]+) l1d=(\d+) l2=(\d+)", text)]
    tl1 = sum(h[1] for h in heat) or 1
    tl2 = sum(h[2] for h in heat) or 1
    print("\ndata misses by 64 KiB block (share of L1D misses, of L2 misses)")
    for a, x, y in sorted(heat, key=lambda h: -(h[1] * 25 + h[2] * 100))[:args.top]:
        secs = [n for v, s, n in sections if s and v < a + 0x10000 and v + s > a]
        syms = sorted(((s, n) for v, s, n in data if v < a + 0x10000 and v + s > a), reverse=True)[:2]
        print("  0x%08x %5.1f%% %5.1f%%  %s %s" % (a, 100 * x / tl1, 100 * y / tl2, ",".join(secs[:2]),
                                                  "; ".join("%s(%dK)" % (n[:40], s // 1024) for s, n in syms)))


if __name__ == "__main__":
    main()
