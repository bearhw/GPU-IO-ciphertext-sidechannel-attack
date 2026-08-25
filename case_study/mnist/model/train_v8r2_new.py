"""v8r2 retraining (new .out_v5.list + UNet_training_v5.json)
Output: unet_gan_generator_v8r2_new.pth
tmux: /home/eun/miniforge3/envs/mura/bin/python train_v8r2_new.py 2>&1 | tee train_v8r2_new.log
"""
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import numpy as np
import json, os, ast, re
from torch.utils.data import Dataset, DataLoader, ConcatDataset
from torchvision import datasets, transforms

CHUNK_BYTES = 16
PAGE_SIZE   = 4096
IMAGE_SIZE  = 3136

def augment_sparsity(pixel_arr):
    pixel_arr    = np.where(pixel_arr < 1e-4, 0.0, pixel_arr)
    pixel_bytes  = pixel_arr.flatten().astype(np.float32).tobytes()
    page_offset  = np.random.randint(0, PAGE_SIZE - IMAGE_SIZE - 16)
    smear_shift  = np.random.randint(0, 16)
    total_offset = page_offset + smear_shift
    page = bytearray(PAGE_SIZE + 32)
    page[total_offset: total_offset + IMAGE_SIZE] = pixel_bytes
    return [1 if any(b != 0 for b in page[total_offset + k*CHUNK_BYTES: total_offset + (k+1)*CHUNK_BYTES]) else 0
            for k in range(196)]

def sp_to_mask(sp):
    return F.interpolate(sp.view(-1, 1, 28, 7), size=(28, 28), mode='nearest')

