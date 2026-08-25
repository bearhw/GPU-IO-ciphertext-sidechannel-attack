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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x92997ed8, "_printk" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf9c0b663, "strlcat" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x85bd1608, "__request_region" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x779447df, "pci_map_rom" },
	{ 0x979833d1, "pci_unmap_rom" },
	{ 0xde80cd09, "ioremap" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0xc631580a, "console_unlock" },
	{ 0x4672e5, "fb_pan_display" },
	{ 0xaa897f18, "fb_set_cmap" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x6a17f3af, "param_ops_invbool" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001002d00004C45sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C46sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004D46sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004D4Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005043sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005044sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005045sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005046sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005047sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005048sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005049sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000504Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000504Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000504Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000504Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000504Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000504Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005050sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005051sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005052sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005053sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005054sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005055sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005056sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005057sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005058sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005245sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005246sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005247sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000524Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000524Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005345sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005346sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005347sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005348sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000534Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000534Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000534Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000534Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005446sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000544Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005452sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005453sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005454sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005455sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "F6C9CBE397DD58666428316");
