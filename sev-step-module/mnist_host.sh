#!/bin/bash
#
# MNIST experiment (host side): write_pattern_tracker, all guest RAM.
# Runs 1-3: batch=64 -> mnist_logs_bs64/
# Runs 4-6: batch=1000 -> mnist_logs_bs1000/
#
# ORDER: start THIS first; THEN start mnist_guest.sh on the guest.
#
set -e

TRACKER="$(cd "$(dirname "$0")" && pwd)/write_pattern_tracker"
ARGS="--duration 300 --settle 3"

mkdir -p mnist_logs_bs64 mnist_logs_bs1000

[ -x "$TRACKER" ] || make -C "$(dirname "$TRACKER")" -s write_pattern_tracker

echo "[host] caching sudo credentials ..."
sudo -v

echo "============================================"
echo "  MNIST — 6 runs (3×bs64 + 3×bs1000)"
echo "  $TRACKER $ARGS"
echo "============================================"

for i in $(seq 1 6); do
    if [ "$i" -le 3 ]; then
        OUTDIR="mnist_logs_bs64"
        RUN_IDX="$i"
        LABEL="bs64 run $i/3"
    else
        OUTDIR="mnist_logs_bs1000"
        RUN_IDX=$((i - 3))
        LABEL="bs1000 run $((i-3))/3"
    fi

    echo ""
    echo "[host] Run $i/6 ($LABEL): waiting for guest signal (/tmp/mnist_run_${i}_start) ..."
    while [ ! -f "/tmp/mnist_run_${i}_start" ]; do sleep 0.5; done
    rm -f "/tmp/mnist_run_${i}_start"

    echo "[host] Run $i: arming tracker -> ${OUTDIR}/host_run${RUN_IDX}.log"
    sudo sh -c "$TRACKER $ARGS > ${OUTDIR}/host_run${RUN_IDX}.log 2>${OUTDIR}/host_run${RUN_IDX}_dbg.log"

    echo "[host] Run $i: done. WRITE=$(grep -c '^WRITE' ${OUTDIR}/host_run${RUN_IDX}.log 2>/dev/null || echo 0)"
done

echo ""
echo "[host] All 6 runs complete."
