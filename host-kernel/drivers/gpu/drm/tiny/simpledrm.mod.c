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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0x871ab41a, "drm_rect_intersect" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0xf30db916, "drm_fb_clip_offset" },
	{ 0xfffe38f7, "drm_fb_blit_toio" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6ef2f78e, "drm_format_info" },
	{ 0xf1b5340a, "drm_mode_vrefresh" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x9921abec, "devm_aperture_acquire_from_firmware" },
	{ 0x77358855, "iomem_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x22a9685a, "devm_ioremap_wc" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x7060c59b, "drm_connector_set_panel_orientation_with_quirk" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0xb70870ce, "drm_plane_enable_fb_damage_clips" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0x1a3b73ee, "drm_gem_shmem_prime_import_sg_table" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x480d14ca, "drm_gem_shmem_dumb_create" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x5151da72, "drm_poll" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x7f05725d, "drm_open" },
	{ 0x33da23c4, "drm_release" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0x116007b8, "drm_gem_simple_kms_prepare_shadow_fb" },
	{ 0x5cc83965, "drm_gem_simple_kms_cleanup_shadow_fb" },
	{ 0x6660ba7b, "drm_gem_simple_kms_reset_shadow_plane" },
	{ 0x664da421, "drm_gem_simple_kms_duplicate_shadow_plane_state" },
	{ 0x62627e7e, "drm_gem_simple_kms_destroy_shadow_plane_state" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper,drm_shmem_helper");

MODULE_ALIAS("of:N*T*Csimple-framebuffer");
MODULE_ALIAS("of:N*T*Csimple-framebufferC*");

MODULE_INFO(srcversion, "EDD8CA5263814841118BD93");
