"""v9: UNet+PatchGAN, Sparsity Map Only (No Class Conditioning)"""
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import numpy as np
from torchvision import datasets, transforms
from torch.utils.data import Dataset, DataLoader, random_split
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

CHUNK_SIZE = 16
NUM_CHUNKS = 196  # 28 rows × 7 chunks/row

# ── Helpers ───────────────────────────────────────────────────────────────────

def compute_canonical_sparsity(pixel_arr):
    pixel_arr = np.where(pixel_arr < 1e-4, 0.0, pixel_arr)
    raw = pixel_arr.flatten().astype(np.float32).tobytes()
    return [1 if any(b != 0 for b in raw[k*CHUNK_SIZE:(k+1)*CHUNK_SIZE]) else 0
            for k in range(NUM_CHUNKS)]

def sp_to_mask(sp):
    """(B, 196) → (B, 1, 28, 28) binary spatial mask."""
    return F.interpolate(sp.view(-1, 1, 28, 7), size=(28, 28), mode='nearest')

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

# ── Dataset ───────────────────────────────────────────────────────────────────

class SparsityImageDataset(Dataset):
    def __init__(self, mnist_dataset):
        self.mnist = mnist_dataset

    def __len__(self):
        return len(self.mnist)

    def __getitem__(self, idx):
        img, _ = self.mnist[idx]
        sp = compute_canonical_sparsity(img.squeeze().numpy())
        return (torch.tensor(sp, dtype=torch.float32),
                img.squeeze(0).float())

# ── Architecture ──────────────────────────────────────────────────────────────

