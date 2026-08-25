#!/usr/bin/env python3
"""
check_token_ids.py — Verify TOKEN_LABELS IDs against actual Qwen2-VL tokenization.

Run on the GUEST inside the vlm conda env:
  cd ~/medical_ml/med_vlm/scripts
  python3 /path/to/check_token_ids.py

What it does:
  1. Loads the Qwen2-VL tokenizer
  2. Builds a real prompt sample and finds where each indication phrase lands
     in the tokenized input_ids — verifies token IDs in actual BPE context
  3. Scans the full dataset for ALL unique indication strings that contain
     any of the target substrings, prints their real token ID sequences
  4. Outputs a ready-to-paste TOKEN_LABELS definition for orchestrate_v2.py
"""

import json
import os
import struct
import sys
from collections import defaultdict

MODEL_ID     = "Qwen/Qwen2-VL-2B-Instruct"
DATASET_PATH = os.path.expanduser(
    "~/medical_ml/med_vlm/rexgradient/ReXGradient/metadata/rexgradient_test.json"
)
IMAGE_FOLDER = os.path.expanduser(
    "~/medical_ml/med_vlm/rexgradient/ReXGradient"
)

# Substrings to search for (case-insensitive)
TARGET_SUBSTRINGS = [
    "chest pain",
    "shortness of breath",
]

# Current TOKEN_LABELS to compare against
CURRENT_TOKEN_LABELS = [
    ("Chest pain",          [41771, 6646]),
    ("Shortness of breath", [10698, 2090, 315, 11486]),
    ("chest pain",          [15138, 6646]),
    ("shortness of breath", [2805, 2090, 315, 11486]),
]


def load_dataset(path):
    with open(path) as f:
        raw = f.read().strip()
    return json.loads(raw) if raw.startswith("[") else [
        json.loads(line) for line in raw.splitlines() if line.strip()
    ]


def ids_to_bytes(ids):
    return struct.pack(f"<{len(ids)}q", *ids)


def find_subseq(haystack, needle):
    n = len(needle)
    for i in range(len(haystack) - n + 1):
        if haystack[i:i+n] == needle:
            return i
    return -1


def tokenize_in_context(processor, indication_text, sample_text):
    """
    Tokenize `sample_text` (full prompt without image expansion) and locate
    `indication_text` within the resulting token IDs.

    Returns (token_ids_at_indication, start_idx, end_idx) or (None, -1, -1).
    """
    enc = processor.tokenizer(sample_text, add_special_tokens=False,
                              return_offsets_mapping=True)
    ids      = enc["input_ids"]
    offsets  = enc["offset_mapping"]

    char_start = sample_text.find(indication_text)
    if char_start == -1:
        return None, -1, -1
    char_end = char_start + len(indication_text)

    tok_start, tok_end = None, None
    for i, (s, e) in enumerate(offsets):
        if s == e:
            continue
        if tok_start is None and e > char_start:
            tok_start = i
        if s < char_end:
            tok_end = i + 1

    if tok_start is None:
        return None, -1, -1

    return ids[tok_start:tok_end], tok_start, tok_end


def verify_current_labels(processor):
    print("=" * 70)
    print("1. Verifying current TOKEN_LABELS IDs (isolated tokenization)")
    print("=" * 70)

    tokenizer = processor.tokenizer
    for label, expected_ids in CURRENT_TOKEN_LABELS:
        # Tokenize with a space prefix (as the word appears mid-sentence)
        ids_with_space  = tokenizer.encode(" " + label, add_special_tokens=False)
        ids_plain       = tokenizer.encode(label,       add_special_tokens=False)
        match_space = (ids_with_space == expected_ids)
        match_plain = (ids_plain      == expected_ids)
        status = "OK ✓" if (match_space or match_plain) else "MISMATCH ✗"
        print(f"\n  Label:    {label!r}")
        print(f"  Expected: {expected_ids}")
        print(f"  ' '+str:  {ids_with_space}  {'<-- matches' if match_space else ''}")
        print(f"  plain:    {ids_plain}  {'<-- matches' if match_plain else ''}")
        print(f"  Status:   {status}")


