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
        """Reconstruct single 28x28 image using v6r, v9r, and v10."""
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

    def reconstruct_batch(self, sparsities: np.ndarray) -> Dict[str, np.ndarray]:
        """Reconstruct a batch of (B, 196) images using v6r, v9r, and v10."""
        B = len(sparsities)
        sp_t = torch.tensor(sparsities, dtype=torch.float32).to(self.device)
        recons = {}

        with torch.no_grad():
            # v6r Retrieval
            if self.v6r_emb_db is not None and self.v6r_img_db is not None:
                q = self.encoder(sp_t).cpu().numpy()
                sims = self.v6r_emb_db @ q.T   # (N_db, B)
                best_indices = np.argmax(sims, axis=0)
                recons["v6r"] = self.v6r_img_db[best_indices]
            else:
                recons["v6r"] = np.zeros((B, 28, 28), dtype=np.float32)

            # v9r UNet-GAN
            recon9 = self.g9(sp_t).cpu().numpy()
            recons["v9r"] = np.clip(recon9, 0.0, 1.0)

            # v10 Encoder-Decoder
            emb = self.encoder(sp_t)
            recon10 = self.dec10(emb).cpu().numpy()
            recons["v10"] = np.clip(recon10, 0.0, 1.0)

        return recons


_MNIST_DATASET_CACHE = None

def get_mnist_dataset():
    global _MNIST_DATASET_CACHE
    if _MNIST_DATASET_CACHE is None:
        try:
            from torchvision import datasets, transforms
            _MNIST_DATASET_CACHE = datasets.MNIST(str(c.DEFAULT_DATA_DIR), train=True, download=False,
                                                 transform=transforms.ToTensor())
        except Exception:
            _MNIST_DATASET_CACHE = False
    return _MNIST_DATASET_CACHE


def load_mnist_ground_truth(index: int) -> Tuple[Optional[np.ndarray], Optional[int]]:
    """Load Ground Truth MNIST image (28x28 float32 in [0, 1]) and label for index."""
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

    ds = get_mnist_dataset()
    if ds and 0 <= index < len(ds):
        img_tensor, label = ds[index]
        return img_tensor.squeeze().numpy(), int(label)

    return None, None


def load_mnist_ground_truth_batch(start_idx: int, count: int) -> Tuple[Optional[np.ndarray], Optional[List[int]]]:
    """Load batch of Ground Truth MNIST images (B, 28, 28) and labels quickly."""
    raw_images_path = c.DEFAULT_DATA_DIR / "MNIST" / "raw" / "train-images-idx3-ubyte"
    raw_labels_path = c.DEFAULT_DATA_DIR / "MNIST" / "raw" / "train-labels-idx1-ubyte"
    if raw_images_path.exists() and raw_labels_path.exists():
        try:
            with open(raw_images_path, "rb") as f_img:
                f_img.seek(16 + start_idx * 784)
                buf = f_img.read(count * 784)
                imgs = np.frombuffer(buf, dtype=np.uint8).reshape((count, 28, 28)).astype(np.float32) / 255.0
            with open(raw_labels_path, "rb") as f_lbl:
                f_lbl.seek(8 + start_idx)
                lbuf = f_lbl.read(count)
                labels = [int(b) for b in lbuf]
            return imgs, labels
        except Exception:
            pass

    imgs = []
    labels = []
    for i in range(start_idx, start_idx + count):
        img, lbl = load_mnist_ground_truth(i)
        if img is not None:
            imgs.append(img)
            labels.append(lbl)
        else:
            break
    if len(imgs) == count:
        return np.stack(imgs), labels
    return None, None


