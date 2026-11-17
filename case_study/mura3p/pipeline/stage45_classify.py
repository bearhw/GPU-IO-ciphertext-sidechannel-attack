#!/usr/bin/env python3
"""
stage45_classify.py — Stage 4 (3-plane cipher map) + Stage 5 (MURA body part).

Stage 4: every dumped block vs the 192 ref dumps -> blind base offset
(estimate_base_off: the right shift puts R/G/B-keyword hits inside the R/G/B
planes) -> (3,224,56) map of level index per plane.

Fusion: MURA is grayscale (R=G=B pixels), so level k at block (r,c) in ANY plane
means the pixel block is level k. fused[k,r,c] = OR_p (map[p,r,c] == k) gives
MURA's (64,224,56) input; a plane lost to a 2 MB boundary or a missed run is
covered by the other two. The R-plane-only slice (what MURA's original pipeline
sees) is classified too, for the comparison.

  python3 stage45_classify.py --index 0 --output-dir DIR [--model CKPT]
"""
import argparse
import sys
import time
from pathlib import Path

import numpy as np
import torch

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c
import m3_map as sm
from mura_model import XorSliceSENet

DEFAULT_MODEL = c.CASE_STUDY_DIR / "mura" / "pipeline" / "mura_attack_64ref_blind_ff.pth"
_MODEL = {}


def model(path=DEFAULT_MODEL):
    path = str(path)
    if path not in _MODEL:
        m = XorSliceSENet(len(c.CLASSES), n_ref=c.NUM_REFS)
        m.load_state_dict(torch.load(path, map_location="cpu", weights_only=True), strict=True)
        m.eval()
        _MODEL[path] = m
    return _MODEL[path]


def fuse(m: np.ndarray, planes=(0, 1, 2)) -> np.ndarray:
    xs = np.zeros((c.NUM_REFS, c.MAP_ROWS, c.MAP_COLS), bool)
    for p in planes:
        hit = m[p] >= 0
        r, col = np.nonzero(hit)
        xs[m[p][hit], r, col] = True
    return xs


def classify(xs: np.ndarray, model_path=DEFAULT_MODEL) -> np.ndarray:
    with torch.no_grad():
        x = torch.from_numpy(xs.astype(np.float32))[None]
        return torch.softmax(model(model_path)(x, torch.ones(1, 1)), 1)[0].numpy()


def run_stage45(index: int, out: Path, model_path=DEFAULT_MODEL):
    t0 = time.time()
    tr = c.load_json(out / f"tracked_{index}.json")
    d = c.load_json(out / f"dump_{index}.json")
    hits = sm.dump_hits(d["dumps"], sm.load_ref_pages())
    off = sm.estimate_base_off(hits)
    m, good, bad = sm.map_from_hits(hits, off)
    xs, xr = fuse(m), fuse(m, (0,))
    np.savez_compressed(out / f"map_{index}.npz", map=m, fused=xs)
    t4 = time.time() - t0
    prob, prob_r = classify(xs, model_path), classify(xr, model_path)
    order = np.argsort(-prob)
    pred, pred_r = c.CLASSES[order[0]], c.CLASSES[int(prob_r.argmax())]
    fused_cov = float((xs.any(0)).mean())
    meta = {"stage": 5, "index": index, "target_class": tr["target_class"], "pred": pred,
            "correct": pred == tr["target_class"], "pred_r_only": pred_r,
            "correct_r_only": pred_r == tr["target_class"],
            "top3": [(c.CLASSES[k], round(float(prob[k]), 4)) for k in order[:3]],
            "base_off_est": off, "base_off_gt": tr.get("gt_base_off"),
            "hits_consistent": good, "hits_inconsistent": bad,
            "coverage": [round(float((m[p] >= 0).mean()), 4) for p in range(3)],
            "fused_coverage": round(fused_cov, 4),
            "t_stage4": round(t4, 2), "t_stage5": round(time.time() - t0 - t4, 2),
            "timestamp": time.time()}
    c.save_json(out / f"result_{index}.json", meta)
    print(f"[stage5] #{index} gt={tr['target_class']} pred={pred} {'OK' if meta['correct'] else 'X'} "
          f"(R-only {pred_r}) base_off est/gt={off}/{tr.get('gt_base_off')} "
          f"cov={meta['coverage']} fused={meta['fused_coverage']}")
    return meta


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--index", type=int, default=0)
    p.add_argument("--model", default=str(DEFAULT_MODEL))
    p.add_argument("--output-dir", required=True)
    a = p.parse_args()
    run_stage45(a.index, Path(a.output_dir), a.model)


if __name__ == "__main__":
    main()
