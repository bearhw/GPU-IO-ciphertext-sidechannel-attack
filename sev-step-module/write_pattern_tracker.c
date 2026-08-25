/*
 * write_pattern_tracker.c – Tensor GPA Finder via Write Pattern Analysis
 *
 * Tracks ALL guest memory writes (DST_TRACK) without any bounce buffer
 * dependency.  Identifies tensor pages by their write pattern:
 *
 *   - DataLoader writes new image data to tensor buffer every batch
 *   - This creates a burst of ~N consecutive page writes
 *   - The same pages are written at regular intervals (batch period)
 *
 * Unlike read tracking, write faults are rarely "consumed" by background
 * kernel activity because kernels mostly read user data, not write it.
 *
 * Usage:
 *   sudo ./write_pattern_tracker --guest-gb 256 --duration 60 > writes.log
 *   # (run training in guest)
 *   # Post-process: find pages with periodic write bursts
 *
 * Options:
 *   --guest-gb <N>       Guest RAM in GB (default: 256)
 *   --duration <sec>     Run time (default: 60)
 *   --settle <sec>       Settle time (default: 3)
 *   --drain-ms <N>       Drain interval (default: 2)
 *   --rearm-ms <N>       Dst re-arm interval (default: 20)
 *
 * Output:
 *   WRITE  gpa=0x<16hex>  ts=<ns>
 *
 * Post-process with: write_analyzer (finds periodic burst patterns)
 *
 * Build:
 *   make write_pattern_tracker
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

/* ── tunables ────────────────────────────────────────────────────── */
#define DEFAULT_GUEST_GB      256
#define DEFAULT_DURATION_S    60
#define DEFAULT_SETTLE_S      3
#define DEFAULT_DRAIN_MS      2
#define DEFAULT_REARM_MS      20

#define MAX_DRAIN_DST         8192

/* ── globals ───────────────────────────────────────────────��─────── */
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

