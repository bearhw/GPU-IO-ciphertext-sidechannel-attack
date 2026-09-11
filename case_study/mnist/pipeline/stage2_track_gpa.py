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
        stderr=subprocess.PIPE, text=True,
    )
    for line in proc.stdout:
        if "HOLDER_READY" in line:
            return proc
    stderr_out = proc.stderr.read()
    proc.stdin.close()
    proc.wait()
    print(f"[stage2] [!] Holder never reached HOLDER_READY for index {index}", file=sys.stderr)
    if stderr_out:
        print(f"[stage2] [!] Guest stderr:\n{stderr_out}", file=sys.stderr)
    return None


def release_holder(proc, index: int) -> Tuple[Optional[int], Optional[int], int]:
    """Release holder past HOLDER_READY gate and read target label / GPA."""
    proc.stdin.write("\n")
    proc.stdin.flush()
    label, image_gpa, pixel_offset = None, None, 0
    for line in proc.stdout:
        print(f"  [guest] {line}", end="")
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


def acquire_guest_gpa_direct(index: int, use_main: bool = True, normalize: bool = False):
    """Direct acquisition from guest (cooperative)."""
    if use_main:
        proc = spawn_holder(index, batch_size=1, normalize=normalize)
        if proc is None:
            return None, None, 0, proc
        label, image_gpa, pixel_offset = release_holder(proc, index)
        return label, image_gpa, pixel_offset, proc

    cmd = (f"cd ~/cc_uvm/pytorch_uvm310_test/mnist && "
           f"sudo {c.GUEST_PY} -u main_gpa_3.py --index {index}")
    proc = subprocess.Popen(
        c.SSH_BASE + [cmd],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, text=True,
    )
    label, image_gpa, pixel_offset = None, None, 0
    for line in proc.stdout:
        print(f"  [guest] {line}", end="")
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


def detect_blind_candidates(log_path: Path) -> List[Dict]:
    """Analyze Region-B precursor writes from tracker log to rank candidate GPAs."""
    window_ns = c.BLIND_WINDOW_US * 1000
    candidates = {}

    look_active = False
    look_remaining = 0
    look_run_base = 0
    look_run_len = 0
    look_prec_ns = 0

    def finalize_run():
        nonlocal look_run_base, look_run_len
        if look_run_len >= c.BLIND_MIN_RUN:
            al = look_run_base & ~(c.BLIND_ALIGN_2MB - 1)
            cand = candidates.setdefault(
                al, {"aligned": al, "exact": look_run_base, "hits": 0, "max_run": 0})
            cand["hits"] += 1
            cand["max_run"] = max(cand["max_run"], look_run_len)
            cand["exact"] = min(cand["exact"], look_run_base)

    if not log_path.exists():
        return []

    with open(log_path, errors="ignore") as f:
        for line in f:
            m = BLIND_LINE_RE.search(line)
            if not m:
                continue
            gpa = int(m.group(1), 16)
            ts = int(m.group(2))

            if c.BLIND_B_LO <= gpa < c.BLIND_B_HI:
                if look_active:
                    finalize_run()
                look_active = True
                look_remaining = c.BLIND_LOOKAHEAD
                look_run_base = 0
                look_run_len = 0
                look_prec_ns = ts
                continue

            if not look_active:
                continue
            if c.BLIND_A_LO <= gpa < c.BLIND_A_HI:
                continue
            if look_run_len == 0 and (ts - look_prec_ns) > window_ns:
                look_active = False
                continue

            if look_run_len == 0:
                look_run_base = gpa
                look_run_len = 1
            else:
                expected = look_run_base + look_run_len * c.PAGE_SIZE
                if gpa == expected:
                    look_run_len += 1
                elif gpa > expected:
                    gap_pages = (gpa - expected) // c.PAGE_SIZE
                    if gap_pages <= c.BLIND_GAP_TOL:
                        look_run_len += int(gap_pages) + 1
                    else:
                        finalize_run()
                        look_run_base = gpa
                        look_run_len = 1
                else:
                    finalize_run()
                    look_run_base = gpa
                    look_run_len = 1

            if look_run_len < c.BLIND_MIN_RUN:
                look_remaining -= 1
                if look_remaining <= 0:
                    look_active = False

    if look_active:
        finalize_run()

    ranked = sorted(candidates.values(),
                    key=lambda x: (x["hits"] * x["max_run"], x["hits"]),
                    reverse=True)
    return ranked


