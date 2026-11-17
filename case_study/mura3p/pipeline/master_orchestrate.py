#!/usr/bin/env python3
"""
master_orchestrate.py — MURA 3-plane end-to-end: Stage 2 -> 3 -> 4/5 per sample.

  sudo python3 master_orchestrate.py --split test --indices 0-19 --gt   # known address
  sudo python3 master_orchestrate.py --split test --indices 0-999 --gpu # blind e2e

Stage 1 (dictionary) runs separately (stage1_ref_dict.py) once per guest boot.
Each sample appends a row to <output-dir>/summary.csv; existing rows are skipped.
"""
import argparse
import csv
import sys
import time
import traceback
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import stage2_track as s2
import stage3_dump as s3
import stage45_classify as s45

FIELDS = ["date", "split", "index", "mode", "gpu", "gt_class", "gpu_pred", "pred", "correct",
          "top3", "n_cands", "probe_choice", "gt_overlap", "gt_pages", "dumped",
          "base_off_est", "base_off_gt", "coverage", "fused_coverage", "img", "t_stage2", "t_localize", "t_dump",
          "t_stage45", "elapsed_sec", "error"]


def parse_indices(s: str):
    out = []
    for part in s.split(","):
        if "-" in part:
            a, b = part.split("-")
            out += range(int(a), int(b) + 1)
        else:
            out.append(int(part))
    return out


def done_set(path: Path):
    if not path.exists():
        return set()
    return {int(r["index"]) for r in csv.DictReader(open(path)) if not r.get("error")}


def run_one(index, split, out, gt, gpu, model):
    t0 = time.time()
    row = {"date": time.strftime("%Y-%m-%d %H:%M:%S"), "split": split, "index": index,
           "mode": "gt" if gt else "blind", "gpu": gpu, "error": ""}
    try:
        m2 = s2.run_stage2(index, out, split, gpu)
        row.update(gt_class=m2["target_class"], gpu_pred=m2.get("gpu_pred"), img=m2.get("img"),
                   n_cands=len(m2["candidates"]), t_stage2=m2["t_stage2"])
        m3 = s3.run_stage3(index, out, gt)
        row.update(probe_choice=m3["probe_choice"], gt_overlap=m3["gt_overlap"],
                   gt_pages=m3["gt_pages"], dumped=m3["dumped"],
                   t_localize=m3["t_localize"], t_dump=m3["t_dump"])
        m5 = s45.run_stage45(index, out, model)
        row.update(pred=m5["pred"], correct=m5["correct"], top3=m5["top3"],
                   base_off_est=m5["base_off_est"], base_off_gt=m5["base_off_gt"],
                   coverage=m5["coverage"], fused_coverage=m5["fused_coverage"], t_stage45=m5["t_stage4"] + m5["t_stage5"])
    except Exception as e:
        traceback.print_exc()
        row["error"] = repr(e)[:200]
    finally:
        s2.release_guest()
    row["elapsed_sec"] = round(time.time() - t0, 2)
    return row


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--split", default="valid", choices=["valid", "train"])
    p.add_argument("--indices", required=True)
    p.add_argument("--gt", action="store_true", help="dump guest-reported pages (known address)")
    p.add_argument("--gpu", action="store_true", help="victim runs ResNet-18 on the CC GPU")
    p.add_argument("--model", default=str(s45.DEFAULT_MODEL))
    p.add_argument("--output-dir", default=None)
    a = p.parse_args()
    out = Path(a.output_dir or HERE.parent / "captures" / f"{a.split}_{'gt' if a.gt else 'blind'}")
    out.mkdir(parents=True, exist_ok=True)
    csv_path = out / "summary.csv"
    skip = done_set(csv_path)
    n_ok = n = 0
    for idx in parse_indices(a.indices):
        if idx in skip:
            continue
        row = run_one(idx, a.split, out, a.gt, a.gpu, a.model)
        new = not csv_path.exists()
        with open(csv_path, "a", newline="") as f:
            w = csv.DictWriter(f, fieldnames=FIELDS)
            if new:
                w.writeheader()
            w.writerow(row)
        if not row["error"]:
            n += 1
            n_ok += bool(row.get("correct"))
        print(f"[master] #{idx} {row.get('gt_class')} -> {row.get('pred')}  "
              f"running top-1 {n_ok}/{n}  ({row['elapsed_sec']}s)", flush=True)


if __name__ == "__main__":
    main()
