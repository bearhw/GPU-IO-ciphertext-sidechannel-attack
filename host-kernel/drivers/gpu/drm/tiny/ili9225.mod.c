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
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xbe787cc2, "mipi_dbi_spi_init" },
	{ 0x3d2ecd70, "mipi_dbi_dev_init" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x2889ce7c, "mipi_dbi_spi_cmd_max_speed" },
	{ 0xa754bc53, "mipi_dbi_spi_transfer" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xe022324, "mipi_dbi_command_buf" },
	{ 0xf9a482f9, "msleep" },
	{ 0x52536c83, "drm_fb_cma_get_gem_obj" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0xaf302fd7, "mipi_dbi_buf_copy" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0x1211e36c, "mipi_dbi_hw_reset" },
	{ 0xe43186d1, "drm_dev_printk" },
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
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_mipi_dbi,drm_cma_helper");

MODULE_ALIAS("spi:v220hf01a-t");
MODULE_ALIAS("of:N*T*Cvot,v220hf01a-t");
MODULE_ALIAS("of:N*T*Cvot,v220hf01a-tC*");

MODULE_INFO(srcversion, "DF3362C0BB87E1149BB11FD");
