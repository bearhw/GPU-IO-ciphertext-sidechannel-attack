#!/usr/bin/env python3
"""
mura_model.py — MURA's 64-ref attack classifier (XorSliceSENet), copied verbatim
from case_study/mura/pipeline/stage5_reconstruct.py so mura3p loads MURA's
checkpoints without importing that pipeline (its `common` module would clash).
Input: (B,64,224,56) level-hit map, aspect scalar fed as 1.0 (as in MURA).
"""
import torch
import torch.nn as nn
import torch.nn.functional as F


class SELayer(nn.Module):
    def __init__(self, ch, reduction=16):
        super().__init__()
        mid = max(ch // reduction, 4)
        self.fc = nn.Sequential(
            nn.Linear(ch, mid, bias=False), nn.ReLU(inplace=True),
            nn.Linear(mid, ch, bias=False), nn.Sigmoid())

    def forward(self, x):
        return x * self.fc(x.mean(dim=(2, 3)))[:, :, None, None]


class SEResBlock(nn.Module):
    def __init__(self, in_ch, out_ch, stride=1, se_reduction=16):
        super().__init__()
        self.c1 = nn.Conv2d(in_ch, out_ch, 3, stride=stride, padding=1, bias=False)
        self.b1 = nn.BatchNorm2d(out_ch)
        self.c2 = nn.Conv2d(out_ch, out_ch, 3, padding=1, bias=False)
        self.b2 = nn.BatchNorm2d(out_ch)
        self.se = SELayer(out_ch, se_reduction)
        self.down = nn.Sequential(
            nn.Conv2d(in_ch, out_ch, 1, stride=stride, bias=False),
            nn.BatchNorm2d(out_ch),
        ) if (stride != 1 or in_ch != out_ch) else nn.Identity()

    def forward(self, x):
        h = F.relu(self.b1(self.c1(x)), inplace=True)
        h = self.se(self.b2(self.c2(h)))
        return F.relu(h + self.down(x), inplace=True)


class XorSliceSENet(nn.Module):
    def __init__(self, num_classes=7, n_ref=64):
        super().__init__()
        self.stem = nn.Sequential(
            nn.Conv2d(n_ref, 64, kernel_size=(7, 3), stride=(2, 1),
                      padding=(3, 1), bias=False),
            nn.BatchNorm2d(64), nn.ReLU(inplace=True), SELayer(64))
        self.pool1  = nn.MaxPool2d(kernel_size=(2, 1), stride=(2, 1))
        self.layer1 = SEResBlock(64,  128, stride=1)
        self.layer2 = SEResBlock(128, 256, stride=2)
        self.layer3 = SEResBlock(256, 512, stride=2)
        self.layer4 = SEResBlock(512, 512, stride=2)
        self.gap    = nn.AdaptiveAvgPool2d(1)
        self.stats_head = nn.Sequential(
            nn.Linear(n_ref, 256), nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Dropout(0.3),
            nn.Linear(256, 128), nn.ReLU(inplace=True))
        self.head = nn.Sequential(
            nn.Linear(512 + 128 + 1, 512), nn.ReLU(inplace=True),
            nn.Dropout(0.4),
            nn.Linear(512, num_classes))

    def forward(self, x, sc):
        stats = x.mean(dim=(2, 3))
        stats_feat = self.stats_head(stats)
        x = self.pool1(self.stem(x))
        x = self.layer1(x); x = self.layer2(x); x = self.layer3(x); x = self.layer4(x)
        sp_feat = self.gap(x).flatten(1)
        return self.head(torch.cat([sp_feat, stats_feat, sc], dim=1))
