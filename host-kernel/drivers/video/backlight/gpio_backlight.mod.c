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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xbb726018, "device_property_present" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0x7954df, "gpiod_direction_output" },
	{ 0x96a75a88, "gpiod_get_direction" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cgpio-backlight");
MODULE_ALIAS("of:N*T*Cgpio-backlightC*");

MODULE_INFO(srcversion, "78111C59526E4CCA8C55232");
