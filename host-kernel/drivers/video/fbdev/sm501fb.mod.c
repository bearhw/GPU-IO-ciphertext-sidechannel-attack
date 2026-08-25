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
	{ 0x96b29254, "strncasecmp" },
	{ 0x2587f789, "_dev_info" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0xc631580a, "console_unlock" },
	{ 0x999e8297, "vfree" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xefcd1590, "sm501_unit_power" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x37a0cba, "kfree" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4c87065b, "sm501_set_clock" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xeefba90b, "sm501_misc_control" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x754d539c, "strlen" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0x12f6f69c, "fb_videomode_to_var" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0xaa897f18, "fb_set_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x85f82bb1, "sm501_modify_reg" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0xa4191c0b, "memset_io" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sm501");


MODULE_INFO(srcversion, "F5DD67135C12D6927D3DC50");
