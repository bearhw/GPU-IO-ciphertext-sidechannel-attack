#!/bin/bash
# Back-to-back full blind e2e runs, each kept in its own directory:
#   run 1: run_e2e_blind       (already running; its infra-retry pass is queued)
#   run 2: run_e2e_blind_run2
#   run 3: run_e2e_blind_run3
# Each run = one watchdog pass over all 1641 samples, then one pass that
# re-measures only the samples with no attack attempt (see
# retry_infra_after_run.py). Run as root inside tmux.
set -u
P=/home/eun/open-science/case_study/llm/pipeline
cd "$P" || exit 1

busy() {   # is any watchdog / infra-retry still working on directory $1?
    ps -eo args | awk -v d="$1" '
        ($1 == "python3" || ($1 == "sudo" && $2 == "python3")) &&
        /auto_watchdog\.py|retry_infra_after_run\.py/ {
            for (i = 1; i <= NF; i++) if ($i == d) found = 1
        } END { exit !found }'
}

echo "[chain] $(date '+%F %T') waiting for run 1 ($P/run_e2e_blind) and its infra retry"
while busy "$P/run_e2e_blind"; do sleep 60; done
echo "[chain] $(date '+%F %T') run 1 finished"

for RUN in run_e2e_blind_run2 run_e2e_blind_run3; do
    OUT="$P/$RUN"
    echo "[chain] $(date '+%F %T') starting $RUN"
    python3 -u auto_watchdog.py --blind --to-stage 5 --build-dict --output-dir "$OUT"
    echo "[chain] $(date '+%F %T') $RUN main pass exited (rc=$?); infra retry"
    python3 -u retry_infra_after_run.py --output-dir "$OUT"
    echo "[chain] $(date '+%F %T') $RUN finished"
done
echo "[chain] $(date '+%F %T') all runs done"
