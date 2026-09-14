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

| Filename | Role |
|---|---|
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
