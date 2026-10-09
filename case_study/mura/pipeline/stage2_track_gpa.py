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
from collections import defaultdict
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

# Envelope of a real channel burst, measured across the tracked runs:
# 49 consecutive writes, nothing interleaved, 131-248us span, <=7.5us between writes.
BURST_MAX_SPAN_US     = 300.0
BURST_MAX_GAP_US      = 10.0
BURST_TOP_K           = 10
BURST_CLUSTER_OVERLAP = 40
BURST_SLIDE_BACK      = 12      # measured slips ran -2 to -9 writes
BURST_SLIDE_FWD       = 4


def _page_runs(pages: List[int]) -> int:
    """Number of maximal physically-contiguous runs in a page set."""
    u = sorted(set(pages))
    n = 1
    for a, b in zip(u, u[1:]):
        if b - a != c.PAGE_SIZE:
            n += 1
    return n


def find_burst_candidates(writes: List[Tuple[int, int]], n_pages: Optional[int] = None,
                          top_k: int = BURST_TOP_K) -> List[Dict]:
    """Candidate channel buffers, found as bursts of consecutive tracked writes.

    The guest materialises the channel with one memcpy, so its pages land as
    exactly n_pages consecutive writes with nothing interleaved. Scanning
    consecutive-write windows — instead of grouping every write in a 2MB block —
    keeps scattered regions that merely share a block out of the candidate set.

    Windows one slot apart share n_pages-1 pages, so near-duplicates are collapsed
    and only distinct buffers are returned, ranked by page-run fragmentation.
    Pages stay in observed order, which is the tensor order.
    """
    n = n_pages or c.IMG_PAGES
    filt = [(g, ts) for g, ts in writes
            if not (c.BLIND_A_LO <= g < c.BLIND_A_HI or c.BLIND_B_LO <= g < c.BLIND_B_HI)]

    wins = []
    for k in range(len(filt) - n + 1):
        w = filt[k:k + n]
        pages = [g for g, _ in w]
        if len(set(pages)) != n:
            continue
        ts = [t for _, t in w]
        span = (ts[-1] - ts[0]) / 1000.0
        gap = max(b - a for a, b in zip(ts, ts[1:])) / 1000.0
        if span > BURST_MAX_SPAN_US or gap > BURST_MAX_GAP_US:
            continue
        # Windows come out a few writes late — a duplicate page near the burst start
        # pushes the first accepted window past it — so carry the surrounding stream
        # and let Stage 3 slide onto the true start using probe hits.
        lo = max(0, k - BURST_SLIDE_BACK)
        hi = min(len(filt), k + n + BURST_SLIDE_FWD)
        wins.append({'pages': pages, 'set': set(pages), 'runs': _page_runs(pages),
                     'span_us': span, 'max_gap_us': gap,
                     'ctx': [g for g, _ in filt[lo:hi]], 'ctx_off': k - lo})

    wins.sort(key=lambda x: (x['runs'], x['span_us']))

    reps: List[Dict] = []
    for w in wins:
        if all(len(w['set'] & r['set']) < BURST_CLUSTER_OVERLAP for r in reps):
            reps.append(w)
            if len(reps) >= top_k:
                break

    out = []
    for w in reps:
        blocks = sorted({g & ~(c.BLIND_ALIGN_2MB - 1) for g in w['pages']})
        out.append({
            'total_pages': len(w['pages']),
            'channel_pages': w['pages'],
            'num_blocks': len(blocks),
            'blocks': [hex(b) for b in blocks],
            'is_stitched': len(blocks) > 1,
            'runs': w['runs'],
            'span_us': round(w['span_us'], 1),
            'max_gap_us': round(w['max_gap_us'], 1),
            'dt_ms': round(w['span_us'] / 1000.0, 4),
            'ctx': w['ctx'],
            'ctx_off': w['ctx_off'],
        })
    return out


BLOCK_LEAD_LOOK = 60      # how far into the block stream to look for the burst start


