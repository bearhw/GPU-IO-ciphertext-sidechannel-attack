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

SYMBOL_CRC(drm_dp_dual_mode_read, 0xc625fceb, "");
SYMBOL_CRC(drm_dp_dual_mode_write, 0x002837b6, "");
SYMBOL_CRC(drm_dp_dual_mode_detect, 0xf099a0e1, "");
SYMBOL_CRC(drm_dp_dual_mode_max_tmds_clock, 0xb87753e5, "");
SYMBOL_CRC(drm_dp_dual_mode_get_tmds_output, 0xebd1ef58, "");
SYMBOL_CRC(drm_dp_dual_mode_set_tmds_output, 0x2b3a2f92, "");
SYMBOL_CRC(drm_dp_get_dual_mode_type_name, 0x5407ae9e, "");
SYMBOL_CRC(drm_lspcon_get_mode, 0x12cbebc5, "");
SYMBOL_CRC(drm_lspcon_set_mode, 0x92e90f28, "");
SYMBOL_CRC(drm_dp_channel_eq_ok, 0xedcf81ce, "");
SYMBOL_CRC(drm_dp_clock_recovery_ok, 0x8d701329, "");
SYMBOL_CRC(drm_dp_get_adjust_request_voltage, 0xc5c99a79, "");
SYMBOL_CRC(drm_dp_get_adjust_request_pre_emphasis, 0x582f248e, "");
SYMBOL_CRC(drm_dp_get_adjust_tx_ffe_preset, 0xccf54d5e, "");
SYMBOL_CRC(drm_dp_128b132b_lane_channel_eq_done, 0xc8b6a8ae, "");
SYMBOL_CRC(drm_dp_128b132b_lane_symbol_locked, 0xd5a95eae, "");
SYMBOL_CRC(drm_dp_128b132b_eq_interlane_align_done, 0x6a4df8c5, "");
SYMBOL_CRC(drm_dp_128b132b_cds_interlane_align_done, 0x92b9835e, "");
SYMBOL_CRC(drm_dp_128b132b_link_training_failed, 0x6aacee47, "");
SYMBOL_CRC(drm_dp_read_clock_recovery_delay, 0xb1741717, "");
SYMBOL_CRC(drm_dp_read_channel_eq_delay, 0xdc832f44, "");
SYMBOL_CRC(drm_dp_128b132b_read_aux_rd_interval, 0x33e9304c, "");
SYMBOL_CRC(drm_dp_link_train_clock_recovery_delay, 0xc30378af, "");
SYMBOL_CRC(drm_dp_link_train_channel_eq_delay, 0xe104969e, "");
SYMBOL_CRC(drm_dp_lttpr_link_train_clock_recovery_delay, 0x1709ddcf, "");
SYMBOL_CRC(drm_dp_lttpr_link_train_channel_eq_delay, 0x7920b218, "");
SYMBOL_CRC(drm_dp_link_rate_to_bw_code, 0x26815dbc, "");
SYMBOL_CRC(drm_dp_bw_code_to_link_rate, 0x73011db0, "");
SYMBOL_CRC(drm_dp_dpcd_probe, 0xadb9b5a8, "");
SYMBOL_CRC(drm_dp_dpcd_read, 0xca8ff46f, "");
SYMBOL_CRC(drm_dp_dpcd_write, 0xb0c01ee9, "");
SYMBOL_CRC(drm_dp_dpcd_read_link_status, 0x6093e836, "");
SYMBOL_CRC(drm_dp_dpcd_read_phy_link_status, 0x8c311745, "");
SYMBOL_CRC(drm_dp_downstream_is_type, 0xc79ecffb, "");
SYMBOL_CRC(drm_dp_downstream_is_tmds, 0x68d8dce7, "");
SYMBOL_CRC(drm_dp_send_real_edid_checksum, 0x1f7cd8ac, "");
SYMBOL_CRC(drm_dp_read_dpcd_caps, 0x0320f011, "");
SYMBOL_CRC(drm_dp_read_downstream_info, 0xde8c96e5, "");
SYMBOL_CRC(drm_dp_downstream_max_dotclock, 0x392a838b, "");
SYMBOL_CRC(drm_dp_downstream_max_tmds_clock, 0x6b53e216, "");
SYMBOL_CRC(drm_dp_downstream_min_tmds_clock, 0x63a477fb, "");
SYMBOL_CRC(drm_dp_downstream_max_bpc, 0x23961837, "");
SYMBOL_CRC(drm_dp_downstream_420_passthrough, 0xf689ad25, "");
SYMBOL_CRC(drm_dp_downstream_444_to_420_conversion, 0x2fa94ef2, "");
SYMBOL_CRC(drm_dp_downstream_rgb_to_ycbcr_conversion, 0xfb1a7a5a, "");
SYMBOL_CRC(drm_dp_downstream_mode, 0xe560d733, "");
SYMBOL_CRC(drm_dp_downstream_id, 0x13214bd2, "");
SYMBOL_CRC(drm_dp_downstream_debug, 0x376e4e9b, "");
SYMBOL_CRC(drm_dp_subconnector_type, 0xf68741fb, "");
SYMBOL_CRC(drm_dp_set_subconnector_property, 0x2b5845f7, "");
SYMBOL_CRC(drm_dp_read_sink_count_cap, 0xf19f1e3e, "");
SYMBOL_CRC(drm_dp_read_sink_count, 0xa8bd1563, "");
SYMBOL_CRC(drm_dp_remote_aux_init, 0xa60434b9, "");
SYMBOL_CRC(drm_dp_aux_init, 0xc3efa62a, "");
SYMBOL_CRC(drm_dp_aux_register, 0x811842bf, "");
SYMBOL_CRC(drm_dp_aux_unregister, 0x8b0d7462, "");
SYMBOL_CRC(drm_dp_psr_setup_time, 0xa1fefe6a, "");
SYMBOL_CRC(drm_dp_start_crc, 0x228dfabf, "");
SYMBOL_CRC(drm_dp_stop_crc, 0x2c7b324e, "");
SYMBOL_CRC(drm_dp_read_desc, 0x97d53b0a, "");
SYMBOL_CRC(drm_dp_dsc_sink_max_slice_count, 0x6615069e, "");
SYMBOL_CRC(drm_dp_dsc_sink_line_buf_depth, 0x06c49551, "");
SYMBOL_CRC(drm_dp_dsc_sink_supported_input_bpcs, 0x3a8063f3, "");
SYMBOL_CRC(drm_dp_read_lttpr_common_caps, 0x73e3d942, "");
SYMBOL_CRC(drm_dp_read_lttpr_phy_caps, 0x2ef18380, "");
SYMBOL_CRC(drm_dp_lttpr_count, 0xaf267620, "");
SYMBOL_CRC(drm_dp_lttpr_max_link_rate, 0x01c4bba9, "");
SYMBOL_CRC(drm_dp_lttpr_max_lane_count, 0x1605d0ed, "");
SYMBOL_CRC(drm_dp_lttpr_voltage_swing_level_3_supported, 0x1b0a1fdc, "");
SYMBOL_CRC(drm_dp_lttpr_pre_emphasis_level_3_supported, 0x76ff6644, "");
SYMBOL_CRC(drm_dp_get_phy_test_pattern, 0x4312668c, "");
SYMBOL_CRC(drm_dp_set_phy_test_pattern, 0x96fbb968, "");
SYMBOL_CRC(drm_dp_vsc_sdp_log, 0xe769e0fa, "");
SYMBOL_CRC(drm_dp_get_pcon_max_frl_bw, 0x7053fa72, "");
SYMBOL_CRC(drm_dp_pcon_frl_prepare, 0x033299cb, "");
SYMBOL_CRC(drm_dp_pcon_is_frl_ready, 0x1ce10517, "");
SYMBOL_CRC(drm_dp_pcon_frl_configure_1, 0x3412db91, "");
SYMBOL_CRC(drm_dp_pcon_frl_configure_2, 0xe25f08cb, "");
SYMBOL_CRC(drm_dp_pcon_reset_frl_config, 0xd92c36b2, "");
SYMBOL_CRC(drm_dp_pcon_frl_enable, 0xafaae4c4, "");
SYMBOL_CRC(drm_dp_pcon_hdmi_link_active, 0x6080be40, "");
SYMBOL_CRC(drm_dp_pcon_hdmi_link_mode, 0xdeec1264, "");
SYMBOL_CRC(drm_dp_pcon_hdmi_frl_link_error_count, 0x82d502ee, "");
SYMBOL_CRC(drm_dp_pcon_enc_is_dsc_1_2, 0x59f27ed7, "");
SYMBOL_CRC(drm_dp_pcon_dsc_max_slices, 0xe5360b84, "");
SYMBOL_CRC(drm_dp_pcon_dsc_max_slice_width, 0xc020c0c1, "");
SYMBOL_CRC(drm_dp_pcon_dsc_bpp_incr, 0x4603c416, "");
SYMBOL_CRC(drm_dp_pcon_pps_default, 0x0fc720fc, "");
SYMBOL_CRC(drm_dp_pcon_pps_override_buf, 0x78311dd2, "");
SYMBOL_CRC(drm_dp_pcon_pps_override_param, 0xc7bb1408, "");
SYMBOL_CRC(drm_dp_pcon_convert_rgb_to_ycbcr, 0xa33aeda6, "");
SYMBOL_CRC(drm_edp_backlight_set_level, 0xb88fa424, "");
SYMBOL_CRC(drm_edp_backlight_enable, 0x30553704, "");
SYMBOL_CRC(drm_edp_backlight_disable, 0xaf161add, "");
SYMBOL_CRC(drm_edp_backlight_init, 0x84b0e133, "");
SYMBOL_CRC(drm_panel_dp_aux_backlight, 0xe08e2152, "");
SYMBOL_CRC(drm_dp_mst_get_port_malloc, 0xe7e97b44, "");
SYMBOL_CRC(drm_dp_mst_put_port_malloc, 0xeb013674, "");
SYMBOL_CRC(drm_dp_mst_connector_late_register, 0xeff5715a, "");
SYMBOL_CRC(drm_dp_mst_connector_early_unregister, 0x18585875, "");
SYMBOL_CRC(drm_dp_send_power_updown_phy, 0x6d8ef0e7, "");
SYMBOL_CRC(drm_dp_send_query_stream_enc_status, 0x320a3b4b, "");
SYMBOL_CRC(drm_dp_update_payload_part1, 0x8472f0d3, "");
SYMBOL_CRC(drm_dp_update_payload_part2, 0x2230f774, "");
SYMBOL_CRC(drm_dp_get_vc_payload_bw, 0xf4a8c409, "");
SYMBOL_CRC(drm_dp_read_mst_cap, 0x9c0f9560, "");
SYMBOL_CRC(drm_dp_mst_topology_mgr_set_mst, 0xd4ee4030, "");
SYMBOL_CRC(drm_dp_mst_topology_mgr_suspend, 0x7036edd9, "");
SYMBOL_CRC(drm_dp_mst_topology_mgr_resume, 0xe8598702, "");
SYMBOL_CRC(drm_dp_mst_hpd_irq, 0x83d18779, "");
SYMBOL_CRC(drm_dp_mst_detect_port, 0xdc4b8ad0, "");
SYMBOL_CRC(drm_dp_mst_get_edid, 0xaf0cf195, "");
SYMBOL_CRC(drm_dp_find_vcpi_slots, 0x0a238700, "");
SYMBOL_CRC(drm_dp_atomic_find_vcpi_slots, 0xfac59a30, "");
SYMBOL_CRC(drm_dp_atomic_release_vcpi_slots, 0xe0d608c6, "");
SYMBOL_CRC(drm_dp_mst_update_slots, 0xc5c5ccfd, "");
SYMBOL_CRC(drm_dp_mst_allocate_vcpi, 0x3a52132a, "");
SYMBOL_CRC(drm_dp_mst_get_vcpi_slots, 0x2c9adb46, "");
SYMBOL_CRC(drm_dp_mst_reset_vcpi_slots, 0x033de6ac, "");
SYMBOL_CRC(drm_dp_mst_deallocate_vcpi, 0x16d6b792, "");
SYMBOL_CRC(drm_dp_check_act_status, 0xd0d8c9cd, "");
SYMBOL_CRC(drm_dp_calc_pbn_mode, 0x8ca2d9e4, "");
SYMBOL_CRC(drm_dp_mst_dump_topology, 0xcaa1bbdd, "");
SYMBOL_CRC(drm_dp_mst_add_affected_dsc_crtcs, 0xaf303877, "");
SYMBOL_CRC(drm_dp_mst_atomic_enable_dsc, 0xa46ee521, "");
SYMBOL_CRC(drm_dp_mst_atomic_check, 0x8b860418, "");
SYMBOL_CRC(drm_dp_mst_topology_state_funcs, 0x3c098824, "");
SYMBOL_CRC(drm_atomic_get_mst_topology_state, 0x86cbce50, "");
SYMBOL_CRC(drm_dp_mst_topology_mgr_init, 0x7f13c7b5, "");
SYMBOL_CRC(drm_dp_mst_topology_mgr_destroy, 0xbf8f8a2e, "");
SYMBOL_CRC(drm_dp_mst_dsc_aux_for_port, 0xce4063de, "");
SYMBOL_CRC(drm_dsc_dp_pps_header_init, 0x648d953b, "");
SYMBOL_CRC(drm_dsc_dp_rc_buffer_size, 0x1a5bf3ca, "");
SYMBOL_CRC(drm_dsc_pps_payload_pack, 0x58d8fcaa, "");
SYMBOL_CRC(drm_dsc_compute_rc_parameters, 0xfe12bcb9, "");
SYMBOL_CRC(drm_hdcp_check_ksvs_revoked, 0xae737de4, "_gpl");
SYMBOL_CRC(drm_connector_attach_content_protection_property, 0x5580ef07, "");
SYMBOL_CRC(drm_hdcp_update_content_protection, 0x1cf416e2, "");
SYMBOL_CRC(drm_hdmi_infoframe_set_hdr_metadata, 0x5dc850a6, "");
SYMBOL_CRC(drm_hdmi_avi_infoframe_colorimetry, 0x65e1b868, "");
SYMBOL_CRC(drm_hdmi_avi_infoframe_bars, 0x047a3670, "");
SYMBOL_CRC(drm_hdmi_avi_infoframe_content_type, 0x03d16fea, "");
SYMBOL_CRC(drm_scdc_read, 0xe51a19da, "");
SYMBOL_CRC(drm_scdc_write, 0xd9433ce6, "");
SYMBOL_CRC(drm_scdc_get_scrambling_status, 0x346f0afc, "");
SYMBOL_CRC(drm_scdc_set_scrambling, 0x77613e64, "");
SYMBOL_CRC(drm_scdc_set_high_tmds_clock_ratio, 0xd700d90c, "");
SYMBOL_CRC(drm_dp_cec_irq, 0x4e15da32, "");
SYMBOL_CRC(drm_dp_cec_set_edid, 0x3740e669, "");
SYMBOL_CRC(drm_dp_cec_unset_edid, 0xd6c98df1, "");
SYMBOL_CRC(drm_dp_cec_register_connector, 0x256c11fa, "");
SYMBOL_CRC(drm_dp_cec_unregister_connector, 0x2930e6f3, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xcb2693a0, "drm_crtc_add_crc_entry" },
	{ 0xdc9b6a1, "cec_delete_adapter" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x20978fb9, "idr_find" },
	{ 0xb2568e5, "drm_connector_register" },
	{ 0x34a90de, "cec_transmit_attempt_done_ts" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf824c7db, "__drm_printfn_debug" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0x723a7ca, "drm_atomic_get_private_obj_state" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x7b7d5de5, "drm_atomic_private_obj_init" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xe4ca8bf7, "cec_s_phys_addr" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0x8fd0d4c8, "cec_s_conn_info" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x5ed6c9b0, "cec_s_phys_addr_from_edid" },
	{ 0x7edf470b, "drm_edid_duplicate" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x51d9d03f, "drm_connector_unregister" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa96a098c, "drm_mode_object_put" },
	{ 0xe4b33762, "request_firmware_direct" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x4f18a150, "__drm_debug" },
	{ 0x44e182e6, "__drm_atomic_helper_private_obj_duplicate_state" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xb181aad4, "drm_atomic_private_obj_fini" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xa916b694, "strnlen" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x4722e83c, "drm_property_create_enum" },
	{ 0x5d49aabc, "init_wait_var_entry" },
	{ 0xe43186d1, "drm_dev_printk" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5e332b52, "__var_waitqueue" },
	{ 0xc5eb3e89, "drm_atomic_get_crtc_state" },
	{ 0xf3ee73c5, "drm_crtc_wait_one_vblank" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xe1fb555d, "drm_modeset_lock" },
	{ 0xa11ff8d2, "drm_modeset_unlock" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x1f1f589c, "device_create" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x12634b90, "fixed_size_llseek" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x9697bfc0, "cec_unregister_adapter" },
	{ 0x9bc9f8fe, "drm_object_attach_property" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xea593f6, "hdmi_drm_infoframe_init" },
	{ 0x86490580, "current_task" },
	{ 0x82c2027, "drm_sysfs_connector_status_event" },
	{ 0xf8f61ebc, "wake_up_var" },
	{ 0xfb578fc5, "memset" },
	{ 0xf9c0b663, "strlcat" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x131db64a, "system_long_wq" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x6b7bb67b, "i2c_add_adapter" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2aed0676, "cec_allocate_adapter" },
	{ 0xa248afde, "drm_detect_monitor_audio" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7727ca0b, "drm_object_property_set_value" },
	{ 0x28779e52, "drm_printf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x6204a1c1, "drm_kms_helper_hotplug_event" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0xf8dd19b9, "drm_display_mode_from_cea_vic" },
	{ 0x391de184, "seq_puts" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xbf885366, "cec_fill_conn_info_from_drm" },
	{ 0x60241a95, "cec_received_msg_ts" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x1668523a, "drm_get_edid" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xdf6e4e77, "drm_atomic_get_connector_state" },
	{ 0x7c545285, "drm_edid_get_monitor_name" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x4403b369, "cec_register_adapter" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,cec,drm_kms_helper");


MODULE_INFO(srcversion, "7FB4EC7FFAD3B8B9C1A889C");
