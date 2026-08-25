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
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0xbd505649, "consume_skb" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x33fc2a31, "get_user_ifreq" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xbb06e299, "sock_common_getsockopt" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x3a970709, "sock_common_setsockopt" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37583cb4, "put_cmsg" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x27cf9939, "dev_getfirstbyhwtype" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xf0a78158, "__sock_recv_cmsgs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x68764184, "proto_register" },
	{ 0xc6cbbc89, "capable" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x7c6024bd, "init_net" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0xeebfcd7a, "ieee802154_hdr_pull" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xbf54b858, "sock_common_recvmsg" },
	{ 0x4a463eba, "sk_common_release" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe05b6928, "dst_release" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0x6ab9a958, "dev_getbyhwaddr_rcu" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xbd8da91e, "dev_load" },
	{ 0x38f48af7, "put_user_ifreq" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ieee802154");


MODULE_INFO(srcversion, "B1260B0CCEAF8D9C7476AEA");
