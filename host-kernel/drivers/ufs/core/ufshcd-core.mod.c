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

SYMBOL_CRC(ufshcd_dump_regs, 0x36180f05, "_gpl");
SYMBOL_CRC(ufshcd_delay_us, 0x723b1abf, "_gpl");
SYMBOL_CRC(ufshcd_get_local_unipro_ver, 0x4dfb99b6, "");
SYMBOL_CRC(ufshcd_hold, 0x96937243, "_gpl");
SYMBOL_CRC(ufshcd_release, 0x01c0a316, "_gpl");
SYMBOL_CRC(ufshcd_clkgate_delay_set, 0x97428fde, "_gpl");
SYMBOL_CRC(ufshcd_map_desc_id_to_length, 0xa0683497, "");
SYMBOL_CRC(ufshcd_dme_configure_adapt, 0xdcbe8a30, "_gpl");
SYMBOL_CRC(ufshcd_dme_set_attr, 0xffacfb5c, "_gpl");
SYMBOL_CRC(ufshcd_dme_get_attr, 0x627b41ff, "_gpl");
SYMBOL_CRC(ufshcd_link_recovery, 0x991f08a7, "_gpl");
SYMBOL_CRC(ufshcd_uic_hibern8_enter, 0x0bd7f20d, "_gpl");
SYMBOL_CRC(ufshcd_uic_hibern8_exit, 0x75ce00e5, "_gpl");
SYMBOL_CRC(ufshcd_auto_hibern8_update, 0x16660d1d, "_gpl");
SYMBOL_CRC(ufshcd_config_pwr_mode, 0x4cbd449d, "_gpl");
SYMBOL_CRC(ufshcd_make_hba_operational, 0xb5ae7068, "_gpl");
SYMBOL_CRC(ufshcd_hba_stop, 0xa1579d91, "_gpl");
SYMBOL_CRC(ufshcd_hba_enable, 0x06528b98, "_gpl");
SYMBOL_CRC(ufshcd_update_evt_hist, 0x987f90d3, "_gpl");
SYMBOL_CRC(ufshcd_fixup_dev_quirks, 0x9f200ee5, "_gpl");
SYMBOL_CRC(ufshcd_system_suspend, 0x6793c7d5, "");
SYMBOL_CRC(ufshcd_system_resume, 0x273346d7, "");
SYMBOL_CRC(ufshcd_runtime_suspend, 0xfc214ed2, "");
SYMBOL_CRC(ufshcd_runtime_resume, 0xf178f117, "");
SYMBOL_CRC(ufshcd_shutdown, 0x8d5c95f0, "");
SYMBOL_CRC(ufshcd_remove, 0x3b8dd3c3, "_gpl");
SYMBOL_CRC(ufshcd_dealloc_host, 0xaa30c322, "_gpl");
SYMBOL_CRC(ufshcd_alloc_host, 0x72794b15, "");
SYMBOL_CRC(ufshcd_init, 0x71928c32, "_gpl");
SYMBOL_CRC(ufshcd_resume_complete, 0xeb3130e2, "_gpl");
SYMBOL_CRC(__ufshcd_suspend_prepare, 0x891bf6cd, "_gpl");
SYMBOL_CRC(ufshcd_suspend_prepare, 0x3c9c5f65, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x90b0f1ed, "scsi_dma_map" },
	{ 0xa6a06c7b, "scsi_print_sense_hdr" },
	{ 0xe914e41e, "strcpy" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x9e6e92ab, "blk_crypto_reprogram_all_keys" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x5ba9c87f, "blk_crypto_keyslot_index" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x7102febc, "bsg_setup_queue" },
	{ 0xc5151506, "scsi_autopm_put_device" },
	{ 0xbc137caa, "scsi_device_get" },
	{ 0xcf30c2cf, "bio_add_pc_page" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x5c954338, "bsg_remove_queue" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x7fc07a65, "bsg_job_done" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xb27eb5df, "scsi_remove_host" },
	{ 0x4abb121f, "blk_rq_append_bio" },
	{ 0x4c75845f, "bpf_trace_run6" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x303f7652, "blk_pm_runtime_init" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x26f31ac4, "scsi_report_bus_reset" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xd1606395, "sysfs_remove_groups" },
	{ 0xcf2a6966, "up" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x593cec66, "sysfs_create_groups" },
	{ 0xa3563db1, "dev_pm_opp_add" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x69acdf38, "memcpy" },
	{ 0x478437e6, "scsi_dma_unmap" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x7630837e, "__scsi_iterate_devices" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x76d9b876, "clk_set_rate" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xe02ba436, "trace_print_hex_seq" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x30036fd4, "blk_mq_alloc_tag_set" },
	{ 0xdd60e91b, "devfreq_add_device" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xf5f370e0, "async_schedule_node" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1953c958, "mempool_create" },
	{ 0xf4c22b92, "scsi_register_driver" },
	{ 0x73118ed2, "blk_crypto_register" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x3197c4e3, "put_device" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x1d2915ac, "blk_mq_free_request" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0x43f81957, "clk_round_rate" },
	{ 0x23b4e0d7, "clear_page_rep" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x615911d7, "__bitmap_set" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x12e047bb, "scsi_device_put" },
	{ 0x2121e851, "device_create_file" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0xa09dd780, "bio_put" },
	{ 0x5b9bd9e0, "regulator_set_load" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x61d12418, "blk_queue_update_dma_alignment" },
	{ 0x6f1a753, "devfreq_remove_device" },
	{ 0x6ec3e817, "scsi_host_put" },
	{ 0xce807a25, "up_write" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x2aa0843e, "mempool_resize" },
	{ 0x48098f3, "device_add" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0xa26854e7, "blk_execute_rq_nowait" },
	{ 0xd4034828, "system_freezable_wq" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x6626afca, "down" },
	{ 0x7871e78, "bpf_trace_run5" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x952975b1, "dev_pm_opp_remove" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x8225558d, "sdev_prefix_printk" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x36eb54d3, "scsi_scan_host" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x925493f, "clear_page_orig" },
	{ 0xd985dc99, "mempool_free_pages" },
	{ 0x5a921311, "strncmp" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x51b7663e, "device_link_remove" },
	{ 0x386865d5, "blk_mq_alloc_request" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xa0ee8941, "blk_queue_update_dma_pad" },
	{ 0x9084b044, "clear_page_erms" },
	{ 0xb91a5868, "__scsi_execute" },
	{ 0x5a363f17, "blk_mq_free_tag_set" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3312881b, "device_del" },
	{ 0x2846b6e2, "bpf_trace_run9" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0xe30d04a4, "regulator_count_voltages" },
	{ 0x82ecb338, "scsi_is_host_device" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0xd713878c, "debugfs_create_u32" },
	{ 0x3c1ecf80, "blk_mq_init_queue" },
	{ 0xcecf053b, "scsi_device_quiesce" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x9fd03309, "scsi_autopm_get_device" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x26f89323, "scsi_print_command" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x839eb71c, "devfreq_suspend_device" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x87b8798d, "sg_next" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x9034a696, "mempool_destroy" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x4d4d7b79, "blk_mq_map_queues" },
	{ 0xabf32f29, "utf16s_to_utf8s" },
	{ 0xefce2322, "devm_blk_crypto_profile_init" },
	{ 0x636a2492, "no_llseek" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x18888d00, "downgrade_write" },
	{ 0x9d05c15c, "scsi_done" },
	{ 0xbb2b861a, "single_release" },
	{ 0xa84c174d, "scsi_unblock_requests" },
	{ 0x905695ab, "sg_copy_from_buffer" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x65acf90c, "sbitmap_weight" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xb363452c, "scsi_remove_device" },
	{ 0xf856ea45, "scsi_block_requests" },
	{ 0x816fc9e7, "scsi_add_host_with_dma" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xb82ba28c, "single_open" },
	{ 0xe2cad31b, "scsi_host_alloc" },
	{ 0x1b17d541, "__scsi_add_device" },
	{ 0x4b0c5a, "devfreq_resume_device" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xeb2ecf81, "device_link_add" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x815588a6, "clk_enable" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0x2569f74, "blk_cleanup_queue" },
	{ 0x53b954a2, "up_read" },
	{ 0x17cef504, "scsi_change_queue_depth" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x5c26a53b, "wait_for_completion_io_timeout" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x766a0927, "mempool_alloc_pages" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "23C0386E614769C8B11C63A");
