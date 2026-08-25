"""v10 cross-split retraining
Train with train:val ratios 6:4 / 7:3 / 8:2.
encoder: sparsity_encoder_v6r_new.pth (frozen)
Output: v10_decoder_split60.pth / v10_decoder_split70.pth / v10_decoder_split80.pth
     train_v10_cross_split60_curves.pdf / ..._split70_ / ..._split80_
tmux: /home/eun/miniforge3/envs/mura/bin/python train_v10_cross.py 2>&1 | tee train_v10_cross.log
"""
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import numpy as np
import json, os, ast, re
from torch.utils.data import Dataset, DataLoader
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

CHUNK_BYTES = 16
PAGE_SIZE   = 4096
IMAGE_SIZE  = 3136

def augment_sparsity(pixel_arr):
    pixel_arr   = np.where(pixel_arr < 1e-4, 0.0, pixel_arr)
    pixel_bytes = pixel_arr.flatten().astype(np.float32).tobytes()
    page_offset = np.random.randint(0, PAGE_SIZE - IMAGE_SIZE - 16)
    smear_shift = np.random.randint(0, 16)
    total_off   = page_offset + smear_shift
    page = bytearray(PAGE_SIZE + 32)
    page[total_off: total_off + IMAGE_SIZE] = pixel_bytes
    return [1 if any(b != 0 for b in page[total_off + k*CHUNK_BYTES: total_off + (k+1)*CHUNK_BYTES]) else 0
            for k in range(196)]

