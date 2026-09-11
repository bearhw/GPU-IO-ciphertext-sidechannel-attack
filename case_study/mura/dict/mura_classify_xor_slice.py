#!/usr/bin/env python3
"""
mura_classify_xor_slice.py -- feed a real (write-tracker candidate ->
mura_dict_build.py --infer) xor_slice.npy into the already-trained
XorSliceSENet (v2, 64-ref) body-part classifier and print the prediction.

Model architecture copied verbatim from mura_bodypart_attacker.ipynb cell 36
(XorSliceSENet v2 definition) -- must match exactly to load the checkpoint.
mura_dict_build.py's infer() already emits (64, 224, 56) float32, exactly
the shape this model expects; no conversion needed.

Aspect ratio scalar: infer() has no access to the original image's real
aspect ratio (we never see the source file, only reconstructed content), so
this defaults to 1.0 (square) unless overridden -- an approximation, not a
measured value.

Usage:
  python3 mura_classify_xor_slice.py xor_slice.npy
  python3 mura_classify_xor_slice.py xor_slice.npy --aspect 1.3
"""
import argparse

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F

CLASSES = ["ELBOW", "FINGER", "FOREARM", "HAND", "HUMERUS", "SHOULDER", "WRIST"]
CKPT_DEFAULT    = "./mura_xor_slice_64ref_v2.pth"
CKPT_V3_DEFAULT = "./mura_xor_slice_64ref_v3.pth"
XOR_ROWS = 224
XOR_COLS = 56
IMG_PAGES = 49


