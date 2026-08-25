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

SYMBOL_CRC(matrox_mystique, 0x8b269b46, "");
SYMBOL_CRC(matrox_G100, 0x1de8b80a, "");
SYMBOL_CRC(DAC1064_global_init, 0xcd594daf, "");
SYMBOL_CRC(DAC1064_global_restore, 0x64188710, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2743599c, "matroxfb_DAC_out" },
	{ 0xaeb8f4a8, "matroxfb_g450_setpll_cond" },
	{ 0x25cf8049, "matroxfb_PLL_calcclock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3b35bc92, "matroxfb_DAC_in" },
	{ 0x92997ed8, "_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xc1b4921b, "matroxfb_vgaHWrestore" },
	{ 0x587ec73b, "matroxfb_g450_setclk" },
	{ 0xbd26ced4, "g450_mnp2f" },
	{ 0x4af6622f, "matroxfb_vgaHWinit" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "matroxfb_misc,g450_pll");


MODULE_INFO(srcversion, "6B880014D468BBA0FF9B4F0");
