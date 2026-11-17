#!/usr/bin/env python3
"""capture_campaign.py — Capture a train or eval set end-to-end for v10 retraining.

Each bs=512 blind capture dumps one 2MB block = 512 images and writes
    <out>/results/sparsities_*_bs512_idx{start}-{end}.npy   (real captured sparsity)
Train and eval captures go to SEPARATE output dirs so the trainer (CAPTURE_DIR) and
the test step never mix them, and so train uses the MNIST train split while eval uses
the test split (which no reconstruction model ever saw).

Batch index N (bs=512) covers images [N*512 : N*512+512] of the chosen split:
  - train split: 60000 images -> batches 0..116
  - test  split: 10000 images -> batches 0..18  (batch 19 would overflow)

Requires a live guest (runs the full blind pipeline via master_orchestrate.py).

Usage:
  sudo python3 capture_campaign.py --split train --start 0 --end 40
  sudo python3 capture_campaign.py --split eval  --start 0 --end 18
  sudo python3 capture_campaign.py --split eval  --start 0 --end 18 --redo   # ignore cache
"""

import argparse
import os
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

# split name -> (guest/GT MNIST split, default output dir, max batch index)
SPLITS = {
    "train": ("train", HERE / "output_train", 116),
    "eval":  ("test",  HERE / "output_eval",  18),
}


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--split", required=True, choices=["train", "eval"],
                   help="train -> MNIST train split, eval -> MNIST test split")
    p.add_argument("--start", type=int, default=0, help="First batch index (inclusive)")
    p.add_argument("--end", type=int, required=True, help="Last batch index (inclusive)")
    p.add_argument("--output-dir", default=None, help="Override default per-split output dir")
    p.add_argument("--duration", type=int, default=None, help="Blind tracker duration (s)")
    p.add_argument("--top-n", type=int, default=None, help="Blind top-N candidates")
    p.add_argument("--redo", action="store_true",
                   help="Recapture even batches that already have metrics (no --skip-existing)")
    args = p.parse_args()

    mnist_split, default_out, max_batch = SPLITS[args.split]
    out_dir = Path(args.output_dir) if args.output_dir else default_out

    if args.end > max_batch:
        sys.exit(f"[campaign] --end {args.end} exceeds the {mnist_split} split: "
                 f"max full bs=512 batch is {max_batch} "
                 f"({(max_batch + 1) * 512} images).")
    if args.start < 0 or args.start > args.end:
        sys.exit(f"[campaign] bad range {args.start}..{args.end}")

    out_dir.mkdir(parents=True, exist_ok=True)

    cmd = [
        "python3", str(HERE / "master_orchestrate.py"),
        "--blind", "--batch-size", "512",
        "--start", str(args.start), "--end", str(args.end),
        "--output-dir", str(out_dir),
    ]
    if not args.redo:
        cmd.append("--skip-existing")
    if args.duration is not None:
        cmd += ["--duration", str(args.duration)]
    if args.top_n is not None:
        cmd += ["--top-n", str(args.top_n)]

    env = dict(os.environ)
    env["MNIST_SPLIT"] = mnist_split   # forwarded to guest (stage2) AND host GT (stage5)

    print(f"[campaign] split={args.split} (MNIST {mnist_split}) "
          f"batches {args.start}..{args.end}  ({(args.end - args.start + 1)} blocks, "
          f"{(args.end - args.start + 1) * 512} images)")
    print(f"[campaign] output -> {out_dir}")
    print(f"[campaign] sparsity arrays land in {out_dir / 'results'}/sparsities_*_bs512_idx*.npy")
    print(f"[campaign] $ MNIST_SPLIT={mnist_split} " + " ".join(cmd))
    print("-" * 70, flush=True)

    rc = subprocess.call(cmd, env=env)
    if rc != 0:
        sys.exit(f"[campaign] master_orchestrate exited with {rc}")

    npys = sorted((out_dir / "results").glob("sparsities_*_bs512_idx*.npy"))
    print("-" * 70)
    print(f"[campaign] done. {len(npys)} sparsity array(s) now in {out_dir / 'results'}")
    if args.split == "train":
        print(f"[campaign] NEXT: retrain with  CAPTURE_DIR={out_dir / 'results'} "
              f"MNIST_SPLIT=train  (see retrain_v10.sh)")
    else:
        print(f"[campaign] NEXT: test with  python3 run_test.py --eval-dir {out_dir}")


if __name__ == "__main__":
    main()
