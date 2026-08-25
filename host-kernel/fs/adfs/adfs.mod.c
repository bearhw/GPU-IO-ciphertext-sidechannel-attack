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
	{ 0xba177c19, "setattr_prepare" },
	{ 0xbd110405, "generic_block_bmap" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x881f764b, "d_make_root" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x87e815bc, "current_time" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8252ca6d, "generic_file_fsync" },
	{ 0xdaf7e8bd, "cont_write_begin" },
	{ 0x52bbd3b4, "generic_file_write_iter" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x92997ed8, "_printk" },
	{ 0xe7e331d3, "block_invalidate_folio" },
	{ 0x26e47eee, "generic_write_end" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x6f8df341, "block_write_full_page" },
	{ 0x5a94490b, "generic_file_mmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0xcee75b49, "__brelse" },
	{ 0xd8d474c1, "generic_file_read_iter" },
	{ 0x4e3567f7, "match_int" },
	{ 0xf9dac74, "truncate_pagecache" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0xd934a25a, "block_dirty_folio" },
	{ 0x86490580, "current_task" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0x668b19a1, "down_read" },
	{ 0x11295008, "truncate_setsize" },
	{ 0x2d727746, "block_read_full_folio" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x44e9a829, "match_token" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x815b5dd4, "match_octal" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb801a7cb, "__mark_inode_dirty" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x53b954a2, "up_read" },
	{ 0x7129e5f8, "hex_asc" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DE189AC6E6801978BD6D051");
