// SPDX-License-Identifier: GPL-2.0
/*
 * jit_npt_trap.c – Two-Phase Just-In-Time NPT Trapping
 *
 * See include/linux/sev-step/jit_npt_trap.h for the full design description.
 *
 * File layout
 * ===========
 *  1. State machine context & helpers
 *  2. jit_npt_handle_fault()  – hot path, called from mmu.c
 *  3. jit_npt_arm()           – arms the trap via sysfs
 *  4. jit_npt_disarm()        – manual disarm via sysfs
 *  5. Sysfs interface         – /sys/kernel/jit_npt_trap/{arm,disarm,state}
 *  6. Module init / exit
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/string.h>
#include <linux/atomic.h>
#include <linux/spinlock.h>
#include <linux/kvm_host.h>
#include <asm/kvm_host.h>

#include <linux/sev-step/sev-step.h>
#include <linux/sev-step/jit_npt_trap.h>

/* forward declaration – defined in arch/x86/kvm/mmu/mmu.c */
void kvm_zap_gfn_range(struct kvm *kvm, gfn_t gfn_start, gfn_t gfn_end);

/* ── x86 page-fault error-code bits ───────────────────────────── */
#ifndef PFERR_PRESENT_MASK
#define PFERR_PRESENT_MASK  (1ULL << 0)
#endif
#ifndef PFERR_WRITE_MASK
#define PFERR_WRITE_MASK    (1ULL << 1)
#endif

/* ══════════════════════════════════════════════════════════════════
 * 1.  Global state
 * ══════════════════════════════════════════════════════════════════ */

struct jit_npt_ctx jit_npt = {
	.state = ATOMIC_INIT(JIT_NPT_DISARMED),
};
EXPORT_SYMBOL(jit_npt);

static const char * const state_names[] = {
	[JIT_NPT_DISARMED]   = "DISARMED",
	[JIT_NPT_IDLE]       = "IDLE (armed, bounce GFN unmapped)",
	[JIT_NPT_SWEEP_DONE] = "SWEEP_DONE (heap zapped, awaiting target read)",
};

/* ══════════════════════════════════════════════════════════════════
 * 2.  Hot path – called from kvm_mmu_page_fault() in mmu.c
 * ══════════════════════════════════════════════════════════════════ */

/*
 * jit_npt_handle_fault() runs on every KVM NPF/EPT violation, BEFORE any
 * KVM MMU lock is acquired.
 *
 * Return value:
 *   0  – caller should continue with normal fault handling
 *   1  – fault fully handled; caller should return 1 (resume guest)
 *
 * Locking strategy
 * ────────────────
 * The atomic_read(state) fast path requires no lock.  State transitions
 * are serialised by jit_npt.lock (a plain spinlock, never nested with
 * kvm->mmu_lock).  kvm_zap_gfn_range() acquires kvm->mmu_lock internally,
 * so it is called AFTER jit_npt.lock is released.
 */
