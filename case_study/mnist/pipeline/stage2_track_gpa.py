#!/usr/bin/env python3
"""
stage2_track_gpa.py — Stage 2: Target Image GPA Tracking and Candidate Ranking.

Acquires Ground Truth GPA from the guest, optionally performs host-side
write_pattern_tracker Region-B precursor detection, falls back to Ground Truth
if blind tracking fails, and persists metadata to tracked_target_{index}.json.

Usage:
    python3 stage2_track_gpa.py --index 0 [--blind] [--output-dir .]
"""

import argparse
import os
import re
import subprocess
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

BLIND_LINE_RE = re.compile(r'WRITE\s+gpa=0x([0-9a-fA-F]+)\s+ts=(\d+)')


def spawn_holder(index: int, batch_size: int = 1, normalize: bool = False):
    """Start main_holder.py on guest stopping at HOLDER_READY gate."""
    holder = "main_holder_norm.py" if normalize else "main_holder.py"
    cmd = (f"cd ~/cc_uvm/pytorch_uvm310_test/mnist && "
           f"sudo {c.GUEST_PY} -u {holder} "
           f"--no-accel --batch-size {batch_size} --epochs 1 --hold-batch {index}")
    proc = subprocess.Popen(
        c.SSH_BASE + [cmd],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, text=True, bufsize=1,
    )
    while True:
        line = proc.stdout.readline()
        if not line:
            break
        if "HOLDER_READY" in line:
            return proc
    stderr_out = proc.stderr.read()
    proc.stdin.close()
    proc.wait()
    print(f"[stage2] [!] Holder never reached HOLDER_READY for index {index}", file=sys.stderr, flush=True)
    if stderr_out:
        print(f"[stage2] [!] Guest stderr:\n{stderr_out}", file=sys.stderr, flush=True)
    return None


def release_holder(proc, index: int) -> Tuple[Optional[int], Optional[int], int]:
    """Release holder past HOLDER_READY gate and read target label / GPA."""
    proc.stdin.write("\n")
    proc.stdin.flush()
    label, image_gpa, pixel_offset = None, None, 0
    while True:
        line = proc.stdout.readline()
        if not line:
            break
        print(f"  [guest] {line}", end="", flush=True)
        m = re.match(r"Target Label: (\d+)", line)
        if m:
            label = int(m.group(1))
        m = re.match(r"Image GPA \(Aligned\): 0x([0-9a-f]+)(?:\s+offset=(\d+))?", line, re.IGNORECASE)
        if m:
            image_gpa = int(m.group(1), 16)
            if m.group(2):
                pixel_offset = int(m.group(2))
        if label is not None and image_gpa is not None:
            break
    return label, image_gpa, pixel_offset


def acquire_guest_gpa_direct(index: int, use_main: bool = True, normalize: bool = False, batch_size: int = 1):
    """Direct acquisition from guest (cooperative)."""
    if use_main:
        proc = spawn_holder(index, batch_size=batch_size, normalize=normalize)
        if proc is None:
            return None, None, 0, proc
        label, image_gpa, pixel_offset = release_holder(proc, index)
        return label, image_gpa, pixel_offset, proc

    cmd = (f"cd ~/cc_uvm/pytorch_uvm310_test/mnist && "
           f"sudo {c.GUEST_PY} -u main_gpa_3.py --index {index}")
    proc = subprocess.Popen(
        c.SSH_BASE + [cmd],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, text=True, bufsize=1,
    )
    label, image_gpa, pixel_offset = None, None, 0
    while True:
        line = proc.stdout.readline()
        if not line:
            break
        print(f"  [guest] {line}", end="", flush=True)
        m = re.match(r"Target Label: (\d+)", line)
        if m:
            label = int(m.group(1))
        m = re.match(r"Image GPA \(Aligned\): 0x([0-9a-f]+)(?:\s+offset=(\d+))?", line, re.IGNORECASE)
        if m:
            image_gpa = int(m.group(1), 16)
            if m.group(2):
                pixel_offset = int(m.group(2))
        if label is not None and image_gpa is not None:
            break
    return label, image_gpa, pixel_offset, proc


