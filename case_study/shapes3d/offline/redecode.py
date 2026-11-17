#!/usr/bin/env python3
"""
redecode.py — re-run assembly + Stage 4/5 offline on saved dumps.

Stage 3 keeps every dumped page (dump_<i>_p<k>.out, k = order of the pre-assembly
page list), so a better assembly or classifier can be scored without re-capturing.
The pre-assembly list is rebuilt from tracked_<i>.json (pieces), the probe log
(pieces with >= PIECE_MIN_HITS) and the write trace (fill_edges); newer dump json
files store it directly (pre_pages). Each sample is decoded with the dictionary
snapshot of its own boot (the VEK changes per boot).

  python3 redecode.py ../captures/test_blind [--indices 752,753] [--write]
"""
import argparse
import json
import sys
from datetime import datetime
from pathlib import Path

import numpy as np
import torch

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "pipeline"))
sys.path.insert(0, str(HERE))
import common as c
import shapes_map as sm
import stage3_dump as s3
import stage2_track as s2


def snapshots(d: Path, year: int):
    out = []
    for p in sorted(d.glob("dict_*")):
        md, hm = p.name.split("_")[1:3]
        t = datetime(year, int(md[:2]), int(md[2:]), int(hm[:2]), int(hm[2:])).timestamp()
        out.append((t, p / "dict_pages_shapes"))
    return out


def ref_pages_at(snaps, ts, cache={}):
    p = max((s for s in snaps if s[0] <= ts), key=lambda s: s[0], default=snaps[0])[1]
    if p not in cache:
        c.DICT_DIR = p
        cache[p] = sm.load_ref_pages()
    return cache[p]


def pre_assembly(d: Path, i: int, meta, ref):
    if "pre_pages" in meta:
        return meta["pre_pages"], meta["pre_dumps"]
    tr = c.load_json(d / f"tracked_{i}.json")
    sel = [tr["pieces"][s["piece"]] for s in meta["probe_scores"] if s["hits"] >= s3.PIECE_MIN_HITS]
    writes = [g for g, _ in s2.read_writes(d / f"wpt_{i}.log", filtered=True)]
    pre, post = s3.fill_edges(sel, writes)
    core = list(dict.fromkeys(g for p in sel for g in p["pages"]))
    edge = set(pre) | set(post)
    pages, dumps = [], []
    for k, g in enumerate(pre + core + post):
        f = d / f"dump_{i}_p{k:03d}.out"
        if not f.exists():
            if g not in edge:
                pages.append(g)
                dumps.append(None)
            continue
        if g in edge and sm.count_page_matches(f, ref) < s3.PIECE_MIN_HITS:
            continue
        pages.append(g)
        dumps.append(str(f))
    return pages, dumps


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dir")
    ap.add_argument("--indices", default=None)
    ap.add_argument("--year", type=int, default=2026)
    ap.add_argument("--write", action="store_true", help="save cmap_<i>_re.npy and redecode.json")
    ap.add_argument("--model", default=str(HERE / "attack_shapes_sim.pth"))
    ap.add_argument("--assembly", default="windowed", choices=["saved", "windowed", "weighted"])
    a = ap.parse_args()
    d = Path(a.dir)
    from stage45_classify import model
    from train_attack import to_tensor
    net = model(a.model)
    snaps = snapshots(d, a.year)
    idx = sorted(int(p.stem.split("_")[1]) for p in d.glob("dump_*.json"))
    if a.indices:
        idx = [i for i in idx if i in {int(x) for x in a.indices.split(",")}]
    rows = []
    for i in idx:
        meta = c.load_json(d / f"dump_{i}.json")
        if meta.get("probe_choice") not in ("pieces", "runhit") or not (d / f"tracked_{i}.json").exists():
            continue
        tr = c.load_json(d / f"tracked_{i}.json")
        ref = ref_pages_at(snaps, meta["timestamp"])
        pages, dumps = pre_assembly(d, i, meta, ref)
        old_p, _ = s3.assemble_by_channel(pages, dumps, ref, windowed=False)
        new_p, new_d = s3.assemble_by_channel(pages, dumps, ref, windowed={"saved": False, "windowed": True, "weighted": "weighted"}[a.assembly])
        gset = {g for g in tr["gt_pages_int"] if g is not None}
        hits = sm.dump_hits(new_d, ref)
        off = sm.estimate_base_off(hits)
        m, _, _ = sm.map_from_hits(hits, off)
        with torch.no_grad():
            prob = torch.softmax(net(to_tensor((m + 1).astype(np.uint8)[None])), 1)[0].numpy()
        pred = c.CLASSES[int(prob.argmax())]
        r = {"index": i, "gt": tr["target_class"], "pred": pred, "correct": pred == tr["target_class"],
             "rebuilt_matches_saved": old_p == meta["pages_int"],
             "gt_overlap_saved": meta["gt_overlap"], "gt_overlap_new": len(gset & set(new_p)),
             "base_off_est": off, "base_off_gt": tr.get("gt_base_off"),
             "coverage": [round(float((m[p] >= 0).mean()), 3) for p in range(3)]}
        rows.append(r)
        print(r, flush=True)
        if a.write:
            np.save(d / f"cmap_{i}_re.npy", (m + 1).astype(np.uint8))
    acc = np.mean([r["correct"] for r in rows]) if rows else 0
    print(f"redecoded {len(rows)}  top-1 {100 * acc:.1f}%  "
          f"rebuild==saved {sum(r['rebuilt_matches_saved'] for r in rows)}/{len(rows)}")
    if a.write:
        (d / "redecode.json").write_text(json.dumps(rows, indent=1))


if __name__ == "__main__":
    main()
