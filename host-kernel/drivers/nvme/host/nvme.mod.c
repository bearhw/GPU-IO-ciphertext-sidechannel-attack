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
	{ 0xbe38f709, "__do_once_done" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x84545be, "pcie_aspm_enabled" },
	{ 0x134ef5bd, "nvme_uninit_ctrl" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xd9aa089e, "dma_pool_create" },
	{ 0x51189b95, "nvme_complete_rq" },
	{ 0xe223bb16, "pci_request_selected_regions" },
	{ 0x12bcb93d, "pci_release_selected_regions" },
	{ 0xfe86c1f0, "nvme_wait_freeze_timeout" },
	{ 0x3e32aadb, "pci_enable_device_mem" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0xd8c57a53, "blk_mq_tagset_wait_completed_request" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x2aa4e901, "nvme_start_queues" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xd45434ee, "admin_timeout" },
	{ 0xe6db41b0, "blk_mq_complete_request_remote" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x794f1e8a, "nvme_setup_cmd" },
	{ 0xa11cd276, "nvme_start_freeze" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x63b29a7a, "nvme_start_ctrl" },
	{ 0xf82d3dd4, "pcibios_resource_to_bus" },
	{ 0xedc03953, "iounmap" },
	{ 0xb74b780e, "param_set_uint" },
	{ 0xc67be5c0, "nvme_complete_batch_req" },
	{ 0x839b38eb, "nvme_submit_sync_cmd" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xdaf61130, "pci_disable_pcie_error_reporting" },
	{ 0xd35a6d31, "mempool_kmalloc" },
	{ 0x64b62862, "nvme_wq" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xa40a8382, "get_device" },
	{ 0xd8895d42, "nvme_disable_ctrl" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x9493fc86, "node_states" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x30036fd4, "blk_mq_alloc_tag_set" },
	{ 0x678b96ec, "dma_pool_alloc" },
	{ 0x6a037cf1, "mempool_kfree" },
	{ 0x5a1f6e62, "blk_mq_end_request_batch" },
	{ 0xf5f370e0, "async_schedule_node" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xb7742c25, "blk_mq_pci_map_queues" },
	{ 0x485b1a27, "nvme_wait_freeze" },
	{ 0x15cc8f51, "nvme_cancel_request" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xe1c59fe2, "nvme_cleanup_cmd" },
	{ 0x18f07c94, "param_get_uint" },
	{ 0x6857b57e, "nvme_sync_queues" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xff44f9f8, "dma_max_mapping_size" },
	{ 0x3197c4e3, "put_device" },
	{ 0x8da72a19, "pci_free_irq" },
	{ 0x9c122bcf, "mempool_create_node" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x5e9a1b55, "__tracepoint_nvme_sq" },
	{ 0x1d2915ac, "blk_mq_free_request" },
	{ 0x58b5116, "nvme_change_ctrl_state" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x2587f789, "_dev_info" },
	{ 0x5b2439a7, "pci_select_bars" },
	{ 0xa7876cad, "nvme_init_ctrl" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x11a5a8d4, "blk_get_queue" },
	{ 0x13fe63c1, "nvme_fail_nonready_command" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x5779794, "pci_request_irq" },
	{ 0x750122e9, "pci_load_saved_state" },
	{ 0xa26854e7, "blk_execute_rq_nowait" },
	{ 0x2f7754a8, "dma_pool_free" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc823584a, "pci_device_is_present" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x44ce4eb, "acpi_storage_d3" },
	{ 0x1fb2f26b, "__blk_rq_map_sg" },
	{ 0xc0f68dd3, "nvme_remove_namespaces" },
	{ 0x386865d5, "blk_mq_alloc_request" },
	{ 0xde80cd09, "ioremap" },
	{ 0x5a363f17, "blk_mq_free_tag_set" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x51641162, "opal_unlock_from_suspend" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x813cf212, "nvme_io_timeout" },
	{ 0x18641660, "blk_put_queue" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x81904f3e, "nvme_enable_ctrl" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x2ee71002, "nvme_try_sched_reset" },
	{ 0x9819ee8, "pci_enable_pcie_error_reporting" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x3c1ecf80, "blk_mq_init_queue" },
	{ 0x8a9c70ed, "nvme_sec_submit" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0xcbfb33e4, "init_opal_dev" },
	{ 0x42635d55, "pm_suspend_global_flags" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xcde77bcc, "free_opal_dev" },
	{ 0x9cd3240b, "blk_mq_update_nr_hw_queues" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x5ba48502, "__SCK__tp_func_nvme_sq" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xb5aa7165, "dma_pool_destroy" },
	{ 0x78ddb76b, "dmi_match" },
	{ 0x5df61205, "param_set_uint_minmax" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xe18ddc1f, "nvme_stop_admin_queue" },
	{ 0x73436831, "nvme_kill_queues" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x91acb249, "nvme_complete_async_event" },
	{ 0x87b8798d, "sg_next" },
	{ 0xde11df5f, "nvme_stop_queues" },
	{ 0x9034a696, "mempool_destroy" },
	{ 0xdacabd45, "nvme_set_queue_count" },
	{ 0x56470118, "__warn_printk" },
	{ 0x2cd4b76e, "nvme_shutdown_ctrl" },
	{ 0x4d4d7b79, "blk_mq_map_queues" },
	{ 0xab128a, "nvme_start_admin_queue" },
	{ 0x2aa0f75d, "nvme_set_features" },
	{ 0x75363368, "blk_mq_start_request" },
	{ 0xb9d4cc93, "blk_mq_tagset_busy_iter" },
	{ 0x34e555f1, "nvme_unfreeze" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x8b425fa4, "nvme_stop_ctrl" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x3bf2393a, "__SCT__tp_func_nvme_sq" },
	{ 0x48b237a, "nvme_wait_reset" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x2c80cada, "nvme_init_request" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x31795ba9, "device_release_driver" },
	{ 0x72d9de8b, "pci_sriov_configure_simple" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x783ce71c, "nvme_init_ctrl_finish" },
	{ 0x5884a7c6, "nvme_reset_ctrl" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0x2569f74, "blk_cleanup_queue" },
	{ 0x66ab0f6e, "nvme_get_features" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x475dd3f4, "__nvme_check_ready" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x18e60984, "__do_once_start" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x5c26a53b, "wait_for_completion_io_timeout" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nvme-core");

MODULE_ALIAS("pci:v00008086d00000953sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000A53sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000A54sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000A55sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000F1A5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000F1A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00005845sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001B36d00000010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000126Fd00002263sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001BB1d00000100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C58d00000003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C58d00000023sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C5Fd00000540sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Dd0000A821sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Dd0000A822sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001987d00005012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001987d00005016sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001B4Bd00001092sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001CC1d000033F8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010ECd00005762sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001CC1d00008201sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001344d00005407sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C5Cd00001504sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C5Cd0000174Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B7d00002001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D97d00002263sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Dd0000A80Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Dd0000A809sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001CC4d00006303sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001CC4d00006302sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00002646d00002262sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00002646d00002263sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001E4Bd00001001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001E4Bd00001002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001E4Bd00001202sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001CC1d00005350sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001E49d00000041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd00000061sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd00000065sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd00008061sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd0000CD00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd0000CD01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd0000CD02sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000106Bd00002001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000106Bd00002003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000106Bd00002005sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v*d*sv*sd*bc01sc08i02*");

MODULE_INFO(srcversion, "C01C610CFFDFF12CBBB592E");
