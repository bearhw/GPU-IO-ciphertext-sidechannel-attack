"""v9r retraining (new .out_v5.list matched indices)
Output: unet_gan_generator_v9r_new.pth
tmux: /home/eun/miniforge3/envs/mura/bin/python train_v9r_new.py 2>&1 | tee train_v9r_new.log
"""
import torch, torch.nn as nn, torch.nn.functional as F, torch.optim as optim
import numpy as np, json, os, re
from torch.utils.data import Dataset, DataLoader
from torchvision import datasets, transforms

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

def sp_to_mask(sp):
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

class MatchedJsonDataset(Dataset):
    def __init__(self, samples, augment=True):
        self.samples = samples
        self.augment = augment
    def __len__(self):
        return len(self.samples)
    def __getitem__(self, idx):
        s   = self.samples[idx]
        img = np.array(s['target_image'], dtype=np.float32)
        sp  = augment_sparsity(img) if self.augment else s['input_sparsity_seq']
        return (torch.tensor(sp,  dtype=torch.float32),
                torch.tensor(img, dtype=torch.float32))

LIST_DIR    = '/home/ubuntu/gpu_cc_io_attack'
list_idx    = {int(re.search(r'-(\d+)\.out_v5\.list$', f).group(1))
               for f in os.listdir(LIST_DIR) if f.endswith('.out_v5.list')}
JSON_PATH   = './UNet_training_v3.json'
with open(JSON_PATH) as f:
    all_samples = json.load(f)
matched = [s for s in all_samples if s['sample_idx'] in list_idx]
print(f'Matched samples: {len(matched)}', flush=True)

n_val   = max(1, len(matched) // 10)
n_train = len(matched) - n_val
rng     = np.random.default_rng(42)
perm    = rng.permutation(len(matched)).tolist()
train_samples = [matched[i] for i in perm[:n_train]]
val_samples   = [matched[i] for i in perm[n_train:]]

train_loader = DataLoader(MatchedJsonDataset(train_samples, augment=True),
                          batch_size=32, shuffle=True,  num_workers=2, pin_memory=False)
val_loader   = DataLoader(MatchedJsonDataset(val_samples,   augment=False),
                          batch_size=32, shuffle=False, num_workers=2, pin_memory=False)

class DoubleConv(nn.Sequential):
    def __init__(self, cin, cout):
        super().__init__(
            nn.Conv2d(cin, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
            nn.Conv2d(cout, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
        )

class UNetGeneratorV9(nn.Module):
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
    def forward(self, sp):
        x  = sp_to_mask(sp)
        e1 = self.enc1(x); e2 = self.enc2(e1); b = self.bot(e2)
        d2 = self.dec2(torch.cat([self.up2(b), e2], dim=1))
        d1 = self.dec1(torch.cat([self.up1(d2), e1], dim=1))
        return self.out(d1).squeeze(1)

class PatchDiscriminator(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(
            nn.Conv2d(2, 32, 4, stride=2, padding=1), nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(32, 64, 4, stride=2, padding=1), nn.BatchNorm2d(64), nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(64, 1, 3, padding=1),
        )
    def forward(self, img, mask):
        return self.net(torch.cat([img.unsqueeze(1), mask], dim=1))

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
G = UNetGeneratorV9().to(device)
D = PatchDiscriminator().to(device)
opt_G = optim.Adam(G.parameters(), lr=2e-4, betas=(0.5, 0.999))
opt_D = optim.Adam(D.parameters(), lr=2e-4, betas=(0.5, 0.999))
sch_G = optim.lr_scheduler.CosineAnnealingLR(opt_G, T_max=200)
sch_D = optim.lr_scheduler.CosineAnnealingLR(opt_D, T_max=200)

LAMBDA_ADV, LAMBDA_MSE, LAMBDA_SSIM = 0.1, 1.0, 0.5
EPOCHS    = 200
best_val  = float('inf')
MODEL_OUT = './unet_gan_generator_v9r_new.pth'

print(f"v9r_new | Device: {device} | Train: {n_train} | Val: {n_val}", flush=True)
print(f"G params: {sum(p.numel() for p in G.parameters()):,}", flush=True)
print("-" * 70)

for epoch in range(EPOCHS):
    G.train(); D.train()
    d_losses, g_losses = [], []
    for sp, img in train_loader:
        sp, img = sp.to(device), img.to(device)
        mask = sp_to_mask(sp)
        fake   = G(sp).detach()
        d_loss = ((F.binary_cross_entropy_with_logits(D(img,  mask), torch.ones_like(D(img,  mask))) +
                   F.binary_cross_entropy_with_logits(D(fake, mask), torch.zeros_like(D(fake, mask)))) * 0.5)
        opt_D.zero_grad(); d_loss.backward(); opt_D.step()
        fake   = G(sp)
        g_loss = (LAMBDA_ADV  * F.binary_cross_entropy_with_logits(D(fake, mask), torch.ones_like(D(fake, mask))) +
                  LAMBDA_MSE  * F.mse_loss(fake, img) +
                  LAMBDA_SSIM * ssim_loss(fake, img))
        opt_G.zero_grad(); g_loss.backward(); opt_G.step()
        d_losses.append(d_loss.item()); g_losses.append(g_loss.item())

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
    v_ssim = val_ssim_sum / len(val_loader)
    v_comb = LAMBDA_MSE * v_mse + LAMBDA_SSIM * v_ssim
    tag = ""
    if v_comb < best_val:
        best_val = v_comb
        torch.save(G.state_dict(), MODEL_OUT)
        tag = " ← saved"
    print(f"Epoch [{epoch+1:3d}/{EPOCHS}]  D: {np.mean(d_losses):.4f}  G: {np.mean(g_losses):.4f}  "
          f"val_mse: {v_mse:.6f}  val_SSIM: {1-v_ssim:.4f}{tag}", flush=True)

print(f"\nDone. Best: {best_val:.6f} → {MODEL_OUT}", flush=True)
