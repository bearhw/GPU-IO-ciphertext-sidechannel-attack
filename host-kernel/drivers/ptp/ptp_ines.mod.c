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
	{ 0x14853a6f, "unregister_mii_tstamp_controller" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x37a0cba, "kfree" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1224284, "ptp_parse_header" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x759c5841, "ptp_classify_raw" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xfd7b7ab8, "skb_complete_tx_timestamp" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4f7a9aac, "register_mii_tstamp_controller" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cines,ptp-ctrl");
MODULE_ALIAS("of:N*T*Cines,ptp-ctrlC*");

MODULE_INFO(srcversion, "DD13D1A1256197F0F942849");
