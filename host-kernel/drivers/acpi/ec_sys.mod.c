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
	{ 0xfc4152fc, "ec_read" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc708f1fe, "ec_write" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x48bedf65, "first_ec" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa5389eb1, "debugfs_create_x32" },
	{ 0x4465655e, "debugfs_create_bool" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x23af578f, "default_llseek" },
	{ 0x6a59169d, "simple_open" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6BF25094433A90516CBD9ED");
