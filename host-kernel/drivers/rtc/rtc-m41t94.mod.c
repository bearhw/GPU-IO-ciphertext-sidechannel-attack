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
	{ 0x8b51deca, "spi_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0xa07321bc, "spi_write_then_read" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "436F4857661B542F9DAE06C");
