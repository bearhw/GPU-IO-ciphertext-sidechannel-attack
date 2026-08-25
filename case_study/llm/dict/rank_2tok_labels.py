#!/usr/bin/env python3
"""
Rank in-context 2-token n-grams from the indication span.

Tokenization matches single_inference_indication_gpa.py /
rebuild_filtered_samples.py: chat-template text from reason, split at
<|vision_end|>, tokenize post-image text alone, take the indication span.

By default drops "meaningless" bigrams (demographic/admin, glue-only,
mid-word BPE starts, weak solo+punct) but always keeps:
  'ough and', 'breath.', 'of breath', ', short', 'ness of'
Always drops: 'Acute', 'tube placement', 'Altered', 'line placement'

Run on the GUEST:
    conda activate vlm
    cd ~/medical_ml/med_vlm/scripts
    python3 rank_2tok_labels.py \
        --raw-json ../rexgradient/ReXGradient/metadata/rexgradient_test.json \
        --ids-cache indication_ids_cache.json \
        --out 2tok_rank.json --out-txt 2tok_rank.txt --top 200

Pass --no-clinical-filter to keep everything (only --deny-regex applies).
"""

from __future__ import annotations

import argparse
import json
import os
import re
from collections import Counter, defaultdict

# Function / glue words that alone (or with punct) are not useful labels.
_GLUE_WORDS = frozenset({
    "a", "an", "the", "of", "to", "in", "on", "at", "for", "and", "or",
    "with", "without", "from", "by", "as", "is", "are", "was", "were",
    "be", "been", "being", "this", "that", "these", "those", "his", "her",
    "their", "our", "my", "your", "vs", "via", "per", "post", "pre",
    "status", "history", "hx", "yo", "y/o", "old", "male", "female",
    "man", "woman", "patient", "pt", "year", "years", "day", "days",
    "week", "weeks", "month", "months", "hour", "hours", "age",
    "due", "after", "before", "since", "over", "under", "into", "onto",
})

_DEFAULT_DENY = [
    r"year-old",
    r"-old\s+(male|female|man|woman)",
    r"\bmale with\b",
    r"\bfemale with\b",
    r"status post",
    r"\bhistory\b",
    r"encounter",
    r"^\s*(for\s+)?\d+\s*(day|days|week|weeks|month|months|hour|hours)s?\.?,?\s*$",
    r"^\s*\d+\s*$",
    r"^\s*[\.,;:\-–—/]+\s*$",
]


def indication_token_ids(processor, raw: dict) -> list[int] | None:
    tokenizer = processor.tokenizer
    indication = raw.get("indication", "") or ""
    reason_text = raw.get("reason", "") or ""
    if not indication or not reason_text:
        return None

    sample = {
        "messages": [{
            "role": "user",
            "content": [
                {"type": "image", "image": "dummy.jpg"},
                {"type": "text", "text": reason_text},
            ],
        }]
    }
    try:
        full_text = processor.apply_chat_template(
            sample["messages"], tokenize=False, add_generation_prompt=True)
    except Exception:
        return None

    marker = "<|vision_end|>"
    pos = full_text.find(marker)
    post_image_text = full_text[pos + len(marker):] if pos != -1 else full_text

    char_start = post_image_text.find(indication)
    if char_start == -1:
        return None
    char_end = char_start + len(indication)

    post_enc = tokenizer(post_image_text, return_offsets_mapping=True,
                         add_special_tokens=False)
    post_ids = post_enc["input_ids"]
    post_offsets = post_enc["offset_mapping"]

    tok_start, tok_end = None, None
    for i, (cs, ce) in enumerate(post_offsets):
        if cs == ce:
            continue
        if tok_start is None and ce > char_start:
            tok_start = i
        if cs < char_end:
            tok_end = i + 1

    if tok_start is None or tok_end is None:
        return None
    return post_ids[tok_start:tok_end]


