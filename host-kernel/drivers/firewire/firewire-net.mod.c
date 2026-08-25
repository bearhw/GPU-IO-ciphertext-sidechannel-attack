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
	{ 0xbc6094c, "fw_core_remove_descriptor" },
	{ 0xbe564b91, "fw_send_response" },
	{ 0x8136ab9e, "fw_iso_context_destroy" },
	{ 0xaedf84ce, "fw_high_memory_region" },
	{ 0xbe888b32, "skb_put" },
	{ 0xc95c1a5f, "fw_iso_buffer_init" },
	{ 0xbd505649, "consume_skb" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0x69acdf38, "memcpy" },
	{ 0x7b8ee9e6, "fw_iso_context_create" },
	{ 0x37a0cba, "kfree" },
	{ 0x36eadb73, "fw_core_remove_address_handler" },
	{ 0xd835c3a9, "fw_iso_context_stop" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa1939e45, "fw_core_add_address_handler" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xff3d6d5, "fw_iso_context_queue" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x7d918d36, "fw_iso_buffer_destroy" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x620681b0, "ethtool_op_get_link" },
	{ 0x3a771e39, "fw_core_add_descriptor" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0x7cc4a5d, "printk_timed_ratelimit" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0xb75c9765, "fw_iso_context_queue_flush" },
	{ 0xbba412fe, "fw_iso_context_start" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x2369da5f, "fw_bus_type" },
	{ 0x4711d4e7, "netif_carrier_off" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xe649d867, "netif_carrier_on" },
	{ 0x15cf37f1, "fw_send_request" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "firewire-core");

MODULE_ALIAS("ieee1394:ven*mo*sp0000005Ever00000001*");
MODULE_ALIAS("ieee1394:ven*mo*sp0000005Ever00000002*");

MODULE_INFO(srcversion, "9ED900BB7D14221EEFD25D2");
