# Tests

Emulation and regression tests for delugemu.

## Running everything: `run-all.sh`

```sh
./tests/run-all.sh                      # every test, PASS / SKIP / FAIL each
./tests/run-all.sh boot scenario        # a subset
./tests/run-all.sh --require-firmware   # what CI runs
```

Each test skips cleanly (exit 0) when something it needs is missing, which
makes a bare run safe anywhere but means "all green" can hide tests that never
ran. `run-all.sh` lists every outcome (logs in `build/test-logs/`, and a table
in the GitHub Actions job summary), and `--require-firmware` turns a skip into a
failure for the tests that only skip for want of firmware or an SD image (boot,
scenario, pad-click, usb-midi, usb-midi-bridge, audio-bench).

**CI** (`.github/workflows/build.yml`) builds the emulator and runs the suite
against real firmware fetched by `.github/actions/test-assets`: the latest
stable DelugeFirmware community release on Linux and macOS, plus the rolling
`beta` prerelease on Linux (non-blocking — it changes daily). The Linux and
macOS legs also build an SD image from the Synthstrom factory card. Windows runs
`smoke unit geometry-sync boot` (the other emulator tests use UNIX sockets).
Expected skips: `usb-peripheral` (no published firmware has peripheral USB
yet) and `midi-coremidi` off macOS.

## `smoke.sh`

The M0 acceptance check. After building (`scripts/build.sh`) it verifies that:

1. `qemu-system-arm` was produced, and
2. the `deluge` machine type is registered and can be instantiated.

```sh
./scripts/bootstrap.sh   # once
./scripts/integrate.sh   # once (re-run after adding/removing source files)
./scripts/build.sh
./tests/smoke.sh
```

It deliberately does **not** boot firmware — see `boot.sh` for that.

## `boot.sh`

The firmware-boot regression test. It boots a Deluge firmware image headless and
asserts that the boot reaches a healthy steady state:

1. **zero** Data Abort exceptions (a bad/unmapped MMIO access would raise one),
2. **zero** Prefetch Abort exceptions (a bad instruction fetch), and
3. a stream of IRQ exceptions (proves we reached the timer-driven main loop
   instead of spinning at the vector table).

Unimplemented-device-access warnings are **not** failures: several regions
(`rza1l.boot.mirror`, `rza1l.io.mid/high`) are deliberate catch-alls the
firmware probes constantly.

```sh
./tests/boot.sh                      # auto-locate firmware + SD image
DELUGE_FIRMWARE=path ./tests/boot.sh # explicit firmware
BOOT_SECONDS=15 ./tests/boot.sh      # widen the run window
```

Firmware is not shipped with the repo, so the test looks for
`firmware2/deluge.elf` then `firmware/deluge.elf` (override with
`DELUGE_FIRMWARE`) and **skips cleanly** (exit 0) when none is present. If
`build/deluge_sd.img` exists it also boots with the card attached, exercising
the SDHI path. Observed healthy counts: 19 IRQs without an SD image, 183 with
one, and 0 aborts in both cases.

## `audio-bench.sh`

The audio-throughput benchmark (roadmap M6). It drives the firmware through a
fixed worst-case synthesis load (loads the 127-sound `FAM1` song and presses
PLAY) while the SSIF production-rate probe records, per virtual second, how much
freshly rendered audio reaches the staging FIFO against the 352,800 B/s
real-time target, plus underruns and host wall-clock. Use it to A/B an emulator
(or firmware) change for an audio-throughput regression.

```sh
./tests/audio-bench.sh                          # auto-locate firmware + SD
./tests/audio-bench.sh --repeat 5               # average over 5 runs
./tests/audio-bench.sh --icount 2               # deterministic virtual clock
./tests/audio-bench.sh --throttle "taskpolicy -b"   # run qemu throttled (macOS)
./tests/audio-bench.sh --gate --min-production 90 --max-underruns 0  # CI gate
```

The regression signal is sharpest on a **throttled/slow host**, where the
emulated CPU can't render in real time and production drops below 100%; on a fast
host it confirms "still ~100%, no new underruns". Like the other tests it
**skips cleanly** (exit 0) when firmware, an SD image, or `python3` is absent.
Reads a clean stats stream via `DELUGEMU_SSIF_STATS=<path>`; needs
`scripts/dz_play.py` to drive the QMP load. See
[`docs/firmware-perf.md`](../docs/firmware-perf.md) for the caveats (the
production % pins ~100% under `--icount` by construction).

## `usb-midi.sh`

The USB host-MIDI enumeration regression test. It boots a firmware image with a
synthetic full-speed USB-MIDI device attached on the host port
(`-global rza1l-usb.midi=on`) and asserts that the firmware's USB host stack
enumerates it:

1. the control-transfer state machine reaches **SET_CONFIGURATION**
   (`RZA1L_USB_DEBUG` traces `SET_CONFIGURATION 1 -> configured=1`),
2. **zero** Data Abort / Prefetch Abort exceptions, and
3. the USBI interrupt actually fires (a non-trivial IRQ stream).

```sh
./tests/usb-midi.sh
DELUGE_FIRMWARE=path ./tests/usb-midi.sh
RUN_SECONDS=15 ./tests/usb-midi.sh
```

Like `boot.sh`, it **skips cleanly** (exit 0) when no firmware image is present.
Observed healthy counts: 44 IRQs, 0 aborts, 1 SET_CONFIGURATION.

## `midi-coremidi.sh`

