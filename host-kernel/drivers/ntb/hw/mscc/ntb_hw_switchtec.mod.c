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
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xfe052363, "ioread64_lo_hi" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xd21c5139, "iowrite64_lo_hi" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce93cd8, "ntb_db_event" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb19b445, "ioread8" },
	{ 0x842c8e9d, "ioread16" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x162ac598, "ntb_unregister_device" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x37a0cba, "kfree" },
	{ 0x2587f789, "_dev_info" },
	{ 0x848d372e, "iowrite8" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9243b3bb, "ntb_link_event" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xfb578fc5, "memset" },
	{ 0xae121354, "pci_iomap" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x1949bb7c, "ntb_register_device" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0xe9e1e851, "pci_iomap_range" },
	{ 0x1414c240, "switchtec_class" },
	{ 0xd9a9d63d, "class_interface_register" },
	{ 0x90c9f554, "class_interface_unregister" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb,switchtec");


MODULE_INFO(srcversion, "EAD46842FF1499E089FB421");
