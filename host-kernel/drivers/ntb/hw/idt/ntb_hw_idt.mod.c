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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0xdaf61130, "pci_disable_pcie_error_reporting" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x162ac598, "ntb_unregister_device" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9243b3bb, "ntb_link_event" },
	{ 0xce93cd8, "ntb_db_event" },
	{ 0xbe178a6d, "ntb_msg_event" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x96848186, "scnprintf" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x37a0cba, "kfree" },
	{ 0xf82d3dd4, "pcibios_resource_to_bus" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x9819ee8, "pci_enable_pcie_error_reporting" },
	{ 0x1181b820, "pci_aer_clear_nonfatal_status" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xfe9e8a82, "pcim_iomap_regions_request_all" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xa18fad6a, "devm_hwmon_device_register_with_groups" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x1949bb7c, "ntb_register_device" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x92997ed8, "_printk" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x6a59169d, "simple_open" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb");

MODULE_ALIAS("pci:v0000111Dd00008091sv*sd*bc06sc80i*");
MODULE_ALIAS("pci:v0000111Dd0000808Fsv*sd*bc06sc80i*");
MODULE_ALIAS("pci:v0000111Dd00008088sv*sd*bc06sc80i*");
MODULE_ALIAS("pci:v0000111Dd00008092sv*sd*bc06sc80i*");
MODULE_ALIAS("pci:v0000111Dd00008090sv*sd*bc06sc80i*");
MODULE_ALIAS("pci:v0000111Dd0000808Esv*sd*bc06sc80i*");
MODULE_ALIAS("pci:v0000111Dd0000808Csv*sd*bc06sc80i*");
MODULE_ALIAS("pci:v0000111Dd0000808Asv*sd*bc06sc80i*");

MODULE_INFO(srcversion, "C9D77CBE467562A270892D3");
