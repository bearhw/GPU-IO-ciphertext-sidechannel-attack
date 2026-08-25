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

SYMBOL_CRC(LZ4_compress_HC, 0xddf86133, "");
SYMBOL_CRC(LZ4_loadDictHC, 0x93ff008c, "");
SYMBOL_CRC(LZ4_compress_HC_continue, 0x38f7b6e0, "");
SYMBOL_CRC(LZ4_saveDictHC, 0x9cef495b, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfb578fc5, "memset" },
	{ 0x69acdf38, "memcpy" },
	{ 0xb0e602eb, "memmove" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1E184FDE61103F3FEDFF37F");
