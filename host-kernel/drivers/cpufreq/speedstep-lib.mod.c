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

SYMBOL_CRC(speedstep_get_frequency, 0x2b67f096, "_gpl");
SYMBOL_CRC(speedstep_detect_processor, 0xd7ab2c0c, "_gpl");
SYMBOL_CRC(speedstep_get_freqs, 0x1b1f2bda, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xd6b33026, "cpu_khz" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x1e6d26a8, "strstr" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "33439A8312D9B325A3B6AFB");
