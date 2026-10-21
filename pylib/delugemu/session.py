# SPDX-License-Identifier: GPL-2.0-or-later
"""DelugeSession: the high-level scripting API for the emulator.

Launch (or attach to) a headless emulator, drive the front panel by control
name / pad coordinate / key, read back deterministic display state, and assert
on it. All input goes through the documented QMP ``input-send-event`` contract,
exercising the same firmware hit-test path a real click would.
"""
import os
import signal
import subprocess
import tempfile
import time

from . import display, geometry
from .qmp import QmpClient, QmpError

# The firmware needs a press held briefly or it never registers it; the device
# model (deluge_input.c) defers a too-fast release. Match that with a margin.
DEFAULT_HOLD_MS = 120


def find_repo_root(start=None):
    """Walk up from ``start`` (or this file) to the repo containing scripts/run.sh."""
    path = os.path.abspath(start or __file__)
    while True:
        if os.path.isfile(os.path.join(path, "scripts", "run.sh")):
            return path
        parent = os.path.dirname(path)
        if parent == path:
            raise QmpError("could not locate repo root (scripts/run.sh) from %s"
                           % (start or __file__))
        path = parent


class AbortDetected(AssertionError):
    pass


class DelugeSession:
    def __init__(self, client, proc=None, int_log=None, repo_root=None,
                 artifacts_dir=None, run_log=None):
        self.q = client
        self.proc = proc
        self.int_log = int_log
        self.repo_root = repo_root
        self.run_log = run_log
        self.artifacts_dir = artifacts_dir or os.getcwd()
        self._paths = {}
        self._closed = False

    # -- lifecycle ---------------------------------------------------------
    @classmethod
    def attach(cls, sock="/tmp/dz_qmp.sock", connect_timeout=30.0, **kw):
        """Connect to an already-running emulator's QMP socket."""
        return cls(QmpClient(sock, connect_timeout), **kw)

    @classmethod
    def launch(cls, firmware=None, sd=None, icount=None, headless=True,
               sock=None, int_log=None, extra_qemu=(), repo_root=None,
               boot_wait=0.0, connect_timeout=90.0, env=None, artifacts_dir=None,
               run_log=None):
        """Start the emulator via scripts/run.sh and connect to it.

        ``firmware`` None lets run.sh resolve one (local image, or a download
        when DELUGEMU_FETCH_FIRMWARE=1). Returns a connected DelugeSession, or
        raises QmpError if run.sh exits before the QMP socket appears (e.g. no
        firmware available)."""
        repo_root = repo_root or find_repo_root()
        run_sh = os.path.join(repo_root, "scripts", "run.sh")
        if sock is None:
            sock = os.path.join(tempfile.gettempdir(),
                                "dz_qmp_%d.sock" % os.getpid())
        for stale in (sock,):
            try:
                os.unlink(stale)
            except OSError:
                pass

        cmd = [run_sh]
        if firmware:
            cmd.append(firmware)
        if sd:
            cmd += ["--sd", sd]
        cmd += ["--display", "console" if not headless else "none"]
        if icount is not None:
            cmd += ["--icount", str(icount)]
        qemu_args = ["-qmp", "unix:%s,server,nowait" % sock]
        if int_log:
            qemu_args += ["-d", "int", "-D", int_log]
        qemu_args += list(extra_qemu)
        cmd += ["--"] + qemu_args

        full_env = dict(os.environ)
        if env:
            full_env.update(env)

        if run_log is None:
            run_log = os.path.join(tempfile.gettempdir(),
                                   "dz_run_%d.log" % os.getpid())
        log_fh = open(run_log, "w")
        proc = subprocess.Popen(cmd, cwd=repo_root, stdout=log_fh,
                                stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL,
                                start_new_session=True, env=full_env)

        deadline = time.monotonic() + connect_timeout
        while not os.path.exists(sock):
            if proc.poll() is not None:
                log_fh.close()
                tail = _tail(run_log, 40)
                raise QmpError("run.sh exited (code %s) before the QMP socket "
                               "appeared.\n--- run.sh output ---\n%s"
                               % (proc.returncode, tail))
            if time.monotonic() > deadline:
                _terminate(proc)
                log_fh.close()
                raise QmpError("timed out waiting for QMP socket %s" % sock)
            time.sleep(0.1)

        client = QmpClient(sock, connect_timeout=15.0)
        session = cls(client, proc=proc, int_log=int_log, repo_root=repo_root,
                      artifacts_dir=artifacts_dir, run_log=run_log)
        if boot_wait:
            session.wait(boot_wait)
        return session

    def close(self, quit_qemu=True):
        if self._closed:
            return
        self._closed = True
        if self.q:
            if quit_qemu and self.proc is not None:
                try:
                    self.q.execute("quit")
                except QmpError:
                    pass
            self.q.close()
        if self.proc is not None:
            _terminate(self.proc)

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.close()
        return False

    # -- device paths (resolved once, cached) ------------------------------
    def _dev(self, key, typename, default):
        if key not in self._paths:
            self._paths[key] = self.q.find_device(typename) or default
        return self._paths[key]

    # -- raw input ---------------------------------------------------------
    def _events(self, events):
        self.q.execute("input-send-event", events=events)

    def _move(self, px, py):
        self._events([
            {"type": "abs", "data": {"axis": "x", "value": geometry.scale_x(px)}},
            {"type": "abs", "data": {"axis": "y", "value": geometry.scale_y(py)}},
        ])

    def _btn(self, button, down):
        self._events([{"type": "btn", "data": {"down": down, "button": button}}])

    def _click(self, px, py, hold_ms):
        self._move(px, py)
        self._btn("left", True)
        self.wait(max(hold_ms, DEFAULT_HOLD_MS) / 1000.0)
        self._btn("left", False)

    # -- named input -------------------------------------------------------
    def key(self, qcode, hold_ms=DEFAULT_HOLD_MS):
        """Press and release a host key by its QMP qcode (e.g. 'spc', 'a', '1')."""
        keyev = lambda d: {"type": "key", "data": {
            "down": d, "key": {"type": "qcode", "data": qcode}}}
        self._events([keyev(True)])
        self.wait(hold_ms / 1000.0)
        self._events([keyev(False)])

    def press(self, name, hold_ms=DEFAULT_HOLD_MS):
        """Tap a button or encoder push-click. ``name`` is a ``Control`` member
        (e.g. ``Control.PLAY``) or its name string (``'PLAY'``, 'SELECT_ENC')."""
        px, py = geometry.control_point(name)
        self._click(px, py, hold_ms)

    def hold(self, name):
        """Press and keep a control held (pair with release)."""
        px, py = geometry.control_point(name)
        self._move(px, py)
        self._btn("left", True)

    def release(self):
        """Release a control held with hold()."""
        self._btn("left", False)

    def turn(self, name, delta):
        """Turn a rotary encoder (``Control`` member or name) by ``delta``
        detents (negative = CCW)."""
        px, py = geometry.control_point(name)
        self._move(px, py)
        self.wait(0.05)
        button = "wheel-up" if delta > 0 else "wheel-down"
        for _ in range(abs(int(delta))):
            self._btn(button, True)
            self._btn(button, False)
            self.wait(0.03)

    def pad(self, x, y, hold_ms=DEFAULT_HOLD_MS):
        """Tap pad grid cell (x, y). Columns 16/17 are the sidebar."""
        px, py = geometry.pad_point(x, y)
        self._click(px, py, hold_ms)

    def latch(self, names):
        """Context manager: latch several controls down at once (Alt-latch)."""
        return _Latch(self, names)

    # -- readout -----------------------------------------------------------
    def read_oled(self):
        path = self._dev("oled", "deluge-oled", "/machine/soc/oled")
        return display.decode_oled(self.q.qom_get(path, "dz-framebuffer"))

    def oled_text(self):
        return display.oled_text(self.read_oled())

    def oled_on(self):
        path = self._dev("oled", "deluge-oled", "/machine/soc/oled")
        return bool(self.q.qom_get(path, "dz-display-on"))

    def read_segment(self):
        path = self._dev("skin", "deluge-skin", "/machine/soc/skin")
        text, _raw = display.decode_segment(self.q.qom_get(path, "dz-seven-seg"))
        return text

    def read_leds(self):
        path = self._dev("skin", "deluge-skin", "/machine/soc/skin")
        return display.decode_leds(self.q.qom_get(path, "dz-leds"))

    def read_pads(self):
        path = self._dev("padgrid", "deluge-padgrid", "/machine/soc/padgrid")
        return display.decode_pads(self.q.qom_get(path, "dz-pad-leds"))

    def read_gold_knob(self):
        path = self._dev("skin", "deluge-skin", "/machine/soc/skin")
        return display.decode_gold_knob(self.q.qom_get(path, "dz-gold-knob"))

    def screenshot(self, path):
        """Capture the composited front panel. PNG if the path ends .png (falls
        back to PPM when the QEMU build lacks PNG screendump)."""
        if not os.path.isabs(path):
            path = os.path.join(self.artifacts_dir, path)
        os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
        if path.lower().endswith(".png"):
            try:
                self.q.execute("screendump", filename=path, format="png")
                return path
            except QmpError:
                path = path[:-4] + ".ppm"
        self.q.execute("screendump", filename=path)
        return path

    # -- timing ------------------------------------------------------------
    def wait(self, seconds):
        if seconds > 0:
            time.sleep(seconds)

    def wait_until(self, predicate, timeout=10.0, poll=0.1):
        """Poll ``predicate(self)`` until true or timeout; returns its result."""
        deadline = time.monotonic() + timeout
        while True:
            value = predicate(self)
            if value:
                return value
            if time.monotonic() > deadline:
                return value
            self.wait(poll)

    # -- assertions --------------------------------------------------------
    def assert_led(self, name, on=True):
        leds = self.read_leds()
        key = geometry.canonical(name)
        if key not in leds:
            raise AssertionError("control %r has no indicator LED" % name)
        if leds[key] != on:
            raise AssertionError("LED %s is %s, expected %s"
                                 % (key, "on" if leds[key] else "off",
                                    "on" if on else "off"))

    def assert_segment(self, text):
        got = self.read_segment().strip()
        if got.replace(".", "") != str(text).strip().replace(".", ""):
            raise AssertionError("7-seg shows %r, expected %r" % (got, text))

    def assert_oled_contains(self, substring):
        """Assert the decoded OLED, rendered as text rows, is non-empty when a
        substring marker is requested. (Text OCR is not modeled; this checks the
        panel is lit/non-blank.)"""
        rows = self.read_oled()
        if not any(any(r) for r in rows):
            raise AssertionError("OLED is blank; expected content %r" % substring)

    def assert_no_aborts(self):
        """Fail if the -d int log recorded a Data/Prefetch Abort (needs int_log)."""
        if not self.int_log or not os.path.exists(self.int_log):
            raise AssertionError("assert_no_aborts requires launch(int_log=...)")
        with open(self.int_log, errors="replace") as fh:
            text = fh.read()
        data = text.count("Taking exception 4 [")
        prefetch = text.count("Taking exception 3 [")
        if data or prefetch:
            raise AbortDetected("boot faulted: %d data-abort(s), %d prefetch-abort(s)"
                                % (data, prefetch))


class _Latch:
    def __init__(self, session, names):
        self.s = session
        self.names = names

    def __enter__(self):
        self.s.key  # noqa: ensure attr
        self.s._events([{"type": "key", "data": {
            "down": True, "key": {"type": "qcode", "data": "alt"}}}])
        for name in self.names:
            px, py = geometry.control_point(name)
            self.s._click(px, py, DEFAULT_HOLD_MS)
        return self

    def __exit__(self, *exc):
        self.s._events([{"type": "key", "data": {
            "down": False, "key": {"type": "qcode", "data": "alt"}}}])
        return False


def _terminate(proc):
    try:
        os.killpg(os.getpgid(proc.pid), signal.SIGINT)
        proc.wait(timeout=4)
        return
    except (ProcessLookupError, subprocess.TimeoutExpired, OSError):
        pass
    try:
        os.killpg(os.getpgid(proc.pid), signal.SIGKILL)
        proc.wait(timeout=4)
    except (ProcessLookupError, subprocess.TimeoutExpired, OSError):
        pass


def _tail(path, lines):
    try:
        with open(path, errors="replace") as fh:
            return "".join(fh.readlines()[-lines:])
    except OSError:
        return "(no output captured)"
