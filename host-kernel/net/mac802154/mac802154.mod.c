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

SYMBOL_CRC(ieee802154_alloc_hw, 0x1794b213, "");
SYMBOL_CRC(ieee802154_configure_durations, 0x2e139d26, "");
SYMBOL_CRC(ieee802154_free_hw, 0xd2467b93, "");
SYMBOL_CRC(ieee802154_register_hw, 0x08f13d44, "");
SYMBOL_CRC(ieee802154_unregister_hw, 0x58694fa8, "");
SYMBOL_CRC(ieee802154_rx_irqsafe, 0xd0bf8f69, "");
SYMBOL_CRC(ieee802154_wake_queue, 0xa8e06ec2, "");
SYMBOL_CRC(ieee802154_stop_queue, 0xeb492ae6, "");
SYMBOL_CRC(ieee802154_xmit_complete, 0x73a0521e, "");
SYMBOL_CRC(ieee802154_xmit_error, 0x3b186ab9, "");
SYMBOL_CRC(ieee802154_xmit_hw_error, 0x172cb3db, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x87e2553b, "ieee802154_max_payload" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0xbe888b32, "skb_put" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x751a4069, "dev_alloc_name" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x87549110, "netdev_warn" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x52ecbc75, "crc_ccitt" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x29b8fdf5, "ieee802154_hdr_peek_addrs" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc9ff0cfd, "wpan_phy_unregister" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0xa0cf1873, "skb_copy_expand" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xd77044d5, "wpan_phy_register" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xeeb417ff, "ieee802154_hdr_peek" },
	{ 0x57b1044d, "wpan_phy_free" },
	{ 0x8d6706dc, "netif_receive_skb" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xeebfcd7a, "ieee802154_hdr_pull" },
	{ 0x79e8fe8c, "crypto_alloc_sync_skcipher" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x34a6572b, "__dynamic_netdev_dbg" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x7b84cc03, "wpan_phy_new" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0xadb41740, "ieee802154_hdr_push" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ieee802154");


MODULE_INFO(srcversion, "B14802D4325C342CF53E28B");
