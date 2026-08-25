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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x69acdf38, "memcpy" },
	{ 0x92e683f5, "down_timeout" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xcf2a6966, "up" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x6626afca, "down" },
	{ 0xae1356e4, "usb_free_coherent" },
	{ 0x1ad22551, "usb_free_urb" },
	{ 0x37a0cba, "kfree" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x905a5683, "device_remove_bin_file" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3744cf36, "vmalloc_to_pfn" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0xc5f26a2b, "fb_deferred_io_mmap" },
	{ 0x16cb454, "fb_deferred_io_cleanup" },
	{ 0x96c17136, "fb_var_to_videomode" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x999e8297, "vfree" },
	{ 0xc9561772, "fb_destroy_modelist" },
	{ 0x1065192a, "usb_put_dev" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0xee58e970, "fb_add_videomode" },
	{ 0xfdcc8a0e, "fb_find_best_display" },
	{ 0x12f6f69c, "fb_videomode_to_var" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xdffc80fc, "vesa_modes" },
	{ 0x20d65e40, "fb_find_nearest_mode" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3e343b7b, "sys_imageblit" },
	{ 0x1a1c7d7f, "sys_copyarea" },
	{ 0x63000ec2, "sys_fillrect" },
	{ 0x32294d1f, "fb_deferred_io_init" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfb578fc5, "memset" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0xd3f2af1e, "fb_sys_write" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0xb210748a, "usb_get_dev" },
	{ 0x93c7edeb, "usb_find_common_endpoints" },
	{ 0x2b77b4c7, "usb_get_descriptor" },
	{ 0xd36760ef, "__usb_get_extra_descriptor" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xd1be46b0, "fb_sys_read" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0x94d8b289, "usb_alloc_coherent" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x2121e851, "device_create_file" },
	{ 0x1a0b1612, "device_create_bin_file" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x821e463, "usb_deregister" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sysimgblt,syscopyarea,sysfillrect,fb_sys_fops");

MODULE_ALIAS("usb:v17E9p*d*dc*dsc*dp*icFFisc00ip00in*");

MODULE_INFO(srcversion, "E20E5D5ADEC86A862DB4CA8");
