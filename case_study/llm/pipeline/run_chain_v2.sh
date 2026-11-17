#!/bin/bash
# Three back-to-back full blind e2e runs with the bitmap pad-bounds estimator
# (orchestrate_v4._estimate_pad_bounds_bitmap), each kept in its own directory:
#   run_e2e_v2_r1, run_e2e_v2_r2, run_e2e_v2_r3
# Each run = one watchdog pass over all 1641 samples, then one pass that
# re-measures only the samples with no attack attempt (retry_infra_after_run.py).
# Run as root inside tmux.
set -u
P=/home/eun/open-science/case_study/llm/pipeline
cd "$P" || exit 1

for RUN in run_e2e_v2_r1 run_e2e_v2_r2 run_e2e_v2_r3; do
    OUT="$P/$RUN"
    echo "[chain] $(date '+%F %T') starting $RUN"
    python3 -u auto_watchdog.py --blind --to-stage 5 --build-dict --output-dir "$OUT"
    echo "[chain] $(date '+%F %T') $RUN main pass exited (rc=$?); infra retry"
    python3 -u retry_infra_after_run.py --output-dir "$OUT"
    echo "[chain] $(date '+%F %T') $RUN finished"
done
echo "[chain] $(date '+%F %T') all runs done"
