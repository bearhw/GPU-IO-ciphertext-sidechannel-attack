# mura3p/pipeline — MURA 3-plane end-to-end capture (host side)

This pipeline applies the 3DShapes pipeline (`case_study/shapes3d/pipeline`) to the MURA victim. Instead of the R plane only, it localizes and dumps all three planes of the `(3,224,224)` tensor (147–148 pages).

- **Dictionary:** MURA's uniform u8 levels, 64 levels × 3 channels = 192 refs (`../offline/dict_keywords.json`).
- **Classifier input:** MURA is grayscale, so the level hits of the three planes are fused with an OR into one `(64,224,56)` map. That map goes into MURA's existing XorSliceSENet.
- **Localization:** pieces mode, i.e. physical runs probed in time order. This pipeline was forked from shapes3d on 11-14, before run\*hit was added.

**Status:** the MURA valid capture (`../captures/valid_blind`) was stopped at 71/3197 on 11-16 13:12, by user decision, to free the host for the 3DShapes run\*hit capture. Of those 71 samples, 31 are correct in `summary.csv`. It has not been resumed. `capture_daemon.py` skips rows already in `summary.csv`, so a rerun resumes from sample 72.

## Files

- **Created:** filesystem birth time (`stat %w`).
- **Modified:** last modification time.
- All dates are 2026.
- Several files are copies of the shapes3d originals with their docstrings unchanged, so they still mention 3DShapes. The table notes which ones.

```
mura3p/pipeline/
├── README.md
├── common.py
├── swapio.py
├── m3_map.py
├── mura_model.py
├── boot_guest.sh
├── stage1_ref_dict.py
├── stage2_track.py
├── stage3_dump.py
├── stage45_classify.py
├── master_orchestrate.py
├── capture_daemon.py
├── valid_order.txt
├── ref_dict.json
├── usenix.fd
└── logs/
    └── daemon_logs_20261119.tar.gz
```

| File | Created | Modified | Description |
|---|---|---|---|
| `common.py` | 11-14 | 11-14 | Constants and helpers: SSH, dump parsing, Region A/B, 147/148-page layout, keyword loading. Derived from shapes3d's `common.py`. The top of the docstring holds the mura3p notes (uniform levels, 3-plane fusion); the rest is the original 3DShapes text. |
| `swapio.py` | 11-14 | 11-14 | PSP page-move readout (`swap_pages_tool` → `KVM_READ_PAGE_DUMP`), shared by Stage 1 and Stage 3. **Identical** to shapes3d's `swapio.py`. |
| `m3_map.py` | 11-14 | 11-14 | Cipher-map code. **Identical** to shapes3d's `shapes_map.py`; only the file name differs, so the docstring says 3DShapes. It works off the keyword table, so with the 192-ref uniform-level dictionary it yields a `(3,224,56)` map of level indices. Imported as `sm` by `stage3_dump.py` and `stage45_classify.py`. |
| `mura_model.py` | 11-14 | 11-14 | XorSliceSENet (MURA's 64-ref attack classifier), copied verbatim from `case_study/mura/pipeline/stage5_reconstruct.py`. It is copied rather than imported to avoid a `common` module name clash. Input is `(B,64,224,56)`, with aspect fixed at 1.0. |
| `boot_guest.sh` | 11-14 | 11-14 | Runs `drop_caches` and `compact_memory`, then boots the SNP guest. Refuses to start if any QEMU is already running. Same as shapes3d's script except the boot log banner (`mura3p boot`). The header comment still says 3DShapes. |
| `stage1_ref_dict.py` | 11-14 | 11-14 | Stage 1: fills a page with each keyword chunk via ICMP and dumps it at FIXED_GPA. **Identical** to shapes3d's script, so the docstring says 3DShapes. Fed `../offline/dict_keywords.json`, it builds 192 refs (11-16 build: 3,734 s). |
| `stage2_track.py` | 11-14 | 11-14 | Stage 2: runs the victim, traces writes, builds candidates, pieces and time segments. Same as shapes3d's script without run\*hit (`runhit_blocks`); usage uses `--split valid`. |
| `stage3_dump.py` | 11-14 | 11-14 | Stage 3: localization by `piece_probe` (pieces mode; `burst_locate` / segments in resident-server mode), `fill_edges`, dump, and `assemble_by_channel`. Has no run\*hit branch. |
| `stage45_classify.py` | 11-14 | 11-14 | Stage 4: compares dumps with the 192 refs, estimates the blind base offset, and builds the `(3,224,56)` level map. It then fuses the three planes into `(64,224,56)` and classifies with XorSliceSENet. Default checkpoint: `case_study/mura/pipeline/mura_attack_64ref_blind_ff.pth`. Also classifies the R-plane-only input, for comparison with the original MURA pipeline. |
| `master_orchestrate.py` | 11-14 | 11-14 | Runs Stage 2 → 3 → 4/5 per sample and appends rows to `summary.csv` (with an extra `fused_coverage` column). `--gt` gives a known-address run. |
| `capture_daemon.py` | 11-14 | 11-14 | Unattended capture. Checks guest health and console oops; on failure it stops only our QEMU, reboots, rebuilds the dictionary and snapshots it next to the captures. Run with `--split valid --indices-file valid_order.txt`. |
| `valid_order.txt` | 11-14 | 11-14 | Capture order for the 3,197 MURA valid images, one index per line, shuffled. How it was generated (script or seed) is not recorded in git; **unverified**. |
| `ref_dict.json` | 11-14 | 11-16 | Stage 1 metadata from the last boot (11-16): `fixed_gpa` 0x146672000, `num_refs`/`usable_refs` 192, `build_sec` 3734. Rewritten on every boot. |
| `usenix.fd` | 11-14 | 11-16 | OVMF UEFI variable store of the capture guest (QEMU pflash unit 1). QEMU updates it on every boot. |
| `logs/daemon_logs_20261119.tar.gz` | 11-19 | 11-19 | Archive of `daemon_valid.log` (git-ignored by `*.log`): the valid capture from 11-14 to 11-16 13:12, with the stop note at the end. |

## Not in git (local only)

| Path | Description |
|---|---|
| `guest_crashes/` | Guest console log saved on oops (1 file). |
| `../captures/valid_blind/` | The 71 captured samples: dumps, traces, `summary.csv`. Ignored by `case_study/**/captures/`. |
| `../dict/dict_pages_m3/` | Ref dumps from the last boot. Tied to that boot's VEK. |
