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
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x5f2fcc83, "ioremap_uc" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3517383e, "register_reboot_notifier" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xac1a55be, "unregister_reboot_notifier" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xc631580a, "console_unlock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77358855, "iomem_resource" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x85bd1608, "__request_region" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001002d00004758sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004358sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004354sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004554sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C54sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005654sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004754sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005655sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004755sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C47sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005656sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004756sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004757sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004759sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000475Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004742sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004744sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004749sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004750sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004751sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C42sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C44sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C49sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C51sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000474Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000474Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000474Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000474Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004752sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004753sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C4Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C4Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C52sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C53sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8038848C97648781D584F22");
