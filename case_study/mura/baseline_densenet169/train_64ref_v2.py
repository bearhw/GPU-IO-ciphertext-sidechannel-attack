"""
XorSliceSENet 학습 스크립트 — ref-64 (v2, SE-ResNet + global-stats branch)

v1 (XorSliceResNet) 대비 변경:
  1. SEResBlock: Squeeze-and-Excitation — ref 채널 단위 중요도 가중치 학습
  2. Global stats branch: 각 ref별 매칭 청크 수(공간 합산) → MLP → spatial feature와 concat
  3. LR warmup 5 epoch + cosine annealing
  4. stem/layer 채널 확장: 64→128→256→512→1024

캐시 호환:
  xor_cache_64/ 는 train_64ref.py 와 공유 (재사용)

사전 조건:
  ./mura_downloads/          MURA 데이터셋
  ./xor_density_survey.npy   density survey 결과

출력:
  ./mura_xor_slice_64ref_v2.pth
  ./mura_xor64_v2_confusion_matrix.pdf

실행:
  conda activate mura
  cd /home/eun/bnb/mura
  python train_64ref_v2.py 2>&1 | tee train_64ref_v2.log
"""
import os, sys, glob, time, math
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

# ── 상수 ──────────────────────────────────────────────────────────────────────
DATA_ROOT   = "./mura_downloads"
CLASSES     = ["ELBOW","FINGER","FOREARM","HAND","HUMERUS","SHOULDER","WRIST"]
CLASS2IDX   = {c: i for i, c in enumerate(CLASSES)}
XOR_ROWS    = 224
XOR_COLS    = 56
CHUNK_BYTES = 16
N_REF       = 64
EPOCHS      = 60
WARMUP_EP   = 5
SEED        = 42

torch.manual_seed(SEED)
np.random.seed(SEED)
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Device: {device}", flush=True)

# ── 데이터 경로 ────────────────────────────────────────────────────────────────
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

# ── ref chunk 선택 ────────────────────────────────────────────────────────────
DENSITY_SURVEY_PATH = "./xor_density_survey.npy"
if not os.path.exists(DENSITY_SURVEY_PATH):
    sys.exit(f"ERROR: {DENSITY_SURVEY_PATH} not found.")

_hit    = np.load(DENSITY_SURVEY_PATH)
_ranked = np.argsort(-_hit).tolist()
REF_U8_64 = _ranked[:N_REF]

def _make_ref_chunk(u8_val):
    f32 = np.array([u8_val], dtype=np.float32) / np.float32(255)
    return np.tile(f32.view(np.uint8), 4)

REF_CHUNKS_64 = np.array([_make_ref_chunk(k) for k in REF_U8_64], dtype=np.uint8)
print(f"REF_U8_64[:8] = {REF_U8_64[:8]}", flush=True)

# ── 캐시 (train_64ref.py 와 공유) ─────────────────────────────────────────────
CACHE_DIR_64       = "./xor_cache_64"
TR_SLICES_64_PATH  = os.path.join(CACHE_DIR_64, "tr_slices.npy")
TR_ASPECTS_64_PATH = os.path.join(CACHE_DIR_64, "tr_aspects.npy")
VA_SLICES_64_PATH  = os.path.join(CACHE_DIR_64, "va_slices.npy")
VA_ASPECTS_64_PATH = os.path.join(CACHE_DIR_64, "va_aspects.npy")
os.makedirs(CACHE_DIR_64, exist_ok=True)

def _compute_one_64(path):
    img = Image.open(path).convert("L")
    orig_w, orig_h = img.size
    arr = np.array(img.resize((224, 224), Image.BILINEAR), dtype=np.float32) / np.float32(255)
    chunks = arr.flatten().view(np.uint8).reshape(XOR_ROWS, XOR_COLS, CHUNK_BYTES)
    xor    = chunks[np.newaxis] ^ REF_CHUNKS_64[:, np.newaxis, np.newaxis, :]
    return (xor == 0).all(axis=3), np.float32(orig_h / max(orig_w, 1))

def build_cache_64(paths, slices_path, aspects_path, tag=""):
    n  = len(paths)
    mm = np.lib.format.open_memmap(slices_path, mode='w+',
                                   dtype=bool, shape=(n, N_REF, XOR_ROWS, XOR_COLS))
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
    print(f"  [{tag}] done  {time.time()-t0:.0f}s", flush=True)
    return mm, aspects

if not os.path.exists(TR_SLICES_64_PATH):
    print(f"Building train cache...", flush=True)
    tr_slices_mm, tr_aspects = build_cache_64(
        tr_paths, TR_SLICES_64_PATH, TR_ASPECTS_64_PATH, "train")
