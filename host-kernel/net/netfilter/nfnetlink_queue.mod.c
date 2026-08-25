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
	{ 0x75ea7f7c, "nf_ct_hook" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd2648f06, "nf_reinject" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x391df80a, "netstamp_needed_key" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x2bf15ca4, "nfnl_ct_hook" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x229e21ca, "skb_tx_error" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x5603a98b, "__nla_reserve" },
	{ 0x8520a781, "nla_put" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xed61f6b3, "security_release_secctx" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0xbe888b32, "skb_put" },
	{ 0xe4fb1fc1, "skb_zerocopy" },
	{ 0xe59c1a85, "skb_zerocopy_headlen" },
	{ 0xf652d653, "skb_checksum_help" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0xf44d53da, "security_secid_to_secctx" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x8407c404, "__skb_gso_segment" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x2591388d, "nf_queue_entry_get_refs" },
	{ 0x52504c4f, "nf_queue_entry_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x69acdf38, "memcpy" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0xa0cf1873, "skb_copy_expand" },
	{ 0x3499aa91, "___pskb_trim" },
	{ 0x6d606913, "pv_ops" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xdb065657, "nfnl_unlock" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x5ce3b588, "nfnl_lock" },
	{ 0x1de23e95, "module_put" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0xfa599bb2, "netlink_register_notifier" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0x52e2a92a, "nf_register_queue_handler" },
	{ 0xdf54a8f7, "netlink_unregister_notifier" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xd7ea7094, "nf_unregister_queue_handler" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfnetlink");


MODULE_INFO(srcversion, "3D0B486B3B2B64302C6DEE4");
