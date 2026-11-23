# 3DShapes end-to-end ciphertext attack

The victim is a 3DShapes shape classifier (ResNet-18, 4 classes: cube / cylinder / sphere / capsule) running inside an AMD SEV-SNP guest.
Its input tensor is `(3,224,224)` float32 (planar R→G→B, 147 pages, 148 with the base offset). The host:

1. reads the tensor pages as ciphertext through SNP page-move,
2. compares them with a chosen-plaintext dictionary (Dict-16 = top-16 4-pixel tuples per channel, 48 refs) to build a cipher map,
3. classifies the shape from the cipher map.

Design notes, experiment log and numbers: [PLAN.md](PLAN.md).

## Final results (2026-11-18, `captures/test_runhit`, test split 400 = 100 per class)

The run uses run\*hit localization, the original LNDS assembly and the v2 classifier.

| Input | Top-1 | Top-2 | Top-3 |
|---|---|---|---|
| RGB, Dict-16 | 83.5% | 90.8% | 93.8% |
| R only | 78.5% | 88.5% | 94.5% |
| G only | 77.8% | 86.0% | 93.2% |
| B only | 69.5% | 80.5% | 91.5% |
| RGB, Dict-8 (offline replay) | 81.0% | 87.5% | 94.2% |
| Plaintext baseline (victim ResNet-18 on the images, no side channel) | 100.0% | 100.0% | 100.0% |

The plaintext baseline is also 100.0% on the full test split (1,000), every shape at 100%. The gap to the attack therefore comes from the side channel (localization, dictionary hits, offset), not from the task.

To reproduce:

```bash
cd offline
python3 dict_k_redecode.py ../captures/test_runhit --k 8
python3 eval_runhit.py ../captures/test_runhit
python3 eval_plaintext.py --capture ../captures/test_runhit
```

- **Leakage:** classifiers are trained only on `split.json` train_pool (sim_train). Checkpoints are selected on 2,000 maps held out of sim_train with fixed damage. Test hue combinations are disjoint from train.
- **Disclosure:** the run\*hit K=8 (number of 2 MB blocks probed) was chosen after looking at test captures.

## File tree

The tree lists every git-tracked file under `case_study/shapes3d/`.

- **Created:** the file's birth time on the filesystem (`stat %w`).
- **Modified:** the last modification time.
- Dates are in 2026.

```
case_study/shapes3d/
├── README.md
├── PLAN.md
├── dict/
│   └── dict_cache_shapes.json
├── logs/
│   ├── train_logs_20261118.tar.gz
│   └── capture_logs_20261118.tar.gz
├── offline/
│   ├── make_split.py
│   ├── split.json
│   ├── select_dict.py
│   ├── dict_keywords.json
│   ├── build_sim.py
│   ├── build_capture_set.py
│   ├── train_attack.py
│   ├── attack_shapes_sim.pth
│   ├── attack_shapes_sim_v2.pth
│   ├── attack_shapes_sim_v2_Ronly.pth
│   ├── attack_shapes_sim_v2_Gonly.pth
│   ├── attack_shapes_sim_v2_Bonly.pth
│   ├── attack_shapes_sim_v2_dict8.pth
│   ├── report.py
│   ├── rescore_cmaps.py
│   ├── redecode.py
│   ├── dict_k_redecode.py
│   ├── eval_runhit.py
│   └── eval_plaintext.py
├── pipeline/
│   ├── README.md
│   ├── common.py
│   ├── swapio.py
│   ├── shapes_map.py
│   ├── boot_guest.sh
│   ├── stall_guard.sh
│   ├── stage1_ref_dict.py
│   ├── stage2_track.py
│   ├── stage3_dump.py
│   ├── stage45_classify.py
│   ├── master_orchestrate.py
│   ├── capture_daemon.py
│   ├── ref_dict.json
│   ├── usenix.fd
│   └── runs/
│       ├── gt_debug/
│       │   ├── summary.csv
│       │   ├── tracked_0.json
│       │   ├── dump_0.json
│       │   └── result_0.json
│       └── blind_debug/
│           ├── summary.csv
│           ├── tracked_1.json  tracked_2.json  tracked_3.json
│           ├── dump_1.json     dump_2.json     dump_3.json
│           └── result_1.json   result_2.json   result_3.json
└── victim/
    ├── train_victim.py
    ├── victim_resnet18.pth
    ├── guest_shapes_loader.py
    ├── guest_shapes_server.py
    └── guest_scratch_holder.py
```

