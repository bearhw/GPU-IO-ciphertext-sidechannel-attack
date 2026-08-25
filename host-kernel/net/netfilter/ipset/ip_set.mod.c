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

SYMBOL_CRC(ip_set_type_register, 0x5328c5ae, "_gpl");
SYMBOL_CRC(ip_set_type_unregister, 0x2276f00e, "_gpl");
SYMBOL_CRC(ip_set_alloc, 0xf3b4d4ae, "_gpl");
SYMBOL_CRC(ip_set_free, 0x397f6231, "_gpl");
SYMBOL_CRC(ip_set_get_ipaddr4, 0xa293f8a6, "_gpl");
SYMBOL_CRC(ip_set_get_ipaddr6, 0x9e98722b, "_gpl");
SYMBOL_CRC(ip_set_init_comment, 0x5922420e, "_gpl");
SYMBOL_CRC(ip_set_extensions, 0xe24187de, "_gpl");
SYMBOL_CRC(ip_set_elem_len, 0x8202224c, "_gpl");
SYMBOL_CRC(ip_set_get_extensions, 0x67dd76de, "_gpl");
SYMBOL_CRC(ip_set_put_extensions, 0x9641c5c6, "_gpl");
SYMBOL_CRC(ip_set_match_extensions, 0xd1c17ba8, "_gpl");
SYMBOL_CRC(ip_set_test, 0xb9867643, "_gpl");
SYMBOL_CRC(ip_set_add, 0xaad3f406, "_gpl");
SYMBOL_CRC(ip_set_del, 0xaca83782, "_gpl");
SYMBOL_CRC(ip_set_get_byname, 0x4da15d8c, "_gpl");
SYMBOL_CRC(ip_set_put_byindex, 0xe44841d8, "_gpl");
SYMBOL_CRC(ip_set_name_byindex, 0xb5997d69, "_gpl");
SYMBOL_CRC(ip_set_nfnl_get_byindex, 0x7d0b6ea8, "_gpl");
SYMBOL_CRC(ip_set_nfnl_put, 0xbe1bbf53, "_gpl");
SYMBOL_CRC(ip_set_put_flags, 0x51fa242b, "_gpl");
SYMBOL_CRC(ip_set_get_ip4_port, 0x1a30617d, "_gpl");
SYMBOL_CRC(ip_set_get_ip6_port, 0xc243b27a, "_gpl");
SYMBOL_CRC(ip_set_netmask_map, 0x81fff2d1, "_gpl");
SYMBOL_CRC(ip_set_hostmask_map, 0x7924b6de, "_gpl");
SYMBOL_CRC(ip_set_range_to_cidr, 0x22d966c6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x3fb130e, "nf_register_sockopt" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd82a9982, "netlink_ack" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x4490c46c, "nf_unregister_sockopt" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0x5792f848, "strlcpy" },
	{ 0x5a921311, "strncmp" },
	{ 0x8520a781, "nla_put" },
	{ 0x9166fada, "strncpy" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xdb065657, "nfnl_unlock" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xdd64e639, "strscpy" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x999e8297, "vfree" },
	{ 0x5ce3b588, "nfnl_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfnetlink");


MODULE_INFO(srcversion, "486534DFFDB1D492DEBAB0B");
