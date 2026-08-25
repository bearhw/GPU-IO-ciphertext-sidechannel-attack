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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x63a5e9da, "comedi_pci_auto_config" },
	{ 0x9dbf2816, "comedi_8254_set_mode" },
	{ 0x4c672995, "comedi_8254_write" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0x6ed165e0, "comedi_nsamples_left" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x369058ca, "comedi_buf_read_samples" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0xb8f1eb1f, "comedi_nscans_left" },
	{ 0x7a2af7b4, "cpu_number" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi_8254,comedi,comedi_8255");

MODULE_ALIAS("pci:v000014DCd00000000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DCd00000006sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "211A165BD4DD83803D1DC86");
