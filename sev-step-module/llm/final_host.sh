#!/bin/bash
#
# FINAL experiment (host side): write_pattern_tracker, all guest RAM.
# Outputs CLOCK_REF + WRITE lines -> enables timestamp filtering in analysis.
#
# ORDER: start THIS first; wait for "waiting for guest signal"; THEN start guest.
#
set -e

TRACKER="./write_pattern_tracker"
ARGS="--duration 500 --settle 3"
OUTDIR="./final_logs"
RUNS=3
START=1

mkdir -p "$OUTDIR"
rm -f /tmp/guest_run_*_start /tmp/guest_run_*_done /tmp/host_tracker_ready_*

[ -x "$TRACKER" ] || make -s write_pattern_tracker

echo "[host] caching sudo credentials ..."
sudo -v

echo "============================================"
echo "  FINAL — $RUNS runs, batch=128, write_pattern_tracker"
echo "  $TRACKER $ARGS"
echo "============================================"

for i in $(seq $START $RUNS); do
    echo ""
    echo "[host] Run $i/$RUNS: waiting for guest signal (/tmp/guest_run_${i}_start) ..."
    while [ ! -f "/tmp/guest_run_${i}_start" ]; do sleep 0.5; done
    rm -f "/tmp/guest_run_${i}_start"

    echo "[host] Run $i: arming tracker (settle 3s + detect 180s) ..."
    sudo sh -c "$TRACKER $ARGS > ${OUTDIR}/host_run${i}.log 2>${OUTDIR}/host_run${i}_dbg.log"

    echo "[host] Run $i: done -> ${OUTDIR}/host_run${i}.log"
    echo "       WRITE=$(grep -c '^WRITE' ${OUTDIR}/host_run${i}.log 2>/dev/null || echo 0)"
done

echo ""
echo "[host] Done. Now run:  python3 final_analyze.py"
