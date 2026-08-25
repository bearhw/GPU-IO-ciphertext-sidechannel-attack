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

SYMBOL_CRC(wpan_phy_find, 0xb26c6865, "");
SYMBOL_CRC(wpan_phy_for_each, 0xd94719e2, "");
SYMBOL_CRC(wpan_phy_new, 0x7b84cc03, "");
SYMBOL_CRC(wpan_phy_register, 0xd77044d5, "");
SYMBOL_CRC(wpan_phy_unregister, 0xc9ff0cfd, "");
SYMBOL_CRC(wpan_phy_free, 0x57b1044d, "");
SYMBOL_CRC(ieee802154_hdr_push, 0xadb41740, "_gpl");
SYMBOL_CRC(ieee802154_hdr_pull, 0xeebfcd7a, "_gpl");
SYMBOL_CRC(ieee802154_hdr_peek_addrs, 0x29b8fdf5, "_gpl");
SYMBOL_CRC(ieee802154_hdr_peek, 0xeeb417ff, "_gpl");
SYMBOL_CRC(ieee802154_max_payload, 0x87e2553b, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe914e41e, "strcpy" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xafe42007, "trace_output_call" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x37a0cba, "kfree" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x27b0d5bd, "device_rename" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0x6e3d9d78, "netlink_broadcast" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xf4e44828, "class_for_each_device" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x48098f3, "device_add" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x8520a781, "nla_put" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x3312881b, "device_del" },
	{ 0xb758b0ac, "dev_set_mac_address" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa1f8a9e6, "get_net_ns_by_pid" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x5df0ab87, "device_match_name" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0xbc24a051, "__dev_change_net_namespace" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x890e8ab3, "get_net_ns_by_fd" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "91343AA2593152BD3242E98");
