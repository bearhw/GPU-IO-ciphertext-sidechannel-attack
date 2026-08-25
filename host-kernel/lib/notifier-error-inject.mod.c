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

SYMBOL_CRC(notifier_err_inject_dir, 0x3ef5f74d, "_gpl");
SYMBOL_CRC(notifier_err_inject_init, 0xdd67a493, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x92997ed8, "_printk" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x20a00b75, "simple_attr_read" },
	{ 0xe85fea61, "simple_attr_write" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F60642BED4841BDD0A9F8E4");
