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
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9b657880, "usb_sg_cancel" },
	{ 0x88896213, "usb_unlink_urb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x9166fada, "strncpy" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0x37a0cba, "kfree" },
	{ 0xa6257a2f, "complete" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x1ad22551, "usb_free_urb" },
	{ 0x5f0fb884, "usb_kill_urb" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0x2214f6e, "usb_sg_init" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x24d273d1, "add_timer" },
	{ 0xbd88660, "usb_sg_wait" },
	{ 0xfb578fc5, "memset" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xb210748a, "usb_get_dev" },
	{ 0x1661c05f, "usb_string" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x1065192a, "usb_put_dev" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x92997ed8, "_printk" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x963afbea, "wake_up_process" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x379ec72a, "usb_lock_device_for_reset" },
	{ 0xff238c42, "usb_reset_device" },
	{ 0x905695ab, "sg_copy_from_buffer" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x96848186, "scnprintf" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x821e463, "usb_deregister" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v2201p012Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0424p012Cd*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "95A13A2F94CB16B053C8CFE");
