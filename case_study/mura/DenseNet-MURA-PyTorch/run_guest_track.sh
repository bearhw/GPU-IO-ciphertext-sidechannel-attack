#!/bin/bash
# run_guest_track.sh
#
# Runs on GUEST. Paired with run_host_side.sh — executes track_input.py
# N times (default 5) and produces mura_guest_<i>.log.
#
# Usage:
#   ./run_guest_track.sh [num_runs(default 5)] [max_iters(default 10)] [phase(default valid)]
#
# Environment variables:
#   PYTHON=/path/to/python3   (default: /home/ubuntu/miniconda3/envs/vlm/bin/python3)
#   HOST_ADDR=user@host       (default: user@10.0.2.2)

set -u

RUNS=${1:-5}
MAX_ITERS=${2:-10}
PHASE=${3:-valid}
PYTHON=${PYTHON:-/home/ubuntu/miniconda3/envs/vlm/bin/python3}
HOST_ADDR=${HOST_ADDR:-user@10.0.2.2}
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

signal_host() {
    sudo -u ubuntu ssh \
        -o StrictHostKeyChecking=no -o ConnectTimeout=3 -o BatchMode=yes \
        "$HOST_ADDR" "touch $1" \
        >/dev/null 2>&1
}

echo "[GUEST] $RUNS run(s) x $MAX_ITERS iter(s), phase=$PHASE"
echo "[GUEST] Make sure run_host_side.sh is running on the host."

for i in $(seq 1 "$RUNS"); do
    OUT="mura_guest_${i}.log"
    RAW="mura_guest_${i}_raw.log"

    echo "[GUEST] (${i}/${RUNS}) signalling host: run start"
    signal_host /tmp/guest_run_start
    sleep 1

    echo "[GUEST] (${i}/${RUNS}) running track_input.py -> $OUT"
    sudo "$PYTHON" "$SCRIPT_DIR/track_input.py" \
        --max_iters "$MAX_ITERS" --phase "$PHASE" \
        2>&1 | tee "$RAW" | grep -E '^\[(GPA|TS|INFO)\]' > "$OUT"
    STATUS=${PIPESTATUS[0]}

    echo "[GUEST] (${i}/${RUNS}) signalling host: run done"
    signal_host /tmp/guest_run_done

    LINES=$(wc -l < "$OUT" 2>/dev/null || echo 0)
    if [ "$STATUS" -ne 0 ] || [ "$LINES" -eq 0 ]; then
        echo "[GUEST] (${i}/${RUNS}) [ERROR] track_input.py exit=$STATUS, $OUT has $LINES lines."
        echo "[GUEST] last 30 lines of $RAW:"
        tail -n 30 "$RAW"
        echo "[GUEST] Stopping further runs."
        break
    fi
    echo "[GUEST] (${i}/${RUNS}) complete. $OUT: $LINES lines"
done

echo "[GUEST] All $RUNS run(s) complete: mura_guest_1.log .. mura_guest_${RUNS}.log"
