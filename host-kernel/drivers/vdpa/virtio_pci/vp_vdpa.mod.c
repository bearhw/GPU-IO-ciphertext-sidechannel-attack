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
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xe74eea8c, "vp_modern_remove" },
	{ 0x541125c9, "vdpa_mgmtdev_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0x96ee7b73, "vp_modern_get_features" },
	{ 0x905cef39, "_vdpa_unregister_device" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0xc62d823c, "vp_modern_generation" },
	{ 0x848d372e, "iowrite8" },
	{ 0xb19b445, "ioread8" },
	{ 0x97790d90, "vp_modern_queue_vector" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0x3e9448b6, "vp_modern_config_vector" },
	{ 0x29e1b42e, "vp_modern_get_status" },
	{ 0x5a703f33, "vp_modern_set_status" },
	{ 0x7fcf5c68, "vp_modern_get_driver_features" },
	{ 0x2e3d7d91, "vp_modern_set_features" },
	{ 0x4c9df508, "vp_modern_get_queue_enable" },
	{ 0x1c1a8779, "vp_modern_set_queue_enable" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x3eabed59, "vp_modern_set_queue_size" },
	{ 0xfaaeab68, "vp_modern_queue_address" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe40f4ed3, "__vdpa_alloc_device" },
	{ 0x7fcdcea3, "vp_modern_get_num_queues" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa033a0d, "vp_modern_map_vq_notify" },
	{ 0x886e3a2d, "_vdpa_register_device" },
	{ 0x3197c4e3, "put_device" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x1681ff83, "vp_modern_probe" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xe48d6275, "vdpa_mgmtdev_register" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vdpa");


MODULE_INFO(srcversion, "F690FF9ED9CE08E67E8052E");
