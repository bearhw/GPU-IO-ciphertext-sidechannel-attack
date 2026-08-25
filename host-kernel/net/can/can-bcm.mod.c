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
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0xbe888b32, "skb_put" },
	{ 0xe1867209, "can_rx_unregister" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x7345413, "can_proto_register" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xf0a78158, "__sock_recv_cmsgs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x74b5af39, "can_send" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0xa906274e, "seq_putc" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xfb578fc5, "memset" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0xb86ea2ee, "sock_efree" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xd322535f, "proc_create_net_single" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xd139ae5d, "can_proto_unregister" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xce8d534f, "_proc_mkdir" },
	{ 0x828e22f4, "hrtimer_forward" },
	{ 0xef34bf3e, "hrtimer_active" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x324bca89, "can_rx_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "can");


MODULE_INFO(srcversion, "A933E0FEFA0C4A6D445716A");
