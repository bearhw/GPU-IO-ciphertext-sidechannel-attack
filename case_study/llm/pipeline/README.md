# LLM End-to-End Modular Attack Pipeline

A 5-stage modular attack pipeline analyzing and reconstructing patient Clinical Indication texts from the encrypted memory of VLM/LLM (Qwen2-VL-2B-Instruct) workloads in an SEV-SNP environment. Each stage operates as an independent CLI script coupled through JSON caches and standard interfaces. `master_orchestrate.py` automates full or selective execution across stages.

---

## 1. Architecture & 2-Stage Pinpoint Localization

```
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 1: Dict & Reference Plant (stage1_prepare_dict.py)               │
│  - Acquire clean Zero GPA and validate <|image_pad|> reference fingerp.│
│  - Generate and validate clinical token dictionary (dict_cache_v4.json)│
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 2: Write Tracking & 2MB Block Ranking (stage2_track_blocks.py)   │
│  - Trigger guest VLM inference and log with Write Pattern Tracker      │
│  - Analyze GPU-CC Region A/B and contiguous write runs (max_run_len)   │
│  - Rank 2MB candidate blocks and export stage2_tracked_{index}.json    │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 3: Image-Pad Fingerprint Base Localization (stage3_locate_base.py)│
│  - 1-swap Image-Pad fingerprint scan on candidate 2MB blocks           │
│  - Combined adaptive continuation / next-block / bootstrap fallbacks   │
│  - Pinpoint input_ids base GPA (host_base) and save metadata           │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 4: Pad Boundary & Indication Bounds Search (stage4_estimate_bounds.py)
│  - Binary search (~11 swaps) for Image-Pad boundary from Base GPA      │
│  - Determine pad token count (N_est) and token range [tok_min, tok_max]│
│  - Save boundary metadata to stage4_bounds_{index}.json                │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 5: Dictionary Matching & Evaluation (stage5_dict_match.py)       │
│  - Execute sweep_blind dictionary swap matching on Indication window   │
│  - Quantitative analysis: Top-1 accuracy, Multi-matches, and FPs       │
│  - Save final results to stage5_result_{index}.json                    │
└────────────────────────────────────────────────────────────────────────┘
```

---

## 2. File Organization

- **Created:** filesystem birth time (`stat %w`).
- **Modified:** last modification time.
- All dates are 2026. This section was rewritten on 11-18, after checking every git-tracked file in this directory: 22,560 files, of which 138 are at the top level, plus 33 subdirectories.
- Stage 4/5 import `../orchestrate_v4.py`, which sits outside this directory, for the swap, pad-bounds and matching primitives.

### 2.1 Final blind end-to-end results (three runs over the 1,641 filtered samples)

Run with `run_status.py`. "Strict" means a match counts only when it is exact.

| Run (directory) | Pad-bounds estimator | Period | true block in top-10 | Localization | Match \| loc (strict) | End-to-end (strict) |
|---|---|---|---|---|---|---|
| run 1 `run_e2e_blind/` | old probe | 10-24 to 10-29 | 61.5% (1010) | 78.9% (1295) | 52.3% (677/1295) | 41.3% (677) |
| run 2 `run_e2e_v2_r1/` | bitmap | 10-27 to 10-29 | 60.0% (984) | 78.2% (1284) | 56.5% (725/1284) | 44.2% (725) |
| run 3 `run_e2e_v2_r2/` | bitmap | 10-29 to 10-31 | 61.2% (1005) | 79.4% (1303) | 53.8% (701/1303) | 42.7% (701) |

Each run is one `auto_watchdog.py --blind --to-stage 5 --build-dict` pass, followed by `retry_infra_after_run.py`. The retry pass re-measures only the samples with no attack attempt: SAMPLE_ERROR, GEN_FAIL, or localized but no Stage 5. All three runs end with 0 no-attempt samples.

### 2.2 Code and scripts

