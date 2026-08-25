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
	{ 0x5d2ee6d8, "ttm_bo_vm_dummy_page" },
	{ 0x9f596732, "drm_mode_is_420_also" },
	{ 0x7b7d5de5, "drm_atomic_private_obj_init" },
	{ 0xd4ee4030, "drm_dp_mst_topology_mgr_set_mst" },
	{ 0x33de6ac, "drm_dp_mst_reset_vcpi_slots" },
	{ 0x6b980b08, "kobject_del" },
	{ 0xedcf81ce, "drm_dp_channel_eq_ok" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x98dc7e7, "drm_is_current_master" },
	{ 0x85479ed4, "dma_buf_fd" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x396abd95, "drm_modeset_lock_all_ctx" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x5a05660c, "drm_aperture_remove_conflicting_pci_framebuffers" },
	{ 0x9b54fd62, "dma_buf_unpin" },
	{ 0x750122e9, "pci_load_saved_state" },
	{ 0x5a826a51, "drm_atomic_helper_crtc_reset" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xf89c0ce4, "drm_atomic_helper_update_plane" },
	{ 0xa46ee521, "drm_dp_mst_atomic_enable_dsc" },
	{ 0x97820a51, "dma_resv_iter_first" },
	{ 0x999e8297, "vfree" },
	{ 0xeff5715a, "drm_dp_mst_connector_late_register" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x5642d92d, "drm_atomic_helper_plane_duplicate_state" },
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0xba6ad1ba, "drm_crtc_handle_vblank" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0xd0f9fa29, "dma_resv_reserve_fences" },
	{ 0x7c173634, "__bitmap_complement" },
	{ 0x7ae22c04, "drm_gem_dmabuf_vmap" },
	{ 0x7023bea8, "unregister_acpi_notifier" },
	{ 0x90e2c790, "mmu_interval_notifier_insert_locked" },
	{ 0x16cdc340, "acpi_get_table" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x6a4f623b, "mmu_notifier_synchronize" },
	{ 0x1668523a, "drm_get_edid" },
	{ 0xdabccc74, "devm_request_free_mem_region" },
	{ 0x90e6b950, "pcie_capability_write_word" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0x3e2ef244, "drm_plane_create_rotation_property" },
	{ 0x781b12e8, "kthread_park" },
	{ 0xf82ec573, "rb_prev" },
	{ 0x685a0458, "amd_iommu_device_info" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0x84545be, "pcie_aspm_enabled" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0xbf66365c, "ttm_resource_init" },
	{ 0xb39a9773, "dma_resv_replace_fences" },
	{ 0x7936a8e5, "iommu_iova_to_phys" },
	{ 0x4833b272, "drm_fb_helper_output_poll_changed" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0xa9e668b8, "__mmdrop" },
	{ 0xae0ebf2f, "pci_store_saved_state" },
	{ 0xb302156f, "drm_hdmi_vendor_infoframe_from_display_mode" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x81b038dd, "find_get_pid" },
	{ 0x9ce050be, "drm_mode_copy" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xf0850137, "devm_memremap_pages" },
	{ 0x2e880445, "pcie_get_readrq" },
	{ 0x2846b6e2, "bpf_trace_run9" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x62f7e207, "down_read_killable" },
	{ 0x11089ac7, "_ctype" },
	{ 0x87b8798d, "sg_next" },
	{ 0x2e80b5ac, "ww_mutex_unlock" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x42a7681, "drm_gem_dmabuf_mmap" },
	{ 0x2b5845f7, "drm_dp_set_subconnector_property" },
	{ 0xa5389eb1, "debugfs_create_x32" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x8b860418, "drm_dp_mst_atomic_check" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x4e2cb4a5, "drm_atomic_helper_update_legacy_modeset_state" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0xbf8f8a2e, "drm_dp_mst_topology_mgr_destroy" },
	{ 0x2d9e9583, "drm_buddy_print" },
	{ 0xf881a8b, "ttm_bo_vm_reserve" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0xf53089ee, "drm_modeset_unlock_all" },
	{ 0x7d08011a, "__drm_atomic_helper_plane_duplicate_state" },
	{ 0x94d738ba, "mmu_notifier_put" },
	{ 0xca9360b5, "rb_next" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0x4722e83c, "drm_property_create_enum" },
	{ 0x37cc15c4, "sync_file_create" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0x96848186, "scnprintf" },
	{ 0xc6cbbc89, "capable" },
	{ 0xd1f60a89, "arch_io_free_memtype_wc" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x1d048b89, "drm_syncobj_create" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x4c75845f, "bpf_trace_run6" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x7871e78, "bpf_trace_run5" },
	{ 0xc5eb3e89, "drm_atomic_get_crtc_state" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xcbcd095f, "ttm_bo_move_memcpy" },
	{ 0xa20c8e78, "drm_set_preferred_mode" },
	{ 0x84aa95fc, "__put_task_struct" },
	{ 0x8e21c9a1, "dma_fence_add_callback" },
	{ 0x18888d00, "downgrade_write" },
	{ 0xb35e608e, "ttm_device_clear_dma_mappings" },
	{ 0x1f7cd8ac, "drm_dp_send_real_edid_checksum" },
	{ 0x731c4a9c, "dma_fence_signal" },
	{ 0x4940ba3b, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x2f5c461b, "drm_atomic_helper_resume" },
	{ 0x12362d9f, "cpu_info" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x10795da2, "__put_page" },
	{ 0xdab5a1eb, "interval_tree_insert" },
	{ 0x896ca658, "dma_resv_iter_next" },
	{ 0xe1fb555d, "drm_modeset_lock" },
	{ 0x93636f65, "dma_map_sgtable" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x3122d93a, "drm_prime_gem_destroy" },
	{ 0x8d701329, "drm_dp_clock_recovery_ok" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x5f947ff5, "ttm_bo_vm_open" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xb2c7417f, "ttm_range_man_init_nocheck" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xfe5d8404, "synchronize_srcu" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0xded3c0c0, "drm_kms_helper_connector_hotplug_event" },
	{ 0xcd8ce890, "acpi_format_exception" },
	{ 0xdd4ebf05, "drm_cvt_mode" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xc9b3280a, "pm_runtime_autosuspend_expiration" },
	{ 0x8fede48e, "vm_mmap" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x13f26ae, "dma_fence_get_stub" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xb91fc7c5, "dma_resv_test_signaled" },
	{ 0x917cf0ca, "drm_gem_prime_export" },
	{ 0x6d6e2f6b, "drm_crtc_vblank_on" },
	{ 0x9714e0bb, "ktime_get_raw" },
	{ 0x87587652, "drm_sched_entity_push_job" },
	{ 0x26815dbc, "drm_dp_link_rate_to_bw_code" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xcf2c1175, "__drm_atomic_helper_crtc_duplicate_state" },
	{ 0x98c039dc, "dma_fence_wait_timeout" },
	{ 0x582f248e, "drm_dp_get_adjust_request_pre_emphasis" },
	{ 0x5586a8a5, "migrate_vma_setup" },
	{ 0x2557cec4, "drm_sched_fault" },
	{ 0xd371ae64, "drm_crtc_vblank_count" },
	{ 0x1c12c32, "cpu_bit_bitmap" },
	{ 0x983b9baa, "perf_pmu_unregister" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x3c098824, "drm_dp_mst_topology_state_funcs" },
	{ 0xfb578fc5, "memset" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xe7a843a5, "dma_buf_move_notify" },
	{ 0xc8884d94, "dma_map_resource" },
	{ 0x5fdf7b32, "smca_get_bank_type" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x7bdc215a, "mmu_interval_notifier_insert" },
	{ 0xb82ba28c, "single_open" },
	{ 0x94c6f681, "ttm_sg_tt_init" },
	{ 0x7df03617, "debugfs_create_blob" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x24038c2f, "vga_switcheroo_register_client" },
	{ 0x19188f3f, "drm_sched_suspend_timeout" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x98378a1d, "cc_mkdec" },
	{ 0x9b9de1c1, "drm_edid_header_is_valid" },
	{ 0xe091538c, "__drm_atomic_helper_connector_reset" },
	{ 0x56256e8a, "orderly_poweroff" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0xc5c99a79, "drm_dp_get_adjust_request_voltage" },
	{ 0x3ab83a50, "drm_sched_init" },
	{ 0x87f588c0, "drm_plane_create_blend_mode_property" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x87bae58b, "ttm_bo_init_reserved" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x76dfe01, "drm_connector_attach_vrr_capable_property" },
	{ 0xe40f7318, "drm_atomic_commit" },
	{ 0x9c81e7bc, "drm_atomic_helper_crtc_duplicate_state" },
	{ 0x3cdc37e9, "drm_edid_to_speaker_allocation" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xc81ac9fd, "drm_sched_dependency_optimized" },
	{ 0xb0e602eb, "memmove" },
	{ 0x779447df, "pci_map_rom" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x4daa750d, "drm_sched_job_arm" },
	{ 0x1ef899d1, "drm_mode_crtc_set_gamma_size" },
	{ 0x969b0ebd, "dma_buf_pin" },
	{ 0x48091b40, "ttm_bo_vm_access" },
	{ 0x2d6931b8, "drm_sched_job_init" },
	{ 0xa5c450c9, "pci_pr3_present" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x5a921311, "strncmp" },
	{ 0x1a0f57db, "drm_crtc_helper_set_mode" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x7be82b14, "hwmon_device_unregister" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0xd0f82335, "dma_buf_put" },
	{ 0xf20b7eac, "ww_mutex_trylock" },
	{ 0x704ea0a4, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0xa15e1675, "drm_gem_object_release" },
	{ 0x4ec54e78, "bitmap_to_arr32" },
	{ 0x7f05725d, "drm_open" },
	{ 0x7f4ed11, "task_active_pid_ns" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xe914e41e, "strcpy" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x9c35a889, "dma_resv_wait_timeout" },
	{ 0xb8b2b1f7, "mce_register_decode_chain" },
	{ 0x34880f3a, "sysfs_remove_files" },
	{ 0xe7e97b44, "drm_dp_mst_get_port_malloc" },
	{ 0x800473f, "__cond_resched" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x5a290250, "hdmi_drm_infoframe_pack_only" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0x53b954a2, "up_read" },
	{ 0xa203e539, "irq_create_mapping_affinity" },
	{ 0x97ed721b, "perf_event_update_userpage" },
	{ 0x60409e8d, "drm_atomic_helper_disable_plane" },
	{ 0x6baadd76, "drm_crtc_vblank_off" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0xc5ca5a49, "drm_atomic_add_affected_connectors" },
	{ 0xce807a25, "up_write" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0xb0012962, "backlight_device_set_brightness" },
	{ 0x55c76a23, "ksys_sync_helper" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x87fc4c8e, "seq_hex_dump" },
	{ 0x979833d1, "pci_unmap_rom" },
	{ 0x73011db0, "drm_dp_bw_code_to_link_rate" },
	{ 0xe0d608c6, "drm_dp_atomic_release_vcpi_slots" },
	{ 0x25c249fe, "vga_switcheroo_register_handler" },
	{ 0x54470317, "drm_syncobj_find_fence" },
	{ 0x922f45a6, "__bitmap_clear" },
	{ 0xa916b694, "strnlen" },
	{ 0x3b5d3474, "ttm_resource_fini" },
	{ 0x6093e836, "drm_dp_dpcd_read_link_status" },
	{ 0x6ae84b98, "amd_iommu_bind_pasid" },
	{ 0x214e9884, "ttm_bo_eviction_valuable" },
	{ 0x2fd44381, "pcie_set_readrq" },
	{ 0x15c5fb81, "debugfs_lookup" },
	{ 0x63799c0f, "sysfs_create_file_ns" },
	{ 0xaf303877, "drm_dp_mst_add_affected_dsc_crtcs" },
	{ 0x696478f1, "drm_helper_mode_fill_fb_struct" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x1795dcff, "vga_switcheroo_unregister_client" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xea124bd1, "gcd" },
	{ 0x7da05f2e, "mfd_remove_devices" },
	{ 0xd5ae4903, "drm_sched_entity_init" },
	{ 0x4b7ebf95, "drm_mm_remove_node" },
	{ 0xb11364ca, "drm_sched_entity_flush" },
	{ 0xa86fee46, "drm_connector_list_iter_end" },
	{ 0xf7f48002, "migrate_vma_pages" },
	{ 0xd9491c14, "xa_destroy" },
	{ 0x20ec69d6, "drm_atomic_helper_wait_for_flip_done" },
	{ 0x7c7e1b58, "drm_atomic_helper_crtc_destroy_state" },
	{ 0xf7acb66, "drm_mm_print" },
	{ 0x16d6b792, "drm_dp_mst_deallocate_vcpi" },
	{ 0x22d53779, "drm_buddy_free_list" },
	{ 0x59c4b9de, "drm_helper_hpd_irq_event" },
	{ 0x1bab7272, "mfd_add_devices" },
	{ 0x879b0adc, "drm_crtc_vblank_helper_get_vblank_timestamp" },
	{ 0x228dfabf, "drm_dp_start_crc" },
	{ 0x28779e52, "drm_printf" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x8bd0e29f, "drm_crtc_arm_vblank_event" },
	{ 0x59bf89d9, "drm_modeset_backoff" },
	{ 0x1f9907f7, "__tracepoint_mmap_lock_start_locking" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0x435f223e, "drm_gem_handle_create" },
	{ 0x9f44c898, "drm_buddy_init" },
	{ 0x5151da72, "drm_poll" },
	{ 0xa885c7cd, "debugfs_create_file_size" },
	{ 0x8ca2d9e4, "drm_dp_calc_pbn_mode" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x983b9cc, "ttm_pool_alloc" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xb9cad492, "__drm_atomic_state_free" },
	{ 0x6626afca, "down" },
	{ 0xcad20cf7, "ttm_bo_validate" },
	{ 0xb481db6, "generic_handle_domain_irq" },
	{ 0x58d8fcaa, "drm_dsc_pps_payload_pack" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2121e851, "device_create_file" },
	{ 0x3b91c516, "ttm_tt_fini" },
	{ 0x3277b8f2, "ttm_resource_free" },
	{ 0x2522a243, "ttm_range_man_fini_nocheck" },
	{ 0xa6257a2f, "complete" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xcf3cfbce, "ttm_eu_fence_buffer_objects" },
	{ 0x6b7bb67b, "i2c_add_adapter" },
	{ 0x2e2d522c, "pcie_get_mps" },
	{ 0x19249204, "drm_syncobj_add_point" },
	{ 0xa084749a, "__bitmap_or" },
	{ 0x8eaf2a5f, "vga_switcheroo_unregister_handler" },
	{ 0xd9b4753, "drm_mode_equal" },
	{ 0xd4c14632, "system_unbound_wq" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0xd96babb4, "interval_tree_iter_next" },
	{ 0xc6eed989, "pci_get_class" },
	{ 0x47b8942d, "debugfs_create_file_unsafe" },
	{ 0x7c545285, "drm_edid_get_monitor_name" },
	{ 0xcef6fc7a, "ww_mutex_lock_interruptible" },
	{ 0x37a0cba, "kfree" },
	{ 0x5b2f27fb, "do_wait_intr" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xc30378af, "drm_dp_link_train_clock_recovery_delay" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0x2b9bf108, "ttm_resource_manager_init" },
	{ 0x18585875, "drm_dp_mst_connector_early_unregister" },
	{ 0x1b074f, "mce_is_correctable" },
	{ 0xa047c1fd, "ttm_bo_mem_space" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x349cba85, "strchr" },
	{ 0xee91879b, "rb_first_postorder" },
	{ 0x16dee44d, "dma_fence_init" },
	{ 0x43a90f84, "drm_atomic_get_plane_state" },
	{ 0x4e68e9be, "rb_next_postorder" },
	{ 0xa9c72303, "amd_iommu_pc_get_max_banks" },
	{ 0x3505be55, "drm_atomic_helper_page_flip" },
	{ 0xa1bedd72, "amd_iommu_pc_get_max_counters" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x51d58e8, "dma_fence_wait_any_timeout" },
	{ 0x7f4618bc, "drm_atomic_helper_check_planes" },
	{ 0xce5dc9de, "amd_iommu_set_invalidate_ctx_cb" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0x29a1933, "drm_connector_set_path_property" },
	{ 0xe5259331, "drm_atomic_helper_check_plane_state" },
	{ 0x2eca9998, "sysfs_remove_bin_file" },
	{ 0x5c000d78, "kobject_init" },
	{ 0x4575a0ca, "drm_mode_set_crtcinfo" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x377bbcbc, "pm_suspend_target_state" },
	{ 0xcd72be06, "__folio_lock" },
	{ 0x34d85f84, "drm_sched_stop" },
	{ 0x6e2b016f, "mmput" },
	{ 0x811842bf, "drm_dp_aux_register" },
	{ 0x29ad8e33, "x86_hyper_type" },
	{ 0x33f0768c, "cpufreq_quick_get_max" },
	{ 0x7c92bd35, "drm_framebuffer_init" },
	{ 0x593b6030, "ww_mutex_lock" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0xffae8e8b, "nsecs_to_jiffies" },
	{ 0x9ae33487, "pci_rebar_get_possible_sizes" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7f24de73, "jiffies_to_usecs" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0x156905cb, "drm_syncobj_get_handle" },
	{ 0x2ceb7f28, "drm_sched_job_cleanup" },
	{ 0x56470118, "__warn_printk" },
	{ 0x77358855, "iomem_resource" },
	{ 0x380eaa4, "dma_buf_unmap_attachment" },
	{ 0x46ed28d8, "fget" },
	{ 0x35552f56, "drm_atomic_helper_cleanup_planes" },
	{ 0x88ab6fe3, "kgdb_active" },
	{ 0x618911fc, "numa_node" },
	{ 0xff748b76, "drm_buddy_alloc_blocks" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x1a63af34, "vga_switcheroo_process_delayed_switch" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x4a92cbb6, "drm_calc_timestamping_constants" },
	{ 0x73234ae0, "pcie_bandwidth_available" },
	{ 0x94e87f42, "vga_switcheroo_init_domain_pm_ops" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0xce214ed5, "ttm_bo_move_accel_cleanup" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x9493fc86, "node_states" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd5d074ec, "sysfs_create_bin_file" },
	{ 0x3d463af9, "ttm_eu_backoff_reservation" },
	{ 0x7bc56a8b, "drm_connector_attach_max_bpc_property" },
	{ 0x2c208607, "power_supply_is_system_supplied" },
	{ 0xa508e139, "migrate_vma_finalize" },
	{ 0x631ba0f2, "sysfs_create_files" },
	{ 0x23af578f, "default_llseek" },
	{ 0xf03e9b49, "component_del" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xa94a09bb, "mem_section" },
	{ 0x683cd46f, "pci_msix_vec_count" },
	{ 0x51d9d03f, "drm_connector_unregister" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xc823584a, "pci_device_is_present" },
	{ 0x2683bf95, "ttm_bo_wait" },
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0x615911d7, "__bitmap_set" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0xf7019105, "ttm_resource_manager_usage" },
	{ 0x6b0cd993, "__get_task_comm" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x10f74645, "pid_task" },
	{ 0xe8eb5b88, "kset_register" },
	{ 0xbe27b66f, "dma_resv_get_fences" },
	{ 0xf52f864, "kthread_use_mm" },
	{ 0xdf2c2742, "rb_last" },
	{ 0x85493d2f, "drm_plane_create_alpha_property" },
	{ 0x504aff0f, "ttm_bo_put" },
	{ 0x668b19a1, "down_read" },
	{ 0xff06df37, "ttm_bo_lock_delayed_workqueue" },
	{ 0xc3efa62a, "drm_dp_aux_init" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0xd28f6a7f, "fput" },
	{ 0xb58cb534, "amd_iommu_free_device" },
	{ 0x54ea6dfe, "xen_start_flags" },
	{ 0x2ef6745b, "param_ops_bint" },
	{ 0x7c983a5d, "dmi_walk" },
	{ 0x416c1e62, "drm_gem_fb_destroy" },
	{ 0xa12673be, "ttm_bo_vm_close" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x37b00400, "drm_sched_resubmit_jobs" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0xc972c6c0, "drm_any_plane_has_format" },
	{ 0x2773c485, "__wake_up_locked" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xc01d25e9, "drm_vblank_init" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x24f14039, "__mmap_lock_do_trace_start_locking" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x39ef08f1, "dma_buf_dynamic_attach" },
	{ 0x7060c59b, "drm_connector_set_panel_orientation_with_quirk" },
	{ 0x1fdb397e, "ttm_bo_set_bulk_move" },
	{ 0x81808c2b, "dma_buf_get" },
	{ 0x13d0adf7, "__kfifo_out" },
	{ 0x336a7c69, "vga_switcheroo_fini_domain_pm_ops" },
	{ 0x7036edd9, "drm_dp_mst_topology_mgr_suspend" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x576efa0c, "__devm_release_region" },
	{ 0x20978fb9, "idr_find" },
	{ 0xd1753559, "mmu_interval_read_begin" },
	{ 0x9753a8e8, "vga_client_register" },
	{ 0xc30d71cc, "drm_buddy_block_print" },
	{ 0xdf6e4e77, "drm_atomic_get_connector_state" },
	{ 0x2c7b324e, "drm_dp_stop_crc" },
	{ 0xd0c05159, "emergency_restart" },
	{ 0xb692d1b9, "node_data" },
	{ 0xb290ada, "dma_fence_chain_walk" },
	{ 0x2295bc93, "drm_kms_helper_poll_init" },
	{ 0x2930e6f3, "drm_dp_cec_unregister_connector" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0x828e22f4, "hrtimer_forward" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x79245dac, "drm_atomic_helper_check_modeset" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x9c39e13a, "pcie_capability_read_dword" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x1d5f28de, "hmm_range_fault" },
	{ 0x7b2e2166, "drm_vma_node_revoke" },
	{ 0x19ad1a2e, "drm_modeset_acquire_fini" },
	{ 0x44002f02, "drm_connector_attach_hdr_output_metadata_property" },
	{ 0x973fa82e, "register_acpi_notifier" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xfd98a590, "find_vma" },
	{ 0xc567e846, "irq_set_chip_and_handler_name" },
	{ 0xabceb1cb, "drm_crtc_send_vblank_event" },
	{ 0x79cc14e8, "unmap_mapping_range" },
	{ 0x92ec510d, "jiffies64_to_msecs" },
	{ 0xc392bf7, "kobject_init_and_add" },
	{ 0x57698a50, "drm_mm_takedown" },
	{ 0x89eeeec3, "pcie_get_speed_cap" },
	{ 0xaa236b40, "drm_connector_atomic_hdr_metadata_equal" },
	{ 0xcaa1bbdd, "drm_dp_mst_dump_topology" },
	{ 0x411535ae, "__drm_atomic_helper_plane_reset" },
	{ 0xc83b983b, "kthread_unuse_mm" },
	{ 0x5a4734d1, "drm_kms_helper_is_poll_worker" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xfd4eec47, "drm_gem_dmabuf_release" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0x9b285573, "drm_match_cea_mode" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xf2b11959, "seq_read" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xde80cd09, "ioremap" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0xde913a0e, "to_drm_sched_fence" },
	{ 0xaebd12f0, "acpi_get_name" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x3a52132a, "drm_dp_mst_allocate_vcpi" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0xe123f3d9, "dma_fence_release" },
	{ 0xcb1ad332, "drm_sched_resubmit_jobs_ext" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xce4063de, "drm_dp_mst_dsc_aux_for_port" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x73965ef6, "i2c_new_client_device" },
	{ 0xe6af0549, "sysfs_add_file_to_group" },
	{ 0xcb2693a0, "drm_crtc_add_crc_entry" },
	{ 0x2587f789, "_dev_info" },
	{ 0xe870b85f, "pm_genpd_add_device" },
	{ 0xca9beaa4, "__xa_store" },
	{ 0xae277372, "__drm_crtc_commit_free" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x9f4f2aa3, "acpi_gbl_FADT" },
	{ 0x80961b33, "drm_mode_config_cleanup" },
	{ 0x3ad392f0, "mmu_notifier_get_locked" },
	{ 0x976c8ec7, "drm_mode_create_scaling_mode_property" },
	{ 0xea8ee118, "drm_simple_encoder_init" },
	{ 0x44e182e6, "__drm_atomic_helper_private_obj_duplicate_state" },
	{ 0xdf6feb47, "ttm_bo_unlock_delayed_workqueue" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8b59c4e8, "ttm_bo_kunmap" },
	{ 0x364850b1, "down_write_killable" },
	{ 0x120b336a, "__rb_insert_augmented" },
	{ 0x3082b526, "drm_encoder_cleanup" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x6aa20a82, "drm_sched_start" },
	{ 0x228fe49f, "ttm_eu_reserve_buffers" },
	{ 0x46c47fb6, "__node_distance" },
	{ 0x1ad236c2, "drm_sched_entity_modify_sched" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfdfb792f, "amd_iommu_pc_supported" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x35a69950, "__drm_atomic_helper_connector_destroy_state" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x9bc9f8fe, "drm_object_attach_property" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0xd6c98df1, "drm_dp_cec_unset_edid" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x3fe3b715, "__srcu_read_lock" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xb0c01ee9, "drm_dp_dpcd_write" },
	{ 0x807919c, "pci_ignore_hotplug" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x47283066, "drm_connector_list_iter_begin" },
	{ 0xc310b981, "strnstr" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x16a53381, "ttm_pool_debugfs" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xca8ff46f, "drm_dp_dpcd_read" },
	{ 0xb64b4823, "drm_atomic_helper_commit_hw_done" },
	{ 0x45ac8202, "_dev_emerg" },
	{ 0x2330f595, "drm_gem_object_lookup" },
	{ 0x188236aa, "dma_unmap_resource" },
	{ 0x389ef8e9, "drm_mode_is_420_only" },
	{ 0xbe1ed923, "handle_simple_irq" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0xa22bfbdd, "vma_alloc_folio" },
	{ 0x6daa08ae, "sysfs_remove_file_from_group" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x1a411479, "drm_syncobj_free" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x47cfd825, "kstrtouint_from_user" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x636a2492, "no_llseek" },
	{ 0xbd8bbd97, "fd_install" },
	{ 0xb55c053f, "drm_connector_init_with_ddc" },
	{ 0x8a28f53b, "drm_crtc_enable_color_mgmt" },
	{ 0x248c29c8, "drm_universal_plane_init" },
	{ 0xaf0cf195, "drm_dp_mst_get_edid" },
	{ 0x7f13c7b5, "drm_dp_mst_topology_mgr_init" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x3dc37960, "drm_gem_dmabuf_vunmap" },
	{ 0xaa0c318b, "vscnprintf" },
	{ 0x76f7ec51, "__drm_atomic_helper_connector_duplicate_state" },
	{ 0x20ee561, "ttm_bo_pin" },
	{ 0x2d8ca4a3, "put_pid" },
	{ 0x25750a11, "perf_pmu_register" },
	{ 0xe69b5422, "drm_sched_entity_set_priority" },
	{ 0xbc835e6c, "ttm_lru_bulk_move_tail" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa2b8d0d4, "drm_add_modes_noedid" },
	{ 0x152407ec, "drm_atomic_add_affected_planes" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xfa150882, "drm_buddy_fini" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0xe8598702, "drm_dp_mst_topology_mgr_resume" },
	{ 0xcf2a6966, "up" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0xb6127243, "drm_need_swiotlb" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x9b53e14, "interval_tree_remove" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x45d246da, "node_to_cpumask_map" },
	{ 0x86490580, "current_task" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x8b0d7462, "drm_dp_aux_unregister" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0xaea842cd, "drm_atomic_helper_suspend" },
	{ 0xabdc439, "cc_platform_has" },
	{ 0x2230f774, "drm_dp_update_payload_part2" },
	{ 0xabb5a026, "drm_buddy_block_trim" },
	{ 0x8472f0d3, "drm_dp_update_payload_part1" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0xce6f93af, "pci_reset_function" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x58ab7f99, "get_task_mm" },
	{ 0x554ac3d, "drm_crtc_cleanup" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0x6d1c8700, "drm_primary_helper_destroy" },
	{ 0xded32ea9, "ttm_bo_kmap" },
	{ 0xf6d59ef0, "dma_fence_array_create" },
	{ 0x905089da, "iommu_get_domain_for_dev" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x97d52e9c, "drm_atomic_state_alloc" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0xd34792b, "drm_send_event_locked" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x64e66cf1, "drm_atomic_helper_async_check" },
	{ 0xa59d3ac7, "drm_atomic_helper_plane_destroy_state" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xeb013674, "drm_dp_mst_put_port_malloc" },
	{ 0x58f58fff, "drm_kms_helper_poll_enable" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0xcd91b127, "system_highpri_wq" },
	{ 0x86d6c57d, "drm_connector_attach_dp_subconnector_property" },
	{ 0x9975dc22, "acpi_get_handle" },
	{ 0xa11ff8d2, "drm_modeset_unlock" },
	{ 0x1000e51, "schedule" },
	{ 0x551bd071, "__rb_erase_color" },
	{ 0x809712ff, "hdmi_avi_infoframe_pack" },
	{ 0xe71c4fef, "send_sig" },
	{ 0x29a6cfc9, "drm_syncobj_get_fd" },
	{ 0x6694dd27, "drm_crtc_accurate_vblank_count" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x5fd62d78, "get_task_pid" },
	{ 0x95352ea6, "kobject_set_name" },
	{ 0xc7d04fc5, "drm_vma_node_allow" },
	{ 0x392663c0, "amd_iommu_unbind_pasid" },
	{ 0x7727ca0b, "drm_object_property_set_value" },
	{ 0xa0761407, "drm_modeset_acquire_init" },
	{ 0x556422b3, "ioremap_cache" },
	{ 0xbb3f494, "ttm_glob" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x5da0bdb4, "mmu_interval_notifier_remove" },
	{ 0x83d18779, "drm_dp_mst_hpd_irq" },
	{ 0x57bc19d2, "down_write" },
	{ 0x391de184, "seq_puts" },
	{ 0x1cd8438b, "pxm_to_node" },
	{ 0x33da23c4, "drm_release" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0x4465655e, "debugfs_create_bool" },
	{ 0x650ab4d5, "amd_iommu_init_device" },
	{ 0xf0517d7a, "drm_mm_init" },
	{ 0xfac59a30, "drm_dp_atomic_find_vcpi_slots" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x6472c126, "drm_sched_pick_best" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xb2f30866, "drm_helper_force_disable_all" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xcfb8f52a, "kobject_add" },
	{ 0xd713878c, "debugfs_create_u32" },
	{ 0x132f2fb1, "kthread_unpark" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x85d31dc3, "drm_gem_ttm_vmap" },
	{ 0xf1b5340a, "drm_mode_vrefresh" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xfe12bcb9, "drm_dsc_compute_rc_parameters" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x3713299c, "hwmon_device_register_with_groups" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0x256c11fa, "drm_dp_cec_register_connector" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xad993d48, "pci_wait_for_pending_transaction" },
	{ 0xc9ff5b23, "__task_pid_nr_ns" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x148653, "vsnprintf" },
	{ 0x12dff28a, "drm_sched_reset_karma" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0x92997ed8, "_printk" },
	{ 0xf5984138, "pci_resize_resource" },
	{ 0xe919abb8, "drm_plane_create_color_properties" },
	{ 0x6dd47092, "drm_fb_helper_set_suspend_unlocked" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb7da87a8, "drm_fb_helper_lastclose" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x1cf416e2, "drm_hdcp_update_content_protection" },
	{ 0xdc4b8ad0, "drm_dp_mst_detect_port" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0xab86734c, "drm_gem_ttm_mmap" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x3cc58122, "drm_sched_entity_destroy" },
	{ 0x9e9eab95, "devcgroup_check_permission" },
	{ 0x4f18a150, "__drm_debug" },
	{ 0x2f2f1e5a, "dma_resv_add_fence" },
	{ 0x89023912, "drm_encoder_init" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0xf9a482f9, "msleep" },
	{ 0x98f6a292, "ttm_device_init" },
	{ 0xf1421d13, "drm_mode_sort" },
	{ 0x837aefe, "pm_genpd_remove_device" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x92b99a33, "acpi_put_table" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x3ef2485d, "ttm_device_fini" },
	{ 0xb8ebaa03, "irq_domain_remove" },
	{ 0x6a59169d, "simple_open" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xd0d8c9cd, "drm_dp_check_act_status" },
	{ 0x6ac01ea8, "drm_edid_to_sad" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xe43186d1, "drm_dev_printk" },
	{ 0x66e38f89, "__srcu_read_unlock" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0xf2b81b64, "arch_io_reserve_memtype_wc" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0xdd64e639, "strscpy" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x2b44c0dc, "param_ops_ullong" },
	{ 0x698e1c3, "drm_crtc_init" },
	{ 0x270b039f, "ttm_bo_unpin" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x558e68f5, "sg_alloc_table_from_pages_segment" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xe5db3426, "ttm_bo_vm_fault_reserved" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x5580ef07, "drm_connector_attach_content_protection_property" },
	{ 0xc5c5ccfd, "drm_dp_mst_update_slots" },
	{ 0xb4032484, "drm_mm_insert_node_in_range" },
	{ 0xe4b33762, "request_firmware_direct" },
	{ 0xf15ca581, "drm_connector_list_iter_next" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x65442026, "pci_release_resource" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0x51587db2, "drm_prime_pages_to_sg" },
	{ 0xe09013ee, "ttm_pool_free" },
	{ 0xd76aa523, "drm_modeset_drop_locks" },
	{ 0xd0b01891, "drm_hdmi_avi_infoframe_from_display_mode" },
	{ 0x3740e669, "drm_dp_cec_set_edid" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x4268445a, "pci_assign_unassigned_bus_resources" },
	{ 0x929d9ed2, "kobject_get" },
	{ 0x98d94cee, "drm_gem_private_object_init" },
	{ 0x34b9b10b, "dma_get_required_mask" },
	{ 0xb6fde909, "close_fd" },
	{ 0x9819ee8, "pci_enable_pcie_error_reporting" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xe396e71b, "drm_gem_ttm_vunmap" },
	{ 0x40ead7a2, "drm_atomic_helper_calc_timestamping_constants" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0xdb63f629, "drm_atomic_helper_set_config" },
	{ 0x47b1831d, "drm_crtc_helper_set_config" },
	{ 0xa44a1307, "interval_tree_iter_first" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x4e15da32, "drm_dp_cec_irq" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xc3bc72ad, "trace_print_array_seq" },
	{ 0x56ac5181, "dma_resv_get_singleton" },
	{ 0x7bb07f83, "amd_iommu_set_invalid_ppr_cb" },
	{ 0x62567d06, "anon_inode_getfd" },
	{ 0xe8757ff9, "drm_crtc_vblank_put" },
	{ 0x6ef2f78e, "drm_format_info" },
	{ 0x6d606913, "pv_ops" },
	{ 0x5f9564a, "component_add" },
	{ 0x44a2cadb, "drm_prime_sg_to_dma_addr_array" },
	{ 0xd1875d31, "__drm_atomic_helper_crtc_reset" },
	{ 0x778498e5, "drm_helper_connector_dpms" },
	{ 0x3a028a17, "pci_enable_atomic_ops_to_root" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xf69d620c, "__drm_atomic_helper_crtc_destroy_state" },
	{ 0x946f4172, "drm_sched_fini" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xa012d2b1, "ttm_resource_manager_create_debugfs" },
	{ 0xb2dfc9b5, "drm_mode_destroy" },
	{ 0xb62fbf91, "drm_crtc_init_with_planes" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x1f1f589c, "device_create" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xc12d7c13, "drm_sched_entity_fini" },
	{ 0x6c751286, "pcie_capability_read_word" },
	{ 0x6c241300, "drm_read" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x4088b7b0, "drm_property_create_range" },
	{ 0x30f7d8d0, "ttm_bo_move_to_lru_tail" },
	{ 0xdca09c91, "sysfs_remove_file_ns" },
	{ 0x69acdf38, "memcpy" },
	{ 0xdba64316, "param_ops_hexint" },
	{ 0xa508ab8b, "drm_kms_helper_poll_disable" },
	{ 0x9d5e063, "seq_write" },
	{ 0xb92e0ba9, "drm_handle_vblank" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x97fa4dd1, "dma_buf_map_attachment" },
	{ 0xe02c9c92, "__xa_erase" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xa29aeb66, "drm_gem_fb_create_handle" },
	{ 0xb0831844, "get_pid_task" },
	{ 0x5eb85eee, "drm_plane_cleanup" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0x754d539c, "strlen" },
	{ 0x70d1ef80, "pci_bus_resource_n" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x9b515cb6, "drm_modeset_lock_all" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x6d954f94, "drm_syncobj_replace_fence" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeb6eb87, "add_taint" },
	{ 0x7c181721, "kobject_put" },
	{ 0x89fa5120, "__irq_domain_add" },
	{ 0xc5f3370a, "drm_connector_set_vrr_capable_property" },
	{ 0xffb7c514, "ida_free" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0x2be3b2ec, "drm_syncobj_find" },
	{ 0x8d72789e, "drm_edid_is_valid" },
	{ 0xbb2b861a, "single_release" },
	{ 0x582ee90f, "drm_crtc_vblank_get" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x70be8cc2, "ttm_resource_manager_evict_all" },
	{ 0xedc03953, "iounmap" },
	{ 0x5dc850a6, "drm_hdmi_infoframe_set_hdr_metadata" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x714758a6, "drm_sched_increase_karma" },
	{ 0x615e2f98, "drm_kms_helper_poll_fini" },
	{ 0x4b75a00, "drm_helper_resume_force_mode" },
	{ 0xb181aad4, "drm_atomic_private_obj_fini" },
	{ 0x6204a1c1, "drm_kms_helper_hotplug_event" },
	{ 0x85df9b6c, "strsep" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0x985ff1d9, "kobj_sysfs_ops" },
	{ 0x723a7ca, "drm_atomic_get_private_obj_state" },
	{ 0x2293ac3, "dma_fence_chain_ops" },
	{ 0xd42f4adc, "drm_atomic_helper_plane_reset" },
	{ 0x14605535, "dma_fence_context_alloc" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0xe104969e, "drm_dp_link_train_channel_eq_delay" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x1e8776c3, "pm_genpd_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ttm,drm,drm_display_helper,drm_kms_helper,drm_buddy,i2c-algo-bit,gpu-sched,iommu_v2,drm_ttm_helper");

