"""
XorSliceResNet training script — ref-32 & ref-64 (density-based ref selection)

Prerequisites:
  ./mura_downloads/          MURA dataset
  ./xor_density_survey.npy   density survey result from mura_bodypart_attacker.ipynb

Output:
  ./mura_xor_slice_32ref.pth
  ./mura_xor_slice_64ref.pth
  ./mura_xor32_confusion_matrix.pdf
  ./mura_xor64_confusion_matrix.pdf

Run:
  tmux new -s train
  conda activate mura
  cd .
  python train_64ref.py 2>&1 | tee train_log.txt
"""
import os, sys, glob, time
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
from concurrent.futures import ThreadPoolExecutor, as_completed
from PIL import Image
from sklearn.metrics import confusion_matrix, classification_report
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

# ── Constants ────────────────────────────────────────────────────────────────
DATA_ROOT   = "./mura_downloads"
CLASSES     = ["ELBOW","FINGER","FOREARM","HAND","HUMERUS","SHOULDER","WRIST"]
CLASS2IDX   = {c: i for i, c in enumerate(CLASSES)}
XOR_ROWS    = 224
XOR_COLS    = 56
CHUNK_BYTES = 16
EPOCHS      = 50
SEED        = 42

torch.manual_seed(SEED)
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Device: {device}", flush=True)

# ── Load data paths ───────────────────────────────────────────────────────────
def collect_paths_labels(split):
    paths, labels = [], []
    for cls in CLASSES:
        pattern = os.path.join(DATA_ROOT, split, f"XR_{cls}", "**", "*.png")
        for p in glob.glob(pattern, recursive=True):
            paths.append(p); labels.append(CLASS2IDX[cls])
    return paths, labels

tr_paths, tr_labels = collect_paths_labels("train")
va_paths, va_labels = collect_paths_labels("valid")
print(f"Train {len(tr_paths):,}  Valid {len(va_paths):,}", flush=True)

# ── Ref chunk helper ─────────────────────────────────────────────────────────
def _make_ref_chunk(u8_val):
    f32 = np.array([u8_val], dtype=np.float32) / np.float32(255)
    return np.tile(f32.view(np.uint8), 4)   # (16,) bytes

# ── Density survey -> ref selection ───────────────────────────────────────────
DENSITY_SURVEY_PATH = "./xor_density_survey.npy"
if not os.path.exists(DENSITY_SURVEY_PATH):
    sys.exit(
        f"ERROR: {DENSITY_SURVEY_PATH} not found.\n"
        "Run the density survey cell in mura_bodypart_attacker.ipynb first."
    )

_hit    = np.load(DENSITY_SURVEY_PATH)           # (256,) int64
_ranked = np.argsort(-_hit).tolist()             # u8 sorted by density desc

REF_U8_32 = _ranked[:32]
REF_U8_64 = _ranked[:64]
N_REF_32, N_REF_64 = 32, 64

assert REF_U8_64[:32] == REF_U8_32, "nested [:32] broken"

REF_CHUNKS_64 = np.array([_make_ref_chunk(k) for k in REF_U8_64], dtype=np.uint8)  # (64, 16)

print(f"REF_U8_32[:8] = {REF_U8_32[:8]}", flush=True)
print(f"REF_U8_64[:8] = {REF_U8_64[:8]}", flush=True)

# ── 64-ref cache (32-ref shares via [:, :32] slicing) ────────────────────────
CACHE_DIR_64       = "./xor_cache_64"
TR_SLICES_64_PATH  = os.path.join(CACHE_DIR_64, "tr_slices.npy")
TR_ASPECTS_64_PATH = os.path.join(CACHE_DIR_64, "tr_aspects.npy")
VA_SLICES_64_PATH  = os.path.join(CACHE_DIR_64, "va_slices.npy")
VA_ASPECTS_64_PATH = os.path.join(CACHE_DIR_64, "va_aspects.npy")
os.makedirs(CACHE_DIR_64, exist_ok=True)

