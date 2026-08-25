"""
Generate 196-bit memory sparsity vectors from QEMU xp /512gx page dumps.
Handles v5_ssim_re/ filenames: 'N.out' (uses SAMPLE_INDICES) and 'N-M.out' (M is sample_idx).
Automated Alignment: Finds the best offset by matching patterns with JSON v5 ground truth.
"""

import re
import sys
import json
from pathlib import Path

# --- Configuration ---
SSIM_DIR = Path(__file__).parent / "v5_ssim_re"

JSON_PATH = Path(__file__).parent / "UNet_training_v5.json"
CHUNK_SIZE = 16
NUM_CHUNKS = 196
IMAGE_SIZE = NUM_CHUNKS * CHUNK_SIZE  # 3136 bytes
DUMP_BYTES = 4096

# Fallback: label -> sample_idx for files named 'N.out'
SAMPLE_INDICES = {
    "7": 38,
    "0": 37,
    "6": 36,
    "5": 35,
    "9": 33,
    "8": 31,
    "3": 30,
    "1": 40,
    "2": 25,
    "4": 26
}

HEX_LINE = re.compile(
    r'^[0-9a-f]+:\s+0x([0-9a-f]{16})\s+0x([0-9a-f]{16})',
    re.IGNORECASE,
)

def parse_dump(raw: str) -> bytearray:
    """Parse QEMU hex output into a little-endian bytearray."""
    buf = bytearray()
    for line in raw.splitlines():
        m = HEX_LINE.match(line.strip())
        if m:
            for grp in (m.group(1), m.group(2)):
                buf += int(grp, 16).to_bytes(8, "little")
    return buf

def split_dumps(text: str) -> list[str]:
    """Split the .out file into individual QEMU dump blocks."""
    blocks = re.split(r"^\s*\(qemu\).*$", text, flags=re.MULTILINE)
    return [b for b in blocks if b.strip()]

def get_sparsity_at_offset(dump1, dump2, offset):
    """Generate a 196-bit vector starting from a specific byte offset."""
    vec = []
    for k in range(NUM_CHUNKS):
        s = offset + k * CHUNK_SIZE
        e = s + CHUNK_SIZE
        changed = any(dump1[i] ^ dump2[i] for i in range(s, e))
        vec.append(1 if changed else 0)
    return vec

def find_truth_vector(sample_idx):
    """Load the reference sparsity vector from the training JSON v5."""
    if not JSON_PATH.exists():
        raise FileNotFoundError(f"Missing {JSON_PATH}. Run training data generation v5 first.")

    with open(JSON_PATH, "r") as f:
        data = json.load(f)

    for item in data:
        if item["sample_idx"] == sample_idx:
            return item["input_sparsity_seq"]
    return None

def resolve_sample_idx(stem: str) -> tuple[str, int] | None:
    """
    Parse filename stem to (label, sample_idx).
    Accepts:
      - 'N'    -> label=N, idx from SAMPLE_INDICES
      - 'N-M'  -> label=N, idx=M (explicit)
    Returns None if unrecognized.
    """
    # Try 'N-M' format first
    m = re.fullmatch(r'(\d+)-(\d+)', stem)
    if m:
        label, idx = m.group(1), int(m.group(2))
        return label, idx

    # Try plain label
    if stem in SAMPLE_INDICES:
        return stem, SAMPLE_INDICES[stem]

    return None

def process_file_with_alignment(path: Path, sample_idx: int) -> list[int]:
    """Search for the best offset in the dump by matching the JSON v5 truth vector."""
    text = path.read_text(errors="replace")
    blocks = split_dumps(text)

    if len(blocks) < 2:
        raise ValueError(f"Insufficient dumps in {path.name}")

    dump1 = parse_dump(blocks[-2])
    dump2 = parse_dump(blocks[-1])

    truth_vec = find_truth_vector(sample_idx)
    if truth_vec is None:
        raise ValueError(f"Index {sample_idx} not found in training JSON")

    best_offset = 0
    max_matches = -1
    final_vec = []

    search_limit = DUMP_BYTES - IMAGE_SIZE  # 4096 - 3136 = 960

    print(f"  Searching alignment for {path.name} (sample_idx={sample_idx})...")

    for offset in range(search_limit):
        current_vec = get_sparsity_at_offset(dump1, dump2, offset)
        matches = sum(1 for i, j in zip(current_vec, truth_vec) if i == j)
        if matches > max_matches:
            max_matches = matches
            best_offset = offset
            final_vec = current_vec

    match_rate = (max_matches / NUM_CHUNKS) * 100
    print(f"    Best offset: {best_offset}  Match rate: {match_rate:.1f}%")

    if match_rate < 80:
        print(f"    [!] WARNING: Low match rate. Alignment might be poor.")

    return final_vec

def main() -> None:
    if not SSIM_DIR.exists():
        print(f"Directory not found: {SSIM_DIR}", file=sys.stderr)
        sys.exit(1)

    out_files = sorted(SSIM_DIR.glob("*.out"))

    print(f"Processing files in {SSIM_DIR} (v5_ssim_re mode)...\n")

    for path in out_files:
        result = resolve_sample_idx(path.stem)
        if result is None:
            print(f"  Skipping {path.name}: cannot resolve sample_idx from name")
            continue

        label, sample_idx = result

        try:
            vec = process_file_with_alignment(path, sample_idx)
            dest = path.with_name(f"{path.name}_v5.list")
            dest.write_text(str(vec))
            print(f"    Saved -> {dest.name}\n")
        except Exception as exc:
            print(f"  ERROR processing {path.name}: {exc}", file=sys.stderr)

    print("Done.")

if __name__ == "__main__":
    main()