def load_or_build_ids_cache(processor, raw_entries, cache_path: str | None):
    if cache_path and os.path.exists(cache_path):
        with open(cache_path) as f:
            cache = json.load(f)
        print(f"[2tok] loaded ids cache {cache_path} ({len(cache)} entries)")
        return {int(k): v for k, v in cache.items()}

    cache: dict[int, list[int]] = {}
    for index, raw in enumerate(raw_entries):
        ids = indication_token_ids(processor, raw)
        if ids is not None:
            cache[index] = ids
        if (index + 1) % 500 == 0:
            print(f"  ... tokenized {index + 1}/{len(raw_entries)}")
    if cache_path:
        with open(cache_path, "w") as f:
            json.dump(cache, f)
        print(f"[2tok] wrote ids cache → {cache_path}")
    return cache


def _alpha_words(text: str) -> list[str]:
    return re.findall(r"[A-Za-z][A-Za-z\-']*", text)


# Always keep these surface forms (and leading-space variants) even if they
# trip BPE/glue/punct heuristics — user-requested for SOB/cough phrase pieces.
_KEEP_ALWAYS = frozenset({
    "ough and",
    "breath.",
    "of breath",
    ", short",
    "ness of",
})

# Always drop these (strip/lower), even if they pass clinical heuristics.
_DROP_ALWAYS = frozenset({
    "acute",
    "tube placement",
    "altered",
    "line placement",
})


def _keep_key(text: str) -> str:
    return re.sub(r"\s+", " ", text.strip().lower())


def _is_bpe_continuation(tok_text: str) -> bool:
    """True if this single-token decode looks like a mid-word BPE piece
    (no leading space/punct, starts with lowercase letter)."""
    if not tok_text:
        return True
    if tok_text[0] in " \t\n.,;:!?-–—/\\\"'([{":
        return False
    return tok_text[0].islower()


