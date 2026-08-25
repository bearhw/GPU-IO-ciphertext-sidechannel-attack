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
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xedc03953, "iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x69acdf38, "memcpy" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xde80cd09, "ioremap" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x85bd1608, "__request_region" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001013d000000ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000A8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000A4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d00001202sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d00000038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000BCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000D4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000D6sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "B7AA3E346AD39E6F0396271");
