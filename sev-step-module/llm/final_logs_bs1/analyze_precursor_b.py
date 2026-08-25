#!/usr/bin/env python3
"""
Precursor-B gating analysis for bs1 LLM runs.
For LLM: input_ids CPU write → H2D DMA → BURST_B fires (B is postcursor).
Gate: collect WRITE blocks in window [ts_B - WINDOW_NS, ts_B] for each B episode.
Score: S(b) = H(b) * R(b) on 2MB blocks.
Compare with ungated S(b)=H*R.
"""
import re, sys, os
from collections import defaultdict

DIR   = os.path.dirname(os.path.abspath(__file__))
PAGE  = 0x1000
BLOCK = 0x200000
RUNS  = [1, 2]
TOP_N = 12

# Pre-B window: WRITEs that arrive up to WINDOW_NS before each B episode
WINDOW_NS   = 50_000_000   # 50ms  (adjust if needed)
B_GAP_NS    = 200_000_000  # 200ms gap → new B episode

RE_W   = re.compile(r'^WRITE  gpa=0x([0-9a-f]+)\s+ts=(\d+)')
RE_B   = re.compile(r'^BURST_B.*?ts=(\d+)')
RE_IDS = re.compile(r'\[GPA_RUN\] batch(\d+)/input/input_ids: 0x([0-9a-f]+) len=(\d+)')


