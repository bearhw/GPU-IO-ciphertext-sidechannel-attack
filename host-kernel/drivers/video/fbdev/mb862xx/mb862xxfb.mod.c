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
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x12f6f69c, "fb_videomode_to_var" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x2587f789, "_dev_info" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x2121e851, "device_create_file" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x6b7bb67b, "i2c_add_adapter" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000010CFd00002019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010CFd0000201Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010CFd0000202Bsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "65C80FD3675CD7C87EE75CF");
