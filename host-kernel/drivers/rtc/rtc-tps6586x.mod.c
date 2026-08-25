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
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x1ad8b43e, "tps6586x_update" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x9a37e4d9, "tps6586x_reads" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0xc02c574f, "tps6586x_clr_bits" },
	{ 0xae79f0b5, "tps6586x_writes" },
	{ 0x4189a67d, "tps6586x_set_bits" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0xfb2f8a4, "mktime64" },
	{ 0x7522f3ba, "irq_modify_status" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "73C1ADD834182A1203EA85F");
