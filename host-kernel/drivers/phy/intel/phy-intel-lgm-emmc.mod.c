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
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2e1ca751, "clk_put" },
	{ 0x82c40558, "clk_get" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc34bbddd, "syscon_regmap_lookup_by_phandle" },
	{ 0x3c9fff02, "devm_phy_create" },
	{ 0xd409a706, "of_phy_simple_xlate" },
	{ 0x210681c5, "__devm_of_phy_provider_register" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cintel,lgm-emmc-phy");
MODULE_ALIAS("of:N*T*Cintel,lgm-emmc-phyC*");

MODULE_INFO(srcversion, "C8BC6FC5ED6AEE94D4DC719");
