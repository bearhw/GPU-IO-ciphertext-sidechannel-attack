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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xbfc177bc, "iowrite32_rep" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x37a0cba, "kfree" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6d606913, "pv_ops" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x85bd1608, "__request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0x92997ed8, "_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa916b694, "strnlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xfe32014a, "fb_ddc_read" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0xfdcc8a0e, "fb_find_best_display" },
	{ 0x12f6f69c, "fb_videomode_to_var" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i2c-algo-bit,fb_ddc");

MODULE_ALIAS("pci:v00001023d00009880sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00008400sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00008420sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00008500sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00008520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00008600sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00008620sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009540sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009440sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009660sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009750sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009850sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009320sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009388sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009525sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009397sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d0000939Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00008820sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009910sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001023d00009930sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8C9A875137F203CE8BD1C35");