def detect_blind_candidates(log_path: Path, batch_size: int = 1, top_n: int = 5) -> List[Dict]:
    """Analyze tracker log to rank Top-N candidate GPAs using Burst Density & Contiguous Run signatures."""
    if not log_path.exists():
        return []

    PAGE = 0x1000
    candidates = {}

    look_active = False
    look_prec_ns = 0
    look_remaining = 0
    window_ns = c.BLIND_WINDOW_US * 1000

    cur_run_base = 0
    cur_run_len = 0

    with open(log_path, errors="ignore") as f:
        for line in f:
            m = BLIND_LINE_RE.search(line)
            if not m:
                continue
            gpa = int(m.group(1), 16)
            ts = int(m.group(2))

            # 1. Detect Precursor-B write (AES-GCM staging buffer 0x3f80000000 ~ 0x3f90000000)
            if c.BLIND_B_LO <= gpa < c.BLIND_B_HI:
                look_active = True
                look_prec_ns = ts
                look_remaining = c.BLIND_LOOKAHEAD
                continue

            # 2. Exclude per-batch clock region & precursor region
            if (c.BLIND_A_LO <= gpa < c.BLIND_A_HI) or (c.BLIND_B_LO <= gpa < c.BLIND_B_HI):
                continue

            # 3. Check time window expiration for precursor correlation
            if look_active:
                if (ts - look_prec_ns) > window_ns or look_remaining <= 0:
                    look_active = False
                else:
                    look_remaining -= 1

            # 4. Strict filter: User Dynamic Memory (16GB ~ 248GB)
            if not (0x400000000 <= gpa < 0x3e00000000):
                continue

            # 5. Cluster writes by 2MB block boundary & track contiguous runs
            al = gpa & ~(c.BLIND_ALIGN_2MB - 1)
            cand = candidates.setdefault(
                al, {"aligned": al, "exact": gpa, "min_gpa": gpa, "pages": set(), "burst_hits": 0, "max_run": 1, "last_gpa": 0, "cur_run": 1, "prec_hits": 0}
            )
            cand["pages"].add(gpa)
            cand["burst_hits"] += 1
            cand["min_gpa"] = min(cand["min_gpa"], gpa)
            if look_active:
                cand["prec_hits"] += 1

            if cand["last_gpa"] > 0:
                expected = cand["last_gpa"] + PAGE
                if gpa == expected:
                    cand["cur_run"] += 1
                elif gpa > expected and (gpa - expected) // PAGE <= 2:
                    cand["cur_run"] += 1 + ((gpa - expected) // PAGE)
                else:
                    cand["cur_run"] = 1
                if cand["cur_run"] > cand["max_run"]:
                    cand["max_run"] = cand["cur_run"]
            cand["last_gpa"] = gpa

    # 6. Rank candidate 2MB blocks:
    # High score for wide unique page footprint + contiguous run length, penalized for repetitive loops
    ranked_list = []
    for cand in candidates.values():
        unique_cnt = len(cand["pages"])
        if unique_cnt < 2:
            continue
        burst_hits = cand["burst_hits"]
        max_run = max(cand["max_run"], unique_cnt if unique_cnt <= 10 else int(unique_cnt * 0.8))
        ratio = burst_hits / unique_cnt

        if ratio > 10.0:
            score = float((unique_cnt * max_run) / (ratio * 5.0))
        else:
            prec_bonus = 1.5 if cand["prec_hits"] > 0 else 1.0
            score = float((unique_cnt * max_run * prec_bonus) / max(1.0, ratio))

        cand_dict = {
            "aligned": cand["aligned"],
            "exact": cand["min_gpa"],
            "unique_pages": unique_cnt,
            "hits": burst_hits,
            "max_run": max_run,
            "ratio": round(ratio, 2),
            "score": round(score, 2),
        }
        ranked_list.append(cand_dict)

    ranked_list.sort(key=lambda x: x["score"], reverse=True)
    return ranked_list[:top_n]


def track_image_gpa_blind(index: int, output_dir: Path, settle: int = 2,
                          duration: int = c.DEFAULT_TRACKER_DURATION,
                          use_main: bool = True, batch_size: int = 1,
                          normalize: bool = False, top_n: int = 5):
    """Arm write_pattern_tracker on host, trigger sample load, and harvest load burst."""
    dumps_dir, logs_dir, results_dir = c.get_output_subdirs(output_dir)
    guest_proc = spawn_holder(index, batch_size=batch_size, normalize=normalize) if use_main else None

    log_path = logs_dir / f"blind_{index}.log"
    dbg_path = logs_dir / f"blind_{index}_dbg.log"
    log_f = open(log_path, "w")
    dbg_f = open(dbg_path, "w")

    tracker_bin = str(c.TRACKER_PATH)
    tracker_cmd = [
        tracker_bin, "--duration", str(duration), "--settle", str(settle),
        "--start-gpa", "0x0", "--track-size", "0x4000000000",
        "--start-gpa2", hex(c.BLIND_B_LO), "--track-size2", hex(c.BLIND_B_HI - c.BLIND_B_LO)
    ]
    tracker_proc = subprocess.Popen(tracker_cmd, stdout=log_f, stderr=dbg_f)
    print(f"[stage2] [blind] Armed write_pattern_tracker (settle={settle}s, max_duration={duration}s, bs={batch_size})")

    deadline = time.time() + settle + 5
    while time.time() < deadline:
        time.sleep(0.2)
        if dbg_path.exists() and "Settle done" in dbg_path.read_text(errors="ignore"):
            break

    if use_main and guest_proc:
        label, gt_gpa, pixel_offset = release_holder(guest_proc, index)
    else:
        label, gt_gpa, pixel_offset, guest_proc = acquire_guest_gpa_direct(
            index, use_main=False, normalize=normalize, batch_size=batch_size)

    # Guest has completed batch loading and is holding at the gate.
    # Allow 2.0s drain for in-flight write faults, then terminate tracker to avoid idle noise.
    time.sleep(2.0)
    tracker_proc.terminate()
    try:
        tracker_proc.wait(timeout=5)
    except subprocess.TimeoutExpired:
        tracker_proc.kill()
        tracker_proc.wait()

    log_f.close()
    dbg_f.close()

    candidates = detect_blind_candidates(log_path, batch_size=batch_size, top_n=top_n)
    print(f"[stage2] [blind] Found {len(candidates)} Top-N candidate(s) from write trace (min_run={c.BLIND_MIN_RUN})")
    for i, cand in enumerate(candidates, 1):
        print(f"         #{i}: GPA 0x{cand['exact']:x} (aligned 0x{cand['aligned']:x}, max_run={cand['max_run']}, hits={cand['hits']}, score={cand['score']})")
    return label, gt_gpa, pixel_offset, candidates, guest_proc


def run_stage2(index: int, output_dir: Path, blind: bool = False,
               batch_size: int = 1, page2_gpa_override: int = None,
               hold_guest: bool = True, duration: int = c.DEFAULT_TRACKER_DURATION,
               top_n: int = 5) -> Tuple[Dict, Optional[subprocess.Popen]]:
    """Execute Stage 2."""
    dumps_dir, logs_dir, results_dir = c.get_output_subdirs(output_dir)
    json_path = results_dir / f"tracked_target_{index}.json"

    c.ensure_guest_suppressions()

    if blind:
        label, gt_gpa, pixel_offset, candidates, guest_proc = track_image_gpa_blind(
            index, output_dir, settle=2, duration=duration, use_main=True,
            batch_size=batch_size, normalize=False, top_n=top_n)
        if candidates:
            chosen_gpa = candidates[0]["exact"]
            blind_detected = True
            print(f"[stage2] [blind] Selected top candidate: 0x{chosen_gpa:x} "
                  f"(hits={candidates[0]['hits']}, max_run={candidates[0]['max_run']}, score={candidates[0]['score']})")
        else:
            chosen_gpa = gt_gpa
            blind_detected = False
            print(f"[stage2] [blind] No candidate found -> falling back to Ground Truth GPA: 0x{gt_gpa:x}")
    else:
        guest_proc = spawn_holder(index, batch_size=batch_size, normalize=False)
        if guest_proc:
            label, gt_gpa, pixel_offset = release_holder(guest_proc, index)
        else:
            label, gt_gpa, pixel_offset, guest_proc = acquire_guest_gpa_direct(index, use_main=False, normalize=False)
        chosen_gpa = gt_gpa
        blind_detected = False
        candidates = []
        print(f"[stage2] [cooperative] Acquired Ground Truth GPA: 0x{chosen_gpa:x}, label={label}, offset={pixel_offset}")

    # Resolve Page 2 GPA (for batch_size=1 compatibility)
    page2_table = c.load_page2_table()
    if page2_gpa_override is not None:
        page2_gpa = page2_gpa_override
        p2_src = "explicit override"
    elif chosen_gpa in page2_table:
        page2_gpa = page2_table[chosen_gpa]
        p2_src = "lookup cache"
    else:
        page2_gpa = chosen_gpa + c.PAGE_SIZE if chosen_gpa else None
        p2_src = "contiguous fallback (+4096)"

    # Calculate number of pages for this batch
    if batch_size == 1:
        num_pages = 2
        page_gpas = [chosen_gpa, page2_gpa] if chosen_gpa and page2_gpa else ([chosen_gpa] if chosen_gpa else [])
        print(f"[stage2] Single sample spanning 2 pages: Page 1=0x{chosen_gpa:x}, Page 2 ({p2_src})=0x{page2_gpa:x}")
    else:
        num_pages = (batch_size * c.IMG_BYTES + c.PAGE_SIZE - 1) // c.PAGE_SIZE
        page_gpas = [chosen_gpa + k * c.PAGE_SIZE for k in range(num_pages)] if chosen_gpa else []
        print(f"[stage2] Batch size {batch_size} spanning {num_pages} pages: 0x{page_gpas[0]:x} .. 0x{page_gpas[-1]:x}")

    meta = {
        "stage": 2,
        "index": index,
        "batch_size": batch_size,
        "num_pages": num_pages,
        "label": label,
        "image_gpa": f"0x{chosen_gpa:x}" if chosen_gpa else None,
        "image_gpa_int": chosen_gpa,
        "page2_gpa": f"0x{page2_gpa:x}" if page2_gpa else None,
        "page2_gpa_int": page2_gpa,
        "page_gpas": [f"0x{g:x}" for g in page_gpas],
        "page_gpas_int": page_gpas,
        "pixel_offset": pixel_offset,
        "blind_detected": blind_detected,
        "ground_truth_gpa": f"0x{gt_gpa:x}" if gt_gpa else None,
        "candidates": candidates,
        "timestamp": time.time(),
    }
    c.save_json(json_path, meta)
    print(f"[stage2] Saved tracking metadata → {json_path}")

    if not hold_guest and guest_proc:
        try:
            guest_proc.stdin.close()
            guest_proc.wait(timeout=5)
        except Exception:
            guest_proc.kill()
        guest_proc = None

    return meta, guest_proc


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, required=True, help="MNIST sample/batch index (0-59999)")
    p.add_argument("--batch-size", type=int, default=1, help="Batch size (default: 1, e.g. 512)")
    p.add_argument("--blind", action="store_true", help="Perform blind write tracking")
    p.add_argument("--duration", type=int, default=c.DEFAULT_TRACKER_DURATION, help="Tracker duration in seconds (default: 120)")
    p.add_argument("--top-n", type=int, default=5, help="Number of top candidates to keep (default: 5)")
    p.add_argument("--page2-gpa", default=None, help="Explicit Page 2 GPA override (hex)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save metadata")
    p.add_argument("--release-guest", action="store_true", help="Release guest memory hold immediately after tracking")
    args = p.parse_args()

    p2_override = int(args.page2_gpa, 16) if args.page2_gpa else None
    meta, guest_proc = run_stage2(
        args.index, Path(args.output_dir), blind=args.blind,
        batch_size=args.batch_size,
        page2_gpa_override=p2_override, hold_guest=not args.release_guest,
        duration=args.duration, top_n=args.top_n)

    if guest_proc:
        print("[stage2] Guest process is currently holding tensor memory.")
        print("[stage2] Press Enter to release guest process...")
        try:
            input()
        except EOFError:
            pass
        finally:
            guest_proc.stdin.close()
            guest_proc.wait()


if __name__ == "__main__":
    main()
