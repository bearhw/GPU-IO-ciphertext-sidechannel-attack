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

SYMBOL_CRC(admin_timeout, 0xd45434ee, "_gpl");
SYMBOL_CRC(nvme_io_timeout, 0x813cf212, "_gpl");
SYMBOL_CRC(nvme_wq, 0x64b62862, "_gpl");
SYMBOL_CRC(nvme_reset_wq, 0x49224181, "_gpl");
SYMBOL_CRC(nvme_delete_wq, 0xd58bbbcb, "_gpl");
SYMBOL_CRC(nvme_try_sched_reset, 0x2ee71002, "_gpl");
SYMBOL_CRC(nvme_reset_ctrl, 0x5884a7c6, "_gpl");
SYMBOL_CRC(nvme_delete_ctrl, 0x5c1ea997, "_gpl");
SYMBOL_CRC(nvme_complete_rq, 0x51189b95, "_gpl");
SYMBOL_CRC(nvme_complete_batch_req, 0xc67be5c0, "_gpl");
SYMBOL_CRC(nvme_host_path_error, 0xcd7bc297, "_gpl");
SYMBOL_CRC(nvme_cancel_request, 0x15cc8f51, "_gpl");
SYMBOL_CRC(nvme_cancel_tagset, 0xc65d01d6, "_gpl");
SYMBOL_CRC(nvme_cancel_admin_tagset, 0xa6fa380f, "_gpl");
SYMBOL_CRC(nvme_change_ctrl_state, 0x058b5116, "_gpl");
SYMBOL_CRC(nvme_wait_reset, 0x048b237a, "_gpl");
SYMBOL_CRC(nvme_put_ns, 0x9f6715de, "_gpl");
SYMBOL_CRC(nvme_init_request, 0x2c80cada, "_gpl");
SYMBOL_CRC(nvme_fail_nonready_command, 0x13fe63c1, "_gpl");
SYMBOL_CRC(__nvme_check_ready, 0x475dd3f4, "_gpl");
SYMBOL_CRC(nvme_cleanup_cmd, 0xe1c59fe2, "_gpl");
SYMBOL_CRC(nvme_setup_cmd, 0x794f1e8a, "_gpl");
SYMBOL_CRC(__nvme_submit_sync_cmd, 0xfc5c306e, "_gpl");
SYMBOL_CRC(nvme_submit_sync_cmd, 0x839b38eb, "_gpl");
SYMBOL_CRC(nvme_command_effects, 0x77c4117a, "_gpl");
SYMBOL_CRC(nvme_execute_passthru_rq, 0x310a6f4a, "_gpl");
SYMBOL_CRC(nvme_stop_keep_alive, 0x64a7c94f, "_gpl");
SYMBOL_CRC(nvme_set_features, 0x2aa0f75d, "_gpl");
SYMBOL_CRC(nvme_get_features, 0x66ab0f6e, "_gpl");
SYMBOL_CRC(nvme_set_queue_count, 0xdacabd45, "_gpl");
SYMBOL_CRC(nvme_sec_submit, 0x8a9c70ed, "_gpl");
SYMBOL_CRC(nvme_disable_ctrl, 0xd8895d42, "_gpl");
SYMBOL_CRC(nvme_enable_ctrl, 0x81904f3e, "_gpl");
SYMBOL_CRC(nvme_shutdown_ctrl, 0x2cd4b76e, "_gpl");
SYMBOL_CRC(nvme_init_ctrl_finish, 0x783ce71c, "_gpl");
SYMBOL_CRC(nvme_find_get_ns, 0xf16db61d, "_gpl");
SYMBOL_CRC(nvme_remove_namespaces, 0xc0f68dd3, "_gpl");
SYMBOL_CRC(nvme_complete_async_event, 0x91acb249, "_gpl");
SYMBOL_CRC(nvme_stop_ctrl, 0x8b425fa4, "_gpl");
SYMBOL_CRC(nvme_start_ctrl, 0x63b29a7a, "_gpl");
SYMBOL_CRC(nvme_uninit_ctrl, 0x134ef5bd, "_gpl");
SYMBOL_CRC(nvme_init_ctrl, 0xa7876cad, "_gpl");
SYMBOL_CRC(nvme_kill_queues, 0x73436831, "_gpl");
SYMBOL_CRC(nvme_unfreeze, 0x34e555f1, "_gpl");
SYMBOL_CRC(nvme_wait_freeze_timeout, 0xfe86c1f0, "_gpl");
SYMBOL_CRC(nvme_wait_freeze, 0x485b1a27, "_gpl");
SYMBOL_CRC(nvme_start_freeze, 0xa11cd276, "_gpl");
SYMBOL_CRC(nvme_stop_queues, 0xde11df5f, "_gpl");
SYMBOL_CRC(nvme_start_queues, 0x2aa4e901, "_gpl");
SYMBOL_CRC(nvme_stop_admin_queue, 0xe18ddc1f, "_gpl");
SYMBOL_CRC(nvme_start_admin_queue, 0x00ab128a, "_gpl");
SYMBOL_CRC(nvme_sync_io_queues, 0xf0047107, "_gpl");
SYMBOL_CRC(nvme_sync_queues, 0x6857b57e, "_gpl");
SYMBOL_CRC(nvme_ctrl_from_file, 0xedb26570, "_gpl");
SYMBOL_CRC(__tracepoint_nvme_sq, 0x5e9a1b55, "_gpl");
SYMBOL_CRC(__traceiter_nvme_sq, 0x962ff269, "_gpl");
SYMBOL_CRC(__SCK__tp_func_nvme_sq, 0x5ba48502, "_gpl");
SYMBOL_CRC(__SCT__tp_func_nvme_sq, 0x3bf2393a, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x2287440d, "set_capacity_and_notify" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x273aff5c, "__SCT__tp_func_block_bio_remap" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xd2e83b51, "set_disk_ro" },
	{ 0x56232755, "__blk_alloc_disk" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xb3626ae6, "blk_integrity_register" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xc72d9306, "device_remove_file_self" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x81088473, "blk_queue_logical_block_size" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x172a2f5a, "ext_pi_type3_crc64" },
	{ 0x525d0aa3, "trace_seq_printf" },
	{ 0x31e8f817, "disk_update_readahead" },
	{ 0xd5c36791, "dev_pm_qos_expose_latency_tolerance" },
	{ 0x88330529, "device_add_disk" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0xd8c57a53, "blk_mq_tagset_wait_completed_request" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0xadd992bd, "import_iovec" },
	{ 0x67735685, "cdev_device_del" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xaf510a5f, "blk_mq_unquiesce_queue" },
	{ 0xbce4d380, "t10_pi_type1_crc" },
	{ 0x17dd96bd, "blk_queue_dma_alignment" },
	{ 0x51e587e4, "blk_mq_quiesce_queue" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x550f2827, "ext_pi_type1_crc64" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0xae04012c, "__vmalloc" },
	{ 0x3496c7a, "blk_queue_write_cache" },
	{ 0xa8694ecd, "kblockd_schedule_work" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x5d9a993c, "disk_uevent" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xfe5d8404, "synchronize_srcu" },
	{ 0x3c872672, "param_ops_byte" },
	{ 0xa40a8382, "get_device" },
	{ 0x34e1053e, "blk_mq_end_request" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xa84e677a, "__blk_mq_alloc_disk" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9493fc86, "node_states" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xb7e30117, "blk_integrity_unregister" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x984089b1, "blk_mq_delay_kick_requeue_list" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1b5f4377, "trace_seq_putc" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x39978da, "put_disk" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0xe17756cf, "dev_pm_qos_update_user_latency_tolerance" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x7ee04d80, "blk_queue_physical_block_size" },
	{ 0xe46bdec8, "blk_execute_rq" },
	{ 0x3197c4e3, "put_device" },
	{ 0x490ef36f, "blk_queue_max_zone_append_sectors" },
	{ 0xa916b694, "strnlen" },
	{ 0xeae84dbe, "blk_queue_flag_set" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x1d2915ac, "blk_mq_free_request" },
	{ 0x618911fc, "numa_node" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7f7f63c2, "blk_rq_map_kern" },
	{ 0xc6cbbc89, "capable" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0xf12c728b, "t10_pi_type3_crc" },
	{ 0x800473f, "__cond_resched" },
	{ 0x46c47fb6, "__node_distance" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x40897392, "blk_rq_map_user" },
	{ 0x7cab996a, "init_srcu_struct" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x1cd42933, "__SCK__tp_func_block_bio_remap" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xf3cbc0a8, "blk_revalidate_disk_zones" },
	{ 0xce807a25, "up_write" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x48098f3, "device_add" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0xa26854e7, "blk_execute_rq_nowait" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x3fe3b715, "__srcu_read_lock" },
	{ 0x6297f232, "hwmon_device_register_with_info" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xe3f3d437, "set_capacity" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x58b1e30a, "blk_sync_queue" },
	{ 0x7f60d7d7, "bio_integrity_add_page" },
	{ 0x5a921311, "strncmp" },
	{ 0x87a33d0f, "__SCK__tp_func_block_bio_complete" },
	{ 0x6dcf857f, "uuid_null" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x64e22c65, "blk_mq_alloc_request_hctx" },
	{ 0x386865d5, "blk_mq_alloc_request" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa9c639c, "blk_stack_limits" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x8f381413, "del_gendisk" },
	{ 0xb2aabc17, "blk_queue_max_discard_sectors" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x5691349, "cleanup_srcu_struct" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd0ebc22, "bio_integrity_alloc" },
	{ 0x1b939763, "blk_queue_max_discard_segments" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbfc0d310, "blk_set_stacking_limits" },
	{ 0x44bc2694, "blk_mq_freeze_queue_wait_timeout" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x3312881b, "device_del" },
	{ 0x815fda83, "sed_ioctl" },
	{ 0xbd73e725, "blk_queue_set_zoned" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x3526e0bf, "blk_mq_wait_quiesce_done" },
	{ 0xd2ce8dc4, "blk_queue_max_segments" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x63eac261, "io_uring_cmd_done" },
	{ 0xc101110e, "blk_rq_unmap_user" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0xf474fdcb, "kfree_const" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x745a981, "xa_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x5d55b1be, "blk_queue_virt_boundary" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xd0693c90, "blk_mq_complete_request" },
	{ 0xb9d30d26, "blk_queue_chunk_sectors" },
	{ 0x156d36c0, "blk_queue_max_write_zeroes_sectors" },
	{ 0xf2ab7f33, "blk_mq_freeze_queue" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xd9491c14, "xa_destroy" },
	{ 0x3e3ab402, "blk_freeze_queue_start" },
	{ 0x4a0766b1, "dev_pm_qos_hide_latency_tolerance" },
	{ 0x8fa25c24, "xa_find" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xf036ebdf, "__tracepoint_block_bio_complete" },
	{ 0x8e14dea3, "blk_queue_split" },
	{ 0x5b3e282f, "xa_store" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xf8730f8f, "blk_queue_io_min" },
	{ 0x66e38f89, "__srcu_read_unlock" },
	{ 0x7be82b14, "hwmon_device_unregister" },
	{ 0xba97195a, "__tracepoint_block_bio_remap" },
	{ 0x923db2ab, "blk_mq_unfreeze_queue" },
	{ 0xb9d4cc93, "blk_mq_tagset_busy_iter" },
	{ 0x12bbbc57, "blk_rq_map_user_iov" },
	{ 0xb5c4e0ab, "blk_cleanup_disk" },
	{ 0xdf36914b, "xa_find_after" },
	{ 0xbb146a4b, "blk_queue_max_hw_sectors" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xbe374d76, "blk_mark_disk_dead" },
	{ 0x754d539c, "strlen" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xa6deb5b6, "blk_mq_freeze_queue_wait" },
	{ 0x84502a47, "blk_status_to_errno" },
	{ 0x35e03f29, "blk_queue_io_opt" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x2569f74, "blk_cleanup_queue" },
	{ 0x53b954a2, "up_read" },
	{ 0xc39b8467, "blk_mq_requeue_request" },
	{ 0x6c4b60d, "io_uring_cmd_complete_in_task" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x4e144a54, "__SCT__tp_func_block_bio_complete" },
	{ 0x330097fc, "blk_steal_bios" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "514C6A55F967650F099174F");
