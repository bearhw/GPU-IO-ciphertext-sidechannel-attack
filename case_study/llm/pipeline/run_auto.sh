#!/usr/bin/env bash
set -e
cd /home/eun/open-science/case_study/llm/pipeline
sudo python3 -u master_orchestrate.py --filtered-only --from-stage 1 --to-stage 3 --blind --output-dir run_filtered_ml 2>&1 | tee -a run_filtered_ml/pipeline_run.log
