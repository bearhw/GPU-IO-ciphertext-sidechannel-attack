#!/usr/bin/env python3
"""
main_holder.py — Run main.py unmodified, with blocking added for host swap.

How it works:
  1. enumerate patch: only yield --hold-batch N from DataLoader (skip earlier batches).
  2. Normalize patch: no-op → keep background pixels at 0.0 (main_gpa_3.py training format).
  3. print patch: convert "[Train] batch N GPA: 0x..." to orchestrate.py parse format.
     - Output "Image GPA (Aligned): 0x{page_gpa} offset={offset}".
     - stdin.readline() blocks — released when host closes stdin after swap is done.
     - Host assumes page2 = image_gpa + PAGE_SIZE, so no separate page2 GPA report needed.

Usage:
  python3 -u main_holder.py --no-accel --batch-size 1 --epochs 1 --hold-batch N
"""

import os, sys, re, runpy, builtins, argparse

PAGE_SIZE = os.sysconf('SC_PAGE_SIZE')

# --hold-batch is a wrapper arg; the rest are passed through to main.py
_p = argparse.ArgumentParser(add_help=False)
_p.add_argument('--hold-batch', type=int, default=0)
_wrapper_args, _main_argv = _p.parse_known_args()
_HOLD_BATCH = _wrapper_args.hold_batch


def _load_label(idx: int) -> int:
    path = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                        '../data/MNIST/raw/train-labels-idx1-ubyte')
    try:
        with open(path, 'rb') as f:
            f.seek(8 + idx)
            return f.read(1)[0]
    except Exception:
        return -1


# ── enumerate patch ─────────────────────────────────────────────────────────
_orig_enumerate = builtins.enumerate


class _FilteredEnumerate:
    def __init__(self, iterable, start=0):
        self._it        = iterable
        self._start     = start
        self._is_loader = hasattr(iterable, 'dataset')

    def __iter__(self):
        if not self._is_loader:
            yield from _orig_enumerate(self._it, self._start)
            return
        for i, item in _orig_enumerate(self._it, self._start):
            if i != _HOLD_BATCH:
                continue   # earlier batches: load only, skip forward/backward
            yield i, item
            return


builtins.enumerate = _FilteredEnumerate


# ── print patch ─────────────────────────────────────────────────────────────
_orig_print = builtins.print


def _patched_print(*args, **kwargs):
    text = ' '.join(str(a) for a in args)
    m = re.search(r'\[Train\]\s+batch (\d+) GPA: 0x([0-9a-f]+)', text, re.IGNORECASE)
    if m and int(m.group(1)) == _HOLD_BATCH:
        gpa_raw   = int(m.group(2), 16)
        page_gpa  = gpa_raw & ~(PAGE_SIZE - 1)
        offset    = gpa_raw & (PAGE_SIZE - 1)
        label     = _load_label(_HOLD_BATCH)
        _orig_print(f"Target Label: {label}", flush=True)
        # offset is for debug; host can infer via density scan
        _orig_print(f"Image GPA (Aligned): 0x{page_gpa:016x} offset={offset}", flush=True)
        sys.stdin.readline()   # blocks until host closes stdin after swap
    else:
        _orig_print(*args, **kwargs)


builtins.print = _patched_print


# ── Normalize → no-op ───────────────────────────────────────────────────────
# main.py: Normalize(0.1307, 0.3081) → background 0.0 → -0.4242 → sparsity signal destroyed
from torchvision import transforms as _tv_transforms
_tv_transforms.Normalize.__call__ = lambda self, tensor: tensor


# ── Run main.py ──────────────────────────────────────────────────────────────
import runpy

sys.argv = ['main.py'] + _main_argv
runpy.run_path(
    os.path.join(os.path.dirname(os.path.abspath(__file__)), 'main.py'),
    run_name='__main__',
)
