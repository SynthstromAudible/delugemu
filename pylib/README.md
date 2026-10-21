# delugemu — Deluge emulator scripting interface

A Python library, CLI, and declarative scenario runner for driving the delugemu
emulator: write integration tests, run them in CI, and capture bug repros.

Stdlib-only (no runtime dependencies). YAML scenarios need the `yaml` extra.

```python
from delugemu import DelugeSession, Control

with DelugeSession.launch(firmware="firmware/deluge.bin", int_log="/tmp/int.log",
                          boot_wait=4.0) as dz:
    dz.assert_no_aborts()
    dz.press(Control.PLAY)       # or dz.press("PLAY")
    assert dz.read_leds()["PLAY"]
    dz.screenshot("playing.png")
```

Controls are named by the `Control` enum (generated from the C skin table);
every control-taking method also accepts the equivalent name string, so JSON/YAML
scenarios and the CLI keep working.

Run from the repo without installing:

```sh
PYTHONPATH=pylib python3 -m delugemu.cli controls
PYTHONPATH=pylib python3 -m unittest discover -s pylib/tests
```

Or install the `delugemu` command:

```sh
pip install -e pylib          # or: pip install -e 'pylib[yaml]'
delugemu run tests/scenarios/boot.json --firmware firmware/deluge.bin
```

To attach to a running emulator instead of launching one, expose a QMP socket
(`-qmp unix:/tmp/dz_qmp.sock,server,nowait`) and `DelugeSession.attach(sock)`.
**Keep that socket path short** — a unix-socket path has a hard OS limit (~104
chars on macOS) and a longer one fails with `AF_UNIX path too long`, so use
e.g. `/tmp/dz_qmp.sock`, not a deeply nested temp directory.

Full documentation: [`docs/scripting.md`](../docs/scripting.md).

## Layout

- `delugemu/qmp.py` — minimal QMP client.
- `delugemu/geometry.py` + `delugemu/_controls.py` — the `Control` enum and named-control geometry, generated from the C headers by `scripts/gen_control_map.py` (regenerate + commit after changing the panel layout; `tests/geometry-sync.sh` guards drift).
- `delugemu/display.py` — decoders for the `dz-*` readout snapshots.
- `delugemu/session.py` — `DelugeSession`, the high-level API.
- `delugemu/scenario.py` — the declarative scenario runner.
- `delugemu/cli.py` — the `delugemu` command.
