#!/usr/bin/env python3
"""
main_holder_norm.py — main_holder.py, minus the Normalize->no-op patch.

Same enumerate/print/hold machinery as main_holder.py, but Normalize(0.1307,
0.3081) stays ACTIVE — this is what main.py does natively (transform =
Compose([ToTensor(), Normalize(...)]) runs inside Dataset.__getitem__, fully
before collation, so the batch tensor `data` used in the train loop IS the
post-Normalize tensor; there is no separate pre-Normalize buffer to chase).
Background pixel -> normalize_u8(0) == -0.4242129..., NOT 0.0.

Use this (not main_holder.py) with a dictionary built for normalized values
(mnist_dict_build.py's normalize_u8) -- main_holder.py's Normalize-disabled
convention only matches a dictionary built for raw [0,1] ToTensor values
(main_gpa_3.py's convention) and will never match a normalized-value
dictionary.

Usage:
  python3 -u main_holder_norm.py --no-accel --batch-size 512 --epochs 1 --hold-batch N
"""

import os, sys, re, runpy, builtins, argparse

PAGE_SIZE = os.sysconf('SC_PAGE_SIZE')

# --hold-batch is a wrapper arg; the rest are passed through to main.py
_p = argparse.ArgumentParser(add_help=False)
_p.add_argument('--hold-batch', type=int, default=0)
_wrapper_args, _main_argv = _p.parse_known_args()
_HOLD_BATCH = _wrapper_args.hold_batch

# ── ready gate ───────────────────────────────────────────────────────────────
# Let the host complete the (comparatively expensive) SSH handshake and spawn
# this process BEFORE arming anything timing-sensitive (e.g. write_pattern_tracker,
# which write-protects guest RAM and can starve a single-vCPU guest badly enough
# that a NEW incoming SSH connection's banner exchange times out). The host
# arms its tracker only after seeing HOLDER_READY, then releases this gate --
# no new connection needed for that, just a byte on the already-open stdin pipe.
sys.stdout.write("HOLDER_READY\n")
sys.stdout.flush()
sys.stdin.readline()


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


# ── Run main.py (Normalize left ACTIVE — no monkeypatch here) ──────────────
sys.argv = ['main.py'] + _main_argv
runpy.run_path(
    os.path.join(os.path.dirname(os.path.abspath(__file__)), 'main.py'),
    run_name='__main__',
)
