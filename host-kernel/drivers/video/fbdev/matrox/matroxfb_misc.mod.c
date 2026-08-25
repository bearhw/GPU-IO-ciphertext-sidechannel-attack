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

SYMBOL_CRC(matroxfb_DAC_in, 0x3b35bc92, "");
SYMBOL_CRC(matroxfb_DAC_out, 0x2743599c, "");
SYMBOL_CRC(matroxfb_var2my, 0xcdc90c64, "");
SYMBOL_CRC(matroxfb_PLL_calcclock, 0x25cf8049, "");
SYMBOL_CRC(matroxfb_vgaHWinit, 0x4af6622f, "");
SYMBOL_CRC(matroxfb_vgaHWrestore, 0xc1b4921b, "");
SYMBOL_CRC(matroxfb_read_pins, 0xe6bc56f8, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xde80cd09, "ioremap" },
	{ 0xedc03953, "iounmap" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "57F10F44998CE5CDD7B6F00");
