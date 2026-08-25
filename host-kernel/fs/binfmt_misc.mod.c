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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb15169bb, "get_tree_single" },
	{ 0x94f5f6cf, "simple_fill_super" },
	{ 0x83d070e8, "clear_inode" },
	{ 0x37a0cba, "kfree" },
	{ 0x84d5b86a, "filp_close" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xca415961, "drop_nlink" },
	{ 0xa0a14f90, "d_drop" },
	{ 0x7f8f3ec6, "dput" },
	{ 0xe1fea7df, "simple_release_fs" },
	{ 0xa916b694, "strnlen" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xd45cc6ca, "bin2hex" },
	{ 0x754d539c, "strlen" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x349cba85, "strchr" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x64bbc288, "string_unescape" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd9e8f475, "open_exec" },
	{ 0xdcaf4a77, "lookup_one_len" },
	{ 0x29d1b6da, "new_inode" },
	{ 0xe953b21f, "get_next_ino" },
	{ 0x87e815bc, "current_time" },
	{ 0x391c079, "simple_pin_fs" },
	{ 0xd9b85ef6, "lockref_get" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0xbcd4b433, "iput" },
	{ 0x92997ed8, "_printk" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x9f984513, "strrchr" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa1e8148e, "copy_string_kernel" },
	{ 0xfd176b4c, "bprm_change_interp" },
	{ 0xf25bbf52, "dentry_open" },
	{ 0xf080364f, "remove_arg_zero" },
	{ 0x388a5624, "register_filesystem" },
	{ 0xe6fcc938, "__register_binfmt" },
	{ 0x78dbe764, "unregister_binfmt" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x460cabd0, "simple_statfs" },
	{ 0x23af578f, "default_llseek" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x1f7a9338, "kill_litter_super" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "82A38B7372120A634FF3181");
