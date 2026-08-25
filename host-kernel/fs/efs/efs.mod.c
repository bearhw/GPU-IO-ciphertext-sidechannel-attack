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
	{ 0x2796b2, "init_special_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x881f764b, "d_make_root" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x37a0cba, "kfree" },
	{ 0xbcd4b433, "iput" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xcee75b49, "__brelse" },
	{ 0x43c5c4c1, "inode_nohighmem" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0xe021e1be, "generic_ro_fops" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcad5e743, "d_obtain_alias" },
	{ 0x6425d944, "__bread_gfp" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x2d727746, "block_read_full_folio" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0xb553fe15, "page_symlink_inode_operations" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3f97c5df, "generic_fh_to_parent" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x814706bf, "iget_failed" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BAD4CE0202C9048A65B1093");
