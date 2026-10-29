# SPDX-License-Identifier: GPL-2.0-or-later
"""Integration tests for the arp freeze of the Deluge community firmware.

The arp freeze (FREEZE on the arpeggiator's PATTERN menu) replaces a clip's notes with what its arpeggiator plays.
It isn't in a firmware release yet, so these tests only run with a firmware given explicitly, and skip otherwise.

The fixture song ARPTEST has a synth clip of one bar (384 ticks) holding C4, E4 and G4 for the whole bar, with the
arpeggiator on: up, 2 octaves, synced to 16ths, gate as saved by the default synth (about 42 %). The other test songs
are made from it: other sync rates, clips played reversed or ping-pong, rows with their own length or direction.

Each test loads its song in a fresh emulator, freezes through the arp pattern menu, saves the song (the Deluge
suggests the name "<song> 2") and checks the saved notes and layout.

Environment:
    ARP_FREEZE_FIRMWARE    firmware with the arp freeze (required, the tests skip without it)
    DELUGEMU_QEMU_BIN  qemu-system-arm to use, default this repo's build (or the bin/ of a release bundle)

The SD card is a folder, so mtools and dosfstools are needed (see scripts/mksd.sh).

Run from the repo root:
    ARP_FREEZE_FIRMWARE=path/to/deluge.bin python3 tests/arp_freeze/test_arp_freeze.py -v
"""

import math
import os
import re
import shutil
import sys
import tempfile
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
QEMU = os.environ.get("DELUGEMU_QEMU_BIN", os.path.join(REPO, "qemu", "build", "qemu-system-arm"))
FIRMWARE = os.environ.get("ARP_FREEZE_FIRMWARE", "")
sys.path.insert(0, os.path.join(REPO, "pylib"))

from delugemu import Control, DelugeSession  # noqa: E402

SHIFT = (8, 0)  # Matrix position of SHIFT, for raw events (hold() and pad() share the pointer)
ARP_MODE_PAD = (11, 4)  # SHIFT + this pad opens the arpeggiator menu
STEP = 24  # Ticks per 16th
BAR = 16 * STEP
C, E, G = 60, 64, 67
GATE = 0xEB851EA5  # The arp gate of the fixture's synth
SYNC_TYPE_TRIPLET = 10
SYNC_TYPE_DOTTED = 19

# --- The fixture and its variants -------------------------------------------------------------------------------


def note_data(notes):
    """noteDataWithSplitProb: per note pos, length, velocity, lift, probability, iterance, fill."""
    return "0x" + "".join("%08X%08X404014000000" % (pos, length) for pos, length in notes)


def make_song(card, name, rows, clip_direction=None, sync_level=None, sync_type=None):
    """Write a variant of ARPTEST. rows: [(key, [(pos, length), ...], {extra noteRow attributes})]."""
    with open(os.path.join(HERE, "fixture", "SONGS", "ARPTEST.XML")) as f:
        song = f.read()
    note_rows = "".join(
        "\n\t\t\t\t<noteRow\n\t\t\t\t\ty=\"%d\"%s\n\t\t\t\t\tnoteDataWithSplitProb=\"%s\" />"
        % (key, "".join('\n\t\t\t\t\t%s="%s"' % item for item in attributes.items()), note_data(notes))
        for key, notes, attributes in rows
    )
    song = re.sub(r"<noteRows>.*?</noteRows>", "<noteRows>" + note_rows + "\n\t\t\t</noteRows>", song, flags=re.S)
    clip_start = song.index("<instrumentClip")
    if clip_direction:
        at = song.index('length="384"', clip_start)
        song = song[:at] + 'sequenceDirection="%s"\n\t\t\t' % clip_direction + song[at:]
    arp_start = song.index("<arpeggiator", clip_start)
    arp_end = song.index("/>", arp_start)
    arp = song[arp_start:arp_end]
    if sync_level is not None:
        arp = re.sub(r'syncLevel="\d+"', 'syncLevel="%d"' % sync_level, arp)
    if sync_type is not None:
        arp = re.sub(r'syncType="\d+"', 'syncType="%d"' % sync_type, arp)
    song = song[:arp_start] + arp + song[arp_end:]
    with open(os.path.join(card, "SONGS", name + ".XML"), "w") as f:
        f.write(song)


