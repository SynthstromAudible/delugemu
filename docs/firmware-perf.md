# Firmware performance — findings and tooling

## The problem in one paragraph

Under dense synthesis load the emulated Cortex-A9 can't always render audio at
real time, causing occasional breakup. This is a **TCG throughput limit, not a
buffering one**, and it cannot be closed from the host side: rebuilding QEMU
with `-O3 -march=native` gives **zero** improvement (the audio hot path is
JIT-generated guest code, not statically-compiled QEMU C), and the guest is
single-core so MTTCG can't help. The only lever is the **firmware**: do less
work in the render path. In TCG, cost is ≈ proportional to guest instructions
retired, so reducing guest instructions translates almost 1:1 into speedup. The
real-time target is **44100 × 8 = 352,800 B/s** sustained.

## Hard constraint: portable wins only

We pursue **only** changes that also help (or are neutral) on real Cortex-A9
hardware — the DelugeFirmware maintainers reject emulator-only changes. This
rules out softfloat→host-SSE shims, "scalar beats NEON under TCG" rewrites
(NEON is slower under TCG but faster on HW), and any TCG-block / translation-
boundary trick. Profiling is used **only to rank guest-instruction-count
hotspots**, which is a portable ranking; TCG does not model cache/pipeline
timing.

## Key finding: the scheduler is where the firmware idles, and you must profile the Release build

`firmware/deluge.elf` is byte-identical to `build/Debug/deluge.elf` (`-Og`, no
LTO). **Real hardware ships the Release build** (`-O2 -flto=auto`), which must be
built and profiled separately:

```sh
firmware/DelugeFirmware/toolchain/current/cmake/bin/cmake \
    --build firmware/DelugeFirmware/build --config Release   # ~46s
# -> firmware/DelugeFirmware/build/Release/deluge.elf
```

At `-O2` the scheduler helpers that dominate the *Debug* profile
(`Time::operator<=>`, `Task::isReady`, `Task::isRunnable`) are **fully inlined**
and vanish as symbols, and the `double` time constants fold away (no soft-float
in the hot path).

**The scheduler's share of instructions measures idle time, not scheduler cost.**
When no task is ready, the dispatch loop re-runs `chooseBestTask` (three O(N)
passes over all tasks) + `checkConditionalTasks` (O(25)) + `runHighestPriTask`
and loops: a busy-spin, which is how the firmware waits. So the less work there
is, the bigger the scheduler looks. An earlier version of this table (dense
`FAM1.XML`, no `--icount`, host clock) put `chooseBestTask` at 74.9% and the
scheduler at ~91%. That run was idle-diluted: on the host clock the guest runs
much faster than a Deluge and spends most of its time waiting. It is not the
load on a real Deluge playing a song.

Release profile while a song plays, at Deluge speed (2026-10-25): probe firmware
(`debug/pmu-render-probe`, community d2bfbf188), "Make You A Deal 2",
`tools/perf/run_emu.py --plugin timectl=1,cachesim=0,cpi=1.45 --lean --slices 400
--hotblocks`. Render load **88.7%**, with the firmware culling voices to stay
there. 39.4 B instructions over ~100 s of playback. Boot and song load are
subtracted using a second run stopped at PLAY:
`scripts/dz_bucket.py <run>/plugin.log <elf> 40 --minus <toplay>/plugin.log`.

| Symbol | % of guest instructions |
|--------|------------------------|
| `Delay::process` | **28.6%** |
| `Freeverb::process` | 8.2% |
| `LpLadderFilter::doFilterStereo` | 7.7% |
| `ModControllableAudio::processFX` | 7.6% |
| `HpLadderFilter::doFilterStereo` | 7.0% |
| `processReverbSendAndVolume` | 3.2% |
| `GlobalEffectableForClip::renderOutput` | 2.9% |
| `processSRRAndBitcrushing` | 2.6% |
| `Sound::render` | 2.3% |
| `RMSFeedbackCompressor::render` | 1.4% |
| `TaskManager::chooseBestTask` | 7.7% |
| `getSecondsFromStart` + `checkConditionalTasks` + `runTask` + `runHighestPriTask` | 2.0% |
| **scheduler subtotal** | **9.7%** |
| probe instrumentation (`dzProbeWindow`, `DzScope`) | 1.3% |

