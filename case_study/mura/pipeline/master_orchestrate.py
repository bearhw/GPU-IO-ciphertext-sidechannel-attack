#!/usr/bin/env python3
"""
master_orchestrate.py — Master Orchestrator for MURA End-to-End Attack Pipeline.

Coordinates the complete 5-stage modular pipeline:
  Stage 1: Reference Dictionary & Fixed GPA Management (stage1_ref_dict.py)
  Stage 2: Target 49-Page GPA Tracking & Multi-Block Stitching (stage2_track_gpa.py)
  Stage 3: PSP 49-Page Sequential Collision Swap & Dump (stage3_swap_dump.py)
  Stage 4: 64-Ref XOR Feature Extraction (stage4_extract_features.py)
  Stage 5: XorSliceSENetV3 Classification, 2D Reconstruction & Metrics (stage5_reconstruct.py)

Usage:
    # Run full pipeline for sample 0 (blind mode)
    sudo python3 master_orchestrate.py --index 0 --blind

    # Run specific stages (e.g. Stage 4 to 5)
    python3 master_orchestrate.py --from-stage 4 --to-stage 5 --index 0

    # Batch mode over multiple studies
    sudo python3 master_orchestrate.py --start 0 --end 5 --blind
"""

import argparse
import os
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

import common as c
import stage1_ref_dict as s1
import stage2_track_gpa as s2
import stage3_swap_dump as s3
import stage4_extract_features as s4
import stage5_reconstruct as s5


def orchestrate_single(index: int, output_dir: Path, from_stage: int = 1,
                       to_stage: int = 5, blind: bool = False,
                       class_name: Optional[str] = None, rebuild_dict: bool = False,
                       mock: bool = False, host_log: Optional[str] = None,
                       ab_gt: bool = False, probe: bool = False,
                       slide: bool = False, block_from_guest: bool = False,
                       split: str = "valid") -> Dict:
    """Execute stages for a single MURA index."""
    print(f"\n{'='*74}")
    print(f"  [MURA E2E Orchestrator] Study Index {index} (Stages {from_stage} -> {to_stage})")
    print(f"{'='*74}\n")

    output_dir.mkdir(parents=True, exist_ok=True)
    summary: Dict = {"index": index, "status": "ok"}
    t_start = time.time()

    # Stage 1: Ref Dictionary
    if from_stage <= 1 <= to_stage:
        print("\n--- [Stage 1: Reference Dictionary & Fixed GPA] ---")
        meta1 = s1.run_stage1(output_dir, rebuild=rebuild_dict)
        summary["stage1"] = meta1

    # Stage 2: Track & Multi-Block Stitching
    if from_stage <= 2 <= to_stage:
        print("\n--- [Stage 2: Target 49-Page Tracking & Stitching] ---")
        meta2 = s2.run_stage2(index, output_dir, blind=blind,
                              study_type=class_name, host_log_override=host_log,
                              block_from_guest=block_from_guest,
                              release_guest=(to_stage < 3), split=split)
        summary["stage2"] = meta2

    # Stage 3: PSP Collision Swap & Dump
    if from_stage <= 3 <= to_stage:
        print("\n--- [Stage 3: PSP 49-Page Collision Swap & Dump] ---")
        meta3 = s3.run_stage3(index, output_dir, mock=mock, ab_gt=ab_gt, probe=probe, slide=slide)
        summary["stage3"] = meta3

    # Stage 4: Feature Extraction
    if from_stage <= 4 <= to_stage:
        print("\n--- [Stage 4: 64-Ref XOR Feature Extraction] ---")
        meta4 = s4.run_stage4(index, output_dir, mock=mock)
        summary["stage4"] = meta4

    # Stage 5: Classification & Reconstruction
    if from_stage <= 5 <= to_stage:
        print("\n--- [Stage 5: Classification & Captured Pages Summary] ---")
        meta5 = s5.run_stage5(index, output_dir, mock=mock)
        summary["stage5"] = meta5

    elapsed = time.time() - t_start
    summary["elapsed_sec"] = round(elapsed, 2)
    
    # Auto-log to pipeline_summary.csv
    append_summary_csv(summary, output_dir / "pipeline_summary.csv")
    return summary