/* ── main ────────────────────────────────────────────────────────── */
int main(int argc, char **argv)
{
    unsigned guest_gb   = DEFAULT_GUEST_GB;
    unsigned duration_s = DEFAULT_DURATION_S;
    unsigned settle_s   = DEFAULT_SETTLE_S;
    unsigned drain_ms   = DEFAULT_DRAIN_MS;
    unsigned rearm_ms   = DEFAULT_REARM_MS;
    uint64_t start_gpa  = 0;           /* 0 = start from beginning */
    uint64_t track_size = 0;           /* 0 = use guest_gb as limit */
    uint64_t start_gpa2 = 0;
    uint64_t track_size2 = 0;
    int      have_range2 = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--guest-gb") == 0 && i + 1 < argc)
            guest_gb = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--duration") == 0 && i + 1 < argc)
            duration_s = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--settle") == 0 && i + 1 < argc)
            settle_s = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--drain-ms") == 0 && i + 1 < argc)
            drain_ms = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--rearm-ms") == 0 && i + 1 < argc)
            rearm_ms = (unsigned)atoi(argv[++i]);
        else if (strcmp(argv[i], "--start-gpa") == 0 && i + 1 < argc)
            start_gpa = strtoull(argv[++i], NULL, 0);
        else if (strcmp(argv[i], "--track-size") == 0 && i + 1 < argc)
            track_size = strtoull(argv[++i], NULL, 0);
        else if (strcmp(argv[i], "--start-gpa2") == 0 && i + 1 < argc) {
            start_gpa2 = strtoull(argv[++i], NULL, 0);
            have_range2 = 1;
        }
        else if (strcmp(argv[i], "--track-size2") == 0 && i + 1 < argc)
            track_size2 = strtoull(argv[++i], NULL, 0);
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            fprintf(stderr,
                "Usage: %s [options]\n\n"
                "  --guest-gb <N>      Guest RAM in GB (default: %u)\n"
                "  --duration <sec>    Run time (default: %u)\n"
                "  --settle <sec>      Settle time (default: %u)\n"
                "  --drain-ms <N>      Drain interval (default: %u)\n"
                "  --rearm-ms <N>      Dst re-arm interval (default: %u)\n"
                "  --start-gpa <hex>   Start GPA for write tracking (default: 0x0)\n"
                "  --track-size <hex>  Byte range to track from start-gpa (default: guest_gb)\n"
                "  --start-gpa2 <hex>  Second range start GPA (e.g. Region B)\n"
                "  --track-size2 <hex> Second range size (default: 0x10000000)\n",
                argv[0], DEFAULT_GUEST_GB, DEFAULT_DURATION_S,
                DEFAULT_SETTLE_S, DEFAULT_DRAIN_MS, DEFAULT_REARM_MS);
            return 0;
        }
    }

    uint64_t track_start_gfn = start_gpa >> 12;
    uint64_t track_gfn_max   = track_size ? (track_size >> 12)
                                           : (((uint64_t)guest_gb << 30) >> 12);
    uint64_t track_start_gfn2 = start_gpa2 >> 12;
    uint64_t track_gfn_max2   = track_size2 ? (track_size2 >> 12)
                                             : (0x10000000ULL >> 12);  /* default 256MB */

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = on_signal;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    struct kvm_dst_fault_entry *dst_buf = malloc(sizeof(*dst_buf) * MAX_DRAIN_DST);
    if (!dst_buf) { fprintf(stderr, "[ERR] malloc\n"); return 1; }

    int fd = open("/dev/kvm", O_RDWR);
    if (fd < 0) { perror("[ERR] open /dev/kvm"); return 1; }

    fprintf(stderr,
        "[INFO] Write Pattern Tracker\n"
        "[INFO] Guest RAM  : %u GB\n"
        "[INFO] Range 1    : GFN 0x%llx + 0x%llx pages (0x%llx – 0x%llx)\n"
        "[INFO] Duration   : %u s\n"
        "[INFO] Drain      : %u ms\n"
        "[INFO] Dst re-arm : %u ms\n",
        guest_gb,
        (unsigned long long)track_start_gfn,
        (unsigned long long)track_gfn_max,
        (unsigned long long)(track_start_gfn << 12),
        (unsigned long long)((track_start_gfn + track_gfn_max) << 12),
        duration_s, drain_ms, rearm_ms);

    if (have_range2)
        fprintf(stderr,
            "[INFO] Range 2    : GFN 0x%llx + 0x%llx pages (0x%llx – 0x%llx)\n",
            (unsigned long long)track_start_gfn2,
            (unsigned long long)track_gfn_max2,
            (unsigned long long)(track_start_gfn2 << 12),
            (unsigned long long)((track_start_gfn2 + track_gfn_max2) << 12));

    /* Cleanup */
    ioctl(fd, KVM_DST_TRACK_DISABLE);

    struct kvm_dst_track_enable_param dp_en = {
        .start_gfn = track_start_gfn,
        .nr_pages  = track_gfn_max
    };
    if (ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en) < 0) {
        perror("[ERR] KVM_DST_TRACK_ENABLE (range 1)");
        goto out;
    }

    struct kvm_dst_track_enable_param dp_en2 = { 0 };
    if (have_range2) {
        dp_en2.start_gfn = track_start_gfn2;
        dp_en2.nr_pages  = track_gfn_max2;
        if (ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en2) < 0) {
            perror("[ERR] KVM_DST_TRACK_ENABLE (range 2)");
            goto out;
        }
    }

    fprintf(stderr, "[INFO] DST_TRACK armed. Settling %u s...\n", settle_s);

    /* Settle: drain and discard */
    uint64_t start_ns   = now_ns();
    uint64_t settle_end = start_ns + (uint64_t)settle_s * 1000000000ULL;

    /* Reference pair for converting fault ts (CLOCK_MONOTONIC, same domain
     * as kernel ktime_get_ns()) to wall-clock ns, so guest-side
     * CLOCK_REALTIME timestamps can be compared against host fault ts:
     *   real_ns_of_fault = fault.ts + (real_ns - mono_ns) */
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
        struct kvm_dst_drain_param ddp;
        ddp.max_faults = MAX_DRAIN_DST; ddp.nr_faults = 0;
        ddp.faults_ptr = (uint64_t)(uintptr_t)dst_buf;
        ioctl(fd, KVM_DST_TRACK_DRAIN, &ddp);
    }

    /* Re-arm after settle */
    ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en);
    if (have_range2)
        ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en2);

    fprintf(stderr, "[INFO] Settle done. Monitoring writes...\n\n");

    /* ── main loop ───────────────────────────────────────────────── */
    uint64_t deadline      = start_ns + (uint64_t)duration_s * 1000000000ULL;
    uint64_t last_rearm_ns = now_ns();
    unsigned long total_writes = 0;

    while (!g_stop && now_ns() < deadline) {
        sleep_ms(drain_ms);

        /* Drain write faults */
        struct kvm_dst_drain_param ddp;
        do {
            ddp.max_faults = MAX_DRAIN_DST; ddp.nr_faults = 0;
            ddp.faults_ptr = (uint64_t)(uintptr_t)dst_buf;
            if (ioctl(fd, KVM_DST_TRACK_DRAIN, &ddp) < 0) break;

            for (uint32_t i = 0; i < ddp.nr_faults; i++) {
                printf("WRITE  gpa=0x%016llx  ts=%llu\n",
                       (unsigned long long)dst_buf[i].fault_gpa,
                       (unsigned long long)dst_buf[i].timestamp_ns);
                total_writes++;
            }
            if (ddp.nr_faults > 0) fflush(stdout);
        } while (ddp.nr_faults == MAX_DRAIN_DST);

        /* Periodic re-arm */
        uint64_t now = now_ns();
        if (now - last_rearm_ns >= (uint64_t)rearm_ms * 1000000ULL) {
            ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en);
            if (have_range2)
                ioctl(fd, KVM_DST_TRACK_ENABLE, &dp_en2);
            last_rearm_ns = now;
        }
    }

    fprintf(stderr, "\n[INFO] Done. Total writes: %lu\n", total_writes);

out:
    ioctl(fd, KVM_DST_TRACK_DISABLE);
    close(fd);
    free(dst_buf);
    fprintf(stderr, "[INFO] DST_TRACK disabled.\n");
    return 0;
}
