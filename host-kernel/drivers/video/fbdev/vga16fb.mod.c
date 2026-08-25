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
	{ 0xedc03953, "iounmap" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x686de290, "restore_vga" },
	{ 0xe7a2620e, "save_vga" },
	{ 0x92997ed8, "_printk" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xc683da81, "set_memory_decrypted" },
	{ 0x37b8b39e, "screen_info" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x6d606913, "pv_ops" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vgastate");


MODULE_INFO(srcversion, "C695A8D12416C1FB7FFD306");
