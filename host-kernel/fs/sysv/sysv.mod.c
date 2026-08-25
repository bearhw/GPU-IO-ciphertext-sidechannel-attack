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
	{ 0xdf929370, "fs_overflowgid" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xa0fa8103, "inode_init_owner" },
	{ 0x5d0bd002, "generic_fillattr" },
	{ 0xba177c19, "setattr_prepare" },
	{ 0x721718ea, "iget_locked" },
	{ 0xbd110405, "generic_block_bmap" },
	{ 0x10795da2, "__put_page" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0x83d070e8, "clear_inode" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x2796b2, "init_special_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x5f192896, "mark_buffer_dirty" },
	{ 0x1c2090d, "__block_write_begin" },
	{ 0x881f764b, "d_make_root" },
	{ 0xdf1f15d0, "__bforget" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0xd4bf9ea9, "block_truncate_page" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x87e815bc, "current_time" },
	{ 0x69acdf38, "memcpy" },
	{ 0xddce9b72, "ihold" },
	{ 0xd08f3d14, "page_get_link" },
	{ 0x37a0cba, "kfree" },
	{ 0x8252ca6d, "generic_file_fsync" },
	{ 0x544c46c, "read_cache_page" },
	{ 0xbcd4b433, "iput" },
	{ 0x52bbd3b4, "generic_file_write_iter" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3c060549, "inode_newsize_ok" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0xe7e331d3, "block_invalidate_folio" },
	{ 0x26e47eee, "generic_write_end" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x2e95a259, "truncate_inode_pages_final" },
	{ 0x7893b95a, "block_write_end" },
	{ 0x6f8df341, "block_write_full_page" },
	{ 0x5a94490b, "generic_file_mmap" },
	{ 0xa916b694, "strnlen" },
	{ 0x1cee517d, "invalidate_inode_buffers" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xcee75b49, "__brelse" },
	{ 0x43c5c4c1, "inode_nohighmem" },
	{ 0xd8d474c1, "generic_file_read_iter" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0xf9dac74, "truncate_pagecache" },
	{ 0xe0c6065e, "sync_dirty_buffer" },
	{ 0x377b5f2f, "page_symlink" },
	{ 0x79309710, "setattr_copy" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x7f78fd7e, "from_kgid" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0xd934a25a, "block_dirty_folio" },
	{ 0x402830fd, "from_kuid" },
	{ 0xfb578fc5, "memset" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x47e04fe2, "__insert_inode_hash" },
	{ 0xb4c136f6, "folio_write_one" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x11295008, "truncate_setsize" },
	{ 0x2d727746, "block_read_full_folio" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x304900ea, "unlock_buffer" },
	{ 0x6e2f0cd5, "__getblk_gfp" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x3d8122aa, "inc_nlink" },
	{ 0x5c06a9c4, "__lock_buffer" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x25820c64, "fs_overflowuid" },
	{ 0xcd72be06, "__folio_lock" },
	{ 0x3bc2c481, "pagecache_get_page" },
	{ 0x34db489a, "block_write_begin" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x754d539c, "strlen" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb801a7cb, "__mark_inode_dirty" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0xb828cfb, "mark_buffer_dirty_inode" },
	{ 0xca415961, "drop_nlink" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x814706bf, "iget_failed" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "827050ED4EDEEA0CE0C9240");
