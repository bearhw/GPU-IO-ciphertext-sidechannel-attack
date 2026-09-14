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

| Filename | Role |
|---|---|
| `common.py` | Shared configuration, SSH connections, Pacer safety control, network settings, evaluation metrics |
| `stage1_prepare_dict.py` | [Stage 1] Prepare & validate Zero GPA, Image-Pad Ref, and Token Dictionary |
| `stage2_track_blocks.py` | [Stage 2] Write Tracker logging and 2MB candidate block ranking |
| `stage3_locate_base.py` | [Stage 3] Pinpoint `host_base` GPA via 1-swap Image-Pad fingerprint scanning |
| `stage4_estimate_bounds.py` | [Stage 4] Pad boundary binary search and Indication token range estimation |
| `stage5_dict_match.py` | [Stage 5] Dictionary swap matching, clinical label recovery, Top-1 and FP analysis |
| `master_orchestrate.py` | Unified coordinator for Stages 1–5, selective execution, and Persistent Stdin-Loop batching |

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
