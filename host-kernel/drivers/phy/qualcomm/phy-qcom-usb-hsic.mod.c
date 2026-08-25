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
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf3a92611, "devm_pinctrl_get" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x3c9fff02, "devm_phy_create" },
	{ 0xd409a706, "of_phy_simple_xlate" },
	{ 0x210681c5, "__devm_of_phy_provider_register" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0xe2044c84, "ulpi_write" },
	{ 0x3bfed546, "pinctrl_lookup_state" },
	{ 0xbd44d6b9, "pinctrl_select_state" },
	{ 0xcaf9a63, "__ulpi_register_driver" },
	{ 0xc644233d, "ulpi_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ulpi");

MODULE_ALIAS("of:N*T*Cqcom,usb-hsic-phy");
MODULE_ALIAS("of:N*T*Cqcom,usb-hsic-phyC*");

MODULE_INFO(srcversion, "79925B2C4A8C0142BDB5479");
