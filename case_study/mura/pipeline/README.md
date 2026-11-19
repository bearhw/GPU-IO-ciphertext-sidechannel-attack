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

- **Created:** filesystem birth time (`stat %w`).
- **Modified:** last modification time.
- All dates are 2026.
- This section was rewritten on 11-18/19, after checking every git-tracked file in this directory: 298,616 files, of which 5,353 are at the top level, plus 53 subdirectories. Per-sample files are grouped by pattern; everything else is listed file by file.

### 2.1 Code and scripts

| File | Created | Modified | Role |
|---|---|---|---|
| `README.md` | 09-11 | 11-19 | This file. |
| `common.py` | 10-19 | 10-19 | Shared constants, paths, SSH, the 64-ref dictionary definition (ref-16/32/64), metrics. |
| `stage1_ref_dict.py` | 09-22 | 10-20 | [Stage 1] Gets and verifies FIXED_GPA, injects the 64 normalized MURA pixel levels via ICMP and dumps the reference pages. Writes `ref_dict.json`. |
| `stage2_track_gpa.py` | 11-02 | 11-02 | [Stage 2] Detects Region-B precursor bursts in the `write_pattern_tracker` write stream, then stitches the 49-page single-channel tensor across 2 MB boundaries by time. Writes `tracked_mura_{i}.json`. |
| `stage3_swap_dump.py` | 09-22 | 10-20 | [Stage 3] Swap-dumps the 49 pages one by one at FIXED_GPA. Diagnostics:<br>`probe_{i}/` — candidate probes, stopping at the first empty page<br>`slide_{i}/` — extends the window backwards<br>`ab_{i}/` — dumps both the selected and the GT page sets for comparison<br>Writes `swap_meta_{i}.json`. |
| `stage4_extract_features.py` | 09-23 | 09-23 | [Stage 4] Compares the 49 dumped pages with the 64 refs to build the `(64,224,56)` XOR slice (top-aligned option). |
| `stage5_reconstruct.py` | 10-19 | 10-19 | [Stage 5] XorSliceSENetV3 body-part classification (top-1/top-3) and a captured-pages summary. Writes `metrics_{i}.json`. |
| `master_orchestrate.py` | 09-22 | 10-19 | Runs stages 1–5 together or selectively, with batch mode. Appends to `pipeline_summary.csv`. |
| `capture_daemon.py` | 10-22 | 10-22 | Runs captures that take days. Checks guest health before each chunk and recovers from reboots, dead dictionaries, stuck loaders and vfio loss. Snapshots each boot's dictionary into `dict_snapshots/<boot_id>/`. |
| `blind_capture_watchdog.sh` | 10-22 | 10-22 | Restarts `capture_daemon.py` itself if it dies (exception, OOM, hang-up), for the blind valid capture. |
| `stall_guard.sh` | 11-05 | 11-05 | Kills the stuck child when the daemon log has not moved for STALL_MIN minutes, so the daemon can recover. The 11-03 incident (blocked 16:48 → 23:05) is why it exists. |
| `stop_capture.sh` | 10-20 | 10-20 | Stops the blind capture without leaving orphans: watchdog → daemon signal → children reaped. |
| `build_attack_dataset.py` | 10-21 | 10-21 | Turns capture dumps into model-input XOR slice maps (`datasets/{split}_{N}ref_*`). Options: `--blind-only`, `--tag`. |
| `finetune_attack_model.py` | 10-27 | 10-27 | Fine-tunes the v2 XorSliceSENet (trained on 36,808 clean maps) on attack-captured maps. Prints the zero-shot accuracy first. Options: `--shift-dist` (blind page-shift distribution), `--foreign-fill`, `--balance`, `--holdout-split`. |
| `run_blind_finetune.sh` | 10-21 | 10-21 | Fine-tunes Dict-16/32/64 for the blind attack: block-given train captures plus the blind shift distribution, evaluated on `valid_blind`. Output: `mura_attack_{N}ref_blind_ft.pth`. |
| `blind_ft_watchdog.sh` | 10-21 | 10-21 | Waits for the blind capture to finish, then keeps `run_blind_finetune.sh` running until all three models are done (flock, single instance). Written because the 10-19 run died in a host reboot. |
| `run_ft.slurm` | 10-23 | 10-23 | SLURM job (ARC cluster, A100) for blind_ft. `--account` is still a placeholder (`YOUR_ALLOC`). |
| `run_ft_ff.slurm` | 10-27 | 10-27 | SLURM job for blind_ff: blind shift plus foreign fill 0.9, `--holdout-split --every 10`, 30 epochs. Output: `mura_attack_{N}ref_blind_ff.pth`. |
| `verify_dict.py` | 09-22 | 09-22 | Validates the 64-ref dictionary: distinctness, detection on existing captures, and a stronger check. |
| `verify_stitching.py` | 09-13 | 09-13 | Compares Stage 2's stitched 49 pages with the GT pages from the guest log. |
| `summarize_recovery.py` | 09-23 | 09-24 | Page-recovery statistics from `pipeline_summary.csv`. Rows without GT count as failures. |
| `bone_dictionary.ipynb` | 10-07 | 10-07 | Dictionary analysis notebook (17 MB, outputs included). |
| `mura_attack_viz.ipynb` | 10-28 | 11-07 | Attack-result visualization notebook. Produces the figures in `figures/`. |