int jit_npt_handle_fault(struct kvm_vcpu *vcpu, gpa_t gpa, u64 error_code)
{
	enum jit_npt_state cur;
	bool is_write  = !!(error_code & PFERR_WRITE_MASK);
	gfn_t fault_gfn = gpa >> PAGE_SHIFT;
	struct kvm *kvm = vcpu->kvm;

	/* ── fast exit when disarmed (zero overhead) ─────────────── */
	cur = (enum jit_npt_state)atomic_read(&jit_npt.state);
	if (cur == JIT_NPT_DISARMED)
		return 0;

	/* ── Phase 2 → 3: access fault on the bounce buffer ────────
	 *
	 * H2D direction: write fault (CPU writes to bounce from src_plain)
	 * D2H direction: read fault  (CPU reads from bounce into dst_plain)
	 *
	 * Action:
	 *   a) Transition state to SWEEP_DONE
	 *   b) Zap [sweep_start_gfn, sweep_end_gfn) – the guest memory
	 *      region that contains the target buffer
	 *   c) Return 0 so the normal KVM fault handler maps the bounce
	 *      buffer (P=1) and resumes the guest vCPU
	 */
	if (cur == JIT_NPT_IDLE &&
	    fault_gfn == jit_npt.bounce_gfn) {

		bool do_sweep = false;

		spin_lock(&jit_npt.lock);
		/* Re-check under lock to avoid a TOCTOU race */
		if (atomic_read(&jit_npt.state) == JIT_NPT_IDLE) {
			atomic_set(&jit_npt.state, JIT_NPT_SWEEP_DONE);
			do_sweep = true;
		}
		spin_unlock(&jit_npt.lock);

		if (do_sweep) {
			pr_info("jit_npt: Phase 2 – write fault on bounce GFN 0x%llx "
				"(GPA 0x%llx), sweeping GFN range [0x%llx, 0x%llx)\n",
				jit_npt.bounce_gfn,
				(u64)gpa,
				jit_npt.sweep_start_gfn,
				jit_npt.sweep_end_gfn);

			/*
			 * kvm_zap_gfn_range() acquires kvm->mmu_lock (write),
			 * zaps all leaf SPTEs for the range in both the shadow
			 * and TDP MMU paths, then flushes remote TLBs.
			 * After this call every access to [sweep_start, sweep_end)
			 * will trap as a not-present NPF until re-mapped.
			 */
			kvm_zap_gfn_range(kvm,
					   jit_npt.sweep_start_gfn,
					   jit_npt.sweep_end_gfn);

			pr_info("jit_npt: Phase 3 – heap sweep done. "
				"Handing bounce fault back to normal handler.\n");
		}

		/*
		 * Return 0: let the normal KVM fault handler map the bounce
		 * buffer at the standard HPA and resume the vCPU.
		 */
		return 0;
	}

	/* ── Phase 4: write fault in the swept region ──────────────
	 *
	 * D2H: memcpy(dst_plain, bounce, 4096)
	 *   After the bounce READ is handled, the CPU stores to dst_plain.
	 *   Page table walks and instruction fetches are all READs and are
	 *   skipped.  The first WRITE is the store to dst_plain.
	 *
	 * H2D: also works — the first WRITE after sweep is to the target.
	 *
	 * Action:
	 *   a) Log the target GPA
	 *   b) Reset to DISARMED
	 *   c) Return 0 so the normal handler maps the target page
	 */
	if (cur == JIT_NPT_SWEEP_DONE &&
	    fault_gfn >= jit_npt.sweep_start_gfn &&
	    fault_gfn <  jit_npt.sweep_end_gfn   &&
	    is_write) {

		bool do_log = false;

		spin_lock(&jit_npt.lock);
		if (atomic_read(&jit_npt.state) == JIT_NPT_SWEEP_DONE) {
			jit_npt.target_gpa = gpa;
			atomic_set(&jit_npt.state, JIT_NPT_DISARMED);
			do_log = true;
		}
		spin_unlock(&jit_npt.lock);

		if (do_log) {
			/*
			 * This is the primary research output.
			 * Print at KERN_ALERT so it is not lost even with a
			 * high dmesg log level.
			 */
			pr_alert("jit_npt: *** TARGET ACQUIRED ***\n");
			pr_alert("jit_npt: target_input GPA = 0x%llx  "
				 "(GFN 0x%llx)  vCPU %u\n",
				 (u64)gpa, fault_gfn, vcpu->vcpu_id);

			/*
			 * Cleanup note:
			 * Resetting to DISARMED is sufficient to stop the
			 * interception loop.  The N-1 remaining swept pages
			 * re-map through normal KVM demand-paging — one NPF
			 * per page, handled at full speed.  For tight sweep
			 * ranges (< 256 pages) this causes negligible overhead.
			 *
			 * If a wider sweep was used and a true zero-overhead
			 * recovery is needed, call:
			 *   kvm_mmu_zap_all(kvm);  // zaps everything, expensive
			 * or proactively re-map by calling kvm_zap_gfn_range()
			 * followed by a kvm_mmu_page_fault() for each GFN
			 * (not provided by the KVM API; out of scope here).
			 */
		}

		/* Fall through to normal handler to map the target page */
		return 0;
	}

	return 0;
}
EXPORT_SYMBOL(jit_npt_handle_fault);

