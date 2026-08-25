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
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x22c71c1, "md_wakeup_thread" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa6257a2f, "complete" },
	{ 0x5232906e, "md_register_thread" },
	{ 0x92997ed8, "_printk" },
	{ 0xe914e41e, "strcpy" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x754d539c, "strlen" },
	{ 0x647d6170, "dlm_lock" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x4b62826c, "dlm_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe35d81bf, "md_find_rdev_nr_rcu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x935bae2a, "md_bitmap_resize" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x406989a7, "md_reload_sb" },
	{ 0x4fd1913c, "mddev_unlock" },
	{ 0x2287440d, "set_capacity_and_notify" },
	{ 0x56470118, "__warn_printk" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xd0d09c49, "md_bitmap_sync_with_cluster" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xdd64e639, "strscpy" },
	{ 0x245d1c1c, "md_cluster_ops" },
	{ 0x86490580, "current_task" },
	{ 0x73e008ea, "md_bitmap_free" },
	{ 0xe18ec4f5, "get_bitmap_from_slot" },
	{ 0x27e4d20a, "md_bitmap_update_sb" },
	{ 0xd730efa8, "md_bitmap_copy_from_slot" },
	{ 0xd3220720, "md_check_recovery" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xcd224e1d, "dlm_new_lockspace" },
	{ 0xe3d51626, "md_unregister_thread" },
	{ 0xcf9f3328, "dlm_release_lockspace" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xc24ac022, "md_update_sb" },
	{ 0x4e6295fa, "register_md_cluster_operations" },
	{ 0x15bafe29, "unregister_md_cluster_operations" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dlm");


MODULE_INFO(srcversion, "5CC6BD1A41575ED742D2529");
