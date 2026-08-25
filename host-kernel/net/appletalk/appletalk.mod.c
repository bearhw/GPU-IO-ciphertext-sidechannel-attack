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

SYMBOL_CRC(aarp_send_ddp, 0x3ddb6961, "");
SYMBOL_CRC(atrtr_get_dev, 0xdfab473d, "");
SYMBOL_CRC(atalk_find_dev_addr, 0x142a4b25, "");
SYMBOL_CRC(alloc_ltalkdev, 0xd4739835, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0xb4b232a4, "dev_mc_add_global" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xdf6b082f, "proc_dointvec_jiffies" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xbd505649, "consume_skb" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0x33fc2a31, "get_user_ifreq" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xd30ba6c1, "unregister_snap_client" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xb6a022da, "remove_proc_subtree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xb2d00eb2, "__dev_get_by_name" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x68764184, "proto_register" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xfd8d6441, "register_snap_client" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x24d273d1, "add_timer" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x3dfc897c, "seq_hlist_start_head" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x75bda77a, "seq_hlist_next" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0x391de184, "seq_puts" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0x38f48af7, "put_user_ifreq" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "psnap");


MODULE_INFO(srcversion, "76532B04AC67FF936704950");
