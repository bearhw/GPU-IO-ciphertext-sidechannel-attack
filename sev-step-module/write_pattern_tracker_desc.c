/*
 * write_pattern_tracker_desc.c – Image GPA finder via descending run detection
 *
 * CUDA tensor memory (cudaHostAlloc) is stored in DESCENDING GPA order.
 * memcpy writes pages from logical offset 0 upward, which maps to
 * physically decreasing GPAs:  page[N+1] = page[N] - 0x1000.
 *
 * OS/kernel noise is predominantly ascending (allocators go low→high).
 * Descending contiguous runs therefore act as a highly selective filter
 * for tensor (image) pages — no external precursor signal needed.
 *
 * Algorithm:
 *   For every write fault, maintain a running descending-run detector:
 *     if (gpa == prev_gpa - 0x1000)  → extend current run
 *     elif (gap_count < max_gap)     → tolerate interleaved noise write
 *     else                           → finalize run, start new one
 *   Runs >= min_run pages are accumulated per 2MB region.
 *   Regions scored by  run_count × max_run_length.
 *   Top-N regions = image tensor candidates.
 *
 * Validated offline on MURA DenseNet-169 traces (runs 1-4):
 *   desc runs >= 30:  avg Precision = 0.81,  avg F1 = 0.50
 *   2MB expand (top regions with max_run >= 50): zero noise regions selected
 *
 * On exit:
 *   stderr : ranked table of top candidates
 *   stdout : "IMAGE_REGION_<n>=0x<2MB-aligned>" (machine-readable)
 *   exit 0 if >= 1 candidate, exit 1 otherwise
 *
 * Build:  make write_pattern_tracker_desc
 * Run:    sudo ./write_pattern_tracker_desc [--duration 120] [--min-run 30]
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

/* ── candidate tracking ─────────────────────────────────────────── */
#define MAX_CANDIDATES 512
#define TOP_N          10

typedef struct {
    uint64_t aligned_gpa;       /* 2MB-aligned region base */
    uint64_t best_run_high_gpa; /* highest GPA of the longest run */
    unsigned hit_count;         /* number of desc runs in this region */
    int      max_run_len;       /* longest desc run in this region */
} candidate_t;

static candidate_t g_candidates[MAX_CANDIDATES];
static int         g_n_candidates = 0;

static void record_hit(uint64_t aligned_gpa, uint64_t run_high, int run_len)
{
    for (int i = 0; i < g_n_candidates; i++) {
        if (g_candidates[i].aligned_gpa == aligned_gpa) {
            g_candidates[i].hit_count++;
            if (run_len > g_candidates[i].max_run_len) {
                g_candidates[i].max_run_len    = run_len;
                g_candidates[i].best_run_high_gpa = run_high;
            }
            return;
        }
    }
    if (g_n_candidates < MAX_CANDIDATES) {
        g_candidates[g_n_candidates++] = (candidate_t){
            .aligned_gpa       = aligned_gpa,
            .best_run_high_gpa = run_high,
            .hit_count         = 1,
            .max_run_len       = run_len,
        };
    }
}

static int cmp_candidates(const void *a, const void *b)
{
    const candidate_t *ca = a, *cb = b;
    unsigned sa = ca->hit_count * (unsigned)ca->max_run_len;
    unsigned sb = cb->hit_count * (unsigned)cb->max_run_len;
    if (sb != sa) return (sb > sa) ? 1 : -1;
    return (cb->max_run_len > ca->max_run_len) ? 1 : -1;
}

static void finalize_run(uint64_t run_high_gpa, int run_len, int min_run)
{
    if (run_len < min_run)
        return;
    uint64_t run_low  = run_high_gpa - (uint64_t)(run_len - 1) * 0x1000ULL;
    uint64_t aligned  = run_low & ~(0x200000ULL - 1);
    record_hit(aligned, run_high_gpa, run_len);
}