def plot_batch_grid(gt_imgs: Optional[np.ndarray], recons: Dict[str, np.ndarray],
                    gt_labels: Optional[List[int]], index: int, batch_size: int,
                    start_idx: int, end_idx: int, out_png: Path,
                    per_image_results: List[Dict], num_samples: int = 8):
    """Generate an 8-row x 4-col visual comparison grid across representative samples in the batch."""
    if gt_imgs is None or len(gt_imgs) == 0:
        return

    B = len(gt_imgs)
    # Pick up to 8 representative sample indices across the batch
    if B <= num_samples:
        sample_indices = list(range(B))
    else:
        sample_indices = [int(i * (B - 1) / (num_samples - 1)) for i in range(num_samples)]

    n_rows = len(sample_indices)
    n_cols = 4  # [GT, v6r, v9r, v10]
    fig, axes = plt.subplots(n_rows, n_cols, figsize=(3.2 * n_cols, 2.7 * n_rows))
    if n_rows == 1:
        axes = np.expand_dims(axes, 0)

    model_keys = ["v6r", "v9r", "v10"]
    model_names = ["v6r (Retrieval)", "v9r (UNet-GAN)", "v10 (Decoder)"]

    for r, local_idx in enumerate(sample_indices):
        global_idx = start_idx + local_idx
        lbl = gt_labels[local_idx] if gt_labels else "?"
        rec_info = per_image_results[local_idx] if local_idx < len(per_image_results) else {}
        ssim_dict = rec_info.get("ssim", {})

        # Col 0: Ground Truth
        ax_gt = axes[r, 0]
        ax_gt.imshow(gt_imgs[local_idx], cmap="gray", vmin=0.0, vmax=1.0)
        ax_gt.set_title(f"Image #{global_idx} (Digit {lbl})\nGround Truth", fontsize=9, fontweight="bold")
        ax_gt.axis("off")

        # Cols 1..3: Reconstructions
        for c_idx, (m_key, m_name) in enumerate(zip(model_keys, model_names), start=1):
            ax_m = axes[r, c_idx]
            recon_img = recons[m_key][local_idx]
            ax_m.imshow(recon_img, cmap="gray", vmin=0.0, vmax=1.0)
            ssim_val = ssim_dict.get(m_key)
            ssim_str = f"SSIM: {ssim_val*100:.2f}%" if ssim_val is not None else ""
            ax_m.set_title(f"{m_name}\n{ssim_str}", fontsize=9)
            ax_m.axis("off")

    fig.suptitle(f"MNIST Batch #{index} (Batch Size: {batch_size}, Images #{start_idx} ~ #{end_idx}) — 8-Sample Visual Grid",
                 fontsize=13, fontweight="bold", y=1.01)
    plt.tight_layout()
    fig.savefig(out_png, bbox_inches="tight", dpi=150)
    plt.close(fig)
    print(f"[stage5] Saved multi-sample comparison grid → {out_png.name}")


def plot_comparison(gt_img: Optional[np.ndarray], recons: Dict[str, np.ndarray],
                    ssims: Dict[str, Optional[float]], label: Optional[int],
                    index: int, out_png: Path):
    """Generate a clean side-by-side comparison figure for a single sample."""
    n_cols = 4 if gt_img is not None else 3
    fig, axes = plt.subplots(1, n_cols, figsize=(3.2 * n_cols, 3.8))

    titles = []
    imgs = []

    if gt_img is not None:
        titles.append(f"Ground Truth\n(Digit {label if label is not None else '?'})")
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

    fig.suptitle(f"MNIST Sample #{index} Side-Channel Reconstruction", fontsize=13, fontweight="bold", y=1.02)
    plt.tight_layout()
    fig.savefig(out_png, bbox_inches="tight", dpi=150)
    plt.close(fig)
    print(f"[stage5] Saved comparison figure → {out_png.name}")


def print_ssim_table(index: int, label: Optional[int], metrics: Dict[str, Dict[str, float]],
                     batch_size: int = 1, start_idx: int = 0, end_idx: int = 0):
    """Format and print an ASCII comparison table."""
    print("\n" + "=" * 68)
    title = f"BATCH #{index} (Batch Size {batch_size}, Images #{start_idx} ~ #{end_idx}) AVERAGE" if batch_size > 1 else f"Sample #{index}, Label: {label}"
    print(f"  SSIM & RECONSTRUCTION COMPARISON ({title})")
    print("=" * 68)
    print(f"  {'Model':<18} | {'SSIM (%)':<12} | {'PSNR (dB)':<12} | {'L1 Error':<10}")
    print("  " + "-" * 64)
    for model_name, vals in metrics.items():
        ssim_str = f"{vals['ssim'] * 100:.2f}%" if vals.get('ssim') is not None else "N/A"
        psnr_str = f"{vals['psnr']:.2f} dB" if vals.get('psnr') is not None else "N/A"
        l1_str   = f"{vals['l1']:.4f}" if vals.get('l1') is not None else "N/A"
        print(f"  {model_name:<18} | {ssim_str:<12} | {psnr_str:<12} | {l1_str:<10}")
    print("=" * 68 + "\n")


