#!/usr/bin/env python3
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import infer, SWAP_TOOL

infer(0x1a10f9000, str(SWAP_TOOL), Path("xor_slice_ground_truth.npy"))
