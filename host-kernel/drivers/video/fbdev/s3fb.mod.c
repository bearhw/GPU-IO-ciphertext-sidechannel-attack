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
	{ 0x2587f789, "_dev_info" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc631580a, "console_unlock" },
	{ 0x84c337c2, "svga_wcrt_multi" },
	{ 0x92997ed8, "_printk" },
	{ 0xa10b6c59, "svga_tilecursor" },
	{ 0x686de290, "restore_vga" },
	{ 0xe7a2620e, "save_vga" },
	{ 0x84c97d2a, "svga_match_format" },
	{ 0xb0ab2b2e, "svga_check_timings" },
	{ 0xd6ec2c44, "svga_compute_pll" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xedc03953, "iounmap" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x6d606913, "pv_ops" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x4800960c, "pci_iomap_wc" },
	{ 0xa8304678, "pcibios_bus_to_resource" },
	{ 0x754d539c, "strlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0xa916b694, "strnlen" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xde80cd09, "ioremap" },
	{ 0xfe32014a, "fb_ddc_read" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0x37a0cba, "kfree" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0xfdcc8a0e, "fb_find_best_display" },
	{ 0x12f6f69c, "fb_videomode_to_var" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xe28d2a49, "svga_set_default_gfx_regs" },
	{ 0xd22ca511, "svga_set_default_atc_regs" },
	{ 0x17f3f471, "svga_set_default_seq_regs" },
	{ 0x4ab38ef2, "svga_set_default_crt_regs" },
	{ 0xf9a482f9, "msleep" },
	{ 0x83a41489, "svga_set_timings" },
	{ 0xa4191c0b, "memset_io" },
	{ 0x1be6dc30, "svga_set_textmode_vga_regs" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x91239a2, "svga_get_caps" },
	{ 0xe7e5ec3d, "svga_tilecopy" },
	{ 0x848d5c48, "svga_tilefill" },
	{ 0x7f8a96bd, "svga_tileblit" },
	{ 0xaffaadab, "svga_get_tilemax" },
	{ 0xddeef891, "svga_settile" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "svgalib,vgastate,i2c-algo-bit,fb_ddc");

MODULE_ALIAS("pci:v00005333d00008810sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008811sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008812sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008814sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008901sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008902sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00005631sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d0000883Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A10sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A11sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A12sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A13sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008904sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C01sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "9DFB932B01493C276D9D3B9");
