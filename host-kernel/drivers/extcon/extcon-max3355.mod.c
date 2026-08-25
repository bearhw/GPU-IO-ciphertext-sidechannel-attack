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
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cmaxim,max3355");
MODULE_ALIAS("of:N*T*Cmaxim,max3355C*");

MODULE_INFO(srcversion, "178EE0813E45FEDF39EAC71");
