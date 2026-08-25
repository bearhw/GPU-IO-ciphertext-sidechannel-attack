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

SYMBOL_CRC(pn_sock_hash, 0x101cda6c, "");
SYMBOL_CRC(pn_sock_unhash, 0x22866cf7, "");
SYMBOL_CRC(phonet_stream_ops, 0x5cfa0f81, "");
SYMBOL_CRC(pn_sock_get_port, 0x4588eb88, "");
SYMBOL_CRC(phonet_header_ops, 0x64b890ed, "");
SYMBOL_CRC(pn_skb_send, 0x49dde649, "");
SYMBOL_CRC(phonet_proto_register, 0xfa71c94d, "");
SYMBOL_CRC(phonet_proto_unregister, 0x3673968a, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xda10ec3, "security_sock_graft" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xbd505649, "consume_skb" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x579e0bf5, "rtnl_unregister_all" },
	{ 0xbb06e299, "sock_common_getsockopt" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x3499aa91, "___pskb_trim" },
	{ 0x37a0cba, "kfree" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x3a970709, "sock_common_setsockopt" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x1b556d75, "netlink_capable" },
	{ 0xd8a6c1d8, "rtnl_set_sk_err" },
	{ 0x68764184, "proto_register" },
	{ 0xc6cbbc89, "capable" },
	{ 0x1de23e95, "module_put" },
	{ 0x948dbf5a, "__sk_receive_skb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0x7c6024bd, "init_net" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x8520a781, "nla_put" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0x9366c653, "rtnl_register_module" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0xbf54b858, "sock_common_recvmsg" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x4a463eba, "sk_common_release" },
	{ 0x6d606913, "pv_ops" },
	{ 0x1e70eef, "seq_pad" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc622556f, "prepare_to_wait_exclusive" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x31dd3bbc, "rtnl_notify" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x391de184, "seq_puts" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "74AE222EE2C28649F6704CB");