def ssim_loss(pred, target, window_size=7):
    p, t = pred.unsqueeze(1), target.unsqueeze(1)
    C1, C2, w = 0.01**2, 0.03**2, window_size
    k = torch.ones(1, 1, w, w, device=pred.device) / (w * w)
    mu_p   = F.conv2d(p, k, padding=w//2)
    mu_t   = F.conv2d(t, k, padding=w//2)
    sig_p  = F.conv2d(p*p, k, padding=w//2) - mu_p**2
    sig_t  = F.conv2d(t*t, k, padding=w//2) - mu_t**2
    sig_pt = F.conv2d(p*t, k, padding=w//2) - mu_p * mu_t
    return 1 - ((2*mu_p*mu_t + C1)*(2*sig_pt + C2) /
                ((mu_p**2 + mu_t**2 + C1)*(sig_p + sig_t + C2))).mean()

class SparsityV5Dataset(Dataset):
    def __init__(self, samples, augment=True):
        self.samples = samples
        self.augment = augment
    def __len__(self):
        return len(self.samples)
    def __getitem__(self, idx):
        s     = self.samples[idx]
        img   = np.array(s['target_image'], dtype=np.float32)
        label = s['label']
        sp    = augment_sparsity(img) if self.augment else s['input_sparsity_seq']
        return (torch.tensor(sp,    dtype=torch.float32),
                torch.tensor(img,   dtype=torch.float32),
                torch.tensor(label, dtype=torch.long))

class RealListDataset(Dataset):
    def __init__(self, list_dir, images_db, index_filter=None):
        self.images_db = images_db
        self.items = []
        for fname in sorted(os.listdir(list_dir)):
            if not fname.endswith('.out_v5.list'):
                continue
            m_lbl = re.match(r'^(\d+)-', fname)
            m_idx = re.search(r'-(\d+)\.out_v5\.list$', fname)
            if not (m_lbl and m_idx):
                continue
            label    = int(m_lbl.group(1))
            true_idx = int(m_idx.group(1))
            if true_idx >= len(images_db):
                continue
            if index_filter is not None and true_idx not in index_filter:
                continue
            self.items.append((os.path.join(list_dir, fname), label, true_idx))
        print(f"  RealListDataset: {len(self.items)} files loaded", flush=True)
    def __len__(self):
        return len(self.items)
    def __getitem__(self, idx):
        fpath, label, true_idx = self.items[idx]
        with open(fpath) as f:
            sp = ast.literal_eval(f.read().strip())
        img = self.images_db[true_idx]
        return (torch.tensor(sp,    dtype=torch.float32),
                torch.tensor(img,   dtype=torch.float32),
                torch.tensor(label, dtype=torch.long))

class DoubleConv(nn.Sequential):
    def __init__(self, cin, cout):
        super().__init__(
            nn.Conv2d(cin, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
            nn.Conv2d(cout, cout, 3, padding=1), nn.BatchNorm2d(cout), nn.ReLU(inplace=True),
        )

class UNetGeneratorR(nn.Module):
    def __init__(self, n_classes=10):
        super().__init__()
        self.class_embed = nn.Embedding(n_classes, 28 * 28)
        self.enc1 = DoubleConv(2, 32)
        self.enc2 = nn.Sequential(nn.MaxPool2d(2), DoubleConv(32, 64))
        self.bot  = nn.Sequential(nn.MaxPool2d(2), DoubleConv(64, 256), nn.Dropout2d(0.2))
        self.up2  = nn.ConvTranspose2d(256, 64, kernel_size=2, stride=2)
        self.dec2 = DoubleConv(128, 64)
        self.up1  = nn.ConvTranspose2d(64, 32, kernel_size=2, stride=2)
        self.dec1 = DoubleConv(64, 32)
        self.out  = nn.Sequential(nn.Conv2d(32, 1, 1), nn.Sigmoid())
    def forward(self, sp, label):
        mask = sp_to_mask(sp)
        cls  = self.class_embed(label).view(-1, 1, 28, 28)
        x    = torch.cat([mask, cls], dim=1)
        e1 = self.enc1(x); e2 = self.enc2(e1); b = self.bot(e2)
        d2 = self.dec2(torch.cat([self.up2(b), e2], dim=1))
        d1 = self.dec1(torch.cat([self.up1(d2), e1], dim=1))
        return self.out(d1).squeeze(1)

class PatchDiscriminator(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(
            nn.Conv2d(2, 32, 4, 2, 1), nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(32, 64, 4, 2, 1), nn.BatchNorm2d(64), nn.LeakyReLU(0.2, inplace=True),
            nn.Conv2d(64, 1, 3, 1, 1),
        )
    def forward(self, img, mask):
        return self.net(torch.cat([img.unsqueeze(1), mask], dim=1))

mnist     = datasets.MNIST('./data', train=True, download=True, transform=transforms.ToTensor())
images_db = np.stack([mnist[i][0].squeeze().numpy() for i in range(len(mnist))])

OUT_LIST_DIR = '/home/ubuntu/gpu_cc_io_attack/'
real_index_set = set()
for fname in os.listdir(OUT_LIST_DIR):
    if not fname.endswith('.out_v5.list'):
        continue
    m = re.search(r'-(\d+)\.out_v5\.list$', fname)
    if m:
        real_index_set.add(int(m.group(1)))

print("Loading UNet_training_v5.json ...", flush=True)
with open('/home/ubuntu/gpu_cc_io_attack/UNet_training_v5.json') as f:
    all_samples = json.load(f)
matched = [s for s in all_samples if s['sample_idx'] in real_index_set]
print(f"  .out_v5.list index count : {len(real_index_set)}", flush=True)
print(f"  v5.json matched samples  : {len(matched)}", flush=True)

rng  = np.random.default_rng(42)
perm = rng.permutation(len(matched)).tolist()
n_tr = int(len(matched) * 0.9)

json_train_ds = SparsityV5Dataset([matched[i] for i in perm[:n_tr]], augment=True)
val_ds        = SparsityV5Dataset([matched[i] for i in perm[n_tr:]], augment=False)
val_indices   = {matched[i]['sample_idx'] for i in perm[n_tr:]}

real_ds = RealListDataset(OUT_LIST_DIR, images_db, index_filter=real_index_set - val_indices)
train_ds = ConcatDataset([json_train_ds, real_ds])

train_loader = DataLoader(train_ds, batch_size=128, shuffle=True,  num_workers=2, pin_memory=False)
val_loader   = DataLoader(val_ds,   batch_size=128, shuffle=False, num_workers=2, pin_memory=False)

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

G = UNetGeneratorR().to(device)
D = PatchDiscriminator().to(device)

LAMBDA_MSE  = 1.0
LAMBDA_SSIM = 1.5
LAMBDA_ADV  = 0.05

EPOCHS    = 100
best_val  = float('inf')
MODEL_OUT = './unet_gan_generator_v8r2_new.pth'

opt_G = optim.Adam(G.parameters(), lr=2e-4, betas=(0.5, 0.999))
opt_D = optim.Adam(D.parameters(), lr=2e-4, betas=(0.5, 0.999))
sch_G = optim.lr_scheduler.CosineAnnealingLR(opt_G, T_max=EPOCHS)
sch_D = optim.lr_scheduler.CosineAnnealingLR(opt_D, T_max=EPOCHS)

print(f"\nUNetGeneratorR (v8r2_new) | Device: {device}", flush=True)
print(f"  json_train : {len(json_train_ds)} (matched, augment_sparsity)", flush=True)
print(f"  real_ds    : {len(real_ds)} (.out_v5.list, real, val excluded)", flush=True)
print(f"  train total: {len(train_ds)}", flush=True)
print(f"  val        : {len(val_ds)} (matched, fixed sparsity)", flush=True)
print(f"G params: {sum(p.numel() for p in G.parameters()):,}  "
      f"D params: {sum(p.numel() for p in D.parameters()):,}", flush=True)
print("-" * 80)

for epoch in range(1, EPOCHS + 1):
    G.train(); D.train()
    d_losses, g_losses = [], []

    for sp, img, label in train_loader:
        sp, img, label = sp.to(device), img.to(device), label.to(device)
        mask = sp_to_mask(sp)

        fake   = G(sp, label).detach()
        d_real = F.binary_cross_entropy_with_logits(D(img,  mask), torch.ones_like(D(img,  mask)))
        d_fake = F.binary_cross_entropy_with_logits(D(fake, mask), torch.zeros_like(D(fake, mask)))
        opt_D.zero_grad(); ((d_real + d_fake) * 0.5).backward(); opt_D.step()

        fake   = G(sp, label)
        g_loss = (LAMBDA_ADV  * F.binary_cross_entropy_with_logits(D(fake, mask), torch.ones_like(D(fake, mask)))
                + LAMBDA_MSE  * F.mse_loss(fake, img)
                + LAMBDA_SSIM * ssim_loss(fake, img))
        opt_G.zero_grad(); g_loss.backward(); opt_G.step()

        d_losses.append((d_real + d_fake).item() * 0.5)
        g_losses.append(g_loss.item())

    G.eval()
    val_mse_sum = val_ssim_sum = 0.0
    with torch.no_grad():
        for sp, img, label in val_loader:
            sp, img, label = sp.to(device), img.to(device), label.to(device)
            fake = G(sp, label)
            val_mse_sum  += F.mse_loss(fake, img).item()
            val_ssim_sum += ssim_loss(fake, img).item()

    sch_G.step(); sch_D.step()

    v_mse  = val_mse_sum  / len(val_loader)
    v_ssim = 1 - val_ssim_sum / len(val_loader)
    v_comb = LAMBDA_MSE * v_mse + LAMBDA_SSIM * (1 - v_ssim)

    tag = ""
    if v_comb < best_val:
        best_val = v_comb
        torch.save(G.state_dict(), MODEL_OUT)
        tag = " ← saved"

    print(f"[{epoch:3d}/{EPOCHS}]  D:{np.mean(d_losses):.4f}  G:{np.mean(g_losses):.4f}"
          f"  mse:{v_mse:.5f}  SSIM:{v_ssim:.4f}{tag}", flush=True)

print(f"\nDone → {MODEL_OUT}  (best combined: {best_val:.5f})", flush=True)