The scheduler's 9.7% is close to the 11.3% of time not spent rendering. For
comparison, over boot and song load (5.0 B instructions, mostly waiting) the same
firmware spends 48% in `chooseBestTask` alone. In lean mode time is proportional
to instructions (flat CPI), so these shares are shares of time too. The cache
model (`run_emu.py` without `--lean`) charges render code more per instruction
than the cache-hot spin loop, so render's real share of time is a little higher.

**Consequence:** at high load the scheduler mostly drops out, and render DSP is
what limits how many voices play. `chooseBestTask` is the right target only for
latency (how soon a ready task starts) or power, not for render capacity.
Cutting its per-call cost still matters a little at high load, as the spin
between renders gets shorter, but it can't buy back more than the ~10% the
firmware isn't already rendering.

## Useful tools (built and proven)

| Tool | Where / how | Why it's useful |
|------|-------------|-----------------|
| **`libhotblocks`** | `qemu/build/contrib/plugins/`; pass via `run.sh … -- -plugin <path>/libhotblocks.dylib,inline=on,limit=0 -d plugin -D <log>` | **The** hotspot tool. Per-basic-block `pc, tcount, icount, ecount`; weight `icount × ecount`, bucket by `nm` symbol for a gprof-style flat profile. |
| **`scripts/dz_bucket.py`** | `dz_bucket.py <hb.txt> <deluge.elf> [top_n]` | Buckets a hotblocks report into a ranked %-of-guest-instructions table by symbol (uses `arm-none-eabi-nm -n` + `c++filt`). |
| **`scripts/dz_topblocks.py`** | `dz_topblocks.py <hb.txt> <deluge.elf> [top_n]` | Maps the hottest individual blocks to source lines via `addr2line` (Python — macOS `awk` lacks `strtonum`). Use to see *which lines* inside a hot function dominate. |
| **`scripts/dz_play.py`** | `dz_play.py /tmp/dz_qmp.sock "<timed key seq>"` | Scripted QMP key driver for a repeatable load. Canonical run: `"6.0:_wait 0:l:tap 3.0:ret:tap 8.0:spc:tap 14.0:_quit"` (boot 6 s, LOAD `l`, SELECT-click `ret` loads highlighted `FAM1`, PLAY `spc`). |
| **`tests/audio-bench.sh`** | `tests/audio-bench.sh [--repeat N] [--icount S] [--throttle CMD]` | Wraps `dz_play.py` + `DELUGEMU_SSIF_STATS` into a one-shot throughput A/B: drives the FAM1 worst-case load and reports mean/min production %, total underruns, and host wall-clock. The regression signal is sharpest on a throttled host (`--throttle "taskpolicy -b"`); on a fast host it confirms "still ~100%, no new underruns". Add `--gate --min-production <pct> --max-underruns <n>` for a pass/fail CI gate. Reads a clean stats stream via `DELUGEMU_SSIF_STATS=<path>`. |
| **`--icount N`** (`run.sh --icount`) | built in | Deterministic, instruction-exact runs **and** the lever that forces CPU saturation (see idle dilution below). Use `--icount 2`; cross-check `4`. |
| **`DELUGEMU_SSIF_STATS=1`** | SSIF device, built in | Per-virtual-second audio production rate (B/s, % of 352,800), underruns/s, FIFO occupancy. Counted at the staging FIFO, so with `--tx-render-head <addr>` it reflects what was *actually rendered*. Set to a **path** instead of `1` to write the stats stream to a file (used by `tests/audio-bench.sh` to avoid scraping stderr). **Caveat: wall-clock delivery gate** — on a fast host it pins ~100% even under load. Use it to confirm no *regression*, not as the primary lever. |
| **`DELUGEMU_SDHI_STATS=1`** | SDHI device, built in | Per-virtual-second SD activity: commands, KiB read/written, busy % split into bus time and buffer wait (block waiting on the firmware/DMA), and interrupt service latency (avg/max µs from the SDHI raising its interrupt to the firmware reading its status). The SDHI models real card/bus timing (see `register-coverage.md` § SDHI), so a busy figure near 100% means the firmware is SD-bound, as it would be on hardware. Tune the card with `-global rza1l-sdhi.read-latency-us=…` (and `write-block-us`, `write-busy-us`); `-global rza1l-sdhi.timing=off` restores the old instant SD for an A/B. |
| **`DELUGEMU_SSIF_DUMP=<path>`** | SSIF device, built in | Raw S32LE stereo capture **before** the resampler, for spectral / by-ear spot-checks. Perceptual only (see "Validation reality"). |
| **`dzcache` plugin + `tools/perf/`** | `plugins/dzcache.c`, `scripts/build-plugins.sh` | A9/PL310 cache model, per-render and per-function accounting, and a cycle-driven guest clock (`timectl=1`, needs `qemu-patches/0007`). `cpi=1.45` reproduces a real Deluge on a CPU-bound song (load, culling, voices), calibrated against hardware PMU counters. See [tools/perf/README.md](../tools/perf/README.md). |
| **`arm-none-eabi-nm` / `-objdump` / `-addr2line` / `-c++filt`** | `/opt/homebrew/bin` | Map addresses to symbols/source. The ELF carries full `debug_info`. Re-derive the render head per build: `nm <elf> \| grep i2sTXBufferPos`. |
| **before-copy A/B** | `build/perf-baseline/deluge-release-before.elf` (gitignored) | Keep a pristine Release ELF when editing firmware so you can profile old vs new on the **same** workload. |

