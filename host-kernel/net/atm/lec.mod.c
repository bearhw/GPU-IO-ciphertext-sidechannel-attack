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
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x37a0cba, "kfree" },
	{ 0xf9a02593, "vcc_release_async" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0x92997ed8, "_printk" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xa906274e, "seq_putc" },
	{ 0x391de184, "seq_puts" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x69acdf38, "memcpy" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x1de23e95, "module_put" },
	{ 0xc6cbbc89, "capable" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x31cbdc32, "vcc_insert_socket" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x24d273d1, "add_timer" },
	{ 0xb76771c0, "alloc_etherdev_mqs" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xa0cf1873, "skb_copy_expand" },
	{ 0xbe888b32, "skb_put" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x4ae8d076, "dev_set_mtu" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x11cf7ff9, "br_fdb_test_addr_hook" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x4443d399, "atm_proc_root" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x59f209e, "register_atm_ioctl" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x67023607, "deregister_atm_ioctl" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");


MODULE_INFO(srcversion, "A54E05E9DC4C4B24A6F27A9");
