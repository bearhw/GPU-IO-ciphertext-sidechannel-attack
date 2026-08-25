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
	{ 0x8bc8cc11, "config_group_init_type_name" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x12b44a14, "pci_epc_clear_bar" },
	{ 0x679724ab, "pci_epc_mem_free_addr" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x33ee0e47, "pci_epc_get_features" },
	{ 0x4cddcd62, "pci_epc_raise_irq" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x21fe55d2, "pci_epc_map_addr" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x704f39d4, "pci_epc_unmap_addr" },
	{ 0x19f2428b, "pci_epc_map_msi_irq" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xdbdacea6, "pci_epf_free_space" },
	{ 0x4686193, "pci_epc_remove_epf" },
	{ 0xd7417b3c, "pci_epc_put" },
	{ 0xb655f91b, "pci_epc_get_next_free_bar" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xec8bc50e, "pci_epf_alloc_space" },
	{ 0x71a8003, "pci_epc_set_bar" },
	{ 0x4be943d3, "pci_epc_set_msix" },
	{ 0xa2545720, "pci_epc_mem_alloc_addr" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xd400114d, "pci_epc_write_header" },
	{ 0xd8bbe6da, "pci_epc_set_msi" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x6fc06a98, "__pci_epf_register_driver" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x92997ed8, "_printk" },
	{ 0x97229c11, "pci_epf_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "4D6B4DE999DD683E6DAAE7A");
