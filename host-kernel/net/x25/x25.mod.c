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
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0xa33b08f3, "sk_send_sigurg" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0xf346231f, "seq_list_start_head" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xde293f9e, "add_wait_queue_exclusive" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xb6a022da, "remove_proc_subtree" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9fa78973, "__pskb_copy_fclone" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x68764184, "proto_register" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x800473f, "__cond_resched" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x24d273d1, "add_timer" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x3dfc897c, "seq_hlist_start_head" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2235b121, "sock_rfree" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x75bda77a, "seq_hlist_next" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0x391de184, "seq_puts" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xe71c4fef, "send_sig" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x754d539c, "strlen" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x3b9bf9ff, "skb_append" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E276CBF6AD592310C52D309");
