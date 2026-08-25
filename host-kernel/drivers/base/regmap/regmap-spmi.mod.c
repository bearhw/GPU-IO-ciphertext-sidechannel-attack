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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(__regmap_init_spmi_base, 0x3805f63b, "_gpl");
SYMBOL_CRC(__devm_regmap_init_spmi_base, 0x71581185, "_gpl");
SYMBOL_CRC(__regmap_init_spmi_ext, 0x9bbac742, "_gpl");
SYMBOL_CRC(__devm_regmap_init_spmi_ext, 0xaf1a34a4, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbe5c720e, "__regmap_init" },
	{ 0x36b5eaef, "spmi_register_read" },
	{ 0xde8263bb, "spmi_register_write" },
	{ 0xe87b8d32, "spmi_register_zero_write" },
	{ 0xbca2be76, "__devm_regmap_init" },
	{ 0x3dbb46f7, "spmi_ext_register_read" },
	{ 0x3cf64684, "spmi_ext_register_readl" },
	{ 0x915226e0, "spmi_ext_register_write" },
	{ 0xb566268e, "spmi_ext_register_writel" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "spmi");


MODULE_INFO(srcversion, "1E3246823CE1A9B76C01ADA");