| File | Created | Modified | Role |
|---|---|---|---|
| `README.md` | 09-11 | 11-18 | This file. |
| `common.py` | 10-24 | 10-24 | Shared configuration, SSH, Pacer (swap safety pacing), network settings, evaluation metrics, `PIPELINE_DIR` and other paths. |
| `stage1_prepare_dict.py` | 09-22 | 09-22 | [Stage 1] Checks the zero-page GPA and the `<\|image_pad\|>` reference page fingerprint, then validates the token dictionary (`../dict_cache_v4.json`). Writes `stage1_ref.json`. |
| `stage2_track_blocks.py` | 10-24 | 10-24 | [Stage 2] Runs the guest VLM inference under `write_pattern_tracker`. Filters Region A/B, then ranks 2 MB blocks by max_run_len (S=H×R). Can also parse an existing log offline (`--host-log`). Writes `stage2_tracked_{i}.json`. |
| `stage3_locate_base.py` | 10-24 | 10-24 | [Stage 3] Finds `host_base` (the input_ids base GPA) inside the candidate blocks with 1-swap image_pad fingerprint scans. Strategies: blind_window, blind, plus fallbacks. With `--blind`, the GT block is never used. Writes `stage3_located_{i}.json`. |
| `stage4_estimate_bounds.py` | 10-24 | 10-24 | [Stage 4] Binary-searches the pad boundary from `host_base` using `orchestrate_v4._estimate_pad_bounds` (which estimator applies depends on the `orchestrate_v4.py` in use). Writes N_est and the token window to `stage4_bounds_{i}.json`. |
| `stage5_dict_match.py` | 10-24 | 10-24 | [Stage 5] Dictionary swap matching over the indication window (`orchestrate_v4` sweep), giving the verdict MATCH / MULTI_MATCH / NO_MATCH. Writes `stage5_result_{i}.json`. |
| `master_orchestrate.py` | 10-24 | 10-24 | Runs stages 1–5 together or selectively. Options include `--blind`, `--build-dict`, `--filtered-only`, `--all`, `--track-size` and `--fast`; supports batch and persistent stdin-loop modes. Appends to `pipeline_summary.csv`. |
| `auto_watchdog.py` | 10-25 | 10-25 | Supervisor for unattended runs. Detects guest/QEMU crashes, tears down QEMU, TAP and sockets, reboots in SNP mode, re-enables CC mode, runs net_preflight, then resumes `master_orchestrate.py` from the summary CSV. Loops until all 1,641 samples are done. |
| `retry_infra_after_run.py` | 10-25 | 10-25 | After the watchdog finishes, re-measures only the no-attempt samples (infrastructure failures) once. Real attack outcomes (LOC_FAIL, MATCH, MULTI_MATCH, NO_MATCH) are never re-run. |
| `run_status.py` | 10-27 | 10-27 | Prints progress, top-10 block coverage, localization, strict matching and end-to-end rates for the blind e2e runs. No-attempt samples are excluded. Defaults to the v2 runs. |
| `evaluate_localization.py` | 09-16 | 09-16 | Aggregates localization rate, swap count and time from `pipeline_summary.csv` or `stage3_located_*.json`. Reports blind hits separately from GT-assisted ones (strategy `bootstrap`). |
| `batch_orchestrate.py` | 09-16 | 09-16 | Batch-mode localization experiment. The guest pins a `[B, seq_len]` input_ids buffer and rewrites it N times, so its 2 MB block ranks at the top. Output: `batch_run/`, `bs1_test/`. |
| `persistent_orchestrate.py` | 09-24 | 09-24 | Persistent-process experiment. Establishes the input_ids block ranking during a warmup, then measures later samples only by whether they land in the top-K. Output: `persistent_run/`. |
| `run_auto.sh` | 09-19 | 09-19 | Runs `master_orchestrate.py --filtered-only --from-stage 1 --to-stage 3 --blind --output-dir run_filtered_ml`. |
| `run_chain.sh` | 10-25 | 10-25 | After run 1 (`run_e2e_blind`), runs `run_e2e_blind_run2` and `_run3` back to back. Only run2 started; it is kept as the 827-row partial in `run_e2e_blind_run2.partial-816-oldpad/`. |
| `run_chain_v2.sh` | 10-27 | 10-27 | Runs three passes with the bitmap pad-bounds estimator (`run_e2e_v2_r1..r3`). The loop was stopped after r1. |
| `run_chain_v3.sh` | 10-29 | 10-29 | Follow-up to v2: infra retry on run 2 (v2_r1) until complete; infra retry on run 1 after swapping `../orchestrate_v4.py` for `orchestrate_v4.run1_probe.bak`; then the full run 3 (v2_r2). Restores the bitmap version on exit. |

### 2.3 Data and results at the top level

