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
	{ 0xa78af5f3, "ioread32" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x886e3a2d, "_vdpa_register_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xe40f4ed3, "__vdpa_alloc_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x541125c9, "vdpa_mgmtdev_unregister" },
	{ 0x848d372e, "iowrite8" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb19b445, "ioread8" },
	{ 0x905cef39, "_vdpa_unregister_device" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xe48d6275, "vdpa_mgmtdev_register" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vdpa");

MODULE_ALIAS("pci:v00001AF4d00001041sv00008086sd0000001Abc*sc*i*");
MODULE_ALIAS("pci:v00001AF4d00001000sv00008086sd00000001bc*sc*i*");
MODULE_ALIAS("pci:v00001AF4d00001001sv00008086sd00000002bc*sc*i*");

MODULE_INFO(srcversion, "C97EC1D7FB12FD4B53C9CD8");
