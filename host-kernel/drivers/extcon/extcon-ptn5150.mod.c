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
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xc9fd634a, "usb_role_switch_put" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xd5474690, "usb_role_switch_set_role" },
	{ 0x39aa4888, "usb_role_string" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0xde49eaa4, "extcon_set_property_capability" },
	{ 0x805ad20a, "usb_role_switch_get" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x2587f789, "_dev_info" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:ptn5150");
MODULE_ALIAS("of:N*T*Cnxp,ptn5150");
MODULE_ALIAS("of:N*T*Cnxp,ptn5150C*");

MODULE_INFO(srcversion, "01FC0291F5FB04102C7CB30");
