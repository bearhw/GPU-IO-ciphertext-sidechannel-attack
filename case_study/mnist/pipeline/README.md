# MNIST End-to-End Modular Attack Pipeline

A 5-stage modular attack pipeline analyzing and reconstructing encrypted memory from MNIST workloads in an SEV-SNP environment. Each stage operates as an independent CLI script coupled through JSON caches and standard I/O. `master_orchestrate.py` automates full or selective execution across stages.

---

## 1. Architecture & Pipeline Stages

```
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 1: Zero GPA Acquisition (stage1_zero_gpa.py)                     │
│  - Acquire clean Zero GPA from guest ICMP module (/proc/large_icmp_last)│
│  - Dump z.out via read_gpa.py and save metadata to zero_gpa.json       │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 2: Target Image GPA Tracking (stage2_track_gpa.py)               │
│  - Acquire Ground Truth GPA from guest process                         │
│  - Blind analysis of Region-B Precursor via write_pattern_tracker      │
│  - Automatic fallback to Ground Truth if blind detection misses        │
│  - Compute Page 2 GPA and save to tracked_target_{index}.json          │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 3: PSP Page Swap & Dump (stage3_swap_dump.py)                    │
│  - Swap-dump Page 1 & Page 2 ↔ Zero Page via swap_and_dump.py          │
│  - Restore guest memory state safely using --swap-back                 │
│  - Export {label}-{index}.out, {label}-{index}_p2.out, swap_meta.json  │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 4: Sparsity Feature Extraction (stage4_extract_features.py)      │
│  - Compare dump files against z.out                                    │
│  - PyTorch 64B alignment + spatial Center-of-Mass in-page offset search│
│  - Extract 196-dim Sparsity Vector: {label}-{index}.out_v5.list        │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 5: Multi-Model Reconstruction & Comparison (stage5_reconstruct.py)│
│  - Simultaneous reconstruction: v6r (Retrieval), v9r (UNet-GAN), v10   │
│  - Compute SSIM, PSNR, L1 Error vs MNIST Ground Truth                  │
│  - Output comparison_{index}.png and SSIM comparison table             │
└────────────────────────────────────────────────────────────────────────┘
```

---

## 2. File Organization

- **Created:** filesystem birth time (`stat %w`).
- **Modified:** last modification time.
- All dates are 2026. This section was rewritten on 11-18, after checking every git-tracked file in this directory.

```
mnist/pipeline/
├── README.md
├── EVAL_README.md
├── common.py
├── stage1_zero_gpa.py
├── stage2_track_gpa.py
├── stage2b_locate_pages.py
├── stage3_swap_dump.py
├── stage4_extract_features.py
├── stage5_reconstruct.py
├── master_orchestrate.py
├── capture_campaign.py
├── run_test.py
├── timing_harness.py
├── output/            (81 files, 09-11 to 09-13)
│   ├── dumps/
│   ├── logs/
│   └── results/
└── output_timing/     (121 files, 11-07)
    ├── timing_summary.json
    └── results/
```

| File | Created | Modified | Role |
|---|---|---|---|
| `README.md` | 09-11 | 11-18 | This file: pipeline architecture, usage, file and directory descriptions. |
| `EVAL_README.md` | 10-23 | 10-23 | Run order (Korean) for retraining v10 on real captures and measuring blind SSIM on the test split: train capture → retrain → eval capture → `run_test.py`. The `MNIST_SPLIT` switch is explained here. |
| `common.py` | 09-11 | 09-13 | Shared configuration, SSH connections, path constants, SSIM/PSNR metric computation. |
| `stage1_zero_gpa.py` | 09-11 | 11-07 | [Stage 1] Gets a verified all-zero page GPA from the guest ICMP module and dumps it to `z.out` (`zero_gpa.json`). This zero page is MNIST's "dictionary". |
| `stage2_track_gpa.py` | 09-11 | 11-07 | [Stage 2] Gets the GT GPA and, with `--blind`, runs `write_pattern_tracker` Region-B precursor detection and 2 MB block ranking. Falls back to GT if blind detection misses. Writes `tracked_target_{index}.json`. |
| `stage2b_locate_pages.py` | 10-19 | 10-19 | [Stage 2b] Finds the tensor start page inside a candidate 2 MB block from content. It swap-dumps all 512 pages, XORs them against the zero page, and picks the 49-page window whose background ratio is closest to 80.9% (`score_windows`). Write timing alone cannot place the start: measured offsets were 44–254 pages. |
| `stage3_swap_dump.py` | 09-11 | 09-13 | [Stage 3] Page-swaps Page 1/2 with the zero page and dumps them (`swap_and_dump.py --swap-back`). Writes `swap_meta_{index}.json`. |
| `stage4_extract_features.py` | 09-11 | 11-07 | [Stage 4] XORs dumps against `z.out`, estimates the in-page offset (64 B alignment + center of mass), and extracts the 196-dim sparsity vector (`.out_v5.list`). |
| `stage5_reconstruct.py` | 09-11 | 11-07 | [Stage 5] Reconstructs with v6r (retrieval), v9r (UNet-GAN) and v10 (SparsityEncoder + V10Decoder), computes SSIM/PSNR/L1 against GT, and writes the comparison png. |
| `master_orchestrate.py` | 09-13 | 09-13 | Runs stages 1–5 together or selectively (`--from-stage/--to-stage/--stage`), with batch mode (`--start/--end`). |
| `capture_campaign.py` | 10-23 | 10-23 | Capture campaign for v10 retraining. Each bs=512 blind capture = one 2 MB block = 512 images, saved as `results/sparsities_*_bs512_idx*.npy`. Train (60k → batches 0–116) and eval (test 10k → batches 0–18) go to separate output dirs. Needs the guest. |
| `run_test.py` | 10-23 | 10-23 | Guest-free. Re-runs Stage 5 with the current weights on the saved eval sparsity arrays and reports mean ± std of per-batch SSIM plus pooled per-image SSIM. GT is the MNIST test split. |
| `timing_harness.py` | 11-07 | 11-07 | Per-stage timing study. Runs the blind bs=512 pipeline for N batches and reports wall-clock and self-reported times for dict_build, track_rank, page_dump, ciphermap, recon and per_sample. Output: `output_timing/`. |

