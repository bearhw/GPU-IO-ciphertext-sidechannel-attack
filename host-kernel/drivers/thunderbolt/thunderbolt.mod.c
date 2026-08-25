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

SYMBOL_CRC(__tb_ring_enqueue, 0x8f1d274f, "_gpl");
SYMBOL_CRC(tb_ring_poll, 0x3c44548d, "_gpl");
SYMBOL_CRC(tb_ring_poll_complete, 0x28a984a7, "_gpl");
SYMBOL_CRC(tb_ring_alloc_tx, 0x2f9ccc90, "_gpl");
SYMBOL_CRC(tb_ring_alloc_rx, 0x23f50afb, "_gpl");
SYMBOL_CRC(tb_ring_start, 0x76e1415d, "_gpl");
SYMBOL_CRC(tb_ring_stop, 0x5f86890f, "_gpl");
SYMBOL_CRC(tb_ring_free, 0x2c3a5977, "_gpl");
SYMBOL_CRC(tb_property_create_dir, 0x01d23ee1, "_gpl");
SYMBOL_CRC(tb_property_free_dir, 0x393b4f2f, "_gpl");
SYMBOL_CRC(tb_property_add_immediate, 0x658e3d97, "_gpl");
SYMBOL_CRC(tb_property_add_data, 0xa3d2b403, "_gpl");
SYMBOL_CRC(tb_property_add_text, 0xb7c7cdce, "_gpl");
SYMBOL_CRC(tb_property_add_dir, 0x8b62f95e, "_gpl");
SYMBOL_CRC(tb_property_remove, 0x785eb82c, "_gpl");
SYMBOL_CRC(tb_property_find, 0x4e5064a7, "_gpl");
SYMBOL_CRC(tb_property_get_next, 0x73ad2acb, "_gpl");
SYMBOL_CRC(tb_xdomain_response, 0x1737b136, "_gpl");
SYMBOL_CRC(tb_xdomain_request, 0xf475ec12, "_gpl");
SYMBOL_CRC(tb_register_protocol_handler, 0x4e64bdfd, "_gpl");
SYMBOL_CRC(tb_unregister_protocol_handler, 0xf76028c7, "_gpl");
SYMBOL_CRC(tb_register_service_driver, 0xbad2a958, "_gpl");
SYMBOL_CRC(tb_unregister_service_driver, 0xecb80866, "_gpl");
SYMBOL_CRC(tb_service_type, 0xa801f987, "_gpl");
SYMBOL_CRC(tb_xdomain_type, 0x465e13b2, "_gpl");
SYMBOL_CRC(tb_xdomain_lane_bonding_enable, 0xc7ddad03, "_gpl");
SYMBOL_CRC(tb_xdomain_lane_bonding_disable, 0x09276249, "_gpl");
SYMBOL_CRC(tb_xdomain_alloc_in_hopid, 0x63d23ce2, "_gpl");
SYMBOL_CRC(tb_xdomain_alloc_out_hopid, 0x2cab991a, "_gpl");
SYMBOL_CRC(tb_xdomain_release_in_hopid, 0x521e859c, "_gpl");
SYMBOL_CRC(tb_xdomain_release_out_hopid, 0x9b270998, "_gpl");
SYMBOL_CRC(tb_xdomain_enable_paths, 0x591b22aa, "_gpl");
SYMBOL_CRC(tb_xdomain_disable_paths, 0x7cf1d968, "_gpl");
SYMBOL_CRC(tb_xdomain_find_by_uuid, 0xd37f1fe6, "_gpl");
SYMBOL_CRC(tb_xdomain_find_by_route, 0x283f7c6b, "_gpl");
SYMBOL_CRC(tb_register_property_dir, 0xf1cfd1ff, "_gpl");
SYMBOL_CRC(tb_unregister_property_dir, 0x603249ed, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe914e41e, "strcpy" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xa7414e19, "pci_find_ext_capability" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xd9aa089e, "dma_pool_create" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xec2b8a42, "acpi_walk_namespace" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x77bc13a0, "strim" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcc39c03e, "nvmem_unregister" },
	{ 0x96848186, "scnprintf" },
	{ 0xe4933139, "dev_fwnode" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x69acdf38, "memcpy" },
	{ 0xf03e9b49, "component_del" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x556cca46, "x86_apple_machine" },
	{ 0xf06dd93f, "fwnode_property_get_reference_args" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x50cf7585, "hex2bin" },
	{ 0x678b96ec, "dma_pool_alloc" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xb6af5afe, "pm_wakeup_dev_event" },
	{ 0x1e180698, "register_acpi_bus_type" },
	{ 0x1000e51, "schedule" },
	{ 0x9e52e1b8, "acpi_find_child_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x3197c4e3, "put_device" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x12411375, "device_for_each_child_reverse" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x800473f, "__cond_resched" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xae5a04bb, "acpi_evaluate_dsm" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd7fea2a8, "device_wakeup_enable" },
	{ 0x755b14b4, "crypto_shash_setkey" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x84909a73, "bus_find_device" },
	{ 0x48098f3, "device_add" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xf235f72e, "device_property_read_u8_array" },
	{ 0x2f7754a8, "dma_pool_free" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc823584a, "pci_device_is_present" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x6dcf857f, "uuid_null" },
	{ 0x6983b40b, "crypto_shash_digest" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x422066d2, "device_register" },
	{ 0x3312881b, "device_del" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x223bb837, "unregister_acpi_bus_type" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xfc31675f, "acpi_get_first_physical_node" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xba1008c8, "__crc32c_le" },
	{ 0xb67fec0e, "uuid_parse" },
	{ 0x352e7e70, "pm_runtime_no_callbacks" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x42635d55, "pm_suspend_global_flags" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0x7129a6f4, "osc_sb_native_usb4_support_confirmed" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb5aa7165, "dma_pool_destroy" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x999e8297, "vfree" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4087b19f, "acpi_fetch_acpi_dev" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xd7269c64, "osc_sb_native_usb4_control" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0xddc3d4e9, "device_iommu_capable" },
	{ 0x391de184, "seq_puts" },
	{ 0xbb2b861a, "single_release" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xc5b83def, "pci_walk_bus" },
	{ 0xdd18a993, "acpi_check_dsm" },
	{ 0x8a97a36e, "nvmem_register" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x5f9564a, "component_add" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0xb82ba28c, "single_open" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xbacc0824, "crypto_alloc_shash" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xeb2ecf81, "device_link_add" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x791a408b, "pci_bus_type" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d00001513sv00002222sd00001111bc08sc80i00*");
MODULE_ALIAS("pci:v00008086d00001547sv00002222sd00001111bc08sc80i00*");
MODULE_ALIAS("pci:v00008086d0000156Asv*sd*bc08sc80i00*");
MODULE_ALIAS("pci:v00008086d0000156Csv*sd*bc08sc80i00*");
MODULE_ALIAS("pci:v00008086d00001575sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001577sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015DDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015BFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015DCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015D9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015D2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015DEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015E8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015EBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008A17sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008A0Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009A1Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009A1Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009A1Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009A21sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000463Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000466Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v*d*sv*sd*bc0Csc03i40*");

MODULE_INFO(srcversion, "475A96697657542E9107B57");
