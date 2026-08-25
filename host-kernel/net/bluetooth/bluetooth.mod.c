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

SYMBOL_CRC(bt_sock_reclassify_lock, 0x20ae5750, "");
SYMBOL_CRC(bt_sock_register, 0x644f1f0d, "");
SYMBOL_CRC(bt_sock_unregister, 0x8fea24bd, "");
SYMBOL_CRC(bt_sock_link, 0xf9b939ef, "");
SYMBOL_CRC(bt_sock_unlink, 0xf3895984, "");
SYMBOL_CRC(bt_accept_enqueue, 0x554e51b5, "");
SYMBOL_CRC(bt_accept_unlink, 0x7ec121e5, "");
SYMBOL_CRC(bt_accept_dequeue, 0x6898b0f4, "");
SYMBOL_CRC(bt_sock_recvmsg, 0x48c765f8, "");
SYMBOL_CRC(bt_sock_stream_recvmsg, 0x282f8ea0, "");
SYMBOL_CRC(bt_sock_poll, 0x7c18457e, "");
SYMBOL_CRC(bt_sock_ioctl, 0x530cf00e, "");
SYMBOL_CRC(bt_sock_wait_state, 0xd62ef0fe, "");
SYMBOL_CRC(bt_sock_wait_ready, 0xd0818fa4, "");
SYMBOL_CRC(bt_procfs_init, 0xfa779867, "");
SYMBOL_CRC(bt_procfs_cleanup, 0x14b1fdc3, "");
SYMBOL_CRC(bt_debugfs, 0x87683d13, "_gpl");
SYMBOL_CRC(hci_alloc_dev_priv, 0x1aeb86d3, "");
SYMBOL_CRC(hci_free_dev, 0x2649eeb7, "");
SYMBOL_CRC(hci_register_dev, 0xce6d6578, "");
SYMBOL_CRC(hci_unregister_dev, 0xc1860618, "");
SYMBOL_CRC(hci_release_dev, 0x9f443f8c, "");
SYMBOL_CRC(hci_suspend_dev, 0x01f5d410, "");
SYMBOL_CRC(hci_resume_dev, 0x393b033e, "");
SYMBOL_CRC(hci_reset_dev, 0x31ae2de9, "");
SYMBOL_CRC(hci_recv_frame, 0x5f40b8d8, "");
SYMBOL_CRC(hci_recv_diag, 0xac87ee16, "");
SYMBOL_CRC(hci_set_hw_info, 0x0df5ec53, "");
SYMBOL_CRC(hci_set_fw_info, 0x3887ed45, "");
SYMBOL_CRC(hci_register_cb, 0x9753bad6, "");
SYMBOL_CRC(hci_unregister_cb, 0xdad3ff9f, "");
SYMBOL_CRC(__hci_cmd_send, 0x481f7fea, "");
SYMBOL_CRC(hci_get_route, 0x0ccb56c5, "");
SYMBOL_CRC(hci_conn_security, 0x82befc88, "");
SYMBOL_CRC(hci_conn_check_secure, 0xae5e42b8, "");
SYMBOL_CRC(hci_conn_switch_role, 0x89e47c70, "");
SYMBOL_CRC(hci_mgmt_chan_register, 0xfe397205, "");
SYMBOL_CRC(hci_mgmt_chan_unregister, 0x4a883d6a, "");
SYMBOL_CRC(l2cap_add_psm, 0x76e5ff5a, "_gpl");
SYMBOL_CRC(l2cap_chan_create, 0x4abcf17f, "_gpl");
SYMBOL_CRC(l2cap_chan_put, 0x8738ddc4, "_gpl");
SYMBOL_CRC(l2cap_chan_set_defaults, 0x8862d412, "_gpl");
SYMBOL_CRC(l2cap_chan_del, 0x54c65eca, "_gpl");
SYMBOL_CRC(l2cap_chan_list, 0xa60fc879, "_gpl");
SYMBOL_CRC(l2cap_chan_close, 0xd40d00cc, "");
SYMBOL_CRC(l2cap_register_user, 0xd86cd4d7, "");
SYMBOL_CRC(l2cap_unregister_user, 0xa98b2f6f, "");
SYMBOL_CRC(l2cap_conn_get, 0x9ebb1d2c, "");
SYMBOL_CRC(l2cap_conn_put, 0x8aba51a3, "");
SYMBOL_CRC(l2cap_chan_send, 0xd6877e25, "_gpl");
SYMBOL_CRC(l2cap_chan_connect, 0xb0d811d3, "_gpl");
SYMBOL_CRC(l2cap_is_socket, 0x8cb81e1a, "");
SYMBOL_CRC(baswap, 0x7b5ce5c3, "");
SYMBOL_CRC(bt_to_errno, 0x7aad008b, "");
SYMBOL_CRC(bt_info, 0x0718b8b7, "");
SYMBOL_CRC(bt_warn, 0x214e4265, "");
SYMBOL_CRC(bt_err, 0x7b8c32f1, "");
SYMBOL_CRC(bt_warn_ratelimited, 0xddacccf6, "");
SYMBOL_CRC(bt_err_ratelimited, 0xd7613212, "");
SYMBOL_CRC(__hci_cmd_sync_sk, 0xbf593775, "");
SYMBOL_CRC(__hci_cmd_sync, 0x8559f33f, "");
SYMBOL_CRC(hci_cmd_sync, 0xbe2f6b3c, "");
SYMBOL_CRC(__hci_cmd_sync_ev, 0xaa8d1a95, "");
SYMBOL_CRC(__hci_cmd_sync_status_sk, 0xc48a8fe6, "");
SYMBOL_CRC(__hci_cmd_sync_status, 0x6fdac0b1, "");
SYMBOL_CRC(hci_cmd_sync_cancel, 0x2ae3dd9a, "");
SYMBOL_CRC(hci_cmd_sync_queue, 0x005b2f72, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xda10ec3, "security_sock_graft" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x7475be8e, "crypto_ecdh_key_len" },
	{ 0x78b887ed, "vsprintf" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x20978fb9, "idr_find" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x83eb21c, "rfkill_unregister" },
	{ 0xbe888b32, "skb_put" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xbec48996, "crypto_stats_kpp_generate_public_key" },
	{ 0xa38602cd, "drain_workqueue" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x2be1612f, "crypto_shash_tfm_digest" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xc0970890, "debugfs_create_u16" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x49fef933, "led_trigger_register_simple" },
	{ 0xc0763484, "rfkill_blocked" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xe4933139, "dev_fwnode" },
	{ 0x7681946c, "unregister_pm_notifier" },
	{ 0xde293f9e, "add_wait_queue_exclusive" },
	{ 0xe2f15e8e, "crypto_stats_kpp_set_secret" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x5ecbd350, "crypto_stats_kpp_compute_shared_secret" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x69acdf38, "memcpy" },
	{ 0xdb68bbad, "rfkill_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1984d421, "out_of_line_wait_on_bit" },
	{ 0x840e7da8, "led_trigger_unregister_simple" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x148653, "vsnprintf" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x248efd3, "kstrtobool_from_user" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x558b281d, "aes_expandkey" },
	{ 0x9fa78973, "__pskb_copy_fclone" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37583cb4, "put_cmsg" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x230971b7, "crypto_alloc_kpp" },
	{ 0x6b853d06, "ns_to_kernel_old_timeval" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xf0a78158, "__sock_recv_cmsgs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x68764184, "proto_register" },
	{ 0x16e297c3, "bit_wait" },
	{ 0xd0654aba, "woken_wake_function" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0x7561021b, "__sock_recv_timestamp" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xb37f24cd, "sk_filter_trim_cap" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x7c6024bd, "init_net" },
	{ 0x755b14b4, "crypto_shash_setkey" },
	{ 0x6a59169d, "simple_open" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x48098f3, "device_add" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xf2e1cca5, "init_uts_ns" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x7d4ccb4f, "device_move" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x5a921311, "strncmp" },
	{ 0x9cc4f70a, "register_pm_notifier" },
	{ 0xa906274e, "seq_putc" },
	{ 0xbd6841d4, "crc16" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0xffb7c514, "ida_free" },
	{ 0x3dfc897c, "seq_hlist_start_head" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0xf29a63f8, "rfkill_alloc" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x86490580, "current_task" },
	{ 0xb230d2ec, "crypto_ecdh_encode_key" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x3312881b, "device_del" },
	{ 0xab76505, "__sock_queue_rcv_skb" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x23af578f, "default_llseek" },
	{ 0xfd6361e7, "__sock_recv_wifi_status" },
	{ 0x402830fd, "from_kuid" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x6b0cd993, "__get_task_comm" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xe06141e9, "security_sk_clone" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xf474fdcb, "kfree_const" },
	{ 0x738737f9, "skb_unlink" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xfa2660d5, "devm_led_trigger_register" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xff282521, "rfkill_register" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x1632bc21, "kvasprintf_const" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x75bda77a, "seq_hlist_next" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x6d5f5b91, "radix_tree_tagged" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x636a2492, "no_llseek" },
	{ 0xf049d0ab, "skb_pull_data" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x391de184, "seq_puts" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xbb2b861a, "single_release" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xc97ba611, "led_trigger_event" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa0fbac79, "wake_up_bit" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x23bd38fe, "debugfs_create_u8" },
	{ 0xb82ba28c, "single_open" },
	{ 0xbacc0824, "crypto_alloc_shash" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x5344e504, "fwnode_property_read_u8_array" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x77e9eb37, "aes_encrypt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B5EA270357C80C1CB6164EF");
