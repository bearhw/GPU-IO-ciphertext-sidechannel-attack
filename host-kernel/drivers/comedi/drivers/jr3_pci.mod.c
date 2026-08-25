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
	{ 0x63a5e9da, "comedi_pci_auto_config" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0x11089ac7, "_ctype" },
	{ 0xab6d5b3b, "hex_to_bin" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xf1c0f6f4, "comedi_alloc_spriv" },
	{ 0x3fe0bdf8, "comedi_load_firmware" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x24d273d1, "add_timer" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi");

MODULE_ALIAS("pci:v00001762d00001111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00003111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00003112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00003113sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00003114sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "778AAB315118D2EDAC2006F");
