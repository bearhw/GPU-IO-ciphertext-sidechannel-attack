#!/bin/bash
# Follow-up to run_chain_v2.sh (whose loop was stopped after run_e2e_v2_r1).
# The three runs are run_e2e_blind (run 1), run_e2e_v2_r1 (run 2), run_e2e_v2_r2 (run 3).
#   1. wait for run 2's in-flight infra retry (pid $1) to exit
#   2. run 2:  infra retry until every sample has an attack attempt (max passes)
#   3. run 1:  same, with run 1's code (old probe pad-bounds estimator)
#   4. run 3:  full pass with the bitmap estimator, then infra retry until complete
# Only no-attempt samples (SAMPLE_ERROR / GEN_FAIL / localized but no Stage 5)
# are retried; real attack outcomes are never re-rolled.
# Run as root inside tmux.
set -u
P=/home/eun/open-science/case_study/llm/pipeline
L=/home/eun/open-science/case_study/llm
MAX_PASSES=6
cd "$P" || exit 1

restore_bitmap() { cp "$L/orchestrate_v4.v2_bitmap.bak" "$L/orchestrate_v4.py"; }
trap restore_bitmap EXIT

n_missing() {
    python3 -c "import sys; sys.path.insert(0, '$P'); from pathlib import Path; \
import retry_infra_after_run as r; print(len(r.infra_indices(Path('$1'))))"
}

retry_until_complete() {
    local OUT="$1" pass=1
    while [ "$(n_missing "$OUT")" -gt 0 ] && [ $pass -le $MAX_PASSES ]; do
        echo "[chain3] $(date '+%F %T') $(basename "$OUT"): $(n_missing "$OUT") missing, infra pass $pass"
        python3 -u retry_infra_after_run.py --output-dir "$OUT"
        pass=$((pass + 1))
    done
    echo "[chain3] $(date '+%F %T') $(basename "$OUT"): done, $(n_missing "$OUT") still missing"
}

if [ -n "${1:-}" ]; then
    echo "[chain3] $(date '+%F %T') waiting for pid $1 (run 2 infra retry)"
    while kill -0 "$1" 2>/dev/null; do sleep 60; done
fi

retry_until_complete "$P/run_e2e_v2_r1"

echo "[chain3] $(date '+%F %T') switching to run 1 code (probe estimator)"
cp "$L/orchestrate_v4.run1_probe.bak" "$L/orchestrate_v4.py"
retry_until_complete "$P/run_e2e_blind"
restore_bitmap
echo "[chain3] $(date '+%F %T') restored bitmap estimator"

OUT="$P/run_e2e_v2_r2"
echo "[chain3] $(date '+%F %T') starting $(basename "$OUT")"
python3 -u auto_watchdog.py --blind --to-stage 5 --build-dict --output-dir "$OUT"
retry_until_complete "$OUT"
echo "[chain3] $(date '+%F %T') all done"