class DoubleConv(nn.Sequential):
    def __init__(self, cin, cout):
        super().__init__(
            nn.Conv2d(cin, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
            nn.Conv2d(cout, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
        )

class UNetGeneratorV9(nn.Module):
    """
    Input : sparsity (B, 196)  — NO class label
    Output: image   (B, 28, 28)
    """
    def __init__(self):
        super().__init__()
        self.enc1 = DoubleConv(1, 32)                                   # (32, 28, 28)
        self.enc2 = nn.Sequential(nn.MaxPool2d(2), DoubleConv(32, 64))  # (64, 14, 14)
        self.bot  = nn.Sequential(nn.MaxPool2d(2), DoubleConv(64, 128)) # (128, 7, 7)
        self.up2  = nn.ConvTranspose2d(128, 64, kernel_size=2, stride=2)
        self.dec2 = DoubleConv(128, 64)
        self.up1  = nn.ConvTranspose2d(64, 32, kernel_size=2, stride=2)
        self.dec1 = DoubleConv(64, 32)
        self.out  = nn.Sequential(nn.Conv2d(32, 1, 1), nn.Sigmoid())

    def forward(self, sp):
        x  = sp_to_mask(sp)                                          # (B, 1, 28, 28)
        e1 = self.enc1(x)                                            # (B, 32, 28, 28)
        e2 = self.enc2(e1)                                           # (B, 64, 14, 14)
        b  = self.bot(e2)                                            # (B, 128, 7, 7)
        d2 = self.dec2(torch.cat([self.up2(b), e2], dim=1))         # (B, 64, 14, 14)
        d1 = self.dec1(torch.cat([self.up1(d2), e1], dim=1))        # (B, 32, 28, 28)
        return self.out(d1).squeeze(1)                               # (B, 28, 28)

class PatchDiscriminator(nn.Module):
    """Input: cat(image, sparsity_mask) = (2, 28, 28) → patch score (1, 7, 7)"""
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(
            nn.Conv2d(2, 32, 4, stride=2, padding=1),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(32, 64, 4, stride=2, padding=1),
            nn.BatchNorm2d(64),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(64, 1, 3, padding=1),
        )

    def forward(self, img, mask):
        x = torch.cat([img.unsqueeze(1), mask], dim=1)  # (B, 2, 28, 28)
        return self.net(x)                               # (B, 1, 7, 7)

# ── Training ──────────────────────────────────────────────────────────────────

device  = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
mnist   = datasets.MNIST('./data', train=True, download=True, transform=transforms.ToTensor())
full_ds = SparsityImageDataset(mnist)

n_val   = 5000
n_train = len(full_ds) - n_val
train_ds, val_ds = random_split(full_ds, [n_train, n_val],
                                generator=torch.Generator().manual_seed(42))
train_loader = DataLoader(train_ds, batch_size=128, shuffle=True,  num_workers=2, pin_memory=False)
val_loader   = DataLoader(val_ds,   batch_size=128, shuffle=False, num_workers=2, pin_memory=False)

G = UNetGeneratorV9().to(device)
D = PatchDiscriminator().to(device)

opt_G = optim.Adam(G.parameters(), lr=2e-4, betas=(0.5, 0.999))
opt_D = optim.Adam(D.parameters(), lr=2e-4, betas=(0.5, 0.999))
sch_G = optim.lr_scheduler.CosineAnnealingLR(opt_G, T_max=50)
sch_D = optim.lr_scheduler.CosineAnnealingLR(opt_D, T_max=50)

LAMBDA_ADV  = 0.1
LAMBDA_MSE  = 1.0
LAMBDA_SSIM = 0.5
EPOCHS      = 50
best_val    = float('inf')

print(f"v9 UNet+PatchGAN | Device: {device} | Train: {n_train} | Val: {n_val}")
print(f"G params: {sum(p.numel() for p in G.parameters()):,}  "
      f"D params: {sum(p.numel() for p in D.parameters()):,}")
print("-" * 70)

history = {'d': [], 'g': [], 'val_mse': [], 'val_ssim': []}

for epoch in range(EPOCHS):
    G.train(); D.train()
    d_losses, g_losses = [], []

    for sp, img in train_loader:
        sp, img = sp.to(device), img.to(device)
        mask = sp_to_mask(sp)

        # ── Discriminator ──────────────────────────────────────────────────
        fake   = G(sp).detach()
        d_real = F.binary_cross_entropy_with_logits(D(img, mask),  torch.ones_like(D(img, mask)))
        d_fake = F.binary_cross_entropy_with_logits(D(fake, mask), torch.zeros_like(D(fake, mask)))
        d_loss = (d_real + d_fake) * 0.5
        opt_D.zero_grad(); d_loss.backward(); opt_D.step()

        # ── Generator ──────────────────────────────────────────────────────
        fake   = G(sp)
        adv_l  = F.binary_cross_entropy_with_logits(D(fake, mask), torch.ones_like(D(fake, mask)))
        mse_l  = F.mse_loss(fake, img)
        ssim_l = ssim_loss(fake, img)
        g_loss = LAMBDA_ADV * adv_l + LAMBDA_MSE * mse_l + LAMBDA_SSIM * ssim_l
        opt_G.zero_grad(); g_loss.backward(); opt_G.step()

        d_losses.append(d_loss.item())
        g_losses.append(g_loss.item())

    # ── Validation ─────────────────────────────────────────────────────────
    G.eval()
    val_mse_sum, val_ssim_sum = 0.0, 0.0
    with torch.no_grad():
        for sp, img in val_loader:
            sp, img = sp.to(device), img.to(device)
            fake = G(sp)
            val_mse_sum  += F.mse_loss(fake, img).item()
            val_ssim_sum += ssim_loss(fake, img).item()

    sch_G.step(); sch_D.step()

    v_mse  = val_mse_sum  / len(val_loader)
    v_ssim = val_ssim_sum / len(val_loader)   # 1 - SSIM (loss)
    v_comb = LAMBDA_MSE * v_mse + LAMBDA_SSIM * v_ssim

    history['d'].append(np.mean(d_losses))
    history['g'].append(np.mean(g_losses))
    history['val_mse'].append(v_mse)
    history['val_ssim'].append(1 - v_ssim)

    tag = ""
    if v_comb < best_val:
        best_val = v_comb
        torch.save(G.state_dict(), './unet_gan_generator_v9.pth')
        tag = " ← saved"

    print(f"Epoch [{epoch+1:3d}/{EPOCHS}]  "
          f"D: {np.mean(d_losses):.4f}  G: {np.mean(g_losses):.4f}  "
          f"val_mse: {v_mse:.6f}  val_SSIM: {1-v_ssim:.4f}{tag}", flush=True)

print(f"\nDone. Best val combined: {best_val:.6f} → unet_gan_generator_v9.pth")

# ── Save training curve ────────────────────────────────────────────────────────
fig, axes = plt.subplots(1, 2, figsize=(12, 4))
epochs = range(1, EPOCHS + 1)
axes[0].plot(epochs, history['d'], label='D loss')
axes[0].plot(epochs, history['g'], label='G loss')
axes[0].set_xlabel('Epoch'); axes[0].set_ylabel('Loss')
axes[0].set_title('Training Loss'); axes[0].legend(); axes[0].grid(True)
axes[1].plot(epochs, history['val_ssim'], label='val SSIM', color='green')
axes[1].set_xlabel('Epoch'); axes[1].set_ylabel('SSIM')
axes[1].set_title('Validation SSIM'); axes[1].legend(); axes[1].grid(True)
plt.tight_layout()
plt.savefig('./train_v9_curves.pdf')
print("Curve saved → train_v9_curves.pdf")
