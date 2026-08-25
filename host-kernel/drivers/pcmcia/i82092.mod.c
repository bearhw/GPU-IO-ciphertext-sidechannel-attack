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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x45c00a5, "pcmcia_unregister_socket" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xd653a169, "pccard_nonstatic_ops" },
	{ 0x9d08e002, "pcmcia_register_socket" },
	{ 0x93cdae47, "pcmcia_parse_events" },
	{ 0x92997ed8, "_printk" },
	{ 0xf82d3dd4, "pcibios_resource_to_bus" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia_core,pcmcia_rsrc");

MODULE_ALIAS("pci:v00008086d00001221sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "0F976D0661769B4C59A6616");