### Directories

| Directory | Created | Contents |
|---|---|---|
| `output/dumps/` | 09-11 to 09-13 | `z.out` (zero page dump), `3-30.out` / `3-30_p2.out` (Page 1/2 dumps of sample #30, label 3). |
| `output/logs/` | 09-11 to 09-13 | Write traces from the blind runs: `blind_{0,30}.log` (`CLOCK_REF` / `WRITE gpa ts` lines) and `blind_*_dbg.log`. |
| `output/results/` | 09-11 to 09-13 | Single-sample results: `features_{0,30,1000}.json`, `metrics_{0,30,1000..1003}.json`, `recon_{30,1000..1003}_{v6r,v9r,v10}.{npy,png}`, `swap_meta_*.json`, `tracked_target_*.json`, `zero_gpa.json`, `*.out_v5.list`.<br>bs=512 batch results (images 0–511) from 4 runs: `batch_0`, `20260913_094647`, `20260913_095852`, `20260913_102307`. Each run has `sparsities_*.npy`, `recons_*_{v6r,v9r,v10}.npy`, `metrics_*.json` and `comparison_*.png`.<br>v10 batch SSIM per run: 0.417 / 0.418 / 0.454 / 0.444 (v6r 0.385–0.435, v9r 0.009–0.287). |
| `output_timing/` | 11-07 | Output of `timing_harness.py` (`MNIST_SPLIT=test`, n=20, bs=512).<br>`timing_summary.json` holds the per-stage mean in seconds per batch: dict_build 6.18, track_rank 127.0, page_dump 190.4, ciphermap 0.32, recon 3.22, per_sample 321.0.<br>`results/` holds per-batch `tracked_target_N.json`, `swap_meta_N.json`, `features_N.json`, `metrics_N.json`, `metrics_*_bs512_idx*.json` (20 each), `comparison_*.png` (19) and `zero_gpa.json`. |

---|---|
| `common.py` | Shared configuration, SSH connections, path constants, SSIM/PSNR metric computation |
| `stage1_zero_gpa.py` | [Stage 1] Acquire Zero Page GPA and dump `z.out` |
| `stage2_track_gpa.py` | [Stage 2] Blind tracking with `write_pattern_tracker` and GT acquisition |
| `stage3_swap_dump.py` | [Stage 3] PSP-based swap-dump for Page 1 & Page 2 |
| `stage4_extract_features.py` | [Stage 4] In-page offset estimation and 196-dim Sparsity Vector extraction |
| `stage5_reconstruct.py` | [Stage 5] Multi-model reconstruction (v6r, v9r, v10) and SSIM benchmark table |
| `master_orchestrate.py` | Unified coordinator for Stages 1–5, selective stage execution, and batch processing |

---

## 3. Usage Examples

### (1) Full End-to-End Execution via Master Orchestrator
```bash
# Execute full pipeline for a single sample (Stages 1–5)
sudo python3 master_orchestrate.py --index 30

# Run in blind write-tracker mode
sudo python3 master_orchestrate.py --index 30 --blind

# Run batch mode (Samples 0 to 10)
sudo python3 master_orchestrate.py --start 0 --end 10 --skip-existing
```

### (2) Selective Stage Execution
```bash
# Run Stage 4 (Feature Extraction) to Stage 5 (Reconstruction) only
python3 master_orchestrate.py --from-stage 4 --to-stage 5 --index 1000

# Run Stage 5 (Image Reconstruction & SSIM table) batch standalone
python3 master_orchestrate.py --stage 5 --start 1000 --end 1010
```

### (3) Standalone Module Execution
```bash
# Stage 1 standalone: Acquire Zero Page
sudo python3 stage1_zero_gpa.py --output-dir .

# Stage 2 standalone: Target GPA Tracking
sudo python3 stage2_track_gpa.py --index 30 --blind

# Stage 3 standalone: PSP Swap Dump
sudo python3 stage3_swap_dump.py --index 30

# Stage 4 standalone: Sparsity Extraction (Auto-Offset Estimation)
python3 stage4_extract_features.py --index 30

# Stage 5 standalone: v6r / v9r / v10 Reconstruction & SSIM Comparison
python3 stage5_reconstruct.py --index 30
```

---

## 4. Artifact Specifications

- `zero_gpa.json` & `z.out`: Zero Page GPA and memory dump
- `tracked_target_{index}.json`: Tracked Page 1 / Page 2 GPAs and blind candidate list
- `{label}-{index}.out` & `{label}-{index}_p2.out`: 4KB memory dumps
- `swap_meta_{index}.json`: Swap execution metadata
- `{label}-{index}.out_v5.list` & `features_{index}.json`: 196-dim Sparsity vector and in-page offset details
- `recon_{index}_v6r.png`, `recon_{index}_v9r.png`, `recon_{index}_v10.png`: 28x28 reconstructed images per model
- `comparison_{index}.png`: Visual comparison against Ground Truth across all 3 models
- `metrics_{index}.json`: Quantitative metrics (SSIM, PSNR, L1 Error) per model
