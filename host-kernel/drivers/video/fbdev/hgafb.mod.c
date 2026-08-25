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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xb0e602eb, "memmove" },
	{ 0x6d606913, "pv_ops" },
	{ 0xde80cd09, "ioremap" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0xedc03953, "iounmap" },
	{ 0x92997ed8, "_printk" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xab781570, "fb_get_options" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FDD684804B6D50F5FF6A7B0");
