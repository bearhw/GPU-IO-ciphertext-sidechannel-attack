#!/usr/bin/env python3
"""timing_harness.py — Per-stage timing study for the MNIST blind e2e attack.

Runs the blind bs=512 pipeline for N batches, timing every stage (wall clock
around each stage call) and also reading the stages' self-reported times
(dict_build_time_sec, total_swap_time_sec, ciphermap_build_time_sec). Reports
mean and median per stage across the successful batches.

Six reported timings (per the attack-cost breakdown):
  dict_build   stage1  zero-page acquisition + dump (MNIST's "dictionary")
  track_rank   stage2  write tracking + 2MB block ranking
  page_dump    stage3  PSP swap dump of the batch pages
  ciphermap    stage4  XOR vs z.out -> 196-bit model input per image
  recon        stage5  model reconstruction + SSIM
  per_sample   total   stage2..5 wall time for the batch (/512 for per-image)

Usage:
  MNIST_SPLIT=test python3 timing_harness.py --n 20 --batch-size 512 \
      --out /abs/output_timing
"""
import argparse
import json
import os
import statistics as st
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c
import stage1_zero_gpa as s1
import stage2_track_gpa as s2
import stage3_swap_dump as s3
import stage4_extract_features as s4
import stage5_reconstruct as s5


def _release(proc):
    if not proc:
        return
    try:
        proc.stdin.close()
        proc.wait(timeout=10)
    except Exception:
        try:
            proc.kill()
        except Exception:
            pass


def run_batch(index, out_dir, batch_size, duration, top_n, zero_meta):
    """Mirror master.process_sample, timing each stage. Returns a dict row."""
    row = {"index": index, "ok": False}
    guest_proc = None
    try:
        t = time.time()
        meta2, guest_proc = s2.run_stage2(
            index, out_dir, blind=True, batch_size=batch_size,
            hold_guest=True, duration=duration, top_n=top_n)
        row["track_rank"] = time.time() - t
        row["track_rank_self"] = meta2.get("track_rank_time_sec")
        row["blind_detected"] = meta2.get("blind_detected")

        t = time.time()
        meta3 = s3.run_stage3(
            index, out_dir,
            image_gpa=meta2.get("image_gpa_int"),
            page2_gpa=meta2.get("page2_gpa_int"),
            zero_gpa=zero_meta.get("zero_gpa_int") if zero_meta else None,
            label=meta2.get("label"), batch_size=batch_size)
        row["page_dump"] = time.time() - t
        row["page_dump_self"] = meta3.get("total_swap_time_sec")

        _release(guest_proc); guest_proc = None

        t = time.time()
        meta4 = s4.run_stage4(
            index, out_dir, pixel_offset=meta2.get("pixel_offset"),
            label=meta2.get("label"), json_path=None,
            batch_size=batch_size, clean_dumps=True)
        row["ciphermap"] = time.time() - t
        row["ciphermap_self"] = meta4.get("ciphermap_build_time_sec")

        t = time.time()
        meta5 = s5.run_stage5(index, out_dir, sparsity=meta4.get("sparsity"),
                              label=meta4.get("label") or meta2.get("label"),
                              batch_size=batch_size)
        row["recon"] = time.time() - t
        row["recon_self"] = meta5.get("recon_time_sec")

        row["per_sample"] = (row["track_rank"] + row["page_dump"]
                             + row["ciphermap"] + row["recon"])
        row["ok"] = True
    except Exception as e:
        row["error"] = f"{type(e).__name__}: {e}"
    finally:
        _release(guest_proc)
    return row


