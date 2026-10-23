#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Run the whole test suite and report PASS / SKIP / FAIL for each test.
#
# Every test skips cleanly (exit 0) when something it needs is missing, which
# keeps the suite safe to run anywhere but means a broken firmware download
# could turn CI green while testing nothing. This runner makes that visible:
# each test's outcome is listed (and, under GitHub Actions, written to the job
# summary), and --require-firmware turns a skip into a failure for the tests
# that only skip for want of firmware or an SD image.
#
# Usage:
#   ./tests/run-all.sh                         # every test
#   ./tests/run-all.sh boot scenario           # just these
#   ./tests/run-all.sh --require-firmware      # CI: firmware must be present
#   DELUGE_FIRMWARE=path DELUGE_SD_IMG=img ./tests/run-all.sh
#
# Tests: smoke, unit (pylib unit tests), geometry-sync, boot, scenario,
# pad-click, usb-midi, usb-midi-bridge, usb-peripheral, midi-coremidi,
# audio-bench. Logs go to build/test-logs/<test>.log. Exits non-zero if any
# test failed.
set -uo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "${REPO_ROOT}"

ALL_TESTS=(smoke unit geometry-sync boot scenario pad-click usb-midi
           usb-midi-bridge usb-peripheral midi-coremidi audio-bench)

# Tests whose only reason to skip is missing firmware (or the SD image built
# alongside it). usb-peripheral is not listed: it also skips when the firmware
# predates peripheral USB support, which no published release has yet.
NEEDS_FIRMWARE=" boot scenario pad-click usb-midi usb-midi-bridge audio-bench "

REQUIRE_FIRMWARE=0
TESTS=()
for arg in "$@"; do
    case "${arg}" in
        --require-firmware) REQUIRE_FIRMWARE=1 ;;
        -h|--help) sed -n '3,24p' "$0" | sed 's/^# \{0,1\}//'; exit 0 ;;
        -*) printf 'run-all: unknown option %s\n' "${arg}" >&2; exit 2 ;;
        *) TESTS+=("${arg}") ;;
    esac
done
[ ${#TESTS[@]} -gt 0 ] || TESTS=("${ALL_TESTS[@]}")

LOG_DIR="${REPO_ROOT}/build/test-logs"
mkdir -p "${LOG_DIR}"

run_test() {
    case "$1" in
        unit) PYTHONPATH=pylib python3 -m unittest discover -s pylib/tests -v ;;
        *)
            [ -x "tests/$1.sh" ] || { printf 'no such test: %s\n' "$1"; return 2; }
            "./tests/$1.sh"
            ;;
    esac
}

results=()
failed=0
for t in "${TESTS[@]}"; do
    log="${LOG_DIR}/${t}.log"
    printf '=== %s\n' "${t}"
    start=$SECONDS
    run_test "${t}" >"${log}" 2>&1
    rc=$?
    secs=$((SECONDS - start))
    # Tests announce a skip as "<NAME> SKIP: <reason>" and exit 0.
    reason="$(grep -m1 -E '^[A-Z-]+ SKIP: ' "${log}" | sed -E 's/^[A-Z-]+ SKIP: //' || true)"
    if [ "${rc}" -ne 0 ]; then
        status=FAIL
    elif [ -n "${reason}" ]; then
        status=SKIP
        if [ "${REQUIRE_FIRMWARE}" -eq 1 ] && [[ "${NEEDS_FIRMWARE}" == *" ${t} "* ]]; then
            status=FAIL
            reason="skipped, but --require-firmware: ${reason}"
        fi
    else
        status=PASS
    fi
    [ "${status}" = FAIL ] && failed=1
    printf '%s %s (%ss)%s\n' "${status}" "${t}" "${secs}" "${reason:+ — ${reason}}"
    if [ "${status}" = FAIL ]; then
        printf -- '--- last lines of %s ---\n' "${log#${REPO_ROOT}/}"
        tail -n 25 "${log}"
    fi
    results+=("${status}|${t}|${secs}|${reason}")
done

printf '\n%-5s %-16s %6s  %s\n' RESULT TEST TIME NOTE
for r in "${results[@]}"; do
    IFS='|' read -r status t secs reason <<<"${r}"
    printf '%-5s %-16s %5ss  %s\n' "${status}" "${t}" "${secs}" "${reason}"
done

if [ -n "${GITHUB_STEP_SUMMARY:-}" ]; then
    {
        printf '### Test results (%s)\n\n' "${RUNNER_OS:-local}"
        printf 'Firmware: `%s`  \nSD image: `%s`\n\n' \
            "${DELUGE_FIRMWARE:-auto}" "${DELUGE_SD_IMG:-auto}"
        printf '| Result | Test | Time | Note |\n|---|---|---|---|\n'
        for r in "${results[@]}"; do
            IFS='|' read -r status t secs reason <<<"${r}"
            case "${status}" in PASS) icon='✅' ;; SKIP) icon='⏭️' ;; *) icon='❌' ;; esac
            printf '| %s %s | %s | %ss | %s |\n' "${icon}" "${status}" "${t}" "${secs}" "${reason}"
        done
    } >>"${GITHUB_STEP_SUMMARY}"
fi

exit "${failed}"
