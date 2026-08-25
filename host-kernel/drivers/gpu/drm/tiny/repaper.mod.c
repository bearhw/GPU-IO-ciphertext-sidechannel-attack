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
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x8b51deca, "spi_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xb0c47761, "device_property_read_string" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xf48bd891, "thermal_zone_get_zone_by_name" },
	{ 0xe43186d1, "drm_dev_printk" },
	{ 0x762d2eea, "spi_get_device_id" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xceb66bec, "sched_clock_cpu" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0x52536c83, "drm_fb_cma_get_gem_obj" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0xc67fc73a, "thermal_zone_get_temp" },
	{ 0x5043ea76, "drm_gem_fb_begin_cpu_access" },
	{ 0xea59de2f, "drm_fb_xrgb8888_to_mono" },
	{ 0x959eaca3, "drm_gem_fb_end_cpu_access" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0x978e3a7b, "drm_gem_cma_prime_import_sg_table_vmap" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x9b930703, "drm_gem_cma_dumb_create" },
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
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_cma_helper");

MODULE_ALIAS("spi:e1144cs021");
MODULE_ALIAS("spi:e1190cs021");
MODULE_ALIAS("spi:e2200cs021");
MODULE_ALIAS("spi:e2271cs021");
MODULE_ALIAS("of:N*T*Cpervasive,e1144cs021");
MODULE_ALIAS("of:N*T*Cpervasive,e1144cs021C*");
MODULE_ALIAS("of:N*T*Cpervasive,e1190cs021");
MODULE_ALIAS("of:N*T*Cpervasive,e1190cs021C*");
MODULE_ALIAS("of:N*T*Cpervasive,e2200cs021");
MODULE_ALIAS("of:N*T*Cpervasive,e2200cs021C*");
MODULE_ALIAS("of:N*T*Cpervasive,e2271cs021");
MODULE_ALIAS("of:N*T*Cpervasive,e2271cs021C*");

MODULE_INFO(srcversion, "360F08E627BB860E9292DB8");