### Top level

| File | Created | Modified | Description |
|---|---|---|---|
| `README.md` | 11-18 | 11-18 | This file. Results summary and per-file description. |
| `PLAN.md` | 11-12 | 11-18 | Design decisions (D1–D7), stage plan, and results and decisions by date (11-12 through 11-18). |

### `dict/`

| File | Created | Modified | Description |
|---|---|---|---|
| `dict_cache_shapes.json` | 11-12 | 11-17 | Dictionary index written by Stage 1 for the most recent guest boot: `fixed_gpa`, plus each ref (`R00`–`B15`) with its GPA, channel, pixels, dump file path and verification flag. It is rewritten on every boot, and the committed copy is from the last boot of 11-17. The ref dumps themselves (`dict_pages_shapes/`) are tied to that boot's VEK and are not in git. |

### `logs/`

| File | Created | Description |
|---|---|---|
| `train_logs_20261118.tar.gz` | 11-18 | Offline training and replay logs. The original `offline/*.log` files are git-ignored, so they are archived here. Contents (original modified date):<br>`build_sim.log` (11-12) — sim_train/sim_test generation, coverage per channel<br>`train_attack_sim.log` (11-12) — v1 classifier training<br>`train_attack_sim_v2.log` (11-14) — v2 training (`--aug v2`), per-epoch sim_test / sim_val_damaged<br>`train_attack_sim_v2_{R,G,B}only.log` (11-18) — single-channel training (`--keep-ch`)<br>`train_attack_sim_v2_dict8.log` (11-18) — Dict-8 training (`--dict-k 8`)<br>`dictk_check.log` (11-18) — `dict_k_redecode.py --check`: the Dict-16 replay matches live on 400/400<br>`dictk8.log` (11-18) — Dict-8 replay, kept blocks and GT overlap per sample |
| `capture_logs_20261118.tar.gz` | 11-18 | Capture daemon logs (originals in `pipeline/*.log`). Contents:<br>`stage1_build.log` (11-12) — first dictionary build<br>`daemon_pilot*.log` (11-12) — pilot captures<br>`daemon_test.log` (11-13) — pieces-localization capture of 400 samples (`captures/test_blind`)<br>`daemon_runhit.log` (11-17) — run\*hit capture of 400 samples (`captures/test_runhit`): per-sample prediction, guest oops events, reboots, dictionary rebuilds |

### `offline/` — dataset split, dictionary choice, classifier training, evaluation (no guest needed)

