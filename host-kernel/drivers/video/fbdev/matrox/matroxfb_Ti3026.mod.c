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

SYMBOL_CRC(matrox_millennium, 0x92220728, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x3b35bc92, "matroxfb_DAC_in" },
	{ 0x2743599c, "matroxfb_DAC_out" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc1b4921b, "matroxfb_vgaHWrestore" },
	{ 0x92997ed8, "_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x25cf8049, "matroxfb_PLL_calcclock" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4af6622f, "matroxfb_vgaHWinit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "matroxfb_misc");


MODULE_INFO(srcversion, "0BC0124AC5A175E46DF16FA");
