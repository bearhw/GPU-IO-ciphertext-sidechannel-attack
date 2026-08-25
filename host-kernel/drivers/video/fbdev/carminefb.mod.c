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
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x77358855, "iomem_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xedc03953, "iounmap" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x37a0cba, "kfree" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000010CFd0000202Bsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8D085BA1CA12569478D15BA");
