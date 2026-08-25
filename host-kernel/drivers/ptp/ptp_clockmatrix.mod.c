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
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x387da1c0, "ptp_schedule_worker" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9714e0bb, "ktime_get_raw" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x2587f789, "_dev_info" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x85f6adc3, "ptp_clock_unregister" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x4e20169c, "ptp_find_pin" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf9a482f9, "msleep" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x81db095, "ptp_clock_register" },
	{ 0x45b514fb, "ptp_clock_event" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "060260081E4A32CAD4C9284");