static void print_results(unsigned long total_entries, unsigned long total_desc_runs)
{
    if (g_n_candidates == 0) {
        fprintf(stderr, "[RESULT] No candidates found.\n");
        return;
    }

    qsort(g_candidates, g_n_candidates, sizeof(candidate_t), cmp_candidates);

    int top = g_n_candidates < TOP_N ? g_n_candidates : TOP_N;

    fprintf(stderr,
        "================================================================\n"
        "  TOP %d IMAGE REGION CANDIDATES  (descending-run detector)\n"
        "  total_writes=%lu  desc_runs_found=%lu  unique_regions=%d\n"
        "================================================================\n"
        "  Rank  2MB Region              Run-high GPA            runs  max_run  score\n"
        "  ----  ----------------------  ----------------------  ----  -------  -----\n",
        top, total_entries, total_desc_runs, g_n_candidates);

    for (int i = 0; i < top; i++) {
        unsigned score = g_candidates[i].hit_count * (unsigned)g_candidates[i].max_run_len;
        fprintf(stderr, "  #%-2d   0x%016llx  0x%016llx  %4u    %5d  %5u\n",
            i + 1,
            (unsigned long long)g_candidates[i].aligned_gpa,
            (unsigned long long)g_candidates[i].best_run_high_gpa,
            g_candidates[i].hit_count,
            g_candidates[i].max_run_len,
            score);
    }
    fprintf(stderr, "================================================================\n\n");

    for (int i = 0; i < top; i++) {
        printf("IMAGE_REGION_%d=0x%016llx  RANGE=[0x%016llx, 0x%016llx)\n",
               i + 1,
               (unsigned long long)g_candidates[i].aligned_gpa,
               (unsigned long long)g_candidates[i].aligned_gpa,
               (unsigned long long)(g_candidates[i].aligned_gpa + 0x200000ULL));
    }
    fflush(stdout);
}

/* GPU BAR / MMIO regions — never tensor pages, skip in run detection */
#define SKIP_LO               0x3f00000000ULL
#define SKIP_HI               0x4000000000ULL

/* ── tunables ───────────────────────────────────────────────────── */
#define DEFAULT_GUEST_GB      256
#define DEFAULT_DURATION_S    120
#define DEFAULT_SETTLE_S      3
#define DEFAULT_DRAIN_MS      2
#define DEFAULT_REARM_MS      20
#define DEFAULT_MIN_RUN       30
#define DEFAULT_MAX_GAP       3

#define MAX_DRAIN_DST         8192
#define PAGE                  0x1000ULL

/* ── globals ────────────────────────────────────────────────────── */
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

