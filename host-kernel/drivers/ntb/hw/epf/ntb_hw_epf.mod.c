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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x162ac598, "ntb_unregister_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9243b3bb, "ntb_link_event" },
	{ 0xce93cd8, "ntb_db_event" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xae121354, "pci_iomap" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x1949bb7c, "ntb_register_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb");


MODULE_INFO(srcversion, "505260E7BD2384C56CF1C87");
