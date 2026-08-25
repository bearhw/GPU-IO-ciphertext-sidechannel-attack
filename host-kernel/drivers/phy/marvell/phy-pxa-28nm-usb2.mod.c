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
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x3c9fff02, "devm_phy_create" },
	{ 0xd409a706, "of_phy_simple_xlate" },
	{ 0x210681c5, "__devm_of_phy_provider_register" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cmarvell,pxa1928-usb-phy");
MODULE_ALIAS("of:N*T*Cmarvell,pxa1928-usb-phyC*");

MODULE_INFO(srcversion, "FF2D052812511BC6FE1138C");
