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
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x37a0cba, "kfree" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x4abcf17f, "l2cap_chan_create" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc36dbe8a, "lowpan_register_netdev" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb8dd4639, "netdev_notify_peers" },
	{ 0xb0d811d3, "l2cap_chan_connect" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x87683d13, "bt_debugfs" },
	{ 0x8976be4c, "lowpan_unregister_netdev" },
	{ 0xa0cf1873, "skb_copy_expand" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x8906f4a8, "lowpan_header_decompress" },
	{ 0x4f4dfce6, "dev_open" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x47b8942d, "debugfs_create_file_unsafe" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x35279c79, "nd_tbl" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x5d8eed3b, "dev_close" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x7b5ce5c3, "baswap" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0x8738ddc4, "l2cap_chan_put" },
	{ 0xccb56c5, "hci_get_route" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x718b8b7, "bt_info" },
	{ 0xd40d00cc, "l2cap_chan_close" },
	{ 0x7b8c32f1, "bt_err" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x76e5ff5a, "l2cap_add_psm" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xd6877e25, "l2cap_chan_send" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xd894637d, "lowpan_header_compress" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x636a2492, "no_llseek" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x54c65eca, "l2cap_chan_del" },
	{ 0xbb2b861a, "single_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb82ba28c, "single_open" },
	{ 0x8862d412, "l2cap_chan_set_defaults" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bluetooth,6lowpan");


MODULE_INFO(srcversion, "78BDC821CBA529D870338C6");
