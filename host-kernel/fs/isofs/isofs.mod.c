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
	{ 0xbd110405, "generic_block_bmap" },
	{ 0x10795da2, "__put_page" },
	{ 0xeb9eef52, "match_uint" },
	{ 0x2796b2, "init_special_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x881f764b, "d_make_root" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xbcd4b433, "iput" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x35a88f28, "zlib_inflateInit2" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0x96b29254, "strncasecmp" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3de604fb, "load_nls" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0x800473f, "__cond_resched" },
	{ 0x581f98da, "zlib_inflate" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x8d3086e7, "cdrom_read_tocentry" },
	{ 0xcee75b49, "__brelse" },
	{ 0x43c5c4c1, "inode_nohighmem" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0x4e3567f7, "match_int" },
	{ 0xe021e1be, "generic_ro_fops" },
	{ 0xa07a37f0, "memchr" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x34b6449c, "__wait_on_buffer" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x5a921311, "strncmp" },
	{ 0xce5ac24f, "zlib_inflate_workspacesize" },
	{ 0xd4816202, "cdrom_multisession" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcad5e743, "d_obtain_alias" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0x86490580, "current_task" },
	{ 0x11089ac7, "_ctype" },
	{ 0x7e09a12c, "mpage_read_folio" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6e2f0cd5, "__getblk_gfp" },
	{ 0x999e8297, "vfree" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0xb553fe15, "page_symlink_inode_operations" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x89e9571c, "mpage_readahead" },
	{ 0xfb2f8a4, "mktime64" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x44e9a829, "match_token" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xabf32f29, "utf16s_to_utf8s" },
	{ 0x88e92c91, "ll_rw_block" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x3bc2c481, "pagecache_get_page" },
	{ 0x391de184, "seq_puts" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x990dce4e, "iget5_locked" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x30d45807, "unload_nls" },
	{ 0x107e5878, "zlib_inflateEnd" },
	{ 0xa8ba1637, "sb_min_blocksize" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x814706bf, "iget_failed" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7AA4227B57D30438F55EB50");
