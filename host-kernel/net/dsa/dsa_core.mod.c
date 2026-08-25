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

SYMBOL_CRC(dsa_tag_drivers_register, 0x0e489931, "_gpl");
SYMBOL_CRC(dsa_tag_drivers_unregister, 0xf69aec4a, "_gpl");
SYMBOL_CRC(dsa_dev_to_net_device, 0xd246ebc5, "_gpl");
SYMBOL_CRC(dsa_switch_suspend, 0xd7f27159, "_gpl");
SYMBOL_CRC(dsa_switch_resume, 0x06ed5ea6, "_gpl");
SYMBOL_CRC(dsa_flush_workqueue, 0x0c6039ac, "_gpl");
SYMBOL_CRC(dsa_devlink_param_get, 0xd077e855, "_gpl");
SYMBOL_CRC(dsa_devlink_param_set, 0xfd3e2b67, "_gpl");
SYMBOL_CRC(dsa_devlink_params_register, 0xe4fcfbfc, "_gpl");
SYMBOL_CRC(dsa_devlink_params_unregister, 0x4a42537b, "_gpl");
SYMBOL_CRC(dsa_devlink_resource_register, 0x46dd6e5d, "_gpl");
SYMBOL_CRC(dsa_devlink_resources_unregister, 0xeddee42b, "_gpl");
SYMBOL_CRC(dsa_devlink_resource_occ_get_register, 0x1e417e7d, "_gpl");
SYMBOL_CRC(dsa_devlink_resource_occ_get_unregister, 0x8f744d3e, "_gpl");
SYMBOL_CRC(dsa_devlink_region_create, 0xcaff7589, "_gpl");
SYMBOL_CRC(dsa_devlink_port_region_create, 0xe56844a4, "_gpl");
SYMBOL_CRC(dsa_devlink_region_destroy, 0xc23e8d5f, "_gpl");
SYMBOL_CRC(dsa_port_from_netdev, 0x0b00bd19, "_gpl");
SYMBOL_CRC(dsa_fdb_present_in_other_db, 0x1fe4434a, "_gpl");
SYMBOL_CRC(dsa_mdb_present_in_other_db, 0xf0f6ff36, "_gpl");
SYMBOL_CRC(dsa_switch_find, 0xd031cc6f, "_gpl");
SYMBOL_CRC(dsa_register_switch, 0x9398002d, "_gpl");
SYMBOL_CRC(dsa_unregister_switch, 0xf9f3fd90, "_gpl");
SYMBOL_CRC(dsa_switch_shutdown, 0x2b7a3d77, "_gpl");
SYMBOL_CRC(dsa_enqueue_skb, 0x602fa45a, "_gpl");
SYMBOL_CRC(dsa_port_phylink_mac_change, 0x2912b522, "_gpl");
SYMBOL_CRC(dsa_slave_dev_check, 0xd0e8c162, "_gpl");
SYMBOL_CRC(dsa_tag_8021q_bridge_vid, 0x45ca5090, "_gpl");
SYMBOL_CRC(dsa_tag_8021q_standalone_vid, 0x1dce07df, "_gpl");
SYMBOL_CRC(dsa_8021q_rx_switch_id, 0x417d1fed, "_gpl");
SYMBOL_CRC(dsa_8021q_rx_source_port, 0x9e59271d, "_gpl");
SYMBOL_CRC(vid_is_dsa_8021q, 0xf13e1803, "_gpl");
SYMBOL_CRC(dsa_tag_8021q_bridge_join, 0x1e76e835, "_gpl");
SYMBOL_CRC(dsa_tag_8021q_bridge_leave, 0x3bdb1a39, "_gpl");
SYMBOL_CRC(dsa_tag_8021q_register, 0xa38c0fcd, "_gpl");
SYMBOL_CRC(dsa_tag_8021q_unregister, 0xa99de5e7, "_gpl");
SYMBOL_CRC(dsa_8021q_xmit, 0xb878d86c, "_gpl");
SYMBOL_CRC(dsa_tag_8021q_find_port_by_vbid, 0xd31594b6, "_gpl");
SYMBOL_CRC(dsa_8021q_rcv, 0x10a8ab8a, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe2986eb0, "mdiobus_alloc_size" },
	{ 0xd06524ba, "raw_notifier_chain_unregister" },
	{ 0xb5f9b3e3, "netdev_lower_get_next" },
	{ 0xe874fbbf, "flow_block_cb_lookup" },
	{ 0x63f62e1b, "switchdev_handle_port_obj_add_foreign" },
	{ 0xc80f8e4a, "devlink_resource_occ_get_unregister" },
	{ 0x4ae8d076, "dev_set_mtu" },
	{ 0x99311936, "br_vlan_enabled" },
	{ 0x657dfd17, "__skb_pad" },
	{ 0x3bcdeeb, "devlink_port_type_eth_set" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x946c0028, "devlink_unregister" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xa851973a, "raw_notifier_call_chain" },
	{ 0xa410a295, "devlink_region_destroy" },
	{ 0x45b8eb5, "br_port_flag_is_set" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x23638e45, "call_switchdev_notifiers" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x5ee32106, "br_port_get_stp_state" },
	{ 0xbd505649, "consume_skb" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xb0e602eb, "memmove" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xadfbb915, "is_hsr_master" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x8670b650, "__netpoll_free" },
	{ 0x16da6c69, "br_vlan_get_proto" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0x53a4768, "br_mst_get_state" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0x41890d65, "dev_uc_del" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xec4a61b5, "netpoll_send_skb" },
	{ 0x58b4645c, "dev_close_many" },
	{ 0xe2b3207a, "unregister_switchdev_notifier" },
	{ 0xb73e37e3, "devlink_params_unregister" },
	{ 0x161aed40, "devlink_port_attrs_set" },
	{ 0xc090c376, "net_selftest_get_strings" },
	{ 0x37a0cba, "kfree" },
	{ 0x853e3913, "devlink_alloc_ns" },
	{ 0x4faf6912, "dev_set_promiscuity" },
	{ 0xc498bdc9, "devlink_register" },
	{ 0x5152bd85, "devlink_port_type_clear" },
	{ 0x660eb6bd, "devlink_free" },
	{ 0x4dc6467, "gro_cells_init" },
	{ 0x87549110, "netdev_warn" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0xa40a8382, "get_device" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9f54ead7, "gro_cells_destroy" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa32fb801, "ether_setup" },
	{ 0xdc9fa232, "raw_notifier_chain_register" },
	{ 0x2d2f4e65, "switchdev_handle_fdb_event_to_device" },
	{ 0x5891f551, "netdev_err" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x74b791fc, "netdev_upper_dev_link" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xe94e609d, "switchdev_handle_port_attr_set" },
	{ 0x9adcd5f8, "phylink_create" },
	{ 0xd75aa1a7, "vlan_for_each" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x92997ed8, "_printk" },
	{ 0x26d5b787, "br_mst_get_info" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x6cc52932, "vlan_dev_vlan_proto" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0x7f00bdac, "devlink_resource_register" },
	{ 0x198d753d, "netdev_upper_get_next_dev_rcu" },
	{ 0x6fa426d2, "phylink_ethtool_nway_reset" },
	{ 0x5fd9fbf1, "netif_device_detach" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9473ae54, "switchdev_bridge_port_offload" },
	{ 0xb11e6d6a, "netif_device_attach" },
	{ 0x2c8e28ee, "phylink_ethtool_get_eee" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x759c5841, "ptp_classify_raw" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x4f4dfce6, "dev_open" },
	{ 0xfca7f934, "devlink_region_create" },
	{ 0x212f14f3, "vlan_dev_real_dev" },
	{ 0x37eb6c0b, "devlink_port_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x7c6024bd, "init_net" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0x8c114e28, "phy_ethtool_get_strings" },
	{ 0x990cf157, "skb_vlan_untag" },
	{ 0x8677245d, "unregister_switchdev_blocking_notifier" },
	{ 0xe53c1081, "dcb_ieee_getapp_mask" },
	{ 0xf4f14de6, "rtnl_trylock" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0x983276da, "phylink_disconnect_phy" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x19abf763, "gro_cells_receive" },
	{ 0xc2cb0db4, "switchdev_handle_port_obj_del_foreign" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xf8fe5642, "phylink_ethtool_get_pauseparam" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x65da0a40, "netdev_upper_dev_unlink" },
	{ 0x8520a781, "nla_put" },
	{ 0xed477587, "dev_mc_del" },
	{ 0x69159425, "br_vlan_get_info" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x911fcd6c, "phylink_start" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xc0d18ac, "mdiobus_free" },
	{ 0x61f9e095, "phylink_generic_validate" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x159d5a81, "devlink_resource_occ_get_register" },
	{ 0x620681b0, "ethtool_op_get_link" },
	{ 0x15c4e3e2, "phylink_ethtool_set_pauseparam" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0x6d294e43, "clock_t_to_jiffies" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x86490580, "current_task" },
	{ 0x57727285, "phylink_ethtool_set_eee" },
	{ 0x8213956, "phylink_ethtool_get_wol" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x876b8d25, "switchdev_bridge_port_unoffload" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x995ee849, "phy_ethtool_get_stats" },
	{ 0xdcb0a2c0, "phylink_stop" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xfdd79d43, "flow_block_cb_is_busy" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0xad645234, "register_switchdev_notifier" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x8942405e, "dev_mc_add" },
	{ 0xb27c0eef, "flow_block_cb_alloc" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x48d93b44, "br_vlan_get_pvid_rcu" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x34a6572b, "__dynamic_netdev_dbg" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x39f39aa5, "net_selftest" },
	{ 0x96e2ea02, "mdiobus_unregister" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xb384c13e, "phylink_ethtool_ksettings_set" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa8551377, "__netpoll_setup" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xb30cfd69, "vlan_vid_add" },
	{ 0x23c009f0, "devlink_params_register" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x12135396, "phylink_mac_change" },
	{ 0x6f298e41, "vlan_vid_del" },
	{ 0x7cd402bc, "dev_set_allmulti" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xee38ef57, "register_switchdev_blocking_notifier" },
	{ 0x50616e69, "devlink_resources_unregister" },
	{ 0xdf355a43, "netdev_master_upper_dev_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4711d4e7, "netif_carrier_off" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xcded9dd5, "__vlan_find_dev_deep_rcu" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x8c047a33, "devlink_port_region_create" },
	{ 0x6e3347ec, "devlink_priv" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x949fdeac, "__hw_addr_sync_dev" },
	{ 0x492b76b6, "mdiobus_get_phy" },
	{ 0xf3083a1d, "phylink_destroy" },
	{ 0x877fbbf2, "__mdiobus_register" },
	{ 0x182541a9, "phylink_ethtool_ksettings_get" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x258c38bc, "dev_uc_add" },
	{ 0x915c6907, "vlan_dev_vlan_id" },
	{ 0x62104126, "phylink_ethtool_set_wol" },
	{ 0xbc4c6b9a, "br_mst_enabled" },
	{ 0xde66f4a7, "phylink_mii_ioctl" },
	{ 0x7aa0bfb6, "phylink_of_phy_connect" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x52ed6513, "dcb_ieee_delapp" },
	{ 0x8e6b1a9e, "net_selftest_get_count" },
	{ 0xeb2ecf81, "device_link_add" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xdf50b524, "dcb_ieee_setapp" },
	{ 0x4e132cfb, "phy_ethtool_get_sset_count" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xd5a17699, "__skb_vlan_pop" },
	{ 0xb84096ed, "phylink_connect_phy" },
	{ 0x3c57a3f3, "br_get_ageing_time" },
	{ 0x4020d591, "devlink_port_register" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bridge,hsr,phylink");


MODULE_INFO(srcversion, "5E327E207A12435B4D52330");