| File | Created | Modified | Description |
|---|---|---|---|
| `make_split.py` | 11-12 | 11-12 | Splits 3DShapes by (floor, wall, object) hue combination: 20% of the 1,000 combinations are test-only. Writes `split.json`. |
| `split.json` | 11-12 | 11-12 | Split result: seed 0, `test_combos` 200, `train_pool` 384,000 image indices, `capture_train` 600, `test` 1,000 (250 per shape). |
| `select_dict.py` | 11-12 | 11-12 | Ranks 4-pixel tuples per channel by frequency over train_pool images and picks the top-K (`--k 16`). Computes each keyword's ICMP chunk as the exact float32 bytes. |
| `dict_keywords.json` | 11-12 | 11-12 | Dict-16 keywords: per channel, `rank`, `code`, `pixels`, `chunk_hex` × 16 (48 total). Dict-8 is the rank 0–7 prefix of this file. |
| `build_sim.py` | 11-12 | 11-12 | Builds simulated cipher maps from images with victim-identical preprocessing and exact keyword lookup. Output: `datasets/sim_train.npz` (30k, train_pool) and `sim_test.npz` (test 1,000), stored as uint8 idx+1. |
| `build_capture_set.py` | 11-12 | 11-12 | Collects captured `cmap_<i>.npy` into an npz in the same format as the simulated maps (for fine-tuning or evaluation; not used in the final results). |
| `train_attack.py` | 11-14 | 11-18 | ShapeNet training: 4-channel input of R/G/B values + hit mask at 112×112, small ResNet.<br>`--aug v1/v2` — capture-damage augmentation<br>`--keep-ch` — single channel<br>`--dict-k` — Dict-K prefix<br>`--threads`<br>With v2, the checkpoint is selected on 2,000 maps held out of sim_train. |
| `attack_shapes_sim.pth` | 11-12 | 11-12 | v1 classifier (degrade v1). 85.7% on `test_blind` captures. Superseded by v2. |
| `attack_shapes_sim_v2.pth` | 11-14 | 11-14 | **v2 classifier, used for the final results** (RGB, Dict-16, `--aug v2`). sim_val_damaged 97.9%. Default model in `stage45_classify.py`. |
| `attack_shapes_sim_v2_Ronly.pth` | 11-17 | 11-18 | Single-channel R model (`--keep-ch R`). sim_val_damaged 92.8%. |
| `attack_shapes_sim_v2_Gonly.pth` | 11-17 | 11-18 | Single-channel G model. sim_val_damaged 90.1%. |
| `attack_shapes_sim_v2_Bonly.pth` | 11-17 | 11-18 | Single-channel B model. sim_val_damaged 89.5%. |
| `attack_shapes_sim_v2_dict8.pth` | 11-18 | 11-18 | Dict-8 model (`--dict-k 8`). sim_val_damaged 97.9%. |
| `report.py` | 11-12 | 11-12 | Reads a capture directory's `summary.csv` and reports accuracy, confusion, localization and time per stage. |
| `rescore_cmaps.py` | 11-17 | 11-18 | Re-classifies the captured `cmap_<i>.npy` with another checkpoint and prints top-1/2/3. `model.pth:G` keeps only that plane. |
| `redecode.py` | 11-17 | 11-17 | Re-runs assembly and Stage 4/5 offline from saved dumps (`--assembly saved/windowed/weighted`), using each sample's boot dictionary snapshot. |
| `dict_k_redecode.py` | 11-18 | 11-18 | Replays a run\*hit capture with Dict-K (a Dict-16 prefix): block probe recount → LNDS assembly → base offset → cmap. With `--check` it replays Dict-16 and compares with live (400/400 identical). Output goes to `dictk_out/` (git-ignored). |
| `eval_runhit.py` | 11-18 | 11-18 | Produces all final tables in one run: localization (all planes and per plane), top-1/2/3 (RGB, R/G/B-only, Dict-8), and single-channel accuracy by pages found. |
| `eval_plaintext.py` | 11-23 | 11-23 | Plaintext baseline: the victim ResNet-18 (`victim/victim_resnet18.pth`, preprocessing imported from `train_victim.py`) on the raw test images. Top-1/2/3 on the test split (1,000) and on the 400 captured samples, and checks that capture labels match. CPU, ~15 s. |

### `pipeline/` — host-side capture pipeline (needs SNP host and guest)

