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


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x12fba874, "comedi_isadma_disable" },
	{ 0xc0d4ea32, "comedi_8254_pacer_enable" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x44a53057, "comedi_8254_cascade_ns_to_timer" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xb4246d37, "comedi_request_region" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x2f0ad9d3, "range_bipolar5" },
	{ 0x3a77427c, "comedi_isadma_alloc" },
	{ 0xcd330f4, "range_unknown" },
	{ 0x8113872c, "range_unipolar10" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0x4fe634f3, "range_bipolar2_5" },
	{ 0xb159d2b5, "comedi_isadma_free" },
	{ 0xd8957246, "comedi_legacy_detach" },
	{ 0x6ed165e0, "comedi_nsamples_left" },
	{ 0xea878430, "comedi_isadma_program" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x2d446dbb, "comedi_8254_update_divisors" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_isadma,comedi_8254,comedi");


MODULE_INFO(srcversion, "1CBBB0B2707277CB1266224");
