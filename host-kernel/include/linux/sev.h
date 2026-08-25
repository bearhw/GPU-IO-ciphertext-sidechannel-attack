/* SPDX-License-Identifier: GPL-2.0 */
/*
 * AMD Secure Encrypted Virtualization
 *
 * Author: Brijesh Singh <brijesh.singh@amd.com>
 */

#ifndef __LINUX_SEV_H
#define __LINUX_SEV_H

/* RMUPDATE detected 4K page and 2MB page overlap. */
#define RMPUPDATE_FAIL_OVERLAP		7

#ifdef CONFIG_AMD_MEM_ENCRYPT
int snp_lookup_rmpentry(u64 pfn, int *level);
int psmash(u64 pfn);
int rmp_make_private(u64 pfn, u64 gpa, enum pg_level level, int asid, bool immutable);
int rmp_make_shared(u64 pfn, enum pg_level level);
int rmp_make_pre_swap(u64 pfn);
int snp_free_guest_invalid_page(struct page *page);
void dump_rmpentry(u64 pfn);
int get_rmpentry_asid(u64 pfn);
#else
static inline int snp_lookup_rmpentry(u64 pfn, int *level) { return 0; }
static inline int psmash(u64 pfn) { return -ENXIO; }
static inline int rmp_make_private(u64 pfn, u64 gpa, enum pg_level level, int asid,
				   bool immutable)
{
	return -ENODEV;
}
static inline int rmp_make_shared(u64 pfn, enum pg_level level) { return -ENODEV; }
static inline int rmp_make_pre_swap(u64 pfn) { return -ENODEV; }
static inline void dump_rmpentry(u64 pfn) { }
static inline int get_rmpentry_asid(u64 pfn) { return 0; }

#endif /* CONFIG_AMD_MEM_ENCRYPT */
#endif /* __LINUX_SEV_H */