def clinical_reject_reason(text: str, tok_a: str, tok_b: str,
                           min_content_len: int) -> str | None:
    """Return a short reason string if this bigram should be dropped, else None."""
    stripped = text.strip()
    if not stripped:
        return "empty"

    if _keep_key(text) in _KEEP_ALWAYS:
        return None
    if _keep_key(text) in _DROP_ALWAYS:
        return "drop_always"

    # Pure punctuation / whitespace glue
    if re.fullmatch(r"[\s\W_]+", text):
        return "punct_only"

    # Leading comma/period glue: '. History' (', short' is whitelisted above)
    if re.match(r"^[\s]*[\.,;:]\s", text):
        return "punct_prefix"

    # Mid-word start: first token is a BPE continuation
    # Second token being a continuation is normal (e.g. ' C'+'ough' → ' Cough').
    if _is_bpe_continuation(tok_a):
        return "bpe_fragment"

    words = _alpha_words(text)
    if not words:
        return "no_alpha"

    # Starts with a function word: ' and short', ' for ' (' of breath' whitelisted)
    if words[0].lower() in _GLUE_WORDS:
        return "starts_with_glue"

    # Ends with a function word: ' breath and', ' pain for'
    if words[-1].lower() in _GLUE_WORDS:
        return "ends_with_glue"

    # Need at least one real content word
    content = [w for w in words
               if w.lower() not in _GLUE_WORDS and len(w) >= min_content_len]
    if not content:
        return "glue_only"

    # Ultra-generic lone noun + punctuation (' pain.', ' failure.') —
    # 'breath.' is whitelisted above.
    _weak_solo = frozenset({
        "pain", "failure", "placement", "status", "line", "tube",
    })
    if (len(content) == 1
            and content[0].lower() in _weak_solo
            and re.search(r"[\.,;:]\s*$", text)):
        return "weak_solo_punct"

    return None


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--raw-json",
                   default="../rexgradient/ReXGradient/metadata/rexgradient_test.json")
    p.add_argument("--model-id", default="Qwen/Qwen2-VL-2B-Instruct")
    p.add_argument("--ids-cache", default="indication_ids_cache.json",
                   help="Reuse/write cache. Empty string disables.")
    p.add_argument("--min-count", type=int, default=3)
    p.add_argument("--min-samples", type=int, default=1)
    p.add_argument("--top", type=int, default=0)
    p.add_argument("--min-content-len", type=int, default=4,
                   help="Min letters in a non-glue word required to keep a bigram")
    p.add_argument("--no-clinical-filter", action="store_true",
                   help="Disable BPE/glue filters; only --deny-regex applies")
    p.add_argument("--deny-regex", action="append", default=None,
                   help="Extra deny patterns (repeatable). Defaults always applied "
                        "unless --no-default-deny.")
    p.add_argument("--no-default-deny", action="store_true")
    p.add_argument("--out", default="2tok_rank.json")
    p.add_argument("--out-txt", default="2tok_rank.txt")
    args = p.parse_args()

    from transformers import AutoProcessor
    processor = AutoProcessor.from_pretrained(args.model_id)
    tokenizer = processor.tokenizer

    with open(args.raw_json) as f:
        raw_entries = json.load(f)
    print(f"[2tok] {len(raw_entries)} raw samples from {args.raw_json}")

    cache_path = args.ids_cache or None
    ids_cache = load_or_build_ids_cache(processor, raw_entries, cache_path)
    print(f"[2tok] {len(ids_cache)} samples with resolved indication ids")

    abs_count: Counter = Counter()
    sample_hits: dict[tuple, set[int]] = defaultdict(set)
    text_votes: dict[tuple, Counter] = defaultdict(Counter)

    for index, ids in ids_cache.items():
        if len(ids) < 2:
            continue
        seen_here: set[tuple] = set()
        for i in range(len(ids) - 1):
            gram = (ids[i], ids[i + 1])
            abs_count[gram] += 1
            text_votes[gram][tokenizer.decode(list(gram))] += 1
            seen_here.add(gram)
        for gram in seen_here:
            sample_hits[gram].add(index)

    deny_pats = []
    if not args.no_default_deny:
        deny_pats.extend(_DEFAULT_DENY)
    if args.deny_regex:
        deny_pats.extend(args.deny_regex)
    deny_res = [re.compile(pat, re.IGNORECASE) for pat in deny_pats]

    drop_reasons: Counter = Counter()
    rows = []
    for gram, n_abs in abs_count.items():
        n_samples = len(sample_hits[gram])
        if n_abs < args.min_count or n_samples < args.min_samples:
            continue
        best_text, _ = text_votes[gram].most_common(1)[0]
        tok_a = tokenizer.decode([gram[0]])
        tok_b = tokenizer.decode([gram[1]])

        if any(r.search(best_text) for r in deny_res):
            drop_reasons["deny_regex"] += 1
            continue

        if not args.no_clinical_filter:
            why = clinical_reject_reason(
                best_text, tok_a, tok_b, args.min_content_len)
            if why:
                drop_reasons[why] += 1
                continue

        rows.append({
            "rank": 0,
            "text": best_text,
            "ids": list(gram),
            "tok_texts": [tok_a, tok_b],
            "abs": n_abs,
            "samples": n_samples,
            "coverage": round(n_samples / len(ids_cache), 6) if ids_cache else 0.0,
        })

    rows.sort(key=lambda r: (-r["samples"], -r["abs"], r["ids"]))
    if args.top > 0:
        rows = rows[: args.top]
    for i, r in enumerate(rows, 1):
        r["rank"] = i

    with open(args.out, "w") as f:
        json.dump({
            "n_raw": len(raw_entries),
            "n_resolved": len(ids_cache),
            "min_count": args.min_count,
            "min_samples": args.min_samples,
            "clinical_filter": not args.no_clinical_filter,
            "dropped": dict(drop_reasons),
            "n_bigrams": len(rows),
            "bigrams": rows,
        }, f, indent=2)
    print(f"[2tok] wrote {len(rows)} bigrams → {args.out}")
    print(f"[2tok] dropped: {dict(drop_reasons)}")

    with open(args.out_txt, "w") as f:
        f.write(f"# 2-token clinical-ish bigrams  resolved={len(ids_cache)}/{len(raw_entries)}\n")
        f.write(f"# clinical_filter={not args.no_clinical_filter}  "
                f"dropped={dict(drop_reasons)}\n")
        f.write("# sorted by samples desc, then abs desc\n")
        for r in rows:
            f.write(
                f"[{r['rank']:4d}] samples={r['samples']:4d} abs={r['abs']:4d}  "
                f"{r['text']!r}  ids={r['ids']}\n"
            )
    print(f"[2tok] wrote {args.out_txt}")

    print("\n[2tok] top 30:")
    for r in rows[:30]:
        print(f"  #{r['rank']:<3d} samples={r['samples']:<4d} abs={r['abs']:<4d} "
              f"{r['text']!r}  {r['ids']}")


if __name__ == "__main__":
    main()
