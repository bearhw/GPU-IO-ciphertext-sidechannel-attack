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
	{ 0x48112d76, "_raw_read_lock_irq" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0x60eda3b5, "proc_create" },
	{ 0x56a53f51, "seq_release" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3aca0190, "_raw_write_lock_irq" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x7c6024bd, "init_net" },
	{ 0x5f454dc5, "softnet_data" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x24d273d1, "add_timer" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0xf9a02593, "vcc_release_async" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x4443d399, "atm_proc_root" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x59f209e, "register_atm_ioctl" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0x67023607, "deregister_atm_ioctl" },
	{ 0x23d8225b, "seq_open" },
	{ 0xa9320d27, "ktime_get_seconds" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x31cbdc32, "vcc_insert_socket" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");


MODULE_INFO(srcversion, "F22E17331D200A27D3EDA73");
