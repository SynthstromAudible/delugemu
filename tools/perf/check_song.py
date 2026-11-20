#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Boot firmware in delugemu, load a song, press PLAY, check it plays without aborts (e.g. a gen_tickload.py song).

Usage: check_song.py ELF SDIMG SONGPATH OUTDIR
  e.g. tools/perf/check_song.py deluge.elf build/deluge_sd_tick.img /SONGS/TICKLOAD.XML build/perf/check
Set TL_AUDIO="wav,path=/abs/out.wav" to record the SSIF output to a WAV file (QEMU wav audiodev, no host audio).
Set TL_STOP_WAIT=SECONDS to press PLAY again (stop) after the check and keep running that long, so effect tails
(delay/reverb) can be measured in the WAV; result.json then has t_play/t_stop (host seconds since launch).
Writes OLED screenshots (after load, while playing) and pads/LED dumps to OUTDIR. Host audio is never connected.
"""
import json
import os
import sys
import time

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(REPO, "pylib"))
from delugemu import DelugeSession  # noqa: E402


def lit_rows(pads):
    """Rows (y) of the 16 main columns with any lit pad."""
    rows = set()
    for x, col in enumerate(pads[:16]):
        for y, rgb in enumerate(col):
            if any(rgb):
                rows.add(y)
    return sorted(rows)


def main():
    elf, sd, song, out = sys.argv[1:5]
    os.makedirs(out, exist_ok=True)
    int_log = os.path.join(out, "int.log")
    t0 = time.monotonic()
    with DelugeSession.launch(firmware=elf, sd=sd, int_log=int_log, boot_wait=8.0, audio=os.environ.get("TL_AUDIO", "none"),
                              sock="/tmp/dz_check_song_%d.sock" % os.getpid(), run_log=os.path.join(out, "run.log"),
                              repo_root=REPO) as dz:
        dz.assert_no_aborts()
        dz.screenshot(os.path.join(out, "0_boot.png"))
        dz.load_song(song, timeout=90)
        dz.wait(1.0)
        dz.screenshot(os.path.join(out, "1_loaded.png"))
        pads_loaded = dz.read_pads(flashes=False)
        with open(os.path.join(out, "oled_loaded.txt"), "w") as f:
            f.write(dz.oled_text() if isinstance(dz.oled_text(), str) else "\n".join(dz.oled_text()))
        dz.press("PLAY")
        t_play = time.monotonic() - t0
        dz.wait(6.0)
        leds = dz.read_leds()
        dz.screenshot(os.path.join(out, "2_playing.png"))
        pads_playing = dz.read_pads(flashes=False)
        dz.assert_no_aborts()
        res = dict(song=song, play_led=leds.get("PLAY"), lit_rows_loaded=lit_rows(pads_loaded),
                   lit_rows_playing=lit_rows(pads_playing), segment=dz.read_segment(),
                   leds_on=sorted(k for k, v in leds.items() if v), t_play=round(t_play, 2))
        stop_wait = float(os.environ.get("TL_STOP_WAIT", "0"))
        if stop_wait:
            dz.press("PLAY")
            res["t_stop"] = round(time.monotonic() - t0, 2)
            dz.wait(stop_wait)
            dz.assert_no_aborts()
        with open(os.path.join(out, "result.json"), "w") as f:
            json.dump(res, f, indent=1)
        print(json.dumps(res))
        if not stop_wait:
            dz.press("PLAY")  # stop
            dz.wait(0.5)


if __name__ == "__main__":
    main()
