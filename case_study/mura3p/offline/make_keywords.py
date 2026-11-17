#!/usr/bin/env python3
"""
make_keywords.py — mura3p dictionary: MURA's 64 density-ranked u8 levels
(case_study/mura/xor_density_survey.npy, same REF_U8_64 order as MURA's
classifiers) for each of R, G, B. A ref is 4 identical normalized pixels.

  python3 make_keywords.py   -> dict_keywords.json (192 refs)
"""
import json
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
MURA = HERE.parent.parent / "mura"
MEAN = {"R": 0.485, "G": 0.456, "B": 0.406}
STD = {"R": 0.229, "G": 0.224, "B": 0.225}


def chunk(u8, ch):
    v = (np.float32(u8) / np.float32(255) - np.float32(MEAN[ch])) / np.float32(STD[ch])
    return np.array([v] * 4, np.float32).tobytes()


def main():
    levels = np.argsort(-np.load(MURA / "xor_density_survey.npy"))[:64].tolist()
    out = {"source": "mura/xor_density_survey.npy top-64 (REF_U8_64)", "levels": levels, "channels": {}}
    for ch in "RGB":
        out["channels"][ch] = [{"rank": k, "pixels": [u8] * 4, "chunk_hex": chunk(u8, ch).hex()}
                               for k, u8 in enumerate(levels)]
    (HERE / "dict_keywords.json").write_text(json.dumps(out, indent=1))
    print(f"{3 * len(levels)} refs, levels {levels[:8]}...")


if __name__ == "__main__":
    main()
