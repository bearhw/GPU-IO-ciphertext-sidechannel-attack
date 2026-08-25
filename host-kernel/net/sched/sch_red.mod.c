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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x77732147, "gnet_stats_copy_app" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0xda5d4ed, "qdisc_offload_dump_helper" },
	{ 0x8520a781, "nla_put" },
	{ 0xa288b2ee, "tcf_qevent_dump" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x9fb85917, "tcf_qevent_destroy" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0x574206e2, "tcf_qevent_handle" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xf4846190, "qdisc_offload_graft_helper" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7729a256, "bfifo_qdisc_ops" },
	{ 0x517ed726, "fifo_create_dflt" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0xa965ca81, "reciprocal_value" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x96ce1ef0, "tcf_qevent_validate_change" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xf07a4c2a, "tcf_qevent_init" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "62F037B8C8317543D2A3A81");
