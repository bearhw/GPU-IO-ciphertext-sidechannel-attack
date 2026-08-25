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
	{ 0x4ae8d076, "dev_set_mtu" },
	{ 0x25659fc1, "dev_get_stats" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x7f9100a9, "dev_mc_sync" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x18ab595e, "mrp_request_join" },
	{ 0xb41a27f4, "mrp_unregister_application" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x1335a054, "netdev_update_features" },
	{ 0x431ec3a9, "__nla_validate" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x8670b650, "__netpoll_free" },
	{ 0xd10a282, "dev_uc_sync" },
	{ 0x41890d65, "dev_uc_del" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xec4a61b5, "netpoll_send_skb" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x58b4645c, "dev_close_many" },
	{ 0x8654dd3, "mrp_register_application" },
	{ 0x3d8955cb, "netif_inherit_tso_max" },
	{ 0x37a0cba, "kfree" },
	{ 0x4faf6912, "dev_set_promiscuity" },
	{ 0x9977539, "eth_validate_addr" },
	{ 0x87549110, "netdev_warn" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xa6350222, "garp_unregister_application" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xb2d00eb2, "__dev_get_by_name" },
	{ 0xfd28270f, "dev_uc_unsync" },
	{ 0xa32fb801, "ether_setup" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x74b791fc, "netdev_upper_dev_link" },
	{ 0xa65d28e1, "mrp_init_applicant" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xdfb49d52, "eth_header_parse" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0xd35957d4, "garp_request_leave" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x7c6024bd, "init_net" },
	{ 0x94d532a2, "netif_stacked_transfer_operstate" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xfbb8a761, "strscpy_pad" },
	{ 0x65da0a40, "netdev_upper_dev_unlink" },
	{ 0x8520a781, "nla_put" },
	{ 0x75a2cd76, "garp_register_application" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x620681b0, "ethtool_op_get_link" },
	{ 0xe59eb89b, "__ethtool_get_link_ksettings" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x10fbf38f, "vlan_ioctl_set" },
	{ 0xb55bbd45, "proc_remove" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x6d606913, "pv_ops" },
	{ 0x843b6e2e, "garp_init_applicant" },
	{ 0xa8551377, "__netpoll_setup" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xb30cfd69, "vlan_vid_add" },
	{ 0x28735b4e, "linkwatch_fire_event" },
	{ 0xa540cd94, "call_netdevice_notifiers" },
	{ 0x6f298e41, "vlan_vid_del" },
	{ 0x7cd402bc, "dev_set_allmulti" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4711d4e7, "netif_carrier_off" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xe649d867, "netif_carrier_on" },
	{ 0x799984c2, "vlan_uses_dev" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x5d258aaa, "garp_request_join" },
	{ 0x391de184, "seq_puts" },
	{ 0xce8d534f, "_proc_mkdir" },
	{ 0x258c38bc, "dev_uc_add" },
	{ 0x915c6907, "vlan_dev_vlan_id" },
	{ 0xdc81a570, "garp_uninit_applicant" },
	{ 0xa6aa1711, "proc_create_single_data" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x6264afe0, "dev_get_flags" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xf4477ea6, "vlan_filter_drop_vids" },
	{ 0x50a15609, "mrp_request_leave" },
	{ 0xb3806a23, "dev_mc_unsync" },
	{ 0x3f08ba40, "vlan_filter_push_vids" },
	{ 0xc9c78eea, "dev_change_flags" },
	{ 0xe8f8e56c, "mrp_uninit_applicant" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mrp,garp");


MODULE_INFO(srcversion, "C8663326A4A78D353D58B7D");