/* ══════════════════════════════════════════════════════════════════
 * 3.  Arming
 * ══════════════════════════════════════════════════════════════════ */

/*
 * jit_npt_arm() – arm the trap for a new bounce buffer / sweep range.
 *
 * Called from the sysfs "arm" store handler.  Must be called while the
 * guest VM is paused or at least not in the critical memcpy window.
 *
 * bounce_gpa       : guest physical address of the SWIOTLB bounce buffer
 * sweep_start_gfn  : first GFN of the guest heap region to zap in Phase 3
 * sweep_end_gfn    : first GFN *past* the end of the sweep region
 */
static int jit_npt_arm(gpa_t bounce_gpa,
		       gfn_t sweep_start_gfn,
		       gfn_t sweep_end_gfn)
{
	struct kvm *kvm;
	gfn_t bounce_gfn = bounce_gpa >> PAGE_SHIFT;

	if (sweep_end_gfn <= sweep_start_gfn) {
		pr_err("jit_npt: arm: sweep range is empty "
		       "(start=0x%llx end=0x%llx)\n",
		       sweep_start_gfn, sweep_end_gfn);
		return -EINVAL;
	}

	kvm = global_sev_step_config.main_vm;
	if (!kvm) {
		pr_err("jit_npt: arm: main_vm == NULL – start the VM first\n");
		return -ENXIO;
	}

	/* Store configuration under the lock */
	spin_lock(&jit_npt.lock);
	atomic_set(&jit_npt.state, JIT_NPT_DISARMED); /* ensure clean start */
	jit_npt.bounce_gfn       = bounce_gfn;
	jit_npt.sweep_start_gfn  = sweep_start_gfn;
	jit_npt.sweep_end_gfn    = sweep_end_gfn;
	jit_npt.target_gpa       = 0;
	spin_unlock(&jit_npt.lock);

	/*
	 * Phase 1: unmap the bounce buffer page so the very first write to
	 * it (from memcpy) triggers an NPF.
	 *
	 * kvm_zap_gfn_range() is safe to call outside of the fault path
	 * (acquires kvm->mmu_lock internally).
	 */
	kvm_zap_gfn_range(kvm, bounce_gfn, bounce_gfn + 1);

	/* Now officially armed */
	atomic_set(&jit_npt.state, JIT_NPT_IDLE);

	pr_info("jit_npt: ARMED  bounce_gpa=0x%llx (GFN 0x%llx) "
		"sweep=[0x%llx, 0x%llx)  (%llu pages)\n",
		(u64)bounce_gpa, bounce_gfn,
		sweep_start_gfn, sweep_end_gfn,
		sweep_end_gfn - sweep_start_gfn);

	return 0;
}

/* ══════════════════════════════════════════════════════════════════
 * 4.  Manual disarm
 * ══════════════════════════════════════════════════════════════════ */

static void jit_npt_disarm(void)
{
	spin_lock(&jit_npt.lock);
	atomic_set(&jit_npt.state, JIT_NPT_DISARMED);
	spin_unlock(&jit_npt.lock);
	pr_info("jit_npt: DISARMED by user request\n");
}

/* ══════════════════════════════════════════════════════════════════
 * 5.  Sysfs interface
 *
 *  /sys/kernel/jit_npt_trap/
 *      arm     (write-only) : "bounce_gpa sweep_start_gfn sweep_end_gfn"
 *                              all values are hex with optional 0x prefix
 *      disarm  (write-only) : write anything
 *      state   (read-only)  : human-readable current state
 * ══════════════════════════════════════════════════════════════════ */

static struct kobject *jit_npt_kobj;

/* ── /arm ─────────────────────────────────────────────────────── */

