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
	{ 0xa07321bc, "spi_write_then_read" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("spi:rx4581");

MODULE_INFO(srcversion, "24B9B4A242E0CAAEDFA11E7");
