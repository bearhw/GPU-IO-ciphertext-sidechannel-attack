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

SYMBOL_CRC(can_sock_destruct, 0x22c6cac7, "");
SYMBOL_CRC(can_send, 0x74b5af39, "");
SYMBOL_CRC(can_rx_register, 0x324bca89, "");
SYMBOL_CRC(can_rx_unregister, 0xe1867209, "");
SYMBOL_CRC(can_proto_register, 0x07345413, "");
SYMBOL_CRC(can_proto_unregister, 0xd139ae5d, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x1a8bd555, "try_module_get" },
	{ 0xbd505649, "consume_skb" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x50171cd6, "sock_register" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x68764184, "proto_register" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xa906274e, "seq_putc" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xb86ea2ee, "sock_efree" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xd322535f, "proc_create_net_single" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x391de184, "seq_puts" },
	{ 0xce8d534f, "_proc_mkdir" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x91eb9b4, "round_jiffies" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "828730B864CED076E1EBF19");
