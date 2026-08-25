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
	{ 0x721718ea, "iget_locked" },
	{ 0xbd110405, "generic_block_bmap" },
	{ 0x9ff1bde6, "generic_fh_to_dentry" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x2875a315, "utf32_to_utf8" },
	{ 0x881f764b, "d_make_root" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0xeeee4967, "load_nls_default" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3de604fb, "load_nls" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xa916b694, "strnlen" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0x94bf03ca, "utf8_to_utf32" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xcee75b49, "__brelse" },
	{ 0x43c5c4c1, "inode_nohighmem" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0xddddf2ba, "simple_symlink_inode_operations" },
	{ 0x4e3567f7, "match_int" },
	{ 0xe021e1be, "generic_ro_fops" },
	{ 0xc81314f9, "kmem_cache_create_usercopy" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x5792f848, "strlcpy" },
	{ 0x5a921311, "strncmp" },
	{ 0xcad5e743, "d_obtain_alias" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0x86490580, "current_task" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0x2d727746, "block_read_full_folio" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0xb553fe15, "page_symlink_inode_operations" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x44e9a829, "match_token" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x391de184, "seq_puts" },
	{ 0x3f97c5df, "generic_fh_to_parent" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x754d539c, "strlen" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x30d45807, "unload_nls" },
	{ 0xa8ba1637, "sb_min_blocksize" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x814706bf, "iget_failed" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5EF373581E0BA7F9BA5D5DE");
