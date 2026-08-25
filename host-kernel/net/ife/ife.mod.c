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

SYMBOL_CRC(ife_encode, 0x459acad5, "_gpl");
SYMBOL_CRC(ife_decode, 0x69372eb6, "_gpl");
SYMBOL_CRC(ife_tlv_meta_decode, 0x67db2029, "_gpl");
SYMBOL_CRC(ife_tlv_meta_next, 0x6210e871, "_gpl");
SYMBOL_CRC(ife_tlv_meta_encode, 0xe7888e98, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x69acdf38, "memcpy" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xfb578fc5, "memset" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2A4D397E9FF00A6CB3FF02C");
