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
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0xbd505649, "consume_skb" },
	{ 0x5cfa0f81, "phonet_stream_ops" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x49dde649, "pn_skb_send" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3673968a, "phonet_proto_unregister" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xd0654aba, "woken_wake_function" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x948dbf5a, "__sk_receive_skb" },
	{ 0x800473f, "__cond_resched" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x4588eb88, "pn_sock_get_port" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x4a463eba, "sk_common_release" },
	{ 0x2235b121, "sock_rfree" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xfa71c94d, "phonet_proto_register" },
	{ 0x101cda6c, "pn_sock_hash" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x4711d4e7, "netif_carrier_off" },
	{ 0x75a90502, "sk_stream_wait_connect" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x22866cf7, "pn_sock_unhash" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xae4cc05, "release_sock" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "phonet");


MODULE_INFO(srcversion, "559E3FD83C8440E57E2037E");
