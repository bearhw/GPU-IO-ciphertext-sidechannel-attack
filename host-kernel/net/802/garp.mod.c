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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(garp_request_join, 0x5d258aaa, "_gpl");
SYMBOL_CRC(garp_request_leave, 0xd35957d4, "_gpl");
SYMBOL_CRC(garp_init_applicant, 0x843b6e2e, "_gpl");
SYMBOL_CRC(garp_uninit_applicant, 0xdc81a570, "_gpl");
SYMBOL_CRC(garp_register_application, 0x75a2cd76, "_gpl");
SYMBOL_CRC(garp_unregister_application, 0xa6350222, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xe8ac1889, "stp_proto_register" },
	{ 0x54aef0e8, "stp_proto_unregister" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xe55365b5, "llc_mac_hdr_init" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x37a0cba, "kfree" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x8942405e, "dev_mc_add" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xece784c2, "rb_first" },
	{ 0xca9360b5, "rb_next" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0xed477587, "dev_mc_del" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "stp,llc");


MODULE_INFO(srcversion, "AA122B7A403CDAD497C9DEA");
