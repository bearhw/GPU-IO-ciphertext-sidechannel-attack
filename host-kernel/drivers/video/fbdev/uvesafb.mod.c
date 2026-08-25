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
	{ 0x9166fada, "strncpy" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xedc03953, "iounmap" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x77358855, "iomem_resource" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x37a0cba, "kfree" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x96848186, "scnprintf" },
	{ 0xc6cbbc89, "capable" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x69acdf38, "memcpy" },
	{ 0xa6257a2f, "complete" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x12f6f69c, "fb_videomode_to_var" },
	{ 0x61198ff3, "fb_validate_mode" },
	{ 0xce4cdb8e, "fb_find_best_mode" },
	{ 0xc7c9abe5, "fb_get_mode" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xa6c4041, "cn_netlink_send" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xa7eedcc4, "call_usermodehelper" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0x96c17136, "fb_var_to_videomode" },
	{ 0xee58e970, "fb_add_videomode" },
	{ 0xdffc80fc, "vesa_modes" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0x85bd1608, "__request_region" },
	{ 0xc9561772, "fb_destroy_modelist" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6d606913, "pv_ops" },
	{ 0x77346fe8, "cn_add_callback" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x7483e13, "cn_del_callback" },
	{ 0xf19f134f, "driver_create_file" },
	{ 0x7bdff18e, "driver_remove_file" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x6a17f3af, "param_ops_invbool" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7CDAD021721F6589022DF76");
