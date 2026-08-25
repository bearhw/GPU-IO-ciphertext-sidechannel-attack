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

SYMBOL_CRC(hsr_get_version, 0x667b7530, "");
SYMBOL_CRC(is_hsr_master, 0xadfbb915, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4ae8d076, "dev_set_mtu" },
	{ 0x657dfd17, "__skb_pad" },
	{ 0x69668826, "netdev_increment_features" },
	{ 0x7eafb3e8, "eth_header" },
	{ 0xbe888b32, "skb_put" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x1335a054, "netdev_update_features" },
	{ 0xb0e602eb, "memmove" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0x37a0cba, "kfree" },
	{ 0x4faf6912, "dev_set_promiscuity" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x87549110, "netdev_warn" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd82a9982, "netlink_ack" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0x9fa78973, "__pskb_copy_fclone" },
	{ 0xa32fb801, "ether_setup" },
	{ 0x5891f551, "netdev_err" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x74b791fc, "netdev_upper_dev_link" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x33cda7ef, "netdev_core_stats_alloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xa042c7c5, "netdev_rx_handler_unregister" },
	{ 0xdfb49d52, "eth_header_parse" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x6e3d9d78, "netlink_broadcast" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xa0cf1873, "skb_copy_expand" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x71a19b46, "netdev_printk" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x65da0a40, "netdev_upper_dev_unlink" },
	{ 0x8520a781, "nla_put" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xf2b11959, "seq_read" },
	{ 0xfff55056, "debugfs_rename" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0xa540cd94, "call_netdevice_notifiers" },
	{ 0xa5976e4f, "dev_base_lock" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4711d4e7, "netif_carrier_off" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe649d867, "netif_carrier_on" },
	{ 0xe27e26c2, "netdev_rx_handler_register" },
	{ 0x391de184, "seq_puts" },
	{ 0xbb2b861a, "single_release" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x4b124fc9, "dev_disable_lro" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xb82ba28c, "single_open" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xcc5cdacd, "netdev_info" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "91871778AF806C3CB5A3954");
