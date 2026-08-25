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
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x613662b7, "mlx5_db_free" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x38ff875f, "vhost_iotlb_add_range" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xc46f5fb, "vringh_iov_pull_iotlb" },
	{ 0xe07fab2d, "mlx5_query_nic_vport_mtu" },
	{ 0x886e3a2d, "_vdpa_register_device" },
	{ 0xedc03953, "iounmap" },
	{ 0xa376089e, "mlx5_create_auto_grouped_flow_table" },
	{ 0xa8efaeb9, "vringh_set_iotlb" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x3ee1955e, "vringh_init_iotlb" },
	{ 0x6bec0e66, "vhost_iotlb_del_range" },
	{ 0xe40f4ed3, "__vdpa_alloc_device" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x51dc5e30, "auxiliary_driver_unregister" },
	{ 0x10ea35bb, "mlx5_cmd_exec" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x541125c9, "vdpa_mgmtdev_unregister" },
	{ 0xe5e354bb, "mlx5_mpfs_del_mac" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x61e3831b, "vringh_getdesc_iotlb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x2587f789, "_dev_info" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0x18f3ddc2, "vringh_iov_push_iotlb" },
	{ 0xeeca09a6, "mlx5_notifier_register" },
	{ 0xa4aecbad, "mlx5_core_create_cq" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xf505a6ef, "mlx5_add_flow_rules" },
	{ 0xcc002b85, "mlx5_destroy_flow_table" },
	{ 0xc1d8c001, "mlx5_get_flow_namespace" },
	{ 0x69e872f9, "vhost_iotlb_itree_first" },
	{ 0x50b1cb2f, "mlx5_mpfs_add_mac" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xea393437, "mlx5_put_uars_page" },
	{ 0x851fb6a2, "mlx5_get_uars_page" },
	{ 0x8520a781, "nla_put" },
	{ 0x83be64b9, "vhost_iotlb_itree_next" },
	{ 0x5b6994df, "mlx5_del_flow_rules" },
	{ 0xde80cd09, "ioremap" },
	{ 0xc0bb1581, "vringh_need_notify_iotlb" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x469314d0, "mlx5_frag_buf_free" },
	{ 0x905cef39, "_vdpa_unregister_device" },
	{ 0x976c018e, "mlx5_notifier_unregister" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x668b19a1, "down_read" },
	{ 0xb963eef5, "mlx5_query_nic_vport_mac_address" },
	{ 0xe48d6275, "vdpa_mgmtdev_register" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa24517eb, "vhost_iotlb_free" },
	{ 0x87b8798d, "sg_next" },
	{ 0xf55ca00c, "mlx5_frag_buf_alloc_node" },
	{ 0x3684d8af, "vringh_complete_iotlb" },
	{ 0xdcb1320b, "__auxiliary_driver_register" },
	{ 0xd990acf7, "mlx5_db_alloc_node" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0xd01442a9, "mlx5_core_destroy_cq" },
	{ 0x81aadc6a, "mlx5_fill_page_frag_array_perm" },
	{ 0xea124bd1, "gcd" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xc577832d, "vhost_iotlb_alloc" },
	{ 0x53b954a2, "up_read" },
	{ 0x6c8667e0, "mlx5_vector2eqn" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x72460c4, "mlx5_fill_page_frag_array" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mlx5_core,vhost_iotlb,vringh,vdpa");

MODULE_ALIAS("auxiliary:mlx5_core.vnet");

MODULE_INFO(srcversion, "11D083BEF02492BFDD5B02E");
