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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0xc631580a, "console_unlock" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x61198ff3, "fb_validate_mode" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xf02fff58, "pci_ioremap_wc_bar" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x69acdf38, "memcpy" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xfe32014a, "fb_ddc_read" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0x37a0cba, "kfree" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0xfdcc8a0e, "fb_find_best_display" },
	{ 0x12f6f69c, "fb_videomode_to_var" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i2c-algo-bit,fb_ddc");

MODULE_ALIAS("pci:v00008086d000000D1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007800sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "5AD86E6D682D740CBF0066A");
