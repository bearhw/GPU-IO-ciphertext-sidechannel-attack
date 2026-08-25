/*
 * swap_pages_tool.c
 *
 * Moves the data of one guest page (src GPA) so it is accessible at a
 * different guest page (dst GPA) inside a running SEV-SNP VM.
 *
 * How it works
 * ------------
 * KVM_SWAP_GUEST_PAGES queues the swap in the kernel
 * (global_sev_step_config.is_swap_pages = true) and then kicks vcpu0 to
 * force QEMU's running KVM_RUN to exit the guest.  When QEMU re-enters
 * KVM_RUN, svm_vcpu_run() detects the pending swap and executes it under
 * the correct (QEMU) process context — no VMRUN from this tool required.
 *
 * This tool polls KVM_USP_SWAP_STATUS until the kernel reports that
 * svm_vcpu_run() has finished the swap (swap_done = true).
 *
 * Usage
 * -----
 *   sudo ./swap_pages_tool <src_gpa_hex> <dst_gpa_hex> [--swap-back] [--nr-times N]
 *
 * Build
 * -----
 *   gcc -DENABLE_OLD_SWAP_PAGES_SUPPORT -Wall -O2 -o swap_pages_tool swap_pages_tool.c
 */

#ifndef ENABLE_OLD_SWAP_PAGES_SUPPORT
#define ENABLE_OLD_SWAP_PAGES_SUPPORT
#endif

#include <errno.h>
#include <fcntl.h>
#include <linux/kvm.h>
#include <linux/sev-step/sev-step.h>
#include <sched.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

/* KVM_USP_SWAP_STATUS: poll /dev/kvm until done != 0.
 * Defined here in case the installed system header predates this addition. */
#ifndef KVM_USP_SWAP_STATUS
#define KVM_USP_SWAP_STATUS  _IOR(KVMIO, 0x2a, uint32_t)
#endif

#define POLL_TIMEOUT_SEC 30   /* wall-clock timeout for the swap to complete */

/* ------------------------------------------------------------------ */
/* Usage                                                                */
/* ------------------------------------------------------------------ */
static void usage(const char *prog)
{
	fprintf(stderr,
		"Usage: %s <src_gpa_hex> <dst_gpa_hex> [--swap-back] [--nr-times N]\n"
		"\n"
		"  src_gpa_hex  Guest physical address of the source page\n"
		"  dst_gpa_hex  Guest physical address of the destination page\n"
		"  --swap-back  Also swap back (round-trip). Default: one-way move\n"
		"  --nr-times N Number of swap iterations (default: 1)\n",
		prog);
}

/* ------------------------------------------------------------------ */
/* main                                                                 */
/* ------------------------------------------------------------------ */
int main(int argc, char *argv[])
{
	if (argc < 3) { usage(argv[0]); return 1; }

	uint64_t gpa1     = strtoull(argv[1], NULL, 0);
	uint64_t gpa2     = strtoull(argv[2], NULL, 0);
	bool is_swap_back = false;
	int  nr_times     = 1;

	for (int i = 3; i < argc; i++) {
		if (strcmp(argv[i], "--swap-back") == 0) {
			is_swap_back = true;
		} else if (strcmp(argv[i], "--nr-times") == 0 && i + 1 < argc) {
			nr_times = atoi(argv[++i]);
		} else {
			fprintf(stderr, "Unknown option: %s\n", argv[i]);
			usage(argv[0]);
			return 1;
		}
	}

	printf("src_gpa=0x%lx (gfn=0x%lx), dst_gpa=0x%lx (gfn=0x%lx)\n",
	       gpa1, gpa1 >> 12, gpa2, gpa2 >> 12);
	printf("is_swap_back=%d, nr_times=%d\n", is_swap_back, nr_times);

	/* --- Open /dev/kvm ----------------------------------------------- */
	int kvm_fd = open("/dev/kvm", O_RDWR | O_CLOEXEC);
	if (kvm_fd < 0) { perror("open /dev/kvm"); return 1; }

	/* --- [1/2] Queue the swap --------------------------------------- */
	struct kvm_swap_pages_param_t param = {
		.gfn1                    = gpa1 >> 12,
		.gfn2                    = gpa2 >> 12,
		.is_swap_back            = is_swap_back,
		.nr_swap_times           = nr_times,
		.nr_gfn1_new_assignments = 0,
		.nr_gfn2_new_assignments = 0,
	};
	printf("[1/2] Queuing KVM_SWAP_GUEST_PAGES (gfn1=0x%lx gfn2=0x%lx)...\n",
	       param.gfn1, param.gfn2);
	if (ioctl(kvm_fd, KVM_SWAP_GUEST_PAGES, &param) < 0) {
		perror("KVM_SWAP_GUEST_PAGES");
		close(kvm_fd);
		return 1;
	}
	printf("[1/2] Swap queued; vcpu0 kicked — waiting for svm_vcpu_run() to execute it...\n");

	/* --- [2/2] Poll KVM_USP_SWAP_STATUS until the swap completes ---- */
	printf("[2/2] Polling KVM_USP_SWAP_STATUS (timeout %ds)...\n",
	       POLL_TIMEOUT_SEC);
	{
		struct timespec t_start, t_now;
		long iter = 0;

		clock_gettime(CLOCK_MONOTONIC, &t_start);

		for (;;) {
			uint32_t done = 0;

			if (ioctl(kvm_fd, KVM_USP_SWAP_STATUS, &done) < 0) {
				perror("KVM_USP_SWAP_STATUS");
				close(kvm_fd);
				return 1;
			}
			if (done) {
				if (done != 1) {
					fprintf(stderr,
						"[2/2] Swap FAILED after %ld poll iterations"
						" — kernel returned error.\n"
						"      Check dmesg for details.\n",
						iter + 1);
					close(kvm_fd);
					return 1;
				}
				printf("[2/2] Swap complete after %ld poll iterations.\n",
				       iter + 1);
				break;
			}

			/* Check elapsed time every 1000 iterations. */
			if (++iter % 1000 == 0) {
				clock_gettime(CLOCK_MONOTONIC, &t_now);
				if (t_now.tv_sec - t_start.tv_sec >= POLL_TIMEOUT_SEC) {
					fprintf(stderr,
						"[2/2] Timed out after %ds (%ld iters)"
						" — swap did not complete.\n"
						"      Check dmesg for kernel errors.\n",
						POLL_TIMEOUT_SEC, iter);
					close(kvm_fd);
					return 1;
				}
			}

			/* Yield the CPU so the kernel/QEMU can make progress. */
			sched_yield();
		}
	}

	printf("Page swap complete — check dmesg for kernel details.\n");
	close(kvm_fd);
	return 0;
}
