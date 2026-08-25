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

SYMBOL_CRC(get_cfcnfg, 0x4459cc1e, "");
SYMBOL_CRC(caif_enroll_dev, 0x97fcb8c1, "");
SYMBOL_CRC(caif_disconnect_client, 0x57cb3dcb, "");
SYMBOL_CRC(caif_connect_client, 0xbaab5b5f, "");
SYMBOL_CRC(cfcnfg_add_phy_layer, 0x37b7a3b4, "");
SYMBOL_CRC(cfcnfg_set_phy_state, 0x839ddb7b, "");
SYMBOL_CRC(cfcnfg_del_phy_layer, 0x38701a7c, "");
SYMBOL_CRC(caif_free_client, 0xb7b6874e, "");
SYMBOL_CRC(caif_client_register_refcnt, 0x1446b60a, "");
SYMBOL_CRC(cfpkt_fromnative, 0x2a09f713, "");
SYMBOL_CRC(cfpkt_tonative, 0x4a237e57, "");
SYMBOL_CRC(cfpkt_extr_head, 0x40babbe0, "");
SYMBOL_CRC(cfpkt_add_head, 0x3fa84493, "");
SYMBOL_CRC(cfpkt_info, 0x329dbd06, "");
SYMBOL_CRC(cfpkt_set_prio, 0x9e3e305d, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xbe888b32, "skb_put" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x3499aa91, "___pskb_trim" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x52ecbc75, "crc_ccitt" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9e73a62, "skb_cow_data" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xed206e2d, "pskb_put" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7F2994758A75F60089285A4");
