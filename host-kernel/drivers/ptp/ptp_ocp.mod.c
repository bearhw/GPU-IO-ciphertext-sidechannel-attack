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
	{ 0xa78af5f3, "ioread32" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x754d539c, "strlen" },
	{ 0x96b29254, "strncasecmp" },
	{ 0x9c6f9221, "i2c_verify_client" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x45b514fb, "ptp_clock_event" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb82ba28c, "single_open" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe914e41e, "strcpy" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7380dffa, "argv_split" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0xe0b13336, "argv_free" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x77fef0b9, "i2c_verify_adapter" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xd2c5f70, "__clk_hw_register_fixed_rate" },
	{ 0xc9a31b37, "devm_clk_hw_register_clkdev" },
	{ 0x7aa09d09, "serial8250_register_8250_port" },
	{ 0x6e3347ec, "devlink_priv" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0x4c41c60, "devlink_flash_update_status_notify" },
	{ 0xbd6841d4, "crc16" },
	{ 0x5c45e3e3, "mtd_write" },
	{ 0x5e4d33dd, "mtd_erase" },
	{ 0x365acda7, "set_normalized_timespec64" },
	{ 0x8349a895, "nvmem_device_put" },
	{ 0xe1454e77, "nvmem_device_find" },
	{ 0xc697b0f7, "nvmem_device_read" },
	{ 0x90688bcd, "devlink_info_driver_name_put" },
	{ 0xb1647fc2, "devlink_info_version_running_put" },
	{ 0x2c66ac85, "devlink_info_serial_number_put" },
	{ 0x607c4683, "devlink_info_version_fixed_put" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x5779794, "pci_request_irq" },
	{ 0x37a0cba, "kfree" },
	{ 0x262d940b, "device_find_child_by_name" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x593cec66, "sysfs_create_groups" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x5a170ade, "ptp_clock_index" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xd1606395, "sysfs_remove_groups" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x8da72a19, "pci_free_irq" },
	{ 0xcefcd99a, "serial8250_unregister_port" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x941a3d4f, "clk_hw_unregister_fixed_rate" },
	{ 0x85f6adc3, "ptp_clock_unregister" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0x715a43ce, "priv_to_devlink" },
	{ 0x946c0028, "devlink_unregister" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x660eb6bd, "devlink_free" },
	{ 0x7c6024bd, "init_net" },
	{ 0x853e3913, "devlink_alloc_ns" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x48098f3, "device_add" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x81db095, "ptp_clock_register" },
	{ 0xf597132c, "pps_lookup_dev" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x2587f789, "_dev_info" },
	{ 0xc498bdc9, "devlink_register" },
	{ 0xa1600c1b, "__class_register" },
	{ 0xde37f64f, "i2c_bus_type" },
	{ 0x3318cdf8, "bus_register_notifier" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xa9cec9e6, "bus_unregister_notifier" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x92997ed8, "_printk" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xf2b11959, "seq_read" },
	{ 0xbb2b861a, "single_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mtd");

MODULE_ALIAS("pci:v00001D9Bd00000400sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000018D4d00001008sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "21FDE680F4ED8EE6D3D7F5E");
