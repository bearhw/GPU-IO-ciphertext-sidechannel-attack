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
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0xc46a2c52, "mpt_get_msg_frame" },
	{ 0x3b7cdd92, "mpt_put_msg_frame" },
	{ 0xe6c1e126, "mpt_event_deregister" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xbd505649, "consume_skb" },
	{ 0x37a0cba, "kfree" },
	{ 0x92997ed8, "_printk" },
	{ 0x471fb168, "alloc_fcdev" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x862e02c3, "mpt_free_msg_frame" },
	{ 0xcd3165e6, "__dev_kfree_skb_irq" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0xbe888b32, "skb_put" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x69acdf38, "memcpy" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x1ea8f504, "mpt_event_register" },
	{ 0xfd972c5b, "mpt_register" },
	{ 0x95f4fe1c, "mpt_reset_register" },
	{ 0xbb889362, "mpt_device_driver_register" },
	{ 0x74a0134a, "mpt_device_driver_deregister" },
	{ 0x610b257e, "mpt_reset_deregister" },
	{ 0x981efe92, "mpt_deregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mptbase");


MODULE_INFO(srcversion, "8C829EB8A95E0439A83F075");
