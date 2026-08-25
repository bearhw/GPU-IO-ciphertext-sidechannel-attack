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
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0x4711d4e7, "netif_carrier_off" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0xe649d867, "netif_carrier_on" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa32fb801, "ether_setup" },
	{ 0xe838916, "eth_mac_addr" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xff1e9dd8, "seq_list_start" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbd505649, "consume_skb" },
	{ 0x6d606913, "pv_ops" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3aca0190, "_raw_write_lock_irq" },
	{ 0x1de23e95, "module_put" },
	{ 0x37a0cba, "kfree" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0xc6cbbc89, "capable" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x5a921311, "strncmp" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xf728c38e, "vcc_process_recv_queue" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x4443d399, "atm_proc_root" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x59f209e, "register_atm_ioctl" },
	{ 0xb09faf79, "register_atmdevice_notifier" },
	{ 0x67023607, "deregister_atm_ioctl" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xcfb6a3da, "unregister_atmdevice_notifier" },
	{ 0x9977539, "eth_validate_addr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");


MODULE_INFO(srcversion, "D8D21A574ED5CF7CE3083CB");