else:
    print("Loading train cache (memmap)...", flush=True)
    tr_slices_mm = np.lib.format.open_memmap(TR_SLICES_64_PATH, mode='r')
    tr_aspects   = np.load(TR_ASPECTS_64_PATH)

if not os.path.exists(VA_SLICES_64_PATH):
    print(f"Building valid cache...", flush=True)
    va_slices_mm, va_aspects = build_cache_64(
        va_paths, VA_SLICES_64_PATH, VA_ASPECTS_64_PATH, "valid")
else:
    print("Loading valid cache (memmap)...", flush=True)
    va_slices_mm = np.lib.format.open_memmap(VA_SLICES_64_PATH, mode='r')
    va_aspects   = np.load(VA_ASPECTS_64_PATH)

print(f"Train: {tr_slices_mm.shape}  Valid: {va_slices_mm.shape}", flush=True)

# ── Dataset ───────────────────────────────────────────────────────────────────
class XorSliceCachedDataset(Dataset):
    def __init__(self, slices_mm, aspects, labels, augment=False):
        self.slices  = slices_mm
        self.aspects = aspects
        self.labels  = labels
        self.augment = augment

    def __len__(self): return len(self.labels)

    def __getitem__(self, idx):
        slices = self.slices[idx].astype(np.float32)   # (N_REF, 224, 56)
        if self.augment:
            # salt-and-pepper noise on binary map
            flip   = (np.random.random(slices.shape) < 0.005).astype(np.float32)
            slices = np.abs(slices - flip)
            # random horizontal flip (column axis)
            if np.random.random() < 0.5:
                slices = slices[:, :, ::-1].copy()
        return (torch.from_numpy(slices),
                torch.tensor([self.aspects[idx]], dtype=torch.float32),
                self.labels[idx])

