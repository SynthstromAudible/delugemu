#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Scenario regression harness for the delugemu scripting interface.
#
# Runs every scenario under tests/scenarios/ (or the ones named as arguments)
# against a freshly launched headless emulator, using the `delugemu` Python
# package to drive the panel and assert on deterministic display state. Each
# scenario launches its own instance (clean isolation) with `-d int` logging so
# assert_no_aborts works.
#
# Firmware is not shipped with the repo, so the harness SKIPS cleanly (exit 0)
# when no firmware is available, matching tests/boot.sh. Set DELUGE_FIRMWARE (or
# place a .bin in firmware/) to run it, or DELUGEMU_FETCH_FIRMWARE=1 to let it
# download the latest release.
#
#   ./tests/scenario.sh                        # all scenarios
#   ./tests/scenario.sh tests/scenarios/boot.json
#   DELUGE_FIRMWARE=path ./tests/scenario.sh
#   DELUGEMU_FETCH_FIRMWARE=1 ./tests/scenario.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
case "$(uname -s 2>/dev/null || echo unknown)" in
    MINGW*|MSYS*|CYGWIN*) EXE_SUFFIX=".exe" ;;
    *)                    EXE_SUFFIX="" ;;
esac
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm${EXE_SUFFIX}"

ART_DIR="${DELUGEMU_ARTIFACTS:-${REPO_ROOT}/build/scenario-artifacts}"

fail() { printf 'SCENARIO FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'SCENARIO SKIP: %s\n' "$*"; exit 0; }

[ -x "${BIN}" ] || fail "qemu-system-arm not built at ${BIN} (run scripts/build.sh)"
command -v python3 >/dev/null 2>&1 || skip "python3 not available"

# Resolve a firmware image the same way run.sh does, to decide up front whether
# to run or skip cleanly. An explicit path, then a local .bin, else only run if
# the download fallback is enabled.
FIRMWARE="${DELUGEMU_FIRMWARE:-${DELUGE_FIRMWARE:-}}"
FIRMWARE_DIR="${DELUGEMU_FIRMWARE_DIR:-${REPO_ROOT}/firmware}"
if [ -z "${FIRMWARE}" ] && [ -d "${FIRMWARE_DIR}" ]; then
    FIRMWARE="$(find "${FIRMWARE_DIR}" -type f -iname '*.bin' 2>/dev/null \
                | LC_ALL=C sort | head -n1 || true)"
fi
if [ -z "${FIRMWARE}" ] \
    && [ "${DELUGEMU_FETCH_FIRMWARE:-0}" != "1" ] \
    && [ -z "${DELUGEMU_FIRMWARE_REPO:-}" ]; then
    skip "no firmware image (set DELUGE_FIRMWARE=path, DELUGEMU_FETCH_FIRMWARE=1, or add firmware/*.bin)"
fi

SCENARIOS=("$@")
if [ ${#SCENARIOS[@]} -eq 0 ]; then
    while IFS= read -r f; do SCENARIOS+=("$f"); done \
        < <(find "${REPO_ROOT}/tests/scenarios" -type f \
                \( -name '*.json' -o -name '*.yaml' -o -name '*.yml' \) \
                2>/dev/null | LC_ALL=C sort)
fi
[ ${#SCENARIOS[@]} -gt 0 ] || skip "no scenario files found"

# Optional SD-card image override (otherwise run.sh resolves its default card).
SD="${DELUGEMU_SD:-}"

mkdir -p "${ART_DIR}"
printf 'SCENARIO: firmware=%s  artifacts=%s\n' \
    "${FIRMWARE:-<fetch-latest>}" "${ART_DIR#"${REPO_ROOT}/"}"

rc=0
for scn in "${SCENARIOS[@]}"; do
    name="$(basename "${scn}")"; name="${name%.*}"
    printf '  running %s...\n' "${name}"
    if PYTHONPATH="${REPO_ROOT}/pylib" python3 -m delugemu.cli run "${scn}" \
            ${FIRMWARE:+--firmware "${FIRMWARE}"} \
            ${SD:+--sd "${SD}"} \
            --artifacts "${ART_DIR}" \
            --int-log "${ART_DIR}/${name}-int.log"; then
        printf '  %s: OK\n' "${name}"
    else
        printf '  %s: FAIL\n' "${name}" >&2
        rc=1
    fi
done

[ "${rc}" -eq 0 ] || fail "one or more scenarios failed (see ${ART_DIR#"${REPO_ROOT}/"})"
printf 'SCENARIO OK: all scenarios passed\n'