def blk(gpa):
    return (gpa // BLOCK) * BLOCK


def load_host(run):
    """Returns sorted list of (ts, page) for WRITEs and sorted list of ts for BURST_B."""
    writes, bursts = [], []
    with open(f"{DIR}/host_run{run}.log") as f:
        for l in f:
            m = RE_W.match(l)
            if m:
                writes.append((int(m.group(2)), int(m.group(1), 16) & ~(PAGE-1)))
                continue
            m = RE_B.match(l)
            if m:
                bursts.append(int(m.group(1)))
    writes.sort()
    bursts.sort()
    return writes, bursts


def cluster_bursts(bursts):
    """Cluster consecutive BURST_B events → return list of episode-start timestamps."""
    if not bursts:
        return []
    episodes = [bursts[0]]
    for ts in bursts[1:]:
        if ts - episodes[-1] > B_GAP_NS:
            episodes.append(ts)
    return episodes


def score_ungated(writes):
    """Standard S(b)=H*R on full WRITE stream (contiguous ascending runs ≥4 pages)."""
    block_runs = defaultdict(list)
    if not writes:
        return {}
    cur_blk  = blk(writes[0][1])
    cur_len  = 1
    cur_prev = writes[0][1]
    for _, gpa in writes[1:]:
        b = blk(gpa)
        if b == blk(cur_prev) and gpa == cur_prev + PAGE:
            cur_len += 1
            cur_prev = gpa
        else:
            if cur_len >= 4:
                block_runs[cur_blk].append(cur_len)
            cur_blk  = b
            cur_len  = 1
            cur_prev = gpa
    if cur_len >= 4:
        block_runs[cur_blk].append(cur_len)
    return {b: (len(r)*max(r), len(r), max(r)) for b, r in block_runs.items()}


def score_bgated(writes, episodes):
    """
    For each B episode, collect WRITEs in [ts_ep - WINDOW_NS, ts_ep].
    Accumulate: per block, count episodes where it appears (H),
    track max consecutive run length in any window (R).
    S = H * R.
    """
    # Build index: ts-sorted writes for fast window query
    ts_arr  = [w[0] for w in writes]
    gpa_arr = [w[1] for w in writes]

    blk_episodes = defaultdict(set)   # block -> set of episode indices
    blk_maxR     = defaultdict(int)   # block -> max run length seen

    import bisect
    for ep_idx, ep_ts in enumerate(episodes):
        lo = bisect.bisect_left(ts_arr,  ep_ts - WINDOW_NS)
        hi = bisect.bisect_right(ts_arr, ep_ts)
        if hi <= lo:
            continue
        window_gpas = sorted(gpa_arr[lo:hi])
        # score runs within this window
        if not window_gpas:
            continue
        cur_b   = blk(window_gpas[0])
        cur_len = 1
        cur_prv = window_gpas[0]
        for gpa in window_gpas[1:]:
            b = blk(gpa)
            if b == blk(cur_prv) and gpa == cur_prv + PAGE:
                cur_len += 1
                cur_prv = gpa
            else:
                if cur_len >= 2:
                    blk_episodes[cur_b].add(ep_idx)
                    blk_maxR[cur_b] = max(blk_maxR[cur_b], cur_len)
                cur_b   = b
                cur_len = 1
                cur_prv = gpa
        if cur_len >= 2:
            blk_episodes[cur_b].add(ep_idx)
            blk_maxR[cur_b] = max(blk_maxR[cur_b], cur_len)

    scores = {}
    for b in blk_episodes:
        H = len(blk_episodes[b])
        R = blk_maxR[b]
        scores[b] = (H * R, H, R)
    return scores


def load_gt(run):
    gt = set()
    with open(f"{DIR}/guest_run{run}.log") as f:
        for l in f:
            m = RE_IDS.search(l)
            if m:
                base = int(m.group(2), 16) & ~(PAGE-1)
                for i in range(int(m.group(3))):
                    gt.add(blk(base + i*PAGE))
    return gt


def rank_of_gt(scores, gt):
    top = sorted(scores, key=lambda b: -scores[b][0])
    for i, b in enumerate(top):
        if b in gt:
            return i+1, b, scores[b]
    return None, None, None


for run in RUNS:
    print(f"\n{'='*60}")
    print(f"  Run {run}")
    print(f"{'='*60}")

    writes, bursts = load_host(run)
    episodes = cluster_bursts(bursts)
    gt = load_gt(run)

    print(f"  WRITEs: {len(writes):,}  BURST_B: {len(bursts):,}  "
          f"B-episodes: {len(episodes):,}  GT blocks: {len(gt)}")

    # ── Ungated ──────────────────────────────────────────────────────────────
    ug = score_ungated(writes)
    ug_top = sorted(ug, key=lambda b: -ug[b][0])[:TOP_N]
    ug_rank, ug_blk, ug_tup = rank_of_gt(ug, gt)

    print(f"\n  [Ungated S(b)=H×R]  window=all  threshold≥4p")
    print(f"  {'Rank':<5} {'Block':>10}  {'S':>10}  {'H':>6}  {'R':>6}  {'GT?'}")
    for i, b in enumerate(ug_top):
        S, H, R = ug[b]
        flag = "<-- GT (input_ids)" if b in gt else ""
        print(f"  #{i+1:<4} 0x{b>>21:04x}       {S:>10,}  {H:>6}  {R:>6}p  {flag}")

    # ── B-gated ──────────────────────────────────────────────────────────────
    bg = score_bgated(writes, episodes)
    bg_top = sorted(bg, key=lambda b: -bg[b][0])[:TOP_N]
    bg_rank, bg_blk, bg_tup = rank_of_gt(bg, gt)

    print(f"\n  [B-gated S(b)=H×R]  window={WINDOW_NS//1_000_000}ms before each B episode")
    print(f"  {'Rank':<5} {'Block':>10}  {'S':>10}  {'H':>6}  {'R':>6}  {'GT?'}")
    for i, b in enumerate(bg_top):
        S, H, R = bg[b]
        flag = "<-- GT (input_ids)" if b in gt else ""
        print(f"  #{i+1:<4} 0x{b>>21:04x}       {S:>10,}  {H:>6}  {R:>6}p  {flag}")

    # ── Summary ───────────────────────────────────────────────────────────────
    print(f"\n  Summary:")
    if ug_rank:
        print(f"    Ungated  → input_ids rank #{ug_rank}  "
              f"block=0x{ug_blk>>21:04x}  S={ug_tup[0]:,}  H={ug_tup[1]}  R={ug_tup[2]}p")
    else:
        print(f"    Ungated  → input_ids NOT in top-{TOP_N}")
    if bg_rank:
        print(f"    B-gated  → input_ids rank #{bg_rank}  "
              f"block=0x{bg_blk>>21:04x}  S={bg_tup[0]:,}  H={bg_tup[1]}  R={bg_tup[2]}p")
    else:
        print(f"    B-gated  → input_ids NOT in top-{TOP_N}")
