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
	{ 0x4997d9eb, "__max730x_remove" },
	{ 0xa07321bc, "spi_write_then_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x923ba07e, "__max730x_probe" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "gpio-max730x");

MODULE_ALIAS("spi:max7301");

MODULE_INFO(srcversion, "A4F28972FF3C85CCF767F9A");