# ── XorSliceSENet (v2) -- verbatim from mura_bodypart_attacker.ipynb cell 36 ─
class SELayer(nn.Module):
    def __init__(self, ch, reduction=16):
        super().__init__()
        mid = max(ch // reduction, 4)
        self.fc = nn.Sequential(
            nn.Linear(ch, mid, bias=False), nn.ReLU(inplace=True),
            nn.Linear(mid, ch, bias=False), nn.Sigmoid(),
        )

    def forward(self, x):
        scale = self.fc(x.mean(dim=(2, 3)))
        return x * scale[:, :, None, None]


class SEResBlock(nn.Module):
    def __init__(self, in_ch, out_ch, stride=1, se_reduction=16):
        super().__init__()
        self.c1   = nn.Conv2d(in_ch,  out_ch, 3, stride=stride, padding=1, bias=False)
        self.b1   = nn.BatchNorm2d(out_ch)
        self.c2   = nn.Conv2d(out_ch, out_ch, 3, padding=1, bias=False)
        self.b2   = nn.BatchNorm2d(out_ch)
        self.se   = SELayer(out_ch, se_reduction)
        self.down = nn.Sequential(
            nn.Conv2d(in_ch, out_ch, 1, stride=stride, bias=False),
            nn.BatchNorm2d(out_ch),
        ) if (stride != 1 or in_ch != out_ch) else nn.Identity()

    def forward(self, x):
        h = F.relu(self.b1(self.c1(x)), inplace=True)
        h = self.se(self.b2(self.c2(h)))
        return F.relu(h + self.down(x), inplace=True)


class XorSliceSENet(nn.Module):
    def __init__(self, num_classes=7, n_ref=64):
        super().__init__()
        self.stem = nn.Sequential(
            nn.Conv2d(n_ref, 64, kernel_size=(7, 3), stride=(2, 1),
                      padding=(3, 1), bias=False),
            nn.BatchNorm2d(64), nn.ReLU(inplace=True),
            SELayer(64),
        )
        self.pool1  = nn.MaxPool2d(kernel_size=(2, 1), stride=(2, 1))
        self.layer1 = SEResBlock(64,  128, stride=1)
        self.layer2 = SEResBlock(128, 256, stride=2)
        self.layer3 = SEResBlock(256, 512, stride=2)
        self.layer4 = SEResBlock(512, 512, stride=2)
        self.gap    = nn.AdaptiveAvgPool2d(1)

        self.stats_head = nn.Sequential(
            nn.Linear(n_ref, 256), nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Dropout(0.3),
            nn.Linear(256, 128), nn.ReLU(inplace=True),
        )

        self.head = nn.Sequential(
            nn.Linear(512 + 128 + 1, 512), nn.ReLU(inplace=True),
            nn.Dropout(0.4),
            nn.Linear(512, num_classes),
        )

    def forward(self, x, sc):
        stats      = x.mean(dim=(2, 3))
        stats_feat = self.stats_head(stats)

        x = self.pool1(self.stem(x))
        x = self.layer1(x)
        x = self.layer2(x)
        x = self.layer3(x)
        x = self.layer4(x)
        sp_feat = self.gap(x).flatten(1)

        return self.head(torch.cat([sp_feat, stats_feat, sc], dim=1))


class XorSliceSENetV3(XorSliceSENet):
    """Partial-image-robust variant (train_64ref_v3_partial.py). Arch identical
    to v2; only the scalar's meaning (capture FRACTION, not aspect) and the
    stats-branch normalization (over the top-aligned VALID region only) differ.
    Input must be TOP-ALIGNED: the captured strip in rows [0, frac*224), zeros
    below. frac = captured_pages / 49."""

    def forward(self, x, frac):
        valid = (frac.clamp(min=1e-3) * XOR_ROWS * XOR_COLS)   # (B,1)
        stats = x.sum(dim=(2, 3)) / valid
        stats_feat = self.stats_head(stats)
        x = self.pool1(self.stem(x))
        x = self.layer1(x); x = self.layer2(x)
        x = self.layer3(x); x = self.layer4(x)
        sp_feat = self.gap(x).flatten(1)
        return self.head(torch.cat([sp_feat, stats_feat, frac], dim=1))


def _resolve_frac(args, xor_slice) -> float:
    """Capture fraction for the v3 scalar. Priority: --frac > --pages/49 >
    <npy>.frac sidecar (written by mura_dict_build.py --infer) > infer from the
    last top-aligned nonzero row > 1.0 (full)."""
    if args.frac is not None:
        return float(args.frac)
    if args.pages is not None:
        return max(1, min(IMG_PAGES, args.pages)) / IMG_PAGES
    import os
    sidecar = args.xor_slice_npy + ".frac"
    if os.path.exists(sidecar):
        try:
            return float(open(sidecar).read().strip())
        except ValueError:
            pass
    nz = np.where(xor_slice.reshape(xor_slice.shape[0], XOR_ROWS, XOR_COLS)
                  .any(axis=(0, 2)))[0]
    if len(nz):
        return float((nz.max() + 1) / XOR_ROWS)
    return 1.0


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("xor_slice_npy", help="output of mura_dict_build.py --infer")
    ap.add_argument("--aspect", type=float, default=1.0,
                     help="orig_h/orig_w scalar (default 1.0 -- not measured, "
                          "we never see the source file)")
    ap.add_argument("--variant", choices=["v2", "v3"], default="v3",
                     help="v3 = partial-image robust (default). v2 = full-image "
                          "only (legacy).")
    ap.add_argument("--ckpt", default=None,
                     help="checkpoint path (default: v2/v3 ckpt per --variant)")
    ap.add_argument("--pages", type=int, default=None,
                     help="[v3] # captured pages of the 49-page R plane "
                          "(frac=pages/49). Overridden by --frac.")
    ap.add_argument("--frac", type=float, default=None,
                     help="[v3] capture fraction directly (0<f<=1). Highest "
                          "priority; else --pages, else <npy>.frac, else auto.")
    args = ap.parse_args()
    if args.ckpt is None:
        args.ckpt = CKPT_V3_DEFAULT if args.variant == "v3" else CKPT_DEFAULT

    xor_slice = np.load(args.xor_slice_npy)
    print(f"[classify] loaded {args.xor_slice_npy} shape={xor_slice.shape} "
          f"dtype={xor_slice.dtype}")
    if xor_slice.shape != (64, 224, 56):
        print(f"[!] expected (64, 224, 56), got {xor_slice.shape} -- "
              f"check --n-ref / IMG_SIZE match")

    device = torch.device("cpu")
    Net = XorSliceSENetV3 if args.variant == "v3" else XorSliceSENet
    model = Net(len(CLASSES), n_ref=64).to(device)
    n_params = sum(p.numel() for p in model.parameters())
    print(f"[classify] {Net.__name__} params={n_params:,}  ckpt={args.ckpt}")
    model.load_state_dict(torch.load(args.ckpt, map_location=device, weights_only=True))
    model.eval()

    x  = torch.from_numpy(xor_slice).float().unsqueeze(0).to(device)
    if args.variant == "v3":
        frac = _resolve_frac(args, xor_slice)
        sc   = torch.tensor([[frac]], dtype=torch.float32).to(device)
        print(f"[classify] v3 capture frac={frac:.3f} "
              f"(~{round(frac*IMG_PAGES)}/{IMG_PAGES} pages, top-aligned)")
    else:
        sc = torch.tensor([[args.aspect]], dtype=torch.float32).to(device)

    with torch.no_grad():
        logits = model(x, sc)
        probs  = F.softmax(logits, dim=1)[0]
        pred   = int(probs.argmax().item())

    print(f"\n[classify] predicted: {CLASSES[pred]}  (p={probs[pred]:.3f})")
    print("[classify] full distribution:")
    for i, c in enumerate(CLASSES):
        bar = "#" * int(probs[i] * 40)
        print(f"  {c:10s} {probs[i]*100:5.1f}%  {bar}")


if __name__ == "__main__":
    main()