def track_image_gpa_blind(index: int, output_dir: Path, settle: int = 2, duration: int = 8,
                          use_main: bool = True, normalize: bool = False):
    """Arm write_pattern_tracker on host and trigger sample load."""
    guest_proc = spawn_holder(index, batch_size=1, normalize=normalize) if use_main else None

    log_path = output_dir / f"blind_{index}.log"
    dbg_path = output_dir / f"blind_{index}_dbg.log"
    log_f = open(log_path, "w")
    dbg_f = open(dbg_path, "w")

    tracker_bin = str(c.TRACKER_PATH)
    tracker_cmd = [
        tracker_bin, "--duration", str(duration), "--settle", str(settle),
        "--start-gpa", "0x0", "--track-size", "0x400000000",
        "--start-gpa2", hex(c.BLIND_B_LO), "--track-size2", hex(c.BLIND_B_HI - c.BLIND_B_LO)
    ]
    tracker_proc = subprocess.Popen(tracker_cmd, stdout=log_f, stderr=dbg_f)
    print(f"[stage2] [blind] Armed write_pattern_tracker (settle={settle}s, duration={duration}s)")

    deadline = time.time() + settle + 5
    while time.time() < deadline:
        time.sleep(0.2)
        if dbg_path.exists() and "Settle done" in dbg_path.read_text(errors="ignore"):
            break

    if use_main and guest_proc:
        label, gt_gpa, pixel_offset = release_holder(guest_proc, index)
    else:
        label, gt_gpa, pixel_offset, guest_proc = acquire_guest_gpa_direct(index, use_main=False, normalize=normalize)

    try:
        tracker_proc.wait(timeout=duration + 15)
    except subprocess.TimeoutExpired:
        tracker_proc.kill()
        tracker_proc.wait()

    log_f.close()
    dbg_f.close()

    candidates = detect_blind_candidates(log_path)
    print(f"[stage2] [blind] Found {len(candidates)} candidate(s) from write trace")
    return label, gt_gpa, pixel_offset, candidates, guest_proc


def run_stage2(index: int, output_dir: Path, blind: bool = False,
               page2_gpa_override: int = None, hold_guest: bool = True) -> Tuple[Dict, Optional[subprocess.Popen]]:
    """Execute Stage 2."""
    output_dir.mkdir(parents=True, exist_ok=True)
    json_path = output_dir / f"tracked_target_{index}.json"

    c.ensure_guest_suppressions()

    if blind:
        label, gt_gpa, pixel_offset, candidates, guest_proc = track_image_gpa_blind(
            index, output_dir, use_main=True, normalize=False)
        if candidates:
            chosen_gpa = candidates[0]["exact"]
            blind_detected = True
            print(f"[stage2] [blind] Selected top candidate: 0x{chosen_gpa:x} "
                  f"(hits={candidates[0]['hits']}, max_run={candidates[0]['max_run']})")
        else:
            chosen_gpa = gt_gpa
            blind_detected = False
            print(f"[stage2] [blind] No candidate found -> falling back to Ground Truth GPA: 0x{gt_gpa:x}")
    else:
        label, gt_gpa, pixel_offset, guest_proc = acquire_guest_gpa_direct(index, use_main=True, normalize=False)
        chosen_gpa = gt_gpa
        blind_detected = False
        candidates = []
        print(f"[stage2] [cooperative] Acquired Ground Truth GPA: 0x{chosen_gpa:x}, label={label}, offset={pixel_offset}")

    # Resolve Page 2 GPA
    page2_table = c.load_page2_table()
    if page2_gpa_override is not None:
        page2_gpa = page2_gpa_override
        p2_src = "explicit override"
    elif chosen_gpa in page2_table:
        page2_gpa = page2_table[chosen_gpa]
        p2_src = "lookup cache"
    else:
        page2_gpa = chosen_gpa + c.PAGE_SIZE
        p2_src = "contiguous fallback (+4096)"

    print(f"[stage2] Page 2 GPA ({p2_src}) = 0x{page2_gpa:x}")

    meta = {
        "stage": 2,
        "index": index,
        "label": label,
        "image_gpa": f"0x{chosen_gpa:x}" if chosen_gpa else None,
        "image_gpa_int": chosen_gpa,
        "page2_gpa": f"0x{page2_gpa:x}" if page2_gpa else None,
        "page2_gpa_int": page2_gpa,
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
    p.add_argument("--index", type=int, required=True, help="MNIST sample index (0-59999)")
    p.add_argument("--blind", action="store_true", help="Perform blind write tracking")
    p.add_argument("--page2-gpa", default=None, help="Explicit Page 2 GPA override (hex)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save metadata")
    p.add_argument("--release-guest", action="store_true", help="Release guest memory hold immediately after tracking")
    args = p.parse_args()

    p2_override = int(args.page2_gpa, 16) if args.page2_gpa else None
    meta, guest_proc = run_stage2(
        args.index, Path(args.output_dir), blind=args.blind,
        page2_gpa_override=p2_override, hold_guest=not args.release_guest)

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
