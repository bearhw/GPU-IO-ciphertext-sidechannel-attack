# ── v6r Stage 1: Real-Data Contrastive Training ─────────────────────────────
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import numpy as np
import os, ast, re
from torchvision import datasets, transforms
from torch.utils.data import Dataset, DataLoader

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

class RealPairDataset(Dataset):
    """Contrastive pair = (real captured sparsity, synthetic sparsity of its clean GT).
    Pulling the two views together teaches the encoder to map a noisy real attack
    capture into the same embedding as its clean digit — which is exactly what the
    retrieval DB and the v10 decoder (frozen encoder) need. Only the input SOURCE
    changed to real end-to-end captures; the contrastive objective is unchanged."""
    def __init__(self, items):
        self.items = items     # list of (real_sp: list[int], gt_img: np.ndarray)
        print(f'  RealPairDataset: {len(self.items)} pairs loaded')

    def __len__(self):
        return len(self.items)

    def __getitem__(self, idx):
        real_sp, gt_img = self.items[idx]
        aug_sp = augment_sparsity(gt_img)
        return (torch.tensor(real_sp, dtype=torch.float32),
                torch.tensor(aug_sp,  dtype=torch.float32))

class SparsityEncoder(nn.Module):
    def __init__(self, input_dim=196, embed_dim=128):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(input_dim, 512), nn.BatchNorm1d(512), nn.ReLU(inplace=True),
            nn.Linear(512, 256),       nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Linear(256, embed_dim),
        )
    def forward(self, x):
        return F.normalize(self.net(x), dim=1)

def nt_xent_loss(z1, z2, temperature=0.1):
    B   = z1.size(0)
    z   = torch.cat([z1, z2], dim=0)
    sim = torch.mm(z, z.T) / temperature
    sim.fill_diagonal_(-1e9)
    labels = torch.cat([torch.arange(B, 2*B), torch.arange(B)]).to(z.device)
    return F.cross_entropy(sim, labels)

device    = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

# Real end-to-end attack captures, shared with train_v9r / train_v10 (capture_data).
from capture_data import load_items
items, _msg = load_items()
print(f'[v6r] {_msg}')
if not items:
    raise SystemExit('No training data: set CAPTURE_DIR to a dir with '
                     'sparsities_*_bs*_idx*.npy, or provide legacy .out_v5.list files.')

dataset      = RealPairDataset(items)
# Original used EPOCHS = len(dataset), which explodes with larger capture sets; use a
# fixed, env-overridable epoch count instead.
EPOCHS       = int(os.environ.get('V6R_EPOCHS', '200'))
loader       = DataLoader(dataset, batch_size=64, shuffle=True, num_workers=2, pin_memory=False)
LOG_EVERY    = max(1, EPOCHS // 20)

encoder   = SparsityEncoder().to(device)
optimizer = optim.Adam(encoder.parameters(), lr=1e-3, weight_decay=1e-4)
scheduler = optim.lr_scheduler.CosineAnnealingLR(optimizer, T_max=EPOCHS)

best_loss = float('inf')
print(f'v6r Training | Device: {device} | Real samples: {len(dataset)} | EPOCHS: {EPOCHS}')
print(f'Batch size: 64 | Batches/epoch: {len(loader)} | Total steps: {EPOCHS * len(loader)}')
print('-' * 70)

for epoch in range(1, EPOCHS + 1):
    encoder.train()
    total_loss = 0.0
    for sp_real, sp_aug in loader:
        sp_real, sp_aug = sp_real.to(device), sp_aug.to(device)
        optimizer.zero_grad()
        loss = nt_xent_loss(encoder(sp_real), encoder(sp_aug))
        loss.backward()
        optimizer.step()
        total_loss += loss.item()
    scheduler.step()
    avg = total_loss / len(loader)
    tag = ''
    if avg < best_loss:
        best_loss = avg
        torch.save(encoder.state_dict(), './sparsity_encoder_v6r.pth')
        tag = ' ← saved'
    if epoch % LOG_EVERY == 0 or epoch == EPOCHS:
        print(f'Epoch [{epoch:5d}/{EPOCHS}]  Loss: {avg:.4f}{tag}')

print(f'\nDone. Best loss: {best_loss:.4f} → sparsity_encoder_v6r.pth')
