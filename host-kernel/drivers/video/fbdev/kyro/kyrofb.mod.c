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
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf02fff58, "pci_ioremap_wc_bar" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v0000104Ad00000010sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "77880391EF71F4E7C30619C");
