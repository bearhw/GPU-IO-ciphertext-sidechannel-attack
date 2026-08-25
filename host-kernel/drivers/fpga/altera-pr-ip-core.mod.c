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

SYMBOL_CRC(alt_pr_register, 0x145931e2, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x634f7f45, "devm_fpga_mgr_register" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x2587f789, "_dev_info" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-mgr");


MODULE_INFO(srcversion, "94F365A767E3DC9DED41886");
