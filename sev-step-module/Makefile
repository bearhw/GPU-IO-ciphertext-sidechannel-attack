CC      ?= gcc
CFLAGS  := -Wall -Wextra -O2 -g -I. -I..

TARGETS := write_pattern_tracker write_pattern_tracker_early_exit write_pattern_tracker_B write_pattern_tracker_desc

.PHONY: all clean

all: $(TARGETS)

write_pattern_tracker: write_pattern_tracker.c
	@echo "  CC  $@ (write pattern tracker for tensor identification)"
	$(CC) $(CFLAGS) -o $@ $<
	@echo "  Built: $@"
	@echo "  Run:   sudo ./$@ --duration 60 > writes.log"

write_pattern_tracker_early_exit: write_pattern_tracker_early_exit.c
	@echo "  CC  $@ (early-exit image GPA finder via 0x3f8 precursor)"
	$(CC) $(CFLAGS) -o $@ $<
	@echo "  Built: $@"
	@echo "  Run:   sudo ./$@ [--duration 120] [--min-run 8] [--lookahead 30]"

write_pattern_tracker_B: write_pattern_tracker_B.c
	@echo "  CC  $@ (region-B precursor + timing-gated image GPA finder)"
	$(CC) $(CFLAGS) -o $@ $<
	@echo "  Built: $@"
	@echo "  Run:   sudo ./$@ [--duration 120] [--window-us 40] [--lookahead 12]"

write_pattern_tracker_desc: write_pattern_tracker_desc.c
	@echo "  CC  $@ (descending-run image GPA detector)"
	$(CC) $(CFLAGS) -o $@ $<
	@echo "  Built: $@"
	@echo "  Run:   sudo ./$@ [--duration 120] [--min-run 30] [--max-gap 3]"


clean:
	rm -f $(TARGETS)
