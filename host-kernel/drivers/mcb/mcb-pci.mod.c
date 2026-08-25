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
	{ 0x2ad0effe, "mcb_release_bus" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x77358855, "iomem_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x728a5a01, "mcb_alloc_bus" },
	{ 0x2434a5a3, "chameleon_parse_cells" },
	{ 0xe8e5654a, "mcb_bus_add_devices" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mcb");

MODULE_ALIAS("pci:v00001A88d00004D45sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001172d00004D45sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8E5BDEB4B8A841D7FCA78F3");
