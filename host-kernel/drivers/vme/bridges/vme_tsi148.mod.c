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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x9bb4e317, "ioread32be" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe419bc99, "iowrite32be" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x37a0cba, "kfree" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xb19b445, "ioread8" },
	{ 0x364bd292, "vme_irq_handler" },
	{ 0xe191b00e, "vme_bus_error_handler" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x36046213, "vme_unregister_bridge" },
	{ 0xedc03953, "iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x842c8e9d, "ioread16" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x9a0c3a18, "vme_unregister_error_handler" },
	{ 0xf9f47100, "vme_register_error_handler" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x848d372e, "iowrite8" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3da171f9, "pci_mem_start" },
	{ 0xbdde6953, "pci_bus_alloc_resource" },
	{ 0xde80cd09, "ioremap" },
	{ 0xf82d3dd4, "pcibios_resource_to_bus" },
	{ 0xc5e74216, "release_resource" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xa1216e69, "vme_init_bridge" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x2587f789, "_dev_info" },
	{ 0xca2f0dd4, "vme_register_bridge" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000010E3d00000148sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "CAA3C1012F605FBFBA4C4B7");
