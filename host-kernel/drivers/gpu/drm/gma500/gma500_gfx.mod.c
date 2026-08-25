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
	{ 0xf0e5d263, "drm_framebuffer_cleanup" },
	{ 0x416c1e62, "drm_gem_fb_destroy" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x615e2f98, "drm_kms_helper_poll_fini" },
	{ 0x7f05725d, "drm_open" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x8d64ac1c, "drm_fb_helper_init" },
	{ 0x5151da72, "drm_poll" },
	{ 0x2038da42, "drm_fb_helper_debug_enter" },
	{ 0xd5094b5a, "vmf_insert_pfn" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x1ef899d1, "drm_mode_crtc_set_gamma_size" },
	{ 0x29f078d1, "drm_mode_legacy_fb_format" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0x472d1bb0, "drm_gem_get_pages" },
	{ 0xdfdcdfbd, "i2c_get_adapter" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x2295bc93, "drm_kms_helper_poll_init" },
	{ 0x7c92bd35, "drm_framebuffer_init" },
	{ 0xb7da87a8, "drm_fb_helper_lastclose" },
	{ 0x1cc5612e, "drm_property_create" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0x593cd573, "drm_fb_helper_setcmap" },
	{ 0xc00816c4, "drm_helper_disable_unused_functions" },
	{ 0xf53089ee, "drm_modeset_unlock_all" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x9b515cb6, "drm_modeset_lock_all" },
	{ 0x2ce58257, "drm_fb_helper_fini" },
	{ 0xd7afc0f, "set_pages_uc" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x5b135546, "drm_fb_helper_cfb_imageblit" },
	{ 0x556422b3, "ioremap_cache" },
	{ 0x2e80b5ac, "ww_mutex_unlock" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xedc03953, "iounmap" },
	{ 0x69acdf38, "memcpy" },
	{ 0x59c4b9de, "drm_helper_hpd_irq_event" },
	{ 0x37a0cba, "kfree" },
	{ 0x554ac3d, "drm_crtc_cleanup" },
	{ 0x8c6ac271, "drm_aperture_remove_conflicting_framebuffers" },
	{ 0x47283066, "drm_connector_list_iter_begin" },
	{ 0x1401cf77, "drm_fb_helper_fill_info" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0x3082b526, "drm_encoder_cleanup" },
	{ 0xef3c4945, "drm_gem_object_init" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x698e1c3, "drm_crtc_init" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x45d68b78, "drm_fb_helper_alloc_fbi" },
	{ 0x38690d99, "drm_detect_hdmi_monitor" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7f24de73, "jiffies_to_usecs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x582ee90f, "drm_crtc_vblank_get" },
	{ 0x2330f595, "drm_gem_object_lookup" },
	{ 0xabceb1cb, "drm_crtc_send_vblank_event" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xc2bb8c22, "set_pages_wb" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x2ed3c600, "drm_mode_debug_printmodeline" },
	{ 0x1a0f57db, "drm_crtc_helper_set_mode" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x3a0c7507, "drm_fb_helper_blank" },
	{ 0x11881cf4, "drm_object_property_get_value" },
	{ 0x98d94cee, "drm_gem_private_object_init" },
	{ 0xb268cabe, "drm_fb_helper_check_var" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5635a60a, "vmalloc_user" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xf5c5edc0, "drm_framebuffer_unregister_private" },
	{ 0x973fa82e, "register_acpi_notifier" },
	{ 0x976c8ec7, "drm_mode_create_scaling_mode_property" },
	{ 0xa86fee46, "drm_connector_list_iter_end" },
	{ 0xa7a99978, "i2c_add_numbered_adapter" },
	{ 0xe81c5a77, "set_pages_array_wb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x2587f789, "_dev_info" },
	{ 0x4833b272, "drm_fb_helper_output_poll_changed" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x4575a0ca, "drm_mode_set_crtcinfo" },
	{ 0x23b4e0d7, "clear_page_rep" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x549baa77, "drm_helper_crtc_in_use" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0x800473f, "__cond_resched" },
	{ 0xdc905b62, "drm_gem_vm_close" },
	{ 0x75f96800, "drm_gem_vm_open" },
	{ 0x5bcf5897, "drm_fb_helper_prepare" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce807a25, "up_write" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x24d273d1, "add_timer" },
	{ 0x8eda3f82, "drm_property_add_enum" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0x6c241300, "drm_read" },
	{ 0xa15e1675, "drm_gem_object_release" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x925493f, "clear_page_orig" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x593b6030, "ww_mutex_lock" },
	{ 0x9166fada, "strncpy" },
	{ 0x6d6e2f6b, "drm_crtc_vblank_on" },
	{ 0x779447df, "pci_map_rom" },
	{ 0x9084b044, "clear_page_erms" },
	{ 0x435f223e, "drm_gem_handle_create" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7023bea8, "unregister_acpi_notifier" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0x9bc9f8fe, "drm_object_attach_property" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x696478f1, "drm_helper_mode_fill_fb_struct" },
	{ 0xe8757ff9, "drm_crtc_vblank_put" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbe56866a, "drm_dev_unregister" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0x9ce050be, "drm_mode_copy" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x459cadd5, "drm_fb_helper_cfb_copyarea" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x778498e5, "drm_helper_connector_dpms" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x88ab6fe3, "kgdb_active" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xb92e0ba9, "drm_handle_vblank" },
	{ 0x346a29df, "drm_fb_helper_pan_display" },
	{ 0xceb85f42, "drm_fb_helper_unregister_fbi" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6b7bb67b, "i2c_add_adapter" },
	{ 0xc82982eb, "drm_get_format_info" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x8826c13b, "acpi_video_register" },
	{ 0xa248afde, "drm_detect_monitor_audio" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf3e0e1df, "allocate_resource" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0xf15ca581, "drm_connector_list_iter_next" },
	{ 0x7727ca0b, "drm_object_property_set_value" },
	{ 0x89023912, "drm_encoder_init" },
	{ 0x823d28fd, "set_pages_array_wc" },
	{ 0xea8ee118, "drm_simple_encoder_init" },
	{ 0xc01d25e9, "drm_vblank_init" },
	{ 0x999e8297, "vfree" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x6baadd76, "drm_crtc_vblank_off" },
	{ 0x56470118, "__warn_printk" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0x291f0042, "drm_fb_helper_debug_leave" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x4088b7b0, "drm_property_create_range" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xb2dfc9b5, "drm_mode_destroy" },
	{ 0xa29aeb66, "drm_gem_fb_create_handle" },
	{ 0xd26e79d7, "drm_crtc_from_index" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0xc0bea473, "vmf_insert_mixed" },
	{ 0x979833d1, "pci_unmap_rom" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc5e74216, "release_resource" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0xa8de2a5f, "drm_fb_helper_initial_config" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x22ec6284, "drm_fb_helper_cfb_fillrect" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x1668523a, "drm_get_edid" },
	{ 0xe02e38c0, "drm_gem_put_pages" },
	{ 0x4b75a00, "drm_helper_resume_force_mode" },
	{ 0x53b954a2, "up_read" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0x47b1831d, "drm_crtc_helper_set_config" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xd8f3ba89, "drm_fb_helper_ioctl" },
	{ 0x2ae60448, "drm_fb_helper_set_par" },
	{ 0x33da23c4, "drm_release" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper,i2c-algo-bit,video");

MODULE_ALIAS("pci:v00008086d00008108sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008109sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004102sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004103sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004104sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004105sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004106sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004107sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004108sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BE9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BEAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BEBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BECsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BEDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BEEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000BEFsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8F9E97B8DE52B9F996A7BB7");
