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
	{ 0xc1514a3b, "free_irq" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x4ba6ac2e, "wm8350_set_bits" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x5c8ce503, "wm8350_block_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf6eb473, "wm8350_reg_read" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x2ac97bd5, "wm8350_block_write" },
	{ 0xee7c61c, "wm8350_clear_bits" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x4859b8bb, "rtc_year_days" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x2587f789, "_dev_info" },
	{ 0x636aa7c6, "wm8350_reg_unlock" },
	{ 0x3ce006bb, "wm8350_reg_lock" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EECF8220A9B7267C5E7B1D4");
