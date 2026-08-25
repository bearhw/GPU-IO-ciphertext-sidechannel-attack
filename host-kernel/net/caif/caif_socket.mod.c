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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x1446b60a, "caif_client_register_refcnt" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x5963b14, "sk_stream_kill_queues" },
	{ 0xb7b6874e, "caif_free_client" },
	{ 0x92997ed8, "_printk" },
	{ 0xc6cbbc89, "capable" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xae4cc05, "release_sock" },
	{ 0xbaab5b5f, "caif_connect_client" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x800473f, "__cond_resched" },
	{ 0x57cb3dcb, "caif_disconnect_client" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2a09f713, "cfpkt_fromnative" },
	{ 0x9e3e305d, "cfpkt_set_prio" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x86490580, "current_task" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0xbe888b32, "skb_put" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xe71c4fef, "send_sig" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x4a237e57, "cfpkt_tonative" },
	{ 0xb37f24cd, "sk_filter_trim_cap" },
	{ 0x2235b121, "sock_rfree" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x408c2ba6, "__sk_mem_schedule" },
	{ 0x50171cd6, "sock_register" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "caif");


MODULE_INFO(srcversion, "A3FEB1F5436033F0A41F7D2");
