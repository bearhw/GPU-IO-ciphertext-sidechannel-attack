#!/bin/bash
#
# FINAL experiment (guest side).
#
# scp this + single_inference.py to the guest. Start final_host.sh on the host
# FIRST (wait until it says "waiting for guest signal"), THEN run this.
#
set -e

HOST="user@10.0.2.2"
SSH_OPTS="-o StrictHostKeyChecking=no -o ConnectTimeout=3 -o BatchMode=yes"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
OUTDIR="${SCRIPT_DIR}"
VLM_PYTHON="/home/ubuntu/miniconda3/envs/vlm/bin/python3"
RUNS=3
START=1
BATCH_SIZE=128
SETTLE=5          # host settle 3s + margin

mkdir -p "$OUTDIR"

ssh_signal() { sudo -u ubuntu ssh $SSH_OPTS "$HOST" "touch $1" 2>/dev/null || \
               echo "[guest] WARN: could not signal $1"; }

echo "============================================"
echo "  Guest FINAL — $RUNS runs, batch=$BATCH_SIZE"
echo "============================================"

for i in $(seq $START $RUNS); do
    echo ""
    echo "[guest] Run $i/$RUNS: signaling host to arm tracker ..."
    ssh_signal "/tmp/guest_run_${i}_start"

    echo "[guest] Run $i: settling ${SETTLE}s so host arms tracker ..."
    sleep "$SETTLE"

    echo "[guest] Run $i: inference (batch=$BATCH_SIZE) ..."
    LOG="${OUTDIR}/guest_run${i}.log"
    > "$LOG"
    sudo "$VLM_PYTHON" "${SCRIPT_DIR}/single_inference.py" \
        --run_all \
        --batch_size "$BATCH_SIZE" \
        2>&1 | tee -a "$LOG"
    echo "[guest] Run $i: inference done. Waiting for host window ..."
    sleep 10
    echo "[guest] Run $i complete."
done

echo ""
echo "[guest] All $RUNS runs complete. scp final_logs/guest_run*.log back to host."