def find_burst_in_blocks(writes: List[Tuple[int, int]], blocks, 
                         n_pages: Optional[int] = None,
                         top_k: int = BURST_TOP_K) -> List[Dict]:
    """Windows of n_pages consecutive writes inside the given 2MB block(s).

    With the block known, the channel burst is no longer buried in unrelated
    traffic: inside its own block it starts after a long pause (measured 68-436us
    against 3-19us between its own writes) and runs to the end of the block's
    activity. Ranking start positions by that leading gap recovered 46.4/49 pages
    on average, with no dictionary involved, where whole-stream shape rules
    managed 9.3.
    """
    n = n_pages or c.IMG_PAGES
    blocks = set(blocks)
    F = [(g, ts) for g, ts in writes if (g & ~(c.BLIND_ALIGN_2MB - 1)) in blocks]
    if len(F) < n:
        return []

    starts = [(F[k][1] - F[k - 1][1], k)
              for k in range(1, min(BLOCK_LEAD_LOOK, len(F) - n + 1))]
    starts.sort(reverse=True)
    ordered = [k for _, k in starts]
    if 0 not in ordered:
        ordered.append(0)      # the burst can begin at the block's first write

    out = []
    for k in ordered[:top_k]:
        pages = [g for g, _ in F[k:k + n]]
        if len(set(pages)) != n:
            continue
        ts = [t for _, t in F[k:k + n]]
        blks = sorted({g & ~(c.BLIND_ALIGN_2MB - 1) for g in pages})
        out.append({
            'total_pages': len(pages),
            'channel_pages': pages,
            'num_blocks': len(blks),
            'blocks': [hex(b) for b in blks],
            'is_stitched': len(blks) > 1,
            'runs': _page_runs(pages),
            'span_us': round((ts[-1] - ts[0]) / 1000.0, 1),
            'max_gap_us': round(max(b - a for a, b in zip(ts, ts[1:])) / 1000.0, 1),
            'lead_gap_us': round((F[k][1] - F[k - 1][1]) / 1000.0, 1) if k else None,
            'start_in_block': k,
            'dt_ms': round((ts[-1] - ts[0]) / 1e6, 4),
        })
    return out