MODULE_ALIAS("pci:v00001002d00006780sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006784sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006788sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000678Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006790sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006791sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006792sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006798sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006799sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006800sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006801sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006802sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006806sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006808sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006809sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006810sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006811sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006816sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006817sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006818sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006819sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006600sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006601sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006602sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006603sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006604sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006605sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006606sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006607sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006608sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006610sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006611sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006613sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006617sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006620sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006621sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006623sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006631sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006820sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006821sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006822sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006823sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006824sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006825sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006826sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006827sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006828sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006829sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006830sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006831sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006837sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006838sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006839sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000683Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000683Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000683Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006660sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006663sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006664sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006665sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006667sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000666Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001304sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001305sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001306sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001307sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001309sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001313sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001315sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001316sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001317sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000131Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000131Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000131Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006640sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006641sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006646sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006647sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006649sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006650sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006651sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006658sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000665Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000665Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000665Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067AAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067BAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067BEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009830sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009831sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009832sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009833sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009834sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009836sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009837sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009838sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009839sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009850sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009851sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009852sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009853sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009854sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009855sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009856sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009857sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009858sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009859sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006900sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006901sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006902sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006903sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006907sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006920sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006921sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006928sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006929sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000692Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000692Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006930sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006938sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006939sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000730Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009870sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009874sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009875sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009876sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009877sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000098E4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067EBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067EFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067FFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067DFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067CAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067CCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067CFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006FDFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006980sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006981sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006985sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006986sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006987sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006995sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006997sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000699Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000694Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000694Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000694Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006860sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006861sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006862sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006863sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006864sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006867sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006868sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006869sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000687Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000015DDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000015D8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000738Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007388sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000738Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007390sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007319sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007340sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007341sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007347sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000734Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000015E7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001636sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001638sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000164Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007360sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007362sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ABsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ADsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073AEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073BFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000163Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000164Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001681sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073C1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073C3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ECsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073FFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007408sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000740Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000740Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007410sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000013FEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000143Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007420sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007421sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007422sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007423sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007424sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000743Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d*sv*sd*bc03sc00i00*");
MODULE_ALIAS("pci:v00001002d*sv*sd*bc03sc80i00*");

MODULE_INFO(srcversion, "E3C403930CBD01C448A7D0F");
