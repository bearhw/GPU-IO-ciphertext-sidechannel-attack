#!/usr/bin/env python3
"""
stage5_reconstruct.py — Stage 5: Multi-Model Reconstruction & SSIM Comparison (v6r, v9r, v10).

Reconstructs MNIST images from the 196-dim sparsity vector using:
  1. v6r (Retrieval: SparsityEncoder + Embedding Database Cosine Search)
  2. v9r (UNet-GAN Generator)
  3. v10 (SparsityEncoder + V10Decoder)
Evaluates against Ground Truth MNIST image, generates comparison plots, and
prints a formatted SSIM comparison table.

Usage:
    python3 stage5_reconstruct.py --index 0 [--output-dir .]
"""

import argparse
import ast
import json
import os
import re
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c


# ---------------------------------------------------------------------------
# Neural Network Architectures
# ---------------------------------------------------------------------------
class SparsityEncoder(nn.Module):
    """v6r/v10 Sparsity Encoder (196 -> 128 embedding)."""
    def __init__(self, input_dim: int = 196, embed_dim: int = 128):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(input_dim, 512), nn.BatchNorm1d(512), nn.ReLU(inplace=True),
            nn.Linear(512, 256),       nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Linear(256, embed_dim),
        )

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        return F.normalize(self.net(x), dim=1)


