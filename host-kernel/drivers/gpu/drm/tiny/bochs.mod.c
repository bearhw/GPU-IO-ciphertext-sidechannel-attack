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
	{ 0x1c1b6a3e, "drm_mode_config_helper_resume" },
	{ 0x6b3849c7, "drm_mode_config_helper_suspend" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0xedc03953, "iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x37a0cba, "kfree" },
	{ 0xc7831494, "drm_dev_put" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xc60b2e27, "drm_gem_vram_offset" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17eb1a70, "drm_gem_fb_create" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0xa2b8d0d4, "drm_add_modes_noedid" },
	{ 0xa20c8e78, "drm_set_preferred_mode" },
	{ 0x5a05660c, "drm_aperture_remove_conflicting_pci_framebuffers" },
	{ 0x2f1d6eaa, "drm_dev_alloc" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xe4e48c91, "drmm_kmalloc" },
	{ 0x85bd1608, "__request_region" },
	{ 0x7cb8cb5f, "pci_request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0x92997ed8, "_printk" },
	{ 0x3a32bb89, "drmm_vram_helper_init" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x9b9de1c1, "drm_edid_header_is_valid" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xaadb001c, "drm_do_get_edid" },
	{ 0xe6e1aea6, "drm_connector_attach_edid_property" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x85ce2b6e, "drm_vram_mm_debugfs_init" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x3bb7b4ea, "drm_gem_vram_driver_dumb_create" },
	{ 0x16b1be0b, "drm_gem_ttm_dumb_map_offset" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x5151da72, "drm_poll" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x7f05725d, "drm_open" },
	{ 0x33da23c4, "drm_release" },
	{ 0x54805c00, "drm_vram_helper_mode_valid" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x4e874dc3, "drm_gem_vram_simple_display_pipe_prepare_fb" },
	{ 0xeaf93c19, "drm_gem_vram_simple_display_pipe_cleanup_fb" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,drm_vram_helper,drm_ttm_helper");

MODULE_ALIAS("pci:v00001234d00001111sv00001AF4sd00001100bc*sc*i*");
MODULE_ALIAS("pci:v00001234d00001111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00004321d00001111sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "1575E0EF05735B6A8F1FABD");
