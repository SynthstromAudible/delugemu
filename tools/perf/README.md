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
| `tools/perf/firmware/tick-probe.patch` | The song-tick probe: a DelugeFirmware patch that records tick vs render cost, voice starts and culls (see below). |
| `tools/perf/ticks.py` | Reads the tick probe's per-render ring: do culls line up with song ticks? |
| `tools/perf/set_song.py` | Patches the song the probe autoplays (`dzSongPath`) in a probe ELF, without rebuilding. |
| `tools/perf/gen_tickload.py` | Writes test songs that start many voices on every sequencer step, optionally with effects. |
| `tools/perf/check_song.py` | Boots firmware, loads a song through the browser, presses PLAY and checks it plays without aborts. |

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

## Song-tick probe

The render probe answers "how expensive is the render". The tick probe answers "how much does the song tick add on
top, and is that what culls voices". Each song tick (`AudioEngine::tickSongFinalizeWindows()` ->
`PlaybackHandler::actionTimerTick()` / `actionSwungTick()`) runs just before a render and starts that tick's notes,
so a tick that starts many voices lands as a spike on one render.

`tools/perf/firmware/tick-probe.patch` is one commit against DelugeFirmware main (680b93c). Everything is in
`src/deluge/io/debug/dz_probe.{h,cpp}` behind `DZ_PROBE`, plus small hooks; it is not for merging.

```sh
cd DelugeFirmware && git checkout -b perf/tick-probe 680b93c && git am <delugemu>/tools/perf/firmware/tick-probe.patch
./dbt build release            # or cherry-pick the commit onto the branch you want to measure
```

It keeps the render probe's ring (`dzProbe`, so `run_emu.py` and `summarize.py` work unchanged) and adds:

- per-window tick fields (`dzprobe.TICK_FIELDS`): ticks, tick cycles, render cycles of renders with and without a
  tick, voices started in the tick / from pending / refused by `allowedToStartVoice()`, culls split into kill /
  terminate / force-release and hard / soft events, culls by renders since the last tick, direness, margin, and
  `songTickCost`;
- `dzRenders`, a ring of the last 16,384 renders (about 8 s): tick and render cycles, buffer space, samples, voices
  started, culls, voices, direness and predicted margin for each render;
- DzScope on six tick-path functions instead of the DSP ones: `actionSwungTick`, `InstrumentClip::processCurrentPos`,
  `NoteRow::processCurrentPos`, `Sound::noteOnPostArpeggiator`, `Voice::noteOn` and the pending-note start;
- autoplay: once the card is ready it loads the alphabetically first `/SONGS/*.XML` whose name contains `dzSongPath`
  (default `TICKLOAD`), then presses play.

```sh
tools/perf/gen_tickload.py --outdir sdcard/SONGS      # the standard TICKLOAD set (see Test songs)
scripts/mksd.sh sdcard build/deluge_sd_tick.img
tools/perf/set_song.py probe.elf TICKLOAD_N30          # optional: pick another song
tools/perf/run_emu.py --elf $PWD/probe.elf --sd build/deluge_sd_tick.img --out runs/n30 \
    --plugin timectl=1,cachesim=0,cpi=1.45 --lean --all-renders
tools/perf/summarize.py runs/n30 --skip 5              # adds a song-tick table
tools/perf/ticks.py runs/n30/renders_all.bin --list 10 # culls by renders since the last tick, renders around culls
```

`--all-renders` dumps the per-render ring at every poll and merges the dumps, so `renders_all.bin` covers the whole
run instead of the last 8 s. In lean mode the guest clock advances every few thousand instructions, so a single
short interval (one note-on) reads quantised to ~10 us; use sums and averages, or full mode, for those.

### Test songs: `gen_tickload.py`

`gen_tickload.py` writes Deluge song XML files that start many voices together on every 16th step. They are used
to measure how much the song tick (`PlaybackHandler::actionTimerTick` → clips → NoteRows → `Sound::noteOn`) adds
on top of the audio render.

- Defaults: 120 BPM, a one-bar loop, 20 voices per step (5 synth clips × 4-note chords).
- Each note lasts one step with the shortest release, so the voice count stays near N. The load spike comes from
  starting notes, not from voices piling up.
- Sounds are subtractive synths only, so nothing streams from the SD card.
- Optional effect chains run on every sound, at kit level and at song (master) level. They exercise effect units
  that allocate buffers and cost CPU in the render.

The script uses the Python 3 standard library only. Every tag, attribute and value encoding comes from the
firmware's song read/write code; the script's comments cite the functions.

```sh
tools/perf/gen_tickload.py --outdir sdcard/SONGS          # standard set (identical existing files are left alone)
tools/perf/gen_tickload.py --outdir sdcard/SONGS --only FXALL,GRAIN
tools/perf/gen_tickload.py -o SONGS/X.XML --clips 4 --chord 6 --bpm 140
tools/perf/gen_tickload.py -o SONGS/K.XML --kit 24                       # one kit, 24 synth drum rows
tools/perf/gen_tickload.py -o SONGS/A.XML --fx-set modfx=phaser,delay=8thT,analog,reverb=30 --song-fx comp,reverb=digital
tools/perf/gen_tickload.py -o SONGS/B.XML --fx-all --fx-vary --clips 7 --voices 20 --song-fx all
tools/perf/gen_tickload.py -o SONGS/C.XML --kit 20 --fx-set modfx=grain --kit-fx delay,comp,sidechain
tools/perf/gen_tickload.py --check SONGS/*.XML    # static check, voices started per step, active FX units
```