def _compute_one_64(path):
    img = Image.open(path).convert("L")
    orig_w, orig_h = img.size
    arr_f32 = np.array(img.resize((224, 224), Image.BILINEAR),
                       dtype=np.float32) / np.float32(255)
    chunks = arr_f32.flatten().view(np.uint8).reshape(XOR_ROWS, XOR_COLS, CHUNK_BYTES)
    xor    = chunks[np.newaxis] ^ REF_CHUNKS_64[:, np.newaxis, np.newaxis, :]
    return (xor == 0).all(axis=3), np.float32(orig_h / max(orig_w, 1))

def build_cache_64(paths, slices_path, aspects_path, tag=""):
    n       = len(paths)
    mm      = np.lib.format.open_memmap(slices_path, mode='w+',
                                        dtype=bool, shape=(n, N_REF_64, XOR_ROWS, XOR_COLS))
    aspects = np.zeros(n, dtype=np.float32)
    WORKERS = min(16, os.cpu_count() or 8)
    t0 = time.time()
    with ThreadPoolExecutor(max_workers=WORKERS) as ex:
        futs = {ex.submit(_compute_one_64, p): i for i, p in enumerate(paths)}
        done = 0
        for fut in as_completed(futs):
            i = futs[fut]
            mm[i], aspects[i] = fut.result()
            done += 1
            if done % 5000 == 0:
                print(f"  [{tag}] {done:>6}/{n}  {time.time()-t0:.0f}s", flush=True)
    np.save(aspects_path, aspects)
    print(f"  [{tag}] done → {slices_path} ({os.path.getsize(slices_path)/1e9:.1f} GB)  "
          f"{time.time()-t0:.0f}s", flush=True)
    return mm, aspects

if not os.path.exists(TR_SLICES_64_PATH):
    print(f"Building train cache ({len(tr_paths):,} × {N_REF_64} refs)...", flush=True)
    tr_slices64_mm, tr_aspects64 = build_cache_64(
        tr_paths, TR_SLICES_64_PATH, TR_ASPECTS_64_PATH, "train")
else:
    print("Loading train cache (memmap)...", flush=True)
    tr_slices64_mm = np.lib.format.open_memmap(TR_SLICES_64_PATH, mode='r')
    tr_aspects64   = np.load(TR_ASPECTS_64_PATH)

if not os.path.exists(VA_SLICES_64_PATH):
    print(f"Building valid cache ({len(va_paths):,} × {N_REF_64} refs)...", flush=True)
    va_slices64_mm, va_aspects64 = build_cache_64(
        va_paths, VA_SLICES_64_PATH, VA_ASPECTS_64_PATH, "valid")
else:
    print("Loading valid cache (memmap)...", flush=True)
    va_slices64_mm = np.lib.format.open_memmap(VA_SLICES_64_PATH, mode='r')
    va_aspects64   = np.load(VA_ASPECTS_64_PATH)

print(f"Train: {tr_slices64_mm.shape}  Valid: {va_slices64_mm.shape}", flush=True)

# ── Dataset ───────────────────────────────────────────────────────────────────
class XorSliceCachedDataset(Dataset):
    def __init__(self, slices_mm, aspects, labels, augment=False):
        self.slices  = slices_mm
        self.aspects = aspects
        self.labels  = labels
        self.augment = augment

    def __len__(self): return len(self.labels)

    def __getitem__(self, idx):
        slices = self.slices[idx].astype(np.float32)
        if self.augment:
            flip   = (np.random.random(slices.shape) < 0.005).astype(np.float32)
            slices = np.abs(slices - flip)
        return (torch.from_numpy(slices),
                torch.tensor([self.aspects[idx]], dtype=torch.float32),
                self.labels[idx])

