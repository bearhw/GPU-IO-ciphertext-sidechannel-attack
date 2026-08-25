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

SYMBOL_CRC(mhi_register_controller, 0x1b4704af, "_gpl");
SYMBOL_CRC(mhi_unregister_controller, 0xdf9cd31f, "_gpl");
SYMBOL_CRC(mhi_alloc_controller, 0xb1f9be3b, "_gpl");
SYMBOL_CRC(mhi_free_controller, 0xd7da38a4, "_gpl");
SYMBOL_CRC(mhi_prepare_for_power_up, 0x15937681, "_gpl");
SYMBOL_CRC(mhi_unprepare_after_power_down, 0x7b3005b6, "_gpl");
SYMBOL_CRC(__mhi_driver_register, 0xf3627dca, "_gpl");
SYMBOL_CRC(mhi_driver_unregister, 0xfa296300, "_gpl");
SYMBOL_CRC(mhi_get_exec_env, 0x7b543194, "_gpl");
SYMBOL_CRC(mhi_get_mhi_state, 0x907c59e1, "_gpl");
SYMBOL_CRC(mhi_soc_reset, 0x5f99088d, "_gpl");
SYMBOL_CRC(mhi_get_free_desc_count, 0x9a584644, "_gpl");
SYMBOL_CRC(mhi_notify, 0x08fbad5b, "_gpl");
SYMBOL_CRC(mhi_queue_skb, 0x381bd073, "_gpl");
SYMBOL_CRC(mhi_queue_dma, 0x50dc3121, "_gpl");
SYMBOL_CRC(mhi_queue_buf, 0x33da900f, "_gpl");
SYMBOL_CRC(mhi_queue_is_full, 0x295018a2, "_gpl");
SYMBOL_CRC(mhi_prepare_for_transfer, 0xe8afa031, "_gpl");
SYMBOL_CRC(mhi_prepare_for_transfer_autoqueue, 0xac571ac0, "_gpl");
SYMBOL_CRC(mhi_unprepare_from_transfer, 0xcc1fc515, "_gpl");
SYMBOL_CRC(mhi_poll, 0xe1117cae, "_gpl");
SYMBOL_CRC(mhi_pm_suspend, 0xc8d566bf, "_gpl");
SYMBOL_CRC(mhi_pm_resume, 0x56eb3d25, "_gpl");
SYMBOL_CRC(mhi_pm_resume_force, 0xaae8332f, "_gpl");
SYMBOL_CRC(mhi_async_power_up, 0x6062c253, "_gpl");
SYMBOL_CRC(mhi_power_down, 0x44f8b60d, "_gpl");
SYMBOL_CRC(mhi_sync_power_up, 0x32980d8d, "");
SYMBOL_CRC(mhi_force_rddm_mode, 0xe1a7a809, "_gpl");
SYMBOL_CRC(mhi_device_get, 0xf7abeac2, "_gpl");
SYMBOL_CRC(mhi_device_get_sync, 0x6c10b695, "_gpl");
SYMBOL_CRC(mhi_device_put, 0x2b153a89, "_gpl");
SYMBOL_CRC(mhi_download_rddm_image, 0x5d190bb7, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x48112d76, "_raw_read_lock_irq" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x3aca0190, "_raw_write_lock_irq" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xb6af5afe, "pm_wakeup_dev_event" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x3197c4e3, "put_device" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x48098f3, "device_add" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3312881b, "device_del" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x999e8297, "vfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xa4191c0b, "memset_io" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C7B44C625EFDDA72C3098C9");
