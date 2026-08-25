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
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0x5151da72, "drm_poll" },
	{ 0x959eaca3, "drm_gem_fb_end_cpu_access" },
	{ 0x92e683f5, "down_timeout" },
	{ 0x1ad22551, "usb_free_urb" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x2295bc93, "drm_kms_helper_poll_init" },
	{ 0x94d8b289, "usb_alloc_coherent" },
	{ 0x480d14ca, "drm_gem_shmem_dumb_create" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0xcf2a6966, "up" },
	{ 0x5cc83965, "drm_gem_simple_kms_cleanup_shadow_fb" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0x3197c4e3, "put_device" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0x62627e7e, "drm_gem_simple_kms_destroy_shadow_plane_state" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xae1356e4, "usb_free_coherent" },
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0x6edaf212, "usb_intf_get_dma_device" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0x116007b8, "drm_gem_simple_kms_prepare_shadow_fb" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x6626afca, "down" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x821e463, "usb_deregister" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x1a3b73ee, "drm_gem_shmem_prime_import_sg_table" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0x2b77b4c7, "usb_get_descriptor" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0xaadb001c, "drm_do_get_edid" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x664da421, "drm_gem_simple_kms_duplicate_shadow_plane_state" },
	{ 0x5043ea76, "drm_gem_fb_begin_cpu_access" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xe44409d8, "drm_gem_prime_import_dev" },
	{ 0x6660ba7b, "drm_gem_simple_kms_reset_shadow_plane" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x33da23c4, "drm_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_shmem_helper");

MODULE_ALIAS("usb:v17E9p*d*dc*dsc*dp*icFFisc00ip00in*");

MODULE_INFO(srcversion, "2BA6BBDDF1B62494FF76106");
