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
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0x3197c4e3, "put_device" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x63667dc7, "drm_mode_object_get" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x131db64a, "system_long_wq" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0xa96a098c, "drm_mode_object_put" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5043ea76, "drm_gem_fb_begin_cpu_access" },
	{ 0x959eaca3, "drm_gem_fb_end_cpu_access" },
	{ 0xec6c0a91, "usb_bulk_msg" },
	{ 0xe43186d1, "drm_dev_printk" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe44409d8, "drm_gem_prime_import_dev" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x6edaf212, "usb_intf_get_dma_device" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0xe4e48c91, "drmm_kmalloc" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x821e463, "usb_deregister" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
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
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_shmem_helper");

MODULE_ALIAS("usb:v1DE1pC102d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "8A509BB5C3437A889FDE924");