def scan_dataset_indications(processor, dataset):
    print("\n" + "=" * 70)
    print("2. Scanning dataset for all indication variations")
    print("=" * 70)

    tokenizer = processor.tokenizer

    # Collect unique indication strings that contain our target substrings
    found = defaultdict(set)  # target_substr → {indication_string}
    for entry in dataset:
        ind = (entry.get("indication") or "").strip()
        if not ind:
            continue
        for sub in TARGET_SUBSTRINGS:
            if sub in ind.lower():
                found[sub].add(ind)

    for sub, indications in sorted(found.items()):
        print(f"\n  Substring: {sub!r}  ({len(indications)} unique strings)")
        for ind in sorted(indications):
            # Tokenize in two ways: plain and with preceding space
            ids_space = tokenizer.encode(" " + ind, add_special_tokens=False)
            ids_plain = tokenizer.encode(ind,       add_special_tokens=False)
            print(f"\n    Indication: {ind!r}")
            print(f"      ' '+ind : {ids_space}")
            print(f"      plain   : {ids_plain}")

            # Find where our target substring lands within the token sequence
            # by tokenizing with offsets
            enc = tokenizer(" " + ind, add_special_tokens=False,
                            return_offsets_mapping=True)
            ids_all = enc["input_ids"]
            offsets = enc["offset_mapping"]

            target_start = (" " + ind).lower().find(sub)
            target_end   = target_start + len(sub)
            tok_start, tok_end = None, None
            for i, (s, e) in enumerate(offsets):
                if s == e:
                    continue
                if tok_start is None and e > target_start:
                    tok_start = i
                if s < target_end:
                    tok_end = i + 1

            if tok_start is not None:
                phrase_ids = ids_all[tok_start:tok_end]
                phrase_str = tokenizer.decode(phrase_ids)
                print(f"      Phrase '{sub}' tokens: {phrase_ids}  → {phrase_str!r}")


def build_token_labels(processor, dataset):
    """Build TOKEN_LABELS from all unique indication strings found in dataset."""
    print("\n" + "=" * 70)
    print("3. Generating TOKEN_LABELS for orchestrate_v2.py")
    print("=" * 70)

    tokenizer = processor.tokenizer
    seen = {}  # ids_tuple → (label_str, ids_list)

    for entry in dataset:
        ind = (entry.get("indication") or "").strip()
        if not ind:
            continue
        low = ind.lower()
        for sub in TARGET_SUBSTRINGS:
            if sub not in low:
                continue

            # Find the exact substring match (preserving original case)
            idx = low.find(sub)
            phrase = ind[idx:idx+len(sub)]

            # Tokenize with a leading space (mid-sentence position)
            enc = tokenizer(" " + ind, add_special_tokens=False,
                            return_offsets_mapping=True)
            ids_all = enc["input_ids"]
            offsets = enc["offset_mapping"]

            target_start = (" " + ind).lower().find(sub)
            target_end   = target_start + len(sub)
            tok_start, tok_end = None, None
            for i, (s, e) in enumerate(offsets):
                if s == e:
                    continue
                if tok_start is None and e > target_start:
                    tok_start = i
                if s < target_end:
                    tok_end = i + 1

            if tok_start is None:
                continue

            phrase_ids = ids_all[tok_start:tok_end]
            key = (phrase, tuple(phrase_ids))
            if key not in seen:
                seen[key] = (phrase, list(phrase_ids))

    print("\nTOKEN_LABELS = [")
    for i, ((phrase, _), (label, ids)) in enumerate(sorted(seen.items())):
        id_str   = ", ".join(str(x) for x in ids)
        n_tokens = len(ids)
        n_bytes  = n_tokens * 8
        print(f"    ({label!r:<35s} [{id_str}]),  # {i}  ({n_tokens} tok, {n_bytes}B)")
    print("]")
    print()
    print("# Copy the above into orchestrate_v2.py TOKEN_LABELS.")
    print("# After updating, rebuild the dictionary with --build.")


def main():
    print(f"Loading tokenizer: {MODEL_ID} ...")
    try:
        from transformers import AutoProcessor
        processor = AutoProcessor.from_pretrained(MODEL_ID)
    except Exception as e:
        print(f"[!] Failed to load processor: {e}", file=sys.stderr)
        sys.exit(1)

    print(f"Loading dataset: {DATASET_PATH} ...")
    try:
        dataset = load_dataset(DATASET_PATH)
    except Exception as e:
        print(f"[!] Failed to load dataset: {e}", file=sys.stderr)
        sys.exit(1)
    print(f"  {len(dataset)} entries loaded.")

    verify_current_labels(processor)
    scan_dataset_indications(processor, dataset)
    build_token_labels(processor, dataset)


if __name__ == "__main__":
    main()
