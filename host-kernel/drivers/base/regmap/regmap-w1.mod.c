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

SYMBOL_CRC(__regmap_init_w1, 0x56d4f3eb, "_gpl");
SYMBOL_CRC(__devm_regmap_init_w1, 0x6b930ddb, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5c945c57, "w1_reset_select_slave" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xfccee5f1, "w1_write_8" },
	{ 0x94ea671e, "w1_read_8" },
	{ 0xbe5c720e, "__regmap_init" },
	{ 0xbca2be76, "__devm_regmap_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");


MODULE_INFO(srcversion, "4EF656D050A48AA419960D5");
