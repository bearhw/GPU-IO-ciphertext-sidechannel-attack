#!/usr/bin/env python3
"""
train_victim.py — 3DShapes shape classifier (the victim workload). Runs in the guest.

Same preprocessing the attack assumes and the loader uses:
  Resize((224,224)) -> ToTensor -> Normalize(ImageNet)
Model: torchvision ResNet-18 (ImageNet weights if cached, else random init), fc -> 4.
Trained on shapes3d_victim_train.npz, evaluated on shapes3d_test.npz (held-out hue
combinations). The test accuracy is the plaintext upper bound for the attack.

  python3 train_victim.py --data ~/shapes3d/datasets --out ~/shapes3d/victim_resnet18.pth
"""
import argparse
import time
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
from PIL import Image
from torch.utils.data import DataLoader, Dataset
from torchvision import models, transforms

TF = transforms.Compose([
    transforms.Resize((224, 224)),
    transforms.ToTensor(),
    transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225]),
])


class NpzSet(Dataset):
    def __init__(self, path):
        z = np.load(path)
        self.x, self.y = z["images"], z["shape"]

    def __len__(self):
        return len(self.y)

    def __getitem__(self, i):
        return TF(Image.fromarray(self.x[i])), int(self.y[i])


def evaluate(model, loader, dev):
    model.eval()
    ok = n = 0
    per = np.zeros((4, 2), int)
    with torch.no_grad():
        for x, y in loader:
            p = model(x.to(dev)).argmax(1).cpu()
            ok += (p == y).sum().item()
            n += len(y)
            for t, q in zip(y.tolist(), p.tolist()):
                per[t, 0] += t == q
                per[t, 1] += 1
    return 100 * ok / n, 100 * per[:, 0] / per[:, 1]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--data", default=str(Path.home() / "shapes3d" / "datasets"))
    ap.add_argument("--out", default=str(Path.home() / "shapes3d" / "victim_resnet18.pth"))
    ap.add_argument("--epochs", type=int, default=3)
    a = ap.parse_args()
    dev = "cuda" if torch.cuda.is_available() else "cpu"
    d = Path(a.data)
    tr = DataLoader(NpzSet(d / "shapes3d_victim_train.npz"), batch_size=64, shuffle=True, num_workers=0)
    te = DataLoader(NpzSet(d / "shapes3d_test.npz"), batch_size=100, num_workers=0)
    try:
        model = models.resnet18(weights=models.ResNet18_Weights.IMAGENET1K_V1)
    except Exception as e:
        print(f"[victim] no pretrained weights ({e!r}); random init")
        model = models.resnet18(weights=None)
    model.fc = nn.Linear(model.fc.in_features, 4)
    model.to(dev)
    opt = torch.optim.AdamW(model.parameters(), lr=1e-3)
    for ep in range(a.epochs):
        model.train()
        t0 = time.time()
        for x, y in tr:
            opt.zero_grad()
            nn.functional.cross_entropy(model(x.to(dev)), y.to(dev)).backward()
            opt.step()
        acc, per = evaluate(model, te, dev)
        print(f"[victim] ep {ep + 1}  test acc {acc:.2f}%  per-shape {np.round(per, 1).tolist()}  "
              f"({time.time() - t0:.0f}s, {dev})", flush=True)
    torch.save(model.state_dict(), a.out)
    print(f"[victim] saved {a.out}")


if __name__ == "__main__":
    main()
