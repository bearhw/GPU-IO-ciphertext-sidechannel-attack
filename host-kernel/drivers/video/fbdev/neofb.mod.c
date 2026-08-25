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
	{ 0x92997ed8, "_printk" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x686de290, "restore_vga" },
	{ 0xe7a2620e, "save_vga" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x85bd1608, "__request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x6d606913, "pv_ops" },
	{ 0xdffc80fc, "vesa_modes" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x37a0cba, "kfree" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vgastate");

MODULE_ALIAS("pci:v000010C8d00000001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000083sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000005sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000025sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000006sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000016sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "E90F60B4EE431FE1D63AADD");