#### Effects

`--fx-set`, `--song-fx` and `--kit-fx` each take a comma-separated list of `UNIT[=VALUE]`.

- `all` turns on every unit except `route`.
- `--fx-all` is the same as `--fx-set all`.
- `--fx-vary` varies the effects from sound to sound:
  - The modFX type cycles through all seven types.
  - The LPF and HPF modes cycle.
  - Each sound gets one of the selected distortion units in turn.
- The older `--fx` flag (reverb and delay sends only) still works and produces the same output as before.

| unit | sounds | kit | song | value | what it turns on |
|---|---|---|---|---|---|
| `modfx` | ✓ | ✓ | ✓ | `flanger` `chorus` `phaser` `stereochorus` `warble` `dimension` `grain` (default `chorus`) | modFX buffer, or a GranularProcessor with a 512 KiB grain buffer. At song and kit level the file also sets `modFXCurrentParam="depth"`; without that, `getActiveModFXType` turns the effect off. |
| `delay` | ✓ | ✓ | ✓ | sync: `16th` `8th` `8thT` (triplet) `4thD` (dotted) … `off` (default `16th`) | delay buffer, ping-pong |
| `analog` | ✓ | ✓ | ✓ | – | analog delay model |
| `reverb` | ✓ | ✓ | ✓ | send 0..50 (default 20). Song level: `freeverb` `mutable` `digital` | send into the global reverb; at song level also the reverb model |
| `bitcrush`, `srr` | ✓ | ✓ | ✓ | 0..50 | bitcrusher, sample-rate reduction |
| `clip` | ✓ | ✓ | – | 0..15 (default 5) | saturation (`clippingAmount`) |
| `fold` | ✓ | – | – | 0..50 | wavefolder, per voice |
| `eq` | ✓ | ✓ | ✓ | -50..50 (default +15) | bass and treble shelves |
| `lpf`, `hpf` | ✓ | ✓ | ✓ | `12dB` `24dB` `24dBDrive` `SVF_Band` `SVF_Notch` / `SVF_Band` `SVF_Notch` `HPLadder` | filter mode. `hpf` also switches the HPF on; `lpf` at song and kit level also lowers the cutoff. |
| `route` | ✓ | ✓ | ✓ | `H2L` `L2H` `PARA` | filter routing |
| `comp` | ✓ | ✓ | ✓ | threshold 0..50 (default 35) | compressor. For sounds and kits it is on when `compressorThreshold` > 0. For the song it sets the master compressor's `thresh`. |
| `sidechain` | ✓ | ✓ | – | depth 0..50 | The first sound sends sidechain hits (`sideChainSend`). The other sounds duck through a `compressor` → `volumePostReverbSend` patch cable, and a kit through `sidechainCompressorVolume`. |

Stutter is not offered: it only runs while the stutter knob is held, so a song file cannot switch it on.

#### Variants and the probe

The standard set lives directly in `SONGS/`:

| file | contents |
|---|---|
| `TICKLOAD.XML` | default |
| `_KIT20` | one kit with 20 synth rows |
| `_N10` / `_N30` | 10 or 30 voices per step |
| `_FX` | reverb and delay sends |
| `_U4` | unison 4 |
| `_FXALL` | full chain on every sound plus all master FX |
| `_FXVARY` | 7 clips with every modFX type and different distortion and filter modes |
| `_GRAIN` | grain modFX on every sound and on the master |
| `_KITCHAIN` | kit of 20 rows with varied full chains, plus kit-level and master FX |

The probe firmware autoplays the alphabetically first (strcasecmp) `*.XML` directly in `/SONGS` whose name contains
`dzSongPath`. Because `.` sorts before `_`, `TICKLOAD` selects `TICKLOAD.XML`, and each variant suffix selects its
own file. The generator checks this when it writes the set and warns if other files in the directory break it.
FAT directory order cannot be used for this, because `mksd.sh` copies files in host readdir order.

`tools/perf/check_song.py ELF SDIMG /SONGS/NAME.XML OUTDIR` checks that a song loads and plays on a given firmware
(no error popup, PLAY lit, no aborts), with OLED screenshots in OUTDIR.

## Caveats

- Time control freezes the guest clock while the vCPU is halted (WFE/WFI). The C firmware busy-waits, so that's fine;
  firmware that idles in WFE (the Rust/Embassy BSP) needs `-icount`. The plugin warns if it happens.
- The plugin's per-render `timer=` must be `AudioEngine::audioSampleTimer`; counting frames from the output ring
  (`head=`) wraps at 128 frames and under-counts when the render falls behind.
- Cache penalties are fitted averages, not a timing model of the A9 pipeline or the SDRAM.
