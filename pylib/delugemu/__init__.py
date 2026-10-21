# SPDX-License-Identifier: GPL-2.0-or-later
"""delugemu — a standard scripting interface for the Deluge QEMU emulator.

    from delugemu import DelugeSession, Control

    with DelugeSession.launch(firmware="firmware/deluge.bin",
                              icount="auto", int_log="/tmp/int.log") as dz:
        dz.wait(3)
        dz.assert_no_aborts()
        dz.press(Control.PLAY)
        assert dz.read_leds()["PLAY"]

Controls are named by the ``Control`` enum (``Control.PLAY``). Every method
that takes a control also accepts the equivalent name string, so JSON/YAML
scenarios and the CLI keep working unchanged.
"""
from . import display, geometry
from ._controls import Control
from .qmp import QmpClient, QmpError
from .scenario import load_scenario, run_scenario
from .session import DelugeSession

__version__ = "0.1.0"
__all__ = [
    "DelugeSession",
    "Control",
    "QmpClient",
    "QmpError",
    "run_scenario",
    "load_scenario",
    "geometry",
    "display",
]
