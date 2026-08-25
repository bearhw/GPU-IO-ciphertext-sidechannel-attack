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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa6257a2f, "complete" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7f326be9, "pci_create_slot" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x69acdf38, "memcpy" },
	{ 0x252c3d4c, "pci_msi_prepare" },
	{ 0xc0c4eb35, "pci_msi_mask_irq" },
	{ 0x35f03c12, "irq_chip_mask_parent" },
	{ 0x31e2e77f, "vmbus_free_mmio" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x2fd90375, "vmbus_sendpacket" },
	{ 0x37a0cba, "kfree" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0xddbeeecc, "pci_lock_rescan_remove" },
	{ 0x7e1b3ae2, "pci_stop_and_remove_bus_device" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x5790e7a0, "pci_unlock_rescan_remove" },
	{ 0x2bdd953a, "pci_destroy_slot" },
	{ 0x54cad769, "msi_desc_to_pci_dev" },
	{ 0xbc9b8cb4, "irqd_cfg" },
	{ 0x3fae6ab0, "hv_vp_index" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x6cb2f5a1, "cpumask_next_and" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x9bad141d, "hv_hypercall_pg" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x3cfe8604, "irq_chip_unmask_parent" },
	{ 0x5928cf59, "pci_msi_unmask_irq" },
	{ 0x211130c1, "alloc_cpumask_var" },
	{ 0x39b52d19, "__bitmap_and" },
	{ 0xb9c16f51, "hv_max_vp_index" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x2587f789, "_dev_info" },
	{ 0xa205065c, "vmbus_sendpacket_getid" },
	{ 0x95559393, "vmbus_request_addr_match" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xa3afc2c1, "vmbus_close" },
	{ 0xedc03953, "iounmap" },
	{ 0xb8ebaa03, "irq_domain_remove" },
	{ 0xbe650167, "irq_domain_free_fwnode" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x1502df31, "pci_stop_root_bus" },
	{ 0x115e9968, "pci_remove_root_bus" },
	{ 0x9493fc86, "node_states" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x4939ebcd, "numa_map_to_online_node" },
	{ 0x39d7c25d, "irq_domain_get_irq_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xcbc41096, "pci_scan_child_bus" },
	{ 0x261ce3f8, "vmbus_recvpacket_raw" },
	{ 0xb78c6323, "__vmbus_request_addr_match" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe3feba56, "tasklet_unlock_spin_wait" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x21ef374c, "try_wait_for_completion" },
	{ 0xb6cb556a, "_find_first_and_bit" },
	{ 0xf18176a5, "msi_lock_descs" },
	{ 0xc274a9d7, "msi_first_desc" },
	{ 0xae62ee9, "msi_next_desc" },
	{ 0xbb7cf14f, "irq_get_irq_data" },
	{ 0x35e01ad9, "msi_unlock_descs" },
	{ 0xeff80c3f, "vmbus_next_request_id" },
	{ 0x938f9a6e, "vmbus_request_addr" },
	{ 0x77f9ae61, "vmbus_open" },
	{ 0xc5b83def, "pci_walk_bus" },
	{ 0xda32199b, "devm_pci_alloc_host_bridge" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xc9a35505, "vmbus_allocate_mmio" },
	{ 0xde80cd09, "ioremap" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xb69383cd, "__irq_domain_alloc_fwnode" },
	{ 0xa1108294, "x86_vector_domain" },
	{ 0x45b2608e, "handle_edge_irq" },
	{ 0x196857ae, "pci_msi_create_irq_domain" },
	{ 0x26eb0662, "pci_scan_root_bus_bridge" },
	{ 0x823d9bcd, "pci_bus_assign_resources" },
	{ 0x7e1b74de, "pci_bus_add_devices" },
	{ 0x27cdca93, "pci_add_resource" },
	{ 0xcaff6dc5, "vmbus_driver_unregister" },
	{ 0xfb921e00, "hvpci_block_ops" },
	{ 0x90a9d8cc, "hv_is_hyperv_initialized" },
	{ 0x8f4947c8, "__vmbus_driver_register" },
	{ 0x18420867, "irq_chip_ack_parent" },
	{ 0x7268d3d8, "irq_chip_set_affinity_parent" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hv_vmbus,pci-hyperv-intf");

MODULE_ALIAS("vmbus:1df6c444444400449d52802e27ede19f");

MODULE_INFO(srcversion, "DF46FC39719DFA7BBCEC3F2");
