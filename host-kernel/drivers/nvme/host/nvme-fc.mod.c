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

SYMBOL_CRC(nvme_fc_register_localport, 0x1d79e898, "_gpl");
SYMBOL_CRC(nvme_fc_unregister_localport, 0x3884f8b8, "_gpl");
SYMBOL_CRC(nvme_fc_register_remoteport, 0x0d12e564, "_gpl");
SYMBOL_CRC(nvme_fc_unregister_remoteport, 0xfca9dc99, "_gpl");
SYMBOL_CRC(nvme_fc_rescan_remoteport, 0x3e33ac54, "_gpl");
SYMBOL_CRC(nvme_fc_set_remoteport_devloss, 0x8a9cf5a7, "_gpl");
SYMBOL_CRC(nvme_fc_rcv_ls_req, 0xbb0e18a6, "_gpl");
SYMBOL_CRC(nvme_fc_io_getuuid, 0x58e312f7, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xf0047107, "nvme_sync_io_queues" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x134ef5bd, "nvme_uninit_ctrl" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x51189b95, "nvme_complete_rq" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x51c659eb, "nvmf_free_options" },
	{ 0xd8c57a53, "blk_mq_tagset_wait_completed_request" },
	{ 0x2aa4e901, "nvme_start_queues" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd45434ee, "admin_timeout" },
	{ 0xe6db41b0, "blk_mq_complete_request_remote" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x794f1e8a, "nvme_setup_cmd" },
	{ 0x63b29a7a, "nvme_start_ctrl" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0xa789c0b1, "nvmf_connect_io_queue" },
	{ 0xfba7ddd2, "match_u64" },
	{ 0x37a0cba, "kfree" },
	{ 0x274dd1a3, "sg_free_table_chained" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x64b62862, "nvme_wq" },
	{ 0x31ec5018, "nvmf_reg_read32" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x5c1ea997, "nvme_delete_ctrl" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x30036fd4, "blk_mq_alloc_tag_set" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x9fdbb040, "nvmf_get_address" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1000e51, "schedule" },
	{ 0xe1c59fe2, "nvme_cleanup_cmd" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xecf89816, "nvmf_unregister_transport" },
	{ 0xa8805b36, "blkcg_get_fc_appid" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0x58b5116, "nvme_change_ctrl_state" },
	{ 0x2587f789, "_dev_info" },
	{ 0xa7876cad, "nvme_init_ctrl" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x13fe63c1, "nvme_fail_nonready_command" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x1f1f589c, "device_create" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x58b1e30a, "blk_sync_queue" },
	{ 0x5a921311, "strncmp" },
	{ 0x68460527, "blkcg_set_fc_appid" },
	{ 0x1fb2f26b, "__blk_rq_map_sg" },
	{ 0x9166fada, "strncpy" },
	{ 0xffb7c514, "ida_free" },
	{ 0x343d800b, "nvmf_reg_read64" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x5a363f17, "blk_mq_free_tag_set" },
	{ 0x49224181, "nvme_reset_wq" },
	{ 0x4b61711b, "nvmf_connect_admin_queue" },
	{ 0x813cf212, "nvme_io_timeout" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x81904f3e, "nvme_enable_ctrl" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x3c1ecf80, "blk_mq_init_queue" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x9cd3240b, "blk_mq_update_nr_hw_queues" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xd8d91733, "nvmf_reg_write32" },
	{ 0xe18ddc1f, "nvme_stop_admin_queue" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x545760bd, "nvmf_should_reconnect" },
	{ 0x91acb249, "nvme_complete_async_event" },
	{ 0x87b8798d, "sg_next" },
	{ 0xde11df5f, "nvme_stop_queues" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0xdacabd45, "nvme_set_queue_count" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x4d4d7b79, "blk_mq_map_queues" },
	{ 0xab128a, "nvme_start_admin_queue" },
	{ 0x52bee7f2, "nvmf_register_transport" },
	{ 0x75363368, "blk_mq_start_request" },
	{ 0xb9d4cc93, "blk_mq_tagset_busy_iter" },
	{ 0x8b425fa4, "nvme_stop_ctrl" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x783ce71c, "nvme_init_ctrl_finish" },
	{ 0x349cba85, "strchr" },
	{ 0x5884a7c6, "nvme_reset_ctrl" },
	{ 0x1bee4974, "sg_alloc_table_chained" },
	{ 0x2569f74, "blk_cleanup_queue" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x475dd3f4, "__nvme_check_ready" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nvme-core,nvme-fabrics");


MODULE_INFO(srcversion, "D2AD6B5EF5F9F8496BE0361");
