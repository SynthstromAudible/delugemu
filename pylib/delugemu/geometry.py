# SPDX-License-Identifier: GPL-2.0-or-later
"""Front-panel geometry: resolve a control name or pad coordinate to the skin
pixel the pointer must click, and scale a pixel to a QMP absolute-axis value.

The data comes from ``_controls.py``, generated from the C headers by
``scripts/gen_control_map.py`` so there is a single source of truth shared with
the emulator's own hit-testing (``src/hw/input/deluge_input.c``).
"""
from . import _controls as _c
from ._controls import Control

ABS_MAX = 0x7fff

IMAGE_WIDTH = _c.IMAGE_WIDTH
IMAGE_HEIGHT = _c.IMAGE_HEIGHT

# name -> control dict, plus the master OUTPUT LEVEL knob as a synthetic entry.
CONTROLS = dict(_c.CONTROLS)
CONTROLS["MASTER_VOL"] = {
    "col": -1, "row": -1,
    "cx": _c.MASTER_VOL["cx"], "cy": _c.MASTER_VOL["cy"],
    "radius": _c.MASTER_VOL["radius"], "has_led": False,
}

PAD = _c.PAD


def names():
    """Sorted list of all known control names."""
    return sorted(CONTROLS)


def canonical(name):
    """Canonical upper-case name for a ``Control`` member or a string.

    This is the single point that turns whatever a caller passes -- a typed
    ``Control.PLAY``, or the ``"play"`` from a JSON scenario / CLI arg -- into
    the key the geometry table is indexed by.
    """
    if isinstance(name, Control):
        return name.value
    return str(name).strip().upper()


def resolve(name):
    """Return the ``Control`` member for a member or a (case-insensitive) name."""
    if isinstance(name, Control):
        return name
    try:
        return Control(canonical(name))
    except ValueError:
        raise KeyError("unknown control %r (known: %s)"
                       % (name, ", ".join(names())))


def control(name):
    """Return the control dict for ``name`` (a ``Control`` member or a
    case-insensitive string)."""
    key = canonical(name)
    try:
        return CONTROLS[key]
    except KeyError:
        raise KeyError("unknown control %r (known: %s)"
                       % (name, ", ".join(names())))


def is_encoder(name):
    """A turnable encoder is exactly a control with no indicator LED."""
    return not control(name)["has_led"]


def control_point(name):
    c = control(name)
    return c["cx"], c["cy"]


def pad_point(x, y):
    """Skin pixel centre of pad grid cell (x, y). Columns 0..15 are the main
    grid, 16/17 the sidebar; row 0 is the bottom (mirrored like the firmware)."""
    p = PAD
    if not (0 <= y < p["rows"]):
        raise ValueError("pad row %d out of range 0..%d" % (y, p["rows"] - 1))
    total_cols = p["main_cols"] + p["side_cols"]
    if not (0 <= x < total_cols):
        raise ValueError("pad col %d out of range 0..%d" % (x, total_cols - 1))
    scr = p["rows"] - 1 - y
    py = p["side_y0"] + scr * p["side_dy"]
    if x < p["main_cols"]:
        px = p["main_x0"] + x * p["main_dx"]
    else:
        px = p["side_x0"] + (x - p["main_cols"]) * p["side_dx"]
    return px, py


def scale_x(px):
    return round(px * ABS_MAX / (IMAGE_WIDTH - 1))


def scale_y(py):
    return round(py * ABS_MAX / (IMAGE_HEIGHT - 1))