def append_summary_csv(summary: Dict, csv_path: Path):
    """Append execution result to pipeline_summary.csv."""
    import csv
    from datetime import datetime

    idx = summary.get("index", 0)
    s5_res = summary.get("stage5", {})
    s3_res = summary.get("stage3", {})
    s2_res = summary.get("stage2", {})

    gt_label = s5_res.get("target_class", s2_res.get("target_class", "-"))
    pred_label = s5_res.get("predicted_class", "-")
    is_correct = s5_res.get("is_correct", False)

    cap_cnt = s5_res.get("captured_pages_count", s3_res.get("successful_pages", s2_res.get("total_pages", 0)))
    cap_str = f"{cap_cnt}/{c.IMG_PAGES}"
    cap_pct = f"{cap_cnt / max(1, c.IMG_PAGES) * 100:.1f}%"
    succ_ge36 = (cap_cnt >= 36)

    top3 = s5_res.get("top3", [])
    c1 = top3[0]["class"] if len(top3) > 0 else "-"
    c1_p = f"{top3[0]['prob']*100:.1f}%" if len(top3) > 0 else "-"
    c2 = top3[1]["class"] if len(top3) > 1 else "-"
    c2_p = f"{top3[1]['prob']*100:.1f}%" if len(top3) > 1 else "-"
    c3 = top3[2]["class"] if len(top3) > 2 else "-"
    c3_p = f"{top3[2]['prob']*100:.1f}%" if len(top3) > 2 else "-"

    # Page recovery is the result being measured; classification columns stay for
    # runs that include Stage 5 but are empty when the pipeline stops at Stage 3.
    # Stage 3 measures what was actually dumped; without it, fall back to Stage 2 so
    # a tracking-only run (no dictionary, no PSP swaps) still records recovery.
    gt_ov = s3_res.get("gt_overlap", s2_res.get("gt_overlap"))
    gt_ord = s3_res.get("gt_exact_order", s2_res.get("gt_exact_order"))
    gt_best = s2_res.get("gt_best_candidate_overlap")
    gt_n = s3_res.get("gt_pages") or (len(s2_res.get("gt_pages_int") or []) or c.IMG_PAGES)
    slide = (s3_res.get("slide") or {})
    recovered_pct = f"{gt_ov / max(gt_n, 1) * 100:.1f}%" if gt_ov is not None else "-"

    headers = [
        "date", "split", "index", "gt_label",
        "gt_overlap", "gt_best_cand", "gt_pages", "recovered_pct", "gt_exact_order",
        "slide_from", "slide_to", "probe_choice",
        "pred_label", "is_correct",
        "captured_pages", "capture_fraction_pct", "success_rate_ge36",
        "conf1", "conf2", "conf3",
        "conf1_percent", "conf2_percent", "conf3_percent",
        "elapsed_sec"
    ]
    
    # Appending under a header from an older column set silently shifts every
    # field, and the numbers still parse as numbers. Rotate instead.
    file_exists = csv_path.exists()
    if file_exists:
        with open(csv_path) as f:
            existing = (f.readline().strip().split(",") if f else [])
        if existing and existing != headers:
            archived = csv_path.with_name(
                f"{csv_path.stem}.{datetime.now().strftime('%Y%m%d-%H%M%S')}.csv")
            csv_path.rename(archived)
            print(f"[csv] column set changed — previous rows archived to {archived.name}")
            file_exists = False

    with open(csv_path, "a", newline="") as f:
        writer = csv.writer(f)
        if not file_exists:
            writer.writerow(headers)
        writer.writerow([
            datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
            s2_res.get("split", "valid"), idx, gt_label,
            "-" if gt_ov is None else gt_ov,
            "-" if gt_best is None else gt_best, gt_n, recovered_pct,
            "-" if gt_ord is None else gt_ord,
            slide.get("from", "-"), slide.get("to", "-"),
            s3_res.get("probe_choice", "-"),
            pred_label, is_correct,
            cap_str, cap_pct, succ_ge36,
            c1, c2, c3,
            c1_p, c2_p, c3_p,
            summary.get("elapsed_sec", 0.0)
        ])


