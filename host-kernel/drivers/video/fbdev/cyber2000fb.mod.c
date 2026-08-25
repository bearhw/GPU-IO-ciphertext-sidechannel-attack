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

SYMBOL_CRC(cyber2000fb_enable_extregs, 0xb39f68d1, "");
SYMBOL_CRC(cyber2000fb_disable_extregs, 0x534b6f18, "");
SYMBOL_CRC(cyber2000fb_attach, 0x740b1301, "");
SYMBOL_CRC(cyber2000fb_detach, 0x0cc3ede5, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xa916b694, "strnlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x37a0cba, "kfree" },
	{ 0xedc03953, "iounmap" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i2c-algo-bit");

MODULE_ALIAS("pci:v000010EAd00002000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EAd00002010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EAd00005000sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "F3850F05A04ABD443AFB3AC");
