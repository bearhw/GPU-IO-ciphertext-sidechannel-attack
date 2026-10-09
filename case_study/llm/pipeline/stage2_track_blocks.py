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
import os
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

MIN_RUN = 1
GAP_TOL = 2
# GPU-CC control regions: A = per-batch clock, B = image-DMA staging
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
B_LO, B_HI = 0x3f80000000, 0x3f90000000


def block_base_gpa(gpa: int) -> int:
    return (gpa // c.BLOCK_SIZE) * c.BLOCK_SIZE


def score_blocks_from_log(host_log_path: str, start_offset: int = 0
                          ) -> Tuple[Dict[int, Tuple[int, int, int, int]],
                                     Dict[int, List[Tuple[int, int, int]]]]:
    """Parse the WRITE log into per-2MB-block write runs, carrying timestamps.

    Returns:
      scores: {block_base: (write_score, n_runs, max_run, earliest_ts)}
      block_runs: {block_base: [(run_start_gpa, run_len, run_start_ts), ...]}
                  ordered earliest-ts first (input_ids is written early, once).

    earliest_ts (relative ns from the first write in this log segment) is the key
    signal for input_ids: a single-inference input_ids buffer is written ONCE and
    EARLY, whereas activations / KV cache are rewritten heavily throughout — so a
    write-count score favors the wrong tensors. Ranking by earliest_ts surfaces
    the input_ids block; image_pad still confirms it downstream.
    """
    faults_by_block = defaultdict(list)
    t0 = None
    with open(host_log_path, errors="ignore", encoding="utf-8") as f:
        if start_offset > 0:
            try:
                f.seek(start_offset)
                f.readline()
            except Exception:
                pass
        for line in f:
            m = RE_WRITE.search(line)
            if m:
                gpa = int(m.group(1), 16) & ~(c.PAGE_SIZE - 1)
                ts = int(m.group(2))
                if t0 is None:
                    t0 = ts
                blk = block_base_gpa(gpa)
                faults_by_block[blk].append((ts, gpa))

    t0 = t0 or 0
    scores = {}
    block_run_bases = {}
    page_ts_by_block = {}   # blk -> {page_gpa: first_write_ts_rel} (per-PAGE ts, for the known-block latest-first scan)
    for blk, fault_list in faults_by_block.items():
        if blk < c.TRACK_START or blk >= c.TRACK_START + c.TRACK_SIZE:
            continue

        # Spatial aggregation: extract unique GPAs and their earliest write timestamps
        gpa_first_ts = {}
        for ts, gpa in fault_list:
            if gpa not in gpa_first_ts or ts < gpa_first_ts[gpa]:
                gpa_first_ts[gpa] = ts

        sorted_gpas = sorted(gpa_first_ts.keys())
        if not sorted_gpas:
            continue
        page_ts_by_block[blk] = {g: gpa_first_ts[g] - t0 for g in gpa_first_ts}

        # Spatial continuous run detection
        runs = []
        base, length = sorted_gpas[0], 1
        run_ts = [gpa_first_ts[sorted_gpas[0]]]
        for gpa in sorted_gpas[1:]:
            expected = base + length * c.PAGE_SIZE
            if gpa == expected:
                length += 1
                run_ts.append(gpa_first_ts[gpa])
            elif gpa > expected and (gpa - expected) // c.PAGE_SIZE <= GAP_TOL:
                gap = int((gpa - expected) // c.PAGE_SIZE)
                length += gap + 1
                run_ts.append(gpa_first_ts[gpa])
            else:
                runs.append((base, length, min(run_ts) - t0))
                base, length = gpa, 1
                run_ts = [gpa_first_ts[gpa]]
        runs.append((base, length, min(run_ts) - t0))

        # Spatio-Temporal Metrics
        earliest_ns = min(gpa_first_ts.values()) - t0
        earliest_ms = earliest_ns / 1e6
        total_writes = len(fault_list)
        unique_pages = len(gpa_first_ts)
        rewrite_ratio = total_writes / max(unique_pages, 1)

        # Filter out OS / GPU ring buffers (extreme high-frequency spinlocks)
        if rewrite_ratio > 150.0 and total_writes > 100:
            scores[blk] = (100, total_writes, 1, earliest_ns)
            block_run_bases[blk] = [(sorted_gpas[0], 1, earliest_ns)]
            continue

        # Block score: Prioritize contiguous tensor allocation slabs and early arrival
        earliest_ms = (earliest_ns - (t0 or 0)) / 1e6
        max_run = max(r[1] for r in runs)
        # Clean composite scoring: Max run length + unique pages + arrival time weight
        score = (max_run * 2000.0) + (unique_pages * 1000.0) + (500000.0 / (1.0 + earliest_ms / 100.0))
        scores[blk] = (int(score), total_writes, max_run, earliest_ns)

        # Order candidate run targets: prioritize true PyTorch allocation slabs (longest runs first)
        sorted_runs = sorted(runs, key=lambda r: (-r[1], r[2]))
        seen = set()
        unique_bases = []
        for g, l, t in sorted_runs:
            if g not in seen:
                seen.add(g)
                unique_bases.append((g, l, t))
        block_run_bases[blk] = unique_bases

    return scores, block_run_bases, page_ts_by_block


def run_stage2_online(index: int, top_k: int = 40, max_new_tokens: int = 60,
                      output_dir: Optional[Path] = None,
                      active_arena_anchor: Optional[int] = None) -> Dict[str, Any]:
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
         "--duration", "120", "--settle", str(c.TRACKER_SETTLE_S),
         "--rearm-ms", str(c.TRACKER_REARM_MS)],
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

    return process_tracked_log(index, str(log_path), gt, top_k, out_dir, active_arena_anchor=active_arena_anchor)


def process_tracked_log(index: int, host_log_path: str, gt: Optional[Dict[str, Any]],
                        top_k: int = 40, out_dir: Optional[Path] = None,
                        start_offset: int = 0, rank_mode: str = "score",
                        active_arena_anchor: Optional[int] = None) -> Dict[str, Any]:
    out_dir = out_dir or c.PIPELINE_DIR
    out_json = out_dir / f"stage2_tracked_{index}.json"

    scores, block_run_bases, page_ts_by_block = score_blocks_from_log(host_log_path, start_offset=start_offset)
    if not scores and start_offset > 0:
        # Fallback to recent log slice if exact offset had 0 faults
        fallback_offset = max(0, start_offset - 10 * 1024 * 1024)
        scores, block_run_bases, page_ts_by_block = score_blocks_from_log(host_log_path, start_offset=fallback_offset)

    # Apply dynamic session arena affinity boost if active_arena_anchor is known
    final_scores = {}
    for b, (s, h, r, ets) in scores.items():
        if active_arena_anchor is not None:
            dist_mb = abs(b - active_arena_anchor) / (1024 * 1024)
            if dist_mb <= 8:
                loc_boost = 10.0
            elif dist_mb <= 32:
                loc_boost = 4.0
            elif dist_mb <= 64:
                loc_boost = 2.0
            else:
                loc_boost = 1.0
        else:
            loc_boost = 1.0
        final_scores[b] = (int(s * loc_boost), h, r, ets)
    scores = final_scores

    # Rank candidate blocks: Prioritize user-space tensor arena (GPA >= 0x180000000, 6GB+)
    # above OS/GPU-driver scratch regions (<6GB), then rank by score.
    if rank_mode == "score":
        ranked = sorted(scores.keys(), key=lambda b: (
            0 if (c.TRACK_START <= b < c.TRACK_START + c.TRACK_SIZE) else 1,
            -scores[b][0]
        ))
    else:
        ranked = sorted(scores.keys(), key=lambda b: (
            0 if (c.TRACK_START <= b < c.TRACK_START + c.TRACK_SIZE) else 1,
            scores[b][3],
            -scores[b][0]
        ))

    gt_dict = gt or {}
    gt_base = gt_dict.get("base")
    gt_blk = block_base_gpa(gt_base) if gt_base else None
    gt_rank = (ranked.index(gt_blk) + 1) if (gt_blk and gt_blk in ranked) else None

    top_candidates = ranked[:top_k]
    candidate_details = {
        hex(b): {
            "score": scores[b][0],
            "hits": scores[b][1],
            "max_run": scores[b][2],
            "earliest_ts": scores[b][3],
        } for b in top_candidates
    }
    # Export runs for the top candidates AND the ground-truth block, so the
    # non-blind "known-block" scan (Phase K) can restrict its swaps to the gt
    # block's WRITTEN pages even when that block ranks outside top_k. (Blind
    # localization never reads these gt-block runs, so this is not GT leakage.)
    export_blocks = list(top_candidates)
    if gt_blk is not None and gt_blk not in export_blocks:
        export_blocks.append(gt_blk)
    candidate_run_bases = {
        hex(b): [hex(g) for g, _, _ in block_run_bases.get(b, [])[:200]]
        for b in export_blocks
    }
    # Run-aware localization also needs each run's LENGTH and start ts (earliest
    # first), so the locator can scan the span the run covers and the pages just
    # before it — image_pad usually sits off run_start. [[start_hex, run_len], ...]
    # [[start_hex, run_len, run_start_ts_rel], ...] — ts lets the known-block scan
    # visit LATEST-written pages first (input_ids is written late; validated:
    # median 2 swaps to the input page that way vs ~110 earliest-first).
    candidate_runs = {
        hex(b): [[hex(g), int(l), int(t)] for g, l, t in block_run_bases.get(b, [])[:200]]
        for b in export_blocks
    }
    # Per-PAGE first-write ts, LATEST first — the known-block scan (Phase K) walks
    # this so it reaches the input_ids page in ~2 swaps (validated). Per-page ts,
    # not per-run ts: the input page can sit inside a long early-started run.
    candidate_page_ts = {
        hex(b): [[hex(g), int(ts)] for g, ts in
                 sorted(page_ts_by_block.get(b, {}).items(), key=lambda kv: -kv[1])]
        for b in export_blocks
    }

    print(f"[Stage 2] {len(scores)} 2MB blocks scored (rank_mode={rank_mode}). Top candidates:")
    for rank, b in enumerate(top_candidates[:10], 1):
        s, h, r, ets = scores[b]
        is_gt = " (GT MATCH)" if b == gt_blk else ""
        run_gpas_str = ", ".join([hex(g) for g, _, _ in block_run_bases.get(b, [])[:3]])
        print(f"  #{rank:<2d} 0x{b:011x}  t0+{ets/1e6:>8.1f}ms  score={s:>8,d}  max_run={r:>3d}p  run_bases=[{run_gpas_str}]{is_gt}")

    if gt_base:
        print(f"[Stage 2] Ground Truth base=0x{gt_base:x} (Block 0x{gt_blk:x}) Rank: #{gt_rank or 'NOT_IN_TOP'}")

    result = {
        "index": index,
        "host_log": str(host_log_path),
        "total_scored_blocks": len(scores),
        "candidate_blocks": [hex(b) for b in top_candidates],
        "candidate_details": candidate_details,
        "candidate_run_bases": candidate_run_bases,
        "candidate_runs": candidate_runs,
        "candidate_page_ts": candidate_page_ts,
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
    p.add_argument("--top-k", type=int, default=40, help="Number of candidate 2MB blocks to rank")
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
