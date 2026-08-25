/*
 * write_pattern_tracker_B.c
 *
 * Refinement of write_pattern_tracker_early_exit that keys on the REAL image
 * precursor discovered by trace analysis:
 *
 *   Region B  = [0x3f80000000, 0x3f90000000)  ("0x3f8...")
 *       Written in a short burst (1-5 pages, addresses change every transfer)
 *       immediately before each image DMA. Empirically the image contiguous
 *       run begins a median of 8-14 writes / ~24-45 us after a B write
 *       (p90 <= ~27 writes / ~88 us). THIS is the precursor we trigger on.
 *
 *   Region A  = [0x3f7fc00000, 0x3f7fd00000)  ("0x3f7fc...")
 *       A FIXED 26-page structure (identical GPA across every run) touched
 *       ~once per batch as a "clock". It is NOT correlated with the image DMA
 *       moment (appears within 25 writes before an image start only ~0-3% of
 *       the time), so treating it as a precursor only opens empty lookahead
 *       windows and pollutes the ranking. We therefore EXCLUDE it explicitly.
 *
 * Differences vs. write_pattern_tracker_early_exit:
 *   1. precursor = region B only (A is never a precursor).
 *   2. timing gate: the candidate run must START within --window-us of the
 *      triggering B write's timestamp. This rejects long unrelated runs that
 *      merely happen to fall inside the write-count lookahead.
 *   3. pages inside region A or B are skipped when building a run.
 *   4. tighter defaults (lookahead 12) matched to the measured B->image gap.
 *
 * Validated offline on 8 host traces: the true image buffer is present in the
 * candidate list in 8/8 runs, ranked #1 in 3/8, top-3 in 5/8, top-5 in 7/8
 * (the sole top-5 miss, run7, had almost no cleanly-captured image runs).
 *
 * On exit:
 *   stderr : ranked table of top 5 candidates
 *   stdout : "IMAGE_GPA_1=0x<addr>" ... (machine-readable)
 *   exit 0 if >=1 candidate found, exit 1 otherwise
 *
 * Build: make write_pattern_tracker_B
 * Run:   sudo ./write_pattern_tracker_B [options]
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>

#include <linux/kvm.h>

/* ── candidate tracking ──────────────────────────────────────────── */
#define MAX_CANDIDATES 256
#define TOP_N          5

typedef struct {
    uint64_t aligned_gpa;    /* 2MB-aligned (coarse) */
    uint64_t best_exact_gpa; /* 4KB-aligned run start from the longest run */
    unsigned hit_count;
    int      max_run_len;
} candidate_t;

static candidate_t g_candidates[MAX_CANDIDATES];
static int         g_n_candidates = 0;

static void record_hit(uint64_t aligned_gpa, uint64_t exact_gpa, int run_len)
{
    for (int i = 0; i < g_n_candidates; i++) {
        if (g_candidates[i].aligned_gpa == aligned_gpa) {
            g_candidates[i].hit_count++;
            if (run_len > g_candidates[i].max_run_len)
                g_candidates[i].max_run_len = run_len;
            if (exact_gpa < g_candidates[i].best_exact_gpa)
                g_candidates[i].best_exact_gpa = exact_gpa;
            return;
        }
    }
    if (g_n_candidates < MAX_CANDIDATES) {
        g_candidates[g_n_candidates++] = (candidate_t){
            .aligned_gpa    = aligned_gpa,
            .best_exact_gpa = exact_gpa,
            .hit_count      = 1,
            .max_run_len    = run_len,
        };
    }
}

static int cmp_candidates(const void *a, const void *b)
{
    const candidate_t *ca = a, *cb = b;
    unsigned sa = ca->hit_count * (unsigned)ca->max_run_len;
    unsigned sb = cb->hit_count * (unsigned)cb->max_run_len;
    if (sb != sa) return (sb > sa) ? 1 : -1;
    return (cb->hit_count > ca->hit_count) ? 1 : -1;
}

