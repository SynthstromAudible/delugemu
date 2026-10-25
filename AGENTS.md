# Agent Instructions

## Testing Deluge behaviour

For any programmatic interaction with the emulator (reproducing a firmware bug,
loading a song, pressing controls, reading the OLED/LEDs/pads, checking for
aborts), use the Python interface in [`pylib/delugemu`](pylib/README.md):
`DelugeSession.launch(...)`, then `load_song("/SONGS/...")`, `press`, `turn`,
`pad`, `type_text`, `wait_sd_idle`, `read_oled`, `assert_no_aborts`. Don't
hand-roll QMP key sequences. See the README section "Testing Deluge issues
programmatically" and [docs/scripting.md](docs/scripting.md) for the full API.
The default SD image has bug-repro songs under `SONGS/problem_songs/`.

## Measuring firmware performance

To measure how expensive the firmware's audio render is, why a song culls voices, or whether a change is faster,
follow the `measure-firmware-performance` skill (`.claude/skills/measure-firmware-performance/SKILL.md`): it runs
the probe firmware under the `dzcache` plugin at calibrated Deluge speed (`tools/perf/`). Don't measure performance
in the emulator's default real-time mode.
