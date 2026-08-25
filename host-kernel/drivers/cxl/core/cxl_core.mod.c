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

SYMBOL_CRC(is_root_decoder, 0x5ace3c4c, "_gpl");
SYMBOL_CRC(is_cxl_decoder, 0x8066cfa6, "_gpl");
SYMBOL_CRC(to_cxl_decoder, 0x8e5bdc93, "_gpl");
SYMBOL_CRC(is_cxl_port, 0x5c865d30, "_gpl");
SYMBOL_CRC(to_cxl_port, 0xff4ba120, "_gpl");
SYMBOL_CRC(devm_cxl_add_port, 0x3aa44ed5, "_gpl");
SYMBOL_CRC(cxl_port_to_pci_bus, 0x0e4f8a12, "_gpl");
SYMBOL_CRC(devm_cxl_register_pci_bus, 0xa072c71c, "_gpl");
SYMBOL_CRC(find_cxl_root, 0xe0a75486, "_gpl");
SYMBOL_CRC(devm_cxl_add_dport, 0x23a07715, "_gpl");
SYMBOL_CRC(cxl_endpoint_autoremove, 0x5aaa59be, "_gpl");
SYMBOL_CRC(devm_cxl_enumerate_ports, 0x88f1cc05, "_gpl");
SYMBOL_CRC(cxl_mem_find_port, 0xde0001e9, "_gpl");
SYMBOL_CRC(cxl_find_dport_by_dev, 0xda529bdd, "_gpl");
SYMBOL_CRC(cxl_root_decoder_alloc, 0xa05b3bab, "_gpl");
SYMBOL_CRC(cxl_switch_decoder_alloc, 0x60170eef, "_gpl");
SYMBOL_CRC(cxl_endpoint_decoder_alloc, 0x3af55a88, "_gpl");
SYMBOL_CRC(cxl_decoder_add_locked, 0x8f93c381, "_gpl");
SYMBOL_CRC(cxl_decoder_add, 0x3b1e766e, "_gpl");
SYMBOL_CRC(cxl_decoder_autoremove, 0x123d56f3, "_gpl");
SYMBOL_CRC(__cxl_driver_register, 0x7f00d276, "_gpl");
SYMBOL_CRC(cxl_driver_unregister, 0xbc31bd33, "_gpl");
SYMBOL_CRC(cxl_bus_rescan, 0x31fc64d2, "_gpl");
SYMBOL_CRC(schedule_cxl_memdev_detach, 0x297d0a47, "_gpl");
SYMBOL_CRC(cxl_bus_type, 0x571f27af, "_gpl");
SYMBOL_CRC(to_cxl_nvdimm_bridge, 0x6f4f0be3, "_gpl");
SYMBOL_CRC(is_cxl_nvdimm_bridge, 0x7611bbce, "_gpl");
SYMBOL_CRC(cxl_find_nvdimm_bridge, 0xf0330cff, "_gpl");
SYMBOL_CRC(devm_cxl_add_nvdimm_bridge, 0x1ced2f38, "_gpl");
SYMBOL_CRC(is_cxl_nvdimm, 0x66a3f1ee, "_gpl");
SYMBOL_CRC(to_cxl_nvdimm, 0xc77c36bf, "_gpl");
SYMBOL_CRC(devm_cxl_add_nvdimm, 0x43694967, "_gpl");
SYMBOL_CRC(cxl_probe_component_regs, 0x97ccc282, "_gpl");
SYMBOL_CRC(cxl_probe_device_regs, 0x6f3148e1, "_gpl");
SYMBOL_CRC(cxl_map_component_regs, 0xfbdc7a3d, "_gpl");
SYMBOL_CRC(cxl_map_device_regs, 0xa446c503, "_gpl");
SYMBOL_CRC(cxl_find_regblock, 0xbdb6dbf3, "_gpl");
SYMBOL_CRC(is_cxl_memdev, 0xeb55b07d, "_gpl");
SYMBOL_CRC(set_exclusive_cxl_commands, 0xd6ececba, "_gpl");
SYMBOL_CRC(clear_exclusive_cxl_commands, 0x1fe97fc1, "_gpl");
SYMBOL_CRC(devm_cxl_add_memdev, 0xa418d353, "_gpl");
SYMBOL_CRC(cxl_mbox_send_cmd, 0x0121a49d, "_gpl");
SYMBOL_CRC(cxl_enumerate_cmds, 0x291866a4, "_gpl");
SYMBOL_CRC(cxl_dev_state_identify, 0x3274edae, "_gpl");
SYMBOL_CRC(cxl_mem_create_range_info, 0xec580ef0, "_gpl");
SYMBOL_CRC(cxl_dev_state_create, 0xfe61ec2f, "_gpl");
SYMBOL_CRC(devm_cxl_port_enumerate_dports, 0xf56929eb, "_gpl");
SYMBOL_CRC(cxl_await_media_ready, 0xd5fd0a1f, "_gpl");
SYMBOL_CRC(cxl_hdm_decode_init, 0x9fcc31c8, "_gpl");
SYMBOL_CRC(devm_cxl_add_passthrough_decoder, 0x9bc8f710, "_gpl");
SYMBOL_CRC(devm_cxl_setup_hdm, 0x5c538aa0, "_gpl");
SYMBOL_CRC(devm_cxl_enumerate_decoders, 0x148e4619, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0x67735685, "cdev_device_del" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x90576ec4, "vmemdup_user" },
	{ 0x37a0cba, "kfree" },
	{ 0xa40a8382, "get_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x57bc19d2, "down_write" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce807a25, "up_write" },
	{ 0x4465655e, "debugfs_create_bool" },
	{ 0x84909a73, "bus_find_device" },
	{ 0x48098f3, "device_add" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x94875775, "devm_release_action" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x17f55d32, "bus_rescan_devices" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x668b19a1, "down_read" },
	{ 0x7dcf4135, "__xa_insert" },
	{ 0x745a981, "xa_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x5f99383a, "ioread64_hi_lo" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5b83def, "pci_walk_bus" },
	{ 0xb2bc638b, "pci_find_dvsec_capability" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x31795ba9, "device_release_driver" },
	{ 0x77358855, "iomem_resource" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x53b954a2, "up_read" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0xf9a482f9, "msleep" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x791a408b, "pci_bus_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "524743FAB8FD7A9AA227626");
