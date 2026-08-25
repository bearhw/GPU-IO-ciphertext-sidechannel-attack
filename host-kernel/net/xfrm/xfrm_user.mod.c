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

SYMBOL_CRC(xfrm_msg_min, 0x4a0c7516, "_gpl");
SYMBOL_CRC(xfrma_policy, 0xe2521b1c, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbf2f9d4d, "netlink_has_listeners" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x69acdf38, "memcpy" },
	{ 0xad115d2, "nla_reserve" },
	{ 0x1cbbb7c, "netlink_kernel_release" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xee18e3f7, "netlink_rcv_skb" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x79b7c109, "xfrm_policy_hash_rebuild" },
	{ 0x9d410e46, "xfrm_policy_flush" },
	{ 0x9cab8249, "km_policy_notify" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x52bd51b8, "xfrm_state_flush" },
	{ 0x356337e2, "km_state_notify" },
	{ 0xf62396ba, "xfrm_policy_walk_done" },
	{ 0x5efa04e9, "xfrm_policy_walk" },
	{ 0xc9df055a, "xfrm_policy_walk_init" },
	{ 0x9d4e06c1, "xfrm_state_walk_done" },
	{ 0x8ccb66c5, "__netlink_kernel_create" },
	{ 0x8520a781, "nla_put" },
	{ 0x91f4d6a1, "security_locked_down" },
	{ 0xfb578fc5, "memset" },
	{ 0x9166fada, "strncpy" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xefc35200, "netlink_net_capable" },
	{ 0x86490580, "current_task" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x26a16700, "xfrm_get_translator" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0xd0a01aa4, "xfrm_put_translator" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xf4ccacd2, "xfrm_policy_alloc" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x2782b393, "xfrm_state_walk_init" },
	{ 0x13804bf9, "xfrm_state_walk" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0xc326c297, "xfrm_state_lookup_byaddr" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x21d16601, "km_state_expired" },
	{ 0xf74903e8, "__xfrm_state_delete" },
	{ 0xab35db12, "xfrm_audit_state_delete" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc65304b3, "security_xfrm_policy_alloc" },
	{ 0xdc6e5b56, "xfrm_policy_bysel_ctx" },
	{ 0xa9c63b69, "security_xfrm_policy_free" },
	{ 0x70001013, "km_policy_expired" },
	{ 0x8bc203b2, "xfrm_policy_byid" },
	{ 0xb2be222e, "xfrm_policy_destroy" },
	{ 0x2e6157b9, "xfrm_policy_delete" },
	{ 0xd25fa080, "xfrm_audit_policy_delete" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd476fe69, "xfrm_sad_getinfo" },
	{ 0xc599a772, "security_xfrm_state_delete" },
	{ 0x5e2324d9, "xfrm_state_delete" },
	{ 0xfe10c88f, "xfrm_spd_getinfo" },
	{ 0x3338d282, "xfrm_state_alloc" },
	{ 0xffb4e2c0, "km_query" },
	{ 0x741922aa, "xfrm_state_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x9443d60c, "xfrm_policy_insert" },
	{ 0x47f66d82, "xfrm_audit_policy_add" },
	{ 0x49ca83, "xfrm_aead_get_byname" },
	{ 0x754d539c, "strlen" },
	{ 0x37a02412, "xfrm_aalg_get_byname" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd6f50cf7, "xfrm_ealg_get_byname" },
	{ 0xaab23340, "xfrm_calg_get_byname" },
	{ 0x4e670da7, "__xfrm_init_state" },
	{ 0x27866435, "security_xfrm_state_alloc" },
	{ 0x971a4b1a, "xfrm_init_replay" },
	{ 0x8cd0a23f, "xfrm_dev_state_add" },
	{ 0x2991d353, "xfrm_state_update" },
	{ 0xb0af698d, "xfrm_audit_state_add" },
	{ 0x61584d49, "xfrm_state_add" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x6e3d9d78, "netlink_broadcast" },
	{ 0xb01bebf9, "xfrm_get_acqseq" },
	{ 0xdd772aea, "__fib6_flush_trees" },
	{ 0xfeb5d0aa, "verify_spi_info" },
	{ 0x50ebc23b, "xfrm_find_acq_byseq" },
	{ 0x2f62d970, "xfrm_find_acq" },
	{ 0xf8b30914, "xfrm_alloc_spi" },
	{ 0x92997ed8, "_printk" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x172c632c, "xfrm_register_km" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x78522907, "xfrm_unregister_km" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_algo");


MODULE_INFO(srcversion, "5ED83422AFBE88AFC377DC8");
