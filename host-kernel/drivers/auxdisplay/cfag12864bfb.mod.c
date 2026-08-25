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
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xc48e9d95, "cfag12864b_buffer" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x92997ed8, "_printk" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xbda2916c, "vm_map_pages_zero" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2ff9464, "cfag12864b_isinited" },
	{ 0x3389f926, "cfag12864b_enable" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xecb2e5d, "cfag12864b_disable" },
	{ 0xd1be46b0, "fb_sys_read" },
	{ 0xd3f2af1e, "fb_sys_write" },
	{ 0x63000ec2, "sys_fillrect" },
	{ 0x1a1c7d7f, "sys_copyarea" },
	{ 0x3e343b7b, "sys_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cfag12864b,fb_sys_fops,sysfillrect,syscopyarea,sysimgblt");


MODULE_INFO(srcversion, "3F184061B3D765A7E552307");
