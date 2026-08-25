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
	{ 0xc1514a3b, "free_irq" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xe34d0fe2, "dma_async_device_unregister" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0x20d8d10f, "pci_disable_msi" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x3c872672, "param_ops_byte" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xdf82259a, "pci_enable_msix_range" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0x1dc77dab, "rio_inb_pwrite_handler" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x452ee788, "rio_register_mport" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xa594f219, "dma_async_device_register" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xb44db7e0, "rio_mport_initialize" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x4920084, "pcie_capability_clear_and_set_word" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x26f8f0b8, "iowrite16be" },
	{ 0x13d6b829, "dma_async_tx_descriptor_init" },
	{ 0x87b8798d, "sg_next" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x3e3bad0a, "__tasklet_hi_schedule" },
	{ 0xa5f5614b, "pci_disable_msix" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x2ad8501f, "rio_unregister_mport" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x13d0adf7, "__kfifo_out" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v0000111Dd000080ABsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "FA0D992FF4B73A76673B908");
