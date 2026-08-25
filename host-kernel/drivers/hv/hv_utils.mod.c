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
	{ 0xcaff6dc5, "vmbus_driver_unregister" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x7a95e5ae, "do_settimeofday64" },
	{ 0x2fd90375, "vmbus_sendpacket" },
	{ 0x321055cb, "vmbus_prep_negotiate_resp" },
	{ 0xa2f7487f, "hv_is_hibernation_supported" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xa3afc2c1, "vmbus_close" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xd64660db, "vmbus_recvpacket" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x56256e8a, "orderly_poweroff" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xa916b694, "strnlen" },
	{ 0x800473f, "__cond_resched" },
	{ 0xa6c4041, "cn_netlink_send" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x77f9ae61, "vmbus_open" },
	{ 0x81db095, "ptp_clock_register" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x46a417ca, "vmbus_proto_version" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x4708008a, "misc_register" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x85f6adc3, "ptp_clock_unregister" },
	{ 0x7483e13, "cn_del_callback" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x8f4947c8, "__vmbus_driver_register" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xabf32f29, "utf16s_to_utf8s" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xec096b0, "hv_read_reference_counter" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0x794b7271, "orderly_reboot" },
	{ 0x97adb487, "utf8s_to_utf16s" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x77346fe8, "cn_add_callback" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hv_vmbus");

MODULE_ALIAS("vmbus:31600b0e13523449818b38d90ced39db");
MODULE_ALIAS("vmbus:30e62795aed07b49adcee80ab0175caf");
MODULE_ALIAS("vmbus:394f16571591784eab55382f3bd5422d");
MODULE_ALIAS("vmbus:e7f4a0a9455a964db8278a841e8c03e6");
MODULE_ALIAS("vmbus:292efa3523ea364296ae3a6ebacba440");
MODULE_ALIAS("vmbus:e34bd134e4dec8419ae76b174977c192");

MODULE_INFO(srcversion, "407AC177D4F53780961CD41");
