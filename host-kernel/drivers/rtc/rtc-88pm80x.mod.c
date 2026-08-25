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
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xa973a327, "regmap_raw_read" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x812dad29, "regmap_raw_write" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x55784228, "regmap_irq_get_virq" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7DF04923C2E90636008B129");
