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
	{ 0xcb2693a0, "drm_crtc_add_crc_entry" },
	{ 0x7f05725d, "drm_open" },
	{ 0x5151da72, "drm_poll" },
	{ 0x5ea5344d, "__drm_gem_reset_shadow_plane" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xca04a8d3, "drm_atomic_helper_commit_modeset_enables" },
	{ 0xd9372bb1, "devres_release_group" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x152407ec, "drm_atomic_add_affected_planes" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x480d14ca, "drm_gem_shmem_dumb_create" },
	{ 0x60409e8d, "drm_atomic_helper_disable_plane" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0x35552f56, "drm_atomic_helper_cleanup_planes" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x63667dc7, "drm_mode_object_get" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xe50b4155, "drm_writeback_queue_job" },
	{ 0x3a47a690, "drm_atomic_helper_commit_planes" },
	{ 0x554ac3d, "drm_crtc_cleanup" },
	{ 0x57a594ca, "drm_writeback_signal_completion" },
	{ 0x3082b526, "drm_encoder_cleanup" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa2b8d0d4, "drm_add_modes_noedid" },
	{ 0xa96a098c, "drm_mode_object_put" },
	{ 0x582ee90f, "drm_crtc_vblank_get" },
	{ 0xabceb1cb, "drm_crtc_send_vblank_event" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0x69e8aa87, "drm_atomic_helper_commit_modeset_disables" },
	{ 0x6694dd27, "drm_crtc_accurate_vblank_count" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x7723a66c, "drm_gem_fb_vmap" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0xc5eb3e89, "drm_atomic_get_crtc_state" },
	{ 0x821024a2, "drm_gem_cleanup_shadow_fb" },
	{ 0x233e0bb0, "drm_writeback_connector_init" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xa7733894, "drm_atomic_helper_fake_vblank" },
	{ 0xb15186c, "drm_debugfs_create_files" },
	{ 0xb8e3edef, "__drmm_universal_plane_alloc" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x69dd3b5b, "crc32_le" },
	{ 0x314638f6, "drm_gem_fb_vunmap" },
	{ 0x6d6e2f6b, "drm_crtc_vblank_on" },
	{ 0xfac224d5, "devres_open_group" },
	{ 0x17eb1a70, "drm_gem_fb_create" },
	{ 0xe3ca4fc5, "drm_gem_fb_get_obj" },
	{ 0xe5259331, "drm_atomic_helper_check_plane_state" },
	{ 0xb62fbf91, "drm_crtc_init_with_planes" },
	{ 0xe8757ff9, "drm_crtc_vblank_put" },
	{ 0xe2184644, "drm_gem_prepare_shadow_fb" },
	{ 0xbe56866a, "drm_dev_unregister" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x1a3b73ee, "drm_gem_shmem_prime_import_sg_table" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0xdb63f629, "drm_atomic_helper_set_config" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xcf2c1175, "__drm_atomic_helper_crtc_duplicate_state" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf69d620c, "__drm_atomic_helper_crtc_destroy_state" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0xea8ee118, "drm_simple_encoder_init" },
	{ 0xc01d25e9, "drm_vblank_init" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x20ec69d6, "drm_atomic_helper_wait_for_flip_done" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x6baadd76, "drm_crtc_vblank_off" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0xd1875d31, "__drm_atomic_helper_crtc_reset" },
	{ 0xba6ad1ba, "drm_crtc_handle_vblank" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x3505be55, "drm_atomic_helper_page_flip" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xa20c8e78, "drm_set_preferred_mode" },
	{ 0xb64b4823, "drm_atomic_helper_commit_hw_done" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x828e22f4, "hrtimer_forward" },
	{ 0x34319b14, "__drm_gem_duplicate_shadow_plane_state" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2a539838, "__drm_gem_destroy_shadow_plane_state" },
	{ 0x8bd0e29f, "drm_crtc_arm_vblank_event" },
	{ 0xf89c0ce4, "drm_atomic_helper_update_plane" },
	{ 0x4a92cbb6, "drm_calc_timestamping_constants" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x33da23c4, "drm_release" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper,drm_shmem_helper");


MODULE_INFO(srcversion, "2D3BC887DEECA9DF410591E");
