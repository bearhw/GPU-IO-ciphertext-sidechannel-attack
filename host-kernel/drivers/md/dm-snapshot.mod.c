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

SYMBOL_CRC(dm_snap_origin, 0xed93bb28, "");
SYMBOL_CRC(dm_snap_cow, 0x8a36f474, "");
SYMBOL_CRC(dm_exception_store_type_register, 0xe80a6b34, "");
SYMBOL_CRC(dm_exception_store_type_unregister, 0xf54aebee, "");
SYMBOL_CRC(dm_exception_store_create, 0xc68bc69e, "");
SYMBOL_CRC(dm_exception_store_destroy, 0x9eca5675, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x919e42b3, "dm_internal_resume_fast" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x4b5fd49e, "dm_kcopyd_do_callback" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0xca9360b5, "rb_next" },
	{ 0xfb5d0b97, "dm_table_get_size" },
	{ 0xc90df7e5, "dm_bufio_prefetch" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x96848186, "scnprintf" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xdc868649, "dm_hold" },
	{ 0x37a0cba, "kfree" },
	{ 0x7880c781, "dm_kcopyd_prepare_callback" },
	{ 0xb04f56ab, "dm_bufio_read" },
	{ 0x601f665f, "dm_io_client_create" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1984d421, "out_of_line_wait_on_bit" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd688716b, "dm_kcopyd_client_create" },
	{ 0x1000e51, "schedule" },
	{ 0xc849b0b6, "dm_accept_partial_bio" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x9f984513, "strrchr" },
	{ 0x16e297c3, "bit_wait" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xeca7949e, "dm_bufio_client_destroy" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x800473f, "__cond_resched" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0x2773c485, "__wake_up_locked" },
	{ 0xa34af51, "dm_suspended" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x93a6e0b2, "io_schedule" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0x3d86bedc, "dm_bufio_client_create" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xe6024e59, "dm_bufio_release" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x11089ac7, "_ctype" },
	{ 0x466793e6, "dm_set_target_max_io_len" },
	{ 0x851b1e40, "dm_kcopyd_zero" },
	{ 0xfb578fc5, "memset" },
	{ 0x2bf609c5, "dm_table_event" },
	{ 0x96ac2277, "dm_internal_suspend_fast" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xece784c2, "rb_first" },
	{ 0xe52634d2, "dm_put" },
	{ 0x9e4faeef, "dm_io_client_destroy" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x80702017, "dm_kcopyd_copy" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0x999e8297, "vfree" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x154c6338, "dm_kcopyd_client_destroy" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x72f07bf4, "dm_bufio_set_minimum_buffers" },
	{ 0x6b9f01cd, "blkdev_issue_flush" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xb1b06a8f, "dm_table_get_md" },
	{ 0xd991e3b9, "dm_bufio_get_device_size" },
	{ 0xfc14bb2e, "dm_get_dev_t" },
	{ 0x2d8750e5, "dm_io" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xa0fbac79, "wake_up_bit" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x53b954a2, "up_read" },
	{ 0xcd2ba798, "dm_bufio_forget" },
	{ 0xceeef209, "dm_bio_get_target_bio_nr" },
	{ 0x7deff673, "dm_consume_args" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x38e46431, "mempool_exit" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-bufio");


MODULE_INFO(srcversion, "BF1453D7605FFD00C99FD90");
