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
	{ 0xda10ec3, "security_sock_graft" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x53dea1ff, "ax2asc" },
	{ 0x8baa23e9, "ax25_linkfail_register" },
	{ 0xee02e420, "ax25_findbyuid" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xc1444946, "ax25cmp" },
	{ 0x14cecd59, "ax25_display_timer" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xbd505649, "consume_skb" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x81ca2730, "ax25_listen_register" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8ede9e26, "ax25_protocol_release" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xb2d00eb2, "__dev_get_by_name" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x1000e51, "schedule" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xd09cd600, "sk_reset_timer" },
	{ 0x68764184, "proto_register" },
	{ 0xf67d38c2, "ax25_send_frame" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xb37f24cd, "sk_filter_trim_cap" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x24d273d1, "add_timer" },
	{ 0x242852b9, "ax25_uid_policy" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x5a921311, "strncmp" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0xd43ecbf1, "null_ax25_address" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x3dfc897c, "seq_hlist_start_head" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x4563ebe9, "ax25_listen_release" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0x88c9652c, "ax25_find_cb" },
	{ 0x13d29713, "sk_alloc" },
	{ 0xab76505, "__sock_queue_rcv_skb" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x4e69cc4a, "ax25_register_pid" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x75bda77a, "seq_hlist_next" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x8ac5eea, "ax25_linkfail_release" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x391de184, "seq_puts" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0x8991d825, "sk_stop_timer" },
	{ 0xe71c4fef, "send_sig" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x754d539c, "strlen" },
	{ 0x4502c65a, "asc2ax" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x3b9bf9ff, "skb_append" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ax25");


MODULE_INFO(srcversion, "2814CF11A64F5E05B85E5CE");
