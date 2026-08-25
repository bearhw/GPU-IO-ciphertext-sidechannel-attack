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

SYMBOL_CRC(capi_ctr_handle_message, 0x18c78aba, "");
SYMBOL_CRC(capi_ctr_ready, 0xd684322b, "");
SYMBOL_CRC(capi_ctr_down, 0xf0f5849e, "");
SYMBOL_CRC(attach_capi_ctr, 0xac24667c, "");
SYMBOL_CRC(detach_capi_ctr, 0x623ea7b3, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0x60eda3b5, "proc_create" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x1e91687d, "tty_kref_put" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb1e8027, "__tty_alloc_driver" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x15bd91a4, "tty_standard_install" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x148653, "vsnprintf" },
	{ 0x34ac593f, "tty_unregister_driver" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x67b27ec1, "tty_std_termios" },
	{ 0x90641976, "tty_unregister_device" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x5fb2dddd, "tty_port_tty_wakeup" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x97e4f755, "tty_ldisc_ref" },
	{ 0xa097bede, "tty_vhangup" },
	{ 0x1f1f589c, "device_create" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x781a487c, "tty_port_init" },
	{ 0x9166fada, "strncpy" },
	{ 0xb49ce922, "tty_port_register_device" },
	{ 0x9d087aff, "tty_ldisc_deref" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x11089ac7, "_ctype" },
	{ 0x23af578f, "default_llseek" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0xad252699, "tty_port_close" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0xaa6878ed, "tty_port_put" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc783c290, "tty_register_driver" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xaa7322dc, "tty_port_hangup" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x2f3a6084, "tty_port_open" },
	{ 0x636a2492, "no_llseek" },
	{ 0x7ec6993, "stream_open" },
	{ 0xa6aa1711, "proc_create_single_data" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x2032b017, "tty_driver_kref_put" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xcd420564, "tty_port_tty_get" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9A60905EC61C0E01CCEA499");
