# shapes3d/pipeline — 3DShapes end-to-end capture (host side)

This is the host pipeline for the SEV-SNP guest's 3DShapes victim. Per sample it runs:

- **Stage 1** (once per boot): dictionary.
- **Stage 2:** write tracking.
- **Stage 3:** localization and dump.
- **Stage 4/5:** cipher map and classification.

The final run is the 400-sample test capture from 11-17 (`../captures/test_runhit`), using run\*hit localization, plain LNDS assembly and the v2 classifier. Results and the overall layout are in [../README.md](../README.md) and [../PLAN.md](../PLAN.md).

## Files

- **Created:** filesystem birth time (`stat %w`).
- **Modified:** last modification time.
- All dates are 2026.

```
shapes3d/pipeline/
├── README.md
├── common.py
├── swapio.py
├── shapes_map.py
├── boot_guest.sh
├── stall_guard.sh
├── stage1_ref_dict.py
├── stage2_track.py
├── stage3_dump.py
├── stage45_classify.py
├── master_orchestrate.py
├── capture_daemon.py
├── ref_dict.json
├── usenix.fd
└── runs/
    ├── gt_debug/
    │   ├── summary.csv
    │   ├── tracked_0.json
    │   ├── dump_0.json
    │   └── result_0.json
    └── blind_debug/
        ├── summary.csv
        ├── tracked_1.json  tracked_2.json  tracked_3.json
        ├── dump_1.json     dump_2.json     dump_3.json
        └── result_1.json   result_2.json   result_3.json
```

