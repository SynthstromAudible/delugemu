# SPDX-License-Identifier: GPL-2.0-or-later
"""Decoders for the deterministic display-state snapshots exposed over QMP by
the emulator's ``dz-*`` QOM properties (see the device models in src/hw)."""
import base64

from . import geometry

OLED_WIDTH = 128
OLED_HEIGHT = 48

# 7-segment bit layout from src/hw/display/deluge_segment.c:
#   bit0=g bit1=f bit2=e bit3=d bit4=c bit5=b bit6=a bit7=dp
_SEG = {"a": 6, "b": 5, "c": 4, "d": 3, "e": 2, "f": 1, "g": 0}

# Segments lit for each renderable glyph (letters chosen to match firmware use).
_GLYPHS = {
    "0": "abcdef", "1": "bc", "2": "abged", "3": "abgcd", "4": "fgbc",
    "5": "afgcd", "6": "afgcde", "7": "abc", "8": "abcdefg", "9": "abcdfg",
    "A": "abcefg", "b": "cdefg", "C": "adef", "d": "bcdeg", "E": "adefg",
    "F": "aefg", "G": "acdef", "H": "bcefg", "I": "bc", "J": "bcde",
    "L": "def", "n": "ceg", "o": "cdeg", "P": "abefg", "r": "eg",
    "S": "afgcd", "t": "defg", "U": "bcdef", "u": "cde", "y": "bcdfg",
    "-": "g", " ": "",
}
_MASK_TO_CHAR = {}
for _ch, _segs in _GLYPHS.items():
    _m = 0
    for _s in _segs:
        _m |= 1 << _SEG[_s]
    _MASK_TO_CHAR.setdefault(_m, _ch)


def decode_oled(b64, width=OLED_WIDTH, height=OLED_HEIGHT, page_start=0):
    """Decode a ``dz-framebuffer`` snapshot to a height x width list of bools.

    The raw GDDRAM is page-major (byte [page][col]); bit b of that byte is the
    pixel at row (page - page_start)*8 + b. The panel shows ``height`` rows
    from ``page_start`` (``dz-page-start``), as the display model draws them."""
    data = base64.b64decode(b64)
    cols = len(data) // 8  # 8 pages
    rows = []
    for y in range(height):
        page = page_start + (y >> 3)
        if page >= 8:
            rows.append([False] * width)
            continue
        bit = y & 7
        base = page * cols
        row = [bool((data[base + x] >> bit) & 1) for x in range(width)]
        rows.append(row)
    return rows


def oled_text(rows):
    """Render an OLED bitmap as ``#``/``.`` lines for display or logging."""
    return "\n".join("".join("#" if p else "." for p in r) for r in rows)


def decode_segment(hexstr):
    """Decode a ``dz-seven-seg`` snapshot to (text, raw_masks).

    ``text`` is the best-effort 4-char glyph reading (``?`` for an unknown
    pattern); a lit decimal point appends ``.`` after its digit."""
    raw = [int(hexstr[i:i + 2], 16) for i in range(0, len(hexstr), 2)]
    chars = []
    for mask in raw:
        glyph = _MASK_TO_CHAR.get(mask & 0x7f, "?" if (mask & 0x7f) else " ")
        if mask & 0x80:
            glyph += "."
        chars.append(glyph)
    return "".join(chars), raw


def decode_leds(bits):
    """Decode a ``dz-leds`` snapshot ('0'/'1' per LED) to {control_name: bool}
    for every control that carries an indicator LED."""
    out = {}
    for name, c in geometry.CONTROLS.items():
        if not c["has_led"] or c["col"] < 0:
            continue
        index = c["col"] + 9 * c["row"]
        out[name] = index < len(bits) and bits[index] == "1"
    return out


def decode_pads(b64, cols=18, rows=8):
    """Decode a ``dz-pad-leds`` snapshot to a cols x rows grid of (r, g, b).

    Memory layout is column-major: rgb[col][row][component]."""
    data = base64.b64decode(b64)
    grid = []
    for col in range(cols):
        column = []
        for row in range(rows):
            off = (col * rows + row) * 3
            column.append((data[off], data[off + 1], data[off + 2]))
        grid.append(column)
    return grid


def decode_gold_knob(b64):
    """Decode a ``dz-gold-knob`` snapshot to a [2][4] brightness grid."""
    data = base64.b64decode(b64)
    return [[data[w * 4 + led] for led in range(4)] for w in range(2)]
