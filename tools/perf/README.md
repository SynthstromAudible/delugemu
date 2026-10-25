# Performance tools: cache model, cycle-timed emulation and hardware calibration

These measure where the Deluge firmware's audio render spends its time, and make the emulator run that render at
roughly the speed a real Deluge would, so CPU-bound behaviour (voice culling) can be studied without hardware.

| Piece | What it is |
| ----- | ---------- |
| `plugins/dzcache.c` | TCG plugin: A9/PL310 cache model, per-render and per-function accounting, cycle-driven guest clock. Build with `scripts/build-plugins.sh`. |
| `qemu-patches/0007` | Lets plugin time control actually drive `QEMU_CLOCK_VIRTUAL` under TCG without `-icount` (upstream QEMU leaves it on the host clock). |
| `tools/perf/run_emu.py` | Runs the probe firmware under the plugin, collects `plugin.log` and the probe's window ring. |
| `tools/perf/hw_probe.py` | Loads the probe firmware onto a Deluge through a Black Magic Probe, dumps its ring, restores. |
| `tools/perf/summarize.py` | Side-by-side table of runs and a hardware dump; per-function cost per active call. |
| `tools/perf/cache_report.py` | Functions ranked by modelled cache stall, and which data the misses hit. |
| `tools/perf/icache_replay.c` | Replays an instruction-fetch trace (`itrace=`) through L1I size/replacement/fetch-ahead variants. |

The firmware side is the DelugeFirmware branch `debug/pmu-render-probe`: a probe that records 100 ms windows of
render timing, culls, A9 PMU counters (cycles, instructions, L1 refills, I/D-cache stall cycles), inclusive costs of
six functions (`DzScope`) and delay-path counts, and that loads and plays a song by itself at boot
(`dzSongPath`, default "Make You A Deal 2"). Build it like any firmware; in a worktree,
`DBT_NO_SYNC=1 DBT_TOOLCHAIN_PATH=<main checkout> ./dbt build release`.

## Typical use

```sh
scripts/build-plugins.sh
tools/perf/run_emu.py --elf probe.elf --out runs/cpi145 --plugin timectl=1,cachesim=0,cpi=1.45 --lean  # ~70 s
tools/perf/run_emu.py --elf probe.elf --out runs/cpi145f --plugin timectl=1,cachesim=0,cpi=1.45  # + per-function, ~4.5 min
tools/perf/run_emu.py --elf probe.elf --out runs/cache  --plugin timectl=1,pfstreams=4,pfdist=4,l2pf=1  # ~8 min, calibrated defaults
tools/perf/summarize.py runs/cpi145 runs/cache --hw hw.bin --hw-play 136
tools/perf/cache_report.py runs/cache/plugin.log --elf probe.elf
```

Host audio is never connected (`--audio none`).

`--lean` (plugin `lean=1`) is the fast way to run firmware at Deluge speed: instructions are counted inline per
translation block and the clock advances every few thousand instructions, with no per-instruction callbacks, so an
80 s song runs in about 70 s instead of 4.5 minutes, with the same culling, voices and load. It has no per-render or
per-function accounting; drop `--lean` for those. The plugin assumes a single vCPU and takes no locks.

## Calibration (October 2026, "I'Ll Make You A Deal 2", 32 KiB-cluster card)

Hardware (RZ/A1L, 400 MHz, warm phase): render load 88%, 5,710 instructions and 7,933 cycles per output frame
(1.39 cycles/instruction), I-cache stalls 3.9% and D-cache stalls 11.6% of render cycles, 12.4 L1I and 5.3 L1D refills
per 1,000 instructions, soft-culling to 2-3 synth voices (45-63 culls per 5 s). `Delay::process` is about a third of
the render (the analog delay's IR convolution), the audio-clip path (`GlobalEffectableForClip::renderOutput`) 73%,
and the reverb the most cache-bound part (1.7 cycles/instruction).

Emulator: per active unit (per delay, per sound, per clip) the instruction counts match hardware; without culling it
just has more active units. With time control:

| clock | render ins/frame | load | culls/5 s | voices |
| ----- | ---------------- | ---- | --------- | ------ |
| hardware | 5,710 | 88% | 45-63 | 2.1-2.4 |
| `cpi=1.37` (flat) | 5,887 | 88% | 22 | 3.6 |
| `cpi=1.45` (flat) | 5,607 | 89% | 50 | 2.4 |
| cache model, first fit (penalties from PMU refill counts) | 5,914 | 88% | 14 | 4.2 |
| cache model, defaults (`cpi=1.30,pi=9,pd=25.6,pdev=60`) | 5,490 | 89% | 59 | 2.1 |

So `timectl=1,cachesim=0,cpi=1.45 --lean` is the quick stand-in for a Deluge, and the cache model with its defaults
the closer one (and the one to use when changing memory layout or code size).

### The I-cache "gap"

The A9's L1I refill counter reads 12 per 1,000 render instructions, the model 5-6. The counter isn't a demand-miss
count, though: the same renders spend only 3.9% of cycles (53 per 1,000 instructions) stalled on the I-cache, about
4 cycles per counted refill, where a demand miss served by the L2 costs ~20. Most counted refills are fetch-ahead
and wrong-path fetches that overlap execution; demand misses are more like 2.5-3 per 1,000 instructions, the
model's order. `tools/perf/icache_replay.c` replays an instruction-fetch trace (`itrace=`) through L1I variants: the
counter's 12 needs the fetch unit requesting 3-4 lines ahead, while the hot render code sits right at the 32 KiB
edge (16 KiB doubles the misses, 64 KiB removes four fifths).

So the cache model's timing penalties are fitted to the hardware's *stall cycles*, not its refill counts:
`pi=9` cycles per modelled I-miss, `pd=25.6` per D-miss, `pdev=60` per strongly-ordered/device access, and a base
`cpi=1.30` fitted so the emulator culls like the Deluge (1.26 gives 35 culls per 5 s, 1.30 59, 1.34 82; the
hardware 63). These are the plugin's defaults, and with them the model's L1D miss rate (5.1 per 1,000 instructions)
and voice count (2.1) match the hardware.

The PL310 is r3p2, 128 KiB, 8-way, 32-byte lines, round-robin replacement, next-line I and D prefetch; its event
counters read zero because AUX_CONTROL bit 20 (event monitor bus) is off and can only be set with L2 disabled.

## Caveats

- Time control freezes the guest clock while the vCPU is halted (WFE/WFI). The C firmware busy-waits, so that's fine;
  firmware that idles in WFE (the Rust/Embassy BSP) needs `-icount`. The plugin warns if it happens.
- The plugin's per-render `timer=` must be `AudioEngine::audioSampleTimer`; counting frames from the output ring
  (`head=`) wraps at 128 frames and under-counts when the render falls behind.
- Cache penalties are fitted averages, not a timing model of the A9 pipeline or the SDRAM.
