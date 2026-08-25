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
	{ 0x6d606913, "pv_ops" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x85bd1608, "__request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0xf6f12283, "cpci_hp_register_controller" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xb5b4339c, "cpci_hp_register_bus" },
	{ 0x6a8441be, "cpci_hp_start" },
	{ 0x53b35439, "cpci_hp_unregister_controller" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x21486fc, "cpci_hp_unregister_bus" },
	{ 0x94ef4d05, "cpci_hp_stop" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001138d00005550sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "9CCAE9B4B0831F60B628CE1");
