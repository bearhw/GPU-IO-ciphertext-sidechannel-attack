#!/usr/bin/env python3
"""
Standalone diagnostic — re-derive in-context token n-grams from
filtered_samples.json, the same way single_inference_indication_gpa.py's
find_indication_token_span() does (build the chat-template text, split at
<|vision_end|>, tokenize the post-image text alone with offset mapping) —
but without loading the model or any real image, since none of that affects
the indication text's own token IDs.

Run on the GUEST (needs the Qwen2-VL processor/tokenizer):
    conda activate vlm
    python3 token_study.py --json filtered_samples.json --min-count 2 --max-n 8
"""

import argparse
import json
from collections import Counter


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("--json", default="filtered_samples.json")
    p.add_argument("--model-id", default="Qwen/Qwen2-VL-2B-Instruct")
    p.add_argument("--min-count", type=int, default=2)
    p.add_argument("--min-n", type=int, default=2)
    p.add_argument("--max-n", type=int, default=14)
    p.add_argument("--out", default="token_study2.txt")
    args = p.parse_args()

    from transformers import AutoProcessor
    processor = AutoProcessor.from_pretrained(args.model_id)
    tokenizer = processor.tokenizer

    with open(args.json) as f:
        samples = json.load(f)
    print(f"[study] {len(samples)} samples loaded from {args.json}")

    # ngram -> Counter(text -> count), so we can report the most common
    # surface text for each distinct id-sequence.
    ngram_counts: dict[tuple, Counter] = {}
    n_ok = n_fail = 0

    for s in samples:
        indication = s.get("indication", "") or ""
        reason_text = s.get("reason", "") or ""
        if not indication or not reason_text:
            n_fail += 1
            continue

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
        except Exception as e:
            print(f"  [!] apply_chat_template failed idx={s.get('index')}: {e}")
            n_fail += 1
            continue

        marker = "<|vision_end|>"
        pos = full_text.find(marker)
        post_image_text = full_text[pos + len(marker):] if pos != -1 else full_text

        char_start = post_image_text.find(indication)
        if char_start == -1:
            n_fail += 1
            continue
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
            n_fail += 1
            continue

        indication_ids = post_ids[tok_start:tok_end]
        n_ok += 1

        for n in range(args.min_n, args.max_n + 1):
            for i in range(0, len(indication_ids) - n + 1):
                gram = tuple(indication_ids[i:i + n])
                text = tokenizer.decode(list(gram))
                ngram_counts.setdefault(gram, Counter())[text] += 1

    print(f"[study] resolved {n_ok} indication spans, {n_fail} failed")

    # Flatten: (n, total_count, gram, best_text) sorted by n desc, count desc
    rows = []
    for gram, texts in ngram_counts.items():
        total = sum(texts.values())
        if total < args.min_count:
            continue
        best_text, best_count = texts.most_common(1)[0]
        rows.append((len(gram), total, best_count, best_text, gram))

    rows.sort(key=lambda r: (-r[0], -r[1]))

    with open(args.out, "w") as f:
        for n, total, best_count, text, gram in rows:
            f.write(f"[{n}tok x {total}hits] {text!r} ids={list(gram)}\n")

    print(f"[study] wrote {len(rows)} n-grams (count>={args.min_count}) → {args.out}")


if __name__ == "__main__":
    main()
