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

SYMBOL_CRC(hd44780_common_print, 0x36dc00a2, "_gpl");
SYMBOL_CRC(hd44780_common_gotoxy, 0x07b26ecc, "_gpl");
SYMBOL_CRC(hd44780_common_home, 0x3c4c183f, "_gpl");
SYMBOL_CRC(hd44780_common_clear_display, 0x23159a5b, "_gpl");
SYMBOL_CRC(hd44780_common_init_display, 0x8d4f3fa4, "_gpl");
SYMBOL_CRC(hd44780_common_shift_cursor, 0xc369090d, "_gpl");
SYMBOL_CRC(hd44780_common_shift_display, 0x30e85287, "_gpl");
SYMBOL_CRC(hd44780_common_display, 0x64415593, "_gpl");
SYMBOL_CRC(hd44780_common_cursor, 0xa22afdaa, "_gpl");
SYMBOL_CRC(hd44780_common_blink, 0x8585e5fd, "_gpl");
SYMBOL_CRC(hd44780_common_fontsize, 0xf360d788, "_gpl");
SYMBOL_CRC(hd44780_common_lines, 0x1aa688fd, "_gpl");
SYMBOL_CRC(hd44780_common_redefine_char, 0x489c89e8, "_gpl");
SYMBOL_CRC(hd44780_common_alloc, 0x79e8e259, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x349cba85, "strchr" },
	{ 0xab6d5b3b, "hex_to_bin" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xd3e29970, "charlcd_backlight" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "charlcd");


MODULE_INFO(srcversion, "C4796470BAEF97784063248");