# --- Reading saved songs ----------------------------------------------------------------------------------------


def read_song(card, name):
    with open(os.path.join(card, "SONGS", name + ".XML")) as f:
        return f.read()


def attributes(tag):
    return dict(re.findall(r'(\w+)="([^"]*)"', tag))


def clip_attributes(song):
    start = song.index("<instrumentClip")
    return attributes(song[start : song.index(">", start)])


def clip_rows(song):
    """[{attributes}] of the instrument clip's note rows."""
    return [attributes(tag) for tag in re.findall(r"<noteRow\b[^>]*/>", song)]


def clip_notes(song):
    """{key: [(pos, length), ...]}"""
    notes = {}
    for row in clip_rows(song):
        data = row.get("noteDataWithSplitProb", "0x")[2:]
        for i in range(0, len(data), 28):
            notes.setdefault(int(row["y"]), []).append((int(data[i : i + 8], 16), int(data[i + 8 : i + 16], 16)))
    return notes


def clip_arp_mode(song):
    return re.search(r"<arpeggiator\s+mode=\"(\w+)\"", song.split("<instrumentClip", 1)[1]).group(1)


# --- What the arpeggiator should play --------------------------------------------------------------------------


def gate_ticks(period):
    """Length of an arp note: it ends at the first tick where the gate position has passed the gate threshold."""
    threshold = ((GATE + 0x80000000) & 0xFFFFFFFF) >> 8
    return next(k for k in range(1, period + 1) if (k << 24) // period >= threshold)


def full_chord_notes(period, length=BAR):
    """C E G held all the time, up over 2 octaves: one note per period cycling C E G C' E' G'."""
    keys = [C, E, G, C + 12, E + 12, G + 12]
    notes = {}
    for i, pos in enumerate(range(0, length, period)):
        notes.setdefault(keys[i % len(keys)], []).append((pos, min(gate_ticks(period), length - pos)))
    return notes


def sounding_windows(note, row_length, direction, render_length):
    """When a note of a row sounds while the clip plays: the row loops at its length, and on the passes it plays
    backwards a note sounds from its end to its start."""
    pos, length = note
    windows = []
    for i in range(render_length // row_length):
        reversed_pass = direction == "reverse" or (direction == "pingpong" and i % 2 == 1)
        start = i * row_length + (row_length - pos - length if reversed_pass else pos)
        windows.append((start, start + length))
    return windows


def starts(notes, keys):
    return sorted(pos for key in keys for pos, _ in notes.get(key, []))


# --- Tests ------------------------------------------------------------------------------------------------------


class ArpFreezeTest(unittest.TestCase):
    def setUp(self):
        if not os.path.exists(FIRMWARE):
            self.skipTest("set ARP_FREEZE_FIRMWARE to a firmware with the arp freeze")
        if not os.path.exists(QEMU):
            self.skipTest("qemu-system-arm not built (scripts/build.sh) and DELUGEMU_QEMU_BIN not set")
        self.tmp = tempfile.mkdtemp(prefix="arpfreeze")
        # A folder ending in "_rw" gets the card's changes written back when the emulator quits
        self.card = os.path.join(self.tmp, "card_rw")
        shutil.copytree(os.path.join(HERE, "fixture"), self.card)
        self.dz = None

    def tearDown(self):
        if self.dz is not None:
            self.dz.close()
        shutil.rmtree(self.tmp, ignore_errors=True)

    def start(self, song):
        env = {"DELUGEMU_QEMU_BIN": QEMU}
        self.dz = DelugeSession.launch(
            firmware=FIRMWARE,
            sd=self.card,
            repo_root=REPO,
            int_log=os.path.join(self.tmp, "int.log"),
            boot_wait=15.0,
            env=env,
            audio="none",
        )
        # The first LOAD after boot is sometimes missed while the emulator is busy
        for attempt in range(3):
            try:
                self.dz.load_song(song)
                break
            except AssertionError:
                if attempt == 2:
                    raise
                self.dz.wait(3.0)
        self.dz.wait(1.5)

    def lit_pads(self):
        pads = self.dz.read_pads(flashes=False)
        return {(x, y) for x in range(16) for y in range(8) if max(pads[x][y]) > 0}

    def shift_pad(self, x, y):
        dz = self.dz
        dz.button(*SHIFT, True)
        dz.wait(0.3)
        dz.pad_event(x, y, True)
        dz.wait(0.3)
        dz.pad_event(x, y, False)
        dz.wait(0.2)
        dz.button(*SHIFT, False)
        dz.wait(0.8)

    def open_freeze_page(self):
        """Open the arp menu and go to its last page, where Freeze is alone (Basic, then 3 Pattern pages)."""
        self.shift_pad(*ARP_MODE_PAD)
        for _ in range(3):
            self.dz.press(Control.CROSS_SCREEN)
            self.dz.wait(0.6)
        return [tuple(row) for row in self.dz.read_oled()]

    def freeze(self):
        page = self.open_freeze_page()
        self.dz.press(Control.SELECT_ENC)  # Freeze: opens the confirmation
        self.dz.wait(0.8)
        self.assertNotEqual([tuple(row) for row in self.dz.read_oled()], page, "no confirmation shown")
        self.dz.press(Control.SELECT_ENC)  # OK
        self.dz.wait(1.5)
        self.dz.assert_no_aborts()

    def freeze_and_save(self, song):
        """Freeze the song and return the saved result."""
        self.start(song)
        self.freeze()
        dz = self.dz
        dz.press(Control.SAVE)
        dz.wait(1.5)
        dz.press(Control.SELECT_ENC)  # Save, under the new name the Deluge suggests
        dz.wait(1.5)
        dz.wait_sd_idle(quiet=1.5, timeout=30)
        dz.close()
        self.dz = None
        saved = read_song(self.card, song + " 2")
        self.assertEqual(clip_arp_mode(saved), "off")
        return saved

    def assert_layout(self, saved, length):
        """The frozen clip plays forwards at the given length, its rows following it."""
        clip = clip_attributes(saved)
        self.assertEqual(int(clip["length"]), length)
        self.assertNotIn("sequenceDirection", clip)
        for row in clip_rows(saved):
            self.assertNotIn("length", row)
            self.assertNotIn("sequenceDirection", row)

    def assert_held_only_in(self, saved, windows, render_length):
        """E (and its octave) is arpeggiated only while it's held, and at least once in each long enough window."""
        notes = clip_notes(saved)
        e_starts = starts(notes, [E, E + 12])
        for pos in e_starts:
            self.assertTrue(any(s <= pos < e for s, e in windows), "E played at %d, outside %s" % (pos, windows))
        for s, e in windows:
            if e - s >= 6 * STEP:
                self.assertTrue(any(s <= pos < e for pos in e_starts), "E not played in %s" % ((s, e),))
        # C is held all the time: arpeggiated over the whole clip
        c_starts = starts(notes, [C, C + 12])
        self.assertLess(c_starts[0], 2 * STEP)
        self.assertGreaterEqual(c_starts[-1], render_length - 4 * STEP)
        self.assertEqual(starts(notes, list(notes)), list(range(0, render_length, STEP)), "not one note per 16th")

    # Timing

    def test_freeze_writes_the_arpeggiated_notes(self):
        saved = self.freeze_and_save("ARPTEST")
        self.assertEqual(clip_notes(saved), full_chord_notes(STEP))
        self.assert_layout(saved, BAR)

    def test_eighths(self):
        make_song(self.card, "ARP8TH", [(k, [(0, BAR)], {}) for k in (C, E, G)], sync_level=5)
        self.assertEqual(clip_notes(self.freeze_and_save("ARP8TH")), full_chord_notes(2 * STEP))

    def test_triplets(self):
        make_song(self.card, "ARPTRIP", [(k, [(0, BAR)], {}) for k in (C, E, G)], sync_type=SYNC_TYPE_TRIPLET)
        self.assertEqual(clip_notes(self.freeze_and_save("ARPTRIP")), full_chord_notes(STEP * 2 // 3))

    def test_dotted(self):
        make_song(self.card, "ARPDOT", [(k, [(0, BAR)], {}) for k in (C, E, G)], sync_type=SYNC_TYPE_DOTTED)
        self.assertEqual(clip_notes(self.freeze_and_save("ARPDOT")), full_chord_notes(STEP * 3 // 2))

    def test_unsynced(self):
        """Frozen at the current tempo: evenly spaced, up the chord."""
        make_song(self.card, "ARPFREE", [(k, [(0, BAR)], {}) for k in (C, E, G)], sync_level=0)
        notes = clip_notes(self.freeze_and_save("ARPFREE"))
        played = sorted((pos, key) for key, row in notes.items() for pos, _ in row)
        self.assertGreater(len(played), 3)
        gaps = [b[0] - a[0] for a, b in zip(played, played[1:])]
        self.assertLessEqual(max(gaps) - min(gaps), 1, "not evenly spaced: %s" % gaps)
        cycle = [C, E, G, C + 12, E + 12, G + 12]
        self.assertEqual([key for _, key in played], [cycle[i % 6] for i in range(len(played))])

    # Layouts: C held all the time, E held only part of the time

    def test_reverse_clip(self):
        e_note = (0, 8 * STEP)
        make_song(self.card, "ARPREV", [(C, [(0, BAR)], {}), (E, [e_note], {})], clip_direction="reverse")
        saved = self.freeze_and_save("ARPREV")
        self.assert_layout(saved, BAR)
        self.assert_held_only_in(saved, sounding_windows(e_note, BAR, "reverse", BAR), BAR)

    def test_pingpong_clip(self):
        e_note = (0, 8 * STEP)
        make_song(self.card, "ARPPP", [(C, [(0, BAR)], {}), (E, [e_note], {})], clip_direction="pingpong")
        saved = self.freeze_and_save("ARPPP")
        self.assert_layout(saved, 2 * BAR)
        self.assert_held_only_in(saved, sounding_windows(e_note, BAR, "pingpong", 2 * BAR), 2 * BAR)

    def test_row_with_its_own_length(self):
        e_note = (0, 6 * STEP)
        row_length = 12 * STEP
        make_song(self.card, "ARPRLEN", [(C, [(0, BAR)], {}), (E, [e_note], {"length": row_length})])
        saved = self.freeze_and_save("ARPRLEN")
        render_length = math.lcm(BAR, row_length)  # 3 bars
        self.assert_layout(saved, render_length)
        self.assert_held_only_in(saved, sounding_windows(e_note, row_length, "forward", render_length), render_length)

    def test_row_with_its_own_direction(self):
        e_note = (0, 6 * STEP)
        make_song(self.card, "ARPRDIR", [(C, [(0, BAR)], {}), (E, [e_note], {"sequenceDirection": "reverse"})])
        saved = self.freeze_and_save("ARPRDIR")
        self.assert_layout(saved, BAR)
        self.assert_held_only_in(saved, sounding_windows(e_note, BAR, "reverse", BAR), BAR)

    def test_pingpong_row_with_its_own_length_in_a_reversed_clip(self):
        e_note = (2 * STEP, 6 * STEP)
        row_length = 12 * STEP
        make_song(
            self.card,
            "ARPMIX",
            [(C, [(0, BAR)], {}), (E, [e_note], {"length": row_length, "sequenceDirection": "pingpong"})],
            clip_direction="reverse",
        )
        saved = self.freeze_and_save("ARPMIX")
        render_length = math.lcm(BAR, 2 * row_length)  # 3 bars
        self.assert_layout(saved, render_length)
        self.assert_held_only_in(saved, sounding_windows(e_note, row_length, "pingpong", render_length), render_length)

    # Undo

    def test_undo_restores_notes_and_arp(self):
        self.start("ARPTEST")
        before = self.lit_pads()
        freeze_page_with_arp_on = self.open_freeze_page()
        self.dz.press(Control.BACK)  # Out of the menu
        self.dz.wait(0.8)

        self.freeze()
        self.assertNotEqual(self.lit_pads(), before)
        # The arp is off now: the Freeze slot shows a dash instead of "Apply"
        self.assertNotEqual(self.open_freeze_page(), freeze_page_with_arp_on)
        self.dz.press(Control.BACK)
        self.dz.wait(0.8)

        self.dz.press(Control.BACK)  # Undo
        self.dz.wait(1.0)
        self.dz.assert_no_aborts()
        self.assertEqual(self.lit_pads(), before)
        self.assertEqual(self.open_freeze_page(), freeze_page_with_arp_on)


if __name__ == "__main__":
    unittest.main()
