#!/usr/bin/env python3
"""
stage5_reconstruct.py — Stage 5: XorSliceSENetV3 Classification & Captured Pages Summary.

Performs:
1. Deep Learning Body-Part Classification via XorSliceSENetV3 (Top-1/Top-3 probabilities).
2. Evaluation of captured single-channel tensor pages (e.g. 49/49 pages).
3. Saves metrics_{index}.json.

Outputs:
  - metrics_{index}.json

Usage:
    python3 stage5_reconstruct.py --index 0 [--output-dir .]
"""

import argparse
import json
import os
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c


# ── Model Definition (XorSliceSENetV3) ───────────────────────────────────────
class SELayer(nn.Module):
    def __init__(self, ch, reduction=16):
        super().__init__()
        mid = max(ch // reduction, 4)
        self.fc = nn.Sequential(
            nn.Linear(ch, mid, bias=False), nn.ReLU(inplace=True),
            nn.Linear(mid, ch, bias=False), nn.Sigmoid())

    def forward(self, x):
        return x * self.fc(x.mean(dim=(2, 3)))[:, :, None, None]


class SEResBlock(nn.Module):
    def __init__(self, in_ch, out_ch, stride=1, se_reduction=16):
        super().__init__()
        self.c1 = nn.Conv2d(in_ch, out_ch, 3, stride=stride, padding=1, bias=False)
        self.b1 = nn.BatchNorm2d(out_ch)
        self.c2 = nn.Conv2d(out_ch, out_ch, 3, padding=1, bias=False)
        self.b2 = nn.BatchNorm2d(out_ch)
        self.se = SELayer(out_ch, se_reduction)
        self.down = nn.Sequential(
            nn.Conv2d(in_ch, out_ch, 1, stride=stride, bias=False),
            nn.BatchNorm2d(out_ch),
        ) if (stride != 1 or in_ch != out_ch) else nn.Identity()

    def forward(self, x):
        h = F.relu(self.b1(self.c1(x)), inplace=True)
        h = self.se(self.b2(self.c2(h)))
        return F.relu(h + self.down(x), inplace=True)


class XorSliceSENetV3(nn.Module):
    def __init__(self, num_classes=7, n_ref=64):
        super().__init__()
        self.stem = nn.Sequential(
            nn.Conv2d(n_ref, 64, kernel_size=(7, 3), stride=(2, 1),
                      padding=(3, 1), bias=False),
            nn.BatchNorm2d(64), nn.ReLU(inplace=True), SELayer(64))
        self.pool1  = nn.MaxPool2d(kernel_size=(2, 1), stride=(2, 1))
        self.layer1 = SEResBlock(64,  128, stride=1)
        self.layer2 = SEResBlock(128, 256, stride=2)
        self.layer3 = SEResBlock(256, 512, stride=2)
        self.layer4 = SEResBlock(512, 512, stride=2)
        self.gap    = nn.AdaptiveAvgPool2d(1)
        self.stats_head = nn.Sequential(
            nn.Linear(n_ref, 256), nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Dropout(0.3),
            nn.Linear(256, 128), nn.ReLU(inplace=True))
        self.head = nn.Sequential(
            nn.Linear(512 + 128 + 1, 512), nn.ReLU(inplace=True),
            nn.Dropout(0.4),
            nn.Linear(512, num_classes))

    def forward(self, x, frac):
        valid = (frac.clamp(min=1e-3) * c.XOR_ROWS * c.XOR_COLS)
        stats = x.sum(dim=(2, 3)) / valid
        stats_feat = self.stats_head(stats)
        x = self.pool1(self.stem(x))
        x = self.layer1(x); x = self.layer2(x); x = self.layer3(x); x = self.layer4(x)
        sp_feat = self.gap(x).flatten(1)
        return self.head(torch.cat([sp_feat, stats_feat, frac], dim=1))


def run_stage5(index: int, output_dir: Path, mock: bool = False,
               ckpt_path: Path = c.CHECKPOINT_V3) -> Dict:
    """Execute Stage 5."""
    output_dir.mkdir(parents=True, exist_ok=True)
    features_json = output_dir / f"features_{index}.json"
    swap_json = output_dir / f"swap_meta_{index}.json"
    tracked_json = output_dir / f"tracked_mura_{index}.json"
    npy_path = output_dir / f"xor_slice_{index}.npy"
    frac_path = output_dir / f"xor_slice_{index}.npy.frac"
    metrics_json = output_dir / f"metrics_{index}.json"

    if mock or not npy_path.exists():
        xor_slice = np.random.binomial(1, 0.04, size=(c.NUM_REFS, c.XOR_ROWS, c.XOR_COLS)).astype(np.float32)
        frac = 1.0
        target_class = "ELBOW"
        captured_pages_count = c.IMG_PAGES
    else:
        xor_slice = np.load(npy_path)
        frac = float(frac_path.read_text().strip()) if frac_path.exists() else 1.0
        feat_meta = c.load_json(features_json) if features_json.exists() else {}
        target_class = feat_meta.get("target_class", "ELBOW")

        # Determine captured single-channel page count
        if swap_json.exists():
            swap_meta = c.load_json(swap_json)
            captured_pages_count = swap_meta.get("successful_pages", int(round(frac * c.IMG_PAGES)))
        elif tracked_json.exists():
            tr_meta = c.load_json(tracked_json)
            captured_pages_count = tr_meta.get("total_pages", int(round(frac * c.IMG_PAGES)))
        else:
            captured_pages_count = int(round(frac * c.IMG_PAGES))

    # 1. Classification
    device = torch.device("cpu")
    model = XorSliceSENetV3(len(c.CLASSES), n_ref=c.NUM_REFS).to(device)
    if ckpt_path.exists() and not mock:
        sd = torch.load(ckpt_path, map_location=device, weights_only=True)
        model.load_state_dict(sd, strict=False)
    model.eval()

    x_t = torch.from_numpy(xor_slice).float().unsqueeze(0).to(device)
    frac_t = torch.tensor([[frac]], dtype=torch.float32).to(device)

    with torch.no_grad():
        logits = model(x_t, frac_t)
        probs = F.softmax(logits, dim=1)[0].cpu().numpy()

    pred_idx = int(np.argmax(probs))
    pred_class = c.CLASSES[pred_idx]
    pred_prob = float(probs[pred_idx])

    top3_indices = np.argsort(-probs)[:3].tolist()
    top3_classes = [{"class": c.CLASSES[i], "prob": float(probs[i])} for i in top3_indices]

    cap_str = f"{captured_pages_count}/{c.IMG_PAGES}"

    print(f"\n[stage5] Classification: Predicted={pred_class} (p={pred_prob:.3f}), Target GT={target_class}")
    for item in top3_classes:
        print(f"  - {item['class']:10s}: {item['prob']*100:5.1f}%")
    print(f"[stage5] Captured Channel Pages: {cap_str} ({captured_pages_count/c.IMG_PAGES*100:.1f}%)")

    meta = {
        "stage": 5,
        "index": index,
        "target_class": target_class,
        "predicted_class": pred_class,
        "confidence": pred_prob,
        "top3": top3_classes,
        "is_correct": (pred_class == target_class),
        "captured_pages": cap_str,
        "captured_pages_count": captured_pages_count,
        "total_channel_pages": c.IMG_PAGES,
        "capture_fraction": frac,
        "timestamp": time.time(),
    }
    c.save_json(metrics_json, meta)
    print(f"[stage5] Saved metrics report → {metrics_json}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="MURA study / sample index")
    p.add_argument("--mock", action="store_true", help="Run with mock data (testing)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory containing stage outputs")
    args = p.parse_args()

    run_stage5(args.index, Path(args.output_dir), mock=args.mock)


if __name__ == "__main__":
    main()
