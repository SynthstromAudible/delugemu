# Scripting the emulator (`delugemu`)

`delugemu` is the standard interface for driving the emulator from code: a
Python library, a CLI, and a declarative scenario format. Use it to write
integration tests, run them in CI as a GitHub Action, and capture bug
reproductions as shareable, re-runnable files.

It drives the front panel over **QMP** (QEMU's JSON control socket) using the
same `input-send-event` path a real click takes, and reads back **deterministic
display state** through read-only `qom-get` properties the device models expose
— so tests assert on the actual OLED / 7-segment / LED / pad state rather than
diffing screenshots.

The package lives in [`pylib/`](../pylib) and is **stdlib-only** (no `pip`
install needed to run it from the repo; YAML scenarios need the optional
`pyyaml` extra).

## Quick start

```python
from delugemu import DelugeSession, Control

# Launch a headless emulator (via scripts/run.sh), drive it, assert, tear down.
with DelugeSession.launch(firmware="firmware/deluge.bin",
                          int_log="/tmp/int.log", boot_wait=4.0) as dz:
    dz.assert_no_aborts()            # nothing faulted during boot
    dz.press(Control.PLAY)           # tap the PLAY button
    assert dz.read_leds()["PLAY"]    # the PLAY indicator lit
    dz.screenshot("playing.png")
```

Controls are named by the **`Control` enum** (`Control.PLAY`, `Control.SELECT_ENC`,
…) — the single, discoverable, typo-proof list, generated from the C skin table.
Every method that takes a control also accepts the equivalent name string
(`"PLAY"`, case-insensitive), so JSON/YAML scenarios and the CLI — which can't
carry a Python object — keep using names. `list(Control)` or `delugemu controls`
enumerates them.

Attach to an already-running instance instead of launching one:

```python
dz = DelugeSession.attach("/tmp/dz_qmp.sock")
```

To expose that socket from `run.sh`, pass it through after `--`:

```sh
./scripts/run.sh firmware/deluge.bin --display none \
    -- -qmp unix:/tmp/dz_qmp.sock,server,nowait
```

> **Keep the QMP socket path short.** A unix-socket path has a hard OS limit
> (`sun_path`, ~104 chars on macOS); a longer one fails with `AF_UNIX path too
> long`. Use a short path like `/tmp/dz_qmp.sock`, not a deeply nested temp
> directory.

Runnable examples of the whole API live in [`pylib/examples/`](../pylib/examples)
(boot + screenshot, transport + LED assertions, encoder/pad navigation, and
attaching to a live instance).

## Library API (`DelugeSession`)

Lifecycle
- `DelugeSession.launch(firmware=None, sd=None, icount=None, headless=True, int_log=None, boot_wait=0.0, extra_qemu=(), artifacts_dir=None)` — start the emulator via `scripts/run.sh` and connect. `firmware=None` lets `run.sh` resolve one (local image, or a download when enabled — see below). Pass `int_log=` to enable `assert_no_aborts()`.
- `DelugeSession.attach(sock="/tmp/dz_qmp.sock")` — connect to a running instance.
- `close()` / context manager — quit QEMU (if launched) and disconnect.

Input (controls are a `Control` enum member — e.g. `Control.PLAY` — or its name string; `delugemu controls` / `list(Control)` lists them)
- `press(name, hold_ms=120)` — tap a button or encoder push-click (`Control.PLAY`, `Control.SHIFT`, `Control.SELECT_ENC`, …).
- `hold(name)` / `release()` — press and keep held, then release.
- `turn(name, delta)` — turn a rotary encoder `delta` detents (negative = CCW).
- `pad(x, y, hold_ms=120)` — tap pad grid cell. Columns 0–15 are the main grid, 16/17 the sidebar; row 0 is the bottom.
- `key(qcode)` — press a host key by QMP qcode (`"spc"`, `"a"`, `"1"`).
- `latch([names])` — context manager latching several controls down at once.

Readout (deterministic, via `qom-get`)
- `read_oled()` → 48×128 list of bools; `oled_text()` → `#`/`.` rows; `oled_on()` → bool.
- `read_segment()` → best-effort 4-char 7-segment text.
- `read_leds()` → `{control_name: bool}` for every indicator LED.
- `read_pads()` → 18×8 grid of `(r, g, b)`; `read_gold_knob()` → `[2][4]` brightness.
- `screenshot(path)` → PNG (falls back to PPM if the build lacks PNG screendump).

Timing & assertions
- `wait(seconds)`, `wait_until(predicate, timeout, poll)`.
- `assert_led(name, on=True)`, `assert_segment(text)`, `assert_oled_contains(marker)`, `assert_no_aborts()` (needs `int_log`).

## CLI

```sh
delugemu run <scenario.json> [--firmware P] [--sd P] [--icount N] [--artifacts DIR]
delugemu press PLAY            # one-shot verbs against a running --sock instance
delugemu turn SELECT_ENC 4
delugemu pad 0 0
delugemu key spc
delugemu shot out.png
delugemu oled | seg | leds [--all] | pads
delugemu controls             # list every known control name
```

`run` launches its own emulator unless you pass `--sock` (then it attaches).
The one-shot verbs attach to `--sock` (default `/tmp/dz_qmp.sock`).

From the repo without installing: `PYTHONPATH=pylib python3 -m delugemu.cli ...`.
Installed (`pip install -e pylib`): the `delugemu` command.

## Scenario files (bug repros and tests)

A scenario is a JSON document (YAML too, with `pip install pyyaml`). It is the
shareable repro artifact: attach the file plus the firmware you used to an
issue, and anyone runs `delugemu run repro.json`.

```json
{
  "name": "enter-song-view",
  "firmware": null,
  "sd": null,
  "icount": 6,
  "boot_wait": 4.0,
  "steps": [
    {"assert_no_aborts": true},
    {"press": "PLAY"},
    {"wait": 0.5},
    {"assert_led": ["PLAY", true]},
    {"turn": ["SELECT_ENC", 4]},
    {"pad": [0, 0]},
    {"screenshot": "song.png"},
    {"assert_segment": "120"}
  ]
}
```

Each step is a one-key object. Verbs map 1:1 to `DelugeSession` methods:
`wait`, `press`, `key`, `turn`, `pad`, `hold`, `release`, `screenshot`,
`assert_led`, `assert_segment`, `assert_oled_contains`, `assert_no_aborts`.
Arguments accept a shorthand (`{"press": "PLAY"}`) or a mapping
(`{"press": {"name": "PLAY", "hold_ms": 150}}`). Set `icount` for a
deterministic virtual clock when you need exact, reproducible timing.

Example scenarios live in [`tests/scenarios/`](../tests/scenarios).

## Firmware resolution

Firmware is not shipped with the repo. `run.sh` (and therefore the library and
CLI) resolves an image in this order:

1. an explicit path — the `firmware=` argument, or `$DELUGEMU_FIRMWARE` / `$DELUGE_FIRMWARE`;
2. a `.bin`/`.elf` already in the firmware folder (`$DELUGEMU_FIRMWARE_DIR`, default `firmware/`);
3. **the latest GitHub release**, when `DELUGEMU_FETCH_FIRMWARE=1` (or `DELUGEMU_FIRMWARE_REPO` is set). The repo defaults to the upstream community firmware and is configurable via `DELUGEMU_FIRMWARE_REPO=owner/repo`; `GITHUB_TOKEN` is used when present to avoid API rate limits;
4. otherwise an interactive prompt (local dev only).

Tests and CI **skip cleanly** (exit 0) when no firmware is available, so the
jobs stay green without shipping proprietary firmware.

## Tests and CI

- `tests/scenario.sh` — runs every scenario in `tests/scenarios/` against a fresh headless emulator; skips cleanly without firmware.
- `tests/geometry-sync.sh` — fails if the committed control map (`pylib/delugemu/_controls.py`) has drifted from the C headers.
- `pylib/tests/` — stdlib unit tests for the pure logic (geometry, decoders, drift guard): `PYTHONPATH=pylib python3 -m unittest discover -s pylib/tests`.

The composite action [`.github/actions/run-scenario`](../.github/actions/run-scenario/action.yml)
packages firmware resolution + scenario running for use in a workflow:

```yaml
- uses: ./.github/actions/run-scenario
  with:
    fetch-latest: "true"                # download the latest release and drive it
    firmware-repo: your-org/DelugeFirmware
    scenarios: tests/scenarios/boot.json
```

The `scenarios` job in [`build.yml`](../.github/workflows/build.yml) builds the
emulator, runs the unit tests + drift guard, and runs the scenario harness
(skipping cleanly without firmware), uploading screenshots as artifacts.

## How the readout hooks work

The device models expose read-only QOM string properties, fetched with the
standard `qom-get` QMP command (no QAPI schema change):

| QOM path | Property | Meaning |
|---|---|---|
| `/machine/soc/oled` | `dz-framebuffer` | base64 GDDRAM (8 pages × 128 cols) |
| `/machine/soc/oled` | `dz-display-on`, `dz-inverted` | panel flags |
| `/machine/soc/padgrid` | `dz-pad-leds` | base64 RGB of the 18×8 pad grid |
| `/machine/soc/skin` | `dz-leds` | 36 indicator LEDs (`'0'`/`'1'`, index `col + 9*row`) |
| `/machine/soc/skin` | `dz-seven-seg` | 4 raw segment bitmasks (hex) |
| `/machine/soc/skin` | `dz-gold-knob` | base64 of the 8 gold-knob brightnesses |

The indicator LEDs, 7-segment digits and gold-knob brightness are owned by the
PIC (an anonymous chardev with no stable QOM path); the skin device holds a live
pointer to it and exposes them. The Python layer locates each device by type via
`qom-list`, so the paths above are the defaults, not a hard dependency.
