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
	{ 0xbe38f709, "__do_once_done" },
	{ 0xd0d156e9, "__rht_bucket_nested" },
	{ 0x822e0163, "xfrm_lookup" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x61ce5c38, "ip_output" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xd55e5a7e, "inet_proto_csum_replace_by_diff" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0x37a0cba, "kfree" },
	{ 0x78f6cca8, "ip6_output" },
	{ 0x4b5acf74, "rhashtable_init" },
	{ 0xe5ce1a56, "rhashtable_walk_enter" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe8fbf4fa, "__alloc_bucket_spinlocks" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xada38766, "dst_cache_destroy" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0x86f015e6, "ip6_route_output_flags" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xae39f80e, "dst_cache_init" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8162c74, "free_bucket_spinlocks" },
	{ 0x54188a32, "dst_cache_get" },
	{ 0x8520a781, "nla_put" },
	{ 0x9a5dce5c, "rhashtable_walk_start_check" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x9cd7551a, "rhashtable_walk_stop" },
	{ 0x5d2aa5fb, "rhashtable_walk_peek" },
	{ 0x7f6cee89, "rhashtable_free_and_destroy" },
	{ 0xb202f0d7, "rht_bucket_nested_insert" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d6167ca, "lwtunnel_state_alloc" },
	{ 0x6d606913, "pv_ops" },
	{ 0xe0313d71, "rhashtable_insert_slow" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x14990a44, "dst_cache_set_ip6" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xe05b6928, "dst_release" },
	{ 0x54651f9b, "rhashtable_walk_next" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x822d582b, "lwtunnel_encap_add_ops" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0xb7f990e9, "rht_bucket_nested" },
	{ 0xf188a662, "rhashtable_walk_exit" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x5ae74c8b, "lwtunnel_encap_del_ops" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x18e60984, "__do_once_start" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6E7993BD389A59148ECB3FD");
