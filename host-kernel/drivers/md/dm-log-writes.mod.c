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
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x80f31438, "dax_recovery_write" },
	{ 0xec5668f6, "dax_zero_page_range" },
	{ 0x2d609547, "dax_direct_access" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x963afbea, "wake_up_process" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x96848186, "scnprintf" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x18219d34, "bio_free_pages" },
	{ 0xa09dd780, "bio_put" },
	{ 0x92997ed8, "_printk" },
	{ 0xa6257a2f, "complete" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0x754d539c, "strlen" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x37a0cba, "kfree" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x86490580, "current_task" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfb578fc5, "memset" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x392b1fea, "wait_for_completion_io" },
	{ 0x7ab88a45, "system_freezing_cnt" },
	{ 0xec507773, "freezing_slow_path" },
	{ 0x4482cdb, "__refrigerator" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "524B565276C620539077ADD");
