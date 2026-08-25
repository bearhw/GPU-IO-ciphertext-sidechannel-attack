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

SYMBOL_CRC(fw_core_add_descriptor, 0x3a771e39, "");
SYMBOL_CRC(fw_core_remove_descriptor, 0x0bc6094c, "");
SYMBOL_CRC(fw_schedule_bus_reset, 0x06df810a, "");
SYMBOL_CRC(fw_card_initialize, 0x279526d8, "");
SYMBOL_CRC(fw_card_add, 0x6cf685e0, "");
SYMBOL_CRC(fw_card_release, 0xe86fb5c7, "_gpl");
SYMBOL_CRC(fw_core_remove_card, 0xb0f43515, "");
SYMBOL_CRC(fw_card_read_cycle_time, 0x4c44d9d5, "_gpl");
SYMBOL_CRC(fw_csr_iterator_init, 0xe80e5087, "");
SYMBOL_CRC(fw_csr_iterator_next, 0xe3fde125, "");
SYMBOL_CRC(fw_csr_string, 0x6dc50487, "");
SYMBOL_CRC(fw_bus_type, 0x2369da5f, "");
SYMBOL_CRC(fw_device_enable_phys_dma, 0x95b42ae9, "");
SYMBOL_CRC(fw_workqueue, 0x3c56ef91, "");
SYMBOL_CRC(fw_iso_buffer_init, 0xc95c1a5f, "");
SYMBOL_CRC(fw_iso_buffer_destroy, 0x7d918d36, "");
SYMBOL_CRC(fw_iso_context_create, 0x7b8ee9e6, "");
SYMBOL_CRC(fw_iso_context_destroy, 0x8136ab9e, "");
SYMBOL_CRC(fw_iso_context_start, 0xbba412fe, "");
SYMBOL_CRC(fw_iso_context_queue, 0x0ff3d6d5, "");
SYMBOL_CRC(fw_iso_context_queue_flush, 0xb75c9765, "");
SYMBOL_CRC(fw_iso_context_flush_completions, 0xec3dc84d, "");
SYMBOL_CRC(fw_iso_context_stop, 0xd835c3a9, "");
SYMBOL_CRC(fw_iso_resource_manage, 0x82a6711e, "");
SYMBOL_CRC(fw_core_handle_bus_reset, 0x4e89d458, "");
SYMBOL_CRC(fw_cancel_transaction, 0xab25a05c, "");
SYMBOL_CRC(fw_send_request, 0x15cf37f1, "");
SYMBOL_CRC(fw_run_transaction, 0x0c8f2543, "");
SYMBOL_CRC(fw_high_memory_region, 0xaedf84ce, "");
SYMBOL_CRC(fw_core_add_address_handler, 0xa1939e45, "");
SYMBOL_CRC(fw_core_remove_address_handler, 0x36eadb73, "");
SYMBOL_CRC(fw_fill_response, 0x37fefd44, "");
SYMBOL_CRC(fw_send_response, 0xbe564b91, "");
SYMBOL_CRC(fw_get_request_speed, 0x2885fec5, "");
SYMBOL_CRC(fw_request_get_timestamp, 0xabb5547d, "_gpl");
SYMBOL_CRC(fw_core_handle_request, 0x9b3dfc25, "");
SYMBOL_CRC(fw_core_handle_response, 0x9fcd89b0, "");
SYMBOL_CRC(fw_rcode_string, 0x86468d44, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x20978fb9, "idr_find" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x5e515be6, "ktime_get_ts64" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xd66c8184, "add_device_randomness" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x3197c4e3, "put_device" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x48098f3, "device_add" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x954f099c, "idr_preload" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x1edb69d6, "ktime_get_raw_ts64" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x11089ac7, "_ctype" },
	{ 0x422066d2, "device_register" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3b48a9d9, "nonseekable_open" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x1d40b6f3, "idr_for_each" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x56470118, "__warn_printk" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0x636a2492, "no_llseek" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9a34a2b, "crc_itu_t" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xbda2916c, "vm_map_pages_zero" },
	{ 0x53b954a2, "up_read" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "crc-itu-t");


MODULE_INFO(srcversion, "CCE9FECDA8880379312184C");
