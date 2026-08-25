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
	{ 0x3fe3b715, "__srcu_read_lock" },
	{ 0x7ceaf0d5, "generic_handle_irq" },
	{ 0x66e38f89, "__srcu_read_unlock" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0xbb7cf14f, "irq_get_irq_data" },
	{ 0xfe5d8404, "synchronize_srcu" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x37a0cba, "kfree" },
	{ 0x10bf4c2c, "pci_find_host_bridge" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x9e52e1b8, "acpi_find_child_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x54cad769, "msi_desc_to_pci_dev" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7fa81482, "handle_untracked_irq" },
	{ 0x48d50025, "irq_domain_set_info" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xae121354, "pci_iomap" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0x82d4f86b, "pci_find_capability" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x1502df31, "pci_stop_root_bus" },
	{ 0x115e9968, "pci_remove_root_bus" },
	{ 0x5691349, "cleanup_srcu_struct" },
	{ 0xb8ebaa03, "irq_domain_remove" },
	{ 0xbe650167, "irq_domain_free_fwnode" },
	{ 0xffb7c514, "ida_free" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x63a6a014, "pcim_iomap" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x47b7e8e, "pci_find_next_bus" },
	{ 0x683cd46f, "pci_msix_vec_count" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0x7cab996a, "init_srcu_struct" },
	{ 0x27cdca93, "pci_add_resource" },
	{ 0x218e600b, "pci_add_resource_offset" },
	{ 0x7504ddee, "pci_create_root_bus" },
	{ 0x5bf3d85f, "pci_acpi_set_companion_lookup_hook" },
	{ 0xcbc41096, "pci_scan_child_bus" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xf23b6b77, "pci_reset_bus" },
	{ 0x4268445a, "pci_assign_unassigned_bus_resources" },
	{ 0x73515502, "pcie_bus_configure_settings" },
	{ 0x7e1b74de, "pci_bus_add_devices" },
	{ 0x7e7a47c9, "pci_acpi_clear_companion_lookup_hook" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x2587f789, "_dev_info" },
	{ 0xb69383cd, "__irq_domain_alloc_fwnode" },
	{ 0x196857ae, "pci_msi_create_irq_domain" },
	{ 0xe1659505, "irq_domain_update_bus_token" },
	{ 0x56470118, "__warn_printk" },
	{ 0x38a71b7e, "pci_free_resource_list" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d0000201Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000028C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000467Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004C3Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A77Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009A0Bsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "F19A6FA07F41CD986363959");