| File | Created | Modified | Contents |
|---|---|---|---|
| `block_ranker.pkl` | 09-18 | 09-18 | ML 2 MB block ranker (pickle). No `.py` in the current repo loads it; it is a leftover from the `run_filtered_ml` period (09-18 to 09-21). |
| `dataset_blocks.npz` | 09-18 | 09-18 | Block-feature dataset for training the ranker: `X` (15975×12), `y` (15975), `feature_names` (12), `meta`. |
| `pipeline_summary.csv` | 09-14 | 09-15 | Summary when the output dir is the default (this directory). Currently 1 row: #2, MATCH. |
| `stage1_ref.json` | 09-11 | 09-15 | Stage 1 result: `dict_cache_path` (`../dict_cache_v4.json`), 512 keys, `image_pad_token_id` 151655, READY. |
| `sample_2_wpt.log` | 09-11 | 09-15 | Empty file (0 B). Placeholder for the Stage 2 write log. |
| `stage2_tracked_{i}.json` | 09-14 to 09-21 | same | Stage 2 output from the first runs in the default dir. Indices: 0, 1, 2, 4, 5, 9, 11, 12, 13, 15, 17, 22, 24, 26, 28, 29, 31, 32, 34, 36, 38, 39, 41, 43, 44, 45, 46, 47, 50, 51, 52, 56, 61 (09-14/15), and 1471, 2380, 2404, 2418, 2510, 2517, 2536, 2538, 2539, 2542, 2545, 2546 (09-21, larger files with full candidate lists). |
| `stage3_located_{i}.json` | 09-14/15 | same | Stage 3 output for the same 33 small indices as above (0 … 61). |
| `stage4_bounds_{i}.json` | 09-14 | 09-14 | Stage 4 output: indices 0, 1, 2, 9. |
| `stage5_result_{i}.json` | 09-14/15 | same | Stage 5 output for the same 33 indices (0 … 61). Most are 256 B with `status: LOC_FAIL`, i.e. localization failed so no matching was done. |

### 2.4 Run directories

Each directory is the `--output-dir` of one run. It usually holds `pipeline_summary.csv`, `stage1_ref.json` and per-sample `stage{2,3,4,5}_*_{i}.json` files. "n" is the number of rows in `pipeline_summary.csv`; the date is the files' creation date.

