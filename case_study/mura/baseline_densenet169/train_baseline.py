"""
Raw image baseline — DenseNet-169 fine-tuning for MURA 7-class body part classification

DenseNet-MURA-PyTorch 를 참고:
  - 입력: grayscale PNG → 3채널 repeat → 224×224 → ImageNet normalize
  - 모델: torchvision densenet169 (ImageNet pretrained), fc → Linear(1664, 7)
  - Loss: class-weighted CrossEntropyLoss + label smoothing 0.1
  - 목적: XOR side-channel 모델(ref-16/32/64)의 baseline 비교

출력:
  ./mura_baseline_densenet169.pth
  ./mura_baseline_confusion_matrix.pdf

실행:
  conda activate mura
  cd /home/eun/bnb/mura
  python train_baseline.py 2>&1 | tee train_baseline.log
"""
import os, sys, glob, time
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
from torchvision import models, transforms
from PIL import Image
from sklearn.metrics import confusion_matrix, classification_report
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

# ── 상수 ──────────────────────────────────────────────────────────────────────
DATA_ROOT   = "./mura_downloads"
CLASSES     = ["ELBOW","FINGER","FOREARM","HAND","HUMERUS","SHOULDER","WRIST"]
CLASS2IDX   = {c: i for i, c in enumerate(CLASSES)}
IMG_SIZE    = 224
EPOCHS      = 30
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
for cls in CLASSES:
    n_tr = sum(1 for l in tr_labels if l == CLASS2IDX[cls])
    n_va = sum(1 for l in va_labels if l == CLASS2IDX[cls])
    print(f"  {cls:10s}: train {n_tr:>5,}  valid {n_va:>4,}", flush=True)

# ── 전처리 (DenseNet-MURA-PyTorch 방식) ───────────────────────────────────────
# MURA 이미지는 grayscale PNG지만 pil_loader 가 RGB 로 로드 → R==G==B.
# 여기서는 명시적으로 L → RGB 변환 후 ImageNet normalize.
IMAGENET_MEAN = [0.485, 0.456, 0.406]
IMAGENET_STD  = [0.229, 0.224, 0.225]

tr_transform = transforms.Compose([
    transforms.Resize((IMG_SIZE, IMG_SIZE)),
    transforms.RandomHorizontalFlip(),
    transforms.RandomRotation(10),
    transforms.ToTensor(),                              # uint8 → float32 [0,1]
    transforms.Normalize(IMAGENET_MEAN, IMAGENET_STD),
])

va_transform = transforms.Compose([
    transforms.Resize((IMG_SIZE, IMG_SIZE)),
    transforms.ToTensor(),
    transforms.Normalize(IMAGENET_MEAN, IMAGENET_STD),
])

# ── Dataset ───────────────────────────────────────────────────────────────────
class MURABodyPartDataset(Dataset):
    def __init__(self, paths, labels, transform):
        self.paths     = paths
        self.labels    = labels
        self.transform = transform

    def __len__(self): return len(self.paths)

    def __getitem__(self, idx):
        # L → RGB: MURA는 grayscale이므로 3채널 repeat (DenseNet-MURA-PyTorch의 pil_loader 동작과 동일)
        img = Image.open(self.paths[idx]).convert("RGB")
        return self.transform(img), self.labels[idx]

tr_ds = MURABodyPartDataset(tr_paths, tr_labels, tr_transform)
va_ds = MURABodyPartDataset(va_paths, va_labels, va_transform)

pin = torch.cuda.is_available()
tr_ld = DataLoader(tr_ds, batch_size=32, shuffle=True,
                   num_workers=8, pin_memory=pin, persistent_workers=True)
va_ld = DataLoader(va_ds, batch_size=64, shuffle=False,
                   num_workers=4, pin_memory=pin, persistent_workers=True)
print(f"Train batches: {len(tr_ld)}  Valid batches: {len(va_ld)}", flush=True)

# ── 모델: DenseNet-169 pretrained → 7-class head ──────────────────────────────
model = models.densenet169(weights=models.DenseNet169_Weights.IMAGENET1K_V1)
# DenseNet-169의 classifier: Linear(1664, 1000) → Linear(1664, 7)
in_features = model.classifier.in_features   # 1664
model.classifier = nn.Linear(in_features, len(CLASSES))
model = model.to(device)

n_param = sum(p.numel() for p in model.parameters())
n_train = sum(p.numel() for p in model.parameters() if p.requires_grad)
print(f"\nDenseNet-169  total params={n_param:,}  trainable={n_train:,}", flush=True)
print(f"  classifier: Linear({in_features}, {len(CLASSES)})", flush=True)

