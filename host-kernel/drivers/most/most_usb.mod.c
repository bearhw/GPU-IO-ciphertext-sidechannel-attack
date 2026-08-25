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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3bbbaa64, "most_resume_enqueue" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x13c129b7, "most_stop_enqueue" },
	{ 0x962c8ae1, "usb_kill_anchored_urbs" },
	{ 0x37a0cba, "kfree" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xa2fc07ba, "most_deregister_interface" },
	{ 0x3197c4e3, "put_device" },
	{ 0xae1356e4, "usb_free_coherent" },
	{ 0x94d8b289, "usb_alloc_coherent" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf8e504bd, "usb_clear_halt" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0xd62aa9e6, "usb_anchor_urb" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0xb0e602eb, "memmove" },
	{ 0x1ad22551, "usb_free_urb" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcbd6b32e, "usb_unanchor_urb" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x24d273d1, "add_timer" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x42048153, "most_register_interface" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa40a8382, "get_device" },
	{ 0x422066d2, "device_register" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x821e463, "usb_deregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "most_core");


MODULE_INFO(srcversion, "749172E84EF6EA711F76742");