class DoubleConv(nn.Sequential):
    def __init__(self, cin: int, cout: int):
        super().__init__(
            nn.Conv2d(cin, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
            nn.Conv2d(cout, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
        )


class UNetGeneratorV9(nn.Module):
    """v9r UNet-GAN Generator."""
    def __init__(self):
        super().__init__()
        self.enc1 = DoubleConv(1, 32)
        self.enc2 = nn.Sequential(nn.MaxPool2d(2), DoubleConv(32, 64))
        self.bot  = nn.Sequential(nn.MaxPool2d(2), DoubleConv(64, 128))
        self.up2  = nn.ConvTranspose2d(128, 64, kernel_size=2, stride=2)
        self.dec2 = DoubleConv(128, 64)
        self.up1  = nn.ConvTranspose2d(64, 32, kernel_size=2, stride=2)
        self.dec1 = DoubleConv(64, 32)
        self.out  = nn.Sequential(nn.Conv2d(32, 1, 1), nn.Sigmoid())

    def forward(self, sp: torch.Tensor) -> torch.Tensor:
        # sp: (B, 196) -> mask: (B, 1, 28, 28)
        x = F.interpolate(sp.view(-1, 1, 28, 7), size=(28, 28), mode='nearest')
        e1 = self.enc1(x)
        e2 = self.enc2(e1)
        b = self.bot(e2)
        d2 = self.dec2(torch.cat([self.up2(b), e2], dim=1))
        d1 = self.dec1(torch.cat([self.up1(d2), e1], dim=1))
        return self.out(d1).squeeze(1)


class V10Decoder(nn.Module):
    """v10 128-dim embedding -> 28x28 image decoder."""
    def __init__(self, z_dim: int = 128):
        super().__init__()
        self.fc = nn.Linear(z_dim, 256 * 7 * 7)
        self.net = nn.Sequential(
            nn.ConvTranspose2d(256, 128, kernel_size=2, stride=2),
            nn.BatchNorm2d(128), nn.ReLU(inplace=True),
            nn.Conv2d(128, 128, 3, padding=1), nn.BatchNorm2d(128), nn.ReLU(inplace=True),
            nn.ConvTranspose2d(128, 64, kernel_size=2, stride=2),
            nn.BatchNorm2d(64), nn.ReLU(inplace=True),
            nn.Conv2d(64, 32, 3, padding=1), nn.BatchNorm2d(32), nn.ReLU(inplace=True),
            nn.Conv2d(32, 1, 1), nn.Sigmoid(),
        )

    def forward(self, z: torch.Tensor) -> torch.Tensor:
        x = F.relu(self.fc(z)).view(-1, 256, 7, 7)
        return self.net(x).squeeze(1)


# ---------------------------------------------------------------------------
# Model Loader Helper
# ---------------------------------------------------------------------------
class ModelSuite:
    def __init__(self, device: torch.device):
        self.device = device

        # 1. Sparsity Encoder (used for v6r and v10)
        enc_weight = c.MODEL_DIR / "sparsity_encoder_v6r_new.pth"
        if not enc_weight.exists():
            enc_weight = c.MODEL_DIR / "sparsity_encoder_v6r.pth"
        self.encoder = SparsityEncoder().to(device)
        if enc_weight.exists():
            self.encoder.load_state_dict(torch.load(enc_weight, map_location=device))
        self.encoder.eval()

        # 2. v6r Retrieval Database
        self.v6r_emb_db = None
        self.v6r_img_db = None
        emb_path = c.MODEL_DIR / "v6r_embeddings_new.npy"
        img_path = c.MODEL_DIR / "v6r_images_new.npy"
        if emb_path.exists() and img_path.exists():
            self.v6r_emb_db = np.load(emb_path)
            self.v6r_img_db = np.load(img_path)

        # 3. v9r UNet-GAN Generator
        v9_weight = c.MODEL_DIR / "unet_gan_generator_v9r_new.pth"
        if not v9_weight.exists():
            v9_weight = c.MODEL_DIR / "unet_gan_generator_v9r.pth"
        if not v9_weight.exists():
            v9_weight = c.MODEL_DIR / "unet_gan_generator_v8r2_new.pth"
        self.g9 = UNetGeneratorV9().to(device)
        if v9_weight.exists():
            self.g9.load_state_dict(torch.load(v9_weight, map_location=device))
        self.g9.eval()

        # 4. v10 Decoder
        v10_weight = c.MODEL_DIR / "v10_decoder_new.pth"
        if not v10_weight.exists():
            v10_weight = c.MODEL_DIR / "v10_decoder.pth"
        self.dec10 = V10Decoder().to(device)
        if v10_weight.exists():
            self.dec10.load_state_dict(torch.load(v10_weight, map_location=device))
        self.dec10.eval()

    def reconstruct_all(self, sparsity: List[int]) -> Dict[str, np.ndarray]:
        """Reconstruct 28x28 image using v6r, v9r, and v10."""
        sp_t = torch.tensor(sparsity, dtype=torch.float32).unsqueeze(0).to(self.device)
        recons = {}

        with torch.no_grad():
            # v6r Retrieval
            if self.v6r_emb_db is not None and self.v6r_img_db is not None:
                q = self.encoder(sp_t).cpu().numpy()
                ret_idx = int(np.argmax(self.v6r_emb_db @ q.T))
                recons["v6r"] = self.v6r_img_db[ret_idx]
            else:
                recons["v6r"] = np.zeros((28, 28), dtype=np.float32)

            # v9r UNet-GAN
            recon9 = self.g9(sp_t).squeeze().cpu().numpy()
            recons["v9r"] = np.clip(recon9, 0.0, 1.0)

            # v10 Encoder-Decoder
            emb = self.encoder(sp_t)
            recon10 = self.dec10(emb).squeeze().cpu().numpy()
            recons["v10"] = np.clip(recon10, 0.0, 1.0)

        return recons


def load_mnist_ground_truth(index: int) -> Tuple[Optional[np.ndarray], Optional[int]]:
    """Load Ground Truth MNIST image (28x28 float32 in [0, 1]) and label for index."""
    try:
        from torchvision import datasets, transforms
        mnist = datasets.MNIST(str(c.DEFAULT_DATA_DIR), train=True, download=False,
                               transform=transforms.ToTensor())
        if 0 <= index < len(mnist):
            img_tensor, label = mnist[index]
            return img_tensor.squeeze().numpy(), int(label)
    except Exception:
        pass

    # Fallback to raw binary files if torchvision dataset is not ready
    raw_images_path = c.DEFAULT_DATA_DIR / "MNIST" / "raw" / "train-images-idx3-ubyte"
    raw_labels_path = c.DEFAULT_DATA_DIR / "MNIST" / "raw" / "train-labels-idx1-ubyte"
    if raw_images_path.exists() and raw_labels_path.exists():
        try:
            with open(raw_images_path, "rb") as f_img:
                f_img.seek(16 + index * 784)
                buf = f_img.read(784)
                img = np.frombuffer(buf, dtype=np.uint8).reshape((28, 28)).astype(np.float32) / 255.0
            with open(raw_labels_path, "rb") as f_lbl:
                f_lbl.seek(8 + index)
                label = int(f_lbl.read(1)[0])
            return img, label
        except Exception:
            pass

    return None, None


def plot_comparison(gt_img: Optional[np.ndarray], recons: Dict[str, np.ndarray],
                    ssims: Dict[str, Optional[float]], label: Optional[int],
                    index: int, out_png: Path):
    """Generate a clean side-by-side comparison figure for GT, v6r, v9r, v10."""
    n_cols = 4 if gt_img is not None else 3
    fig, axes = plt.subplots(1, n_cols, figsize=(3 * n_cols, 3.5))

    titles = []
    imgs = []

    if gt_img is not None:
        titles.append(f"Ground Truth (Digit {label if label is not None else '?'})")
        imgs.append(gt_img)

    for m_key, m_name in [("v6r", "v6r (Retrieval)"), ("v9r", "v9r (UNet-GAN)"), ("v10", "v10 (Decoder)")]:
        ssim_val = ssims.get(m_key)
        ssim_str = f"SSIM: {ssim_val*100:.2f}%" if ssim_val is not None else "Reconstructed"
        titles.append(f"{m_name}\n{ssim_str}")
        imgs.append(recons[m_key])

    for ax, title, img in zip(axes, titles, imgs):
        ax.imshow(img, cmap="gray", vmin=0.0, vmax=1.0)
        ax.set_title(title, fontsize=11, fontweight="bold")
        ax.axis("off")

    fig.suptitle(f"MNIST Sample #{index} Side-Channel Reconstruction", fontsize=13, y=1.02)
    plt.tight_layout()
    fig.savefig(out_png, bbox_inches="tight", dpi=150)
    plt.close(fig)
    print(f"[stage5] Saved comparison figure → {out_png.name}")


def print_ssim_table(index: int, label: Optional[int], metrics: Dict[str, Dict[str, float]]):
    """Format and print an ASCII comparison table."""
    print("\n" + "=" * 65)
    print(f"  SSIM & RECONSTRUCTION COMPARISON (Sample #{index}, Label: {label})")
    print("=" * 65)
    print(f"  {'Model':<18} | {'SSIM (%)':<12} | {'PSNR (dB)':<12} | {'L1 Error':<10}")
    print("  " + "-" * 61)
    for model_name, vals in metrics.items():
        ssim_str = f"{vals['ssim'] * 100:.2f}%" if vals.get('ssim') is not None else "N/A"
        psnr_str = f"{vals['psnr']:.2f} dB" if vals.get('psnr') is not None else "N/A"
        l1_str   = f"{vals['l1']:.4f}" if vals.get('l1') is not None else "N/A"
        print(f"  {model_name:<18} | {ssim_str:<12} | {psnr_str:<12} | {l1_str:<10}")
    print("=" * 65 + "\n")


def run_stage5(index: int, output_dir: Path, sparsity: Optional[List[int]] = None,
               label: Optional[int] = None) -> Dict:
    """Execute Stage 5."""
    output_dir.mkdir(parents=True, exist_ok=True)
    metrics_json = output_dir / f"metrics_{index}.json"

    # 1. Resolve sparsity vector
    if sparsity is None:
        feat_json = output_dir / f"features_{index}.json"
        if not feat_json.exists():
            feat_json = HERE / f"features_{index}.json"
        if feat_json.exists():
            fdata = c.load_json(feat_json)
            sparsity = fdata.get("sparsity")
            if label is None:
                label = fdata.get("label")

    if sparsity is None:
        # Search for .out_v5.list
        list_candidates = list(output_dir.glob(f"*-{index}.out_v5.list"))
        if not list_candidates:
            list_candidates = list(c.FLOW_DIR.glob(f"*-{index}.out_v5.list"))
        if list_candidates:
            with open(list_candidates[0]) as lf:
                sparsity = ast.literal_eval(lf.read().strip())
                m = re.search(r'(\d+)-\d+\.out_v5\.list$', list_candidates[0].name)
                if m and label is None:
                    label = int(m.group(1))

    if sparsity is None or len(sparsity) != c.NUM_CHUNKS:
        raise ValueError(f"[stage5] Valid 196-dim sparsity vector not found for index {index}. Run stage4 first.")

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    suite = ModelSuite(device)

    # 2. Reconstruct across v6r, v9r, v10
    recons = suite.reconstruct_all(sparsity)

    # 3. Ground truth evaluation
    gt_img, gt_label = load_mnist_ground_truth(index)
    if label is None:
        label = gt_label

    metrics = {}
    ssims = {}
    for m_key, m_name in [("v6r", "v6r (Retrieval)"), ("v9r", "v9r (UNet-GAN)"), ("v10", "v10 (Decoder)")]:
        recon = recons[m_key]
        if gt_img is not None:
            s_val = c.compute_ssim(gt_img, recon)
            p_val = c.compute_psnr(gt_img, recon)
            l_val = c.compute_l1(gt_img, recon)
            metrics[m_name] = {"ssim": s_val, "psnr": p_val, "l1": l_val}
            ssims[m_key] = s_val
        else:
            metrics[m_name] = {"ssim": None, "psnr": None, "l1": None}
            ssims[m_key] = None

        # Save individual npy and png
        np.save(output_dir / f"recon_{index}_{m_key}.npy", recon)
        plt.imsave(output_dir / f"recon_{index}_{m_key}.png", recon, cmap="gray", vmin=0.0, vmax=1.0)

    # 4. Save comparison figure & print table
    comp_png = output_dir / f"comparison_{index}.png"
    plot_comparison(gt_img, recons, ssims, label, index, comp_png)
    print_ssim_table(index, label, metrics)

    meta = {
        "stage": 5,
        "index": index,
        "label": label,
        "metrics": metrics,
        "ssim_v6r": ssims.get("v6r"),
        "ssim_v9r": ssims.get("v9r"),
        "ssim_v10": ssims.get("v10"),
        "comparison_png": str(comp_png),
        "timestamp": time.time(),
    }
    c.save_json(metrics_json, meta)
    print(f"[stage5] Saved metrics → {metrics_json.name}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, required=True, help="MNIST sample index (0-59999)")
    p.add_argument("--label", type=int, default=None, help="MNIST digit label (0-9)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory containing features and saving images")
    args = p.parse_args()

    run_stage5(args.index, Path(args.output_dir), label=args.label)


if __name__ == "__main__":
    main()
