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

SYMBOL_CRC(greybus_disabled, 0x15d1942f, "_gpl");
SYMBOL_CRC(greybus_register_driver, 0xb3ff8350, "_gpl");
SYMBOL_CRC(greybus_deregister_driver, 0x0f478be6, "_gpl");
SYMBOL_CRC(gb_debugfs_get, 0x8638d295, "_gpl");
SYMBOL_CRC(__tracepoint_gb_hd_create, 0x4ad777fb, "_gpl");
SYMBOL_CRC(__traceiter_gb_hd_create, 0x647d8388, "_gpl");
SYMBOL_CRC(__SCK__tp_func_gb_hd_create, 0xfa99ed9a, "_gpl");
SYMBOL_CRC(__SCT__tp_func_gb_hd_create, 0xadd7926d, "_gpl");
SYMBOL_CRC(__tracepoint_gb_hd_release, 0xf1cc9474, "_gpl");
SYMBOL_CRC(__traceiter_gb_hd_release, 0xaca90ed7, "_gpl");
SYMBOL_CRC(__SCK__tp_func_gb_hd_release, 0xcbc98b20, "_gpl");
SYMBOL_CRC(__SCT__tp_func_gb_hd_release, 0xae877457, "_gpl");
SYMBOL_CRC(__tracepoint_gb_hd_add, 0xa1bbb037, "_gpl");
SYMBOL_CRC(__traceiter_gb_hd_add, 0x5001b428, "_gpl");
SYMBOL_CRC(__SCK__tp_func_gb_hd_add, 0x71597ded, "_gpl");
SYMBOL_CRC(__SCT__tp_func_gb_hd_add, 0xe6b45fb6, "_gpl");
SYMBOL_CRC(__tracepoint_gb_hd_del, 0x5f7ea03a, "_gpl");
SYMBOL_CRC(__traceiter_gb_hd_del, 0x405ef15f, "_gpl");
SYMBOL_CRC(__SCK__tp_func_gb_hd_del, 0x8f9c6de0, "_gpl");
SYMBOL_CRC(__SCT__tp_func_gb_hd_del, 0xbfb52284, "_gpl");
SYMBOL_CRC(__tracepoint_gb_hd_in, 0xe004051c, "_gpl");
SYMBOL_CRC(__traceiter_gb_hd_in, 0xe97a9154, "_gpl");
SYMBOL_CRC(__SCK__tp_func_gb_hd_in, 0x62df28f9, "_gpl");
SYMBOL_CRC(__SCT__tp_func_gb_hd_in, 0x10d1b03e, "_gpl");
SYMBOL_CRC(__tracepoint_gb_message_submit, 0x89f3c06c, "_gpl");
SYMBOL_CRC(__traceiter_gb_message_submit, 0x9aa71bf6, "_gpl");
SYMBOL_CRC(__SCK__tp_func_gb_message_submit, 0x619d9123, "_gpl");
SYMBOL_CRC(__SCT__tp_func_gb_message_submit, 0x78fedb98, "_gpl");
SYMBOL_CRC(gb_hd_output, 0xd16081fd, "_gpl");
SYMBOL_CRC(gb_hd_cport_reserve, 0x2442786b, "_gpl");
SYMBOL_CRC(gb_hd_cport_release_reserved, 0x2d767457, "_gpl");
SYMBOL_CRC(gb_hd_create, 0xadff1dc0, "_gpl");
SYMBOL_CRC(gb_hd_add, 0xd55dc9aa, "_gpl");
SYMBOL_CRC(gb_hd_del, 0xd88dd44a, "_gpl");
SYMBOL_CRC(gb_hd_shutdown, 0x5383d660, "_gpl");
SYMBOL_CRC(gb_hd_put, 0x6b7ee9c4, "_gpl");
SYMBOL_CRC(gb_interface_request_mode_switch, 0xb81122ab, "_gpl");
SYMBOL_CRC(greybus_data_rcvd, 0xbe3cb384, "_gpl");
SYMBOL_CRC(gb_connection_create, 0x36d1eff3, "_gpl");
SYMBOL_CRC(gb_connection_create_flags, 0x46aeb630, "_gpl");
SYMBOL_CRC(gb_connection_create_offloaded, 0x30310382, "_gpl");
SYMBOL_CRC(gb_connection_enable, 0x0ce6882b, "_gpl");
SYMBOL_CRC(gb_connection_enable_tx, 0x8fdece1d, "_gpl");
SYMBOL_CRC(gb_connection_disable_rx, 0x744a694c, "_gpl");
SYMBOL_CRC(gb_connection_disable, 0x935f99b5, "_gpl");
SYMBOL_CRC(gb_connection_disable_forced, 0x17d60ffe, "_gpl");
SYMBOL_CRC(gb_connection_destroy, 0x0ec7deae, "_gpl");
SYMBOL_CRC(gb_connection_latency_tag_enable, 0xc2a63cfa, "_gpl");
SYMBOL_CRC(gb_connection_latency_tag_disable, 0x7eea8c25, "_gpl");
SYMBOL_CRC(gb_svc_intf_set_power_mode, 0x3ef99298, "_gpl");
SYMBOL_CRC(gb_operation_result, 0x2172cc1e, "_gpl");
SYMBOL_CRC(gb_operation_response_alloc, 0xcfbbf513, "_gpl");
SYMBOL_CRC(gb_operation_create_flags, 0x0df8a03b, "_gpl");
SYMBOL_CRC(gb_operation_get_payload_size_max, 0x5fa6f50f, "_gpl");
SYMBOL_CRC(gb_operation_get, 0x982ee6e8, "_gpl");
SYMBOL_CRC(gb_operation_put, 0x9a26ebc6, "_gpl");
SYMBOL_CRC(gb_operation_request_send, 0xfdedfbf2, "_gpl");
SYMBOL_CRC(gb_operation_request_send_sync_timeout, 0x7463fb2d, "_gpl");
SYMBOL_CRC(greybus_message_sent, 0x8f364c9c, "_gpl");
SYMBOL_CRC(gb_operation_cancel, 0x492acd4e, "_gpl");
SYMBOL_CRC(gb_operation_sync_timeout, 0xc9528eaf, "_gpl");
SYMBOL_CRC(gb_operation_unidirectional_timeout, 0xc1c5c569, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x96848186, "scnprintf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x7681946c, "unregister_pm_notifier" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xfe5d8404, "synchronize_srcu" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0xb0101402, "sysfs_notify" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x3197c4e3, "put_device" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x48098f3, "device_add" },
	{ 0x24d273d1, "add_timer" },
	{ 0xa7eedcc4, "call_usermodehelper" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x9cc4f70a, "register_pm_notifier" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0xf1e046cc, "panic" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x3312881b, "device_del" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0xfca3d3cf, "tracepoint_srcu" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x131db64a, "system_long_wq" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x56470118, "__warn_printk" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xc487b792, "bus_register" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "67E3FA7E61A11BD14904BF4");
