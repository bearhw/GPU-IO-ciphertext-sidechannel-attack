"""capture_data.py — Shared loader for v6r / v9r / v10 training.

All three reconstruction models must train on the SAME real end-to-end attack
captures (not on sparsity synthesized from clean images), so they share one loader.

A bs=512 blind capture writes <CAPTURE_DIR>/sparsities_*_bs512_idx{start}-{end}.npy,
a (512, 196) array of real captured sparsity; row i is image (start+i) of the capture's
MNIST split. load_items() pairs each row with its ground-truth image. If no batch
captures are present it falls back to the legacy per-image .out_v5.list captures so
the training scripts still run.

Env:
  CAPTURE_DIR   dir holding sparsities_*_bs512_idx*.npy (default: ../pipeline/output_train/results)
  MNIST_SPLIT   train | test  — which split the captures are of (default: train)
  MNIST_RAW_DIR raw idx-ubyte dir (default: ./data/MNIST/raw)
"""

import ast
import glob
import json
import os
import re

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))


def _raw_dir():
    return os.environ.get("MNIST_RAW_DIR", os.path.join(HERE, "data", "MNIST", "raw"))


def _split():
    return "train" if os.environ.get("MNIST_SPLIT", "train").lower() != "test" else "test"


def load_gt_image(index: int, split: str = None) -> np.ndarray:
    """Ground-truth MNIST image (28x28 float32 in [0,1]) from the raw idx3 file."""
    split = split or _split()
    fn = "train-images-idx3-ubyte" if split == "train" else "t10k-images-idx3-ubyte"
    with open(os.path.join(_raw_dir(), fn), "rb") as f:
        f.seek(16 + index * 784)
        buf = f.read(784)
    return np.frombuffer(buf, dtype=np.uint8).reshape(28, 28).astype(np.float32) / 255.0


def _default_capture_dir():
    return os.environ.get("CAPTURE_DIR",
                          os.path.join(HERE, "..", "pipeline", "output_train", "results"))


def load_items(capture_dir: str = None, split: str = None,
               legacy_list_dir: str = "./data/",
               legacy_json: str = "./UNet_training_v3.json"):
    """Return (items, message). items = list of (real_sp: list[int], img: np.ndarray[28,28])."""
    split = split or _split()
    capture_dir = capture_dir or _default_capture_dir()

    items = []
    npys = sorted(glob.glob(os.path.join(capture_dir, "sparsities_*_bs*_idx*.npy")))
    for npy in npys:
        m = re.search(r"_idx(\d+)-(\d+)", os.path.basename(npy))
        if not m:
            continue
        start = int(m.group(1))
        arr = np.load(npy)
        if arr.ndim != 2 or arr.shape[1] != 196:
            continue
        for r in range(arr.shape[0]):
            items.append((arr[r].astype(np.int64).tolist(), load_gt_image(start + r, split)))

    if items:
        return items, (f"{len(items)} real sparsity rows from {len(npys)} batch capture(s) "
                       f"in {capture_dir} (split={split})")

    # ── Fallback: legacy per-image .out_v5.list + UNet_training_v3.json GT ──────
    with open(legacy_json) as f:
        json_map = {s["sample_idx"]: s for s in json.load(f)}
    for fname in sorted(os.listdir(legacy_list_dir)):
        if not fname.endswith(".out_v5.list"):
            continue
        m = re.search(r"-(\d+)\.out_v5\.list$", fname)
        if not m:
            continue
        idx = int(m.group(1))
        if idx not in json_map:
            continue
        with open(os.path.join(legacy_list_dir, fname)) as f:
            real_sp = ast.literal_eval(f.read().strip())
        if len(real_sp) != 196:
            continue
        img = np.array(json_map[idx]["target_image"], dtype=np.float32)
        items.append((real_sp, img))
    return items, (f"no batch captures in {capture_dir} — "
                   f"fell back to {len(items)} legacy .out_v5.list items")
