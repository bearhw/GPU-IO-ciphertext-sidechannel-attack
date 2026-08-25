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

SYMBOL_CRC(sdw_bus_type, 0x7e0a21f7, "_gpl");
SYMBOL_CRC(__sdw_register_driver, 0x50609272, "_gpl");
SYMBOL_CRC(sdw_unregister_driver, 0xeda5a94d, "_gpl");
SYMBOL_CRC(sdw_bus_master_add, 0xcd7ee133, "");
SYMBOL_CRC(sdw_bus_master_delete, 0x7aa6c261, "");
SYMBOL_CRC(sdw_write_no_pm, 0x416a08cd, "");
SYMBOL_CRC(sdw_bread_no_pm_unlocked, 0xa863499d, "");
SYMBOL_CRC(sdw_bwrite_no_pm_unlocked, 0x51f14c4e, "");
SYMBOL_CRC(sdw_read_no_pm, 0x0f400bd6, "");
SYMBOL_CRC(sdw_update_no_pm, 0x082effd5, "");
SYMBOL_CRC(sdw_update, 0x471e3d3f, "");
SYMBOL_CRC(sdw_nread, 0x6e8cf0b1, "");
SYMBOL_CRC(sdw_nwrite, 0x98184b5a, "");
SYMBOL_CRC(sdw_read, 0x7203206f, "");
SYMBOL_CRC(sdw_write, 0xa34dfbd8, "");
SYMBOL_CRC(sdw_compare_devid, 0x38b17471, "");
SYMBOL_CRC(sdw_extract_slave_id, 0xcade3366, "");
SYMBOL_CRC(sdw_bus_prep_clk_stop, 0xa1202929, "");
SYMBOL_CRC(sdw_bus_clk_stop, 0x23095ae2, "");
SYMBOL_CRC(sdw_bus_exit_clk_stop, 0xa1fea045, "");
SYMBOL_CRC(sdw_handle_slave_status, 0x19b16242, "");
SYMBOL_CRC(sdw_clear_slave_status, 0x66072b1a, "");
SYMBOL_CRC(sdw_slave_add, 0x741f5b96, "");
SYMBOL_CRC(sdw_master_read_prop, 0x3de0561a, "");
SYMBOL_CRC(sdw_slave_read_prop, 0x4c12afb8, "");
SYMBOL_CRC(sdw_rows, 0xf53ba0b8, "");
SYMBOL_CRC(sdw_cols, 0xba54b904, "");
SYMBOL_CRC(sdw_find_col_index, 0x60e31fbb, "");
SYMBOL_CRC(sdw_find_row_index, 0x1deee061, "");
SYMBOL_CRC(sdw_prepare_stream, 0x16d1706b, "");
SYMBOL_CRC(sdw_enable_stream, 0xbbec2c2e, "");
SYMBOL_CRC(sdw_disable_stream, 0x4cde88bf, "");
SYMBOL_CRC(sdw_deprepare_stream, 0x71891d59, "");
SYMBOL_CRC(sdw_alloc_stream, 0x9e122d79, "");
SYMBOL_CRC(sdw_startup_stream, 0x3b0a8582, "");
SYMBOL_CRC(sdw_shutdown_stream, 0x6f95b16b, "");
SYMBOL_CRC(sdw_release_stream, 0xda5bce09, "");
SYMBOL_CRC(sdw_stream_add_master, 0x6f8a5d30, "");
SYMBOL_CRC(sdw_stream_remove_master, 0xc7ec954c, "");
SYMBOL_CRC(sdw_stream_add_slave, 0xde6458a8, "");
SYMBOL_CRC(sdw_stream_remove_slave, 0x2563008d, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xbb726018, "device_property_present" },
	{ 0xa0eee428, "devm_device_add_groups" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x96848186, "scnprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x44b0ffb1, "dev_pm_domain_attach" },
	{ 0xc16cfc54, "devm_device_add_group" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcc9627d8, "pm_generic_runtime_resume" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xbea9f813, "dev_pm_domain_detach" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x99e1b417, "pm_generic_runtime_suspend" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x422066d2, "device_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0xf2b11959, "seq_read" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xd8cad17f, "fwnode_property_present" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x44b821fd, "device_get_named_child_node" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xbb2b861a, "single_release" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0xb82ba28c, "single_open" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "57845F3EFA9987F3E1F17C8");
