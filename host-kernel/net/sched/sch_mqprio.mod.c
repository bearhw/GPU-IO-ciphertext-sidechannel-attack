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
	{ 0x5f74f960, "dev_graft_qdisc" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0x37a0cba, "kfree" },
	{ 0x48ba113d, "netdev_set_num_tc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5c7a9342, "gnet_stats_copy_basic" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x56605172, "gnet_stats_copy_queue" },
	{ 0x866a62b2, "gnet_stats_basic_sync_init" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfa042227, "gnet_stats_add_basic" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0x7d78794c, "netdev_txq_to_tc" },
	{ 0x2784a458, "dev_deactivate" },
	{ 0xae86d5e8, "dev_activate" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69ad4a42, "pfifo_fast_ops" },
	{ 0x983bd97, "default_qdisc_ops" },
	{ 0xbc9fd33f, "qdisc_create_dflt" },
	{ 0x3fbfee8c, "netdev_set_tc_queue" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x87dcb5f9, "mq_change_real_num_tx" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BD38FF585C5688C2D699241");
