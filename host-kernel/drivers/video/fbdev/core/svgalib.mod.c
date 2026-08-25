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

SYMBOL_CRC(svga_get_caps, 0x091239a2, "");
SYMBOL_CRC(svga_wcrt_multi, 0x84c337c2, "");
SYMBOL_CRC(svga_wseq_multi, 0xdcc5a013, "");
SYMBOL_CRC(svga_set_default_gfx_regs, 0xe28d2a49, "");
SYMBOL_CRC(svga_set_default_atc_regs, 0xd22ca511, "");
SYMBOL_CRC(svga_set_default_seq_regs, 0x17f3f471, "");
SYMBOL_CRC(svga_set_default_crt_regs, 0x4ab38ef2, "");
SYMBOL_CRC(svga_set_textmode_vga_regs, 0x1be6dc30, "");
SYMBOL_CRC(svga_settile, 0xddeef891, "");
SYMBOL_CRC(svga_tilecopy, 0xe7e5ec3d, "");
SYMBOL_CRC(svga_tilefill, 0x848d5c48, "");
SYMBOL_CRC(svga_tileblit, 0x7f8a96bd, "");
SYMBOL_CRC(svga_tilecursor, 0xa10b6c59, "");
SYMBOL_CRC(svga_get_tilemax, 0xaffaadab, "");
SYMBOL_CRC(svga_compute_pll, 0xd6ec2c44, "");
SYMBOL_CRC(svga_check_timings, 0xb0ab2b2e, "");
SYMBOL_CRC(svga_set_timings, 0x83a41489, "");
SYMBOL_CRC(svga_match_format, 0x84c97d2a, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6d606913, "pv_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B45F4B5CCC2BB30D50F30CE");
