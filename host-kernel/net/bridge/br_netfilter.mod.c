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
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0x6162539b, "br_handle_frame_finish" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xce1ac14a, "__skb_ext_del" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xbf5f6bb, "nf_br_ops" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0x66d250a6, "nf_ipv6_ops" },
	{ 0x2a71d705, "ip_route_input_noref" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x437eb1df, "ipv6_mod_enabled" },
	{ 0x337c47a9, "br_forward_finish" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0x3b120344, "br_dev_queue_push_xmit" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xe035534c, "nf_hook_slow" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x5f98bdb6, "nf_hooks_needed" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xcded9dd5, "__vlan_find_dev_deep_rcu" },
	{ 0xe05b6928, "dst_release" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0xb219f6db, "ip_do_fragment" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xde7e2837, "skb_ext_add" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bridge");


MODULE_INFO(srcversion, "12FA2F712BB7BF106AC542D");
