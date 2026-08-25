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
	{ 0x88db9f48, "__check_object_size" },
	{ 0xf9091774, "bpf_prog_put" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x2f3f0762, "sk_page_frag_refill" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0xbd8bbd97, "fd_install" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xf5283e0b, "skb_splice_bits" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x4dd1a2f3, "csum_and_copy_from_iter" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x545146ef, "strp_stop" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x3ec01418, "sk_stream_error" },
	{ 0x408c2ba6, "__sk_mem_schedule" },
	{ 0x163df071, "sock_alloc" },
	{ 0x90cf6253, "sock_alloc_file" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x3a26ed11, "sched_clock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x91ba0c4b, "kernel_sendpage" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x68764184, "proto_register" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xf0f73fe2, "bpf_prog_get_type_dev" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xf84bd6ee, "bpf_stats_enabled_key" },
	{ 0xd28f6a7f, "fput" },
	{ 0x49608959, "migrate_disable" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xc5b06aef, "__sk_mem_reclaim" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x7e766b0b, "strp_done" },
	{ 0x76e8d1d3, "sk_stream_wait_memory" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0xd319981b, "tcp_stream_memory_free" },
	{ 0xf7b9df60, "strp_check_rcv" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xf7fec202, "sk_wait_data" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x738737f9, "skb_unlink" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x2235b121, "sock_rfree" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xd322535f, "proc_create_net_single" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x6e5c0971, "sock_release" },
	{ 0xa901868e, "strp_data_ready" },
	{ 0x391de184, "seq_puts" },
	{ 0xe9bf9d69, "strp_unpause" },
	{ 0xb4232cf, "_copy_from_iter_nocache" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x563512c7, "strp_init" },
	{ 0x6194c18d, "sockfd_lookup" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x4d7272e4, "migrate_enable" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BDA3CECEEF0A8E02DA6B32C");
