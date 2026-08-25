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
	{ 0xc1514a3b, "free_irq" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xe16db2ce, "agp_bind_memory" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xa67b7b0b, "agp_backend_acquire" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x37b8b39e, "screen_info" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x838286d5, "agp_free_memory" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x7a6e3c44, "agp_allocate_memory" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x140c98db, "agp_unbind_memory" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xee2ef679, "fb_firmware_edid" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xd51b6795, "agp_copy_info" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x77358855, "iomem_resource" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x74f8e983, "agp_backend_release" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x85bd1608, "__request_region" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i2c-algo-bit");

MODULE_ALIAS("pci:v00008086d00003577sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d00002562sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d00003582sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d00002572sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d0000358Esv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d00002582sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d00002592sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d00002772sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d000027A2sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d000027AEsv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d000029A2sv*sd*bc03sc00i*");
MODULE_ALIAS("pci:v00008086d00002A02sv*sd*bc03sc00i*");

MODULE_INFO(srcversion, "6D6AB854DE8D00641B3BA58");
