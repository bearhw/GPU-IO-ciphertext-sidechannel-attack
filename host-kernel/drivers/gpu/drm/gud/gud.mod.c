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
	{ 0x615e2f98, "drm_kms_helper_poll_fini" },
	{ 0x7f05725d, "drm_open" },
	{ 0xf7048cb7, "drm_fb_xrgb8888_to_rgb565" },
	{ 0x5151da72, "drm_poll" },
	{ 0x959eaca3, "drm_gem_fb_end_cpu_access" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0x9491f4f9, "drm_atomic_helper_connector_tv_reset" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2295bc93, "drm_kms_helper_poll_init" },
	{ 0xb70870ce, "drm_plane_enable_fb_damage_clips" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0x480d14ca, "drm_gem_shmem_dumb_create" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x2214f6e, "usb_sg_init" },
	{ 0x63667dc7, "drm_mode_object_get" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb9cad492, "__drm_atomic_state_free" },
	{ 0x47283066, "drm_connector_list_iter_begin" },
	{ 0x4f4d78c5, "LZ4_compress_default" },
	{ 0xa0761407, "drm_modeset_acquire_init" },
	{ 0x551a5aad, "drm_fb_xrgb8888_to_rgb332" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa96a098c, "drm_mode_object_put" },
	{ 0xa0b04675, "vmalloc_32" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0x93c7edeb, "usb_find_common_endpoints" },
	{ 0x9b657880, "usb_sg_cancel" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0x3197c4e3, "put_device" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0xa86fee46, "drm_connector_list_iter_end" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x90982d56, "drm_mode_create" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7723a66c, "drm_gem_fb_vmap" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0xb22dfd68, "drm_format_info_min_pitch" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xb15186c, "drm_debugfs_create_files" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0x48a91171, "string_get_size" },
	{ 0x6edaf212, "usb_intf_get_dma_device" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xccc59759, "drm_format_info_block_width" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0x314638f6, "drm_gem_fb_vunmap" },
	{ 0x6bc0a4ce, "drm_mode_create_tv_properties" },
	{ 0x9bc9f8fe, "drm_object_attach_property" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x821e463, "usb_deregister" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0xe40f7318, "drm_atomic_commit" },
	{ 0x558e68f5, "sg_alloc_table_from_pages_segment" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x97d52e9c, "drm_atomic_state_alloc" },
	{ 0x1a3b73ee, "drm_gem_shmem_prime_import_sg_table" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xe4e48c91, "drmm_kmalloc" },
	{ 0xb6c949f4, "drm_fb_xrgb8888_to_rgb888" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xaadb001c, "drm_do_get_edid" },
	{ 0x131db64a, "system_long_wq" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x28c06c53, "drm_fb_memcpy" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf15ca581, "drm_connector_list_iter_next" },
	{ 0x19ad1a2e, "drm_modeset_acquire_fini" },
	{ 0xea8ee118, "drm_simple_encoder_init" },
	{ 0x999e8297, "vfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5043ea76, "drm_gem_fb_begin_cpu_access" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x3e2ef244, "drm_plane_create_rotation_property" },
	{ 0x59bf89d9, "drm_modeset_backoff" },
	{ 0xe44409d8, "drm_gem_prime_import_dev" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0x1c7267d, "drm_mode_create_tv_margin_properties" },
	{ 0x8ec5fdd3, "drm_fb_xrgb8888_to_gray8" },
	{ 0x391de184, "seq_puts" },
	{ 0x4eb69e45, "drm_atomic_state_clear" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x6ef2f78e, "drm_format_info" },
	{ 0xd76aa523, "drm_modeset_drop_locks" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xbd88660, "usb_sg_wait" },
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xdf6e4e77, "drm_atomic_get_connector_state" },
	{ 0x33da23c4, "drm_release" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_shmem_helper,lz4_compress");

MODULE_ALIAS("usb:v1D50p614Dd*dc*dsc*dp*icFFisc*ip*in*");
MODULE_ALIAS("usb:v16D0p10A9d*dc*dsc*dp*icFFisc*ip*in*");

MODULE_INFO(srcversion, "40C440389BAF3A444CD7950");
