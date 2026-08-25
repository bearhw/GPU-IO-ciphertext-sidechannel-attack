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
	{ 0xcaff6dc5, "vmbus_driver_unregister" },
	{ 0x5a05660c, "drm_aperture_remove_conflicting_pci_framebuffers" },
	{ 0x7f05725d, "drm_open" },
	{ 0x5151da72, "drm_poll" },
	{ 0x7cb8cb5f, "pci_request_region" },
	{ 0x245c534d, "drm_fb_memcpy_toio" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xb70870ce, "drm_plane_enable_fb_damage_clips" },
	{ 0xa6257a2f, "complete" },
	{ 0x480d14ca, "drm_gem_shmem_dumb_create" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x556422b3, "ioremap_cache" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x2fd90375, "vmbus_sendpacket" },
	{ 0x5cc83965, "drm_gem_simple_kms_cleanup_shadow_fb" },
	{ 0x69acdf38, "memcpy" },
	{ 0x8c6ac271, "drm_aperture_remove_conflicting_framebuffers" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0xa3afc2c1, "vmbus_close" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xd64660db, "vmbus_recvpacket" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa2b8d0d4, "drm_add_modes_noedid" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x37b8b39e, "screen_info" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x2587f789, "_dev_info" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0x62627e7e, "drm_gem_simple_kms_destroy_shadow_plane_state" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x1f1821ae, "efi" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0x77f9ae61, "vmbus_open" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0x116007b8, "drm_gem_simple_kms_prepare_shadow_fb" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0x46a417ca, "vmbus_proto_version" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x86490580, "current_task" },
	{ 0xf30db916, "drm_fb_clip_offset" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x1a3b73ee, "drm_gem_shmem_prime_import_sg_table" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x31e2e77f, "vmbus_free_mmio" },
	{ 0x664da421, "drm_gem_simple_kms_duplicate_shadow_plane_state" },
	{ 0x8f4947c8, "__vmbus_driver_register" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x6660ba7b, "drm_gem_simple_kms_reset_shadow_plane" },
	{ 0xa20c8e78, "drm_set_preferred_mode" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0xc9a35505, "vmbus_allocate_mmio" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0xf34989c, "pci_release_region" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0x33da23c4, "drm_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hv_vmbus,drm,drm_kms_helper,drm_shmem_helper");

MODULE_ALIAS("vmbus:02780ada77e3ac4a8e770558eb1073f8");
MODULE_ALIAS("pci:v00001414d00005353sv00000000sd00000000bc*sc*i*");

MODULE_INFO(srcversion, "731EE96EDD7D10DB4F22A30");
