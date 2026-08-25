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
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(raid6_empty_zero_page, 0xb0d904b7, "");
SYMBOL_CRC(raid6_call, 0x804a5b70, "_gpl");
SYMBOL_CRC(raid6_2data_recov, 0x1803a6ed, "_gpl");
SYMBOL_CRC(raid6_datap_recov, 0xe4b051cf, "_gpl");
SYMBOL_CRC(raid6_gfmul, 0xd91319d6, "");
SYMBOL_CRC(raid6_vgfmul, 0x0b2c64a3, "");
SYMBOL_CRC(raid6_gfexp, 0x17f54263, "");
SYMBOL_CRC(raid6_gflog, 0xc8e3332b, "");
SYMBOL_CRC(raid6_gfinv, 0x59a2712d, "");
SYMBOL_CRC(raid6_gfexi, 0xcc4ee841, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4302d0eb, "free_pages" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A56707012770564CD6CA136");
