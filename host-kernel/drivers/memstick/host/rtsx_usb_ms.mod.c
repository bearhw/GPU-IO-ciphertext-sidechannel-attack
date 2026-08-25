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
	{ 0x4570d708, "memstick_resume_host" },
	{ 0x68136d78, "memstick_suspend_host" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa9aba759, "memstick_next_req" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xd0582469, "memstick_remove_host" },
	{ 0x6240a29e, "memstick_free_host" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x15c3cf51, "rtsx_usb_add_cmd" },
	{ 0xaf05ddb7, "rtsx_usb_send_cmd" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x63c2cc99, "memstick_detect_change" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x2b9d9740, "rtsx_usb_read_register" },
	{ 0x94093ec1, "rtsx_usb_write_register" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x77cb22c1, "rtsx_usb_get_rsp" },
	{ 0xa38605ec, "rtsx_usb_ep0_read_register" },
	{ 0x2776346a, "rtsx_usb_ep0_write_register" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x91bad0ac, "rtsx_usb_card_exclusive_check" },
	{ 0x60d97f2d, "rtsx_usb_transfer_data" },
	{ 0x9c25bc16, "memstick_alloc_host" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x1cb50365, "memstick_add_host" },
	{ 0xa7dec208, "rtsx_usb_switch_clock" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "memstick,rtsx_usb");

MODULE_ALIAS("platform:rtsx_usb_ms");

MODULE_INFO(srcversion, "EDCB765630E723C67EC3ED4");