# ── Loss / Optimizer / Scheduler ──────────────────────────────────────────────
counts = np.bincount(tr_labels, minlength=len(CLASSES))
w = torch.tensor(counts.sum() / (len(CLASSES) * counts), dtype=torch.float32).to(device)
print(f"\nClass weights: { {c: f'{w[i].item():.3f}' for i, c in enumerate(CLASSES)} }", flush=True)

crit  = nn.CrossEntropyLoss(weight=w, label_smoothing=0.1)
opt   = optim.AdamW(model.parameters(), lr=1e-4, weight_decay=1e-4)
sched = optim.lr_scheduler.CosineAnnealingLR(opt, T_max=EPOCHS)

# ── 학습 ──────────────────────────────────────────────────────────────────────
model_path = "./mura_baseline_densenet169.pth"
best_va = 0.0
print(f"\n{'='*64}", flush=True)

for epoch in range(1, EPOCHS + 1):
    t0 = time.time()
    model.train()
    trl, trc, trt = 0., 0, 0
    for imgs, lbl in tr_ld:
        imgs, lbl = imgs.to(device), lbl.to(device)
        opt.zero_grad()
        out  = model(imgs)
        loss = crit(out, lbl)
        loss.backward(); opt.step()
        trl += loss.item() * imgs.size(0)
        trc += out.argmax(1).eq(lbl).sum().item()
        trt += imgs.size(0)
    sched.step()

    model.eval()
    val, vac, vat = 0., 0, 0
    with torch.no_grad():
        for imgs, lbl in va_ld:
            imgs, lbl = imgs.to(device), lbl.to(device)
            out = model(imgs)
            val += crit(out, lbl).item() * imgs.size(0)
            vac += out.argmax(1).eq(lbl).sum().item()
            vat += imgs.size(0)
    va  = 100. * vac / vat
    lr  = opt.param_groups[0]['lr']
    tag = ""
    if va > best_va:
        best_va = va
        torch.save(model.state_dict(), model_path)
        tag = " ← saved"
    print(f"[ep {epoch:2d}/{EPOCHS}]  "
          f"tr {trl/trt:.4f}/{100.*trc/trt:.1f}%  "
          f"va {val/vat:.4f}/{va:.1f}%  "
          f"lr={lr:.2e}  {time.time()-t0:.0f}s{tag}", flush=True)

print(f"\nBest val (micro): {best_va:.1f}%  → {model_path}", flush=True)

# ── 최종 평가 (best checkpoint) ───────────────────────────────────────────────
model.load_state_dict(torch.load(model_path, map_location=device, weights_only=True))
model.eval()

preds, trues = [], []
with torch.no_grad():
    for imgs, lbl in va_ld:
        preds.extend(model(imgs.to(device)).argmax(1).cpu().numpy())
        trues.extend(lbl.numpy())
preds, trues = np.array(preds), np.array(trues)

print(f"\n===== Baseline (DenseNet-169) evaluation =====", flush=True)
print(classification_report(trues, preds, target_names=CLASSES), flush=True)

per_class = []
print("Per-class accuracy:", flush=True)
for i, c in enumerate(CLASSES):
    m = trues == i
    acc = (preds[m] == i).mean() * 100
    per_class.append(acc)
    print(f"  {c:10s}: {acc:.1f}%  ({m.sum()} samples)", flush=True)

macro = np.mean(per_class)
print(f"\nMacro top-1 accuracy: {macro:.2f}%", flush=True)

# confusion matrix
cm = confusion_matrix(trues, preds)
fig, ax = plt.subplots(figsize=(8, 6))
im = ax.imshow(cm, cmap='Blues'); fig.colorbar(im, ax=ax)
ax.set(xticks=range(7), yticks=range(7),
       xticklabels=CLASSES, yticklabels=CLASSES,
       ylabel='True', xlabel='Predicted',
       title='Baseline: DenseNet-169 (raw image, 7-class body part)')
plt.setp(ax.get_xticklabels(), rotation=45, ha='right')
thresh = cm.max() / 2
for i in range(7):
    for j in range(7):
        ax.text(j, i, cm[i, j], ha='center', va='center',
                color='white' if cm[i, j] > thresh else 'black')
plt.tight_layout()
pdf_path = "./mura_baseline_confusion_matrix.pdf"
plt.savefig(pdf_path, format='pdf', bbox_inches='tight')
plt.close()
print(f"Saved → {pdf_path}", flush=True)

# ── Grad-CAM heatmap ──────────────────────────────────────────────────────────
# DenseNet-169 forward: features(x) → ReLU → GAP → classifier
# model.features 출력 (B, 1664, 7, 7) 에 hook

