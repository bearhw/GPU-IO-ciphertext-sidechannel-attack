#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x721718ea, "iget_locked" },
	{ 0x10795da2, "__put_page" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0xee1f75e, "get_tree_mtd" },
	{ 0x2796b2, "init_special_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x881f764b, "d_make_root" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0xbb0540aa, "zlib_inflateReset" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0x37a0cba, "kfree" },
	{ 0x544c46c, "read_cache_page" },
	{ 0xcfa96893, "mtd_unpoint" },
	{ 0x7e367fa3, "generic_file_readonly_mmap" },
	{ 0xd5244492, "logfc" },
	{ 0x35a88f28, "zlib_inflateInit2" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x815f2897, "empty_zero_page" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0x8046170a, "kill_mtd_super" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0x581f98da, "zlib_inflate" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x43c5c4c1, "inode_nohighmem" },
	{ 0xd8d474c1, "generic_file_read_iter" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0xe021e1be, "generic_ro_fops" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xce5ac24f, "zlib_inflate_workspacesize" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x999e8297, "vfree" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0xb553fe15, "page_symlink_inode_operations" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa7a0ce3, "get_tree_bdev" },
	{ 0x7674413b, "folio_wait_bit" },
	{ 0xc0bea473, "vmf_insert_mixed" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x107e5878, "zlib_inflateEnd" },
	{ 0x75342d5d, "mtd_point" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mtd");


MODULE_INFO(srcversion, "F6B5A980882137FF005336B");
