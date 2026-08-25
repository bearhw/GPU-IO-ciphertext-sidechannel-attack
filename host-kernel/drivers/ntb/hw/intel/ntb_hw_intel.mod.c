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
	{ 0x2b44c0dc, "param_ops_ullong" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x9243b3bb, "ntb_link_event" },
	{ 0xce93cd8, "ntb_db_event" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xae121354, "pci_iomap" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0xd21c5139, "iowrite64_lo_hi" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x96848186, "scnprintf" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x20d8d10f, "pci_disable_msi" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x37a0cba, "kfree" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x848d372e, "iowrite8" },
	{ 0x54bf0e65, "pci_intx" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdf82259a, "pci_enable_msix_range" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x2587f789, "_dev_info" },
	{ 0x5b2439a7, "pci_select_bars" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6a59169d, "simple_open" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xfe052363, "ioread64_lo_hi" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x1949bb7c, "ntb_register_device" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xa5f5614b, "pci_disable_msix" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x162ac598, "ntb_unregister_device" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb");

MODULE_ALIAS("pci:v00008086d00003725sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003C0Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000E0Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002F0Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00006F0Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003726sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003C0Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000E0Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002F0Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00006F0Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003727sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003C0Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000E0Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002F0Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00006F0Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000201Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000347Esv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "DA0559B01D62B71DDFF375F");