# ── Model ────────────────────────────────────────────────────────────────────
class ResBlock(nn.Module):
    def __init__(self, in_ch, out_ch, stride=1):
        super().__init__()
        self.c1   = nn.Conv2d(in_ch, out_ch, 3, stride=stride, padding=1, bias=False)
        self.b1   = nn.BatchNorm2d(out_ch)
        self.c2   = nn.Conv2d(out_ch, out_ch, 3, padding=1, bias=False)
        self.b2   = nn.BatchNorm2d(out_ch)
        self.down = nn.Sequential(
            nn.Conv2d(in_ch, out_ch, 1, stride=stride, bias=False),
            nn.BatchNorm2d(out_ch),
        ) if (stride != 1 or in_ch != out_ch) else nn.Identity()

    def forward(self, x):
        return F.relu(self.b2(self.c2(F.relu(self.b1(self.c1(x))))) + self.down(x))


class XorSliceResNet(nn.Module):
    def __init__(self, num_classes=7, n_ref=32):
        super().__init__()
        self.stem   = nn.Sequential(
            nn.Conv2d(n_ref, 32, kernel_size=(7, 3), stride=(2, 1),
                      padding=(3, 1), bias=False),
            nn.BatchNorm2d(32), nn.ReLU(inplace=True),
        )
        self.pool1  = nn.MaxPool2d(kernel_size=(2, 1), stride=(2, 1))
        self.layer1 = ResBlock(32,  64,  stride=1)
        self.layer2 = ResBlock(64,  128, stride=2)
        self.layer3 = ResBlock(128, 256, stride=2)
        self.layer4 = ResBlock(256, 512, stride=2)
        self.gap    = nn.AdaptiveAvgPool2d(1)
        self.head   = nn.Sequential(
            nn.Linear(512 + 1, 256), nn.ReLU(inplace=True),
            nn.Dropout(0.4),
            nn.Linear(256, num_classes),
        )

    def forward(self, x, sc):
        x = self.pool1(self.stem(x))
        x = self.layer1(x); x = self.layer2(x)
        x = self.layer3(x); x = self.layer4(x)
        return self.head(torch.cat([self.gap(x).flatten(1), sc], dim=1))

# ── Training + Evaluation ────────────────────────────────────────────────────
def _make_loaders(n_ref, batch):
    pin = torch.cuda.is_available()
    tr_ds = XorSliceCachedDataset(tr_slices64_mm[:, :n_ref], tr_aspects64, tr_labels, augment=True)
    va_ds = XorSliceCachedDataset(va_slices64_mm[:, :n_ref], va_aspects64, va_labels, augment=False)
    tr_ld = DataLoader(tr_ds, batch_size=batch, shuffle=True,
                       num_workers=8, pin_memory=pin, persistent_workers=True)
    va_ld = DataLoader(va_ds, batch_size=batch, shuffle=False,
                       num_workers=4, pin_memory=pin, persistent_workers=True)
    return tr_ld, va_ld


def run_ref_config(n_ref, epochs=EPOCHS, batch=128):
    model_path = f"./mura_xor_slice_{n_ref}ref.pth"
    tr_ld, va_ld = _make_loaders(n_ref, batch)
    model    = XorSliceResNet(len(CLASSES), n_ref=n_ref).to(device)
    n_params = sum(p.numel() for p in model.parameters())
    print(f"\n{'='*64}", flush=True)
    print(f"[{n_ref}-ref]  params={n_params:,}  batch={batch}  epochs={epochs}", flush=True)
    print(f"  train={len(tr_ld.dataset):,} ({len(tr_ld)} batches)  "
          f"valid={len(va_ld.dataset):,} ({len(va_ld)} batches)", flush=True)
    print(f"{'='*64}", flush=True)

    counts = np.bincount(tr_labels, minlength=len(CLASSES))
    w = torch.tensor(counts.sum() / (len(CLASSES) * counts), dtype=torch.float32).to(device)
    crit  = nn.CrossEntropyLoss(weight=w, label_smoothing=0.1)
    opt   = optim.AdamW(model.parameters(), lr=3e-4, weight_decay=1e-4)
    sched = optim.lr_scheduler.CosineAnnealingLR(opt, T_max=epochs)

    best = 0.0
    for epoch in range(1, epochs + 1):
        t0 = time.time()
        model.train()
        trl, trc, trt = 0., 0, 0
        for imgs, sc, lbl in tr_ld:
            imgs, sc, lbl = imgs.to(device), sc.to(device), lbl.to(device)
            opt.zero_grad()
            out  = model(imgs, sc)
            loss = crit(out, lbl)
            loss.backward(); opt.step()
            trl += loss.item() * imgs.size(0)
            trc += out.argmax(1).eq(lbl).sum().item()
            trt += imgs.size(0)
        sched.step()

        model.eval()
        val, vac, vat = 0., 0, 0
        with torch.no_grad():
            for imgs, sc, lbl in va_ld:
                imgs, sc, lbl = imgs.to(device), sc.to(device), lbl.to(device)
                out = model(imgs, sc)
                val += crit(out, lbl).item() * imgs.size(0)
                vac += out.argmax(1).eq(lbl).sum().item()
                vat += imgs.size(0)
        va = 100. * vac / vat
        tag = ""
        if va > best:
            best = va
            torch.save(model.state_dict(), model_path)
            tag = " ← saved"
        print(f"[{n_ref}-ref {epoch:2d}/{epochs}]  "
              f"tr {trl/trt:.4f}/{100.*trc/trt:.1f}%  "
              f"va {val/vat:.4f}/{va:.1f}%  {time.time()-t0:.0f}s{tag}", flush=True)

    print(f"\n[{n_ref}-ref] Best val: {best:.1f}%  → {model_path}", flush=True)
    return best, model_path