| File | Created | Modified | Description |
|---|---|---|---|
| `common.py` | 11-12 | 11-12 | Constants and helpers: SSH, dump parsing, Region A/B, 147/148 page layout, keyword loading. 3DShapes version of MURA's `common.py`. |
| `swapio.py` | 11-12 | 11-12 | PSP page-move readout. `swap_pages_tool` swaps a page into FIXED_GPA, and the dump is read through `KVM_READ_PAGE_DUMP`. Shared by Stage 1 and Stage 3. |
| `shapes_map.py` | 11-12 | 11-12 | Cipher maps: `decode_dumps` / `map_from_hits` for real dumps, `simulate` for simulation, `estimate_base_off` for the blind offset, and `to_input` for classifier input. |
| `boot_guest.sh` | 11-12 | 11-12 | Runs `drop_caches` and `compact_memory`, then boots the SNP guest. Without this, 4 KB backing made a boot take 28 min; with it, 2–3 min. Refuses to start if any QEMU is already running, so it never touches another user's VM. |
| `stall_guard.sh` | 11-12 | 11-12 | Kills the child process if the daemon log has not moved for STALL_MIN minutes, so the daemon can recover the guest. |
| `stage1_ref_dict.py` | 11-12 | 11-12 | Stage 1: fills a guest page with each keyword chunk via ICMP and reads its ciphertext under FIXED_GPA, giving 48 ref dumps. Runs once per boot. |
| `stage2_track.py` | 11-16 | 11-16 | Stage 2: runs the victim and traces its writes with `write_pattern_tracker`. Builds burst candidates, physical pieces, and the run\*hit top-8 2 MB blocks (`RUNHIT_LO/HI`, `RUNHIT_TOP_K`). |
| `stage3_dump.py` | 11-17 | 11-17 | Stage 3: localization (`LOCALIZER="runhit"`: 2 probes per block, all hitting blocks kept), dump, and channel assembly `assemble_by_channel` (live uses plain LNDS; `weighted` is offline only). Stores `pre_pages`/`pre_dumps`. |
| `stage45_classify.py` | 11-16 | 11-16 | Stage 4 (dump → cipher map, blind base offset) and Stage 5 (ShapeNet classification, default `attack_shapes_sim_v2.pth`). |
| `master_orchestrate.py` | 11-12 | 11-12 | Runs Stage 2 → 3 → 4/5 per sample and appends rows to `summary.csv`. `--gt` gives a known-address run. |
| `capture_daemon.py` | 11-12 | 11-12 | Unattended capture. Checks guest health and console oops; on failure it stops only our QEMU, reboots, and rebuilds the dictionary before resuming. |
| `ref_dict.json` | 11-12 | 11-17 | Stage 1 metadata for the last boot: `fixed_gpa`, `num_refs`/`usable_refs` 48, build time. Rewritten on every boot. |
| `usenix.fd` | 11-12 | 11-17 | OVMF UEFI variable store of the capture guest (`usenix`). QEMU updates it on every boot. |
| `runs/gt_debug/*` | 11-12 | 11-12 | First known-address (`--gt`) debug run, test #0. `summary.csv` holds the result (cube, 148/148 pages); `tracked_0.json` is Stage 2, `dump_0.json` Stage 3, `result_0.json` Stage 4/5. The page dumps (`.out`) are not in git. |
| `runs/blind_debug/*` | 11-12 | 11-12 | First blind debug run, test #1–3. #1 had 10 candidates and a correct prediction, but 0 GT pages (correct by chance). #2–3 had 0 candidates. Same file layout as above. |

### `victim/` — runs inside the guest

| File | Created | Modified | Description |
|---|---|---|---|
| `train_victim.py` | 11-12 | 11-12 | Victim training: ResNet-18 with fc→4, trained on `shapes3d_victim_train.npz` and evaluated on `shapes3d_test.npz`. Preprocessing is `Resize(224) → ToTensor → Normalize(ImageNet)`. |
| `victim_resnet18.pth` | 11-12 | 11-12 | Victim model weights from `train_victim.py`. Loaded for GPU inference in the CC guest during capture (`--gpu`). |
| `guest_shapes_loader.py` | 11-12 | 11-12 | Victim process: preprocess, `GUEST_READY_FOR_TRACK`, then a tensor copy of 147–148 page writes, plus a ground-truth report. A new process per sample (`SHAPES_SERVER=0`); this is the mode used for the final captures. |
| `guest_shapes_server.py` | 11-12 | 11-12 | Resident-server victim. Rejected because memory fragmentation and leftover data broke localization (see PLAN.md). |
| `guest_scratch_holder.py` | 11-12 | 11-12 | Holds mlocked idle pages so they can serve as FIXED_GPA scratch, which avoids guest panics after page-move. |

## Not in git (local only)

| Path | Reason |
|---|---|
| `captures/` | Raw capture data (page dumps `.out`, write traces, probes; several GB per run). Ignored by `case_study/**/captures/`. Final runs: `test_blind` (pieces, 11-13) and `test_runhit` (run\*hit, 11-17). |
| `datasets/` | `shapes3d_*.npz` and `sim_*.npz` (regenerable from the original h5 with `make_split.py` / `build_sim.py`). Ignored by `*.npz`. |
| `dict/dict_pages_shapes/` | Ref dumps from the last boot. Tied to that boot's VEK, so they cannot be reused. |
| `offline/dictk_out/` | Output of `dict_k_redecode.py` (regenerable). |
| `pipeline/runs/*/dump_*_p*.out` | Page dumps from the debug runs. |
| `pipeline/guest_crashes/` | Guest console logs saved on oops/panic (14 files, 2.6 MB). |
| `offline/recon_grid.png` | Image reconstruction experiment (dropped). |
