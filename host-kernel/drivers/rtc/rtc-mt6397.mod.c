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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x7f24de73, "jiffies_to_usecs" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cmediatek,mt6323-rtc");
MODULE_ALIAS("of:N*T*Cmediatek,mt6323-rtcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt6358-rtc");
MODULE_ALIAS("of:N*T*Cmediatek,mt6358-rtcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt6397-rtc");
MODULE_ALIAS("of:N*T*Cmediatek,mt6397-rtcC*");

MODULE_INFO(srcversion, "40376C975AF7257B5972866");
