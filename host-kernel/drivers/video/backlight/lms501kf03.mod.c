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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xf9a482f9, "msleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0x946aad21, "devm_lcd_device_register" },
	{ 0x2587f789, "_dev_info" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "lcd");


MODULE_INFO(srcversion, "B05B623E0301A1DF3EF112B");
