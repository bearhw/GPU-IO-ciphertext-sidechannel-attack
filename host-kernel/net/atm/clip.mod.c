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
	{ 0x55c958fb, "neigh_direct_output" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x96848186, "scnprintf" },
	{ 0x391de184, "seq_puts" },
	{ 0xa906274e, "seq_putc" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6652da49, "arp_tbl" },
	{ 0x3900ec33, "neigh_seq_start" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xac2217aa, "__neigh_for_each_release" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xf9a02593, "vcc_release_async" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x9def366f, "__icmp_send" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x1de23e95, "module_put" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x1d4c4364, "netif_tx_lock" },
	{ 0x9e29754d, "netif_tx_unlock" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xf6a79e73, "neigh_update" },
	{ 0x92997ed8, "_printk" },
	{ 0xfe029963, "unregister_inetaddr_notifier" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x67023607, "deregister_atm_ioctl" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0xc6cbbc89, "capable" },
	{ 0x31cbdc32, "vcc_insert_socket" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xf728c38e, "vcc_process_recv_queue" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0x7c6024bd, "init_net" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0xacbdf341, "neigh_lookup" },
	{ 0x4ccc1ddf, "__neigh_create" },
	{ 0xe05b6928, "dst_release" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x3926200e, "atm_charge" },
	{ 0x37a0cba, "kfree" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbe888b32, "skb_put" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x59f209e, "register_atm_ioctl" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xf68285c0, "register_inetaddr_notifier" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4443d399, "atm_proc_root" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x3bae0bf4, "neigh_seq_stop" },
	{ 0xafcd5fe2, "neigh_seq_next" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");


MODULE_INFO(srcversion, "B179B5C2C128FCEBAFD1E6A");