static ssize_t arm_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	u64 bounce_gpa_val, sweep_start_val, sweep_end_val;
	int ret;

	/*
	 * Accept three hex values, with or without leading "0x".
	 * Example:  "0x7f3000 0x100000 0x200000"
	 */
	ret = sscanf(buf, "%lli %lli %lli",
		     &bounce_gpa_val, &sweep_start_val, &sweep_end_val);
	if (ret != 3) {
		pr_err("jit_npt: arm: expected "
		       "\"<bounce_gpa> <sweep_start_gfn> <sweep_end_gfn>\", "
		       "got: %s\n", buf);
		return -EINVAL;
	}

	ret = jit_npt_arm((gpa_t)bounce_gpa_val,
			  (gfn_t)sweep_start_val,
			  (gfn_t)sweep_end_val);
	return ret ? ret : count;
}

static struct kobj_attribute arm_attr =
	__ATTR(arm, 0200, NULL, arm_store);

/* ── /disarm ──────────────────────────────────────────────────── */

static ssize_t disarm_store(struct kobject *kobj, struct kobj_attribute *attr,
			    const char *buf, size_t count)
{
	jit_npt_disarm();
	return count;
}

static struct kobj_attribute disarm_attr =
	__ATTR(disarm, 0200, NULL, disarm_store);

/* ── /state ───────────────────────────────────────────────────── */

static ssize_t state_show(struct kobject *kobj, struct kobj_attribute *attr,
			  char *buf)
{
	enum jit_npt_state s = (enum jit_npt_state)atomic_read(&jit_npt.state);
	int n;

	n = scnprintf(buf, PAGE_SIZE,
		      "state      : %s\n"
		      "bounce_gfn : 0x%llx  (GPA 0x%llx)\n"
		      "sweep      : [0x%llx, 0x%llx)  (%llu pages)\n"
		      "target_gpa : 0x%llx\n",
		      (s < ARRAY_SIZE(state_names)) ? state_names[s] : "UNKNOWN",
		      jit_npt.bounce_gfn,
		      jit_npt.bounce_gfn << PAGE_SHIFT,
		      jit_npt.sweep_start_gfn,
		      jit_npt.sweep_end_gfn,
		      jit_npt.sweep_end_gfn > jit_npt.sweep_start_gfn ?
			      jit_npt.sweep_end_gfn - jit_npt.sweep_start_gfn : 0ULL,
		      (u64)jit_npt.target_gpa);
	return n;
}

static struct kobj_attribute state_attr =
	__ATTR(state, 0444, state_show, NULL);

static struct attribute *jit_npt_attrs[] = {
	&arm_attr.attr,
	&disarm_attr.attr,
	&state_attr.attr,
	NULL,
};

static struct attribute_group jit_npt_attr_group = {
	.attrs = jit_npt_attrs,
};

/* ══════════════════════════════════════════════════════════════════
 * 6.  Module init / exit (called from sev-step.c or kvm module init)
 * ══════════════════════════════════════════════════════════════════ */

int jit_npt_init(void)
{
	int ret;

	spin_lock_init(&jit_npt.lock);
	atomic_set(&jit_npt.state, JIT_NPT_DISARMED);

	jit_npt_kobj = kobject_create_and_add("jit_npt_trap", kernel_kobj);
	if (!jit_npt_kobj) {
		pr_err("jit_npt: failed to create kobject\n");
		return -ENOMEM;
	}

	ret = sysfs_create_group(jit_npt_kobj, &jit_npt_attr_group);
	if (ret) {
		pr_err("jit_npt: failed to create sysfs group: %d\n", ret);
		kobject_put(jit_npt_kobj);
		jit_npt_kobj = NULL;
		return ret;
	}

	pr_info("jit_npt: initialised. "
		"Sysfs: /sys/kernel/jit_npt_trap/{arm,disarm,state}\n");
	return 0;
}
EXPORT_SYMBOL(jit_npt_init);

void jit_npt_exit(void)
{
	if (jit_npt_kobj) {
		sysfs_remove_group(jit_npt_kobj, &jit_npt_attr_group);
		kobject_put(jit_npt_kobj);
		jit_npt_kobj = NULL;
	}
	pr_info("jit_npt: exited\n");
}
EXPORT_SYMBOL(jit_npt_exit);