Validates the host CoreMIDI bridge (`scripts/midi_bridge.c`) end to end on
macOS, **without** QEMU or firmware. The test plays both roles around the
bridge: it is the UNIX-socket server the bridge connects to (the same
`-chardev socket,...,server=on,wait=off` contract `run.sh` uses for a `coremidi`
transport), and it is the "DAW" opening the bridge's virtual CoreMIDI ports via
`python-rtmidi`. It checks both directions and the platform-agnostic stream
parser:

1. a CC sent to the virtual **output** port arrives on the socket as raw MIDI,
2. raw bytes written to the socket — using **running status**, an interleaved
   **real-time** byte and a **SysEx** — are framed into the correct discrete
   messages on the virtual **input** port.

```sh
./tests/midi-coremidi.sh
```

It **skips cleanly** (exit 0) when not on macOS or when `python-rtmidi` is not
installed.

## `scenario.sh`

The scripting-interface regression harness. It runs every scenario under
`tests/scenarios/` against a freshly launched headless emulator using the
[`delugemu`](../pylib) Python package, driving the front panel and asserting on
deterministic display state (OLED / 7-segment / indicator LEDs / pads) read back
over QMP. Each scenario runs its own instance with `-d int` logging so
`assert_no_aborts` works.

```sh
./tests/scenario.sh                          # all scenarios
./tests/scenario.sh tests/scenarios/boot.json
DELUGE_FIRMWARE=path ./tests/scenario.sh
DELUGEMU_FETCH_FIRMWARE=1 ./tests/scenario.sh   # download the latest release
```

Like `boot.sh`, it **skips cleanly** (exit 0) when no firmware or `python3` is
present. See [`docs/scripting.md`](../docs/scripting.md) for the full interface.

## `geometry-sync.sh`

Guards that the committed Python control map
(`pylib/delugemu/_controls.py`) is in sync with the C front-panel headers it is
generated from. If a control's geometry changes in C without regenerating, the
scripting interface would click the wrong pixels; this fails so the generator is
re-run (`scripts/gen_control_map.py`). Skips cleanly without `python3`.

## Adding tests

Keep tests runnable standalone and CI-friendly: exit non-zero on failure, avoid
interactive prompts, and don't depend on a real Deluge firmware image unless the
test explicitly fetches/locates one and skips cleanly when it is absent.

To have CI run a new test, add it to `ALL_TESTS` in `run-all.sh`, report a skip
as `<NAME> SKIP: <reason>` (the format `run-all.sh` detects), and add it to
`NEEDS_FIRMWARE` if firmware is the only thing it ever skips for. Prefer
locating firmware via `DELUGE_FIRMWARE` and an SD image via `DELUGE_SD_IMG`,
which is what CI exports.

## Driving the panel: the `delugemu` scripting interface

The standard way to script the emulator is the [`delugemu`](../pylib) Python
package (library + `delugemu` CLI + declarative scenario files), documented in
[`docs/scripting.md`](../docs/scripting.md). It wraps the raw QMP contract below
with named controls, deterministic display readout and assertions:

```sh
# one-shot verbs against a running instance (see "Expose the socket" below)
PYTHONPATH=../pylib python3 -m delugemu.cli press PLAY
PYTHONPATH=../pylib python3 -m delugemu.cli oled
# or a whole scenario, launching its own emulator
PYTHONPATH=../pylib python3 -m delugemu.cli run scenarios/transport.json \
    --firmware ../firmware/deluge.bin
```

The one-off helper scripts below (`press_key.py`, `enc_test.py`) predate the
package and are **superseded** by it; they remain only as thin raw-QMP examples.

### The raw QMP contract

QMP (the **QEMU Machine Protocol**) is QEMU's JSON control channel: a socket on
which you send commands to and query a running instance. We use it to drive the
emulated front panel programmatically — injecting mouse/keyboard input and
capturing the framebuffer — so panel behaviour can be exercised without a human
at the window.

**Expose the socket.** Pass a `-qmp` chardev through `run.sh` (anything after
`--` goes straight to QEMU). A Unix socket under `/tmp` is convenient and is
what the helper scripts expect:

```sh
./scripts/run.sh firmware2/deluge.elf --sd build/deluge_sd.img \
    --display console -- -qmp unix:/tmp/dz_qmp.sock,server,nowait
```

The socket is **single-client** (`nowait`): only one tool may be attached at a
time, so close one connection before opening the next.

**Talk to it.** Connect to the socket and exchange newline-delimited JSON. After
the greeting you must send `qmp_capabilities` once to leave negotiation, then
issue commands:

```sh
printf '%s\r\n' \
  '{"execute":"qmp_capabilities"}' \
  '{"execute":"human-monitor-command","arguments":{"command-line":"screendump /tmp/x.ppm"}}' \
  | nc -U -w1 /tmp/dz_qmp.sock
sips -s format png /tmp/x.ppm --out /tmp/x.png    # PPM -> PNG (macOS)
```

The two commands that matter for panel testing are:

- **`input-send-event`** — inject synthetic input. An `abs` x/y event moves the
  pointer (axis values are scaled `0..0x7fff` across the 2256×1584 skin), a
  `btn` `left` down/up pair is a click, `wheel-up`/`wheel-down` turn an encoder,
  and a `key` event with a `qcode` presses a bound key. To latch multiple
  controls, send a `key` `alt` down, click several pads/buttons, then `alt` up.
- **`screendump`** (via `human-monitor-command`, or the QMP `screendump`
  command) — write the current framebuffer to a PPM you can inspect or diff.

**Helper scripts.** Two ready-made drivers live in `scripts/` and assume the
socket at `/tmp/dz_qmp.sock`:

```sh
./scripts/press_key.py <qcode> <name>          # press a key, then screendump
./scripts/enc_test.py  <x> <y> <label> [up] [dn] # wheel an encoder at (x,y), screendump
```

