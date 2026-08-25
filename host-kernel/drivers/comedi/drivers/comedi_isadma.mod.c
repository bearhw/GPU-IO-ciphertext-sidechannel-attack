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

SYMBOL_CRC(comedi_isadma_program, 0xea878430, "_gpl");
SYMBOL_CRC(comedi_isadma_disable, 0x12fba874, "_gpl");
SYMBOL_CRC(comedi_isadma_disable_on_sample, 0x4a17474e, "_gpl");
SYMBOL_CRC(comedi_isadma_poll, 0xcbacb5f0, "_gpl");
SYMBOL_CRC(comedi_isadma_set_mode, 0xca784d4b, "_gpl");
SYMBOL_CRC(comedi_isadma_alloc, 0x3a77427c, "_gpl");
SYMBOL_CRC(comedi_isadma_free, 0xb159d2b5, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x175e33fb, "dma_spin_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x37a0cba, "kfree" },
	{ 0x72b243d4, "free_dma" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x7054a3e4, "request_dma" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xf82abc1d, "isa_dma_bridge_buggy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B624F5AEF9A98D8DE093E29");
