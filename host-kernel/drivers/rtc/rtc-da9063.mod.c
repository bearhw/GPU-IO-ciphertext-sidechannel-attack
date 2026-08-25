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
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2a8a60bf, "dev_get_regmap" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0xa7f54a6c, "platform_get_irq_byname" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cdlg,da9063-rtc");
MODULE_ALIAS("of:N*T*Cdlg,da9063-rtcC*");
MODULE_ALIAS("of:N*T*Cdlg,da9062-rtc");
MODULE_ALIAS("of:N*T*Cdlg,da9062-rtcC*");

MODULE_INFO(srcversion, "FF04BB3E6E5C0CE7DB32623");
