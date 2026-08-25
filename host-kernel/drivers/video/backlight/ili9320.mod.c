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

SYMBOL_CRC(ili9320_write, 0xe0d30147, "_gpl");
SYMBOL_CRC(ili9320_write_regs, 0x108b76f2, "_gpl");
SYMBOL_CRC(ili9320_probe_spi, 0xda9eee23, "_gpl");
SYMBOL_CRC(ili9320_remove, 0x63c5ac0a, "_gpl");
SYMBOL_CRC(ili9320_suspend, 0xdfe315d7, "_gpl");
SYMBOL_CRC(ili9320_resume, 0x73e6c750, "_gpl");
SYMBOL_CRC(ili9320_shutdown, 0x0cec74e7, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x8b51deca, "spi_sync" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x946aad21, "devm_lcd_device_register" },
	{ 0x2587f789, "_dev_info" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "lcd");


MODULE_INFO(srcversion, "518AFD96D6EB2F419840C39");