### Reproducing a profile

1. Build Release (above). Derive the render head:
   `arm-none-eabi-nm firmware/DelugeFirmware/build/Release/deluge.elf | grep i2sTXBufferPos`
   (currently `0x20031f2c`; the Debug ELF differs).
2. Launch headless with hotblocks:
   ```sh
   ./scripts/run.sh <elf> --display headless --audio none \
     --tx-render-head 0x20031f2c --sd build/deluge_sd.img \
     -- -qmp unix:/tmp/dz_qmp.sock,server,nowait \
     -plugin qemu/build/contrib/plugins/libhotblocks.dylib,inline=on,limit=0 \
     -d plugin -D /tmp/hb.txt </dev/null >/tmp/run.log 2>&1 &
   ```
3. Drive the load: `python3 scripts/dz_play.py /tmp/dz_qmp.sock "6.0:_wait 0:l:tap 3.0:ret:tap 8.0:spc:tap 14.0:_quit"`.
4. Bucket: `python3 scripts/dz_bucket.py /tmp/hb.txt <elf> 20`.

SD card: `./scripts/mksd.sh sdcard build/deluge_sd.img`. Worst-case song ranking:
`FAM1` (127 sounds) > `FAM3` (129) > `FAM2` (10) > `SONG010` (2).

**Idle-dilution caveat:** the scheduler is where the firmware waits, so its
share tracks idle time (see the key finding above). On a fast host the guest
keeps up and idle-spins in the scheduler, so an unsaturated profile is ~70%+
scheduler with DSP buried. For a Deluge-like profile, use `tools/perf/run_emu.py
--hotblocks` with `timectl=1` (Deluge speed) and a song that loads the CPU. Run
under `--icount 2` to saturate. At `--icount 4`+ the firmware's adaptive
voice-culling activates (synth voices drop, master-bus work remains) — read both
a moderate and a deep-saturation profile.

## Not useful here (don't reach for these)

- **`libhwprofile` / `libhotpages`** — `hwprofile` is a *device-IO* access
  profiler, not a guest-PC profiler. Wrong tool for instruction hotspots.
- **`libhowvec`** — its classifier is **AArch64-only**. The Deluge is ARM32
  Thumb-2, so everything shows "Unclassified"; you must decode top opcodes by
  hand. (We already know the render path is overwhelmingly fixed-point/integer.)
- **`liblockstep`** — finds the first execution divergence; useful for
  *emulator* determinism, **useless as a firmware-change audio gate** (two
  different firmware builds diverge immediately by construction).
- **`libcache`** — advisory only; TCG does not model real A9 cache/timing.
- **QEMU `-audiodev wav`** — rejects 32-bit formats (the SSIF voice is S32) and
  sits *after* the host-timing-dependent output resampler. Use `DELUGEMU_SSIF_DUMP`
  instead.
- **Host QEMU compiler flags (`-O3 -march=native`)** — zero effect on guest
  (JIT) code.

## Validation reality (what actually gates a change)

