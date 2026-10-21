# SPDX-License-Identifier: GPL-2.0-or-later
"""Unit tests for the pure-logic parts of the delugemu package (no emulator).

Run with:  PYTHONPATH=pylib python3 -m unittest discover -s pylib/tests
"""
import base64
import os
import subprocess
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from delugemu import display, geometry, qwerty  # noqa: E402

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))


class TestGeometry(unittest.TestCase):
    def test_known_controls_present(self):
        names = geometry.names()
        for expected in ("PLAY", "RECORD", "SHIFT", "SELECT_ENC", "MASTER_VOL"):
            self.assertIn(expected, names)

    def test_encoder_classification(self):
        self.assertTrue(geometry.is_encoder("SELECT_ENC"))
        self.assertFalse(geometry.is_encoder("PLAY"))

    def test_case_insensitive_lookup(self):
        self.assertEqual(geometry.control_point("play"),
                         geometry.control_point("PLAY"))

    def test_control_enum_covers_table(self):
        members = {c.name for c in geometry.Control}
        for name in geometry.names():
            self.assertIn(name, members)
        # The synthetic master knob is an enum member too.
        self.assertIn("MASTER_VOL", members)

    def test_enum_and_string_resolve_alike(self):
        self.assertEqual(geometry.control(geometry.Control.PLAY),
                         geometry.control("PLAY"))
        self.assertEqual(geometry.control_point(geometry.Control.SELECT_ENC),
                         geometry.control_point("select_enc"))
        self.assertTrue(geometry.is_encoder(geometry.Control.SELECT_ENC))

    def test_resolve_and_canonical(self):
        self.assertIs(geometry.resolve("play"), geometry.Control.PLAY)
        self.assertIs(geometry.resolve(geometry.Control.PLAY), geometry.Control.PLAY)
        self.assertEqual(geometry.canonical(geometry.Control.PLAY), "PLAY")
        self.assertEqual(geometry.canonical("play"), "PLAY")

    def test_unknown_control_raises(self):
        with self.assertRaises(KeyError):
            geometry.control("NOPE")
        with self.assertRaises(KeyError):
            geometry.resolve("NOPE")

    def test_pad_corners(self):
        # Row 0 is the bottom; (0,0) is bottom-left of the main grid.
        self.assertEqual(geometry.pad_point(0, 0),
                         (geometry.PAD["main_x0"],
                          geometry.PAD["side_y0"] + 7 * geometry.PAD["side_dy"]))
        # Sidebar column 17, top row.
        px, _ = geometry.pad_point(17, 7)
        self.assertEqual(px, geometry.PAD["side_x0"] + geometry.PAD["side_dx"])

    def test_pad_bounds(self):
        with self.assertRaises(ValueError):
            geometry.pad_point(18, 0)
        with self.assertRaises(ValueError):
            geometry.pad_point(0, 8)

    def test_scale_endpoints(self):
        self.assertEqual(geometry.scale_x(0), 0)
        self.assertEqual(geometry.scale_x(geometry.IMAGE_WIDTH - 1), 0x7fff)
        self.assertEqual(geometry.scale_y(geometry.IMAGE_HEIGHT - 1), 0x7fff)


class TestDisplay(unittest.TestCase):
    def test_oled_roundtrip(self):
        data = bytearray(1024)
        data[0] = 1            # x=0, row 0 (page 0, bit 0)
        data[127] = 0x80       # x=127, row 7 (page 0, bit 7)
        rows = display.decode_oled(base64.b64encode(bytes(data)).decode())
        self.assertEqual(len(rows), 48)
        self.assertEqual(len(rows[0]), 128)
        self.assertTrue(rows[0][0])
        self.assertTrue(rows[7][127])
        self.assertFalse(rows[1][1])

    def test_segment_digits(self):
        m0 = (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1)
        m1 = (1 << 5) | (1 << 4)
        text, raw = display.decode_segment("%02x%02x0000" % (m0, m1))
        self.assertEqual(text, "01  ")
        self.assertEqual(raw[0], m0)

    def test_segment_decimal_point(self):
        m0 = ((1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1)
              | 0x80)
        text, _ = display.decode_segment("%02x000000" % m0)
        self.assertTrue(text.startswith("0."))

    def test_leds(self):
        bits = ["0"] * 36
        bits[8 + 9 * 3] = "1"  # PLAY is col 8, row 3
        leds = display.decode_leds("".join(bits))
        self.assertTrue(leds["PLAY"])
        self.assertFalse(leds["RECORD"])

    def test_pads(self):
        data = bytearray(18 * 8 * 3)
        # pad column 2, row 1 -> red
        off = (2 * 8 + 1) * 3
        data[off] = 255
        grid = display.decode_pads(base64.b64encode(bytes(data)).decode())
        self.assertEqual(grid[2][1], (255, 0, 0))
        self.assertEqual(grid[0][0], (0, 0, 0))


class TestControlMapSync(unittest.TestCase):
    def test_generated_map_matches_headers(self):
        """The committed _controls.py must match the C headers (drift guard)."""
        gen = os.path.join(REPO, "scripts", "gen_control_map.py")
        res = subprocess.run([sys.executable, gen, "--check"],
                             capture_output=True, text=True)
        self.assertEqual(res.returncode, 0,
                         "control map is stale; run scripts/gen_control_map.py\n"
                         + res.stderr)


class TestQwerty(unittest.TestCase):
    # Positions from keyboardChars in the firmware's gui/ui/qwerty_ui.cpp.
    def test_letter_rows(self):
        self.assertEqual(qwerty.key_for("Q"), ((3, 4), False))
        self.assertEqual(qwerty.key_for("a"), ((3, 3), False))
        self.assertEqual(qwerty.key_for("M"), ((9, 2), False))
        self.assertEqual(qwerty.key_for("1"), ((3, 5), False))

    def test_punctuation_and_space(self):
        self.assertEqual(qwerty.key_for("'"), ((13, 3), False))
        self.assertEqual(qwerty.key_for("."), ((11, 2), False))
        self.assertEqual(qwerty.key_for(" "), (qwerty.SPACE_PAD, False))

    def test_shifted(self):
        self.assertEqual(qwerty.key_for("_"), ((13, 5), True))
        self.assertEqual(qwerty.key_for("#"), ((5, 5), True))

    def test_untypeable(self):
        # "\0" is the firmware's marker for an unassigned pad, not a key.
        for ch in "(&\0":
            with self.assertRaises(ValueError):
                qwerty.key_for(ch)
        self.assertEqual(qwerty.typeable_prefix("Mix (v2)"), "Mix ")

    def test_song_path_parts(self):
        want = ["problem_songs", "Deal_COLLECT.ALL", "I'Ll Make You A Deal 2"]
        for path in ("/SONGS/problem_songs/Deal_COLLECT.ALL/I'Ll Make You A Deal 2.XML",
                     "SONGS/problem_songs/Deal_COLLECT.ALL/I'Ll Make You A Deal 2",
                     "problem_songs/Deal_COLLECT.ALL/I'Ll Make You A Deal 2.xml"):
            self.assertEqual(qwerty.song_path_parts(path), want)
        self.assertEqual(qwerty.song_path_parts("SONG001.XML"), ["SONG001"])
        for bad in ("", "/SONGS/", "SONGS/.XML"):
            with self.assertRaises(ValueError):
                qwerty.song_path_parts(bad)


if __name__ == "__main__":
    unittest.main()