static void print_results(unsigned long total_entries, unsigned long precursor_hits)
{
    if (g_n_candidates == 0) {
        fprintf(stderr, "[RESULT] No candidates found.\n");
        return;
    }

    qsort(g_candidates, g_n_candidates, sizeof(candidate_t), cmp_candidates);

    int top = g_n_candidates < TOP_N ? g_n_candidates : TOP_N;

    fprintf(stderr,
        "================================================================\n"
        "  TOP %d IMAGE GPA CANDIDATES  (region-B precursor + timing gate)\n"
        "  entries=%lu  B_precursor_hits=%lu  unique_candidates=%d\n"
        "================================================================\n"
        "  Rank  2MB-aligned GPA             4KB-exact GPA               hits  max_run  score\n"
        "  ----  --------------------------  --------------------------  ----  -------  -----\n",
        top, total_entries, precursor_hits, g_n_candidates);

    for (int i = 0; i < top; i++) {
        unsigned score = g_candidates[i].hit_count * (unsigned)g_candidates[i].max_run_len;
        fprintf(stderr, "  #%d    0x%016llx  0x%016llx  %4u    %5d  %5u\n",
            i + 1,
            (unsigned long long)g_candidates[i].aligned_gpa,
            (unsigned long long)g_candidates[i].best_exact_gpa,
            g_candidates[i].hit_count,
            g_candidates[i].max_run_len,
            score);
    }
    fprintf(stderr, "================================================================\n\n");

    for (int i = 0; i < top; i++) {
        printf("IMAGE_GPA_%d=0x%016llx  IMAGE_GPA_EXACT_%d=0x%016llx\n",
               i + 1, (unsigned long long)g_candidates[i].aligned_gpa,
               i + 1, (unsigned long long)g_candidates[i].best_exact_gpa);
    }
    fflush(stdout);
}

/* ── tunables ────────────────────────────────────────────────────── */
#define DEFAULT_GUEST_GB      256
#define DEFAULT_DURATION_S    120
#define DEFAULT_SETTLE_S      3
#define DEFAULT_DRAIN_MS      2
#define DEFAULT_REARM_MS      20
#define DEFAULT_LOOKAHEAD     12       /* B->image gap p90 ~27 writes; 12 keeps it tight */
#define DEFAULT_MIN_RUN       2
#define DEFAULT_GAP           2
#define DEFAULT_WINDOW_US     40       /* run must start <= this after the B write */

#define MAX_DRAIN_DST         8192

#define PAGE                  0x1000ULL
#define ALIGN_2MB             0x200000ULL

/* region B: the per-transfer image DMA precursor */
#define B_LO                  0x0000003f80000000ULL
#define B_HI                  0x0000003f90000000ULL
/* region A: the fixed per-batch clock — excluded */
#define A_LO                  0x0000003f7fc00000ULL
#define A_HI                  0x0000003f7fd00000ULL

/* ── globals ─────────────────────────────────────────────────────── */
static volatile sig_atomic_t g_stop = 0;
static void on_signal(int sig) { (void)sig; g_stop = 1; }

static void sleep_ms(unsigned ms)
{
    struct timespec ts = { ms / 1000, (long)(ms % 1000) * 1000000L };
    nanosleep(&ts, NULL);
}

static uint64_t now_ns(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
}

static int in_B(uint64_t gpa) { return gpa >= B_LO && gpa < B_HI; }
static int in_A(uint64_t gpa) { return gpa >= A_LO && gpa < A_HI; }

