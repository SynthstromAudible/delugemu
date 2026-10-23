# SPDX-License-Identifier: GPL-2.0-or-later
"""The firmware's on-pad QWERTY keyboard, and song-path handling for the browser.

Whenever the firmware wants text (naming a file, or searching the file
browser), it lights a QWERTY keyboard on the main pad grid
(``gui/ui/qwerty_ui.cpp``). In the browser, typing a name jumps to the first
entry it matches (case-insensitively, as a prefix). This module maps characters
to the pads that type them; ``DelugeSession.type_text`` and
``DelugeSession.load_song`` press them.

Layout (pad rows count from the bottom, as everywhere in this package): digits
on row 5, ``QWERTYUIOP`` on row 4, ``ASDFGHJKL'`` on row 3 (the home row,
``kQwertyHomeRow``), ``ZXCVBNM,.`` on row 2 and space on row 1, each starting at
column 3. ``_``, ``!`` and ``#`` are the shifted ``-``, ``1`` and ``3``: hold a
shift pad (row 2, column 1, 2, 13 or 14) while pressing the key. This is the
default QWERTY layout; the firmware's alternative AZERTY setting is not handled.
"""

_ROWS = (
    (5, "1234567890-"),
    (4, "QWERTYUIOP"),
    (3, "ASDFGHJKL\0'"),   # \0: the firmware leaves that pad unassigned
    (2, "ZXCVBNM,."),
)
_FIRST_COL = 3
SPACE_PAD = (5, 1)
SHIFT_PAD = (1, 2)
_SHIFTED = {"_": "-", "!": "1", "#": "3"}

SONGS_ROOT = "SONGS"
SONG_EXTENSION = ".XML"

# (x, y) pad and shift state for every typeable character, built once so
# key_for is O(1). The firmware's unassigned home-row pad (the \0 slot in the
# row strings above) is skipped.
_KEYS = {" ": SPACE_PAD + (False,)}
for y, keys in _ROWS:
    for x, ch in enumerate(keys):
        if ch != "\0":
            _KEYS[ch] = (_FIRST_COL + x, y, False)
for shifted, base in _SHIFTED.items():
    x, y, _ = _KEYS[base]
    _KEYS[shifted] = (x, y, True)


def key_for(ch):
    """Return ``(pad, shifted)`` for one character, where ``pad`` is the (x, y)
    cell that types it and ``shifted`` says whether the shift pad must be held.
    Letters are case-insensitive. Raises ValueError for a character the
    keyboard cannot type."""
    try:
        x, y, shifted = _KEYS[ch.upper()]
    except (AttributeError, KeyError):
        raise ValueError(
            "character %r cannot be typed on the Deluge keyboard" % ch)
    return (x, y), shifted


def typeable(ch):
    try:
        key_for(ch)
    except ValueError:
        return False
    return True


def typeable_prefix(name):
    """The longest prefix of ``name`` the keyboard can type."""
    for i, ch in enumerate(name):
        if not typeable(ch):
            return name[:i]
    return name


def song_path_parts(path):
    """Split a song path into the browser entries to step through, relative to
    the ``SONGS`` folder the song browser is rooted at.

    ``/SONGS/a/b/Song 2.XML``, ``SONGS/a/b/Song 2`` and ``a/b/Song 2.xml`` all
    give ``["a", "b", "Song 2"]``: the last element is the song (its ``.XML``
    extension dropped, as the browser displays it), the rest are folders."""
    parts = [p for p in path.replace("\\", "/").split("/") if p]
    if parts and parts[0].upper() == SONGS_ROOT:
        parts = parts[1:]
    if not parts:
        raise ValueError("no song named in path %r" % path)
    if parts[-1].upper().endswith(SONG_EXTENSION):
        parts[-1] = parts[-1][:-len(SONG_EXTENSION)]
    if not parts[-1]:
        raise ValueError("no song named in path %r" % path)
    return parts
