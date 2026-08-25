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

SYMBOL_CRC(devm_aperture_acquire_from_firmware, 0x9921abec, "");
SYMBOL_CRC(drm_aperture_remove_conflicting_framebuffers, 0x8c6ac271, "");
SYMBOL_CRC(drm_aperture_remove_conflicting_pci_framebuffers, 0x5a05660c, "");
SYMBOL_CRC(drm_is_current_master, 0x098dc7e7, "");
SYMBOL_CRC(drm_master_get, 0x189e0a56, "");
SYMBOL_CRC(drm_file_get_master, 0xd78770f0, "");
SYMBOL_CRC(drm_master_put, 0x21c8059a, "");
SYMBOL_CRC(drm_master_internal_acquire, 0x98660e3a, "");
SYMBOL_CRC(drm_master_internal_release, 0x33dec24c, "");
SYMBOL_CRC(drm_clflush_pages, 0x4f71159f, "");
SYMBOL_CRC(drm_clflush_sg, 0xb0b05ff5, "");
SYMBOL_CRC(drm_clflush_virt_range, 0x0a72f765, "");
SYMBOL_CRC(drm_need_swiotlb, 0xb6127243, "");
SYMBOL_CRC(drm_memcpy_from_wc, 0xa38c4c94, "");
SYMBOL_CRC(drm_open, 0x7f05725d, "");
SYMBOL_CRC(drm_release, 0x33da23c4, "");
SYMBOL_CRC(drm_release_noglobal, 0xa3504ba0, "");
SYMBOL_CRC(drm_read, 0x6c241300, "");
SYMBOL_CRC(drm_poll, 0x5151da72, "");
SYMBOL_CRC(drm_event_reserve_init_locked, 0xafa73672, "");
SYMBOL_CRC(drm_event_reserve_init, 0x387aa6e1, "");
SYMBOL_CRC(drm_event_cancel_free, 0x1d64e687, "");
SYMBOL_CRC(drm_send_event_timestamp_locked, 0xf5cab263, "");
SYMBOL_CRC(drm_send_event_locked, 0x0d34792b, "");
SYMBOL_CRC(drm_send_event, 0xcc652d5a, "");
SYMBOL_CRC(drm_get_unmapped_area, 0x7f12c769, "_gpl");
SYMBOL_CRC(drm_gem_object_init, 0xef3c4945, "");
SYMBOL_CRC(drm_gem_private_object_init, 0x98d94cee, "");
SYMBOL_CRC(drm_gem_handle_delete, 0xb33c6af1, "");
SYMBOL_CRC(drm_gem_dumb_map_offset, 0xe6356da5, "_gpl");
SYMBOL_CRC(drm_gem_handle_create, 0x435f223e, "");
SYMBOL_CRC(drm_gem_free_mmap_offset, 0xaed2c6b9, "");
SYMBOL_CRC(drm_gem_create_mmap_offset_size, 0xc7f28356, "");
SYMBOL_CRC(drm_gem_create_mmap_offset, 0x1d6db591, "");
SYMBOL_CRC(drm_gem_get_pages, 0x472d1bb0, "");
SYMBOL_CRC(drm_gem_put_pages, 0xe02e38c0, "");
SYMBOL_CRC(drm_gem_objects_lookup, 0x830011f3, "");
SYMBOL_CRC(drm_gem_object_lookup, 0x2330f595, "");
SYMBOL_CRC(drm_gem_dma_resv_wait, 0x398690a8, "");
SYMBOL_CRC(drm_gem_object_release, 0xa15e1675, "");
SYMBOL_CRC(drm_gem_object_free, 0xd680a377, "");
SYMBOL_CRC(drm_gem_vm_open, 0x75f96800, "");
SYMBOL_CRC(drm_gem_vm_close, 0xdc905b62, "");
SYMBOL_CRC(drm_gem_mmap_obj, 0x6024ea00, "");
SYMBOL_CRC(drm_gem_mmap, 0x18c2c9e5, "");
SYMBOL_CRC(drm_gem_vmap, 0xb35a6edf, "");
SYMBOL_CRC(drm_gem_vunmap, 0xea3f7773, "");
SYMBOL_CRC(drm_gem_lock_reservations, 0x7f51e971, "");
SYMBOL_CRC(drm_gem_unlock_reservations, 0x02603eaf, "");
SYMBOL_CRC(drm_noop, 0x3f4b0641, "");
SYMBOL_CRC(drm_invalid_op, 0xd939cb1b, "");
SYMBOL_CRC(drm_ioctl_kernel, 0xfa94f60e, "");
SYMBOL_CRC(drm_ioctl, 0x60457cb1, "");
SYMBOL_CRC(drm_ioctl_flags, 0x57b6efe3, "");
SYMBOL_CRC(drm_put_dev, 0x5ea7721b, "");
SYMBOL_CRC(drm_dev_enter, 0x18b0b5a1, "");
SYMBOL_CRC(drm_dev_exit, 0xe8a034df, "");
SYMBOL_CRC(drm_dev_unplug, 0x5d8a9030, "");
SYMBOL_CRC(__devm_drm_dev_alloc, 0x6ee0b8fb, "");
SYMBOL_CRC(drm_dev_alloc, 0x2f1d6eaa, "");
SYMBOL_CRC(drm_dev_get, 0x1152c6a8, "");
SYMBOL_CRC(drm_dev_put, 0xc7831494, "");
SYMBOL_CRC(drm_dev_register, 0x79fd4f29, "");
SYMBOL_CRC(drm_dev_unregister, 0xbe56866a, "");
SYMBOL_CRC(drm_dev_set_unique, 0x1be82638, "");
SYMBOL_CRC(drm_sysfs_hotplug_event, 0xe0c922d3, "");
SYMBOL_CRC(drm_sysfs_connector_hotplug_event, 0x9d379d8c, "");
SYMBOL_CRC(drm_sysfs_connector_status_event, 0x082c2027, "");
SYMBOL_CRC(drm_class_device_register, 0x674c181d, "_gpl");
SYMBOL_CRC(drm_class_device_unregister, 0x6f310a70, "_gpl");
SYMBOL_CRC(__drm_mm_interval_first, 0x25daad93, "");
SYMBOL_CRC(drm_mm_reserve_node, 0x2754dad8, "");
SYMBOL_CRC(drm_mm_insert_node_in_range, 0xb4032484, "");
SYMBOL_CRC(drm_mm_remove_node, 0x4b7ebf95, "");
SYMBOL_CRC(drm_mm_replace_node, 0x59056243, "");
SYMBOL_CRC(drm_mm_scan_init_with_range, 0x2a962499, "");
SYMBOL_CRC(drm_mm_scan_add_block, 0x2183c08c, "");
SYMBOL_CRC(drm_mm_scan_remove_block, 0x5f7985a5, "");
SYMBOL_CRC(drm_mm_scan_color_evict, 0xdf3f760d, "");
SYMBOL_CRC(drm_mm_init, 0xf0517d7a, "");
SYMBOL_CRC(drm_mm_takedown, 0x57698a50, "");
SYMBOL_CRC(drm_mm_print, 0x0f7acb66, "");
SYMBOL_CRC(drm_crtc_from_index, 0xd26e79d7, "");
SYMBOL_CRC(drm_crtc_init_with_planes, 0xb62fbf91, "");
SYMBOL_CRC(__drmm_crtc_alloc_with_planes, 0xf0b6aa9e, "");
SYMBOL_CRC(drm_crtc_cleanup, 0x0554ac3d, "");
SYMBOL_CRC(drm_mode_set_config_internal, 0xc46551d5, "");
SYMBOL_CRC(drm_crtc_check_viewport, 0x7bade498, "");
SYMBOL_CRC(drm_crtc_create_scaling_filter_property, 0xcd66b347, "");
SYMBOL_CRC(drm_mode_legacy_fb_format, 0x29f078d1, "");
SYMBOL_CRC(drm_driver_legacy_fb_format, 0xfdda2a55, "");
SYMBOL_CRC(drm_format_info, 0x6ef2f78e, "");
SYMBOL_CRC(drm_get_format_info, 0xc82982eb, "");
SYMBOL_CRC(drm_format_info_block_width, 0xccc59759, "");
SYMBOL_CRC(drm_format_info_block_height, 0xca190085, "");
SYMBOL_CRC(drm_format_info_min_pitch, 0xb22dfd68, "");
SYMBOL_CRC(drm_mode_debug_printmodeline, 0x2ed3c600, "");
SYMBOL_CRC(drm_mode_create, 0x90982d56, "");
SYMBOL_CRC(drm_mode_destroy, 0xb2dfc9b5, "");
SYMBOL_CRC(drm_mode_probed_add, 0x0a53d4e7, "");
SYMBOL_CRC(drm_cvt_mode, 0xdd4ebf05, "");
SYMBOL_CRC(drm_gtf_mode_complex, 0x0b6dae70, "");
SYMBOL_CRC(drm_gtf_mode, 0x09ee8614, "");
SYMBOL_CRC(drm_display_mode_from_videomode, 0x66cf2f64, "_gpl");
SYMBOL_CRC(drm_display_mode_to_videomode, 0xfe9f72f3, "_gpl");
SYMBOL_CRC(drm_bus_flags_from_videomode, 0xad885165, "_gpl");
SYMBOL_CRC(drm_mode_set_name, 0x4a35d30d, "");
SYMBOL_CRC(drm_mode_vrefresh, 0xf1b5340a, "");
SYMBOL_CRC(drm_mode_get_hv_timing, 0x4403a9c3, "");
SYMBOL_CRC(drm_mode_set_crtcinfo, 0x4575a0ca, "");
SYMBOL_CRC(drm_mode_copy, 0x9ce050be, "");
SYMBOL_CRC(drm_mode_init, 0xcdb99cc9, "");
SYMBOL_CRC(drm_mode_duplicate, 0xb5e74aec, "");
SYMBOL_CRC(drm_mode_match, 0x9b95c885, "");
SYMBOL_CRC(drm_mode_equal, 0x0d9b4753, "");
SYMBOL_CRC(drm_mode_equal_no_clocks, 0x3ab87110, "");
SYMBOL_CRC(drm_mode_equal_no_clocks_no_stereo, 0x24d124ac, "");
SYMBOL_CRC(drm_mode_validate_driver, 0x0450fdce, "");
SYMBOL_CRC(drm_mode_validate_size, 0xd7a9cf42, "");
SYMBOL_CRC(drm_mode_validate_ycbcr420, 0x7cd670e5, "");
SYMBOL_CRC(drm_mode_prune_invalid, 0xf264d236, "");
SYMBOL_CRC(drm_mode_sort, 0xf1421d13, "");
SYMBOL_CRC(drm_connector_list_update, 0xe8ca04e6, "");
SYMBOL_CRC(drm_mode_parse_command_line_for_connector, 0x311a09bf, "");
SYMBOL_CRC(drm_mode_create_from_cmdline_mode, 0x38e0d0c1, "");
SYMBOL_CRC(drm_mode_is_420_only, 0x389ef8e9, "");
SYMBOL_CRC(drm_mode_is_420_also, 0x9f596732, "");
SYMBOL_CRC(drm_mode_is_420, 0x57afd98a, "");
SYMBOL_CRC(drm_edid_header_is_valid, 0x9b9de1c1, "");
SYMBOL_CRC(drm_edid_are_equal, 0x24993e50, "");
SYMBOL_CRC(drm_edid_block_valid, 0xd13f9985, "");
SYMBOL_CRC(drm_edid_is_valid, 0x8d72789e, "");
SYMBOL_CRC(drm_add_override_edid_modes, 0xbace46e4, "");
SYMBOL_CRC(drm_do_get_edid, 0xaadb001c, "_gpl");
SYMBOL_CRC(drm_probe_ddc, 0x799f4a38, "");
SYMBOL_CRC(drm_get_edid, 0x1668523a, "");
SYMBOL_CRC(drm_edid_get_panel_id, 0x1a3dd48c, "");
SYMBOL_CRC(drm_get_edid_switcheroo, 0xc3751ec4, "");
SYMBOL_CRC(drm_edid_duplicate, 0x7edf470b, "");
SYMBOL_CRC(drm_mode_find_dmt, 0xc458aff9, "");
SYMBOL_CRC(drm_match_cea_mode, 0x9b285573, "");
SYMBOL_CRC(drm_display_mode_from_cea_vic, 0xf8dd19b9, "");
SYMBOL_CRC(drm_edid_get_monitor_name, 0x7c545285, "");
SYMBOL_CRC(drm_edid_to_sad, 0x6ac01ea8, "");
SYMBOL_CRC(drm_edid_to_speaker_allocation, 0x3cdc37e9, "");
SYMBOL_CRC(drm_av_sync_delay, 0xdda19087, "");
SYMBOL_CRC(drm_detect_hdmi_monitor, 0x38690d99, "");
SYMBOL_CRC(drm_detect_monitor_audio, 0xa248afde, "");
SYMBOL_CRC(drm_default_rgb_quant_range, 0x65702bd6, "");
SYMBOL_CRC(drm_add_edid_modes, 0x118dd7a0, "");
SYMBOL_CRC(drm_add_modes_noedid, 0xa2b8d0d4, "");
SYMBOL_CRC(drm_set_preferred_mode, 0xa20c8e78, "");
SYMBOL_CRC(drm_hdmi_avi_infoframe_from_display_mode, 0xd0b01891, "");
SYMBOL_CRC(drm_hdmi_avi_infoframe_quant_range, 0x4b7c8fa3, "");
SYMBOL_CRC(drm_hdmi_vendor_infoframe_from_display_mode, 0xb302156f, "");
SYMBOL_CRC(drm_gem_dmabuf_export, 0xcef0a729, "");
SYMBOL_CRC(drm_gem_dmabuf_release, 0xfd4eec47, "");
SYMBOL_CRC(drm_gem_prime_fd_to_handle, 0x55631405, "");
SYMBOL_CRC(drm_gem_prime_handle_to_fd, 0x6e7a1685, "");
SYMBOL_CRC(drm_gem_map_attach, 0x71d23399, "");
SYMBOL_CRC(drm_gem_map_detach, 0x35c5fcf2, "");
SYMBOL_CRC(drm_gem_map_dma_buf, 0xebc188ac, "");
SYMBOL_CRC(drm_gem_unmap_dma_buf, 0x35dcb6e9, "");
SYMBOL_CRC(drm_gem_dmabuf_vmap, 0x7ae22c04, "");
SYMBOL_CRC(drm_gem_dmabuf_vunmap, 0x3dc37960, "");
SYMBOL_CRC(drm_gem_prime_mmap, 0xc55e0195, "");
SYMBOL_CRC(drm_gem_dmabuf_mmap, 0x042a7681, "");
SYMBOL_CRC(drm_prime_pages_to_sg, 0x51587db2, "");
SYMBOL_CRC(drm_prime_get_contiguous_size, 0xd05fda43, "");
SYMBOL_CRC(drm_gem_prime_export, 0x917cf0ca, "");
SYMBOL_CRC(drm_gem_prime_import_dev, 0xe44409d8, "");
SYMBOL_CRC(drm_gem_prime_import, 0x55c31b92, "");
SYMBOL_CRC(drm_prime_sg_to_page_array, 0xbec3c8a2, "");
SYMBOL_CRC(drm_prime_sg_to_dma_addr_array, 0x44a2cadb, "");
SYMBOL_CRC(drm_prime_gem_destroy, 0x3122d93a, "");
SYMBOL_CRC(drm_vma_offset_manager_init, 0x3c22a4d8, "");
SYMBOL_CRC(drm_vma_offset_manager_destroy, 0x07fb449a, "");
SYMBOL_CRC(drm_vma_offset_lookup_locked, 0xc7910e38, "");
SYMBOL_CRC(drm_vma_offset_add, 0xe8a0e334, "");
SYMBOL_CRC(drm_vma_offset_remove, 0x4831da6e, "");
SYMBOL_CRC(drm_vma_node_allow, 0xc7d04fc5, "");
SYMBOL_CRC(drm_vma_node_revoke, 0x7b2e2166, "");
SYMBOL_CRC(drm_vma_node_is_allowed, 0x24cf437a, "");
SYMBOL_CRC(drm_modeset_lock_all, 0x9b515cb6, "");
SYMBOL_CRC(drm_modeset_unlock_all, 0xf53089ee, "");
SYMBOL_CRC(drm_warn_on_modeset_not_all_locked, 0xfd0336fc, "");
SYMBOL_CRC(drm_modeset_acquire_init, 0xa0761407, "");
SYMBOL_CRC(drm_modeset_acquire_fini, 0x19ad1a2e, "");
SYMBOL_CRC(drm_modeset_drop_locks, 0xd76aa523, "");
SYMBOL_CRC(drm_modeset_backoff, 0x59bf89d9, "");
SYMBOL_CRC(drm_modeset_lock_init, 0x5632daa0, "");
SYMBOL_CRC(drm_modeset_lock, 0xe1fb555d, "");
SYMBOL_CRC(drm_modeset_lock_single_interruptible, 0xeb5c9bc7, "");
SYMBOL_CRC(drm_modeset_unlock, 0xa11ff8d2, "");
SYMBOL_CRC(drm_modeset_lock_all_ctx, 0x396abd95, "");
SYMBOL_CRC(__drm_crtc_commit_free, 0xae277372, "");
SYMBOL_CRC(drm_crtc_commit_wait, 0x39d7d3b4, "");
SYMBOL_CRC(drm_atomic_state_default_release, 0xa889e566, "");
SYMBOL_CRC(drm_atomic_state_init, 0x175bd2ee, "");
SYMBOL_CRC(drm_atomic_state_alloc, 0x97d52e9c, "");
SYMBOL_CRC(drm_atomic_state_default_clear, 0x22abc5e6, "");
SYMBOL_CRC(drm_atomic_state_clear, 0x4eb69e45, "");
SYMBOL_CRC(__drm_atomic_state_free, 0xb9cad492, "");
SYMBOL_CRC(drm_atomic_get_crtc_state, 0xc5eb3e89, "");
SYMBOL_CRC(drm_atomic_get_plane_state, 0x43a90f84, "");
SYMBOL_CRC(drm_atomic_private_obj_init, 0x7b7d5de5, "");
SYMBOL_CRC(drm_atomic_private_obj_fini, 0xb181aad4, "");
SYMBOL_CRC(drm_atomic_get_private_obj_state, 0x0723a7ca, "");
SYMBOL_CRC(drm_atomic_get_old_private_obj_state, 0x33d9fa80, "");
SYMBOL_CRC(drm_atomic_get_new_private_obj_state, 0x34f11ddc, "");
SYMBOL_CRC(drm_atomic_get_old_connector_for_encoder, 0xc63e6508, "");
SYMBOL_CRC(drm_atomic_get_new_connector_for_encoder, 0xc1168254, "");
SYMBOL_CRC(drm_atomic_get_connector_state, 0xdf6e4e77, "");
SYMBOL_CRC(drm_atomic_get_bridge_state, 0x60662703, "");
SYMBOL_CRC(drm_atomic_get_old_bridge_state, 0xc8aeea4d, "");
SYMBOL_CRC(drm_atomic_get_new_bridge_state, 0x120881e5, "");
SYMBOL_CRC(drm_atomic_add_encoder_bridges, 0xe0b11bf0, "");
SYMBOL_CRC(drm_atomic_add_affected_connectors, 0xc5ca5a49, "");
SYMBOL_CRC(drm_atomic_add_affected_planes, 0x152407ec, "");
SYMBOL_CRC(drm_atomic_check_only, 0xed827deb, "");
SYMBOL_CRC(drm_atomic_commit, 0xe40f7318, "");
SYMBOL_CRC(drm_atomic_nonblocking_commit, 0xf62ddb6f, "");
SYMBOL_CRC(__drm_atomic_helper_disable_plane, 0xcd30e701, "");
SYMBOL_CRC(__drm_atomic_helper_set_config, 0xc75a9e1c, "");
SYMBOL_CRC(drm_atomic_print_new_state, 0xbb5ddf11, "");
SYMBOL_CRC(drm_state_dump, 0xe97a901b, "");
SYMBOL_CRC(drm_bridge_add, 0x399e2175, "");
SYMBOL_CRC(drm_bridge_remove, 0xf9a97e7c, "");
SYMBOL_CRC(drm_bridge_attach, 0x86332e44, "");
SYMBOL_CRC(drm_bridge_chain_mode_fixup, 0x19420296, "");
SYMBOL_CRC(drm_bridge_chain_mode_valid, 0x25b1f6c9, "");
SYMBOL_CRC(drm_bridge_chain_disable, 0x9d54caa9, "");
SYMBOL_CRC(drm_bridge_chain_post_disable, 0xfe170766, "");
SYMBOL_CRC(drm_bridge_chain_mode_set, 0x27b8c079, "");
SYMBOL_CRC(drm_bridge_chain_pre_enable, 0x833dcade, "");
SYMBOL_CRC(drm_bridge_chain_enable, 0xf86e4408, "");
SYMBOL_CRC(drm_atomic_bridge_chain_disable, 0xcf3b5bf4, "");
SYMBOL_CRC(drm_atomic_bridge_chain_post_disable, 0x7e92c5b2, "");
SYMBOL_CRC(drm_atomic_bridge_chain_pre_enable, 0x1649d232, "");
SYMBOL_CRC(drm_atomic_bridge_chain_enable, 0xef42bfcb, "");
SYMBOL_CRC(drm_atomic_bridge_chain_check, 0xedcddbe6, "");
SYMBOL_CRC(drm_bridge_detect, 0xa0f6fed7, "_gpl");
SYMBOL_CRC(drm_bridge_get_modes, 0x8b664d26, "_gpl");
SYMBOL_CRC(drm_bridge_get_edid, 0x16a18272, "_gpl");
SYMBOL_CRC(drm_bridge_hpd_enable, 0x1e043a91, "_gpl");
SYMBOL_CRC(drm_bridge_hpd_disable, 0x77e93483, "_gpl");
SYMBOL_CRC(drm_bridge_hpd_notify, 0x3e4f4aef, "_gpl");
SYMBOL_CRC(drm_framebuffer_init, 0x7c92bd35, "");
SYMBOL_CRC(drm_framebuffer_lookup, 0x45812ffd, "");
SYMBOL_CRC(drm_framebuffer_unregister_private, 0xf5c5edc0, "");
SYMBOL_CRC(drm_framebuffer_cleanup, 0xf0e5d263, "");
SYMBOL_CRC(drm_framebuffer_remove, 0x673ac7a4, "");
SYMBOL_CRC(drm_framebuffer_plane_width, 0x803e8ab7, "");
SYMBOL_CRC(drm_framebuffer_plane_height, 0x040fe82e, "");
SYMBOL_CRC(drm_get_connector_type_name, 0xf406e46a, "");
SYMBOL_CRC(drm_connector_init, 0x10408a6f, "");
SYMBOL_CRC(drm_connector_init_with_ddc, 0xb55c053f, "");
SYMBOL_CRC(drm_connector_attach_edid_property, 0xe6e1aea6, "");
SYMBOL_CRC(drm_connector_attach_encoder, 0x574e008e, "");
SYMBOL_CRC(drm_connector_has_possible_encoder, 0xb8ca2273, "");
SYMBOL_CRC(drm_connector_cleanup, 0x29cf8e8d, "");
SYMBOL_CRC(drm_connector_register, 0x0b2568e5, "");
SYMBOL_CRC(drm_connector_unregister, 0x51d9d03f, "");
SYMBOL_CRC(drm_get_connector_status_name, 0x0fd60df2, "");
SYMBOL_CRC(drm_connector_list_iter_begin, 0x47283066, "");
SYMBOL_CRC(drm_connector_list_iter_next, 0xf15ca581, "");
SYMBOL_CRC(drm_connector_list_iter_end, 0xa86fee46, "");
SYMBOL_CRC(drm_get_subpixel_order_name, 0x107742a9, "");
SYMBOL_CRC(drm_display_info_set_bus_formats, 0xeb96c64a, "");
SYMBOL_CRC(drm_mode_create_dvi_i_properties, 0x4677871e, "");
SYMBOL_CRC(drm_connector_attach_dp_subconnector_property, 0x86d6c57d, "");
SYMBOL_CRC(drm_connector_attach_content_type_property, 0xd6507215, "");
SYMBOL_CRC(drm_connector_attach_tv_margin_properties, 0x3e4ff2e8, "");
SYMBOL_CRC(drm_mode_create_tv_margin_properties, 0x01c7267d, "");
SYMBOL_CRC(drm_mode_create_tv_properties, 0x6bc0a4ce, "");
SYMBOL_CRC(drm_mode_create_scaling_mode_property, 0x976c8ec7, "");
SYMBOL_CRC(drm_connector_attach_vrr_capable_property, 0x076dfe01, "");
SYMBOL_CRC(drm_connector_attach_scaling_mode_property, 0xb3e6196b, "");
SYMBOL_CRC(drm_mode_create_aspect_ratio_property, 0x775ce591, "");
SYMBOL_CRC(drm_mode_create_hdmi_colorspace_property, 0x4926eaab, "");
SYMBOL_CRC(drm_mode_create_dp_colorspace_property, 0xa863ec74, "");
SYMBOL_CRC(drm_mode_create_content_type_property, 0x819f917a, "");
SYMBOL_CRC(drm_mode_create_suggested_offset_properties, 0x0b71186b, "");
SYMBOL_CRC(drm_connector_set_path_property, 0x029a1933, "");
SYMBOL_CRC(drm_connector_set_tile_property, 0x5a04922e, "");
SYMBOL_CRC(drm_connector_update_edid_property, 0x39494420, "");
SYMBOL_CRC(drm_connector_set_link_status_property, 0x48691c4c, "");
SYMBOL_CRC(drm_connector_attach_max_bpc_property, 0x7bc56a8b, "");
SYMBOL_CRC(drm_connector_attach_hdr_output_metadata_property, 0x44002f02, "");
SYMBOL_CRC(drm_connector_attach_colorspace_property, 0xfd0a2ed1, "");
SYMBOL_CRC(drm_connector_atomic_hdr_metadata_equal, 0xaa236b40, "");
SYMBOL_CRC(drm_connector_set_vrr_capable_property, 0xc5f3370a, "");
SYMBOL_CRC(drm_connector_set_panel_orientation, 0x3c1a9115, "");
SYMBOL_CRC(drm_connector_set_panel_orientation_with_quirk, 0x7060c59b, "");
SYMBOL_CRC(drm_connector_create_privacy_screen_properties, 0x741bc5c1, "");
SYMBOL_CRC(drm_connector_attach_privacy_screen_properties, 0x5e507f12, "");
SYMBOL_CRC(drm_connector_attach_privacy_screen_provider, 0x722ea85d, "");
SYMBOL_CRC(drm_connector_update_privacy_screen, 0x8bfef011, "");
SYMBOL_CRC(drm_connector_oob_hotplug_event, 0x96a63d2b, "");
SYMBOL_CRC(drm_mode_put_tile_group, 0x0228d65b, "");
SYMBOL_CRC(drm_mode_get_tile_group, 0x1b998ad0, "");
SYMBOL_CRC(drm_mode_create_tile_group, 0xace80385, "");
SYMBOL_CRC(drm_plane_create_alpha_property, 0x85493d2f, "");
SYMBOL_CRC(drm_plane_create_rotation_property, 0x3e2ef244, "");
SYMBOL_CRC(drm_rotation_simplify, 0xdf666902, "");
SYMBOL_CRC(drm_plane_create_zpos_property, 0x397e8896, "");
SYMBOL_CRC(drm_plane_create_zpos_immutable_property, 0xbe4433f4, "");
SYMBOL_CRC(drm_atomic_normalize_zpos, 0xef9eb55a, "");
SYMBOL_CRC(drm_plane_create_blend_mode_property, 0x87f588c0, "");
SYMBOL_CRC(drm_encoder_init, 0x89023912, "");
SYMBOL_CRC(drm_encoder_cleanup, 0x3082b526, "");
SYMBOL_CRC(__drmm_encoder_alloc, 0x1209d56d, "");
SYMBOL_CRC(drm_mode_object_find, 0x66e21440, "");
SYMBOL_CRC(drm_mode_object_put, 0xa96a098c, "");
SYMBOL_CRC(drm_mode_object_get, 0x63667dc7, "");
SYMBOL_CRC(drm_object_attach_property, 0x9bc9f8fe, "");
SYMBOL_CRC(drm_object_property_set_value, 0x7727ca0b, "");
SYMBOL_CRC(drm_object_property_get_value, 0x11881cf4, "");
SYMBOL_CRC(drm_object_property_get_default_value, 0x58d4099c, "");
SYMBOL_CRC(drm_property_create, 0x1cc5612e, "");
SYMBOL_CRC(drm_property_create_enum, 0x4722e83c, "");
SYMBOL_CRC(drm_property_create_bitmask, 0x73ea4021, "");
SYMBOL_CRC(drm_property_create_range, 0x4088b7b0, "");
SYMBOL_CRC(drm_property_create_signed_range, 0x7d290ffe, "");
SYMBOL_CRC(drm_property_create_object, 0x50263b99, "");
SYMBOL_CRC(drm_property_create_bool, 0x6a66beaf, "");
SYMBOL_CRC(drm_property_add_enum, 0x8eda3f82, "");
SYMBOL_CRC(drm_property_destroy, 0xed77317d, "");
SYMBOL_CRC(drm_property_create_blob, 0x84c06699, "");
SYMBOL_CRC(drm_property_blob_put, 0x33dd80c8, "");
SYMBOL_CRC(drm_property_blob_get, 0xebd3d19a, "");
SYMBOL_CRC(drm_property_lookup_blob, 0xef47b37b, "");
SYMBOL_CRC(drm_property_replace_global_blob, 0x87c76f4f, "");
SYMBOL_CRC(drm_property_replace_blob, 0x1dbcd55d, "");
SYMBOL_CRC(drm_universal_plane_init, 0x248c29c8, "");
SYMBOL_CRC(__drmm_universal_plane_alloc, 0xb8e3edef, "");
SYMBOL_CRC(drm_plane_init, 0x77ada1ce, "");
SYMBOL_CRC(drm_plane_cleanup, 0x5eb85eee, "");
SYMBOL_CRC(drm_plane_from_index, 0x2473bdf6, "");
SYMBOL_CRC(drm_plane_force_disable, 0xbb2696a3, "");
SYMBOL_CRC(drm_mode_plane_set_obj_prop, 0x34c224fb, "");
SYMBOL_CRC(drm_any_plane_has_format, 0xc972c6c0, "");
SYMBOL_CRC(drm_plane_enable_fb_damage_clips, 0xb70870ce, "");
SYMBOL_CRC(drm_plane_get_damage_clips_count, 0x4cfc520c, "");
SYMBOL_CRC(drm_plane_get_damage_clips, 0xdd87e544, "");
SYMBOL_CRC(drm_plane_create_scaling_filter_property, 0x6d0ec082, "");
SYMBOL_CRC(drm_color_ctm_s31_32_to_qm_n, 0xad4e902b, "");
SYMBOL_CRC(drm_crtc_enable_color_mgmt, 0x8a28f53b, "");
SYMBOL_CRC(drm_mode_crtc_set_gamma_size, 0x1ef899d1, "");
SYMBOL_CRC(drm_plane_create_color_properties, 0xe919abb8, "");
SYMBOL_CRC(drm_color_lut_check, 0xb8ebf8d8, "");
SYMBOL_CRC(__drm_debug, 0x4f18a150, "");
SYMBOL_CRC(__drm_puts_coredump, 0x3b0e5e9c, "");
SYMBOL_CRC(__drm_printfn_coredump, 0xea00fe81, "");
SYMBOL_CRC(__drm_puts_seq_file, 0x513072fe, "");
SYMBOL_CRC(__drm_printfn_seq_file, 0xfeb953b1, "");
SYMBOL_CRC(__drm_printfn_info, 0xe317082a, "");
SYMBOL_CRC(__drm_printfn_debug, 0xf824c7db, "");
SYMBOL_CRC(__drm_printfn_err, 0x3f405489, "");
SYMBOL_CRC(drm_puts, 0x521ad6d0, "");
SYMBOL_CRC(drm_printf, 0x28779e52, "");
SYMBOL_CRC(drm_print_bits, 0x32a0cc37, "");
SYMBOL_CRC(drm_dev_printk, 0xe43186d1, "");
SYMBOL_CRC(drm_dev_dbg, 0x59148456, "");
SYMBOL_CRC(__drm_dbg, 0xec12af74, "");
SYMBOL_CRC(__drm_err, 0xb11ac7a7, "");
SYMBOL_CRC(drm_print_regset32, 0x57d5b931, "");
SYMBOL_CRC(drm_mode_config_reset, 0x2e695727, "");
SYMBOL_CRC(drmm_mode_config_init, 0x4893617e, "");
SYMBOL_CRC(drm_mode_config_cleanup, 0x80961b33, "");
SYMBOL_CRC(drm_crtc_accurate_vblank_count, 0x6694dd27, "");
SYMBOL_CRC(drm_vblank_init, 0xc01d25e9, "");
SYMBOL_CRC(drm_dev_has_vblank, 0xe0f818d8, "");
SYMBOL_CRC(drm_crtc_vblank_waitqueue, 0x69e5e376, "");
SYMBOL_CRC(drm_calc_timestamping_constants, 0x4a92cbb6, "");
SYMBOL_CRC(drm_crtc_vblank_helper_get_vblank_timestamp_internal, 0xa3327db7, "");
SYMBOL_CRC(drm_crtc_vblank_helper_get_vblank_timestamp, 0x879b0adc, "");
SYMBOL_CRC(drm_crtc_vblank_count, 0xd371ae64, "");
SYMBOL_CRC(drm_crtc_vblank_count_and_time, 0x1d13db41, "");
SYMBOL_CRC(drm_crtc_arm_vblank_event, 0x8bd0e29f, "");
SYMBOL_CRC(drm_crtc_send_vblank_event, 0xabceb1cb, "");
SYMBOL_CRC(drm_crtc_vblank_get, 0x582ee90f, "");
SYMBOL_CRC(drm_crtc_vblank_put, 0xe8757ff9, "");
SYMBOL_CRC(drm_wait_one_vblank, 0x76a5b55f, "");
SYMBOL_CRC(drm_crtc_wait_one_vblank, 0xf3ee73c5, "");
SYMBOL_CRC(drm_crtc_vblank_off, 0x6baadd76, "");
SYMBOL_CRC(drm_crtc_vblank_reset, 0xedf5ceb6, "");
SYMBOL_CRC(drm_crtc_set_max_vblank_count, 0xee660b2b, "");
SYMBOL_CRC(drm_crtc_vblank_on, 0x6d6e2f6b, "");
SYMBOL_CRC(drm_crtc_vblank_restore, 0x4f3bd1b8, "");
SYMBOL_CRC(drm_handle_vblank, 0xb92e0ba9, "");
SYMBOL_CRC(drm_crtc_handle_vblank, 0xba6ad1ba, "");
SYMBOL_CRC(drm_syncobj_find, 0x2be3b2ec, "");
SYMBOL_CRC(drm_syncobj_add_point, 0x19249204, "");
SYMBOL_CRC(drm_syncobj_replace_fence, 0x6d954f94, "");
SYMBOL_CRC(drm_syncobj_find_fence, 0x54470317, "");
SYMBOL_CRC(drm_syncobj_free, 0x1a411479, "");
SYMBOL_CRC(drm_syncobj_create, 0x1d048b89, "");
SYMBOL_CRC(drm_syncobj_get_handle, 0x156905cb, "");
SYMBOL_CRC(drm_syncobj_get_fd, 0x29a6cfc9, "");
SYMBOL_CRC(drm_timeout_abs_to_jiffies, 0x50674de7, "");
SYMBOL_CRC(drm_writeback_connector_init, 0x233e0bb0, "");
SYMBOL_CRC(drm_writeback_connector_init_with_encoder, 0xd15c79c1, "");
SYMBOL_CRC(drm_writeback_prepare_job, 0x1b3834e0, "");
SYMBOL_CRC(drm_writeback_queue_job, 0xe50b4155, "");
SYMBOL_CRC(drm_writeback_cleanup_job, 0xd1e1fc1a, "");
SYMBOL_CRC(drm_writeback_signal_completion, 0x57a594ca, "");
SYMBOL_CRC(drm_writeback_get_out_fence, 0xa3461e60, "");
SYMBOL_CRC(drm_client_init, 0xa536b179, "");
SYMBOL_CRC(drm_client_register, 0xa6f30b26, "");
SYMBOL_CRC(drm_client_release, 0x4510bbf0, "");
SYMBOL_CRC(drm_client_dev_hotplug, 0x75ac8884, "");
SYMBOL_CRC(drm_client_buffer_vmap, 0x56e63a33, "");
SYMBOL_CRC(drm_client_buffer_vunmap, 0x4eb654c4, "");
SYMBOL_CRC(drm_client_framebuffer_create, 0x90b3815a, "");
SYMBOL_CRC(drm_client_framebuffer_delete, 0x4a68aa2d, "");
SYMBOL_CRC(drm_client_framebuffer_flush, 0x42aef466, "");
SYMBOL_CRC(drm_client_modeset_probe, 0x6a8c4554, "");
SYMBOL_CRC(drm_client_rotation, 0xae2308ab, "");
SYMBOL_CRC(drm_client_modeset_check, 0x39aafb77, "");
SYMBOL_CRC(drm_client_modeset_commit_locked, 0x563591e5, "");
SYMBOL_CRC(drm_client_modeset_commit, 0x06307d12, "");
SYMBOL_CRC(drm_client_modeset_dpms, 0x6d1c494e, "");
SYMBOL_CRC(drm_atomic_set_mode_for_crtc, 0xff308e60, "");
SYMBOL_CRC(drm_atomic_set_mode_prop_for_crtc, 0xe0ddc286, "");
SYMBOL_CRC(drm_atomic_set_crtc_for_plane, 0x8d3e86c5, "");
SYMBOL_CRC(drm_atomic_set_fb_for_plane, 0x8724d601, "");
SYMBOL_CRC(drm_atomic_set_crtc_for_connector, 0x840e865c, "");
SYMBOL_CRC(__drmm_add_action, 0xac316ce1, "");
SYMBOL_CRC(__drmm_add_action_or_reset, 0x7e754496, "");
SYMBOL_CRC(drmm_kmalloc, 0xe4e48c91, "");
SYMBOL_CRC(drmm_kstrdup, 0x8d4891f2, "_gpl");
SYMBOL_CRC(drmm_kfree, 0x49bc34bb, "");
SYMBOL_CRC(drmm_mutex_init, 0x3a45ada9, "");
SYMBOL_CRC(drm_vblank_work_schedule, 0x5eb6a460, "");
SYMBOL_CRC(drm_vblank_work_cancel_sync, 0xab93c665, "");
SYMBOL_CRC(drm_vblank_work_flush, 0x91f6bc77, "");
SYMBOL_CRC(drm_vblank_work_init, 0x7a29f8c3, "");
SYMBOL_CRC(drm_compat_ioctl, 0xb35e9eb7, "");
SYMBOL_CRC(drm_panel_init, 0x38505e42, "");
SYMBOL_CRC(drm_panel_add, 0x71b4708d, "");
SYMBOL_CRC(drm_panel_remove, 0xe6eded86, "");
SYMBOL_CRC(drm_panel_prepare, 0x6845c2d1, "");
SYMBOL_CRC(drm_panel_unprepare, 0x75c8b268, "");
SYMBOL_CRC(drm_panel_enable, 0xf6902744, "");
SYMBOL_CRC(drm_panel_disable, 0xb8f117dc, "");
SYMBOL_CRC(drm_panel_get_modes, 0x0731506a, "");
SYMBOL_CRC(drm_panel_of_backlight, 0x5ff68af9, "");
SYMBOL_CRC(drm_debugfs_create_files, 0x0b15186c, "");
SYMBOL_CRC(drm_debugfs_remove_files, 0xdc8d70d0, "");
SYMBOL_CRC(drm_crtc_add_crc_entry, 0xcb2693a0, "_gpl");
SYMBOL_CRC(__drm_set_edid_firmware_path, 0x31b8a5e3, "");
SYMBOL_CRC(__drm_get_edid_firmware_path, 0x03c63897, "");
SYMBOL_CRC(drm_privacy_screen_lookup_add, 0x2f476172, "");
SYMBOL_CRC(drm_privacy_screen_lookup_remove, 0x0eb7f5eb, "");
SYMBOL_CRC(drm_privacy_screen_get, 0x768a04ac, "");
SYMBOL_CRC(drm_privacy_screen_put, 0xc620818b, "");
SYMBOL_CRC(drm_privacy_screen_set_sw_state, 0x621a0d1e, "");
SYMBOL_CRC(drm_privacy_screen_get_state, 0x5e2530c5, "");
SYMBOL_CRC(drm_privacy_screen_register_notifier, 0xa261618c, "");
SYMBOL_CRC(drm_privacy_screen_unregister_notifier, 0x571fc632, "");
SYMBOL_CRC(drm_privacy_screen_register, 0x882d78bc, "");
SYMBOL_CRC(drm_privacy_screen_unregister, 0x79ba7f31, "");
SYMBOL_CRC(drm_privacy_screen_call_notifier_chain, 0xc13f83a2, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc8dcc62a, "krealloc" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xcabcd476, "anon_inode_getfile" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xd8cef6e1, "clear_user" },
	{ 0xcef6fc7a, "ww_mutex_lock_interruptible" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0xbdde263a, "alloc_anon_inode" },
	{ 0x1730463a, "show_class_attr_string" },
	{ 0x96af87e5, "kthread_cancel_work_sync" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0xe6e15da0, "kthread_create_worker" },
	{ 0x551bd071, "__rb_erase_color" },
	{ 0x6c926b1c, "kthread_flush_work" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x20978fb9, "idr_find" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x53245c91, "dma_resv_init" },
	{ 0x494e3393, "vm_get_page_prot" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x9c35a889, "dma_resv_wait_timeout" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xca9360b5, "rb_next" },
	{ 0x8b618d08, "overflowuid" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0xd4e72892, "kthread_flush_worker" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x6749d53f, "hdmi_vendor_infoframe_init" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x96848186, "scnprintf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x2e80b5ac, "ww_mutex_unlock" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x75d0deb9, "nsecs_to_jiffies64" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0xbd8bbd97, "fd_install" },
	{ 0x2293ac3, "dma_fence_chain_ops" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x79cc14e8, "unmap_mapping_range" },
	{ 0x37a0cba, "kfree" },
	{ 0xbcd4b433, "iput" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x32c2a6dc, "__pagevec_release" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x8e21c9a1, "dma_fence_add_callback" },
	{ 0xfe5d8404, "synchronize_srcu" },
	{ 0xa40a8382, "get_device" },
	{ 0xf75af443, "dma_buf_attach" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x907d14d, "blocking_notifier_chain_register" },
	{ 0x5764f9cf, "class_create_file_ns" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x23312d0a, "vga_switcheroo_unlock_ddc" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xf20b7eac, "ww_mutex_trylock" },
	{ 0x1e180698, "register_acpi_bus_type" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0x823eae06, "blocking_notifier_call_chain" },
	{ 0x884c903f, "devm_of_find_backlight" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xff44f9f8, "dma_max_mapping_size" },
	{ 0x3197c4e3, "put_device" },
	{ 0xf82ec573, "rb_prev" },
	{ 0xf6d59ef0, "dma_fence_array_create" },
	{ 0xba6e4b5e, "dma_buf_export" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xa916b694, "strnlen" },
	{ 0x97fa4dd1, "dma_buf_map_attachment" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0xf4753987, "kthread_queue_work" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x3b20fb95, "dma_fence_remove_callback" },
	{ 0x2587f789, "_dev_info" },
	{ 0xb1c3a01a, "oops_in_progress" },
	{ 0xc6cbbc89, "capable" },
	{ 0x1de23e95, "module_put" },
	{ 0xcfc9deaf, "atomic_dec_and_mutex_lock" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x365e7911, "kstrdup_const" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xb290ada, "dma_fence_chain_walk" },
	{ 0xc32503b3, "mark_page_accessed" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0xc9ff5b23, "__task_pid_nr_ns" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0x4ea5d10, "ksize" },
	{ 0x4e547048, "__kmalloc_node_track_caller" },
	{ 0xce286cf0, "shmem_file_setup" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x98378a1d, "cc_mkdec" },
	{ 0x13f26ae, "dma_fence_get_stub" },
	{ 0x2e439142, "drm_get_panel_orientation_quirk" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd28f6a7f, "fput" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb7c0f443, "sort" },
	{ 0x380eaa4, "dma_buf_unmap_attachment" },
	{ 0x37fc612e, "vga_remove_vgacon" },
	{ 0x14605535, "dma_fence_context_alloc" },
	{ 0x48098f3, "device_add" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x10f74645, "pid_task" },
	{ 0xd0c5aa1a, "vga_switcheroo_lock_ddc" },
	{ 0x3fe3b715, "__srcu_read_lock" },
	{ 0x587b0954, "kvasprintf" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x731c4a9c, "dma_fence_signal" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0xdec64e96, "dma_resv_fini" },
	{ 0x954f099c, "idr_preload" },
	{ 0x7c9ca58f, "__sg_page_iter_next" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x120b336a, "__rb_insert_augmented" },
	{ 0xfbb8a761, "strscpy_pad" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x81808c2b, "dma_buf_get" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x5a921311, "strncmp" },
	{ 0x593b6030, "ww_mutex_lock" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x9166fada, "strncpy" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x6dcda273, "shmem_read_mapping_page_gfp" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xd0f82335, "dma_buf_put" },
	{ 0xffb7c514, "ida_free" },
	{ 0x85479ed4, "dma_buf_fd" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x16dee44d, "dma_fence_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xab781570, "fb_get_options" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x422066d2, "device_register" },
	{ 0x3312881b, "device_del" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x558e68f5, "sg_alloc_table_from_pages_segment" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xb9056bb6, "remove_conflicting_framebuffers" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x223bb837, "unregister_acpi_bus_type" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x50d1f870, "pgprot_writecombine" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x131db64a, "system_long_wq" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xf474fdcb, "kfree_const" },
	{ 0x7fe32873, "rb_replace_node" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa57ddaa1, "set_page_dirty" },
	{ 0x5d8a72fe, "init_pseudo" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0xf2b11959, "seq_read" },
	{ 0xeb7f6046, "acpi_get_devices" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x25e58a09, "hdmi_avi_infoframe_init" },
	{ 0x1d40b6f3, "idr_for_each" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xdd64e639, "strscpy" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x4ece3615, "blocking_notifier_chain_unregister" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0xb48c62a2, "remove_conflicting_pci_framebuffers" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x93636f65, "dma_map_sgtable" },
	{ 0x56dc6f0a, "kthread_destroy_worker" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x1d07e365, "memdup_user_nul" },
	{ 0xf25bbf52, "dentry_open" },
	{ 0xe091c977, "list_sort" },
	{ 0x87b8798d, "sg_next" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xccd4c999, "__sg_page_iter_start" },
	{ 0x9d5e063, "seq_write" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xdc7f53cc, "platform_bus_type" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6d5f5b91, "radix_tree_tagged" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x66e38f89, "__srcu_read_unlock" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x1486ded2, "dma_fence_allocate_private_stub" },
	{ 0x25fdcdad, "dma_buf_detach" },
	{ 0x629079b3, "dma_fence_signal_timestamp" },
	{ 0xf583938e, "dma_fence_chain_init" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x391de184, "seq_puts" },
	{ 0xbb2b861a, "single_release" },
	{ 0xcb6f0ffa, "check_move_unevictable_pages" },
	{ 0x12d2c8c8, "pid_vnr" },
	{ 0x8f2703b7, "wbinvd_on_all_cpus" },
	{ 0xcd34c8dd, "sched_set_fifo" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xe1fea7df, "simple_release_fs" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x82b7c307, "kill_anon_super" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0x81188c30, "match_string" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xc7a1840e, "llist_add_batch" },
	{ 0xe123f3d9, "dma_fence_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcc328a5c, "reservation_ww_class" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x754d539c, "strlen" },
	{ 0x77358855, "iomem_resource" },
	{ 0x4e4f0f16, "dma_fence_chain_find_seqno" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xb82ba28c, "single_open" },
	{ 0x349cba85, "strchr" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xabdc439, "cc_platform_has" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x4dca08ee, "sync_file_get_fence" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x2d8ca4a3, "put_pid" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x791a408b, "pci_bus_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x25032414, "class_remove_file_ns" },
	{ 0x391c079, "simple_pin_fs" },
	{ 0x37cc15c4, "sync_file_create" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xcc445ceb, "__sg_page_iter_dma_next" },
	{ 0x6b2b69f7, "static_key_enable" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DCA303E905C65D171652857");
