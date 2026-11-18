# 3DShapes dictionary attack — end-to-end case study plan

Goal: recover 3DShapes inputs from SEV-SNP ciphertext using a dictionary attack, scored as classification (the MURA approach), and run it end-to-end with **blind** localization.
Use in the paper: evidence for color-image generality (D Q15), plus a third blind end-to-end workload (C Q2).

---

## 0. Current state (2026-11-12)

- **Dataset:** `/home/eun/datasets_ext/3dshapes/3dshapes.h5`. Contains 480,000 images of 64×64×3 uint8. Each image has 6 factors:
  - floor_hue: 10 values
  - wall_hue: 10
  - object_hue: 10
  - scale: 8
  - **shape: 4**
  - orientation: 15
- **Offline coverage already measured:** `case_study/color_simple/coverage_3dshapes.json`.
  - Setup: resize to 224, ImageNet normalize, top-K 4-pixel tuples per channel.
  - Result: coverage (%) for R / G / B

    | K | R | G | B |
    |---|---|---|---|
    | 1 | 23.7 | 23.9 | 7.7 |
    | 16 | 48.0 | 71.4 | 45.1 |
    | 64 | 52.5 | 75.0 | 49.1 |
    | 1024 | 72.3 | 84.2 | 66.4 |

  - Gains are large up to K=16 and small beyond, so a small dictionary is enough.
- **MURA pieces that can be reused as-is:**
  - stage2: 49-page tracking and stitching
  - stage3: probe localization and page-move dump
  - `capture_daemon.py`: guest boot management, dictionary rebuild on boot-id change
  - `stall_guard.sh`: guest oops guard
- **Arbitrary-tuple injection is already supported:** `stage1_ref_dict.acquire_gpa(chunk_bytes=...)` can inject any 16 B chunk, not only uniform levels.

## 1. Design decisions (recommended choice first)

| # | Decision | Recommendation | Reason / alternative |
|---|---|---|---|
| D1 | Victim preprocessing | `Resize(224, bilinear) → ToTensor → ImageNet Normalize`, giving (3,224,224) float32 = **147 pages, 49 per plane** | Identical to MURA, so stage2/3 can be reused directly. Native 64×64 (4 pages per plane) is a separate offline ablation |
| D2 | Classification target | **shape** as primary (4 classes, chance 25%). **object/floor/wall hue** as secondary (10 classes each) | A dictionary hit gives back the exact pixel value, so hue is close to a direct readout. That makes a strong demo of color leakage. Scale and orientation are optional |
| D3 | Dictionary | **Top-K 4-pixel tuples per channel from the train split**, K=16 per channel = 48 refs | Unlike MURA (uniform levels, R only), this is per-channel tuples. Estimated about 15 min per boot (MURA builds 64 refs in 20.6 min). K=32 only if needed |
| D4 | Planes read | Phase A: **one plane** (reuse MURA directly). Phase B: **all 3 planes** (full color) | With dictionaries for all 3 channels, whichever plane is captured can be decoded |
| D5 | Cipher-map representation | Per block, the matched tuple or a miss. Decode into a **partial RGB image plus a hit mask**, shape (4,224,224) | Independent of dictionary size. Easier for the classifier to learn than MURA's K-channel XOR slice |
| D6 | Split | **Hold out (floor,wall,object) hue combinations**: 80% of combos for train, 20% for test | A random split puts near-duplicates (same combo, different orientation) on both sides. Holding out combos gives a stronger generalization claim |
| D7 | Victim workload | ResNet-18 shape classifier. The guest loader has two modes: (a) hold-only, (b) **real GPU inference with CC on** | (b) answers A Q5 (did it go through the GPU path?). The VLM and MURA e2e runs lack this |

## 2. Folder layout

```
case_study/shapes3d/
  PLAN.md
  offline/                 # no guest needed
    make_split.py          # D6 combo-held-out split -> split.json
    select_dict.py         # top-K tuples per channel (train) -> dict_keywords.json + coverage curve
    sim_ciphermap.py       # victim-identical preprocessing -> exact cipher map simulation (+ degradation)
    train_attack_sim.py    # attack classifier trained on simulated maps (upper bound)
  victim/
    train_victim.py        # ResNet-18 shape baseline (plaintext upper bound)
    guest_shapes_loader.py # runs inside the guest: index -> preprocess -> [GPU forward] -> HOLDING
  dict/
    dict_pages_shapes/     # ref_{ch}_{k}.out
    dict_cache_shapes.json
  pipeline/                # copied from mura/pipeline and adapted
    common.py  stage1_ref_dict.py  stage2_track_gpa.py  stage3_swap_dump.py
    stage4_ciphermap.py  stage5_classify.py  master_orchestrate.py
    capture_daemon.py  stall_guard.sh  build_attack_dataset.py  finetune_attack_model.py
  captures/{train,test}/   datasets/
```

