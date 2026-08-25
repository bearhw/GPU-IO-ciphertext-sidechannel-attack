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

SYMBOL_CRC(nf_defrag_ipv6_enable, 0xe766aaf7, "_gpl");
SYMBOL_CRC(nf_defrag_ipv6_disable, 0xe00aecba, "_gpl");
SYMBOL_CRC(nf_ct_frag6_gather, 0xdba43280, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe7097cd2, "icmp6_send" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xdf6b082f, "proc_dointvec_jiffies" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xb0e602eb, "memmove" },
	{ 0x5a6a6e71, "inet_frag_queue_insert" },
	{ 0xcaaae203, "inet_frags_init" },
	{ 0x499b74f4, "inet_frag_pull_head" },
	{ 0x37a0cba, "kfree" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x2eb28b3a, "inet_frag_destroy" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x5a705dc0, "inet_frag_reasm_finish" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0xb8e22311, "fqdir_init" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7c6024bd, "init_net" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd47850e2, "inet_frags_fini" },
	{ 0xec2e1c8f, "proc_doulongvec_minmax" },
	{ 0x452ba683, "ipv6_ext_hdr" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xf9cc5a0a, "inet_frag_reasm_prepare" },
	{ 0xe327c28, "inet_frag_find" },
	{ 0x214f0d3f, "fqdir_exit" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe05b6928, "dst_release" },
	{ 0xa8f6c843, "ip_frag_ecn_table" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0xfebda60e, "inet_frag_kill" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7F518094E43206350C191A1");
