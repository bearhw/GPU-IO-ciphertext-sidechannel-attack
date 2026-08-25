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
	{ 0x7eff36c4, "siox_master_unregister" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0xcb072af3, "siox_master_alloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xe5353e3, "siox_master_register" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x3197c4e3, "put_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "siox-core");

MODULE_ALIAS("of:N*T*Ceckelmann,siox-gpio");
MODULE_ALIAS("of:N*T*Ceckelmann,siox-gpioC*");

MODULE_INFO(srcversion, "B955FC7CA6CC9425A2859B5");
