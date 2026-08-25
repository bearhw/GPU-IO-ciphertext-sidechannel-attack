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
	{ 0xddbeeecc, "pci_lock_rescan_remove" },
	{ 0x7e1b3ae2, "pci_stop_and_remove_bus_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xfb15a750, "pci_remove_bus" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x5790e7a0, "pci_unlock_rescan_remove" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0xbc99281e, "xenbus_free_evtchn" },
	{ 0x9b651e51, "xenbus_teardown_ring" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7b89c8b9, "pci_claim_resource" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x65162719, "pci_get_slot" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xe241560, "pci_scan_single_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x45d14bdf, "hypercall_page" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x8cda8029, "xen_clear_irq_pending" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x642eb5c6, "xen_poll_irq_timeout" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xc274a9d7, "msi_first_desc" },
	{ 0xae62ee9, "msi_next_desc" },
	{ 0x92997ed8, "_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x579205ff, "xenbus_setup_ring" },
	{ 0xe7650b7, "xenbus_alloc_evtchn" },
	{ 0x34eab46d, "bind_evtchn_to_irqhandler" },
	{ 0x52431348, "xenbus_transaction_start" },
	{ 0x6aa2a877, "xenbus_printf" },
	{ 0x732852fe, "xenbus_transaction_end" },
	{ 0x4fe00144, "xenbus_dev_fatal" },
	{ 0x24fec4ac, "xenbus_switch_state" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x27cdca93, "pci_add_resource" },
	{ 0x77358855, "iomem_resource" },
	{ 0x9493fc86, "node_states" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x992dd812, "pci_scan_root_bus" },
	{ 0x38a71b7e, "pci_free_resource_list" },
	{ 0xc5b83def, "pci_walk_bus" },
	{ 0x7e1b74de, "pci_bus_add_devices" },
	{ 0x2d4784f6, "pci_find_bus" },
	{ 0xd72feba2, "xenbus_read_driver_state" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x758c97af, "is_swiotlb_active" },
	{ 0x6502d9c2, "xenbus_scanf" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc6572a90, "xenbus_read_unsigned" },
	{ 0x539f157b, "pci_xen_swiotlb_init_late" },
	{ 0xf969b534, "xenbus_dev_error" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x54ea6dfe, "xen_start_flags" },
	{ 0x85cb2c45, "xen_has_pv_devices" },
	{ 0x9e68408f, "xen_pci_frontend" },
	{ 0x15b5ef2e, "__xenbus_register_frontend" },
	{ 0x9ee2b870, "xenbus_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E09C10B3203A427FC4B6A37");
