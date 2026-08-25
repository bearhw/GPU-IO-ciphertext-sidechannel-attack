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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x63a5e9da, "comedi_pci_auto_config" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xf1c0f6f4, "comedi_alloc_spriv" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi");

MODULE_ALIAS("pci:v0000144Ad00007230sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Ad00007233sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Ad00007234sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Ad00007432sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Ad00007433sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Ad00007434sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "4A3BF6FD8FC83EC4FA49DE1");
