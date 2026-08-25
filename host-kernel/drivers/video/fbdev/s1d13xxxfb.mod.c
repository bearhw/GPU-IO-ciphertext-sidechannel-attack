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
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x37a0cba, "kfree" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x92997ed8, "_printk" },
	{ 0xedc03953, "iounmap" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x85bd1608, "__request_region" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xde80cd09, "ioremap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DE3267A929F5291AF4C6AF6");
