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
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1ad22551, "usb_free_urb" },
	{ 0x6b7ee9c4, "gb_hd_put" },
	{ 0x2442786b, "gb_hd_cport_reserve" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xa6257a2f, "complete" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0xd55dc9aa, "gb_hd_add" },
	{ 0x69acdf38, "memcpy" },
	{ 0x78fedb98, "__SCT__tp_func_gb_message_submit" },
	{ 0x37a0cba, "kfree" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x619d9123, "__SCK__tp_func_gb_message_submit" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xadff1dc0, "gb_hd_create" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x8638d295, "gb_debugfs_get" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1065192a, "usb_put_dev" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb210748a, "usb_get_dev" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xd88dd44a, "gb_hd_del" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8f364c9c, "greybus_message_sent" },
	{ 0x89f3c06c, "__tracepoint_gb_message_submit" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0xffb7c514, "ida_free" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x821e463, "usb_deregister" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf9ca2eb4, "kstrtoint_from_user" },
	{ 0xbe3cb384, "greybus_data_rcvd" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x52405e22, "usb_get_urb" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x2d767457, "gb_hd_cport_release_reserved" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x5f0fb884, "usb_kill_urb" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x13d0adf7, "__kfifo_out" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "greybus");

MODULE_ALIAS("usb:v18D1p1EAFd*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "D5848B26193C833A16065D2");
