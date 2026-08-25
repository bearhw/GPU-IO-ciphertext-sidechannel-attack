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
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x27871be6, "nf_log_unset" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x9ad2c4fe, "proc_set_user" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x37a0cba, "kfree" },
	{ 0x1de23e95, "module_put" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2c866db6, "nf_log_unbind_pf" },
	{ 0x2bf15ca4, "nfnl_ct_hook" },
	{ 0x6aea17d2, "nf_log_bind_pf" },
	{ 0xdb065657, "nfnl_unlock" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x5ce3b588, "nfnl_lock" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x754d539c, "strlen" },
	{ 0x8520a781, "nla_put" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x391df80a, "netstamp_needed_key" },
	{ 0xbe888b32, "skb_put" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x24d273d1, "add_timer" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0xfa599bb2, "netlink_register_notifier" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x2d492902, "nf_log_register" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0xdf54a8f7, "netlink_unregister_notifier" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xa8f4170f, "nf_log_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfnetlink");


MODULE_INFO(srcversion, "28F9CE1F9898A1D67C425A1");
