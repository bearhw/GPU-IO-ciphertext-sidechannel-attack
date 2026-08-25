#!/usr/bin/env python3
"""
Greedily select TOKEN_LABELS to cover >= --target ground-truth samples.

1. Tokenize every raw sample's indication span in-context (cached to disk
   so re-runs with a different --target don't re-pay tokenization cost).
2. Candidate pool = every even-length (4/6/8) n-gram (count >= --min-count)
   from the full-dataset token study, plus current TOKEN_LABELS entries.
3. Default: start from EXISTING TOKEN_LABELS coverage, then add candidates
   until covered >= --target.
4. --from-scratch: start empty and greedily pick a minimal set that reaches
   --target (use this to shrink an overgrown label list).

Run on the GUEST:
    conda activate vlm
    cd ~/medical_ml/med_vlm/scripts
    python3 select_labels.py --target 1000 --from-scratch
"""

import argparse
import json
import os
import re

from rebuild_filtered_samples import TOKEN_LABELS, indication_token_ids, contains_sublist


def load_or_build_ids_cache(processor, raw_entries, cache_path):
    if os.path.exists(cache_path):
        with open(cache_path) as f:
            cache = json.load(f)
        return {int(k): v for k, v in cache.items()}

    cache = {}
    for index, raw in enumerate(raw_entries):
        ids = indication_token_ids(processor, raw)
        if ids is not None:
            cache[index] = ids
        if (index + 1) % 500 == 0:
            print(f"  ... tokenized {index + 1}/{len(raw_entries)}")
    with open(cache_path, "w") as f:
        json.dump(cache, f)
    return cache


def load_candidates(study_path, min_count):
    """Parse token_study.py output lines into [(count, text, ids), ...]."""
    out = []
    pat = re.compile(r"\[(\d+)tok x (\d+)hits\] (.*) ids=(\[.*\])")
    with open(study_path) as f:
        for line in f:
            m = pat.match(line.strip())
            if not m:
                continue
            n, count, text, ids = m.groups()
            count = int(count)
            n = int(n)
            if count < min_count:
                continue
            # Even-length only (AES-friendly); skip 2tok and odd lengths.
            if n < 4 or n % 2 != 0:
                continue
            out.append((count, eval(text), tuple(eval(ids))))
    return out


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("--raw-json", default="../rexgradient/ReXGradient/metadata/rexgradient_test.json")
    p.add_argument("--study", default="token_study_full46.txt",
                   help="n-gram candidate pool (from token_study.py against the raw json)")
    p.add_argument("--model-id", default="Qwen/Qwen2-VL-2B-Instruct")
    p.add_argument("--target", type=int, default=1000)
    p.add_argument("--min-count", type=int, default=3)
    p.add_argument("--ids-cache", default="indication_ids_cache.json")
    p.add_argument("--from-scratch", action="store_true",
                   help="Ignore current TOKEN_LABELS as baseline; greedily "
                        "build a minimal set covering --target samples.")
    p.add_argument("--deny-regex", action="append", default=[
        r"year-old",
        r"^\s*(for\s+)?\d+\s*(day|days|week|weeks|month|months|hour|hours)s?\.?,?\s*$",
        r"encounter",
        r"^\s*history of\s*$",
    ], help="Skip candidates whose text matches ANY of these (demographic/"
             "administrative/pure-duration filler, not clinical content). "
             "Repeatable; defaults cover the common non-clinical patterns.")
    args = p.parse_args()

    from transformers import AutoProcessor
    processor = AutoProcessor.from_pretrained(args.model_id)

    with open(args.raw_json) as f:
        raw_entries = json.load(f)
    print(f"[select] {len(raw_entries)} raw samples")

    ids_cache = load_or_build_ids_cache(processor, raw_entries, args.ids_cache)
    print(f"[select] {len(ids_cache)} samples with resolved indication ids"
          f" (cache: {args.ids_cache})")

    clinical_labels = [(l, ids) for l, ids in TOKEN_LABELS if l != "image_pad×4"]

    covered: set[int] = set()
    if not args.from_scratch:
        for index, ids in ids_cache.items():
            for _, label_ids in clinical_labels:
                if contains_sublist(ids, label_ids):
                    covered.add(index)
                    break
        print(f"[select] baseline (current {len(clinical_labels)} labels): "
              f"{len(covered)} samples covered")
    else:
        print(f"[select] from-scratch: ignoring {len(clinical_labels)} existing "
              f"labels as baseline (they remain candidate seeds)")

    deny_res = [re.compile(pat, re.IGNORECASE) for pat in args.deny_regex]

    # Dedup by ids: study ngrams + current labels (as seeds).
    by_ids: dict[tuple, tuple] = {}
    for count, text, ids in load_candidates(args.study, args.min_count):
        if any(r.search(text) for r in deny_res):
            continue
        by_ids[ids] = (count, text, ids)
    for text, ids in clinical_labels:
        t = tuple(ids)
        if len(t) < 4 or len(t) % 2 != 0:
            continue
        if t not in by_ids:
            by_ids[t] = (0, text, t)

    candidates = list(by_ids.values())
    print(f"[select] {len(candidates)} candidate n-grams (even len>=4, "
          f"count>={args.min_count} or existing label, not deny)")

    cand_matches = []
    for count, text, ids in candidates:
        matched = {index for index, sample_ids in ids_cache.items()
                   if contains_sublist(sample_ids, list(ids))}
        if matched:
            cand_matches.append([text, ids, matched])
    print(f"[select] {len(cand_matches)} candidates have >=1 real match")

    chosen = []
    while len(covered) < args.target and cand_matches:
        best_i, best_gain = None, -1
        for i, (text, ids, matched) in enumerate(cand_matches):
            gain = len(matched - covered)
            if gain > best_gain:
                best_gain, best_i = gain, i
        if best_gain <= 0:
            print("[select] no candidate adds any new sample — stopping short of target")
            break
        text, ids, matched = cand_matches.pop(best_i)
        covered |= matched
        chosen.append((text, ids, best_gain))
        print(f"  + {text!r:40s} ids={list(ids)}  +{best_gain} new"
              f"  (total covered={len(covered)})")

    print(f"\n[select] final covered: {len(covered)} / target {args.target}")
    print(f"[select] selected {len(chosen)} labels"
          f"{' (from-scratch)' if args.from_scratch else ' (added on top of baseline)'}:")
    for text, ids, gain in chosen:
        print(f"  {text!r:40s} {list(ids)}  (+{gain})")

    out = [{"text": t, "ids": list(i), "gain": g} for t, i, g in chosen]
    with open("selected_labels.json", "w") as f:
        json.dump(out, f, indent=2)
    print("\n[select] wrote selected_labels.json")

    if args.from_scratch:
        # Also emit a ready-to-paste TOKEN_LABELS snippet (no image_pad).
        lines = ["TOKEN_LABELS = ["]
        for text, ids, _ in sorted(chosen, key=lambda x: (-len(x[1]), x[0])):
            lines.append(f"    ({text!r},".ljust(44) + f" {list(ids)}),")
        lines.append('    ("image_pad×4",                          [IMAGE_PAD_TOKEN_ID] * 4),')
        lines.append("]")
        with open("selected_TOKEN_LABELS.py", "w") as f:
            f.write("\n".join(lines) + "\n")
        print("[select] wrote selected_TOKEN_LABELS.py")
        phases = sum(len(i) for _, i, _ in chosen)
        print(f"[select] {len(chosen)} labels, {phases} phases")


if __name__ == "__main__":
    main()
