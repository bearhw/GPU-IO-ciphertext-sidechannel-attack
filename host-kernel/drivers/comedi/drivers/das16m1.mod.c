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
	{ 0x37a0cba, "kfree" },
	{ 0xd8957246, "comedi_legacy_detach" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x2caf7357, "comedi_8254_read" },
	{ 0xabdc439, "cc_platform_has" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x9dbf2816, "comedi_8254_set_mode" },
	{ 0x4c672995, "comedi_8254_write" },
	{ 0x2d446dbb, "comedi_8254_update_divisors" },
	{ 0xc0d4ea32, "comedi_8254_pacer_enable" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xb4246d37, "comedi_request_region" },
	{ 0xc8b1fea8, "__comedi_request_region" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x44a53057, "comedi_8254_cascade_ns_to_timer" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi,comedi_8254,comedi_8255");


MODULE_INFO(srcversion, "A5A7DB46F450750BA2BF85E");
