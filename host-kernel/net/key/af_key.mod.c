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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2235b121, "sock_rfree" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x5efa04e9, "xfrm_policy_walk" },
	{ 0xf62396ba, "xfrm_policy_walk_done" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0xf0a78158, "__sock_recv_cmsgs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc9df055a, "xfrm_policy_walk_init" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2782b393, "xfrm_state_walk_init" },
	{ 0x9d4e06c1, "xfrm_state_walk_done" },
	{ 0x13804bf9, "xfrm_state_walk" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x67b78eb3, "seq_hlist_next_rcu" },
	{ 0x1e9edfb7, "seq_hlist_start_head_rcu" },
	{ 0xbe888b32, "skb_put" },
	{ 0xfb578fc5, "memset" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x92997ed8, "_printk" },
	{ 0xf4ccacd2, "xfrm_policy_alloc" },
	{ 0xc65304b3, "security_xfrm_policy_alloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xb2be222e, "xfrm_policy_destroy" },
	{ 0x28e23139, "xfrm_probe_algs" },
	{ 0xa575945, "xfrm_count_pfkey_auth_supported" },
	{ 0x7a8ca627, "xfrm_count_pfkey_enc_supported" },
	{ 0xb73be794, "xfrm_ealg_get_byidx" },
	{ 0xc6b1fdbe, "xfrm_aalg_get_byidx" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9d410e46, "xfrm_policy_flush" },
	{ 0x9cab8249, "km_policy_notify" },
	{ 0x52bd51b8, "xfrm_state_flush" },
	{ 0x356337e2, "km_state_notify" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x13d29713, "sk_alloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x37a02412, "xfrm_aalg_get_byname" },
	{ 0xaab23340, "xfrm_calg_get_byname" },
	{ 0xd6f50cf7, "xfrm_ealg_get_byname" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x8bc203b2, "xfrm_policy_byid" },
	{ 0xd25fa080, "xfrm_audit_policy_delete" },
	{ 0xdc6e5b56, "xfrm_policy_bysel_ctx" },
	{ 0xa9c63b69, "security_xfrm_policy_free" },
	{ 0x9443d60c, "xfrm_policy_insert" },
	{ 0x47f66d82, "xfrm_audit_policy_add" },
	{ 0xc599a772, "security_xfrm_state_delete" },
	{ 0x5e2324d9, "xfrm_state_delete" },
	{ 0xab35db12, "xfrm_audit_state_delete" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0x3338d282, "xfrm_state_alloc" },
	{ 0x27866435, "security_xfrm_state_alloc" },
	{ 0xc80741, "xfrm_ealg_get_byid" },
	{ 0x754d539c, "strlen" },
	{ 0x37b4f03a, "xfrm_init_state" },
	{ 0x2991d353, "xfrm_state_update" },
	{ 0xb0af698d, "xfrm_audit_state_add" },
	{ 0x61584d49, "xfrm_state_add" },
	{ 0x5c699441, "xfrm_aalg_get_byid" },
	{ 0x72395dc1, "xfrm_calg_get_byid" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x50ebc23b, "xfrm_find_acq_byseq" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x2f62d970, "xfrm_find_acq" },
	{ 0xfeb5d0aa, "verify_spi_info" },
	{ 0xf8b30914, "xfrm_alloc_spi" },
	{ 0x78522907, "xfrm_unregister_km" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x68764184, "proto_register" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x50171cd6, "sock_register" },
	{ 0x172c632c, "xfrm_register_km" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_algo");


MODULE_INFO(srcversion, "C4A02777CFBD5F7C562BBFE");