def ssim_loss(pred, target, window_size=7):
    p, t = pred.unsqueeze(1), target.unsqueeze(1)
    C1, C2, w = 0.01**2, 0.03**2, window_size
    k = torch.ones(1, 1, w, w, device=pred.device) / (w * w)
    mu_p  = F.conv2d(p, k, padding=w // 2)
    mu_t  = F.conv2d(t, k, padding=w // 2)
    sig_p = F.conv2d(p * p, k, padding=w // 2) - mu_p ** 2
    sig_t = F.conv2d(t * t, k, padding=w // 2) - mu_t ** 2
    sig_pt= F.conv2d(p * t, k, padding=w // 2) - mu_p * mu_t
    num   = (2 * mu_p * mu_t + C1) * (2 * sig_pt + C2)
    den   = (mu_p ** 2 + mu_t ** 2 + C1) * (sig_p + sig_t + C2)
    return 1 - (num / den).mean()

class SparsityEncoder(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(196, 512), nn.BatchNorm1d(512), nn.ReLU(inplace=True),
            nn.Linear(512, 256), nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Linear(256, 128),
        )
    def forward(self, x):
        return F.normalize(self.net(x), dim=1)

class V10Decoder(nn.Module):
    def __init__(self, z_dim=128):
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
    def forward(self, z):
        x = F.relu(self.fc(z)).view(-1, 256, 7, 7)
        return self.net(x).squeeze(1)

class PatchDiscriminator(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(
            nn.Conv2d(1, 32, 4, stride=2, padding=1), nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(32, 64, 4, stride=2, padding=1), nn.BatchNorm2d(64), nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(64, 1, 3, padding=1),
        )
    def forward(self, img):
        return self.net(img.unsqueeze(1))

class V10Dataset(Dataset):
    def __init__(self, items, augment=True):
        self.items   = items
        self.augment = augment
    def __len__(self):
        return len(self.items)
    def __getitem__(self, idx):
        real_sp, img = self.items[idx]
        sp = augment_sparsity(img) if self.augment else real_sp
        return (torch.tensor(sp,  dtype=torch.float32),
                torch.tensor(img, dtype=torch.float32))

# ── Data loading ──────────────────────────────────────────────────────────────
LIST_DIR  = '/home/ubuntu/gpu_cc_io_attack'
JSON_PATH = './UNet_training_v3.json'

with open(JSON_PATH) as f:
    all_samples = json.load(f)
json_map = {s['sample_idx']: s for s in all_samples}

items = []
for fname in sorted(os.listdir(LIST_DIR)):
    if not fname.endswith('.out_v5.list'):
        continue
    m = re.search(r'-(\d+)\.out_v5\.list$', fname)
    if not m:
        continue
    idx = int(m.group(1))
    if idx not in json_map:
        continue
    with open(os.path.join(LIST_DIR, fname)) as f:
        real_sp = ast.literal_eval(f.read().strip())
    if len(real_sp) != 196:
        continue
    img = np.array(json_map[idx]['target_image'], dtype=np.float32)
    items.append((real_sp, img))

print(f'Total matched items: {len(items)}', flush=True)

# ── Hyperparameters ───────────────────────────────────────────────────────────
LAMBDA_ADV, LAMBDA_MSE, LAMBDA_SSIM = 0.1, 1.0, 0.5
EPOCHS = 200
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

# (train_ratio, val_ratio, tag)
SPLITS = [
    (0.6, 0.4, 'split60'),
    (0.7, 0.3, 'split70'),
    (0.8, 0.2, 'split80'),
]

rng  = np.random.default_rng(42)
perm = rng.permutation(len(items)).tolist()

# ── Per-split training loop ───────────────────────────────────────────────────
for train_ratio, val_ratio, tag in SPLITS:
    n_val       = max(1, int(len(items) * val_ratio))
    val_items   = [items[i] for i in perm[:n_val]]
    train_items = [items[i] for i in perm[n_val:]]

    model_out  = f'./v10_decoder_{tag}.pth'
    curves_out = f'./train_v10_cross_{tag}_curves.pdf'

    print('=' * 70, flush=True)
    print(f'[{tag}]  train={len(train_items)}  val={len(val_items)}  '
          f'ratio={int(train_ratio*10)}:{int(val_ratio*10)}', flush=True)
    print(f'        checkpoint → {model_out}', flush=True)
    print('=' * 70, flush=True)

    train_loader = DataLoader(V10Dataset(train_items, augment=True),
                              batch_size=32, shuffle=True,  num_workers=2, pin_memory=False)
    val_loader   = DataLoader(V10Dataset(val_items,   augment=False),
                              batch_size=32, shuffle=False, num_workers=2, pin_memory=False)

    enc = SparsityEncoder().to(device)
    enc.load_state_dict(torch.load('./sparsity_encoder_v6r_new.pth', map_location=device))
    enc.eval()
    for p in enc.parameters():
        p.requires_grad_(False)

    Dec = V10Decoder().to(device)
    D   = PatchDiscriminator().to(device)

    opt_Dec = optim.Adam(Dec.parameters(), lr=2e-4, betas=(0.5, 0.999))
    opt_D   = optim.Adam(D.parameters(),   lr=2e-4, betas=(0.5, 0.999))
    sch_Dec = optim.lr_scheduler.CosineAnnealingLR(opt_Dec, T_max=EPOCHS)
    sch_D   = optim.lr_scheduler.CosineAnnealingLR(opt_D,   T_max=EPOCHS)

    best_val = float('inf')
    history  = {'d': [], 'g': [], 'val_mse': [], 'val_ssim': []}

    for epoch in range(EPOCHS):
        Dec.train(); D.train()
        d_losses, g_losses = [], []

        for sp, img in train_loader:
            sp, img = sp.to(device), img.to(device)
            with torch.no_grad():
                z = enc(sp)

            fake   = Dec(z).detach()
            d_real = D(img);  d_fake = D(fake)
            d_loss = 0.5 * (
                F.binary_cross_entropy_with_logits(d_real, torch.ones_like(d_real)) +
                F.binary_cross_entropy_with_logits(d_fake, torch.zeros_like(d_fake))
            )
            opt_D.zero_grad(); d_loss.backward(); opt_D.step()

            fake   = Dec(z)
            g_loss = (LAMBDA_ADV  * F.binary_cross_entropy_with_logits(D(fake), torch.ones_like(D(fake))) +
                      LAMBDA_MSE  * F.mse_loss(fake, img) +
                      LAMBDA_SSIM * ssim_loss(fake, img))
            opt_Dec.zero_grad(); g_loss.backward(); opt_Dec.step()

            d_losses.append(d_loss.item())
            g_losses.append(g_loss.item())

        Dec.eval()
        val_mse_sum = val_ssim_sum = 0.0
        with torch.no_grad():
            for sp, img in val_loader:
                sp, img = sp.to(device), img.to(device)
                z    = enc(sp)
                fake = Dec(z)
                val_mse_sum  += F.mse_loss(fake, img).item()
                val_ssim_sum += ssim_loss(fake, img).item()
        sch_Dec.step(); sch_D.step()

        v_mse  = val_mse_sum  / len(val_loader)
        v_ssim = val_ssim_sum / len(val_loader)
        v_comb = LAMBDA_MSE * v_mse + LAMBDA_SSIM * v_ssim

        history['d'].append(np.mean(d_losses))
        history['g'].append(np.mean(g_losses))
        history['val_mse'].append(v_mse)
        history['val_ssim'].append(1 - v_ssim)

        save_tag = ""
        if v_comb < best_val:
            best_val = v_comb
            torch.save(Dec.state_dict(), model_out)
            save_tag = " ← saved"

        print(f"[{tag}] Epoch [{epoch+1:3d}/{EPOCHS}]  D: {np.mean(d_losses):.4f}  "
              f"G: {np.mean(g_losses):.4f}  val_mse: {v_mse:.6f}  "
              f"val_SSIM: {1-v_ssim:.4f}{save_tag}", flush=True)

    print(f"\n[{tag}] Done. Best combined val loss: {best_val:.6f} → {model_out}\n", flush=True)

    ep = range(1, EPOCHS + 1)
    fig, axes = plt.subplots(1, 2, figsize=(12, 4))
    axes[0].plot(ep, history['d'], label='D loss')
    axes[0].plot(ep, history['g'], label='G loss')
    axes[0].set_xlabel('Epoch')
    axes[0].set_title(f'Training Loss (v10_cross {tag})')
    axes[0].legend(); axes[0].grid(True)
    axes[1].plot(ep, history['val_ssim'], color='green', label='val SSIM')
    axes[1].set_xlabel('Epoch')
    axes[1].set_title(f'Validation SSIM (v10_cross {tag})')
    axes[1].legend(); axes[1].grid(True)
    plt.tight_layout()
    plt.savefig(curves_out)
    plt.close()
    print(f"Curve saved → {curves_out}", flush=True)

print("\nAll splits done.", flush=True)
