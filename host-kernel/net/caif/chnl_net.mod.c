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
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x5d8eed3b, "dev_close" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xb7b6874e, "caif_free_client" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9166fada, "strncpy" },
	{ 0x2a09f713, "cfpkt_fromnative" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x92997ed8, "_printk" },
	{ 0x57cb3dcb, "caif_disconnect_client" },
	{ 0xbaab5b5f, "caif_connect_client" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0x4ae8d076, "dev_set_mtu" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x4a237e57, "cfpkt_tonative" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x1446b60a, "caif_client_register_refcnt" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "caif");


MODULE_INFO(srcversion, "646AA74C2C5597995A3E41C");