| File | Created | Modified | Description |
|---|---|---|---|
| `common.py` | 11-12 | 11-12 | Constants and helpers: SSH, MTU, dump parsing, Region A/B (`BLIND_A/B_LO/HI`), page layout (`IMG_PAGES` etc.), keyword loading (`load_keywords`), `DICT_DIR`. 3DShapes version of MURA's `common.py`. |
| `swapio.py` | 11-12 | 11-12 | PSP page-move readout. `swap_pages_tool` swaps a page into FIXED_GPA and back; the ciphertext is read through `KVM_READ_PAGE_DUMP`. `pace()` controls the swap rate (`SHAPES_SWAP_PACE`, burst env vars). |
| `shapes_map.py` | 11-12 | 11-12 | Cipher maps: `keyword_tables`, `simulate` (simulated from an image), `page_hits` / `dump_hits` / `decode_dumps` (real dumps), `estimate_base_off` (blind offset), `map_from_hits`, and `to_input` (classifier input). |
| `boot_guest.sh` | 11-12 | 11-12 | Runs `drop_caches` and `compact_memory`, then boots the SNP guest through `launch-qemu-noncc.sh`. With 4 KB backing a boot took 28 min; this cuts it to 2–3 min. Refuses to start if any QEMU is already running. |
| `stall_guard.sh` | 11-12 | 11-12 | Kills the stuck child process when the daemon log has not moved for STALL_MIN minutes, so the daemon can recover the guest. |
| `stage1_ref_dict.py` | 11-12 | 11-12 | Stage 1: for each of the 48 keywords in `../offline/dict_keywords.json`, injects an ICMP payload, finds a page filled with it, and dumps it at FIXED_GPA (`../dict/dict_pages_shapes/ref_*.out`). Runs once per boot, ~15 min. |
| `stage2_track.py` | 11-16 | 11-16 | Stage 2: handshake with the guest loader (`GUEST_READY_FOR_TRACK`), then traces writes with `write_pattern_tracker`. Builds burst candidates, physical pieces, time segments and the run\*hit blocks (`runhit_blocks`: trace slice 0–0.04, 2 MB blocks, score max_run × pages, top-8). Records `gt_block_overlap`. |
| `stage3_dump.py` | 11-17 | 11-17 | Stage 3: localization. With `LOCALIZER="runhit"`, `block_probe` reads 2 pages per block and keeps every block with ≥ `PIECE_MIN_HITS` hits. Also has `piece_probe`, `burst_locate` and `probe`. Then dumps page by page and assembles with `assemble_by_channel` (live: plain LNDS, `ASSEMBLE_WINDOWED=False`; the G/B-weighted option exists but is not used live). Stores `pre_pages`/`pre_dumps`. |
| `stage45_classify.py` | 11-16 | 11-16 | Stage 4: compares dumps with the 48 refs, estimates the base offset and builds the `(3,224,56)` map, saved as `cmap_<i>.npy`. Stage 5: classifies with ShapeNet (default `../offline/attack_shapes_sim_v2.pth`) and records top-3. |
| `master_orchestrate.py` | 11-12 | 11-12 | Runs Stage 2 → 3 → 4/5 per sample and appends rows to `<output-dir>/summary.csv`, skipping rows that already exist. `--gt` gives a known-address run; `--gpu` gives real GPU inference in the CC guest. |
| `capture_daemon.py` | 11-12 | 11-12 | Unattended capture. Detects ssh failure and console oops/panic, stops only our QEMU, reboots (`boot_guest.sh`), and brings back the network, GPU CC, scratch holder and a fresh dictionary before continuing. Snapshots each boot's dictionary into the capture dir (`dict_MMDD_HHMM_*`). |
| `ref_dict.json` | 11-12 | 11-17 | Stage 1 metadata from the last boot: `fixed_gpa`, `num_refs`/`usable_refs` 48, `build_sec`. Rewritten on every boot. |
| `usenix.fd` | 11-12 | 11-17 | OVMF UEFI variable store of the capture guest (`usenix`), QEMU pflash unit 1. `launch-qemu-noncc.sh` copies it from `OVMF_VARS.fd` into the current directory on first boot; QEMU updates it on every boot. |
| `runs/gt_debug/summary.csv` | 11-12 | 11-12 | First known-address (`--gt`) debug run, test #0. Result: cube, correct, 148/148 GT pages. |
| `runs/gt_debug/tracked_0.json` | 11-12 | 11-12 | Stage 2 output for that run: GT pages, candidates, pieces, etc. |
| `runs/gt_debug/dump_0.json` | 11-12 | 11-12 | Stage 3 metadata (dumped page list, GT overlap). |
| `runs/gt_debug/result_0.json` | 11-12 | 11-12 | Stage 4/5 result: prediction, base offset (est = GT = 2112), coverage. |
| `runs/blind_debug/summary.csv` | 11-12 | 11-12 | First blind debug run, test #1–3. #1 had 10 candidates and a correct prediction, but 0 GT pages (correct by chance). #2 and #3 had 0 candidates. |
| `runs/blind_debug/tracked_{1,2,3}.json` | 11-12 | 11-12 | Stage 2 output per sample. #2 and #3 are only 285 B: no candidates. |
| `runs/blind_debug/dump_{1,2,3}.json` | 11-12 | 11-12 | Stage 3 metadata per sample. |
| `runs/blind_debug/result_{1,2,3}.json` | 11-12 | 11-12 | Stage 4/5 result per sample. |

## Not in git (local only)

| Path | Description |
|---|---|
| `daemon_*.log`, `stage1_build.log` | Capture logs. Git-ignored by `*.log`, so they are committed as an archive: `../logs/capture_logs_20261118.tar.gz`. |
| `guest_crashes/` | Guest console logs saved on oops/panic (14 files, 11-12 to 11-17). |
| `runs/*/dump_*_p*.out`, `runs/*/cmap_*.npy`, `runs/*/wpt_*.log`, `runs/blind_debug/probe_1/` | Page dumps, cipher maps, write traces and probe reads from the debug runs. |
| `runs/blind_debug/usenix.fd` | Leftover boot copy, removed from git on 11-18. The file is root-owned, so the local copy is still there. |
| `../captures/` | Main capture data: `test_blind` (pieces, 11-13) and `test_runhit` (run\*hit, 11-17), 3.1 GB each. |