/* ── main ───────────────────────────────────────────────────────── */
int main(int argc, char **argv)
{
    unsigned guest_gb   = DEFAULT_GUEST_GB;
    unsigned duration_s = DEFAULT_DURATION_S;
    unsigned settle_s   = DEFAULT_SETTLE_S;
    unsigned drain_ms   = DEFAULT_DRAIN_MS;
    unsigned rearm_ms   = DEFAULT_REARM_MS;
    int      min_run    = DEFAULT_MIN_RUN;
    int      max_gap    = DEFAULT_MAX_GAP;
    uint64_t start_gpa  = 0;
    uint64_t track_size = 0;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--guest-gb")   && i+1 < argc) guest_gb   = (unsigned)atoi(argv[++i]);
        else if (!strcmp(argv[i], "--duration")   && i+1 < argc) duration_s = (unsigned)atoi(argv[++i]);
        else if (!strcmp(argv[i], "--settle")     && i+1 < argc) settle_s   = (unsigned)atoi(argv[++i]);
        else if (!strcmp(argv[i], "--drain-ms")   && i+1 < argc) drain_ms   = (unsigned)atoi(argv[++i]);
        else if (!strcmp(argv[i], "--rearm-ms")   && i+1 < argc) rearm_ms   = (unsigned)atoi(argv[++i]);
        else if (!strcmp(argv[i], "--min-run")    && i+1 < argc) min_run    = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--max-gap")    && i+1 < argc) max_gap    = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--start-gpa")  && i+1 < argc) start_gpa  = strtoull(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--track-size") && i+1 < argc) track_size = strtoull(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
            fprintf(stderr,
                "Usage: %s [options]\n\n"
                "  --guest-gb <N>      Guest RAM in GB (default: %u)\n"
                "  --duration <sec>    Tracking duration (default: %u)\n"
                "  --settle <sec>      Settle time (default: %u)\n"
                "  --drain-ms <N>      Drain interval (default: %u)\n"
                "  --rearm-ms <N>      Write-protect re-arm interval (default: %u)\n"
                "  --min-run <N>       Min descending run length (default: %d)\n"
                "  --max-gap <N>       Max interleaved noise writes tolerated (default: %d)\n"
                "  --start-gpa <hex>   Start GPA (default: 0x0)\n"
                "  --track-size <hex>  Byte range to track (default: guest_gb)\n",
                argv[0], DEFAULT_GUEST_GB, DEFAULT_DURATION_S,
                DEFAULT_SETTLE_S, DEFAULT_DRAIN_MS, DEFAULT_REARM_MS,
                DEFAULT_MIN_RUN, DEFAULT_MAX_GAP);
            return 0;
        }
    }

    uint64_t track_start_gfn = start_gpa >> 12;
    uint64_t track_gfn_count = track_size ? (track_size >> 12)
                                          : (((uint64_t)guest_gb << 30) >> 12);

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
        "[INFO] Descending-Run Image Detector\n"
        "[INFO] Guest RAM  : %u GB\n"
        "[INFO] Range      : GPA [0x%llx, 0x%llx)\n"
        "[INFO] Duration   : %u s\n"
        "[INFO] Min run    : %d pages\n"
        "[INFO] Max gap    : %d interleaved writes\n"
        "[INFO] Re-arm     : %u ms\n",
        guest_gb,
        (unsigned long long)(track_start_gfn << 12),
        (unsigned long long)((track_start_gfn + track_gfn_count) << 12),
        duration_s, min_run, max_gap, rearm_ms);

    ioctl(fd, KVM_DST_TRACK_DISABLE);

    struct kvm_dst_track_enable_param dp_en = {
        .start_gfn = track_start_gfn,
        .nr_pages  = track_gfn_count,
    };
    if (ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en) < 0) {
        perror("[ERR] KVM_DST_TRACK_ENABLE");
        goto out_fail;
    }

    fprintf(stderr, "[INFO] DST_TRACK armed. Settling %u s...\n", settle_s);

    uint64_t start_ns   = now_ns();
    uint64_t settle_end = start_ns + (uint64_t)settle_s * 1000000000ULL;

    while (!g_stop && now_ns() < settle_end) {
        sleep_ms(drain_ms);
        struct kvm_dst_drain_param ddp = {
            .max_faults = MAX_DRAIN_DST, .nr_faults = 0,
            .faults_ptr = (uint64_t)(uintptr_t)dst_buf,
        };
        ioctl(fd, KVM_DST_TRACK_DRAIN, &ddp);
    }

    ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en);
    fprintf(stderr, "[INFO] Settle done. Scanning for descending runs...\n\n");

    uint64_t deadline      = now_ns() + (uint64_t)duration_s * 1000000000ULL;
    uint64_t last_rearm_ns = now_ns();

    /*
     * Descending-run state machine (persists across drain cycles):
     *   run_high_gpa   : first (highest) GPA of current descending run
     *   run_expect_gpa : next expected GPA (= last matched page - PAGE)
     *   run_len        : matched pages so far
     *   gap_remaining  : non-matching writes left before run breaks
     */
    uint64_t run_high_gpa   = 0;
    uint64_t run_expect_gpa = 0;
    int      run_len        = 0;
    int      gap_remaining  = 0;

    unsigned long total_writes    = 0;
    unsigned long total_desc_runs = 0;

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
                total_writes++;

                if (gpa >= SKIP_LO && gpa < SKIP_HI)
                    continue;

                if (run_len > 0 && gpa == run_expect_gpa) {
                    /* extend descending run */
                    run_expect_gpa = gpa - PAGE;
                    run_len++;
                    gap_remaining = max_gap;
                } else if (run_len > 0 && gap_remaining > 0) {
                    /* tolerate interleaved noise */
                    gap_remaining--;
                } else {
                    /* finalize previous run */
                    if (run_len >= min_run) {
                        finalize_run(run_high_gpa, run_len, min_run);
                        total_desc_runs++;
                    }
                    /* start new potential run */
                    run_high_gpa   = gpa;
                    run_expect_gpa = gpa - PAGE;
                    run_len        = 1;
                    gap_remaining  = max_gap;
                }
            }
        } while (ddp.nr_faults == MAX_DRAIN_DST);

        /* periodic re-arm */
        uint64_t now = now_ns();
        if (now - last_rearm_ns >= (uint64_t)rearm_ms * 1000000ULL) {
            ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en);
            last_rearm_ns = now;
        }
    }

    /* finalize last run */
    if (run_len >= min_run) {
        finalize_run(run_high_gpa, run_len, min_run);
        total_desc_runs++;
    }

    if (g_stop)
        fprintf(stderr, "[STOPPED] Interrupted after %lu writes.\n", total_writes);
    else
        fprintf(stderr, "[DONE] %u s elapsed. %lu writes, %lu desc runs found.\n",
            duration_s, total_writes, total_desc_runs);

    print_results(total_writes, total_desc_runs);

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
