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
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0xe1867209, "can_rx_unregister" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x37a0cba, "kfree" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x7345413, "can_proto_register" },
	{ 0x92997ed8, "_printk" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xf0a78158, "__sock_recv_cmsgs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x74b5af39, "can_send" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x437a0d6d, "__sock_tx_timestamp" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0xd2c99738, "__kmalloc_track_caller" },
	{ 0x58b8f9f7, "sock_recv_errqueue" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x9950d907, "sock_cmsg_send" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x6d606913, "pv_ops" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xd139ae5d, "can_proto_unregister" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x324bca89, "can_rx_register" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "can");


MODULE_INFO(srcversion, "B14178D6F03E9FD2382FF24");
