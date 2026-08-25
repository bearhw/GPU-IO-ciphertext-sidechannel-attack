#!/bin/bash
#
# MNIST experiment (guest side).
# Run on the guest after mnist_host.sh is waiting on the host.
#
set -e

HOST="eun@10.0.2.2"
SSH_OPTS="-o StrictHostKeyChecking=no -o ConnectTimeout=3 -o BatchMode=yes"
MNIST_PYTHON="/home/ubuntu/miniconda3/bin/python3"
MNIST_SCRIPT="/home/ubuntu/cc_uvm/pytorch_uvm310_test/mnist/main.py"
OUTDIR="/home/ubuntu/mnist_logs"
SETTLE=5   # host settle 3s + margin

mkdir -p "$OUTDIR"

ssh_signal() { sudo -u ubuntu ssh $SSH_OPTS "$HOST" "touch $1" 2>/dev/null || \
               echo "[guest] WARN: could not signal $1"; }

echo "============================================"
echo "  MNIST Guest — 3×bs64, then 3×bs1000"
echo "============================================"

# Runs 1-3: batch=64
for i in 1 2 3; do
    echo ""
    echo "[guest] Run $i/6 (bs64): signaling host ..."
    ssh_signal "/tmp/mnist_run_${i}_start"

    echo "[guest] Settling ${SETTLE}s ..."
    sleep "$SETTLE"

    LOG="${OUTDIR}/guest_bs64_run${i}.log"
    echo "[guest] Running main.py --batch-size 64 -> $LOG"
    sudo "$MNIST_PYTHON" "$MNIST_SCRIPT" --batch-size 64 --epochs 1 --no-accel \
        2>&1 | tee "$LOG"

    echo "[guest] Run $i done."
    sleep 5
done

# Runs 4-6: batch=1000
for i in 4 5 6; do
    echo ""
    echo "[guest] Run $i/6 (bs1000): signaling host ..."
    ssh_signal "/tmp/mnist_run_${i}_start"

    echo "[guest] Settling ${SETTLE}s ..."
    sleep "$SETTLE"

    LOG="${OUTDIR}/guest_bs1000_run$((i-3)).log"
    echo "[guest] Running main.py --batch-size 1000 -> $LOG"
    sudo "$MNIST_PYTHON" "$MNIST_SCRIPT" --batch-size 1000 --epochs 1 --no-accel \
        2>&1 | tee "$LOG"

    echo "[guest] Run $i done."
    sleep 5
done

echo ""
echo "[guest] All 6 runs complete."
