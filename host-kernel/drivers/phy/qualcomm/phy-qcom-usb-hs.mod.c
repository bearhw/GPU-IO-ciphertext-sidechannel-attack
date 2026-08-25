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
	{ 0xe2044c84, "ulpi_write" },
	{ 0x2b6f4d1b, "extcon_unregister_notifier" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x63526f4c, "__devm_reset_control_get" },
	{ 0x3c9fff02, "devm_phy_create" },
	{ 0xb062f6ae, "extcon_get_edev_by_phandle" },
	{ 0xd409a706, "of_phy_simple_xlate" },
	{ 0x210681c5, "__devm_of_phy_provider_register" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0x5b9bd9e0, "regulator_set_load" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x83a0236e, "regulator_set_voltage" },
	{ 0x24f39c39, "reset_control_reset" },
	{ 0x9a5c00da, "extcon_get_state" },
	{ 0x6d28fac8, "extcon_register_notifier" },
	{ 0xcaf9a63, "__ulpi_register_driver" },
	{ 0xc644233d, "ulpi_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ulpi");

MODULE_ALIAS("of:N*T*Cqcom,usb-hs-phy");
MODULE_ALIAS("of:N*T*Cqcom,usb-hs-phyC*");

MODULE_INFO(srcversion, "7379991627F9981B1FA5899");
