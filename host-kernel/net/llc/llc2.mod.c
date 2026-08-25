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
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xdf6b082f, "proc_dointvec_jiffies" },
	{ 0x241ed965, "llc_build_and_send_ui_pkt" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xfeda0691, "llc_sap_close" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x69acdf38, "memcpy" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x5fe207b0, "llc_sap_open" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37583cb4, "put_cmsg" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x27cf9939, "dev_getfirstbyhwtype" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x68764184, "proto_register" },
	{ 0xd0654aba, "woken_wake_function" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf446bc54, "llc_add_pack" },
	{ 0x7c6024bd, "init_net" },
	{ 0x5cc1f0f5, "llc_sap_find" },
	{ 0x38b92846, "llc_remove_pack" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xe55365b5, "llc_mac_hdr_init" },
	{ 0x52d7b2fd, "llc_sap_list" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0xbbd66916, "llc_set_station_handler" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb86ea2ee, "sock_efree" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xf7fec202, "sk_wait_data" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x738737f9, "skb_unlink" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2235b121, "sock_rfree" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x391de184, "seq_puts" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x6ab9a958, "dev_getbyhwaddr_rcu" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "llc");


MODULE_INFO(srcversion, "6782900B1D9E5D74F55DAF6");
