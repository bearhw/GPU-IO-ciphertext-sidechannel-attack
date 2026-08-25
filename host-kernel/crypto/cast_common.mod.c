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

SYMBOL_CRC(cast_s1, 0xbd3e7542, "_gpl");
SYMBOL_CRC(cast_s2, 0x5609ce41, "_gpl");
SYMBOL_CRC(cast_s3, 0xb9cba57f, "_gpl");
SYMBOL_CRC(cast_s4, 0x5b17be06, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B6FCD825D5173EDFBDC7D10");