### 2.2 Checkpoints and training records

| File | Created | Modified | Contents |
|---|---|---|---|
| `mura_attack_{16,32,64}ref_ft.pth` | 10-05/06 | same | Fine-tuned on block-given captures (20 MB / 20 MB / 41 MB). |
| `mura_attack_{16,32,64}ref_blind_ft.pth` | 10-27 | 10-27 | Blind fine-tune (shift distribution). Added to git on 11-19. Best val_top1: 59.8 / 70.9 / 82.0% (zero-shot 30.0 / 32.8 / 40.9%). |
| `mura_attack_{16,32,64}ref_blind_ff.pth` | 10-28 | 10-28 | Blind shift plus foreign fill. Added to git on 11-19. Best val_top1: 60.0 / 70.4 / 83.1%. `mura3p` uses `64ref_blind_ff` as its default classifier. |
| `mura_attack_{N}ref_blind_ft_history.json` / `_curve.png` | 10-27 | 10-27 | Per-epoch train/val records and curve for blind_ft. |
| `mura_attack_{N}ref_blind_ff_history.json` / `_curve.png` | 10-28 | 10-28 | Per-epoch records and curve for blind_ff. |
| `mura_attack_{N}ref_blind_ft.done` | 10-22 | 10-22 | Completion markers written by `blind_ft_watchdog.sh` (0 B). |
| `finetune_run1.err`, `finetune_16ref.err`, `finetune_32ref.err` | 10-05/06 | same | stderr from the block-given fine-tune runs. |
| `logs/train_logs_20261119.tar.gz` | 11-19 | 11-19 | Archive of the git-ignored training logs: `finetune_*.log`, `finetune_blind_*.log`, `build_{tr,va}{16,32}.log`, `blind_ft_runner.log`, `blind_ft_watchdog.log`, `blind_watchdog_detached.log`. |

### 2.3 Data and results at the top level

| File | Created | Modified | Contents |
|---|---|---|---|
| `ref_dict.json` | 09-11 | 11-07 | Stage 1 metadata from the last boot (FIXED_GPA, refs). |
| `pipeline_summary.csv` | 09-24 | 09-27 | Summary of runs in the default dir (24 rows). |
| `pipeline_summary.valid3197.csv` | 09-23 | 09-24 | Stage 2/3 summary over all 3,197 valid images (09-23 run). |
| `tracked_mura_{0..3196}.json` | 09-23 | 09-23 to 09-27 | Stage 2 output for each of those 3,197 valid images. |
| `{WRIST,SHOULDER,ELBOW}_{i}_p{00..48}.out` | 09-11 to 09-27 | same | Page dumps from the early runs in the default dir: 41 (label, index) combinations over indices 0–25 (WRIST 26, SHOULDER 14, ELBOW 1; runs from different splits reused the same index numbers), 2,007 files. 40 combinations have all 49 pages and 1 has 47. |
| `features_{0..25}.json`, `metrics_{0..24}.json`, `xor_slice_{0..25}.npy.frac`, `xor_slice_0.npy` | 09-11 to 09-22 | same | Stage 4/5 results for those early samples. The other `xor_slice_*.npy` files are git-ignored (`*.npy`). |
| `swap_meta_{0..12}.json` | 09-23/24 | 09-27 | Stage 3 metadata. |
| `blind_mura_{0,1}.log`, `blind_mura_{0,1}_dbg.log` | 09-13 | 09-27 | Write traces from the first blind runs (committed with force-add). |
| `.index_classes_train.json`, `.index_classes_valid.json` | 09-29 / 10-04 | same | index → body-part label maps (valid has 3,197 entries). |
| `.host_boot_id` | 09-28 | 11-04 | Host boot id used by the daemon to detect reboots. |
| `.capture_daemon.lock`, `.watchdog.lock`, `.blind_ft_watchdog.lock` | 10-21 to 11-04 | to 11-06 | flock files (contents are meaningless). |
| `usenix.fd` | 09-24 | 11-07 | OVMF UEFI variable store of the capture guest. |

