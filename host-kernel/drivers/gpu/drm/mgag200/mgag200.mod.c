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
	{ 0x5a05660c, "drm_aperture_remove_conflicting_pci_framebuffers" },
	{ 0x7f05725d, "drm_open" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x5151da72, "drm_poll" },
	{ 0x245c534d, "drm_fb_memcpy_toio" },
	{ 0x1ef899d1, "drm_mode_crtc_set_gamma_size" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0x480d14ca, "drm_gem_shmem_dumb_create" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x5cc83965, "drm_gem_simple_kms_cleanup_shadow_fb" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x37a0cba, "kfree" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x5fcba7f, "devm_arch_io_reserve_memtype_wc" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x92997ed8, "_printk" },
	{ 0x848d372e, "iowrite8" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0x62627e7e, "drm_gem_simple_kms_destroy_shadow_plane_state" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb55c053f, "drm_connector_init_with_ddc" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0x116007b8, "drm_gem_simple_kms_prepare_shadow_fb" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x779447df, "pci_map_rom" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xbe56866a, "drm_dev_unregister" },
	{ 0xf30db916, "drm_fb_clip_offset" },
	{ 0xb19b445, "ioread8" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x1a3b73ee, "drm_gem_shmem_prime_import_sg_table" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x3a45ada9, "drmm_mutex_init" },
	{ 0x3f2b2c58, "drm_fbdev_generic_setup" },
	{ 0xab60a3e7, "devm_arch_phys_wc_add" },
	{ 0xcf2c1175, "__drm_atomic_helper_crtc_duplicate_state" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xf69d620c, "__drm_atomic_helper_crtc_destroy_state" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x664da421, "drm_gem_simple_kms_duplicate_shadow_plane_state" },
	{ 0x999e8297, "vfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x56470118, "__warn_printk" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0xd1875d31, "__drm_atomic_helper_crtc_reset" },
	{ 0x6660ba7b, "drm_gem_simple_kms_reset_shadow_plane" },
	{ 0x63a6a014, "pcim_iomap" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x979833d1, "pci_unmap_rom" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77358855, "iomem_resource" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x1668523a, "drm_get_edid" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x33da23c4, "drm_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper,drm_shmem_helper,i2c-algo-bit");

MODULE_ALIAS("pci:v0000102Bd00000520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000521sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000522sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000524sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000530sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000532sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000533sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000534sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000536sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000538sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "81C42B9705072062BF96E1F");
