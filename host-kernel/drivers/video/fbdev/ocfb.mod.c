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
	{ 0x4a453f53, "iowrite32" },
	{ 0xe419bc99, "iowrite32be" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x9bb4e317, "ioread32be" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Copencores,ocfb");
MODULE_ALIAS("of:N*T*Copencores,ocfbC*");

MODULE_INFO(srcversion, "648871EFE71736D7B79D362");
