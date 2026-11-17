#!/usr/bin/env python3
"""run_test.py — Score the (retrained) models on the eval captures and report mean±std.

Guest-free. For each eval batch captured by
    sudo python3 capture_campaign.py --split eval ...
it re-runs Stage 5 (reconstruction + SSIM) from the saved sparsity array using the
CURRENT model weights, then aggregates across batches:
  - per-batch mean SSIM -> mean ± std over batches  (localization/capture spread)
  - pooled per-image SSIM over every image          (the headline eval number, large n)

GT comes from the MNIST test split (MNIST_SPLIT=test), which no model was trained on.

Usage:
  python3 run_test.py                         # reconstruct with current weights, then report
  python3 run_test.py --no-recon              # just aggregate existing metrics
  python3 run_test.py --eval-dir output_eval
"""

import argparse
import json
import os
import re
import subprocess
import sys
from pathlib import Path
from statistics import mean, pstdev

HERE = Path(__file__).resolve().parent
MODELS = ["v6r (Retrieval)", "v9r (UNet-GAN)", "v10 (Decoder)"]


def batch_indices(results_dir: Path):
    """Batch indices present as sparsity arrays, from idx{start}-{end} in the name."""
    idxs = set()
    for f in results_dir.glob("sparsities_*_bs512_idx*.npy"):
        m = re.search(r"_idx(\d+)-(\d+)", f.name)
        if m:
            idxs.add(int(m.group(1)) // 512)
    return sorted(idxs)


def latest_metrics_per_batch(results_dir: Path):
    """Newest metrics_*bs512* json per idx-range (one reconstruction run per batch)."""
    best = {}
    for f in results_dir.glob("metrics_*bs512*idx*.json"):
        m = re.search(r"idx(\d+)-(\d+)", f.name)
        if not m:
            continue
        key = m.group(0)
        if key not in best or f.stat().st_mtime > best[key].stat().st_mtime:
            best[key] = f
    return [best[k] for k in sorted(best)]


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--eval-dir", default=str(HERE / "output_eval"))
    p.add_argument("--no-recon", action="store_true",
                   help="Skip Stage 5; aggregate the metrics already on disk")
    args = p.parse_args()

    eval_dir = Path(args.eval_dir)
    results_dir = eval_dir / "results"
    if not results_dir.is_dir():
        sys.exit(f"[test] {results_dir} not found — run capture_campaign.py --split eval first.")

    idxs = batch_indices(results_dir)
    if not idxs:
        sys.exit(f"[test] no sparsities_*_bs512_idx*.npy in {results_dir} — capture eval first.")
    print(f"[test] {len(idxs)} eval batch(es): {idxs}")

    if not args.no_recon:
        env = dict(os.environ)
        env["MNIST_SPLIT"] = "test"                     # GT from the unseen test split
        for i in idxs:
            cmd = ["python3", str(HERE / "master_orchestrate.py"),
                   "--from-stage", "5", "--to-stage", "5",
                   "--index", str(i), "--batch-size", "512",
                   "--output-dir", str(eval_dir)]
            print(f"[test] reconstruct batch {i}: $ MNIST_SPLIT=test " + " ".join(cmd), flush=True)
            rc = subprocess.call(cmd, env=env)
            if rc != 0:
                print(f"[test] [!] batch {i} stage5 exited {rc}", file=sys.stderr)

    # ── aggregate ────────────────────────────────────────────────────────────
    files = latest_metrics_per_batch(results_dir)
    if not files:
        sys.exit("[test] no metrics json to aggregate.")

    per_batch = {m: [] for m in MODELS}      # one mean-SSIM per batch
    pooled = {m: [] for m in MODELS}         # every per-image SSIM
    n_images = 0
    for f in files:
        d = json.loads(f.read_text())
        sm = d.get("summary_metrics", {})
        for m in MODELS:
            if m in sm and sm[m].get("ssim") is not None:
                per_batch[m].append(float(sm[m]["ssim"]))
        pir = d.get("per_image_results", [])
        n_images += len(pir)
        for row in pir:
            s = row.get("ssim", {})
            for key, m in (("v6r", MODELS[0]), ("v9r", MODELS[1]), ("v10", MODELS[2])):
                if isinstance(s, dict) and s.get(key) is not None:
                    pooled[m].append(float(s[key]))

    print("\n" + "=" * 68)
    print(f"EVAL SSIM  |  {len(files)} batches  |  {n_images} images (test split, unseen)")
    print("=" * 68)
    print(f"{'model':<18}{'per-batch mean±std':<26}{'pooled per-image mean':<22}")
    print("-" * 68)
    for m in MODELS:
        pb, pl = per_batch[m], pooled[m]
        pb_s = f"{mean(pb):.4f} ± {pstdev(pb):.4f}" if pb else "—"
        pl_s = f"{mean(pl):.4f}  (n={len(pl)})" if pl else "—"
        print(f"{m:<18}{pb_s:<26}{pl_s:<22}")
    print("=" * 68)
    print("per-batch std = capture/localization spread across blocks; "
          "pooled = headline number.")


if __name__ == "__main__":
    main()
