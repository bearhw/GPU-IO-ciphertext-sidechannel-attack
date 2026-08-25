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
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6c61ce70, "num_registered_fb" },
	{ 0xab781570, "fb_get_options" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Csimple-framebuffer");
MODULE_ALIAS("of:N*T*Csimple-framebufferC*");

MODULE_INFO(srcversion, "86FCAB2605CC9D83CCCD778");
