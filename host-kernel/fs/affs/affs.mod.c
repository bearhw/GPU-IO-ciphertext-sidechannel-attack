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
	{ 0xba177c19, "setattr_prepare" },
	{ 0x721718ea, "iget_locked" },
	{ 0xac9965ea, "clear_nlink" },
	{ 0xbd110405, "generic_block_bmap" },
	{ 0x10795da2, "__put_page" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0x83d070e8, "clear_inode" },
	{ 0xb03e8afb, "grab_cache_page_write_begin" },
	{ 0x9ff1bde6, "generic_fh_to_dentry" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x5f192896, "mark_buffer_dirty" },
	{ 0xb85b664b, "__blockdev_direct_IO" },
	{ 0x881f764b, "d_make_root" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x87e815bc, "current_time" },
	{ 0x69acdf38, "memcpy" },
	{ 0xddce9b72, "ihold" },
	{ 0xd08f3d14, "page_get_link" },
	{ 0x37a0cba, "kfree" },
	{ 0xdaf7e8bd, "cont_write_begin" },
	{ 0xbcd4b433, "iput" },
	{ 0x52bbd3b4, "generic_file_write_iter" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x41814cb8, "dirty_writeback_interval" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3c060549, "inode_newsize_ok" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0xe7e331d3, "block_invalidate_folio" },
	{ 0x26e47eee, "generic_write_end" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x2e95a259, "truncate_inode_pages_final" },
	{ 0xa9d84cc1, "sync_blockdev" },
	{ 0x6f8df341, "block_write_full_page" },
	{ 0x5a94490b, "generic_file_mmap" },
	{ 0x1cee517d, "invalidate_inode_buffers" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0xb8cb7ba2, "file_write_and_wait_range" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xfe5d4bb2, "sys_tz" },
	{ 0xcee75b49, "__brelse" },
	{ 0x43c5c4c1, "inode_nohighmem" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xd8d474c1, "generic_file_read_iter" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0x4e3567f7, "match_int" },
	{ 0xf9dac74, "truncate_pagecache" },
	{ 0xe0c6065e, "sync_dirty_buffer" },
	{ 0x79309710, "setattr_copy" },
	{ 0x34b6449c, "__wait_on_buffer" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x5792f848, "strlcpy" },
	{ 0x7f78fd7e, "from_kgid" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x95bdff9a, "write_inode_now" },
	{ 0xcad5e743, "d_obtain_alias" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0xd934a25a, "block_dirty_folio" },
	{ 0x86490580, "current_task" },
	{ 0x402830fd, "from_kuid" },
	{ 0xfb578fc5, "memset" },
	{ 0x47e04fe2, "__insert_inode_hash" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0x131db64a, "system_long_wq" },
	{ 0x11295008, "truncate_setsize" },
	{ 0x2d727746, "block_read_full_folio" },
	{ 0x6d606913, "pv_ops" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x304900ea, "unlock_buffer" },
	{ 0x6e2f0cd5, "__getblk_gfp" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x44e9a829, "match_token" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x5c06a9c4, "__lock_buffer" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x391de184, "seq_puts" },
	{ 0x3f97c5df, "generic_fh_to_parent" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x815b5dd4, "match_octal" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x349cba85, "strchr" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb801a7cb, "__mark_inode_dirty" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0xb828cfb, "mark_buffer_dirty_inode" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3fe2ccbe, "memweight" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x814706bf, "iget_failed" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "68E325F3936C258B3E686BC");
