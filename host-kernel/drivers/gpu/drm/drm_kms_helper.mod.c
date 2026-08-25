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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(drm_bridge_connector_enable_hpd, 0xb9c18433, "_gpl");
SYMBOL_CRC(drm_bridge_connector_disable_hpd, 0x835cce2a, "_gpl");
SYMBOL_CRC(drm_bridge_connector_init, 0x5df14469, "_gpl");
SYMBOL_CRC(drm_helper_encoder_in_use, 0x41569a81, "");
SYMBOL_CRC(drm_helper_crtc_in_use, 0x549baa77, "");
SYMBOL_CRC(drm_helper_disable_unused_functions, 0xc00816c4, "");
SYMBOL_CRC(drm_crtc_helper_set_mode, 0x1a0f57db, "");
SYMBOL_CRC(drm_crtc_helper_set_config, 0x47b1831d, "");
SYMBOL_CRC(drm_helper_connector_dpms, 0x778498e5, "");
SYMBOL_CRC(drm_helper_resume_force_mode, 0x04b75a00, "");
SYMBOL_CRC(drm_helper_force_disable_all, 0xb2f30866, "");
SYMBOL_CRC(drm_i2c_encoder_init, 0x8c37df67, "");
SYMBOL_CRC(drm_i2c_encoder_destroy, 0xcef59382, "");
SYMBOL_CRC(drm_i2c_encoder_dpms, 0x364730fe, "");
SYMBOL_CRC(drm_i2c_encoder_mode_fixup, 0xdd5adc8f, "");
SYMBOL_CRC(drm_i2c_encoder_prepare, 0x406756b8, "");
SYMBOL_CRC(drm_i2c_encoder_commit, 0xa9efc818, "");
SYMBOL_CRC(drm_i2c_encoder_mode_set, 0x7f27a5e0, "");
SYMBOL_CRC(drm_i2c_encoder_detect, 0xba1d369c, "");
SYMBOL_CRC(drm_i2c_encoder_save, 0xa46c5504, "");
SYMBOL_CRC(drm_i2c_encoder_restore, 0x064a24a4, "");
SYMBOL_CRC(drm_flip_work_allocate_task, 0xcf11a549, "");
SYMBOL_CRC(drm_flip_work_queue_task, 0x21d541eb, "");
SYMBOL_CRC(drm_flip_work_queue, 0x127a8c6b, "");
SYMBOL_CRC(drm_flip_work_commit, 0x842dd90c, "");
SYMBOL_CRC(drm_flip_work_init, 0x5542443b, "");
SYMBOL_CRC(drm_flip_work_cleanup, 0xc6323239, "");
SYMBOL_CRC(drm_kms_helper_poll_enable, 0x58f58fff, "");
SYMBOL_CRC(drm_helper_probe_detect, 0xd22ae4c7, "");
SYMBOL_CRC(drm_helper_probe_single_connector_modes, 0x5907632e, "");
SYMBOL_CRC(drm_kms_helper_hotplug_event, 0x6204a1c1, "");
SYMBOL_CRC(drm_kms_helper_connector_hotplug_event, 0xded3c0c0, "");
SYMBOL_CRC(drm_kms_helper_is_poll_worker, 0x5a4734d1, "");
SYMBOL_CRC(drm_kms_helper_poll_disable, 0xa508ab8b, "");
SYMBOL_CRC(drm_kms_helper_poll_init, 0x2295bc93, "");
SYMBOL_CRC(drm_kms_helper_poll_fini, 0x615e2f98, "");
SYMBOL_CRC(drm_connector_helper_hpd_irq_event, 0xf16cb585, "");
SYMBOL_CRC(drm_helper_hpd_irq_event, 0x59c4b9de, "");
SYMBOL_CRC(drm_primary_helper_destroy, 0x6d1c8700, "");
SYMBOL_CRC(drm_primary_helper_funcs, 0x59b8fff6, "");
SYMBOL_CRC(drm_atomic_helper_check_modeset, 0x79245dac, "");
SYMBOL_CRC(drm_atomic_helper_check_plane_state, 0xe5259331, "");
SYMBOL_CRC(drm_atomic_helper_check_planes, 0x7f4618bc, "");
SYMBOL_CRC(drm_atomic_helper_check, 0xef7dbcda, "");
SYMBOL_CRC(drm_atomic_helper_update_legacy_modeset_state, 0x4e2cb4a5, "");
SYMBOL_CRC(drm_atomic_helper_calc_timestamping_constants, 0x40ead7a2, "");
SYMBOL_CRC(drm_atomic_helper_commit_modeset_disables, 0x69e8aa87, "");
SYMBOL_CRC(drm_atomic_helper_commit_modeset_enables, 0xca04a8d3, "");
SYMBOL_CRC(drm_atomic_helper_wait_for_fences, 0x1ef63e83, "");
SYMBOL_CRC(drm_atomic_helper_wait_for_vblanks, 0x20a4b1e6, "");
SYMBOL_CRC(drm_atomic_helper_wait_for_flip_done, 0x20ec69d6, "");
SYMBOL_CRC(drm_atomic_helper_commit_tail, 0x8c19b9fa, "");
SYMBOL_CRC(drm_atomic_helper_commit_tail_rpm, 0xa960fddb, "");
SYMBOL_CRC(drm_atomic_helper_async_check, 0x64e66cf1, "");
SYMBOL_CRC(drm_atomic_helper_async_commit, 0x88c4b9cd, "");
SYMBOL_CRC(drm_atomic_helper_commit, 0xe8ad0188, "");
SYMBOL_CRC(drm_atomic_helper_setup_commit, 0x468087ab, "");
SYMBOL_CRC(drm_atomic_helper_wait_for_dependencies, 0x6c30a826, "");
SYMBOL_CRC(drm_atomic_helper_fake_vblank, 0xa7733894, "");
SYMBOL_CRC(drm_atomic_helper_commit_hw_done, 0xb64b4823, "");
SYMBOL_CRC(drm_atomic_helper_commit_cleanup_done, 0xdac7cbb9, "");
SYMBOL_CRC(drm_atomic_helper_prepare_planes, 0xdbd29c5b, "");
SYMBOL_CRC(drm_atomic_helper_commit_planes, 0x3a47a690, "");
SYMBOL_CRC(drm_atomic_helper_commit_planes_on_crtc, 0xbf1a0eba, "");
SYMBOL_CRC(drm_atomic_helper_disable_planes_on_crtc, 0xc12897eb, "");
SYMBOL_CRC(drm_atomic_helper_cleanup_planes, 0x35552f56, "");
SYMBOL_CRC(drm_atomic_helper_swap_state, 0x603952f4, "");
SYMBOL_CRC(drm_atomic_helper_update_plane, 0xf89c0ce4, "");
SYMBOL_CRC(drm_atomic_helper_disable_plane, 0x60409e8d, "");
SYMBOL_CRC(drm_atomic_helper_set_config, 0xdb63f629, "");
SYMBOL_CRC(drm_atomic_helper_disable_all, 0xfd6a7b84, "");
SYMBOL_CRC(drm_atomic_helper_shutdown, 0x29442fd5, "");
SYMBOL_CRC(drm_atomic_helper_duplicate_state, 0xb13c00ab, "");
SYMBOL_CRC(drm_atomic_helper_suspend, 0xaea842cd, "");
SYMBOL_CRC(drm_atomic_helper_commit_duplicated_state, 0x152d4d82, "");
SYMBOL_CRC(drm_atomic_helper_resume, 0x2f5c461b, "");
SYMBOL_CRC(drm_atomic_helper_page_flip, 0x3505be55, "");
SYMBOL_CRC(drm_atomic_helper_page_flip_target, 0x803c96f3, "");
SYMBOL_CRC(drm_atomic_helper_bridge_propagate_bus_fmt, 0x4233b181, "");
SYMBOL_CRC(drm_simple_encoder_init, 0xea8ee118, "");
SYMBOL_CRC(__drmm_simple_encoder_alloc, 0x26c1c6b7, "");
SYMBOL_CRC(drm_simple_display_pipe_attach_bridge, 0xdd2cfbbd, "");
SYMBOL_CRC(drm_simple_display_pipe_init, 0xe88ebc52, "");
SYMBOL_CRC(drm_helper_move_panel_connectors_to_head, 0xed947255, "");
SYMBOL_CRC(drm_helper_mode_fill_fb_struct, 0x696478f1, "");
SYMBOL_CRC(drm_crtc_init, 0x0698e1c3, "");
SYMBOL_CRC(drm_mode_config_helper_suspend, 0x6b3849c7, "");
SYMBOL_CRC(drm_mode_config_helper_resume, 0x1c1b6a3e, "");
SYMBOL_CRC(drm_gem_plane_helper_prepare_fb, 0x0e1c6437, "_gpl");
SYMBOL_CRC(drm_gem_simple_display_pipe_prepare_fb, 0xd48b61ad, "");
SYMBOL_CRC(__drm_gem_duplicate_shadow_plane_state, 0x34319b14, "");
SYMBOL_CRC(drm_gem_duplicate_shadow_plane_state, 0x1a541329, "");
SYMBOL_CRC(__drm_gem_destroy_shadow_plane_state, 0x2a539838, "");
SYMBOL_CRC(drm_gem_destroy_shadow_plane_state, 0xe26f879c, "");
SYMBOL_CRC(__drm_gem_reset_shadow_plane, 0x5ea5344d, "");
SYMBOL_CRC(drm_gem_reset_shadow_plane, 0xab2a3778, "");
SYMBOL_CRC(drm_gem_prepare_shadow_fb, 0xe2184644, "");
SYMBOL_CRC(drm_gem_cleanup_shadow_fb, 0x821024a2, "");
SYMBOL_CRC(drm_gem_simple_kms_prepare_shadow_fb, 0x116007b8, "");
SYMBOL_CRC(drm_gem_simple_kms_cleanup_shadow_fb, 0x5cc83965, "");
SYMBOL_CRC(drm_gem_simple_kms_reset_shadow_plane, 0x6660ba7b, "");
SYMBOL_CRC(drm_gem_simple_kms_duplicate_shadow_plane_state, 0x664da421, "");
SYMBOL_CRC(drm_gem_simple_kms_destroy_shadow_plane_state, 0x62627e7e, "");
SYMBOL_CRC(drm_gem_fb_get_obj, 0xe3ca4fc5, "_gpl");
SYMBOL_CRC(drm_gem_fb_destroy, 0x416c1e62, "");
SYMBOL_CRC(drm_gem_fb_create_handle, 0xa29aeb66, "");
SYMBOL_CRC(drm_gem_fb_init_with_funcs, 0xb9f621a9, "_gpl");
SYMBOL_CRC(drm_gem_fb_create_with_funcs, 0x2b7d170c, "_gpl");
SYMBOL_CRC(drm_gem_fb_create, 0x17eb1a70, "_gpl");
SYMBOL_CRC(drm_gem_fb_create_with_dirty, 0x22a8c36f, "_gpl");
SYMBOL_CRC(drm_gem_fb_vmap, 0x7723a66c, "");
SYMBOL_CRC(drm_gem_fb_vunmap, 0x314638f6, "");
SYMBOL_CRC(drm_gem_fb_begin_cpu_access, 0x5043ea76, "");
SYMBOL_CRC(drm_gem_fb_end_cpu_access, 0x959eaca3, "");
SYMBOL_CRC(drm_gem_fb_afbc_init, 0xbcfaaed6, "_gpl");
SYMBOL_CRC(__drm_atomic_helper_crtc_state_reset, 0xd6160466, "");
SYMBOL_CRC(__drm_atomic_helper_crtc_reset, 0xd1875d31, "");
SYMBOL_CRC(drm_atomic_helper_crtc_reset, 0x5a826a51, "");
SYMBOL_CRC(__drm_atomic_helper_crtc_duplicate_state, 0xcf2c1175, "");
SYMBOL_CRC(drm_atomic_helper_crtc_duplicate_state, 0x9c81e7bc, "");
SYMBOL_CRC(__drm_atomic_helper_crtc_destroy_state, 0xf69d620c, "");
SYMBOL_CRC(drm_atomic_helper_crtc_destroy_state, 0x7c7e1b58, "");
SYMBOL_CRC(__drm_atomic_helper_plane_state_reset, 0x5ed8c9f2, "");
SYMBOL_CRC(__drm_atomic_helper_plane_reset, 0x411535ae, "");
SYMBOL_CRC(drm_atomic_helper_plane_reset, 0xd42f4adc, "");
SYMBOL_CRC(__drm_atomic_helper_plane_duplicate_state, 0x7d08011a, "");
SYMBOL_CRC(drm_atomic_helper_plane_duplicate_state, 0x5642d92d, "");
SYMBOL_CRC(__drm_atomic_helper_plane_destroy_state, 0x237e86c3, "");
SYMBOL_CRC(drm_atomic_helper_plane_destroy_state, 0xa59d3ac7, "");
SYMBOL_CRC(__drm_atomic_helper_connector_state_reset, 0x2f04171d, "");
SYMBOL_CRC(__drm_atomic_helper_connector_reset, 0xe091538c, "");
SYMBOL_CRC(drm_atomic_helper_connector_reset, 0x89cd6dc0, "");
SYMBOL_CRC(drm_atomic_helper_connector_tv_reset, 0x9491f4f9, "");
SYMBOL_CRC(__drm_atomic_helper_connector_duplicate_state, 0x76f7ec51, "");
SYMBOL_CRC(drm_atomic_helper_connector_duplicate_state, 0xd287444b, "");
SYMBOL_CRC(__drm_atomic_helper_connector_destroy_state, 0x35a69950, "");
SYMBOL_CRC(drm_atomic_helper_connector_destroy_state, 0x6357ffa3, "");
SYMBOL_CRC(__drm_atomic_helper_private_obj_duplicate_state, 0x44e182e6, "");
SYMBOL_CRC(__drm_atomic_helper_bridge_duplicate_state, 0xc489644b, "");
SYMBOL_CRC(drm_atomic_helper_bridge_duplicate_state, 0xb3f593c8, "");
SYMBOL_CRC(drm_atomic_helper_bridge_destroy_state, 0xebd9bd17, "");
SYMBOL_CRC(__drm_atomic_helper_bridge_reset, 0x85cee047, "");
SYMBOL_CRC(drm_atomic_helper_bridge_reset, 0x78fc2624, "");
SYMBOL_CRC(drm_atomic_helper_check_plane_damage, 0x1fd50129, "");
SYMBOL_CRC(drm_atomic_helper_dirtyfb, 0xde209868, "");
SYMBOL_CRC(drm_atomic_helper_damage_iter_init, 0x06a44103, "");
SYMBOL_CRC(drm_atomic_helper_damage_iter_next, 0x6b5c2b06, "");
SYMBOL_CRC(drm_atomic_helper_damage_merged, 0xc8e9adac, "");
SYMBOL_CRC(drm_fb_clip_offset, 0xf30db916, "");
SYMBOL_CRC(drm_fb_memcpy, 0x28c06c53, "");
SYMBOL_CRC(drm_fb_memcpy_toio, 0x245c534d, "");
SYMBOL_CRC(drm_fb_swab, 0xae1977d3, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_rgb332, 0x551a5aad, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_rgb565, 0xf7048cb7, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_rgb565_toio, 0x6b8606f9, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_rgb888, 0xb6c949f4, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_rgb888_toio, 0x91a4d3dc, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_xrgb2101010_toio, 0x25e9906c, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_gray8, 0x8ec5fdd3, "");
SYMBOL_CRC(drm_fb_blit_toio, 0xfffe38f7, "");
SYMBOL_CRC(drm_fb_xrgb8888_to_mono, 0xea59de2f, "");
SYMBOL_CRC(drm_self_refresh_helper_update_avg_times, 0x1da0184b, "");
SYMBOL_CRC(drm_self_refresh_helper_alter_state, 0xd3805789, "");
SYMBOL_CRC(drm_self_refresh_helper_init, 0xef49d65c, "");
SYMBOL_CRC(drm_self_refresh_helper_cleanup, 0xff744f2d, "");
SYMBOL_CRC(drm_rect_intersect, 0x871ab41a, "");
SYMBOL_CRC(drm_rect_clip_scaled, 0x99fd20aa, "");
SYMBOL_CRC(drm_rect_calc_hscale, 0x2d50570f, "");
SYMBOL_CRC(drm_rect_calc_vscale, 0x91fec1cc, "");
SYMBOL_CRC(drm_rect_debug_print, 0xcb2340b8, "");
SYMBOL_CRC(drm_rect_rotate, 0xb053adda, "");
SYMBOL_CRC(drm_rect_rotate_inv, 0x6e30ba8e, "");
SYMBOL_CRC(drm_panel_bridge_add, 0x285fb7ff, "");
SYMBOL_CRC(drm_panel_bridge_add_typed, 0xf9a7a68b, "");
SYMBOL_CRC(drm_panel_bridge_remove, 0x66fe5cf6, "");
SYMBOL_CRC(devm_drm_panel_bridge_add, 0x9bfdaab0, "");
SYMBOL_CRC(devm_drm_panel_bridge_add_typed, 0xc0d5009b, "");
SYMBOL_CRC(drm_panel_bridge_connector, 0x6284b33a, "");
SYMBOL_CRC(drm_fb_helper_debug_enter, 0x2038da42, "");
SYMBOL_CRC(drm_fb_helper_debug_leave, 0x291f0042, "");
SYMBOL_CRC(drm_fb_helper_restore_fbdev_mode_unlocked, 0x704aece9, "");
SYMBOL_CRC(drm_fb_helper_blank, 0x3a0c7507, "");
SYMBOL_CRC(drm_fb_helper_prepare, 0x5bcf5897, "");
SYMBOL_CRC(drm_fb_helper_init, 0x8d64ac1c, "");
SYMBOL_CRC(drm_fb_helper_alloc_fbi, 0x45d68b78, "");
SYMBOL_CRC(drm_fb_helper_unregister_fbi, 0xceb85f42, "");
SYMBOL_CRC(drm_fb_helper_fini, 0x2ce58257, "");
SYMBOL_CRC(drm_fb_helper_deferred_io, 0x243466b1, "");
SYMBOL_CRC(drm_fb_helper_sys_read, 0x503fff49, "");
SYMBOL_CRC(drm_fb_helper_sys_write, 0xf6f0f948, "");
SYMBOL_CRC(drm_fb_helper_sys_fillrect, 0x5577c12f, "");
SYMBOL_CRC(drm_fb_helper_sys_copyarea, 0x32070e7e, "");
SYMBOL_CRC(drm_fb_helper_sys_imageblit, 0xc128fd82, "");
SYMBOL_CRC(drm_fb_helper_cfb_fillrect, 0x22ec6284, "");
SYMBOL_CRC(drm_fb_helper_cfb_copyarea, 0x459cadd5, "");
SYMBOL_CRC(drm_fb_helper_cfb_imageblit, 0x5b135546, "");
SYMBOL_CRC(drm_fb_helper_set_suspend, 0xaad1b631, "");
SYMBOL_CRC(drm_fb_helper_set_suspend_unlocked, 0x6dd47092, "");
SYMBOL_CRC(drm_fb_helper_setcmap, 0x593cd573, "");
SYMBOL_CRC(drm_fb_helper_ioctl, 0xd8f3ba89, "");
SYMBOL_CRC(drm_fb_helper_check_var, 0xb268cabe, "");
SYMBOL_CRC(drm_fb_helper_set_par, 0x2ae60448, "");
SYMBOL_CRC(drm_fb_helper_pan_display, 0x346a29df, "");
SYMBOL_CRC(drm_fb_helper_fill_info, 0x1401cf77, "");
SYMBOL_CRC(drm_fb_helper_initial_config, 0xa8de2a5f, "");
SYMBOL_CRC(drm_fb_helper_hotplug_event, 0x90c65f80, "");
SYMBOL_CRC(drm_fb_helper_lastclose, 0xb7da87a8, "");
SYMBOL_CRC(drm_fb_helper_output_poll_changed, 0x4833b272, "");
SYMBOL_CRC(drm_fbdev_generic_setup, 0x3f2b2c58, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xf0e5d263, "drm_framebuffer_cleanup" },
	{ 0xa6f30b26, "drm_client_register" },
	{ 0x1b3834e0, "drm_writeback_prepare_job" },
	{ 0xf1b5340a, "drm_mode_vrefresh" },
	{ 0x731506a, "drm_panel_get_modes" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xe8ca04e6, "drm_connector_list_update" },
	{ 0x399e2175, "drm_bridge_add" },
	{ 0x25b1f6c9, "drm_bridge_chain_mode_valid" },
	{ 0x29f078d1, "drm_mode_legacy_fb_format" },
	{ 0x9d2e7707, "unregister_sysrq_key" },
	{ 0xb2568e5, "drm_connector_register" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0xbace46e4, "drm_add_override_edid_modes" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x56e63a33, "drm_client_buffer_vmap" },
	{ 0xae2308ab, "drm_client_rotation" },
	{ 0xf6902744, "drm_panel_enable" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x7c92bd35, "drm_framebuffer_init" },
	{ 0x450fdce, "drm_mode_validate_driver" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0x152407ec, "drm_atomic_add_affected_planes" },
	{ 0x4874bb69, "dma_buf_end_cpu_access" },
	{ 0xf53089ee, "drm_modeset_unlock_all" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0xc5ca5a49, "drm_atomic_add_affected_connectors" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x1e043a91, "drm_bridge_hpd_enable" },
	{ 0xd371ae64, "drm_crtc_vblank_count" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x9b515cb6, "drm_modeset_lock_all" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x4a68aa2d, "drm_client_framebuffer_delete" },
	{ 0xd9b4753, "drm_mode_equal" },
	{ 0x90b3815a, "drm_client_framebuffer_create" },
	{ 0xef42bfcb, "drm_atomic_bridge_chain_enable" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x63667dc7, "drm_mode_object_get" },
	{ 0x69acdf38, "memcpy" },
	{ 0xb35a6edf, "drm_gem_vmap" },
	{ 0x37a0cba, "kfree" },
	{ 0xb9cad492, "__drm_atomic_state_free" },
	{ 0x554ac3d, "drm_crtc_cleanup" },
	{ 0xea3f7773, "drm_gem_vunmap" },
	{ 0x47283066, "drm_connector_list_iter_begin" },
	{ 0x32294d1f, "fb_deferred_io_init" },
	{ 0xc46551d5, "drm_mode_set_config_internal" },
	{ 0x16cb454, "fb_deferred_io_cleanup" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x3082b526, "drm_encoder_cleanup" },
	{ 0x51d9d03f, "drm_connector_unregister" },
	{ 0xa0761407, "drm_modeset_acquire_init" },
	{ 0x6a8c4554, "drm_client_modeset_probe" },
	{ 0xfd0336fc, "drm_warn_on_modeset_not_all_locked" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xdd87e544, "drm_plane_get_damage_clips" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xea900f57, "devres_add" },
	{ 0x98c039dc, "dma_fence_wait_timeout" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa2b8d0d4, "drm_add_modes_noedid" },
	{ 0xf9a97e7c, "drm_bridge_remove" },
	{ 0xa96a098c, "drm_mode_object_put" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x582ee90f, "drm_crtc_vblank_get" },
	{ 0x2330f595, "drm_gem_object_lookup" },
	{ 0xabceb1cb, "drm_crtc_send_vblank_event" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2ed3c600, "drm_mode_debug_printmodeline" },
	{ 0xd3f2af1e, "fb_sys_write" },
	{ 0xef9eb55a, "drm_atomic_normalize_zpos" },
	{ 0xe0c922d3, "drm_sysfs_hotplug_event" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x77e93483, "drm_bridge_hpd_disable" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x3e343b7b, "sys_imageblit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xedf5ceb6, "drm_crtc_vblank_reset" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x40d04664, "console_trylock" },
	{ 0x63000ec2, "sys_fillrect" },
	{ 0xa86fee46, "drm_connector_list_iter_end" },
	{ 0x8d3e86c5, "drm_atomic_set_crtc_for_plane" },
	{ 0x6d1c494e, "drm_client_modeset_dpms" },
	{ 0xf264d236, "drm_mode_prune_invalid" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x75ac8884, "drm_client_dev_hotplug" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0x56ac5181, "dma_resv_get_singleton" },
	{ 0xb1c3a01a, "oops_in_progress" },
	{ 0x5eb85eee, "drm_plane_cleanup" },
	{ 0x4575a0ca, "drm_mode_set_crtcinfo" },
	{ 0x1de23e95, "module_put" },
	{ 0xc7cf1c73, "dma_buf_begin_cpu_access" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc5eb3e89, "drm_atomic_get_crtc_state" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0xa536b179, "drm_client_init" },
	{ 0xf3ee73c5, "drm_crtc_wait_one_vblank" },
	{ 0x1209d56d, "__drmm_encoder_alloc" },
	{ 0x800473f, "__cond_resched" },
	{ 0xd7a9cf42, "drm_mode_validate_size" },
	{ 0xe1fb555d, "drm_modeset_lock" },
	{ 0x563591e5, "drm_client_modeset_commit_locked" },
	{ 0xa11ff8d2, "drm_modeset_unlock" },
	{ 0xb8f117dc, "drm_panel_disable" },
	{ 0x1dbcd55d, "drm_property_replace_blob" },
	{ 0xb22dfd68, "drm_format_info_min_pitch" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd1e1fc1a, "drm_writeback_cleanup_job" },
	{ 0x396abd95, "drm_modeset_lock_all_ctx" },
	{ 0x97ff9a18, "i2c_unregister_device" },
	{ 0x8724d601, "drm_atomic_set_fb_for_plane" },
	{ 0xb55c053f, "drm_connector_init_with_ddc" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xccc59759, "drm_format_info_block_width" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x39d7d3b4, "drm_crtc_commit_wait" },
	{ 0xe0f818d8, "drm_dev_has_vblank" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0xcd30e701, "__drm_atomic_helper_disable_plane" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x435f223e, "drm_gem_handle_create" },
	{ 0x840e865c, "drm_atomic_set_crtc_for_connector" },
	{ 0xb62fbf91, "drm_crtc_init_with_planes" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe8757ff9, "drm_crtc_vblank_put" },
	{ 0x73965ef6, "i2c_new_client_device" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x4cfc520c, "drm_plane_get_damage_clips_count" },
	{ 0xe40f7318, "drm_atomic_commit" },
	{ 0x9ce050be, "drm_mode_copy" },
	{ 0xc5f26a2b, "fb_deferred_io_mmap" },
	{ 0x97d52e9c, "drm_atomic_state_alloc" },
	{ 0x6307d12, "drm_client_modeset_commit" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x7e92c5b2, "drm_atomic_bridge_chain_post_disable" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x88ab6fe3, "kgdb_active" },
	{ 0x31b8a5e3, "__drm_set_edid_firmware_path" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc631580a, "console_unlock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0x4510bbf0, "drm_client_release" },
	{ 0xae277372, "__drm_crtc_commit_free" },
	{ 0x8d72789e, "drm_edid_is_valid" },
	{ 0xc75a9e1c, "__drm_atomic_helper_set_config" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0xe0ddc286, "drm_atomic_set_mode_prop_for_crtc" },
	{ 0xc82982eb, "drm_get_format_info" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x248c29c8, "drm_universal_plane_init" },
	{ 0x6d606913, "pv_ops" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0x1a1c7d7f, "sys_copyarea" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xf15ca581, "drm_connector_list_iter_next" },
	{ 0x19ad1a2e, "drm_modeset_acquire_fini" },
	{ 0x89023912, "drm_encoder_init" },
	{ 0x999e8297, "vfree" },
	{ 0x58d4099c, "drm_object_property_get_default_value" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xdfcc992c, "current_work" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x98660e3a, "drm_master_internal_acquire" },
	{ 0xe93e49c3, "devres_free" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x59bf89d9, "drm_modeset_backoff" },
	{ 0x6845c2d1, "drm_panel_prepare" },
	{ 0x27b8c079, "drm_bridge_chain_mode_set" },
	{ 0x4eb654c4, "drm_client_buffer_vunmap" },
	{ 0xf1421d13, "drm_mode_sort" },
	{ 0xd1be46b0, "fb_sys_read" },
	{ 0x3c63897, "__drm_get_edid_firmware_path" },
	{ 0x43a90f84, "drm_atomic_get_plane_state" },
	{ 0xedcddbe6, "drm_atomic_bridge_chain_check" },
	{ 0xf583938e, "dma_fence_chain_init" },
	{ 0xb868ac5c, "register_sysrq_key" },
	{ 0xebd3d19a, "drm_property_blob_get" },
	{ 0xd4c14632, "system_unbound_wq" },
	{ 0x33dd80c8, "drm_property_blob_put" },
	{ 0xb2dfc9b5, "drm_mode_destroy" },
	{ 0x86332e44, "drm_bridge_attach" },
	{ 0x1649d232, "drm_atomic_bridge_chain_pre_enable" },
	{ 0x4eb69e45, "drm_atomic_state_clear" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x84c06699, "drm_property_create_blob" },
	{ 0x6ef2f78e, "drm_format_info" },
	{ 0xd76aa523, "drm_modeset_drop_locks" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xe123f3d9, "dma_fence_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcf3b5bf4, "drm_atomic_bridge_chain_disable" },
	{ 0x38e0d0c1, "drm_mode_create_from_cmdline_mode" },
	{ 0x7cd670e5, "drm_mode_validate_ycbcr420" },
	{ 0xca190085, "drm_format_info_block_height" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xf62ddb6f, "drm_atomic_nonblocking_commit" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x21ef374c, "try_wait_for_completion" },
	{ 0x33dec24c, "drm_master_internal_release" },
	{ 0x4a92cbb6, "drm_calc_timestamping_constants" },
	{ 0xcdb99cc9, "drm_mode_init" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xfd60df2, "drm_get_connector_status_name" },
	{ 0x75c8b268, "drm_panel_unprepare" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xe0b11bf0, "drm_atomic_add_encoder_bridges" },
	{ 0xdf6e4e77, "drm_atomic_get_connector_state" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x9d379d8c, "drm_sysfs_connector_hotplug_event" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x4403a9c3, "drm_mode_get_hv_timing" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,fb_sys_fops,sysimgblt,sysfillrect,syscopyarea");


MODULE_INFO(srcversion, "A78E24736DFD761ABFC21E6");
