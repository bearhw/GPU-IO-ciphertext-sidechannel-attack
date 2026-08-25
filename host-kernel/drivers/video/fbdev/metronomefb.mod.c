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
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x16cb454, "fb_deferred_io_cleanup" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x999e8297, "vfree" },
	{ 0x1de23e95, "module_put" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x32294d1f, "fb_deferred_io_init" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xf9a482f9, "msleep" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x69acdf38, "memcpy" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x3e343b7b, "sys_imageblit" },
	{ 0x1a1c7d7f, "sys_copyarea" },
	{ 0x63000ec2, "sys_fillrect" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xc5f26a2b, "fb_deferred_io_mmap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sysimgblt,syscopyarea,sysfillrect");


MODULE_INFO(srcversion, "9F26339B34AC021072A2D63");
