"""
Read indication text from 669 samples in valid_indices.json,
classify each as covered vs uncovered by TOKEN_LABELS, and save as JSON.

Run on guest:
  python3 /tmp/analyze_indications.py
"""
import json
from pathlib import Path
from collections import Counter

DATASET = Path("/home/ubuntu/medical_ml/med_vlm/rexgradient/ReXGradient/metadata/rexgradient_test.json")
VALID_IDX = Path("/home/ubuntu/medical_ml/med_vlm/scripts/valid_indices.json")
OUT = Path("/tmp/indication_analysis.json")

TOKEN_LABEL_STRINGS = [
    "Chest pain", "Shortness of breath", "chest pain", "shortness of breath",
    "Chest Pain", "Chest PAIN", "CHEST PAIN", "Shortness of Breath", "shortness of Breath",
]

with open(DATASET) as f:
    data = json.load(f)
with open(VALID_IDX) as f:
    valid_indices = json.load(f)

results = []
for idx in valid_indices:
    ind = (data[idx].get("indication") or "").strip()
    matched = [lb for lb in TOKEN_LABEL_STRINGS if lb in ind]
    results.append({"index": idx, "indication": ind, "matched_labels": matched})

covered   = [r for r in results if r["matched_labels"]]
uncovered = [r for r in results if not r["matched_labels"]]

# uncovered indication frequency
unc_counter = Counter(r["indication"] for r in uncovered)

summary = {
    "total": len(results),
    "covered": len(covered),
    "uncovered": len(uncovered),
    "covered_label_dist": dict(Counter(
        lb for r in covered for lb in r["matched_labels"]
    )),
    "uncovered_top30": unc_counter.most_common(30),
    "per_index": results,
}

with open(OUT, "w") as f:
    json.dump(summary, f, indent=2)

print(f"covered:   {len(covered)} / {len(results)}")
print(f"uncovered: {len(uncovered)} / {len(results)}")
print()
print("=== covered label distribution ===")
for lb, cnt in sorted(summary["covered_label_dist"].items(), key=lambda x: -x[1]):
    print(f"  {cnt:4d}  {lb}")
print()
print("=== uncovered top-30 ===")
for ind, cnt in summary["uncovered_top30"]:
    print(f"  {cnt:4d}  {repr(ind)}")

print(f"\n→ saved: {OUT}")
