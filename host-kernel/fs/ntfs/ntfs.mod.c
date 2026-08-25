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
	{ 0x10795da2, "__put_page" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x83d070e8, "clear_inode" },
	{ 0x9ff1bde6, "generic_fh_to_dentry" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0xb0e602eb, "memmove" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x5f192896, "mark_buffer_dirty" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x881f764b, "d_make_root" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0x53d736c3, "end_buffer_read_sync" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0xea4a64c2, "generic_error_remove_page" },
	{ 0xeeee4967, "load_nls_default" },
	{ 0x69acdf38, "memcpy" },
	{ 0xddce9b72, "ihold" },
	{ 0x37a0cba, "kfree" },
	{ 0x544c46c, "read_cache_page" },
	{ 0xae04012c, "__vmalloc" },
	{ 0xbcd4b433, "iput" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x8f22551c, "submit_bh" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3de604fb, "load_nls" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x4c64beb3, "create_empty_buffers" },
	{ 0x2e95a259, "truncate_inode_pages_final" },
	{ 0x5a94490b, "generic_file_mmap" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x23b4e0d7, "clear_page_rep" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xcee75b49, "__brelse" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xd8d474c1, "generic_file_read_iter" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0xe0c6065e, "sync_dirty_buffer" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x34b6449c, "__wait_on_buffer" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x93a6e0b2, "io_schedule" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x925493f, "clear_page_orig" },
	{ 0x9084b044, "clear_page_erms" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcad5e743, "d_obtain_alias" },
	{ 0x944375db, "_totalram_pages" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xebc45156, "d_add_ci" },
	{ 0xfb578fc5, "memset" },
	{ 0x47e04fe2, "__insert_inode_hash" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x304900ea, "unlock_buffer" },
	{ 0x551e5727, "igrab" },
	{ 0x6e2f0cd5, "__getblk_gfp" },
	{ 0x999e8297, "vfree" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0xf77feee, "d_add" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0xb1cc88df, "buffer_migrate_page" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x5c06a9c4, "__lock_buffer" },
	{ 0xafc325c9, "generic_file_open" },
	{ 0xcd72be06, "__folio_lock" },
	{ 0x3bc2c481, "pagecache_get_page" },
	{ 0x33c57e62, "is_bad_inode" },
	{ 0x49784725, "block_is_partially_uptodate" },
	{ 0x3f97c5df, "generic_fh_to_parent" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x990dce4e, "iget5_locked" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x349cba85, "strchr" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x792dc368, "make_bad_inode" },
	{ 0x30d45807, "unload_nls" },
	{ 0x53b954a2, "up_read" },
	{ 0xa8ba1637, "sb_min_blocksize" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A2D126050753C999D473469");
