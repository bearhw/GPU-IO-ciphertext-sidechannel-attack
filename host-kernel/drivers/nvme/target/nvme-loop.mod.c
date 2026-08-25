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
	{ 0x134ef5bd, "nvme_uninit_ctrl" },
	{ 0x51189b95, "nvme_complete_rq" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x51c659eb, "nvmf_free_options" },
	{ 0xd8c57a53, "blk_mq_tagset_wait_completed_request" },
	{ 0xd45434ee, "admin_timeout" },
	{ 0xe6db41b0, "blk_mq_complete_request_remote" },
	{ 0x794f1e8a, "nvme_setup_cmd" },
	{ 0x63b29a7a, "nvme_start_ctrl" },
	{ 0xa789c0b1, "nvmf_connect_io_queue" },
	{ 0x37a0cba, "kfree" },
	{ 0x274dd1a3, "sg_free_table_chained" },
	{ 0x31ec5018, "nvmf_reg_read32" },
	{ 0x5c1ea997, "nvme_delete_ctrl" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x30036fd4, "blk_mq_alloc_tag_set" },
	{ 0x9fdbb040, "nvmf_get_address" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x35c7353, "nvmet_sq_destroy" },
	{ 0x92997ed8, "_printk" },
	{ 0x15cc8f51, "nvme_cancel_request" },
	{ 0xe1c59fe2, "nvme_cleanup_cmd" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xecf89816, "nvmf_unregister_transport" },
	{ 0x3197c4e3, "put_device" },
	{ 0x6508aecd, "nvmet_unregister_transport" },
	{ 0x58b5116, "nvme_change_ctrl_state" },
	{ 0x2587f789, "_dev_info" },
	{ 0xa7876cad, "nvme_init_ctrl" },
	{ 0xd58bbbcb, "nvme_delete_wq" },
	{ 0x92cc0704, "nvmet_req_init" },
	{ 0x13fe63c1, "nvme_fail_nonready_command" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2e47c67f, "nvmet_register_transport" },
	{ 0x1fb2f26b, "__blk_rq_map_sg" },
	{ 0x343d800b, "nvmf_reg_read64" },
	{ 0x5a363f17, "blk_mq_free_tag_set" },
	{ 0x4b61711b, "nvmf_connect_admin_queue" },
	{ 0x813cf212, "nvme_io_timeout" },
	{ 0x81904f3e, "nvme_enable_ctrl" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x3c1ecf80, "blk_mq_init_queue" },
	{ 0x961a6c11, "blk_mq_hctx_set_fq_lock_class" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x9cd3240b, "blk_mq_update_nr_hw_queues" },
	{ 0xd8d91733, "nvmf_reg_write32" },
	{ 0xe18ddc1f, "nvme_stop_admin_queue" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3214b0a8, "nvmet_sq_init" },
	{ 0x91acb249, "nvme_complete_async_event" },
	{ 0xde11df5f, "nvme_stop_queues" },
	{ 0xdacabd45, "nvme_set_queue_count" },
	{ 0x2cd4b76e, "nvme_shutdown_ctrl" },
	{ 0xab128a, "nvme_start_admin_queue" },
	{ 0x52bee7f2, "nvmf_register_transport" },
	{ 0x75363368, "blk_mq_start_request" },
	{ 0xb9d4cc93, "blk_mq_tagset_busy_iter" },
	{ 0x8b425fa4, "nvme_stop_ctrl" },
	{ 0x783ce71c, "nvme_init_ctrl_finish" },
	{ 0x1bee4974, "sg_alloc_table_chained" },
	{ 0x2569f74, "blk_cleanup_queue" },
	{ 0x3e0ef07a, "nvmet_wq" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x475dd3f4, "__nvme_check_ready" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nvme-core,nvme-fabrics,nvmet");


MODULE_INFO(srcversion, "69703FA5BE17ACA841F4EBC");