### 2.4 Directories

| Directory | Files | Date | Contents |
|---|---|---|---|
| `captures/train/` | 221,959 | 09-27 to 10-04 | Block-given train-split capture, used as fine-tune training data. `pipeline_summary.csv` has 4,782 rows (4,326 unique indices; GT ≥1 page in 4,574/4,749, all 49 in 1,948). Also holds `{BODY}_{i}_p{NN}.out` dumps, `swap_meta_{i}.json`, `probe_{i}/` (19 directories) and `ref_dict.json`. |
| `captures/valid/` | 66,417 | 10-04 to 11-07 | Valid-split capture: block-given first, then blind (rows with `probe_choice`). `pipeline_summary.csv` has 3,766 rows (2,113 unique indices). Git holds only part of the dumps: `tracked_mura`/`swap_meta` for 1,314 samples. The local copy is 9.9 GB. |
| `dict_snapshots/<boot_id>/` | 3,238 | 09-27 to 11-07 | Dictionary snapshots per guest boot: 166 boots of `ref_dict.json`, 48 of which also hold the `ref_NNN.out` ref dumps (3,072 files). Needed to re-decode dumps from that boot. |
| `datasets/` | 6 (git) | 09-27 to 10-07 | `train/valid_{16,32,64}ref_index.json`: sample indices for `build_attack_dataset.py`. On 11-19 `blind_shift_dist.json` (blind page-shift distribution, used for fine-tuning) and `valid_blind_{16,32,64}ref_index.json` were added. The `*_slices.npy`/`*_labels.npy` arrays are git-ignored. |
| `figures/` | 9 | 10-07 to 11-07 | Paper figures: `mura_attack_cm_3panel.{pdf,png}` and `mura_attack_topk.{pdf,png}`. `old_n917/` holds the earlier version (n=917) with its notebook. |
| `fixtures/` | 1 | 09-22 | `idx6.png`, a test fixture image. |
| `probe_{0..19,21}/` | 25–80 each | 09-22 to 09-27 | Stage 3 candidate probe dumps from the early default-dir runs (`c{NN}_p{k}.out`). |
| `slide_{0..19,21}/` | 9–12 each | 09-22 | Stage 3 window-slide diagnostic dumps (`c{NN}.out`). |
| `ab_{3..8}/` | 16 each | 09-22 | Stage 3 A/B diagnostics: `selected_p{0..7}.out` vs `gt_p{0..7}.out`. |

### 2.5 Not in git (local only)

| Path | Description |
|---|---|
| `blind_mura_{i}.log`, `_dbg.log` (3,195 each, 421 MB) | Per-sample write traces from the blind capture. |
| `daemon_{train,valid,blind}.log` (121 / 35 / 117 MB) | Capture daemon logs. Not archived because of their size. |
| `run_{block,full,probe500,track}.log`, `pipeline.log`, `stall_guard.log` | Early run, pipeline and stall_guard logs. |
| `xor_slice_{i}.npy` (25) | Stage 4 outputs (`*.npy`). |
| `datasets/*_slices.npy`, `*_labels.npy`, `datasets/old_valid_blind_n917/` | Built datasets (regenerable with `build_attack_dataset.py`). |
| `captures/blind_test`, `captures/valid_blockgiven_bak`, `captures/valid_quarantine_wide_20261101` | Test captures, a backup of the block-given valid capture, and samples quarantined on 11-01. |
| `guest_crashes/` | Guest console logs saved on oops. |

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