def run_stage5(index: int, output_dir: Path, sparsity: Optional[List[int]] = None,
               label: Optional[int] = None, batch_size: int = 1) -> Dict:
    """Execute Stage 5."""
    dumps_dir, logs_dir, results_dir = c.get_output_subdirs(output_dir)

    # Check for metadata batch size
    feat_json = results_dir / f"features_{index}.json"
    if not feat_json.exists():
        feat_json = output_dir / f"features_{index}.json"
    if feat_json.exists():
        fdata = c.load_json(feat_json)
        if fdata.get("batch_size"):
            batch_size = fdata["batch_size"]

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    suite = ModelSuite(device)

    # ── Batch Mode (batch_size > 1) ──────────────────────────────────
    if batch_size > 1:
        start_gt_idx = index * batch_size
        end_gt_idx = (index + 1) * batch_size - 1
        batch_tag = c.make_timestamp_tag(index, batch_size, start_gt_idx, end_gt_idx)
        metrics_json = results_dir / f"metrics_{batch_tag}.json"

        # Locate sparsities npy
        npy_file = results_dir / f"sparsities_{batch_tag}.npy"
        if not npy_file.exists():
            candidates = sorted(results_dir.glob(f"*_bs{batch_size}_idx{start_gt_idx}-{end_gt_idx}*.npy"), reverse=True)
            if candidates:
                npy_file = candidates[0]
        if not npy_file.exists():
            npy_file = results_dir / f"batch_{index}_sparsities.npy"
        if not npy_file.exists():
            npy_file = output_dir / f"batch_{index}_sparsities.npy"
        if not npy_file.exists():
            raise FileNotFoundError(f"[stage5] batch sparsities array not found. Run stage4 first.")

        sparsities_arr = np.load(npy_file)
        B = len(sparsities_arr)
        print(f"[stage5] Reconstructing {B} images (images #{start_gt_idx}..#{end_gt_idx}) using v6r, v9r, v10 in batch mode...")
        t0 = time.time()
        recons = suite.reconstruct_batch(sparsities_arr)
        print(f"[stage5] Reconstructed {B} images in {time.time() - t0:.2f}s")

        # Save batch reconstruction arrays with explicit descriptive names
        for m_key in ["v6r", "v9r", "v10"]:
            recon_path = results_dir / f"recons_{batch_tag}_{m_key}.npy"
            np.save(recon_path, recons[m_key])
            try:
                (results_dir / f"batch_{index}_recons_{m_key}.npy").unlink(missing_ok=True)
                (results_dir / f"batch_{index}_recons_{m_key}.npy").symlink_to(recon_path.name)
            except Exception:
                pass

        # Evaluate against Ground Truth
        gt_imgs, gt_labels = load_mnist_ground_truth_batch(start_gt_idx, B)

        # Compute per-image metrics for all B images
        s_dict = {}
        p_dict = {}
        l_dict = {}
        metrics = {}
        ssims = {}

        for m_key, m_name in [("v6r", "v6r (Retrieval)"), ("v9r", "v9r (UNet-GAN)"), ("v10", "v10 (Decoder)")]:
            if gt_imgs is not None:
                s_list = [c.compute_ssim(gt_imgs[i], recons[m_key][i]) for i in range(B)]
                p_list = [c.compute_psnr(gt_imgs[i], recons[m_key][i]) for i in range(B)]
                l_list = [c.compute_l1(gt_imgs[i], recons[m_key][i]) for i in range(B)]
                s_dict[m_key] = s_list
                p_dict[m_key] = p_list
                l_dict[m_key] = l_list
                s_avg = float(np.mean(s_list))
                p_avg = float(np.mean(p_list))
                l_avg = float(np.mean(l_list))
                metrics[m_name] = {"ssim": s_avg, "psnr": p_avg, "l1": l_avg}
                ssims[m_key] = s_avg
            else:
                metrics[m_name] = {"ssim": None, "psnr": None, "l1": None}
                ssims[m_key] = None

        # Build full per-image individual results array for all 512 images
        per_image_results = []
        for i in range(B):
            per_image_results.append({
                "image_index": start_gt_idx + i,
                "local_batch_offset": i,
                "label": gt_labels[i] if gt_labels else None,
                "ssim": {
                    "v6r": float(s_dict["v6r"][i]) if "v6r" in s_dict else None,
                    "v9r": float(s_dict["v9r"][i]) if "v9r" in s_dict else None,
                    "v10": float(s_dict["v10"][i]) if "v10" in s_dict else None,
                },
                "psnr": {
                    "v6r": float(p_dict["v6r"][i]) if "v6r" in p_dict else None,
                    "v9r": float(p_dict["v9r"][i]) if "v9r" in p_dict else None,
                    "v10": float(p_dict["v10"][i]) if "v10" in p_dict else None,
                },
                "l1": {
                    "v6r": float(l_dict["v6r"][i]) if "v6r" in l_dict else None,
                    "v9r": float(l_dict["v9r"][i]) if "v9r" in l_dict else None,
                    "v10": float(l_dict["v10"][i]) if "v10" in l_dict else None,
                },
            })

        comp_png = results_dir / f"comparison_{batch_tag}.png"
        plot_batch_grid(gt_imgs, recons, gt_labels, index, B, start_gt_idx, end_gt_idx, comp_png, per_image_results, num_samples=8)
        print_ssim_table(index, None, metrics, batch_size=B, start_idx=start_gt_idx, end_idx=end_gt_idx)

        meta = {
            "stage": 5,
            "index": index,
            "batch_size": B,
            "start_image_index": start_gt_idx,
            "end_image_index": end_gt_idx,
            "batch_tag": batch_tag,
            "summary_metrics": metrics,
            "metrics": metrics,
            "ssim_v6r": ssims.get("v6r"),
            "ssim_v9r": ssims.get("v9r"),
            "ssim_v10": ssims.get("v10"),
            "comparison_png": str(comp_png),
            "per_image_results": per_image_results,
            "timestamp": time.time(),
        }
        c.save_json(metrics_json, meta)
        # Also maintain metrics_{index}.json
        c.save_json(results_dir / f"metrics_{index}.json", meta)
        print(f"[stage5] Saved batch metrics (including all {B} per-image results) → {metrics_json.name}")
        return meta

    # ── Single Sample Mode (batch_size == 1) ─────────────────────────
    if sparsity is None:
        if feat_json.exists():
            fdata = c.load_json(feat_json)
            sparsity = fdata.get("sparsity")
            if label is None:
                label = fdata.get("label")

    if sparsity is None:
        list_candidates = list(results_dir.glob(f"*-{index}.out_v5.list")) + list(output_dir.glob(f"*-{index}.out_v5.list"))
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

    recons = suite.reconstruct_all(sparsity)

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

        np.save(results_dir / f"recon_{index}_{m_key}.npy", recon)
        plt.imsave(results_dir / f"recon_{index}_{m_key}.png", recon, cmap="gray", vmin=0.0, vmax=1.0)

    comp_png = results_dir / f"comparison_{index}.png"
    plot_comparison(gt_img, recons, ssims, label, index, comp_png)
    print_ssim_table(index, label, metrics, batch_size=1)

    meta = {
        "stage": 5,
        "index": index,
        "batch_size": 1,
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
    p.add_argument("--index", type=int, required=True, help="MNIST sample/batch index (0-59999)")
    p.add_argument("--batch-size", type=int, default=1, help="Batch size (default: 1, e.g. 512)")
    p.add_argument("--label", type=int, default=None, help="MNIST digit label (0-9)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory containing features and saving images")
    args = p.parse_args()

    run_stage5(args.index, Path(args.output_dir), label=args.label, batch_size=args.batch_size)


if __name__ == "__main__":
    main()
