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
	{ 0xac9965ea, "clear_nlink" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0x9145da85, "fat_dir_empty" },
	{ 0x5727cbdf, "fat_time_unix2fat" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x1a4b6496, "fat_get_dotdot_entry" },
	{ 0x3dc4a84b, "fat_free_clusters" },
	{ 0x7b4c25ee, "fat_setattr" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x87e815bc, "current_time" },
	{ 0xe54a64ae, "__fat_fs_error" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x41ac606b, "fat_scan" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcee75b49, "__brelse" },
	{ 0x7715fab8, "fat_getattr" },
	{ 0xe0c6065e, "sync_dirty_buffer" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x70ae9cb7, "fat_attach" },
	{ 0x13c6229f, "fat_update_time" },
	{ 0xcbfc86b, "fat_build_inode" },
	{ 0x74417d16, "fat_fill_super" },
	{ 0xc43dd81f, "fat_alloc_new_dir" },
	{ 0xef52daa, "fat_remove_entries" },
	{ 0xd3d13ec, "fat_add_entries" },
	{ 0x722ef1e3, "fat_sync_inode" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3d8122aa, "inc_nlink" },
	{ 0xc624d43b, "fat_truncate_time" },
	{ 0x3831a027, "fat_flush_inodes" },
	{ 0x349cba85, "strchr" },
	{ 0xb801a7cb, "__mark_inode_dirty" },
	{ 0xb828cfb, "mark_buffer_dirty_inode" },
	{ 0xca415961, "drop_nlink" },
	{ 0xdc46465a, "fat_detach" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E4EA6BAE3A40F24D67166E3");
