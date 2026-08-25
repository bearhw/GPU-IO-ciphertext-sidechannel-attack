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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4833efaf, "blk_mq_stop_hw_queues" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xc39b8467, "blk_mq_requeue_request" },
	{ 0x92997ed8, "_printk" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xe6475b21, "memstick_new_req" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x87b8798d, "sg_next" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0x461d16ca, "sg_nents" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc2436cd7, "blk_mq_start_hw_queues" },
	{ 0x8f381413, "del_gendisk" },
	{ 0x2569f74, "blk_cleanup_queue" },
	{ 0x5a363f17, "blk_mq_free_tag_set" },
	{ 0x39978da, "put_disk" },
	{ 0xae50437c, "memstick_init_req" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x75363368, "blk_mq_start_request" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xfb578fc5, "memset" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x905695ab, "sg_copy_from_buffer" },
	{ 0x1fb2f26b, "__blk_rq_map_sg" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0x34e1053e, "blk_mq_end_request" },
	{ 0xde68eda4, "blk_update_request" },
	{ 0xe1d97c99, "__blk_mq_end_request" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x744de463, "blk_mq_alloc_sq_tag_set" },
	{ 0xa84e677a, "__blk_mq_alloc_disk" },
	{ 0xbb146a4b, "blk_queue_max_hw_sectors" },
	{ 0xd2ce8dc4, "blk_queue_max_segments" },
	{ 0xce73cb81, "blk_queue_max_segment_size" },
	{ 0x81088473, "blk_queue_logical_block_size" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe3f3d437, "set_capacity" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x88330529, "device_add_disk" },
	{ 0xd2e83b51, "set_disk_ro" },
	{ 0xb5c4e0ab, "blk_cleanup_disk" },
	{ 0xa6257a2f, "complete" },
	{ 0x4a4e5778, "memstick_init_req_sg" },
	{ 0x792a60e5, "memstick_register_driver" },
	{ 0x8935728c, "memstick_unregister_driver" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "memstick");


MODULE_INFO(srcversion, "D1A85846892C2CCB8BA1477");
