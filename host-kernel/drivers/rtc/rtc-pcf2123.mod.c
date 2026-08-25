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
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x2587f789, "_dev_info" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3e2e916b, "__devm_regmap_init_spi" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("spi:pcf2123");
MODULE_ALIAS("spi:rv2123");
MODULE_ALIAS("spi:rtc-pcf2123");

MODULE_INFO(srcversion, "2895B1D318905A5735C062B");
