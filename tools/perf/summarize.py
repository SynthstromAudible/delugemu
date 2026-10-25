#!/usr/bin/env python3
"""Compare emulator runs (run_emu.py output directories) with each other and with a hardware probe dump.

  tools/perf/summarize.py runs/cpi145 runs/cache --hw hw.bin --hw-play 136

Skips the first --skip seconds after PLAY. Emulator time comes from the plugin's modelled cycles (time control) or
from instructions at --ips (icount runs); hardware time from the probe's 100 ms windows.
"""
import argparse
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import dzprobe  # noqa: E402


def emu_run(path, skip, ips, warm=5_000_000_000):
    text = open(os.path.join(path, "plugin.log"), errors="replace").read()
    mark = re.search(r"MARK insns=(\d+)", text)
    if not mark:
        raise ValueError("%s: PLAY never happened" % path)
    after = text[mark.start():]
    slices = [dict((k, float(v)) for k, v in re.findall(r"(\w+)=([\d.]+)", l))
              for l in re.findall(r"^SLICE \d+ (.*)$", after, re.M)]
    slices = [s for s in slices if s.get("insns") == 1e8]
    timectl = slices and slices[-1].get("cycles", 0) > 0
    per_slice = (slices[-1]["cycles"] - slices[0]["cycles"]) / 400e6 / (len(slices) - 1) if timectl else 1e8 / ips
    slices = slices[int(skip / per_slice):]
    ins = sum(s["insns"] for s in slices)
    rins = sum(s["render_ins"] for s in slices)
    rfr = sum(s["render_frames"] for s in slices)
    secs = per_slice * len(slices)
    r = dict(name=os.path.basename(path.rstrip("/")), frames_s=rfr / secs, ins_frame=rins / max(1, rfr),
             l1i=1000 * sum(s["l1i_miss"] for s in slices) / ins,
             l1d=1000 * sum(s["l1d_rd_miss"] + s["l1d_wr_miss"] for s in slices) / ins)
    # Culls, voices and load from the probe ring: windows while playing, after the skip
    w = [x for x in dzprobe.load_windows(os.path.join(path, "probe.bin")) if x.get("audioVoices")]
    w = w[int(skip * 10):]
    r["culls"] = 50 * sum(x["culls"] for x in w) / len(w)
    r["voices"] = sum(x["voices"] for x in w) / len(w)
    r["load"] = 100 * sum(x["sum_cyc"] for x in w) / (len(w) * 0.1 * 1e9)  # QEMU's PMU cycle counter runs at 1 GHz
    # SCOPE totals cover calls from `warm` instructions after PLAY; take frames and renders over the same span
    r["scopes"] = {int(i): (int(c), int(n)) for i, c, n in re.findall(r"SCOPE (\d) calls=(\d+) ins=(\d+)", text)}
    start = int(mark[1]) + warm
    spans = [int(m[2]) for m in re.finditer(r"^R (\d+) ins=\d+ fr=(\d+)", text, re.M) if int(m[1]) >= start and int(m[2])]
    # The plugin's R lines are calls of AudioEngine::routine(), which can render twice; count actual renders
    # (routine_() calls) with the probe's frames-per-render while playing
    fpr = sum(x["frames"] for x in w) / max(1, sum(x["renders"] for x in w))
    r["scope_frames"], r["scope_renders"] = sum(spans), sum(spans) / fpr
    r["fpr"] = fpr
    return r


def hw_run(path, play, skip):
    w = [x for x in dzprobe.load_windows(path) if x["i"] >= play + int(skip * 10)]
    S = lambda k: sum(x.get(k, 0) for x in w)
    fr = S("frames")
    r = dict(name="hardware", frames_s=fr / (len(w) * 0.1), ins_frame=S("sum_ins") / fr,
             l1i=1000 * S("sum_l1i") / S("sum_ins"), l1d=1000 * S("sum_l1d") / S("sum_ins"),
             culls=50 * S("culls") / len(w), voices=S("voices") / len(w),
             load=100 * S("sum_cyc") / (len(w) * 0.1 * 400e6), fpr=fr / S("renders"))
    r["scopes"] = {i: (S("scopeCalls%d" % i), S("scopeIns%d" % i)) for i in range(6) if "scopeCalls%d" % i in w[0]}
    r["scope_frames"], r["scope_renders"] = fr, S("renders")
    return r


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("runs", nargs="*")
    ap.add_argument("--hw", help="hardware probe dump (tools/perf/hw_probe.py dump)")
    ap.add_argument("--hw-play", type=int, help="window index of PLAY in the hardware dump (dzPlayIndex)")
    ap.add_argument("--skip", type=float, default=25.0, help="seconds after PLAY to ignore")
    ap.add_argument("--ips", type=float, default=5e8, help="instructions per second for icount runs (shift 1 = 5e8)")
    args = ap.parse_args()

    rows = []
    if args.hw:
        rows.append(hw_run(args.hw, args.hw_play, args.skip))
    rows += [emu_run(p, args.skip, args.ips) for p in args.runs]
    print("%-12s %9s %8s %6s %9s %7s %7s %7s %7s" % ("run", "frames/s", "ins/fr", "load%", "culls/5s", "voices",
                                                    "L1I/kI", "L1D/kI", "fr/rnd"))
    for r in rows:
        print("%-12s %9.0f %8.0f %6.0f %9.1f %7.1f %7.1f %7.1f %7.1f" % (
            r["name"], r["frames_s"], r["ins_frame"], r["load"], r["culls"], r["voices"], r["l1i"], r["l1d"], r["fpr"]))
    print("\ninstructions per frame per call, (calls per render):")
    print("  %-38s" % "", " ".join("%16s" % r["name"] for r in rows))
    for i, n in enumerate(dzprobe.SCOPE_NAMES):
        print("  %-38s" % n, " ".join(_scope_cell(r, i) for r in rows))


def _scope_cell(r, i):
    calls, ins = r["scopes"].get(i, (0, 0))
    if not calls or not r.get("scope_renders"):
        return "%16s" % "-"
    per_render = calls / r["scope_renders"]
    frames_per_render = r["scope_frames"] / r["scope_renders"]
    return "%9.0f (%4.1f)" % (ins / calls / frames_per_render, per_render)


if __name__ == "__main__":
    main()
