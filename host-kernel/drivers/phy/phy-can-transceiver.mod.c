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
	{ 0x7cf08396, "mux_state_deselect" },
	{ 0xfa76e911, "mux_state_select_delay" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3c9fff02, "devm_phy_create" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xd409a706, "of_phy_simple_xlate" },
	{ 0x210681c5, "__devm_of_phy_provider_register" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mux-core");

MODULE_ALIAS("of:N*T*Cti,tcan1042");
MODULE_ALIAS("of:N*T*Cti,tcan1042C*");
MODULE_ALIAS("of:N*T*Cti,tcan1043");
MODULE_ALIAS("of:N*T*Cti,tcan1043C*");

MODULE_INFO(srcversion, "8A3C887B3467098220C3B42");
