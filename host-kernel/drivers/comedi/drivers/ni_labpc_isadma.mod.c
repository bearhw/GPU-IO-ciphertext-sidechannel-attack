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

SYMBOL_CRC(labpc_setup_dma, 0x35192b8f, "_gpl");
SYMBOL_CRC(labpc_drain_dma, 0xcc652703, "_gpl");
SYMBOL_CRC(labpc_handle_dma_status, 0x3c2562dc, "_gpl");
SYMBOL_CRC(labpc_init_dma_chan, 0x5a56f828, "_gpl");
SYMBOL_CRC(labpc_free_dma_chan, 0x1766e6d5, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x12fba874, "comedi_isadma_disable" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xea878430, "comedi_isadma_program" },
	{ 0x3a77427c, "comedi_isadma_alloc" },
	{ 0xb159d2b5, "comedi_isadma_free" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_isadma,comedi");


MODULE_INFO(srcversion, "04F5601AB561B5CD2B8CFD0");
