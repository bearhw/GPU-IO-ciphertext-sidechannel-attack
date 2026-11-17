#!/usr/bin/env python3
"""
stage45_classify.py — Stage 4 (cipher map) + Stage 5 (shape classification).

Stage 4 compares every dumped block with the 48 ref dumps, estimates the tensor's
base offset blindly (estimate_base_off), and places hits into a (3,224,56) map.
Stage 5 runs the attack classifier (offline/train_attack.py ShapeNet).

  python3 stage45_classify.py --index 0 [--model ../offline/attack_shapes_sim.pth]
"""
import argparse
import sys
import time
from pathlib import Path

import numpy as np
import torch

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parent / "offline"))
import common as c
import shapes_map as sm

DEFAULT_MODEL = HERE.parent / "offline" / "attack_shapes_sim_v2.pth"
_MODEL = None


def model(path=DEFAULT_MODEL):
    global _MODEL
    if _MODEL is None:
        from train_attack import ShapeNet
        _MODEL = ShapeNet()
        _MODEL.load_state_dict(torch.load(path, map_location="cpu"))
        _MODEL.eval()
    return _MODEL


def run_stage45(index: int, out: Path, model_path=DEFAULT_MODEL):
    from train_attack import to_tensor
    t0 = time.time()
    tr = c.load_json(out / f"tracked_{index}.json")
    d = c.load_json(out / f"dump_{index}.json")
    hits = sm.dump_hits(d["dumps"], sm.load_ref_pages())
    off = sm.estimate_base_off(hits)
    m, good, bad = sm.map_from_hits(hits, off)
    np.save(out / f"cmap_{index}.npy", (m + 1).astype(np.uint8))
    t4 = time.time() - t0
    with torch.no_grad():
        prob = torch.softmax(model(model_path)(to_tensor((m + 1).astype(np.uint8)[None])), 1)[0].numpy()
    order = np.argsort(-prob)
    pred = c.CLASSES[order[0]]
    meta = {"stage": 5, "index": index, "target_class": tr["target_class"], "pred": pred,
            "correct": pred == tr["target_class"],
            "top3": [(c.CLASSES[k], round(float(prob[k]), 4)) for k in order[:3]],
            "base_off_est": off, "base_off_gt": tr.get("gt_base_off"),
            "hits_consistent": good, "hits_inconsistent": bad,
            "coverage": [round(float((m[p] >= 0).mean()), 4) for p in range(3)],
            "t_stage4": round(t4, 2), "t_stage5": round(time.time() - t0 - t4, 2),
            "timestamp": time.time()}
    c.save_json(out / f"result_{index}.json", meta)
    print(f"[stage5] #{index} gt={tr['target_class']} pred={pred} {'OK' if meta['correct'] else 'X'} "
          f"base_off est/gt={off}/{tr.get('gt_base_off')} cov={meta['coverage']}")
    return meta


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--index", type=int, default=0)
    p.add_argument("--model", default=str(DEFAULT_MODEL))
    p.add_argument("--output-dir", default=str(HERE / "runs" / "debug"))
    a = p.parse_args()
    run_stage45(a.index, Path(a.output_dir), a.model)


if __name__ == "__main__":
    main()
