---
name: measure-firmware-performance
description: Measure Deluge firmware audio-render performance in the delugemu emulator at real-Deluge speed (render load, voice culling, instructions per frame, per-function cost, cache misses), and A/B a firmware change. Use when asked how expensive the render is, why a song culls voices or glitches, whether a change makes the firmware faster or slower, or where cache misses come from.
---

# Measuring firmware performance with delugemu

The emulator normally runs the guest on the host's clock, so it is far faster than a Deluge and host hiccups leak in
as fake stalls. For performance work, run the **probe firmware** under the **dzcache plugin**, which times the guest
by modelled A9 cycles calibrated against a real Deluge. Everything lives in `tools/perf/` (read its README for the
calibration data); this skill is the workflow.

## Ground rules

- **Never touch a real Deluge or its debugger unless the user explicitly says so for this task.**
  `tools/perf/hw_probe.py` halts and reloads the device. The emulator is the default.
- **Never connect host audio.** `run_emu.py` always uses `--audio none`; keep it that way in anything you add.
- **Don't measure in real-time mode** (no `--icount` and no `timectl=1`). Host scheduling, JIT warm-up and SD-image
  I/O then show up as guest time: fake slow renders and culls that aren't the firmware's.
- Keep results under `build/perf/<name>/` (gitignored), not `/tmp`.

## 1. Set up (once per checkout)

```sh
scripts/integrate.sh && scripts/build.sh   # QEMU with qemu-patches/ (0007 lets plugins drive the clock)
scripts/build-plugins.sh                   # build/plugins/libdzcache.dylib
```

Use the 32 KiB-cluster card image (`build/deluge_sd_32k.img`, or `scripts/mksd.sh`, which now formats 32 KiB).
Real Deluge cards use 32 KiB clusters, and the firmware streams one cluster per read.

## 2. Build the probe firmware for the code under test

The probe is the DelugeFirmware branch `debug/pmu-render-probe`. It records 100 ms windows of render timing, culls,
late clusters, PMU counters, per-function costs (`DzScope` on six functions) and delay-path counts in an SDRAM ring
(`dzProbe`). At boot it loads and plays a song by itself, so no input driving is needed.

- To measure your change: rebase or cherry-pick it onto the probe branch, or the probe commit onto your branch.
  Keep the probe commit separate. It's not for merging.
- **The song** is the first `.XML` under `SONGS/` whose name contains `dzSongPath`, default `"Make You A Deal 2"`,
  a CPU-bound song that keeps a real Deluge at about 88% render load. To use another song, change the initializer
  in `src/deluge/io/debug/dz_probe.cpp`. It must be on the card image (`sdcard/` → `scripts/mksd.sh`).
- **Build it in a worktree** so the user's checkout stays free. `./dbt` refuses worktrees, so run:
  `DBT_NO_SYNC=1 DBT_TOOLCHAIN_PATH=<main checkout> ./dbt build release`
- **Copy the ELF** somewhere stable (e.g. `build/perf/elf/<name>.elf`). Rebuilding overwrites `build/Release`.

## 3. Pick a mode and run

| Mode | Command flags | Wall time per ~80 s of song | Use for |
| ---- | ------------- | --------------------------- | ------- |
| Lean flat | `--plugin timectl=1,cachesim=0,cpi=1.45 --lean` | ~70 s | Quick "does it cull / what's the load" at Deluge speed |
| Full flat | `--plugin timectl=1,cachesim=0,cpi=1.45` | ~4.5 min | Adds render instructions/frame and the per-function table |
| Cache model | `--plugin timectl=1,pfstreams=4,pfdist=4,l2pf=1` | ~8 min | Closest to hardware; required when a change affects code size, data layout or memory traffic |
| icount | `--icount 1 --plugin cachesim=0` | ~4 min | Instruction counts only; timing isn't Deluge-like, so ignore culls |

```sh
tools/perf/run_emu.py --elf build/perf/elf/base.elf --sd build/deluge_sd_32k.img --out build/perf/base-lean \
    --plugin timectl=1,cachesim=0,cpi=1.45 --lean
```