def summarize(rows, keys):
    good = [r for r in rows if r.get("ok")]
    out = {}
    for k in keys:
        vals = [r[k] for r in good if isinstance(r.get(k), (int, float))]
        if vals:
            out[k] = {
                "mean": round(st.mean(vals), 4),
                "median": round(st.median(vals), 4),
                "stdev": round(st.pstdev(vals), 4) if len(vals) > 1 else 0.0,
                "min": round(min(vals), 4),
                "max": round(max(vals), 4),
                "n": len(vals),
            }
    return out


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--n", type=int, default=20, help="Number of batches")
    p.add_argument("--start", type=int, default=0, help="First batch index")
    p.add_argument("--batch-size", type=int, default=512)
    p.add_argument("--duration", type=int, default=c.DEFAULT_TRACKER_DURATION)
    p.add_argument("--top-n", type=int, default=5)
    p.add_argument("--dict-runs", type=int, default=20,
                   help="Force stage1 this many times for dict-build stats")
    p.add_argument("--out", default=str(HERE / "output_timing"))
    args = p.parse_args()

    out_dir = Path(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)
    print(f"[timing] out={out_dir} split={os.environ.get('MNIST_SPLIT','test')} "
          f"bs={args.batch_size} n={args.n}")

    # ── Dictionary building (stage1): force-refresh repeatedly ───────────────
    dict_times = []
    for j in range(args.dict_runs):
        try:
            m = s1.run_stage1(out_dir, force_refresh=True)
            dt = m.get("dict_build_time_sec")
            if dt is not None:
                dict_times.append(dt)
            print(f"[timing] dict build {j+1}/{args.dict_runs}: {dt}s")
        except Exception as e:
            print(f"[timing] dict build {j+1} failed: {e}")
    zero_meta = s1.run_stage1(out_dir)  # cached, for the pipeline below

    # ── Per-batch pipeline timing ────────────────────────────────────────────
    rows = []
    for i in range(args.start, args.start + args.n):
        print(f"\n{'#'*60}\n[timing] batch {i} ({len(rows)+1}/{args.n})\n{'#'*60}")
        r = run_batch(i, out_dir, args.batch_size, args.duration,
                      args.top_n, zero_meta)
        print(f"[timing] batch {i}: ok={r['ok']} "
              + ("".join(f"{k}={r.get(k):.2f} " for k in
                 ("track_rank", "page_dump", "ciphermap", "recon", "per_sample")
                 if isinstance(r.get(k), (int, float)))
                 or r.get("error", "")))
        rows.append(r)
        # checkpoint after every batch
        _save(out_dir, args, dict_times, rows)

    _save(out_dir, args, dict_times, rows, final=True)


def _save(out_dir, args, dict_times, rows, final=False):
    keys = ["track_rank", "track_rank_self", "page_dump", "page_dump_self",
            "ciphermap", "ciphermap_self", "recon", "recon_self", "per_sample"]
    summary = summarize(rows, keys)
    if dict_times:
        summary["dict_build"] = {
            "mean": round(st.mean(dict_times), 4),
            "median": round(st.median(dict_times), 4),
            "stdev": round(st.pstdev(dict_times), 4) if len(dict_times) > 1 else 0.0,
            "min": round(min(dict_times), 4), "max": round(max(dict_times), 4),
            "n": len(dict_times),
        }
    doc = {
        "batch_size": args.batch_size,
        "n_requested": args.n,
        "n_ok": sum(1 for r in rows if r.get("ok")),
        "split": os.environ.get("MNIST_SPLIT", "test"),
        "summary": summary,
        "rows": rows,
        "dict_times": dict_times,
        "timestamp": time.time(),
    }
    (out_dir / "timing_summary.json").write_text(json.dumps(doc, indent=2))
    if final:
        print("\n" + "=" * 64)
        print(f"TIMING SUMMARY  (bs={args.batch_size}, "
              f"{doc['n_ok']}/{args.n} batches ok)")
        print("=" * 64)
        order = ["dict_build", "track_rank", "page_dump", "ciphermap",
                 "recon", "per_sample"]
        label = {"dict_build": "Dictionary building (s1)",
                 "track_rank": "Write track + block rank (s2)",
                 "page_dump": "Page dump (s3)",
                 "ciphermap": "Ciphermap / model input (s4)",
                 "recon": "Reconstruction + SSIM (s5)",
                 "per_sample": "Per-batch total (s2..5)"}
        print(f"{'stage':<34}{'mean':>9}{'median':>9}{'stdev':>8}{'n':>4}")
        print("-" * 64)
        for k in order:
            s = summary.get(k)
            if s:
                print(f"{label[k]:<34}{s['mean']:>9.3f}{s['median']:>9.3f}"
                      f"{s['stdev']:>8.3f}{s['n']:>4}")
        ps = summary.get("per_sample")
        if ps:
            print("-" * 64)
            print(f"{'Per-image (total/'+str(args.batch_size)+')':<34}"
                  f"{ps['mean']/args.batch_size:>9.4f}"
                  f"{ps['median']/args.batch_size:>9.4f}")
        print(f"\nsaved → {out_dir / 'timing_summary.json'}")


if __name__ == "__main__":
    main()
