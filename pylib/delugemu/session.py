# SPDX-License-Identifier: GPL-2.0-or-later
"""DelugeSession: the high-level scripting API for the emulator.

Launch (or attach to) a headless emulator, drive the front panel by control
name / pad coordinate / key, read back deterministic display state, and assert
on it. All input goes through the documented QMP ``input-send-event`` contract,
exercising the same firmware hit-test path a real click would.
"""
import logging
import os
import signal
import subprocess
import tempfile
import time
import warnings

from . import display, geometry, qwerty
from .qmp import QmpClient, QmpError

# The firmware needs a press held briefly or it never registers it; the device
# model (deluge_input.c) defers a too-fast release. Match that with a margin.
DEFAULT_HOLD_MS = 120

log = logging.getLogger("delugemu")


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

    # -- scripted input ------------------------------------------------------
    # Raw events on the input device's "dz-event" property: independent of the
    # pointer, so any set of controls can be held and each released at will.
    def _dz_event(self, text):
        self.q.qom_set(self._dev("input", "deluge-input", "/machine/soc/input"),
                       "dz-event", text)

    def button(self, x, y, down):
        """Press (down=True) or release a front-panel button at matrix column x, row y."""
        self._dz_event("button %d %d %s" % (x, y, "down" if down else "up"))

    def pad_event(self, x, y, down):
        """Press or release grid pad (x, y): x 0..17 (16/17 the sidebar), y 0..7."""
        self._dz_event("pad %d %d %s" % (x, y, "down" if down else "up"))

    def encoder(self, index, detents):
        """Turn encoder ``index`` (firmware order: 0 scroll Y, 1 scroll X, 2 tempo,
        3 select, 4 upper gold, 5 lower gold) by signed ``detents``."""
        self._dz_event("encoder %d %d" % (index, detents))

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

    def _alt(self, down):
        self._events([{"type": "key", "data": {
            "down": down, "key": {"type": "qcode", "data": "alt"}}}])

    def type_text(self, text, gap=0.15):
        """Type ``text`` on the pad-grid QWERTY keyboard the firmware shows
        while naming a file or browsing (see ``delugemu.qwerty``). In a file
        browser this jumps to the first entry the text prefixes. Raises
        ValueError, before pressing anything, if a character is untypeable."""
        keys = [qwerty.key_for(ch) for ch in text]
        for (x, y), shifted in keys:
            if shifted:
                # Shift is a pad held while the key is pressed: Alt-latch the
                # shift pad, tap the key (latched press, then release), and drop
                # the latch.
                self._alt(True)
                self._click(*geometry.pad_point(*qwerty.SHIFT_PAD), DEFAULT_HOLD_MS)
                self._click(*geometry.pad_point(x, y), DEFAULT_HOLD_MS)
                self._click(*geometry.pad_point(x, y), DEFAULT_HOLD_MS)
                self._alt(False)
            else:
                self.pad(x, y)
            self.wait(gap)

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

    def sd_command_count(self):
        """Total SD commands the firmware has issued since power-on."""
        path = self._dev("sdhi", "rza1l-sdhi", "/machine/soc/sdhi")
        return int(self.q.qom_get(path, "dz-cmd-count"))

    def wait_sd_idle(self, quiet=1.0, timeout=60.0, poll=0.1):
        """Wait until the firmware issues no SD command for ``quiet`` seconds
        (e.g. a song or preset has finished loading). Returns True once quiet,
        False on timeout. Sample streaming during playback never goes quiet."""
        deadline = time.monotonic() + timeout
        last = self.sd_command_count()
        since = time.monotonic()
        while time.monotonic() < deadline:
            self.wait(poll)
            now = self.sd_command_count()
            if now != last:
                last, since = now, time.monotonic()
            elif time.monotonic() - since >= quiet:
                return True
        return False

    def browser_open(self, window=0.8, poll=0.05):
        """Whether a load browser is open, judged by the LOAD LED, which
        blinks for as long as one is. Samples the LED over ``window`` seconds."""
        deadline = time.monotonic() + window
        while time.monotonic() < deadline:
            if self.read_leds().get("LOAD"):
                return True
            self.wait(poll)
        return False

    def _open_song_browser(self, settle):
        self.press("LOAD")
        self.wait(settle)
        if not self.wait_until(lambda s: s.browser_open(), timeout=10.0, poll=0):
            raise AssertionError("LOAD did not open the song browser")

    def _song_browser_to_root(self, settle):
        """Open the song browser at the SONGS folder. It opens in the current
        song's folder and BACK climbs one level, closing the browser from
        SONGS itself; so count the BACKs that close it, reopen, and climb one
        fewer."""
        self._open_song_browser(settle)
        depth = 0
        while True:
            self.press("BACK")
            self.wait(settle)
            if not self.browser_open():
                break
            depth += 1
            if depth > 32:
                raise AssertionError("BACK never closed the song browser")
        log.debug("song browser opened %d folder(s) below SONGS", depth)
        self._open_song_browser(settle)
        for _ in range(depth):
            self.press("BACK")
            self.wait(settle)

    def _type_entry(self, name, settle):
        prefix = qwerty.typeable_prefix(name)
        if not prefix:
            raise ValueError("browser entry %r starts with a character the "
                             "keyboard cannot type" % name)
        if prefix != name:
            warnings.warn("typing only %r of %r (the rest cannot be typed); "
                          "the browser will pick the first entry it prefixes"
                          % (prefix, name), stacklevel=3)
        self.type_text(prefix)
        self.wait(settle)

    def load_song(self, path, timeout=60.0, settle=0.6):
        """Load a song by its card path, e.g.
        ``/SONGS/problem_songs/Some Folder/My Song.XML`` (the ``/SONGS`` prefix
        and ``.XML`` extension are optional).

        Opens the song browser at ``SONGS``, then for each path part types its
        name on the pad QWERTY keyboard (the browser jumps to the first entry
        it prefixes) and presses SELECT: entering each folder, then loading the
        song. Returns once the browser has closed and the card has gone quiet.
        If a folder shares the song's name (``X/`` beside ``X.XML``), the
        browser may land on the folder; that is detected and the song beside it
        is selected instead. Names are matched as typed prefixes, so a name the
        keyboard cannot fully type (``(``, ``&``, ...) may resolve to a
        neighbouring entry (a warning says so)."""
        parts = qwerty.song_path_parts(path)
        self._song_browser_to_root(settle)
        for folder in parts[:-1]:
            log.debug("entering folder %r", folder)
            self._type_entry(folder, settle)
            self.press("SELECT_ENC")
            self.wait(settle)
            self.wait_sd_idle(quiet=0.3, timeout=timeout)

        log.debug("loading song %r", parts[-1])
        self._type_entry(parts[-1], settle)
        self.press("SELECT_ENC")
        self.wait(settle)
        if self.browser_open():
            # Still browsing: SELECT entered a folder of the same name rather
            # than loading. Back out (which reselects that folder) and step to
            # the next entry, the song, which sorts straight after it.
            self.press("BACK")
            self.wait(settle)
            self.turn("SELECT_ENC", -1)
            self.wait(settle)
            self.press("SELECT_ENC")
            self.wait(settle)
            if self.browser_open():
                raise AssertionError("could not load %r: the browser is still "
                                     "open after selecting it" % path)
        if not self.wait_sd_idle(quiet=1.0, timeout=timeout):
            raise AssertionError("song %r still loading after %.0f s"
                                 % (path, timeout))

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