def acquire_guest_mura_live(index: int, study_type: Optional[str] = None,
                             wait_for_host: bool = True,
                             ready_callback=None, split: str = "valid") -> Tuple[str, str, List[int], Optional[subprocess.Popen]]:
    """
    Spawn live MURA guest loader holding real dataset tensor in memory.
    If ready_callback is provided, it is invoked when GUEST_READY_FOR_TRACK is received.
    """
    class_flag = f"--class_name {study_type}" if study_type else ""
    wait_flag = "--wait_for_host" if wait_for_host else ""
    cmd = (
        f"sudo {c.GUEST_PY} -u ~/cc_uvm/pytorch_uvm310_test/mura/guest_mura_loader.py "
        f"--index {index} --split {split} {class_flag} {wait_flag}"
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
    Contiguous Run Detection & Temporal Multi-Block Stitching for MURA Tensors:
    1. Filter out Region A & Region B (kernel network & TLS crypto buffers).
    2. Group writes by 2MB physical block (strict block locality).
    3. Detect contiguous runs per block (gap_tol <= 2, min_run >= 2).
    4. Stitch temporally adjacent runs between neighbouring (+/- 2MB) blocks within 2ms.
    5. Rank candidate channels by quadratic run score: sum(len^2) and max_run.
    """
    by_block = defaultdict(list)
    # The tensor is written by a memcpy that sweeps virtual addresses in order, so
    # the order the tracker observed each page IS the tensor page order. Physical
    # order is not: a 49-page buffer can straddle blocks whose GPAs run backwards.
    # Keep a global first-seen index and order every candidate by it.
    order_idx = {}
    for k, (gpa, ts) in enumerate(writes):
        if c.BLIND_A_LO <= gpa < c.BLIND_A_HI or c.BLIND_B_LO <= gpa < c.BLIND_B_HI:
            continue
        order_idx.setdefault(gpa, k)
        blk = gpa & ~(c.BLIND_ALIGN_2MB - 1)
        by_block[blk].append((gpa, ts))

    block_runs = {}
    for blk, b_writes in by_block.items():
        runs = []
        cur_base, cur_len, cur_ts_start, cur_ts_end, cur_dir = 0, 0, 0, 0, 0
        cur_pages = []

        for gpa, ts in b_writes:
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
                    if cur_len >= c.BLIND_MIN_RUN:
                        runs.append({
                            'base': cur_base, 'len': cur_len,
                            'ts_start': cur_ts_start, 'ts_end': cur_ts_end,
                            'pages': list(cur_pages), 'block': blk, 'dir': cur_dir
                        })
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
                    if cur_len >= c.BLIND_MIN_RUN:
                        runs.append({
                            'base': cur_base, 'len': cur_len,
                            'ts_start': cur_ts_start, 'ts_end': cur_ts_end,
                            'pages': list(cur_pages), 'block': blk, 'dir': cur_dir
                        })
                    cur_base, cur_len, cur_ts_start, cur_ts_end, cur_dir = gpa, 1, ts, ts, 0
                    cur_pages = [gpa]
        if cur_len >= c.BLIND_MIN_RUN:
            runs.append({
                'base': cur_base, 'len': cur_len,
                'ts_start': cur_ts_start, 'ts_end': cur_ts_end,
                'pages': list(cur_pages), 'block': blk, 'dir': cur_dir
            })
        if runs:
            block_runs[blk] = runs

    candidates = []
    seen_block_sets = set()

    for blk, runs in block_runs.items():
        # Single-block candidate
        all_pages_single = []
        for r in runs:
            all_pages_single.extend(r['pages'])
        uniq_pages_single = sorted(set(all_pages_single), key=lambda p: order_idx[p])

        score_single = sum(r['len']**2 for r in runs)
        max_run_single = max(r['len'] for r in runs)

        candidates.append({
            'total_pages': min(len(uniq_pages_single), c.IMG_PAGES),
            'channel_pages': uniq_pages_single[:c.IMG_PAGES],
            'num_blocks': 1,
            'blocks': [hex(blk)],
            'is_stitched': False,
            'score': score_single,
            'max_run': max_run_single,
            'dt_ms': (runs[-1]['ts_end'] - runs[0]['ts_start']) / 1e6,
        })

        # Check adjacent blocks (+/- 2MB) within 2ms
        for adj_blk in [blk + c.BLIND_ALIGN_2MB, blk - c.BLIND_ALIGN_2MB]:
            if adj_blk in block_runs:
                adj_runs = block_runs[adj_blk]
                dt1 = abs(adj_runs[0]['ts_start'] - runs[-1]['ts_end'])
                dt2 = abs(runs[0]['ts_start'] - adj_runs[-1]['ts_end'])
                if dt1 <= 2_000_000 or dt2 <= 2_000_000:
                    bset = frozenset([blk, adj_blk])
                    if bset not in seen_block_sets:
                        seen_block_sets.add(bset)
                        combined_runs = runs + adj_runs
                        comb_pages = []
                        for r in combined_runs:
                            comb_pages.extend(r['pages'])
                        uniq_comb = sorted(set(comb_pages), key=lambda p: order_idx[p])
                        comb_score = sum(r['len']**2 for r in combined_runs)
                        comb_max_run = max(r['len'] for r in combined_runs)
                        candidates.append({
                            'total_pages': min(len(uniq_comb), c.IMG_PAGES),
                            'channel_pages': uniq_comb[:c.IMG_PAGES],
                            'num_blocks': 2,
                            'blocks': [hex(min(blk, adj_blk)), hex(max(blk, adj_blk))],
                            'is_stitched': True,
                            'score': comb_score,
                            'max_run': comb_max_run,
                            'dt_ms': (max(r['ts_end'] for r in combined_runs) - min(r['ts_start'] for r in combined_runs)) / 1e6,
                        })

    # Filter out low-confidence noise candidates
    filtered = [cand for cand in candidates if cand['max_run'] >= 8 and cand['total_pages'] >= 16]
    if not filtered and candidates:
        filtered = [cand for cand in candidates if cand['max_run'] >= 5 and cand['total_pages'] >= 10]

    # Rank by quadratic run score, then max_run, then total_pages
    filtered.sort(key=lambda x: (x['score'], x['max_run'], x['total_pages']), reverse=True)
    return filtered


def track_mura_blind(index: int, output_dir: Path, study_type: Optional[str] = None,
                     settle: int = 1, duration: int = 60, split: str = "valid"):
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
        
        deadline = time.time() + settle + 5
        while time.time() < deadline:
            time.sleep(0.1)
            if dbg_path.exists() and "Settle done" in dbg_path.read_text(errors="ignore"):
                break
        print(f"[stage2] [blind] Tracker fully settled. Triggering guest tensor writes...")

    target_class, img_path, gt_pages, guest_proc = acquire_guest_mura_live(
        index, study_type=study_type, wait_for_host=True,
        ready_callback=on_guest_ready, split=split
    )

    # Let in-flight write events drain
    time.sleep(1.0)

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
    candidates = find_burst_candidates(writes)
    if candidates:
        print(f"[stage2] [blind] Found {len(candidates)} distinct burst candidate(s) "
              f"(best: {candidates[0]['runs']} run(s), {candidates[0]['span_us']}us)")
    else:
        candidates = stitch_temporal_runs(writes)
        print(f"[stage2] [blind] No burst matched the envelope; "
              f"fell back to block stitching ({len(candidates)} candidate(s))")
    return target_class, img_path, gt_pages, candidates, guest_proc, writes


def _count_guest_loaders() -> int:
    """Guest-side loader processes still waiting. They leak one per sample if the
    release flag never lands, and a backlog degrades the write burst long before
    anything else shows it."""
    out = c.ssh_run("pgrep -fc guest_mura_loader").strip()
    try:
        return int(out.splitlines()[0])
    except (ValueError, IndexError):
        return -1


def run_stage2(index: int, output_dir: Path, blind: bool = False,
               study_type: Optional[str] = None, host_log_override: Optional[str] = None,
               block_from_guest: bool = False, release_guest: bool = False,
               split: str = "valid") -> Dict:
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
        candidates = find_burst_candidates(writes) or stitch_temporal_runs(writes)
        target_class = study_type or "ELBOW"
        img_path = ""
        gt_pages = []
        guest_proc = None
        blind_detected = len(candidates) > 0
    elif blind:
        target_class, img_path, gt_pages, candidates, guest_proc, writes = track_mura_blind(
            index, output_dir, study_type=study_type, split=split
        )
        # The guest names the 2MB block(s) its tensor lives in; searching only those
        # turns a needle-in-2500-writes problem into picking a start inside ~150.
        if block_from_guest and gt_pages:
            blocks = {g & ~(c.BLIND_ALIGN_2MB - 1) for g in gt_pages}
            scoped = find_burst_in_blocks(writes, blocks)
            if scoped:
                candidates = scoped
                print(f"[stage2] [block] Restricted to {len(blocks)} block(s) "
                      f"{sorted(hex(b) for b in blocks)} -> {len(candidates)} candidate(s), "
                      f"best starts at write {candidates[0]['start_in_block']} "
                      f"after a {candidates[0]['lead_gap_us']}us pause")
            else:
                print(f"[stage2] [block] No {c.IMG_PAGES}-write window inside the "
                      f"guest's block(s); keeping the blind candidates")
        blind_detected = len(candidates) > 0
    else:
        target_class, img_path, gt_pages, guest_proc = acquire_guest_mura_live(
            index, study_type=study_type, wait_for_host=False, split=split
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
    elif not blind and gt_pages and len(gt_pages) == c.IMG_PAGES:
        selected_pages = gt_pages
        is_stitched = False
        num_blocks = 1
        blocks = [hex(selected_pages[0] & ~(c.BLIND_ALIGN_2MB - 1))]
        print(f"[stage2] Using verified Ground Truth GPA sequence ({len(selected_pages)} pages)")
    else:
        if blind:
            print(f"[stage2] [blind] No valid channel candidate captured by write tracker (0 pages captured).")
            selected_pages = []
            is_stitched = False
            num_blocks = 0
            blocks = []
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
        "block_from_guest": bool(block_from_guest and gt_pages),
        "split": split,
        # Stage 3 probes these against the ref dictionary to pick the real buffer.
        "candidates": [
            dict(
                [(k, v) for k, v in cand.items() if k != "channel_pages"],
                channel_pages_hex=[hex(p) for p in cand["channel_pages"]],
                channel_pages_int=cand["channel_pages"],
            )
            for cand in candidates[:BURST_TOP_K]
        ],
        "timestamp": time.time(),
    }
    # Offline accuracy check: only meaningful when the guest reported its GPAs.
    if gt_pages:
        gset = set(gt_pages)
        meta["gt_overlap"] = len(gset & set(selected_pages))
        meta["gt_exact_order"] = sum(1 for a, b in zip(selected_pages, gt_pages) if a == b)
        meta["gt_best_candidate_overlap"] = max(
            (len(gset & set(x["channel_pages"])) for x in candidates), default=0)
        print(f"[stage2] [gt] selected {meta['gt_overlap']}/{len(gt_pages)} pages "
              f"(order {meta['gt_exact_order']}/{len(gt_pages)}), "
              f"best candidate has {meta['gt_best_candidate_overlap']}")
    c.save_json(json_path, meta)
    print(f"[stage2] Saved tracking metadata → {json_path}")

    # The guest loader blocks on /tmp/host_read_done so its tensor stays live for
    # Stage 3's swaps. When Stage 3 will not run, nothing else releases it, and the
    # loaders pile up one per sample until the guest thrashes and the write burst
    # stops being clean — which is what turned a 95.8% run into 59.3%.
    if release_guest:
        # The loader clears a stale flag before it starts waiting, so touch it in a
        # short loop: a single fire-and-forget touch can land in that window and be
        # deleted, leaving the loader stuck forever.
        for _ in range(3):
            c.ssh_run("touch /tmp/host_read_done")
            time.sleep(0.4)
            if "0" == c.ssh_run("test -e /tmp/host_read_done; echo $?").strip()[:1]:
                continue
            break
        meta["guest_loaders"] = _count_guest_loaders()
        print(f"[stage2] Released the guest loader "
              f"({meta['guest_loaders']} loader(s) alive on the guest)")
        c.save_json(json_path, meta)
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="MURA study / sample index")
    p.add_argument("--blind", action="store_true", help="Perform live blind tracking")
    p.add_argument("--class-name", default=None, help="Optional class name filter (e.g. ELBOW, HAND)")
    p.add_argument("--split", default="valid", choices=["train", "valid"],
                   help="MURA split the index refers to")
    p.add_argument("--keep-guest", action="store_true",
                   help="Leave the guest loader waiting (only if Stage 3 will run next)")
    p.add_argument("--block-from-guest", action="store_true",
                   help="Search only the 2MB block(s) the guest reports its tensor in")
    p.add_argument("--host-log", default=None, help="Optional offline host log file to parse")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save metadata")
    args = p.parse_args()

    run_stage2(args.index, Path(args.output_dir), blind=args.blind,
               study_type=args.class_name, host_log_override=args.host_log,
               block_from_guest=args.block_from_guest,
               release_guest=not args.keep_guest, split=args.split)


if __name__ == "__main__":
    main()
