#!/usr/bin/env python3
"""
case_study/llm/pipeline/stage2_track_blocks.py — Stage 2: Write Pattern Tracking & 2MB Block Ranking.

Tasks:
1. Capture or parse write_pattern_tracker WRITE log during LLM inference.
2. Filter GPU-CC control regions A/B and detect contiguous page write runs.
3. Score 2MB candidate blocks (score = hits * max_run_len) and rank the top-K blocks.
4. Export stage2_tracked_{index}.json for Stage 3 localization.

Usage:
    # Online mode: trigger guest inference and capture live tracker log
    sudo python3 stage2_track_blocks.py --index 2 --output-dir .

    # Offline mode: score an existing tracker log
    python3 stage2_track_blocks.py --index 2 --host-log ../e2e_combined_wpt.log --output-dir .
"""

import argparse
import re
import subprocess
import sys
import threading
import time
from collections import defaultdict
from pathlib import Path
from typing import Any, Dict, List, Optional, Set, Tuple

import common as c

RE_WRITE = re.compile(r'WRITE\s+gpa=0x([0-9a-f]+)\s+ts=(\d+)', re.I)
RE_BASE = re.compile(r'input_ids base(?: page)? GPA:\s*0x([0-9a-f]+)', re.I)
RE_N = re.compile(r'N_image_pad:\s+(\d+)', re.I)

MIN_RUN = 2
GAP_TOL = 2
# GPU-CC control regions: A = per-batch clock, B = image-DMA staging
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
B_LO, B_HI = 0x3f80000000, 0x3f90000000


