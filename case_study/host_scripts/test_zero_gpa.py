#!/usr/bin/env python3
"""Quick test: run acquire_zero_gpa() 5 times and print each result.

Run on the HOST (this directory), not inside the guest:
    sudo python3 test_zero_gpa.py
"""
import orchestrate

for i in range(5):
    gpa = orchestrate.acquire_zero_gpa()
    print(f"--- run {i}: zero_gpa=0x{gpa:x} ---")
