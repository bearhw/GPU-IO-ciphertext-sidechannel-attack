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

SYMBOL_CRC(labpc_common_attach, 0x8b26a5d1, "_gpl");
SYMBOL_CRC(labpc_common_detach, 0x8e5bd37f, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x68b5d967, "comedi_8254_mm_init" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x2b179514, "subdev_8255_mm_init" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0x37a0cba, "kfree" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0x3c2562dc, "labpc_handle_dma_status" },
	{ 0xcc652703, "labpc_drain_dma" },
	{ 0x9dbf2816, "comedi_8254_set_mode" },
	{ 0x44a53057, "comedi_8254_cascade_ns_to_timer" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x2d446dbb, "comedi_8254_update_divisors" },
	{ 0x708b5064, "comedi_8254_load" },
	{ 0x4c672995, "comedi_8254_write" },
	{ 0x35192b8f, "labpc_setup_dma" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi,comedi_8254,comedi_8255,ni_labpc_isadma");


MODULE_INFO(srcversion, "DEC930DB589D5DE513AA482");