class GradCAM:
    def __init__(self, model):
        self.model    = model
        self._feat    = None
        self._grad    = None
        self._fwd_h   = model.features.register_forward_hook(
            lambda m, i, o: setattr(self, '_feat', o.detach()))
        self._bwd_h   = model.features.register_full_backward_hook(
            lambda m, gi, go: setattr(self, '_grad', go[0].detach()))

    def __call__(self, img_t, class_idx=None):
        self.model.zero_grad()
        logits = self.model(img_t.unsqueeze(0))
        cls    = logits.argmax(1).item() if class_idx is None else class_idx
        logits[0, cls].backward()
        # weights: global average of gradients over spatial dims
        w    = self._grad.mean(dim=(2, 3), keepdim=True)   # (1, 1664, 1, 1)
        cam  = (w * self._feat).sum(dim=1, keepdim=True)   # (1, 1, 7, 7)
        cam  = torch.clamp(cam, min=0)
        cam  = cam.squeeze().cpu().numpy()
        cam -= cam.min()
        if cam.max() > 0:
            cam /= cam.max()
        return cam, cls

    def remove(self):
        self._fwd_h.remove(); self._bwd_h.remove()

# 클래스당 4개 샘플 (정답 예측된 것 우선)
N_SAMP  = 4
UNNORM  = transforms.Compose([
    transforms.Normalize(mean=[0., 0., 0.], std=[1/s for s in IMAGENET_STD]),
    transforms.Normalize(mean=[-m for m in IMAGENET_MEAN], std=[1., 1., 1.]),
])

# val set에서 클래스별로 정답 샘플 수집
va_ds_plain = MURABodyPartDataset(va_paths, va_labels, va_transform)
class_samples = {i: [] for i in range(len(CLASSES))}
for idx in range(len(va_ds_plain)):
    img_t, lbl = va_ds_plain[idx]
    if len(class_samples[lbl]) < N_SAMP:
        class_samples[lbl].append((img_t, lbl, va_paths[idx]))
    if all(len(v) >= N_SAMP for v in class_samples.values()):
        break

model.eval()
gcam = GradCAM(model)

import cv2  # for resize; fallback to PIL if not available
try:
    import cv2 as _cv2_test
    def resize_cam(cam, size):
        return _cv2_test.resize(cam, (size, size), interpolation=_cv2_test.INTER_LINEAR)
except ImportError:
    from PIL import Image as _PIL_Image
    def resize_cam(cam, size):
        return np.array(_PIL_Image.fromarray((cam * 255).astype(np.uint8)).resize(
            (size, size), _PIL_Image.BILINEAR)) / 255.0

fig, axes = plt.subplots(len(CLASSES), N_SAMP * 2,
                          figsize=(N_SAMP * 2 * 1.8, len(CLASSES) * 2.2))
fig.subplots_adjust(wspace=0.03, hspace=0.18)

for row, cls_idx in enumerate(range(len(CLASSES))):
    samples = class_samples[cls_idx]
    for col_pair, (img_t, lbl, path) in enumerate(samples):
        # original (unnormalized, grayscale)
        orig = UNNORM(img_t).permute(1, 2, 0).numpy()
        orig = np.clip(orig.mean(axis=2), 0, 1)

        # Grad-CAM
        with torch.enable_grad():
            cam, pred_cls = gcam(img_t.to(device))
        cam_up = resize_cam(cam, IMG_SIZE)

        ax_orig = axes[row][col_pair * 2]
        ax_heat = axes[row][col_pair * 2 + 1]

        ax_orig.imshow(orig, cmap='gray', vmin=0, vmax=1)
        ax_orig.axis('off')

        ax_heat.imshow(orig, cmap='gray', vmin=0, vmax=1)
        ax_heat.imshow(cam_up, cmap='jet', alpha=0.45, vmin=0, vmax=1)
        ax_heat.axis('off')

        correct = (pred_cls == lbl)
        if col_pair == 0:
            ax_orig.set_ylabel(CLASSES[cls_idx], fontsize=8,
                               rotation=0, labelpad=46, va='center')
        color = 'green' if correct else 'red'
        ax_heat.set_title(f"→{CLASSES[pred_cls]}", fontsize=6,
                          color=color, pad=2)

# 컬럼 헤더
for col_pair in range(N_SAMP):
    axes[0][col_pair * 2].set_title("orig", fontsize=7, pad=2)
    axes[0][col_pair * 2 + 1].set_title("Grad-CAM", fontsize=7, pad=2)

plt.suptitle(
    f"Grad-CAM — DenseNet-169 baseline  (macro top-1 {macro:.1f}%)\n"
    "title color: green=correct  red=wrong",
    fontsize=10)
plt.tight_layout()
plt.savefig("./mura_baseline_gradcam.pdf", format='pdf', bbox_inches='tight')
plt.savefig("./mura_baseline_gradcam.png", dpi=150, bbox_inches='tight')
plt.close()
gcam.remove()
print("Saved → mura_baseline_gradcam.pdf / .png", flush=True)
