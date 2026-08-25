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
	{ 0x37a0cba, "kfree" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xf34989c, "pci_release_region" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x2587f789, "_dev_info" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa6b3c164, "pci_dev_get" },
	{ 0x7cb8cb5f, "pci_request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xb171ca46, "ipack_bus_register" },
	{ 0x82ab6ab7, "ipack_device_init" },
	{ 0xd2db9d20, "ipack_device_add" },
	{ 0x903e8731, "ipack_put_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x13b08d1c, "ipack_bus_unregister" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ipack");

MODULE_ALIAS("pci:v00001498d000030C8sv00001498sd0000300Abc*sc*i*");

MODULE_INFO(srcversion, "16FE3A7C1F990A62CD41FF8");
