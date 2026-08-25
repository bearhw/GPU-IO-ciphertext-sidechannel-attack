#!/usr/bin/env python3
"""
Rebuild filtered_samples.json from the full rexgradient_test.json (3463
raw samples): keep only samples whose indication text, tokenized IN-CONTEXT
the same way single_inference_indication_gpa.py does, actually CONTAINS one
of TOKEN_LABELS' exact id sequences as a contiguous subsequence.

Sentence-initial BPE forms (e.g. "Cough"→[C,ough] vs mid " Cough"→[ĠC,ough])
are NOT the same ids. If a clinical word sits at the start of the indication
and TOKEN_LABELS only has the mid-form, that sample is dropped unless some
other in-span label still matches.

Run on the GUEST (needs the Qwen2-VL processor/tokenizer):
    conda activate vlm
    cd ~/medical_ml/med_vlm/scripts
    python3 rebuild_filtered_samples.py \
        --raw-json ../rexgradient/ReXGradient/metadata/rexgradient_test.json \
        --out filtered_samples.json
"""

import argparse
import json
import sys

TOKEN_LABELS = [
    (' of breath',                         [315, 11486]),
    ('ness of',                            [2090, 315]),
    (' Shortness',                         [10698, 2090]),
    (' Cough',                             [356, 1384]),
    (' shortness',                         [2805, 2090]),
    (' breath.',                           [11486, 13]),
    (' chest pain',                        [15138, 6646]),
    (' Chest pain',                        [41771, 6646]),
    (' breath,',                           [11486, 11]),
    (' Respiratory',                       [76834, 5269]),
    ('ough and',                           [1384, 323]),
    (', short',                            [11, 2805]),
    (' cough.',                            [39600, 13]),
    (' pneumonia.',                        [68229, 13]),
    (' cough,',                            [39600, 11]),
    (' rib pain',                          [20131, 6646]),
    (' COPD',                              [67572, 35]),
    (' Follow-up',                         [11112, 5239]),
    (' Weakness',                          [41164, 2090]),
    (' wheez',                             [14894, 10125]),
    (' PICC',                              [60606, 34]),
    (' CABG',                              [80117, 38]),
    (' COVID-',                            [19966, 12]),
    (' fever.',                            [33553, 13]),
    (' respiratory failure',               [41531, 7901]),
    (' pneumoth',                          [56123, 8767]),
    (' Fever.',                            [83901, 13]),
    (' Hypert',                            [38415, 529]),
    (' catheter',                          [30647, 1404]),
    (' Hypox',                             [38415, 5131]),
]


def contains_sublist(haystack: list, needle: list) -> bool:
    n = len(needle)
    return any(haystack[i:i + n] == needle for i in range(len(haystack) - n + 1))


def _user_text(raw: dict) -> str:
    """Match single_inference_indication_gpa.py: conversations[0].value, not reason."""
    conv = raw.get("conversations")
    if isinstance(conv, list) and conv:
        val = (conv[0].get("value") or "").replace("<image>", "").strip()
        if val:
            return val
    return (raw.get("reason") or "").strip()


def indication_token_ids(processor, raw: dict) -> list[int] | None:
    """Indication token ids in the same post-<|vision_end|> text space used
    by find_indication_token_span (no image expansion needed for the text
    after vision_end)."""
    tokenizer = processor.tokenizer
    indication = raw.get("indication", "") or ""
    reason_text = _user_text(raw)
    if not indication or not reason_text:
        return None

    # Prefer the same helper the attack path uses when available.
    try:
        from prediction import build_user_prompt
        sample = {
            "messages": [{
                "role": "user",
                "content": [
                    {"type": "image", "image": "dummy.jpg"},
                    {"type": "text", "text": reason_text},
                ],
            }]
        }
        full_text = build_user_prompt(
            processor, sample, model_id="Qwen/Qwen2-VL-2B-Instruct")
    except Exception:
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


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("--raw-json", default="../rexgradient/ReXGradient/metadata/rexgradient_test.json")
    p.add_argument("--model-id", default="Qwen/Qwen2-VL-2B-Instruct")
    p.add_argument("--out", default="filtered_samples.json")
    args = p.parse_args()

    from transformers import AutoProcessor
    processor = AutoProcessor.from_pretrained(args.model_id)

    with open(args.raw_json) as f:
        raw_entries = json.load(f)
    print(f"[rebuild] {len(raw_entries)} raw samples loaded from {args.raw_json}")
    print(f"[rebuild] TOKEN_LABELS={len(TOKEN_LABELS)} (exact id subsequence required)")

    kept = []
    n_resolved = n_matched = 0
    n_drop_no_label = 0
    for index, raw in enumerate(raw_entries):
        ids = indication_token_ids(processor, raw)
        if ids is None:
            continue
        n_resolved += 1

        matched = [i for i, (_, label_ids) in enumerate(TOKEN_LABELS)
                   if contains_sublist(ids, label_ids)]
        if not matched:
            n_drop_no_label += 1
            continue
        n_matched += 1

        kept.append({
            "index":       index,
            "id":          raw.get("id"),
            "indication":  raw.get("indication"),
            "findings":    raw.get("findings"),
            "reason":      raw.get("reason"),
            "impression":  raw.get("impression"),
            "matched_token_idx": matched,
            "matched_labels":    [TOKEN_LABELS[i][0] for i in matched],
            "indication_token_ids": ids,
        })

        if n_matched % 200 == 0:
            print(f"  ... {index + 1}/{len(raw_entries)} scanned, {n_matched} matched so far")

    print(f"[rebuild] resolved indication span for {n_resolved}/{len(raw_entries)}")
    print(f"[rebuild] dropped (resolved but no TOKEN_LABELS id hit): {n_drop_no_label}")
    print(f"[rebuild] {n_matched} samples contain at least one TOKEN_LABELS entry in-context")

    with open(args.out, "w") as f:
        json.dump(kept, f, indent=2)
    print(f"[rebuild] wrote {len(kept)} samples → {args.out}")


if __name__ == "__main__":
    main()