| Directory | Files | Date | n | Contents |
|---|---|---|---|---|
| `run_e2e_blind/` | 4610 | 10-24 to 10-29 | 1641 | **run 1** (final), with the old probe pad-bounds estimator. See 2.1. |
| `run_e2e_v2_r1/` | 4598 | 10-27 to 10-29 | 1641 | **run 2** (final), bitmap estimator. |
| `run_e2e_v2_r2/` | 4623 | 10-29 to 10-31 | 1641 | **run 3** (final), bitmap estimator. |
| `run_e2e_v2_r1.bitmap-v1-35/` | 60 | 10-27 | 35 | The first 35 samples of v2_r1, run with the first bitmap estimator (v1); 12 SAMPLE_ERROR. Set aside and r1 restarted. The log is `run_chain_v2.bitmap-v1.log`, which is not in git. |
| `run_e2e_blind_run2.partial-816-oldpad/` | 2145 | 10-26 to 10-27 | 827 | Partial run2 from `run_chain.sh`, old pad estimator, indices 2–1758. Its watchdog got SIGTERM at 10-27 10:39 (`run_chain.log`); the bitmap run (v2_r1) started at 11:07. |
| `run_e2e_blind.anchor-poisoned-1626/` | 163 | 10-24 | 78 | Aborted attempt before run 1. LOC_FAIL 73/78. |
| `run_e2e_blind.sticky-seed-1804/` | 194 | 10-24 | 80 | Aborted attempt before run 1. Localization 30/80. |
| `run_e2e_blind.hybrid-cold-1857/` | 15 | 10-24 | 10 | Aborted attempt before run 1. SAMPLE_ERROR 3, GEN_FAIL 1. |
| `run_e2e_blind.invalid-scoring-1424/` | 31 | 10-24 | 10 | Aborted attempt before run 1. Localization 9/10, but the scoring was invalid (going by the name). |
| `run_e2e_blind.window-1920/` | 17 | 10-24 | 5 | Aborted attempt before run 1. blind_window strategy test. |
| `pilot_bitmap/` | 24 | 10-27 | 7 | Bitmap pad-bounds estimator pilot: MATCH 4, MULTI 1, NO_MATCH 1, LOC_FAIL 1. |
| `run_knownblock/` | 3282 | 09-24 to 09-27 | 1641 | Localization only, with the GT block given (`known`, stages 1–3): LOC_SUCCESS 1563/1641. Upper bound for in-block localization. |
| `run_filtered_ml/` | 2390 | 09-18 to 09-21 | 1206 | `run_auto.sh` (blind, stages 1–3, filtered samples), ML block-ranking period: SUCCESS 642 / LOC_FAIL 537 / GEN_FAIL 13 / LOC_MISMATCH 11. |
| `run_filtered/` | 30 | 09-22 | 9 | Small blind stage 1–3 run on filtered samples, all LOC_FAIL. |
| `run_full_attack/` | 44 | 09-18 | 13 | Early full stage 1–5 attempt (non-blind): LOC_FAIL 11, MATCH 1, NO_MATCH 1. |
| `persistent_run/` | 95 | 09-17 to 09-18 | 46 | `persistent_orchestrate.py` experiment: LOC_SUCCESS 2/46. |
| `batch_run/` | 29 | 09-16 | 28 batches | `batch_orchestrate.py` (bs=128): batch block loc_match 16/28, rows_recovered 0. The file is `batch_summary.csv`. |
| `bs1_test/` | 4 | 09-16 | 3 | `batch_orchestrate.py` with bs=1: loc_match 1/3. |
| `blind_all/` | 10 | 09-16 | 4 | Early blind attempt, all LOC_FAIL. |
| `gtcheck/` | 8 | 09-24 | 3 | GT check run, all LOC_FAIL. |
| `known_run/` | 12 | 09-24 | 5 | Early known-address run: LOC_SUCCESS 1/5. |
| `verify_run/` | 4 | 09-15 | 1 | Single-sample (#2) verification, blind, LOC_FAIL. |
| `run_verify_final/`, `test_ml_final/`, `test_ml_run/`, `test_run_idx2/`, `test_run_verify/`, `test_single/` | 4–5 each | 09-18 | 1 each | Single-sample (#2) debug runs, all LOC_FAIL. |
| `test_verify_2/`, `test_verify_final/`, `test_verify_final2/`, `test_verify_run/` | 1–2 each | 09-18 | 0 | Empty runs (CSV header only; `test_verify_2` also has `stage1_ref.json`). |
| `wpt_dataset/` | 1 | 09-18 | — | `dataset_manifest.json`: per-sample WPT log path, gt_base/gt_block/gt_N/indication and collection time. The WPT logs themselves are not in git. |

The suffixes of the `run_e2e_blind.*-HHMM` directories look like a tag for why the attempt was aborted plus the time (10-24 HH:MM). This README does not explain the tags further: neither git nor the session records found say what they mean (**unverified**).

### 2.5 Not in git (local only)

| File | Description |
|---|---|
| `run_chain.log`, `run_chain_v2.log`, `run_chain_v2.bitmap-v1.log`, `run_chain_v3.log`, `pilot_bitmap.log` | Chain-script and pilot logs (git-ignored by `*.log`). |

---

## 3. Usage Examples

### (0) Network Preflight Check (Once after QEMU boot)
```bash
sudo /home/eun/proof_code/llm/net_preflight.sh
```

### (1) Full End-to-End Execution via Master Orchestrator
```bash
# Execute full pipeline for a single sample (Stages 1–5)
sudo python3 master_orchestrate.py --index 2

# Batch mode execution (Indices 2, 9, 12 - fast processing with single model load)
sudo python3 master_orchestrate.py --indices 2,9,12

# Range batch mode execution (Samples 0 to 10)
sudo python3 master_orchestrate.py --start 0 --end 10
```

### (2) Selective Stage Execution
```bash
# Run Stage 3 (Base GPA localization) to Stage 5 (Label recovery) only
sudo python3 master_orchestrate.py --from-stage 3 --to-stage 5 --index 2

# Run Stage 5 (Label recovery & false positive analysis) standalone
python3 master_orchestrate.py --stage 5 --index 2
```

### (3) Standalone Module Execution (CLI)
```bash
# Stage 1: Prepare Dict & Ref
python3 stage1_prepare_dict.py --skip-existing --output-dir .

# Stage 2: Write Pattern Tracking & 2MB Block Ranking
# (Online execution)
sudo python3 stage2_track_blocks.py --index 2 --output-dir .
# (Offline log analysis)
python3 stage2_track_blocks.py --index 2 --host-log ../e2e_combined_wpt.log --output-dir .

# Stage 3: Base GPA Localization (1-swap Image-Pad fingerprint scan)
sudo python3 stage3_locate_base.py --index 2 --output-dir .

# Stage 4: Pad Boundary Binary Search
sudo python3 stage4_estimate_bounds.py --index 2 --output-dir .

# Stage 5: Dictionary Matching & FP Analysis
sudo python3 stage5_dict_match.py --index 2 --output-dir .
```

---

## 4. Artifact Specifications

- `stage1_ref.json`: Dictionary cache path and Reference metadata
- `stage2_tracked_{index}.json` & `sample_{index}_wpt.log`: Top 2MB candidate block rankings and scores
- `stage3_located_{index}.json`: Pinpointed `host_base` GPA, search strategy, and swap counts
- `stage4_bounds_{index}.json`: `N_est` and Indication token scan window `[tok_min, tok_max]`
- `stage5_result_{index}.json`: Recovered clinical labels, Top-1 match status, and false positive list
- `pipeline_summary.csv`: Summary statistics table across all batch runs