# ── 모델: XorSliceSENet ───────────────────────────────────────────────────────
class SELayer(nn.Module):
    """Channel squeeze-and-excitation (along channel dim = ref pages)."""
    def __init__(self, ch, reduction=16):
        super().__init__()
        mid = max(ch // reduction, 4)
        self.fc = nn.Sequential(
            nn.Linear(ch, mid, bias=False), nn.ReLU(inplace=True),
            nn.Linear(mid, ch, bias=False), nn.Sigmoid(),
        )

    def forward(self, x):
        # x: (B, C, H, W)
        scale = self.fc(x.mean(dim=(2, 3)))       # (B, C)
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
    """
    두 브랜치:
      (A) Spatial branch: (B, N_REF, 224, 56) → SE-ResNet → GAP → (B, 512)
      (B) Global stats branch: per-ref match ratio (B, N_REF) → MLP → (B, 128)
    Merge + aspect ratio → (B, 641) → head → 7 classes
    """
    def __init__(self, num_classes=7, n_ref=64):
        super().__init__()
        # --- Spatial branch ---
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
        self.gap    = nn.AdaptiveAvgPool2d(1)       # → (B, 512)

        # --- Global stats branch ---
        # input: per-ref match rate (B, n_ref)
        self.stats_head = nn.Sequential(
            nn.Linear(n_ref, 256), nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Dropout(0.3),
            nn.Linear(256, 128), nn.ReLU(inplace=True),
        )                                            # → (B, 128)

        # --- Classifier head ---
        # 512 (spatial) + 128 (stats) + 1 (aspect) = 641
        self.head = nn.Sequential(
            nn.Linear(512 + 128 + 1, 512), nn.ReLU(inplace=True),
            nn.Dropout(0.4),
            nn.Linear(512, num_classes),
        )

    def forward(self, x, sc):
        # Global stats: mean over spatial dims → per-ref match rate
        stats = x.mean(dim=(2, 3))                 # (B, N_REF)
        stats_feat = self.stats_head(stats)         # (B, 128)

        # Spatial path
        x = self.pool1(self.stem(x))
        x = self.layer1(x)
        x = self.layer2(x)
        x = self.layer3(x)
        x = self.layer4(x)
        sp_feat = self.gap(x).flatten(1)            # (B, 512)

        return self.head(torch.cat([sp_feat, stats_feat, sc], dim=1))


# ── LR 스케줄: linear warmup + cosine ─────────────────────────────────────────
def lr_lambda(epoch, warmup=WARMUP_EP, total=EPOCHS):
    if epoch < warmup:
        return (epoch + 1) / warmup
    progress = (epoch - warmup) / max(total - warmup, 1)
    return 0.5 * (1 + math.cos(math.pi * progress))


# ── 학습 + 평가 ───────────────────────────────────────────────────────────────
def run(epochs=EPOCHS, batch=96):
    model_path = "./mura_xor_slice_64ref_v2.pth"
    pin = torch.cuda.is_available()

    tr_ds = XorSliceCachedDataset(tr_slices_mm, tr_aspects, tr_labels, augment=True)
    va_ds = XorSliceCachedDataset(va_slices_mm, va_aspects, va_labels, augment=False)
    tr_ld = DataLoader(tr_ds, batch_size=batch, shuffle=True,
                       num_workers=8, pin_memory=pin, persistent_workers=True)
    va_ld = DataLoader(va_ds, batch_size=batch, shuffle=False,
                       num_workers=4, pin_memory=pin, persistent_workers=True)

    model   = XorSliceSENet(len(CLASSES), n_ref=N_REF).to(device)
    n_param = sum(p.numel() for p in model.parameters())
    print(f"\n{'='*64}", flush=True)
    print(f"XorSliceSENet  n_ref={N_REF}  params={n_param:,}", flush=True)
    print(f"  train={len(tr_ld.dataset):,} ({len(tr_ld)} batches)  "
          f"valid={len(va_ld.dataset):,} ({len(va_ld)} batches)", flush=True)
    print(f"  warmup={WARMUP_EP} ep  epochs={epochs}  batch={batch}", flush=True)
    print(f"{'='*64}", flush=True)

    counts = np.bincount(tr_labels, minlength=len(CLASSES))
    w = torch.tensor(counts.sum() / (len(CLASSES) * counts), dtype=torch.float32).to(device)
    crit  = nn.CrossEntropyLoss(weight=w, label_smoothing=0.1)
    opt   = optim.AdamW(model.parameters(), lr=3e-4, weight_decay=1e-4)
    sched = optim.lr_scheduler.LambdaLR(opt, lr_lambda=lr_lambda)

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
        va  = 100. * vac / vat
        lr  = opt.param_groups[0]['lr']
        tag = ""
        if va > best:
            best = va
            torch.save(model.state_dict(), model_path)
            tag = " ← saved"
        print(f"[ep {epoch:2d}/{epochs}]  "
              f"tr {trl/trt:.4f}/{100.*trc/trt:.1f}%  "
              f"va {val/vat:.4f}/{va:.1f}%  "
              f"lr={lr:.2e}  {time.time()-t0:.0f}s{tag}", flush=True)

    print(f"\nBest val: {best:.1f}%  → {model_path}", flush=True)
    return model, model_path, va_ld


def evaluate(model, va_ld, model_path):
    model.eval()
    preds, trues = [], []
    with torch.no_grad():
        for imgs, sc, lbl in va_ld:
            preds.extend(model(imgs.to(device), sc.to(device)).argmax(1).cpu().numpy())
            trues.extend(lbl.numpy())
    preds, trues = np.array(preds), np.array(trues)

    print(f"\n===== 64-ref v2 evaluation =====", flush=True)
    print(classification_report(trues, preds, target_names=CLASSES), flush=True)
    print("Per-class accuracy:", flush=True)
    for i, c in enumerate(CLASSES):
        m = trues == i
        print(f"  {c:10s}: {(preds[m]==i).mean()*100:.1f}%  ({m.sum()} samples)", flush=True)

    cm  = confusion_matrix(trues, preds)
    fig, ax = plt.subplots(figsize=(8, 6))
    im = ax.imshow(cm, cmap='Blues'); fig.colorbar(im, ax=ax)
    ax.set(xticks=range(7), yticks=range(7),
           xticklabels=CLASSES, yticklabels=CLASSES,
           ylabel='True', xlabel='Predicted',
           title='XorSliceSENet — 64 ref pages (v2)')
    plt.setp(ax.get_xticklabels(), rotation=45, ha='right')
    thresh = cm.max() / 2
    for i in range(7):
        for j in range(7):
            ax.text(j, i, cm[i, j], ha='center', va='center',
                    color='white' if cm[i, j] > thresh else 'black')
    plt.tight_layout()
    pdf_path = "./mura_xor64_v2_confusion_matrix.pdf"
    plt.savefig(pdf_path, format='pdf', bbox_inches='tight')
    plt.close()
    print(f"Saved → {pdf_path}", flush=True)

    # macro top-1
    per_class = [(preds[trues==i]==i).mean() for i in range(len(CLASSES))]
    macro = np.mean(per_class)
    print(f"\nMacro top-1 accuracy: {macro*100:.2f}%", flush=True)
    return preds, trues


# ── main ──────────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    t_start = time.time()
    model, model_path, va_ld = run(epochs=EPOCHS, batch=96)

    # best checkpoint로 평가
    model.load_state_dict(torch.load(model_path, map_location=device, weights_only=True))
    evaluate(model, va_ld, model_path)

    print(f"\nTotal time: {(time.time()-t_start)/3600:.1f}h", flush=True)