- **Run modes in parallel** when comparing (one emulator per core is fine). Run in the background and wait for the
  `slices after PLAY` line.
- **Default length** is 200 slices of 100M instructions after PLAY (`--slices`).
- **Outputs** go to `<out>/plugin.log` (SLICE/MARK/R/SCOPE/INSN/HEAT lines), `<out>/probe.bin` (the window ring)
  and `<out>/run.log`.

## 4. Read the results

```sh
tools/perf/summarize.py build/perf/base-lean build/perf/change-lean            # side by side
tools/perf/summarize.py build/perf/base-full --hw <hw dump> --hw-play <idx>    # against a hardware run
tools/perf/cache_report.py build/perf/base-cache/plugin.log --elf <elf>        # where cache misses come from
```

`summarize.py` skips the first 25 s after PLAY (`--skip`), when samples are still streaming in. Use `--skip 0` to
look at that cold phase.

| Column | Meaning |
| ------ | ------- |
| `ins/fr` | Render instructions per output frame: the most stable cost metric. ~5,700 for the default song. |
| `load%` | Render cycles over elapsed time. Near 90% means the firmware is at the limit and culling to stay there. |
| `culls/5s`, `voices` | The firmware's response to overload. Fewer culls and more voices at the same `ins/fr` means faster. |
| `L1I/kI`, `L1D/kI` | Cache-model misses per 1,000 instructions (cache mode only). |
| Per-function table | Instructions per frame per call, and calls per render, for the six scoped functions. Compare per call: a change in active units (more delays because fewer culls) isn't a change in cost. |

## 5. A/B a firmware change

1. Build probe ELFs for base and change from the same probe commit.
2. Run both in the same mode, ideally at the same time.
3. Compare `ins/fr` first; it barely varies between runs. Then `load%` and culls/voices.
   - **Culling is very sensitive near the limit:** a ~3% CPI change moves culls 2-3×. So treat a ±15% difference
     in culls between runs as noise, and repeat runs or lengthen them (`--slices 400`) before concluding.
   - **A faster change can show *more* instructions per frame** if it culls less, because more voices are playing.
     Check `voices` and the per-call table.
4. For memory or code-layout changes, use cache mode. Flat CPI can't see them.

## Gotchas

- **QEMU's PMU** only counts cycles (1 GHz of guest time), not instructions or cache events. Instruction and miss
  numbers come from the plugin; the probe ring gives frames, culls, voices and render cycles.
- **R lines are calls of `AudioEngine::routine()`,** which can render twice. `summarize.py` corrects with the probe's
  frames per render. Frames come from `AudioEngine::audioSampleTimer` (`timer=`). Never use the output ring
  (`head=`); it wraps at 128 frames.
- **The reverb scope** (`Reverb::process`) isn't seen by the plugin (devirtualised call). It's only in hardware data.
- **Time control freezes the clock while the CPU is halted** (WFE/WFI). The C firmware never halts. The Rust/Embassy
  firmware does, so use `--icount` for it. The plugin prints a warning if it happens.
- **Hardware's L1I refill counter (~12 per 1,000 instructions) is not a demand-miss count.** It includes fetch-ahead.
  The model's ~5 is the right order. Don't "fix" the model to match the counter (see the README).
- **Instruction hotspots**, not just cache ones: run the stock `libhotblocks` plugin as well
  (`-plugin qemu/build/contrib/plugins/libhotblocks.dylib,inline=on,limit=0`) and bucket with
  `scripts/dz_bucket.py <log> <elf>`.

## Hardware calibration (only when the user asks)

```sh
tools/perf/hw_probe.py load --elf <probe.elf>         # Black Magic Probe: monitor reset_halt, load into RAM, run
# the probe plays its song by itself; wait ~2.5 minutes without halting the device
tools/perf/hw_probe.py dump --elf <probe.elf> --out build/perf/hw.bin   # prints the AUTO state, incl. the PLAY window
tools/perf/hw_probe.py restore                        # back to the installed firmware
```

This needs a BMP firmware whose RZ/A1 driver has `monitor reset_halt` (watchdog reset). Don't halt the device while
the song loads: debugger halts can disturb SD and USB.
