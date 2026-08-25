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
	{ 0xe914e41e, "strcpy" },
	{ 0xba177c19, "setattr_prepare" },
	{ 0x721718ea, "iget_locked" },
	{ 0xac9965ea, "clear_nlink" },
	{ 0xbd110405, "generic_block_bmap" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x83d070e8, "clear_inode" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0xb0e602eb, "memmove" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x2796b2, "init_special_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x5f192896, "mark_buffer_dirty" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x655ca0b, "__find_get_block" },
	{ 0x881f764b, "d_make_root" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xdaf7e8bd, "cont_write_begin" },
	{ 0xbcd4b433, "iput" },
	{ 0x52bbd3b4, "generic_file_write_iter" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x5e95b1cd, "current_umask" },
	{ 0x3c060549, "inode_newsize_ok" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0xe7e331d3, "block_invalidate_folio" },
	{ 0x59fb744, "__breadahead" },
	{ 0x26e47eee, "generic_write_end" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x2e95a259, "truncate_inode_pages_final" },
	{ 0xa9d84cc1, "sync_blockdev" },
	{ 0x6f8df341, "block_write_full_page" },
	{ 0x5a94490b, "generic_file_mmap" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0xc6cbbc89, "capable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0xb8cb7ba2, "file_write_and_wait_range" },
	{ 0x388d2410, "compat_ptr_ioctl" },
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
	{ 0x7f78fd7e, "from_kgid" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0xdc6a9692, "mpage_writepages" },
	{ 0xf1e046cc, "panic" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0xd934a25a, "block_dirty_folio" },
	{ 0x86490580, "current_task" },
	{ 0x7e09a12c, "mpage_read_folio" },
	{ 0x402830fd, "from_kuid" },
	{ 0xfb578fc5, "memset" },
	{ 0xf4b4f6b9, "iomap_fiemap" },
	{ 0x47e04fe2, "__insert_inode_hash" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x11295008, "truncate_setsize" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x6e2f0cd5, "__getblk_gfp" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0xb553fe15, "page_symlink_inode_operations" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x89e9571c, "mpage_readahead" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x3d8122aa, "inc_nlink" },
	{ 0x44e9a829, "match_token" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x815b5dd4, "match_octal" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x754d539c, "strlen" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x792dc368, "make_bad_inode" },
	{ 0xca415961, "drop_nlink" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xe3a87077, "blkdev_issue_discard" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9AF092B388268A87063FF24");
