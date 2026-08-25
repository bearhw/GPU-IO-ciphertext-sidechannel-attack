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
	{ 0xb376018d, "super_setup_bdi_name" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x5d0bd002, "generic_fillattr" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x70cdcbfd, "vbg_warn" },
	{ 0x721718ea, "iget_locked" },
	{ 0x10795da2, "__put_page" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0xa66df15e, "noop_fsync" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x16161009, "fs_param_is_string" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0xb0e602eb, "memmove" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x1663b2e5, "filemap_map_pages" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x2875a315, "utf32_to_utf8" },
	{ 0x35813e55, "vbg_get_gdev" },
	{ 0x881f764b, "d_make_root" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0xeeee4967, "load_nls_default" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x1eb26fc9, "finish_open" },
	{ 0xbcd4b433, "iput" },
	{ 0x52bbd3b4, "generic_file_write_iter" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5bc764ea, "get_tree_nodev" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x358e7605, "fs_param_is_u32" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3de604fb, "load_nls" },
	{ 0x18063a09, "vbg_hgcm_connect" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x5a94490b, "generic_file_mmap" },
	{ 0xa916b694, "strnlen" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0x94bf03ca, "utf8_to_utf32" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xf712f5c1, "generic_parse_monolithic" },
	{ 0xd8d474c1, "generic_file_read_iter" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0x1ae11974, "dentry_path_raw" },
	{ 0x954f099c, "idr_preload" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x72515d2e, "vbg_hgcm_disconnect" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x5792f848, "strlcpy" },
	{ 0xffb7c514, "ida_free" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe107e4bf, "simple_write_begin" },
	{ 0x86490580, "current_task" },
	{ 0xd602239d, "finish_no_open" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x91f44510, "idr_alloc_cyclic" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xfb578fc5, "memset" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x260590c0, "vbg_err" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x9c072aa8, "vbg_status_code_to_errno" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xe51651bf, "vbg_put_gdev" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3096be16, "names_cachep" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0xebfea46d, "invalidate_inode_pages2" },
	{ 0x44e30854, "vbg_hgcm_call" },
	{ 0x7f8f3ec6, "dput" },
	{ 0xafc325c9, "generic_file_open" },
	{ 0xfbe0e228, "filemap_dirty_folio" },
	{ 0x9e4d8096, "__fs_parse" },
	{ 0xb8b043f2, "kfree_link" },
	{ 0x82b7c307, "kill_anon_super" },
	{ 0x41c5bdad, "filemap_write_and_wait_range" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0x1829ff26, "filemap_fault" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x30d45807, "unload_nls" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vboxguest");


MODULE_INFO(srcversion, "8E24DC4CDBEC8369DDC05FD");
