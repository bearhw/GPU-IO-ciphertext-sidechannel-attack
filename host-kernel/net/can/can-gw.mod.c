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
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xe1867209, "can_rx_unregister" },
	{ 0x579e0bf5, "rtnl_unregister_all" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1b556d75, "netlink_capable" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x74b5af39, "can_send" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x8520a781, "nla_put" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x9366c653, "rtnl_register_module" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x7b52e38, "rtnl_unregister" },
	{ 0x324bca89, "can_rx_register" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "can");


MODULE_INFO(srcversion, "6336C5DDB458D108DC7A28A");
