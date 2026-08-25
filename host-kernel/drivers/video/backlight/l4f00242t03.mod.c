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
	{ 0x8b51deca, "spi_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x83a0236e, "regulator_set_voltage" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xf9a482f9, "msleep" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x2ab20b28, "gpiod_set_consumer_name" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x946aad21, "devm_lcd_device_register" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "lcd");


MODULE_INFO(srcversion, "CB29BDB214C18378A4ADA1C");
