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
	{ 0x999e8297, "vfree" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x86490580, "current_task" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1000e51, "schedule" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x92997ed8, "_printk" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3e343b7b, "sys_imageblit" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x1a1c7d7f, "sys_copyarea" },
	{ 0x63000ec2, "sys_fillrect" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0xd1be46b0, "fb_sys_read" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sysimgblt,syscopyarea,sysfillrect,fb_sys_fops");


MODULE_INFO(srcversion, "620D166BE34ABF19E824226");