def print_summary_table(results: List[Dict]):
    """Print formatted summary table with Top-3 predictions and confidences, captured pages, and stitching status."""
    print("\n" + "=" * 106)
    print("  MURA END-TO-END ATTACK & CLASSIFICATION SUMMARY")
    print("=" * 106)
    print(f"{'Index':<7}{'Target GT':<12}{'Top-3 Predictions (Conf %)':<58}{'Captured Pages':<18}{'Stitched':<10}")
    print("-" * 106)
    for r in results:
        idx = r.get("index", "-")
        s5_res = r.get("stage5", {})
        s3_res = r.get("stage3", {})
        s2_res = r.get("stage2", {})

        # Persistent metadata fallbacks
        if not s2_res and idx != "-":
            tr_file = HERE / f"tracked_mura_{idx}.json"
            if tr_file.exists():
                s2_res = c.load_json(tr_file)
        if not s3_res and idx != "-":
            sw_file = HERE / f"swap_meta_{idx}.json"
            if sw_file.exists():
                s3_res = c.load_json(sw_file)

        target = s5_res.get("target_class", s2_res.get("target_class", "-"))

        top3_list = s5_res.get("top3", [])
        if top3_list:
            top3_str = ", ".join(f"{i+1}. {item['class']} ({item['prob']*100:.1f}%)" for i, item in enumerate(top3_list))
        else:
            pred = s5_res.get("predicted_class", "-")
            conf = f"{s5_res.get('confidence', 0.0)*100:.1f}%" if "confidence" in s5_res else "-"
            top3_str = f"1. {pred} ({conf})"

        # Captured pages (1 channel = 49 pages)
        cap_str = s5_res.get("captured_pages", "-")
        if cap_str == "-":
            succ = s3_res.get("successful_pages", s2_res.get("total_pages", 0))
            cap_str = f"{succ}/{c.IMG_PAGES} ({succ/c.IMG_PAGES*100:.1f}%)" if c.IMG_PAGES > 0 else f"{succ}"
        else:
            cnt = s5_res.get("captured_pages_count", 0)
            cap_str = f"{cap_str} ({cnt/c.IMG_PAGES*100:.1f}%)"

        stitched = "YES" if s2_res.get("is_stitched") else "NO"

        print(f"{idx:<7}{target:<12}{top3_str:<58}{cap_str:<18}{stitched:<10}")
    print("=" * 106 + "\n")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="Single MURA study index")
    p.add_argument("--indices", default=None,
                   help="Comma-separated indices to run, in this order "
                        "(overrides --start/--end; lets a batch interleave classes)")
    p.add_argument("--start", type=int, default=None, help="Batch start index (inclusive)")
    p.add_argument("--end", type=int, default=None, help="Batch end index (exclusive)")
    p.add_argument("--stage", type=int, choices=[1, 2, 3, 4, 5], default=None, help="Run only specific stage")
    p.add_argument("--from-stage", type=int, default=1, help="Starting stage (1-5)")
    p.add_argument("--to-stage", type=int, default=5, help="Ending stage (1-5)")
    p.add_argument("--blind", action="store_true", help="Perform blind write tracking in Stage 2")
    p.add_argument("--class-name", default=None, help="Optional target class name filter (e.g. ELBOW, HAND)")
    p.add_argument("--host-log", default=None, help="Optional offline host log for Stage 2")
    p.add_argument("--rebuild-dict", action="store_true", help="Rebuild ref dictionary in Stage 1")
    p.add_argument("--mock", action="store_true", help="Run with mock data (testing)")
    p.add_argument("--ab-gt", action="store_true",
                   help="Stage 3: also dump guest-reported GT pages and compare match scores")
    p.add_argument("--max-loaders", type=int, default=6,
                   help="Stop if this many guest loader processes are still alive")
    p.add_argument("--max-dict-dead", type=int, default=5,
                   help="Stop after this many consecutive samples where no candidate "
                        "matched any reference (a dead dictionary, not a missed burst)")
    p.add_argument("--max-dead", type=int, default=5,
                   help="Stop a batch after this many consecutive zero-page captures")
    p.add_argument("--split", default="valid", choices=["train", "valid"],
                   help="MURA split the indices refer to")
    p.add_argument("--block-from-guest", action="store_true",
                   help="Stage 2: search only the 2MB block(s) the guest reports")
    p.add_argument("--slide", action="store_true",
                   help="Stage 3: walk the window back onto the burst start (REGRESSES recovery)")
    p.add_argument("--probe", action="store_true",
                   help="Stage 3: pick among Stage 2 candidates by dictionary matches (UNVALIDATED)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save artifacts")
    args = p.parse_args()

    from_st = args.stage if args.stage is not None else args.from_stage
    to_st   = args.stage if args.stage is not None else args.to_stage

    out_dir = Path(args.output_dir)

    results = []
    # An explicit list lets a batch interleave classes; train_image_paths.csv is
    # ordered by class, so a contiguous range only ever yields one of them.
    todo = ([int(x) for x in args.indices.split(",")] if args.indices
            else list(range(args.start, args.end))
            if (args.start is not None and args.end is not None) else None)
    if todo:
        dead = dead_dict = 0
        for idx in todo:
            if idx != todo[0]:
                # The PSP queue does not drain between samples at 3s; the guest
                # died after roughly 1,700 cumulative swaps. Give it longer.
                cooldown = float(os.environ.get("MURA_SAMPLE_COOLDOWN", "30.0"))
                print(f"\n[batch] Inter-sample PSP cooldown ({cooldown}s)...")
                time.sleep(cooldown)
            res = orchestrate_single(
                idx, out_dir, from_stage=from_st, to_stage=to_st,
                blind=args.blind, class_name=args.class_name,
                rebuild_dict=args.rebuild_dict, mock=args.mock, host_log=args.host_log,
                ab_gt=args.ab_gt, probe=args.probe, slide=args.slide,
                block_from_guest=args.block_from_guest, split=args.split)
            results.append(res)
            # Loaders that never exit pile up until the guest thrashes and every
            # later sample is noise, so stop while the numbers still mean something.
            loaders = (res.get("stage2") or {}).get("guest_loaders", 0)
            if loaders and loaders > args.max_loaders:
                print(f"\n[batch] {loaders} guest loader(s) still alive at index {idx} — "
                      f"they are not being released. Kill them on the guest "
                      f"('pkill -f guest_mura_loader') before resuming with --start {idx}.",
                      file=sys.stderr)
                break
            # Every candidate scoring zero also happens when tracking simply missed
            # the burst, which is common, so one occurrence proves nothing. Only a
            # run of them points at a dictionary that no longer matches the guest.
            if (res.get("stage3") or {}).get("dict_dead"):
                dead_dict += 1
                if dead_dict >= args.max_dict_dead:
                    print(f"\n[batch] {dead_dict} consecutive samples matched no reference "
                          f"at index {idx} — rebuild the dictionary "
                          f"('stage1_ref_dict.py --rebuild') and resume with --start {idx}.",
                          file=sys.stderr)
                    break
            else:
                dead_dict = 0
            # A dead guest yields zero tracked pages forever; without this the run
            # keeps going and fills the CSV with rows that mean nothing.
            if (res.get("stage2") or {}).get("total_pages", 0) == 0:
                dead += 1
                if dead >= args.max_dead:
                    print(f"\n[batch] {dead} consecutive samples captured 0 pages — "
                          f"guest is probably down. Stopping at index {idx}.", file=sys.stderr)
                    break
            else:
                dead = 0
    else:
        res = orchestrate_single(
            args.index, out_dir, from_stage=from_st, to_stage=to_st,
            blind=args.blind, class_name=args.class_name,
            rebuild_dict=args.rebuild_dict, mock=args.mock, host_log=args.host_log,
            ab_gt=args.ab_gt, probe=args.probe, slide=args.slide,
                block_from_guest=args.block_from_guest, split=args.split)
        results.append(res)

    print_summary_table(results)


if __name__ == "__main__":
    main()
