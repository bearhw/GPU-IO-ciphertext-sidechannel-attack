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
	{ 0x7f05725d, "drm_open" },
	{ 0xf1b5340a, "drm_mode_vrefresh" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x5151da72, "drm_poll" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x1ef899d1, "drm_mode_crtc_set_gamma_size" },
	{ 0x3bb7b4ea, "drm_gem_vram_driver_dumb_create" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0x60409e8d, "drm_atomic_helper_disable_plane" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x49bc34bb, "drmm_kfree" },
	{ 0x37a0cba, "kfree" },
	{ 0x554ac3d, "drm_crtc_cleanup" },
	{ 0x8c6ac271, "drm_aperture_remove_conflicting_framebuffers" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0xc60b2e27, "drm_gem_vram_offset" },
	{ 0x5fcba7f, "devm_arch_io_reserve_memtype_wc" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x848d372e, "iowrite8" },
	{ 0x7e754496, "__drmm_add_action_or_reset" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x5642d92d, "drm_atomic_helper_plane_duplicate_state" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x2587f789, "_dev_info" },
	{ 0x1a541329, "drm_gem_duplicate_shadow_plane_state" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x5eb85eee, "drm_plane_cleanup" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x402a0cb, "drm_gem_vram_unpin" },
	{ 0x1d5bf59c, "drm_gem_vram_plane_helper_prepare_fb" },
	{ 0x821024a2, "drm_gem_cleanup_shadow_fb" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xe9e1e851, "pci_iomap_range" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0xb55c053f, "drm_connector_init_with_ddc" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0x5871e7c0, "drm_gem_vram_vmap" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x54805c00, "drm_vram_helper_mode_valid" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x85ce2b6e, "drm_vram_mm_debugfs_init" },
	{ 0x17eb1a70, "drm_gem_fb_create" },
	{ 0xe5259331, "drm_atomic_helper_check_plane_state" },
	{ 0xd42f4adc, "drm_atomic_helper_plane_reset" },
	{ 0xb62fbf91, "drm_crtc_init_with_planes" },
	{ 0xc12897eb, "drm_atomic_helper_disable_planes_on_crtc" },
	{ 0x8d16d64, "drm_gem_vram_pin" },
	{ 0xe2184644, "drm_gem_prepare_shadow_fb" },
	{ 0xbe56866a, "drm_dev_unregister" },
	{ 0xa960fddb, "drm_atomic_helper_commit_tail_rpm" },
	{ 0xb19b445, "ioread8" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0xe4e48c91, "drmm_kmalloc" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x78979797, "drm_gem_vram_create" },
	{ 0x3a45ada9, "drmm_mutex_init" },
	{ 0xdb63f629, "drm_atomic_helper_set_config" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xab60a3e7, "devm_arch_phys_wc_add" },
	{ 0x3a32bb89, "drmm_vram_helper_init" },
	{ 0xcf2c1175, "__drm_atomic_helper_crtc_duplicate_state" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x248c29c8, "drm_universal_plane_init" },
	{ 0xe26f879c, "drm_gem_destroy_shadow_plane_state" },
	{ 0xf69d620c, "__drm_atomic_helper_crtc_destroy_state" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xea8ee118, "drm_simple_encoder_init" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x56470118, "__warn_printk" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0xd1875d31, "__drm_atomic_helper_crtc_reset" },
	{ 0x3066fe28, "drm_gem_vram_vunmap" },
	{ 0xab2a3778, "drm_gem_reset_shadow_plane" },
	{ 0xe7264b63, "drm_gem_vram_put" },
	{ 0x63a6a014, "pcim_iomap" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x3505be55, "drm_atomic_helper_page_flip" },
	{ 0x16b1be0b, "drm_gem_ttm_dumb_map_offset" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x15e0becb, "drm_gem_vram_plane_helper_cleanup_fb" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xf89c0ce4, "drm_atomic_helper_update_plane" },
	{ 0x1668523a, "drm_get_edid" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x33da23c4, "drm_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_vram_helper,i2c-algo-bit,drm_ttm_helper");

MODULE_ALIAS("pci:v00001A03d00002000sv*sd*bc03sc*i*");
MODULE_ALIAS("pci:v00001A03d00002010sv*sd*bc03sc*i*");

MODULE_INFO(srcversion, "C0AFEFD40A6FF849257D57F");
