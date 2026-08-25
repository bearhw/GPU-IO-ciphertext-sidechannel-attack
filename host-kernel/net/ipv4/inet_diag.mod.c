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

SYMBOL_CRC(inet_diag_msg_common_fill, 0xf2f426ad, "_gpl");
SYMBOL_CRC(inet_diag_msg_attrs_fill, 0xb20739b0, "_gpl");
SYMBOL_CRC(inet_sk_diag_fill, 0xd7a3b1e2, "_gpl");
SYMBOL_CRC(inet_diag_find_one_icsk, 0x474faaa5, "_gpl");
SYMBOL_CRC(inet_diag_dump_one_icsk, 0x4eb853b1, "_gpl");
SYMBOL_CRC(inet_diag_bc_sk, 0xc4dfa4ec, "_gpl");
SYMBOL_CRC(inet_diag_dump_icsk, 0x4403ab7e, "_gpl");
SYMBOL_CRC(inet_diag_register, 0x720d3ca3, "_gpl");
SYMBOL_CRC(inet_diag_unregister, 0x915a0c88, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37a5d32, "sock_diag_save_cookie" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8e4eb451, "bpf_sk_storage_diag_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xf665f74f, "sock_load_diag_module" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0x8520a781, "nla_put" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xefc35200, "netlink_net_capable" },
	{ 0x5d8476d3, "bpf_sk_storage_diag_alloc" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xa8d4fe3e, "nla_reserve_64bit" },
	{ 0x6cf3a006, "inet6_lookup" },
	{ 0x2ec631e3, "sock_diag_check_cookie" },
	{ 0x2c795cac, "sock_gen_put" },
	{ 0xe352a323, "__inet_lookup_established" },
	{ 0x15440701, "__inet_lookup_listener" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xa916b694, "strnlen" },
	{ 0xe218c626, "bpf_sk_storage_diag_put" },
	{ 0xa3e78a68, "sock_diag_put_meminfo" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x800473f, "__cond_resched" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb2a212e7, "sock_diag_register" },
	{ 0x45de6f4f, "sock_diag_unregister" },
	{ 0xea2bed48, "sock_diag_register_inet_compat" },
	{ 0x95a759fd, "sock_diag_unregister_inet_compat" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A3057D682ACFC88F7039C71");
