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

SYMBOL_CRC(most_submit_mbo, 0x693294db, "_gpl");
SYMBOL_CRC(channel_has_mbo, 0xff782251, "_gpl");
SYMBOL_CRC(most_get_mbo, 0x624e5609, "_gpl");
SYMBOL_CRC(most_put_mbo, 0x4e66de1e, "_gpl");
SYMBOL_CRC(most_start_channel, 0xe268024a, "_gpl");
SYMBOL_CRC(most_stop_channel, 0x796322e0, "_gpl");
SYMBOL_CRC(most_register_component, 0x48cfb9b7, "_gpl");
SYMBOL_CRC(most_deregister_component, 0xcbd95f6c, "_gpl");
SYMBOL_CRC(most_register_interface, 0x42048153, "_gpl");
SYMBOL_CRC(most_deregister_interface, 0xa2fc07ba, "_gpl");
SYMBOL_CRC(most_stop_enqueue, 0x13c129b7, "_gpl");
SYMBOL_CRC(most_resume_enqueue, 0x3bbbaa64, "_gpl");
SYMBOL_CRC(most_register_configfs_subsys, 0x5bbab859, "_gpl");
SYMBOL_CRC(most_deregister_configfs_subsys, 0x46bfdd77, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x187b64e8, "config_group_init" },
	{ 0x77bc13a0, "strim" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x96848186, "scnprintf" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb56b87f1, "configfs_unregister_subsystem" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x84909a73, "bus_find_device" },
	{ 0xffb2df28, "configfs_register_subsystem" },
	{ 0x8bc8cc11, "config_group_init_type_name" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5792f848, "strlcpy" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x422066d2, "device_register" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0xdd64e639, "strscpy" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe4994173, "config_item_init_type_name" },
	{ 0x56470118, "__warn_printk" },
	{ 0x5df0ab87, "device_match_name" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "59F28EAED2B55A2499F5164");