A whole-system byte-exact `.wav`/raw A/B diff **does not work here**, for three
independently-fatal reasons (all measured): the `wav` audiodev can't capture the
S32 stream; the `DELUGEMU_SSIF_DUMP` capture isn't bit-reproducible run-to-run
(`-icount …,sleep=on` warps virtual time during guest idle, so the sampler emits
a non-uniform frame count); and oscillator phase accumulators free-run from boot
so any one-sample timing shift changes every subsequent sample across builds.

Working gates instead:

- **Structural / scheduler changes:** sample-neutral *by construction* (they
  change *when* tasks run, not the DSP math or its inputs). Gate = code review
  (DSP call order and arguments unchanged) + `DELUGEMU_SSIF_STATS` showing no
  throughput regression.
- **Intentional DSP approximations / LUTs:** **offline kernel null-test** — drive
  old vs new math over the full input domain in a small host harness (no
  emulator) and bound the worst-case error in dB / ULP. Build the harness
  alongside the change.
- **`DELUGEMU_SSIF_DUMP`:** spectral / by-ear spot-check only; capture with
  `sleep=off` to stay closer to real time.

## What we tried and ruled out (do not retry)

- **Hand-inline the scheduler helpers** (`Time::operator<=>`, `isReady`, …) —
  **already done by `-O2`** on real hardware; redundant and would be rejected
  upstream. (Only appears as a win in the misleading *Debug* profile.)
- **`chooseBestTask`: collapse `isReady()`→`isReleased()` after `isRunnable()`
  + CSE the finish-time** — sound in theory, but in the idle regime the original
  `isReady()` calls are short-circuited to *zero* evaluations, so computing
  `isReleased()` unconditionally *adds* work: ~1300 → ~1407 instr/call (**+8%**).
- **`chooseBestTask`: O(1) idle early-out via cached `min(earliestCallTime)`** —
  the guard never fires. The spin is **not release-time-bound**: the audio task
  (priority 0, `RESOURCE_NONE`, `backOff ≈ 181 µs`) plus overdue tasks keep
  `min(earliestCallTime) ≤ now`, and readiness is gated by
  `idealCallTime`/`latestCallTime`/state/resources, not `earliestCallTime`. The
  only correct "is anything ready" test is the O(N) scan itself.

**A/B metric note:** the throughput gate is wall-clock-bound, so raw
`chooseBestTask` % and total instruction count are **not** valid A/B signals (a
cheaper call just lets the idle loop spin more). The only confound-free metric
is **instructions per `chooseBestTask` call** = (its total instructions) ÷ (its
entry-block execution count, col 4 of the hotblocks report at the symbol PC).

**Open lever (not attempted):** an **event-driven next-wake** redesign —
compute the next time any task transitions to ready and skip dispatch until
then — on the maintainers' core scheduler. As the spin is idle time, this would
cut wasted instructions and power, not add render capacity. It carries genuine
timing-behavior risk, so it is deferred pending explicit direction.

## DSP levers (the main lever at high load)

- **`RMSFeedbackCompressor`** (master bus, always-on) — `render` + `calcRMS`
  driven by `expf`/`logf`. Clean LUT candidate gated by an offline kernel
  null-test, but only ~0.5% of instructions.
- **Per-voice DSP** — `Freeverb::process` (~1%), `Sound::render` (~0.8%),
  `Lp`/`HpLadderFilter` (~0.6%), oscillator/wavetable kernels, voices. All
  fixed-point `long` (Q31). Block-processing raises the polyphony ceiling,
  which is what's limiting at high load (render is ~89% of time on "Make You A
  Deal 2"). The shares above came from the idle-diluted FAM1 profile; on that
  song `Delay::process` (28.6%), Freeverb (8.2%), the ladder filters (~16%) and
  `processFX` (7.6%) lead.

Other clean HW-portable wins if/when the DSP becomes the bottleneck: FPSCR
flush-to-zero / default-NaN (if any FP appears — denormals are catastrophic on
softfloat *and* real VFP/NEON), skipping idle/silent voices, and reducing
inaudible oversampling.

## Prerequisites

- DelugeFirmware source + `arm-none-eabi` toolchain are wired up locally
  (profiling alone needs only the existing ELF; acting on findings needs the
  rebuild).
- Upstreaming path: land wins as DelugeFirmware PRs with sample-neutrality or
  offline-null-test evidence attached.
