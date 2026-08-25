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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0xc631580a, "console_unlock" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x37a0cba, "kfree" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xedc03953, "iounmap" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xf34989c, "pci_release_region" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x2587f789, "_dev_info" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x7cb8cb5f, "pci_request_region" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xde80cd09, "ioremap" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xab781570, "fb_get_options" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v0000126Fd00000710sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000126Fd00000712sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000126Fd00000720sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "14DC5FC49366802B0383D3D");
