# delugemu examples

Small, runnable scripts that drive the emulator through the `delugemu` Python
library. Each is self-contained and documented at the top; read them as the
quickest tour of the API.

Run from the repo without installing (they add `pylib/` to `sys.path`
themselves):

```sh
# Launch-and-drive examples resolve firmware like run.sh does; pass one
# explicitly if it isn't in firmware/ (see docs/scripting.md "Firmware resolution").
python3 pylib/examples/boot_and_screenshot.py --firmware firmware/deluge.bin
python3 pylib/examples/transport_led.py --firmware firmware/deluge.bin
python3 pylib/examples/navigate_and_pads.py --firmware firmware/deluge.bin
```

Or, with the package installed (`pip install -e pylib`), `python3 -m` /
plain `python3 path/to/example.py` both work.

| Script | Shows |
|---|---|
| `boot_and_screenshot.py` | `DelugeSession.launch`, `assert_no_aborts`, reading the OLED, `screenshot` |
| `transport_led.py` | Pressing a `Control` member, polling with `wait_until`, asserting an LED, reading the 7-segment |
| `navigate_and_pads.py` | `turn` on an encoder, tapping the `pad` grid, decoding `read_pads` |
| `attach_and_inspect.py` | `DelugeSession.attach` to an already-running instance and dumping its display state (no launch) |

The launch examples **skip cleanly** (exit 0 with a note) when no firmware is
available, so they are safe to run anywhere. `attach_and_inspect.py` needs an
emulator already listening on its QMP socket — start one with:

```sh
./scripts/run.sh firmware/deluge.bin --display none \
    -- -qmp unix:/tmp/dz_qmp.sock,server,nowait
```

> **Keep the QMP socket path short.** A unix-socket path has a hard OS limit
> (~104 chars on macOS); a longer one fails with `AF_UNIX path too long`. Use a
> short path like `/tmp/dz_qmp.sock` — not a deeply nested temp directory.

Controls are named by the `Control` enum (`Control.PLAY`, `Control.SELECT_ENC`,
…); every control-taking method also accepts the plain name string.
