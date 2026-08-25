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
	{ 0xfe990052, "gpio_free" },
	{ 0xe582fa0e, "gpio_to_desc" },
	{ 0x551f15ad, "gpiod_direction_input" },
	{ 0x6a7d4e41, "gpiod_set_raw_value" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x39799ac, "gpiod_get_raw_value" },
	{ 0x834b6d4, "gpiod_direction_output_raw" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x2587f789, "_dev_info" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1E78468ABF130EC53E3E3B1");
