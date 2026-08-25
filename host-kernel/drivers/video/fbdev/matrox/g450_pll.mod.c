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

SYMBOL_CRC(matroxfb_g450_setclk, 0x587ec73b, "");
SYMBOL_CRC(g450_mnp2f, 0xbd26ced4, "");
SYMBOL_CRC(matroxfb_g450_setpll_cond, 0xaeb8f4a8, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2743599c, "matroxfb_DAC_out" },
	{ 0x3b35bc92, "matroxfb_DAC_in" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x37a0cba, "kfree" },
	{ 0xb0e602eb, "memmove" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "matroxfb_misc");


MODULE_INFO(srcversion, "A9E294CFEC6C8B631B9855B");