## 3. Stage design

| Stage | What it does | Changes from MURA |
|---|---|---|
| S1 Dictionary | Fill a page with each of the K×3 tuples via ICMP at FIXED_GPA, then dump. 48 refs | Uniform level → arbitrary tuple via `chunk_bytes`. Channel-specific normalize. Payload bytes must be **byte-exact** with the victim's float32 output |
| S2 Write tracking | Trap victim writes, rank 2 MB regions, stitch the 49-page run | Reuse as-is. Check whether the Region A/B constants still hold for this guest/workload |
| S3 Localization + dump | Probe each candidate with 8 pages, then dump the chosen 49 pages (Phase B: 147) | Probe scoring uses the new dictionary. Phase B adds plane-to-plane stitching |
| S4 Cipher map | Compare every block with the 48 refs, then build partial RGB + mask | Replaces MURA's XOR slice (D5) |
| S5 Classification | Predict shape and hue with the attack classifier | Multi-head |

## 4. Attack classifier training

1. **Simulation pretraining.** Run victim-identical preprocessing on the train-split images and do exact dictionary matching. This gives clean cipher maps without capture noise, for about 50k images, all offline.
2. **Degradation augmentation.** Simulate partial pages, page shifts, and top-align, using the capture distributions measured on MURA (`blind_shift_dist.json`, capture fraction).
3. **Fine-tuning on captures.** Use a small set of real captures on the train split (about 400).
4. **Evaluation.** Use blind end-to-end captures on the test split, balanced by class (shape: 4 × 200 = 800).

Report each tier in the same format as MURA:

| Tier | Meaning |
|---|---|
| Plaintext ResNet-18 | Upper bound |
| Simulated cipher map | Dictionary ceiling |
| GT-localized capture | Known address |
| Blind e2e | Final result |
| Random | 25% / 10% |

## 5. Milestones

| M | Content | Guest needed? | Exit criterion |
|---|---|---|---|
| M0 | Offline feasibility: split, dictionary choice, simulated-classifier accuracy. 224 vs 64 ablation | No | If simulated shape accuracy is ≥90%, go to M1. Otherwise revisit D2/D3 |
| M1 | Victim: train the ResNet-18 baseline; write the guest loader (both modes); copy the dataset to the guest | Copy only | Loader reaches HOLDING, reports GT GPA, real GPU forward succeeds with CC on |
| M2 | Build the dictionary (S1). Verify on 20 known-GPA samples that captured and simulated cipher maps agree | Yes | Block match rate ≥99% (otherwise fix float byte-exactness) |
| M3 | GT-localized capture, about 200 samples | Yes | Get the GT-localized accuracy |
| M4 | Blind e2e capture through the daemon: test 800 plus fine-tuning captures | Yes | Get blind e2e accuracy, top-k, and per-stage time |
| M5 | (Optional) Phase B with 3 planes; tracker on/off victim slowdown | Yes | Full-color reconstruction figure |

**Time estimate.** MURA takes 167 s per 49-page sample. Single-plane 3DShapes is about the same. With 3 planes, the dump roughly triples, to about 300 s per sample.

| Item | Estimate |
|---|---|
| Test set, 800 samples, 1 plane | about 37 h |
| Test set, 800 samples, 3 planes | about 67 h |
| Fine-tuning captures, 400 samples | 19–33 h |
| Dictionary | about 15 min per boot |

The host's guest can only be used by one capture at a time, so this has to be serialized with the MURA and LLM captures.

## 6. Risks

- **Float byte mismatch.** If the guest's and host's torch or PIL versions differ, bilinear resize and normalize can produce slightly different float32 values, and dictionary entries will never match. Dictionary keywords must be generated **with the guest's own preprocessing code**. M2 verifies this.
- **Tuples are not uniform levels.** Make sure the MURA ref-duplicate check (`_acquire_ref_verified`) works correctly for non-uniform chunks.
- **Plane stitching.** Of MURA's channels, only 29% are physically contiguous. Phase B needs to stitch 3 planes, so its success rate is the uncertain part.
- **"Too easy" criticism.** 3DShapes is synthetic, with uniform colors. Present it as a demonstration of color generality, and back it up with the offline coverage for Fruits-360 and MedMNIST (color_simple).
- **Host stability.** The guest oops issue and the kvm module refcount leak are unresolved, so stall_guard is required.

