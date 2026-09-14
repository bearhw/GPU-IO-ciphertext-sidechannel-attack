# MURA End-to-End Modular Attack Pipeline

A 5-stage modular attack pipeline analyzing and reconstructing encrypted memory from MURA (Musculoskeletal Radiographs) vision workloads in an SEV-SNP environment. It stitches 49-page single-channel tensors partitioned across 2MB physical boundaries based on temporal contiguity, and uses 64-Ref ciphertext collision swaps to classify 7 joint types and reconstruct 2D images alongside quantitative evaluation metrics.

---

## 1. Architecture & Pipeline Stages

```
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 1: Reference Dictionary Acquisition (stage1_ref_dict.py)         │
│  - Acquire FIXED_GPA and build/load 64-Ref normalized reference pages  │
│  - Validate dict_cache_mura.json and dict_pages_mura/ref_{X:03d}.out   │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 2: Target 49-Page Tracking & Stitching (stage2_track_gpa.py)     │
│  - Run guest process (MURA holder/infer) and acquire Ground Truth GPA   │
│  - Detect Region-B Precursor bursts via write_pattern_tracker          │
│  - Multi-Block Temporal Stitching: Auto-stitch 2MB split runs to 49p   │
│  - Save metadata to tracked_mura_{index}.json                          │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 3: PSP Collision Swap & Dump (stage3_swap_dump.py)               │
│  - Sequential swap-dump of 49 target pages ↔ FIXED_GPA (--swap-back)   │
│  - Export {class}_{index}_p{00..48}.out dumps & swap_meta_{index}.json │
│  - Auto-handle Partial Mode (valid_pages, frac) on page omission       │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 4: 64-Ref XOR Feature Extraction (stage4_extract_features.py)    │
│  - Compare 49p dump ciphertext ↔ 64 Ref dictionary 16B chunks          │
│  - Generate (64, 224, 56) float32 xor_slice_{index}.npy & .frac sidecar│
│  - Save metadata to features_{index}.json                              │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 5: Classification, 2D Recon & Metrics (stage5_reconstruct.py)    │
│  - XorSliceSENetV3 7-class joint Top-1/Top-3 classification            │
│  - Reconstruct 224x224 2D image via 64-Ref dequantization              │
│  - Compute SSIM, PSNR, L1 Error vs GT and save comparison_{idx}.png    │
│  - Save final metrics to metrics_{index}.json                          │
└────────────────────────────────────────────────────────────────────────┘
```

---

## 2. File Organization

| Filename | Role |
|---|---|
| `common.py` | Shared configuration, SSH connections, path constants, 64-Ref definitions, SSIM/PSNR metrics |
| `stage1_ref_dict.py` | [Stage 1] Acquire FIXED_GPA & validate/build 64-Ref dictionary (`dict_pages_mura/`) |
| `stage2_track_gpa.py` | [Stage 2] Real-time tracking with `write_pattern_tracker` & 49p Multi-Block Stitching |
| `stage3_swap_dump.py` | [Stage 3] Sequential PSP swap-dump for 49 target pages ↔ FIXED_GPA |
| `stage4_extract_features.py` | [Stage 4] Extract `(64, 224, 56)` XOR slices against 64-Ref dictionary |
| `stage5_reconstruct.py` | [Stage 5] `XorSliceSENetV3` body-part classification, 2D reconstruction & metric reporting |
| `master_orchestrate.py` | Unified coordinator for Stages 1–5, selective stage execution, and batch processing |

---

## 3. Usage Examples

### (1) Full End-to-End Execution via Master Orchestrator
```bash
# Execute full pipeline for a single sample (Stages 1–5)
sudo python3 master_orchestrate.py --index 0 --blind

# Test using offline host log
python3 master_orchestrate.py --index 0 --host-log ../dict/mura_xor_host.log --from-stage 2 --to-stage 5

# Quick pipeline integrity verification with Mock mode (no PSP swaps)
python3 master_orchestrate.py --index 0 --mock
```

### (2) Selective Stage Execution
```bash
# Run Stage 4 (Feature Extraction) to Stage 5 (Reconstruction) only
python3 master_orchestrate.py --from-stage 4 --to-stage 5 --index 0

# Run Stage 5 (Classification & Metrics) standalone
python3 stage5_reconstruct.py --index 0
```

### (3) Standalone Module Execution
```bash
# Stage 1: Validate Ref Dictionary & FIXED_GPA
sudo python3 stage1_ref_dict.py

# Stage 2: Target 49-Page Tracking & Stitching
python3 stage2_track_gpa.py --index 0 --blind

# Stage 3: PSP Collision Swap & Dump
sudo python3 stage3_swap_dump.py --index 0

# Stage 4: 64-Ref XOR Feature Extraction
python3 stage4_extract_features.py --index 0

# Stage 5: XorSliceSENetV3 Classification & Metric Reporting
python3 stage5_reconstruct.py --index 0
```

---

## 4. Artifact Specifications

- `ref_dict.json`: Metadata for FIXED_GPA and 64-Ref dictionary
- `tracked_mura_{index}.json`: Tracked 49-page GPA list and Multi-Block Stitching details
- `{class}_{index}_p{00..48}.out`: 4KB memory dump files for each of the 49 pages
- `swap_meta_{index}.json`: Swap execution statistics and capture fraction ($K/49$)
- `xor_slice_{index}.npy` & `.frac`: `(64, 224, 56)` XOR feature tensor and top-aligned valid ratio
- `features_{index}.json`: Feature extraction metadata and active match density
- `recon_{index}.png` & `recon_{index}.npy`: Reconstructed $224 \times 224$ 2D grayscale image
- `comparison_{index}.png`: 4-panel visualization (Ground Truth / Reconstructed Image / XOR Matching Heatmap / Class Probability)
- `metrics_{index}.json`: Quantitative metrics (SSIM, PSNR in dB, L1 Error) and Top-3 classification results
