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
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Ccortina,gemini-rtc");
MODULE_ALIAS("of:N*T*Ccortina,gemini-rtcC*");
MODULE_ALIAS("of:N*T*Cfaraday,ftrtc010");
MODULE_ALIAS("of:N*T*Cfaraday,ftrtc010C*");

MODULE_INFO(srcversion, "B72BE85E52B8C92883C413C");