## 7. Decisions (user, 2026-11-12)

- Target: **shape only** (4 classes). Hue dropped.
- **3 planes** (147 pages) from the start. Phase A/B split removed.
- Guest: free to use (MURA daemon stopped 11-07 16:20, no QEMU running).

## 7b. Former open decisions

1. Is shape-only enough as the target, or include hue? (Recommendation: shape plus object hue.)
2. Phase B (3 planes) needed? (Recommendation: start with 1 plane; decide on Phase B after the M4 results.)
3. Test-set size / time budget. When can the guest be used, given the order of MURA and LLM captures?

## 8. Status (2026-11-12 23:20)

- Pipeline working end to end. Pilot of 10 blind samples (all 4 shapes): top-1 10/10. Tensor pages recovered: median 139/148. Victim ran ResNet-18 on the CC GPU (10/10 correct).
- Captured cipher maps match the simulation block for block, so the attack classifier is trained on simulated maps (`offline/attack_shapes_sim.pth`).
- Main run: `captures/test_blind`, 400 samples (100 per shape), started 23:17. Daemon log: `pipeline/daemon_test.log`. Results: `python3 offline/report.py captures/test_blind`.
- Victim runs as a fresh process per sample (loader). Resident-server mode failed localization:
  - fragmented memory, so the tensor's pages are physically scattered;
  - stale image data from earlier requests, so probes hit non-tensor pages.
- Stability:
  - FIXED_GPA is a guest-pinned scratch page.
  - The guest still panics about once per 10 samples. capture_daemon recovers automatically (reboot plus a 15-minute dictionary rebuild).

## 2026-11-14 결과 (본 캡처 399/400, blind, --gpu)
- v1 분류기(attack_shapes_sim.pth, 손상 aug 약함): top-1 85.7% (342/399), 위치 찾은 382개 기준 88.7%.
- v2 분류기(attack_shapes_sim_v2.pth, `train_attack.py --aug v2`): sim_train 28k로만 학습, 선택은 sim_train held-out 2k(고정 손상) 97.9%.
  같은 cmap 재채점(offline/rescore_cmaps.py) top-1 95.7% (382/399), 위치 찾은 382개 기준 99.0%.
  per shape cube 94.0 / cylinder 97.0 / sphere 94.9 / capsule 97.0.
- 남은 오류는 대부분 localization 실패 17개(GT 페이지 0). window 조립(stage3 ASSEMBLE_WINDOWED, 기본 off)은 미검증.
- #500 미캡처(첫 샘플 guest crash).

## 11-18 run*hit 400 최종 + 단일 채널 ablation (기존 LNDS 조립, Dict-16)
- 캡처: captures/test_runhit, test split 400 (shape당 100). run*hit K=8은 test 캡처 보고 정함(공개 필요).
- RGB v2: top-1/2/3 83.5/90.8/93.8, GT>=1 남은 샘플만 94.9 (n=331), per-shape 89/88/80/77
- 단일 채널 (train_attack.py --keep-ch, sim_train only, sim_val_damaged로 선택):
  | plane | sim_test | val_dmg | cap top-1/2/3 | plane-localised-only |
  | R | 98.9 | 92.8 | 78.5/88.5/94.5 | 90.5 (n=326) |
  | G | 98.8 | 90.1 | 77.8/86.0/93.2 | 89.3 (n=327) |
  | B | 98.5 | 89.5 | 69.5/80.5/91.5 | 82.6 (n=305) |
- localization (148p): dump >=1/74/109/136/148 = 97.8/81.8/64.2/47.8/35.8, 조립 후 82.8/70.5/55.0/36.5/3.0
- 텐서 양 끝 페이지(0-9, 140-147) recall 낮음 → R/B plane 완전 복원률 낮음, G는 가운데라 유리
- Dict-8 (11-18): Dict-16 prefix로 저장 캡처 재생(offline/dict_k_redecode.py, Dict-16 재생 400/400 라이브와 동일), 모델 attack_shapes_sim_v2_dict8.pth (train_attack.py --dict-k 8)
  top-1/2/3 81.0/87.5/94.2 (Dict-16 83.5/90.8/93.8), localised-only 93.6 (n=328). 148p >=1/74/109/136/148 = 82.0/64.2/51.0/32.0/3.0
  Dict-8 map + Dict-16 localization: 82.8/88.8/94.8 → 손실 대부분 localization(block 탈락 62/400, 2번째 probe 미존재로 보수적)
