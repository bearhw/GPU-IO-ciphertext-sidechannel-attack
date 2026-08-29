"""v6r retraining (new .out_v5.list data)
Output: sparsity_encoder_v6r_new.pth, v6r_embeddings_new.npy, v6r_images_new.npy
tmux: python train_v6r_new.py 2>&1 | tee train_v6r_new.log
"""
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

def compute_canonical_sparsity(pixel_arr):
    pixel_arr = np.where(pixel_arr < 1e-4, 0.0, pixel_arr)
    raw       = pixel_arr.flatten().astype(np.float32).tobytes()
    return [1 if any(b != 0 for b in raw[k*16: (k+1)*16]) else 0 for k in range(196)]

class RealPairDataset(Dataset):
    def __init__(self, list_dir, images_db):
        self.images_db = images_db
        self.items = []
        for fname in sorted(os.listdir(list_dir)):
            if not fname.endswith('.out_v5.list'):
                continue
            m_idx = re.search(r'-(\d+)\.out_v5\.list$', fname)
            if not m_idx:
                continue
            true_idx = int(m_idx.group(1))
            if true_idx < len(images_db):
                self.items.append((os.path.join(list_dir, fname), true_idx))
        print(f'  RealPairDataset: {len(self.items)} pairs loaded', flush=True)

    def __len__(self):
        return len(self.items)

    def __getitem__(self, idx):
        fpath, true_idx = self.items[idx]
        with open(fpath) as f:
            real_sp = ast.literal_eval(f.read().strip())
        aug_sp = augment_sparsity(self.images_db[true_idx])
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

# ── Stage 1: Training ─────────────────────────────────────────────────────────
device    = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
mnist     = datasets.MNIST('./data', train=True, download=True, transform=transforms.ToTensor())
images_db = np.stack([mnist[i][0].squeeze().numpy() for i in range(len(mnist))])

OUT_LIST_DIR = '/home/ubuntu/gpu_cc_io_attack'
dataset      = RealPairDataset(OUT_LIST_DIR, images_db)
EPOCHS       = len(dataset)
loader       = DataLoader(dataset, batch_size=64, shuffle=True, num_workers=2, pin_memory=False)
LOG_EVERY    = max(1, EPOCHS // 20)

encoder   = SparsityEncoder().to(device)
optimizer = optim.Adam(encoder.parameters(), lr=1e-3, weight_decay=1e-4)
scheduler = optim.lr_scheduler.CosineAnnealingLR(optimizer, T_max=EPOCHS)

MODEL_OUT = './sparsity_encoder_v6r_new.pth'
best_loss = float('inf')
print(f'v6r_new Training | Device: {device} | Real samples: {len(dataset)} | EPOCHS: {EPOCHS}', flush=True)
print(f'Batch size: 64 | Batches/epoch: {len(loader)} | Total steps: {EPOCHS * len(loader)}', flush=True)
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
        torch.save(encoder.state_dict(), MODEL_OUT)
        tag = ' ← saved'
    if epoch % LOG_EVERY == 0 or epoch == EPOCHS:
        print(f'Epoch [{epoch:5d}/{EPOCHS}]  Loss: {avg:.4f}{tag}', flush=True)

print(f'\nStage 1 done. Best loss: {best_loss:.4f} → {MODEL_OUT}', flush=True)

# ── Stage 3: Build Embedding Database (60,000 MNIST) ─────────────────────────
print('\nBuilding v6r_new embedding database (60,000 MNIST) ...', flush=True)
encoder.load_state_dict(torch.load(MODEL_OUT, map_location=device))
encoder.eval()

all_embeddings, all_images = [], []
BATCH = 512
with torch.no_grad():
    batch_sp, batch_imgs = [], []
    for idx in range(len(mnist)):
        img, _ = mnist[idx]
        px = img.squeeze().numpy()
        batch_sp.append(compute_canonical_sparsity(px))
        batch_imgs.append(px)
        if len(batch_sp) == BATCH or idx == len(mnist) - 1:
            sp_t = torch.tensor(batch_sp, dtype=torch.float32).to(device)
            all_embeddings.append(encoder(sp_t).cpu().numpy())
            all_images.extend(batch_imgs)
            batch_sp, batch_imgs = [], []
        if (idx + 1) % 10000 == 0:
            print(f'  {idx+1}/60000 done', flush=True)

embeddings_db = np.vstack(all_embeddings).astype(np.float32)
images_db_out = np.stack(all_images).astype(np.float32)

np.save('./v6r_embeddings_new.npy', embeddings_db)
np.save('./v6r_images_new.npy',     images_db_out)
print(f'\nDone. → v6r_embeddings_new.npy {embeddings_db.shape}, v6r_images_new.npy {images_db_out.shape}', flush=True)
