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
	{ 0xa59d3ac7, "drm_atomic_helper_plane_destroy_state" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x5a05660c, "drm_aperture_remove_conflicting_pci_framebuffers" },
	{ 0x7f05725d, "drm_open" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x5151da72, "drm_poll" },
	{ 0x1ef899d1, "drm_mode_crtc_set_gamma_size" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x3bb7b4ea, "drm_gem_vram_driver_dumb_create" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xb7da87a8, "drm_fb_helper_lastclose" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0x60409e8d, "drm_atomic_helper_disable_plane" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x69acdf38, "memcpy" },
	{ 0xb71186b, "drm_mode_create_suggested_offset_properties" },
	{ 0x37a0cba, "kfree" },
	{ 0x7c7e1b58, "drm_atomic_helper_crtc_destroy_state" },
	{ 0x554ac3d, "drm_crtc_cleanup" },
	{ 0x47283066, "drm_connector_list_iter_begin" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0x3082b526, "drm_encoder_cleanup" },
	{ 0x51d9d03f, "drm_connector_unregister" },
	{ 0xc60b2e27, "drm_gem_vram_offset" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0xdd87e544, "drm_plane_get_damage_clips" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa2b8d0d4, "drm_add_modes_noedid" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0x486075c8, "gen_pool_dma_alloc" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0xa86fee46, "drm_connector_list_iter_end" },
	{ 0x5642d92d, "drm_atomic_helper_plane_duplicate_state" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x1a541329, "drm_gem_duplicate_shadow_plane_state" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x5eb85eee, "drm_plane_cleanup" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x1d5bf59c, "drm_gem_vram_plane_helper_prepare_fb" },
	{ 0x821024a2, "drm_gem_cleanup_shadow_fb" },
	{ 0xe1fb555d, "drm_modeset_lock" },
	{ 0xa11ff8d2, "drm_modeset_unlock" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xe9e1e851, "pci_iomap_range" },
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0x54805c00, "drm_vram_helper_mode_valid" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x85ce2b6e, "drm_vram_mm_debugfs_init" },
	{ 0xe5259331, "drm_atomic_helper_check_plane_state" },
	{ 0xd42f4adc, "drm_atomic_helper_plane_reset" },
	{ 0xb62fbf91, "drm_crtc_init_with_planes" },
	{ 0x9bc9f8fe, "drm_object_attach_property" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x4cfc520c, "drm_plane_get_damage_clips_count" },
	{ 0xe2184644, "drm_gem_prepare_shadow_fb" },
	{ 0xbe56866a, "drm_dev_unregister" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0xbefa51a3, "gen_pool_add_owner" },
	{ 0xdb63f629, "drm_atomic_helper_set_config" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xab60a3e7, "devm_arch_phys_wc_add" },
	{ 0x3a32bb89, "drmm_vram_helper_init" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0x4e06ce4a, "devm_gen_pool_create" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x248c29c8, "drm_universal_plane_init" },
	{ 0xe26f879c, "drm_gem_destroy_shadow_plane_state" },
	{ 0x5a826a51, "drm_atomic_helper_crtc_reset" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf15ca581, "drm_connector_list_iter_next" },
	{ 0x7727ca0b, "drm_object_property_set_value" },
	{ 0x89023912, "drm_encoder_init" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6204a1c1, "drm_kms_helper_hotplug_event" },
	{ 0x60ba97c, "gen_pool_free_owner" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0xdd4ebf05, "drm_cvt_mode" },
	{ 0xab2a3778, "drm_gem_reset_shadow_plane" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xb2dfc9b5, "drm_mode_destroy" },
	{ 0x3505be55, "drm_atomic_helper_page_flip" },
	{ 0x16b1be0b, "drm_gem_ttm_dumb_map_offset" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x7d0ba682, "gen_pool_virt_to_phys" },
	{ 0x15e0becb, "drm_gem_vram_plane_helper_cleanup_fb" },
	{ 0x80961b33, "drm_mode_config_cleanup" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x9c81e7bc, "drm_atomic_helper_crtc_duplicate_state" },
	{ 0xf89c0ce4, "drm_atomic_helper_update_plane" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x33da23c4, "drm_release" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x6d1c8700, "drm_primary_helper_destroy" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_vram_helper,drm_ttm_helper");

MODULE_ALIAS("pci:v000080EEd0000BEEFsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "3A36A04A6F33B80FE71B4E9");
