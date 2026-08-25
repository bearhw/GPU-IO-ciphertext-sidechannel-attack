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
	{ 0x61198ff3, "fb_validate_mode" },
	{ 0xfe32014a, "fb_ddc_read" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0xaa897f18, "fb_set_cmap" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x37a0cba, "kfree" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xce4cdb8e, "fb_find_best_mode" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xc7c9abe5, "fb_get_mode" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0xe7a2620e, "save_vga" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x686de290, "restore_vga" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xab781570, "fb_get_options" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xc631580a, "console_unlock" },
	{ 0xf93fd09c, "fb_find_mode_cvt" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0xee2ef679, "fb_firmware_edid" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xfdcc8a0e, "fb_find_best_display" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fb_ddc,i2c-algo-bit,vgastate");

MODULE_ALIAS("pci:v00005333d00008C22sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C24sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C26sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C2Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C2Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C2Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C2Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C2Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C2Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A22sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A20sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A21sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00009102sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C10sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C11sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C12sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C13sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A25sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A26sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008D01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008D02sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008D03sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008D04sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "549DF2ACADFF18FE062D1EE");
