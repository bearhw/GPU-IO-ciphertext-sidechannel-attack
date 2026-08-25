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
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x12fba874, "comedi_isadma_disable" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xb4246d37, "comedi_request_region" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3a77427c, "comedi_isadma_alloc" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xf1c0f6f4, "comedi_alloc_spriv" },
	{ 0xc8b1fea8, "__comedi_request_region" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xcd330f4, "range_unknown" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xb159d2b5, "comedi_isadma_free" },
	{ 0xd8957246, "comedi_legacy_detach" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x44a53057, "comedi_8254_cascade_ns_to_timer" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6ed165e0, "comedi_nsamples_left" },
	{ 0xea878430, "comedi_isadma_program" },
	{ 0x4a17474e, "comedi_isadma_disable_on_sample" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x2d446dbb, "comedi_8254_update_divisors" },
	{ 0xc0d4ea32, "comedi_8254_pacer_enable" },
	{ 0x24d273d1, "add_timer" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi,comedi_isadma,comedi_8254,comedi_8255");


MODULE_INFO(srcversion, "5BA5F215847A890080F19CD");
