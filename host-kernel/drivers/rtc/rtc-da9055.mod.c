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
	{ 0x812dad29, "regmap_raw_write" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x5838f6c9, "rtc_valid_tm" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xa7f54a6c, "platform_get_irq_byname" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E3738684CEDDAB913C63086");