def eval_ref_config(n_ref, model_path=None):
    model_path = model_path or f"./mura_xor_slice_{n_ref}ref.pth"
    _, va_ld   = _make_loaders(n_ref, batch=128)
    model      = XorSliceResNet(len(CLASSES), n_ref=n_ref).to(device)
    model.load_state_dict(torch.load(model_path, map_location=device, weights_only=True))
    model.eval()

    preds, trues = [], []
    with torch.no_grad():
        for imgs, sc, lbl in va_ld:
            preds.extend(model(imgs.to(device), sc.to(device)).argmax(1).cpu().numpy())
            trues.extend(lbl.numpy())
    preds, trues = np.array(preds), np.array(trues)

    print(f"\n===== {n_ref}-ref evaluation =====", flush=True)
    print(classification_report(trues, preds, target_names=CLASSES), flush=True)
    print("Per-class accuracy:", flush=True)
    for i, c in enumerate(CLASSES):
        m = trues == i
        print(f"  {c:10s}: {(preds[m]==i).mean()*100:.1f}%  ({m.sum()} samples)", flush=True)

    cm = confusion_matrix(trues, preds)
    fig, ax = plt.subplots(figsize=(8, 6))
    im = ax.imshow(cm, cmap='Blues'); fig.colorbar(im, ax=ax)
    ax.set(xticks=range(7), yticks=range(7), xticklabels=CLASSES, yticklabels=CLASSES,
           ylabel='True', xlabel='Predicted',
           title=f'XorSliceResNet — {n_ref} ref pages (density-based)')
    plt.setp(ax.get_xticklabels(), rotation=45, ha='right')
    thresh = cm.max() / 2
    for i in range(7):
        for j in range(7):
            ax.text(j, i, cm[i, j], ha='center', va='center',
                    color='white' if cm[i, j] > thresh else 'black')
    plt.tight_layout()
    pdf_path = f"./mura_xor{n_ref}_confusion_matrix.pdf"
    plt.savefig(pdf_path, format='pdf', bbox_inches='tight')
    plt.close()
    print(f"Saved → {pdf_path}", flush=True)
    return preds, trues

# ── main ──────────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    t_start = time.time()

    best_32, _ = run_ref_config(32, epochs=EPOCHS, batch=128)
    eval_ref_config(32)

    best_64, _ = run_ref_config(64, epochs=EPOCHS, batch=96)
    eval_ref_config(64)

    elapsed = time.time() - t_start
    print(f"\n{'='*40}", flush=True)
    print(f"  32-ref best val: {best_32:.1f}%", flush=True)
    print(f"  64-ref best val: {best_64:.1f}%", flush=True)
    print(f"  Total time: {elapsed/3600:.1f}h", flush=True)
    print(f"{'='*40}", flush=True)