def block_base_gpa(gpa: int) -> int:
    return (gpa // c.BLOCK_SIZE) * c.BLOCK_SIZE


def score_blocks_from_log(host_log_path: str) -> Tuple[Dict[int, Tuple[int, int, int]], Dict[int, List[Tuple[int, int]]]]:
    """Return ({block_base: (score, hits, max_run)}, {block_base: [(run_start_gpa, run_len)]}) from WRITE log."""
    faults = []
    with open(host_log_path, errors="ignore", encoding="utf-8") as f:
        for line in f:
            m = RE_WRITE.search(line)
            if m:
                faults.append((int(m.group(2)), int(m.group(1), 16) & ~(c.PAGE_SIZE - 1)))
    faults.sort()

    runs = defaultdict(list)
    base = length = 0

    def record():
        nonlocal base, length
        if length >= MIN_RUN:
            runs[block_base_gpa(base)].append((base, length))

    for _, gpa in faults:
        if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
            record()
            base = length = 0
            continue
        if length == 0:
            base, length = gpa, 1
        else:
            expected = base + length * c.PAGE_SIZE
            if gpa == expected:
                length += 1
            elif gpa > expected:
                gap = (gpa - expected) // c.PAGE_SIZE
                if gap <= GAP_TOL:
                    length += int(gap) + 1
                else:
                    record()
                    base, length = gpa, 1
            else:
                record()
                base, length = gpa, 1
    record()

    scores = {}
    block_run_bases = {}
    for b, r_list in runs.items():
        lengths = [l for _, l in r_list]
        scores[b] = (len(lengths) * max(lengths), len(lengths), max(lengths))
        # Sort run starting GPAs by run length descending (longest runs tried first!)
        sorted_runs = sorted(r_list, key=lambda x: -x[1])
        seen = set()
        unique_bases = []
        for g, l in sorted_runs:
            if g not in seen:
                seen.add(g)
                unique_bases.append((g, l))
        block_run_bases[b] = unique_bases

    return scores, block_run_bases


def run_stage2_online(index: int, top_k: int = 7, max_new_tokens: int = 60,
                      output_dir: Optional[Path] = None) -> Dict[str, Any]:
    """Trigger guest inference via SSH, capture tracker log, and score blocks."""
    out_dir = output_dir or c.PIPELINE_DIR
    out_dir.mkdir(parents=True, exist_ok=True)
    log_path = out_dir / f"sample_{index}_wpt.log"

    print(f"[Stage 2] Starting online tracking for sample index {index}...")
    c.ensure_mtu_9000()

    # Launch guest workload in one-shot mode if running standalone
    cmd = (
        f"cd {c.GUEST_CWD} && sudo env HF_HUB_OFFLINE=1 TRANSFORMERS_OFFLINE=1 "
        f"{c.GUEST_PY} -u {c.GSCRIPT} --model_id Qwen/Qwen2-VL-2B-Instruct "
        f"--calibrate --index {index} --max_new_tokens {max_new_tokens}"
    )

    # Arm tracker
    log_f = open(log_path, "w", encoding="utf-8")
    tr = subprocess.Popen(
        [c.TRACKER_BIN, "--start-gpa", hex(c.TRACK_START),
         "--track-size", hex(c.TRACK_SIZE),
         "--duration", "120", "--settle", str(c.TRACKER_SETTLE_S)],
        stdout=log_f, stderr=subprocess.PIPE, text=True
    )

    armed = False
    deadline = time.time() + c.TRACKER_SETTLE_S + 10
    while time.time() < deadline:
        line = tr.stderr.readline()
        if not line:
            break
        if "Settle done" in line:
            armed = True
            break
    if not armed:
        print("[!] Tracker never settled", file=sys.stderr)

    def _drain():
        for _ in tr.stderr:
            pass
    threading.Thread(target=_drain, daemon=True).start()

    gt = {"base": None, "N": None, "ind": None}
    print(f"[Stage 2] Executing guest inference for index {index}...")
    g = subprocess.Popen(c.SSH_CMD + [cmd], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)

    grab_ind = False
    for l in g.stdout:
        if "INDICATION (sample id" in l:
            grab_ind = True
            continue
        if grab_ind and gt["ind"] is None and l.strip() and "====" not in l:
            gt["ind"] = l.strip()
            grab_ind = False
        m = RE_BASE.search(l)
        if m:
            gt["base"] = int(m.group(1), 16)
        m = RE_N.search(l)
        if m:
            gt["N"] = int(m.group(1))

    g.wait()
    time.sleep(1)
    tr.terminate()
    try:
        tr.wait(timeout=5)
    except Exception:
        tr.kill()
    log_f.close()

    return process_tracked_log(index, str(log_path), gt, top_k, out_dir)


def process_tracked_log(index: int, host_log_path: str, gt: Optional[Dict[str, Any]],
                        top_k: int = 7, out_dir: Optional[Path] = None) -> Dict[str, Any]:
    out_dir = out_dir or c.PIPELINE_DIR
    out_json = out_dir / f"stage2_tracked_{index}.json"

    scores, block_run_bases = score_blocks_from_log(host_log_path)
    ranked = sorted(scores.keys(), key=lambda b: -scores[b][0])

    gt_dict = gt or {}
    gt_base = gt_dict.get("base")
    gt_blk = block_base_gpa(gt_base) if gt_base else None
    gt_rank = (ranked.index(gt_blk) + 1) if (gt_blk and gt_blk in ranked) else None

    top_candidates = ranked[:top_k]
    candidate_details = {
        hex(b): {
            "score": scores[b][0],
            "hits": scores[b][1],
            "max_run": scores[b][2]
        } for b in top_candidates
    }
    candidate_run_bases = {
        hex(b): [hex(g) for g, _ in block_run_bases.get(b, [])[:10]]
        for b in top_candidates
    }

    print(f"[Stage 2] {len(scores)} 2MB blocks scored. Top-{top_k} candidates:")
    for rank, b in enumerate(top_candidates, 1):
        s, h, r = scores[b]
        is_gt = " (GT MATCH)" if b == gt_blk else ""
        run_gpas_str = ", ".join([hex(g) for g, _ in block_run_bases.get(b, [])[:3]])
        print(f"  #{rank:<2d} 0x{b:011x}  score={s:>8,d}  hits={h:>4d}  max_run={r:>3d}p  run_bases=[{run_gpas_str}]{is_gt}")

    if gt_base:
        print(f"[Stage 2] Ground Truth base=0x{gt_base:x} (Block 0x{gt_blk:x}) Rank: #{gt_rank or 'NOT_IN_TOP'}")

    result = {
        "index": index,
        "host_log": str(host_log_path),
        "total_scored_blocks": len(scores),
        "candidate_blocks": [hex(b) for b in top_candidates],
        "candidate_details": candidate_details,
        "candidate_run_bases": candidate_run_bases,
        "gt_base": hex(gt_base) if gt_base else None,
        "gt_rank": gt_rank,
        "gt_indication": gt_dict.get("ind"),
        "gt_N": gt_dict.get("N"),
        "timestamp": time.time(),
    }

    c.save_json(out_json, result)
    print(f"[Stage 2] Saved tracking results -> {out_json}")
    return result


def main():
    p = argparse.ArgumentParser(description="Stage 2: Write Tracking & 2MB Block Candidate Ranking")
    p.add_argument("--index", type=int, default=2, help="Sample index to track")
    p.add_argument("--host-log", type=str, default=None, help="Path to existing write_pattern_tracker log (offline mode)")
    p.add_argument("--top-k", type=int, default=7, help="Number of candidate 2MB blocks to rank")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR, help="Output directory")
    args = p.parse_args()

    if args.host_log:
        if Path(args.host_log).exists():
            print(f"[Stage 2] Using existing host log: {args.host_log}")
            process_tracked_log(args.index, args.host_log, None, args.top_k, args.output_dir)
        else:
            print(f"[!] Specified host log does not exist: {args.host_log}", file=sys.stderr)
            sys.exit(1)
    else:
        run_stage2_online(args.index, args.top_k, output_dir=args.output_dir)


if __name__ == "__main__":
    main()
