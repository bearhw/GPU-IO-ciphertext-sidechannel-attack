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

SYMBOL_CRC(nfnl_lock, 0x5ce3b588, "_gpl");
SYMBOL_CRC(nfnl_unlock, 0xdb065657, "_gpl");
SYMBOL_CRC(nfnetlink_subsys_register, 0x6fea8456, "_gpl");
SYMBOL_CRC(nfnetlink_subsys_unregister, 0x6ece208b, "_gpl");
SYMBOL_CRC(nfnetlink_has_listeners, 0x421b2d09, "_gpl");
SYMBOL_CRC(nfnetlink_send, 0xda159d28, "_gpl");
SYMBOL_CRC(nfnetlink_set_err, 0xf57d1ead, "_gpl");
SYMBOL_CRC(nfnetlink_unicast, 0xd807659f, "_gpl");
SYMBOL_CRC(nfnetlink_broadcast, 0xe83334bf, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xbf2f9d4d, "netlink_has_listeners" },
	{ 0x8de7a042, "nlmsg_notify" },
	{ 0x1eaf4558, "netlink_set_err" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x6e3d9d78, "netlink_broadcast" },
	{ 0x1cbbb7c, "netlink_kernel_release" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8ccb66c5, "__netlink_kernel_create" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x86490580, "current_task" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x37a0cba, "kfree" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x1de23e95, "module_put" },
	{ 0xd82a9982, "netlink_ack" },
	{ 0xefc35200, "netlink_net_capable" },
	{ 0xee18e3f7, "netlink_rcv_skb" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "80FC2CCCE1F766ADC109662");
