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

SYMBOL_CRC(__regmap_init_sdw_mbq, 0xead880a1, "_gpl");
SYMBOL_CRC(__devm_regmap_init_sdw_mbq, 0x7e413917, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbe5c720e, "__regmap_init" },
	{ 0xf400bd6, "sdw_read_no_pm" },
	{ 0x416a08cd, "sdw_write_no_pm" },
	{ 0xbca2be76, "__devm_regmap_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "soundwire-bus");


MODULE_INFO(srcversion, "4598D7065993E5A88063E43");
