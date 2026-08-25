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
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x58465e91, "intel_th_free" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xfe9e8a82, "pcim_iomap_regions_request_all" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd416f32e, "intel_th_alloc" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "intel_th");

MODULE_ALIAS("pci:v00008086d00009D26sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A126sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00005A8Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000A80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001A8Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A2A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000019E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A1A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A226sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000318Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A326sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009DA6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000018E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000034A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000002A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000006A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A3A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000045C5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008A29sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009A33sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A0A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000043A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004DA6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004E29sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004529sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B26sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001BCCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007AA6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000051A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000054A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000466Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004C19sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "AE2E3552F8871861C97B20B");