/* ── main ────────────────────────────────────────────────────────── */
int main(int argc, char **argv)
{
    unsigned guest_gb   = DEFAULT_GUEST_GB;
    unsigned duration_s = DEFAULT_DURATION_S;
    unsigned settle_s   = DEFAULT_SETTLE_S;
    unsigned drain_ms   = DEFAULT_DRAIN_MS;
    unsigned rearm_ms   = DEFAULT_REARM_MS;
    int      lookahead  = DEFAULT_LOOKAHEAD;
    int      min_run    = DEFAULT_MIN_RUN;
    int      gap        = DEFAULT_GAP;
    unsigned window_us  = DEFAULT_WINDOW_US;

    for (int i = 1; i < argc; i++) {
        if      (strcmp(argv[i], "--guest-gb")  == 0 && i+1 < argc) guest_gb   = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--duration")  == 0 && i+1 < argc) duration_s = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--settle")    == 0 && i+1 < argc) settle_s   = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--drain-ms")  == 0 && i+1 < argc) drain_ms   = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--rearm-ms")  == 0 && i+1 < argc) rearm_ms   = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--lookahead") == 0 && i+1 < argc) lookahead  = atoi(argv[++i]);
        else if (strcmp(argv[i], "--min-run")   == 0 && i+1 < argc) min_run    = atoi(argv[++i]);
        else if (strcmp(argv[i], "--gap")       == 0 && i+1 < argc) gap        = atoi(argv[++i]);
        else if (strcmp(argv[i], "--window-us") == 0 && i+1 < argc) window_us  = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            fprintf(stderr,
                "Usage: %s [options]\n\n"
                "  --guest-gb <N>     Guest RAM in GB (default: %u)\n"
                "  --duration <sec>   Max wait time before giving up (default: %u)\n"
                "  --settle <sec>     Settle time at startup (default: %u)\n"
                "  --drain-ms <N>     Drain interval ms (default: %u)\n"
                "  --rearm-ms <N>     Dst re-arm interval ms (default: %u)\n"
                "  --lookahead <N>    Non-precursor entries scanned after a B hit (default: %d)\n"
                "  --min-run <N>      Min pages in run to qualify as image buf (default: %d)\n"
                "  --gap <N>          Max missing pages tolerated inside a run (default: %d)\n"
                "  --window-us <N>    Run must start within this many us of the B write (default: %u)\n",
                argv[0], DEFAULT_GUEST_GB, DEFAULT_DURATION_S, DEFAULT_SETTLE_S,
                DEFAULT_DRAIN_MS, DEFAULT_REARM_MS, DEFAULT_LOOKAHEAD, DEFAULT_MIN_RUN,
                DEFAULT_GAP, DEFAULT_WINDOW_US);
            return 0;
        }
    }

    uint64_t track_gfn_max = ((uint64_t)guest_gb << 30) >> 12;
    uint64_t window_ns     = (uint64_t)window_us * 1000ULL;

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = on_signal;
    sigaction(SIGINT,  &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    struct kvm_dst_fault_entry *dst_buf = malloc(sizeof(*dst_buf) * MAX_DRAIN_DST);
    if (!dst_buf) { fprintf(stderr, "[ERR] malloc\n"); return 1; }

    int fd = open("/dev/kvm", O_RDWR);
    if (fd < 0) { perror("[ERR] open /dev/kvm"); return 1; }

    fprintf(stderr,
        "[INFO] Write Pattern Tracker B -- region-B precursor + timing gate\n"
        "[INFO] Guest RAM  : %u GB  (GFN max 0x%llx)\n"
        "[INFO] Timeout    : %u s\n"
        "[INFO] Precursor  : region B [0x%llx,0x%llx)  (region A clock excluded)\n"
        "[INFO] Trigger    : run of >= %d x 4KB pages, starting <= %u us and <= %d writes after a B\n",
        guest_gb, (unsigned long long)track_gfn_max, duration_s,
        (unsigned long long)B_LO, (unsigned long long)B_HI,
        min_run, window_us, lookahead);

    ioctl(fd, KVM_DST_TRACK_DISABLE);

    struct kvm_dst_track_enable_param dp_en = {
        .start_gfn = 0,
        .nr_pages  = track_gfn_max,
    };
    if (ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en) < 0) {
        perror("[ERR] KVM_DST_TRACK_ENABLE");
        goto out_fail;
    }

    fprintf(stderr, "[INFO] DST_TRACK armed. Settling %u s...\n", settle_s);

    uint64_t start_ns   = now_ns();
    uint64_t settle_end = start_ns + (uint64_t)settle_s * 1000000000ULL;

    {
        struct timespec real_ts;
        clock_gettime(CLOCK_REALTIME, &real_ts);
        uint64_t real_ns = (uint64_t)real_ts.tv_sec * 1000000000ULL + (uint64_t)real_ts.tv_nsec;
        printf("CLOCK_REF  mono_ns=%llu  real_ns=%llu\n",
               (unsigned long long)start_ns, (unsigned long long)real_ns);
        fflush(stdout);
    }

    while (!g_stop && now_ns() < settle_end) {
        sleep_ms(drain_ms);
        struct kvm_dst_drain_param ddp = {
            .max_faults = MAX_DRAIN_DST, .nr_faults = 0,
            .faults_ptr = (uint64_t)(uintptr_t)dst_buf,
        };
        ioctl(fd, KVM_DST_TRACK_DRAIN, &ddp);
    }

    ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en);
    fprintf(stderr, "[INFO] Settle done. Scanning for image GPA...\n\n");

    uint64_t monitor_start = now_ns();
    uint64_t deadline      = monitor_start + (uint64_t)duration_s * 1000000000ULL;
    uint64_t last_rearm_ns = monitor_start;

    /*
     * Precursor state machine (maintained across drain cycles):
     *   look_active    : currently inside the lookahead window after a B hit
     *   look_remaining : write-count budget before the window expires
     *   look_run_base  : GPA of the first page in the current candidate run
     *   look_run_len   : pages in run (gaps within tolerance bridged in)
     *   look_prec_ns   : timestamp of the triggering B write (timing gate)
     */
    int      look_active    = 0;
    int      look_remaining = 0;
    uint64_t look_run_base  = 0;
    int      look_run_len   = 0;
    uint64_t look_prec_ns   = 0;

    unsigned long total_entries  = 0;
    unsigned long precursor_hits = 0;

    while (!g_stop && now_ns() < deadline) {
        sleep_ms(drain_ms);

        struct kvm_dst_drain_param ddp;
        do {
            ddp.max_faults = MAX_DRAIN_DST;
            ddp.nr_faults  = 0;
            ddp.faults_ptr = (uint64_t)(uintptr_t)dst_buf;
            if (ioctl(fd, KVM_DST_TRACK_DRAIN, &ddp) < 0) break;

            for (uint32_t i = 0; i < ddp.nr_faults; i++) {
                uint64_t gpa = dst_buf[i].fault_gpa;
                uint64_t ts  = dst_buf[i].timestamp_ns;
                total_entries++;

                if (in_B(gpa)) {
                    /* finalize any in-progress qualifying run */
                    if (look_active && look_run_len >= min_run) {
                        uint64_t al = look_run_base & ~(ALIGN_2MB - 1);
                        record_hit(al, look_run_base, look_run_len);
                    }
                    precursor_hits++;
                    look_active    = 1;
                    look_remaining = lookahead;
                    look_run_base  = 0;
                    look_run_len   = 0;
                    look_prec_ns   = ts;
                    continue;
                }

                if (!look_active)
                    continue;

                /* never build a run out of the control regions themselves */
                if (in_A(gpa))
                    continue;

                /* timing gate: the run must START promptly after the B write */
                if (look_run_len == 0 && (ts - look_prec_ns) > window_ns) {
                    look_active = 0;
                    continue;
                }

                /* ── extend / gap-bridge / restart run ── */
                if (look_run_len == 0) {
                    look_run_base = gpa;
                    look_run_len  = 1;
                } else {
                    uint64_t expected = look_run_base + (uint64_t)look_run_len * PAGE;
                    if (gpa == expected) {
                        look_run_len++;
                    } else if (gpa > expected) {
                        uint64_t gap_pages = (gpa - expected) / PAGE;
                        if (gap_pages <= (uint64_t)gap) {
                            look_run_len += (int)gap_pages + 1;
                        } else {
                            if (look_run_len >= min_run) {
                                uint64_t al = look_run_base & ~(ALIGN_2MB - 1);
                                record_hit(al, look_run_base, look_run_len);
                                look_active = 0;
                                continue;
                            }
                            look_run_base = gpa;
                            look_run_len  = 1;
                        }
                    } else {
                        if (look_run_len >= min_run) {
                            uint64_t al = look_run_base & ~(ALIGN_2MB - 1);
                            record_hit(al, look_run_base, look_run_len);
                            look_active = 0;
                            continue;
                        }
                        look_run_base = gpa;
                        look_run_len  = 1;
                    }
                }

                /* count lookahead only while run hasn't qualified yet */
                if (look_run_len < min_run && --look_remaining <= 0)
                    look_active = 0;
            }
        } while (ddp.nr_faults == MAX_DRAIN_DST);

        /* Periodic re-arm */
        uint64_t now = now_ns();
        if (now - last_rearm_ns >= (uint64_t)rearm_ms * 1000000ULL) {
            ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en);
            last_rearm_ns = now;
        }
    }

    if (g_stop)
        fprintf(stderr, "[STOPPED] Interrupted after %lu entries.\n", total_entries);
    else
        fprintf(stderr, "[DONE] Timeout after %u s (%lu entries, %lu B precursor hits).\n",
            duration_s, total_entries, precursor_hits);

    print_results(total_entries, precursor_hits);

    ioctl(fd, KVM_DST_TRACK_DISABLE);
    close(fd);
    free(dst_buf);
    return (g_n_candidates > 0) ? 0 : 1;

out_fail:
    ioctl(fd, KVM_DST_TRACK_DISABLE);
    close(fd);
    free(dst_buf);
    return 1;
}
