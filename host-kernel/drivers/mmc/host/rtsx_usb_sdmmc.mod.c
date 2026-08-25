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
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x15c3cf51, "rtsx_usb_add_cmd" },
	{ 0xaf05ddb7, "rtsx_usb_send_cmd" },
	{ 0x77cb22c1, "rtsx_usb_get_rsp" },
	{ 0x348165a9, "rtsx_usb_read_ppbuf" },
	{ 0x2b9d9740, "rtsx_usb_read_register" },
	{ 0x94093ec1, "rtsx_usb_write_register" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8ac39522, "rtsx_usb_get_card_status" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x91bad0ac, "rtsx_usb_card_exclusive_check" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xa7dec208, "rtsx_usb_switch_clock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2776346a, "rtsx_usb_ep0_write_register" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa38605ec, "rtsx_usb_ep0_read_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x905695ab, "sg_copy_from_buffer" },
	{ 0x37a0cba, "kfree" },
	{ 0x60d97f2d, "rtsx_usb_transfer_data" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0x2824885b, "rtsx_usb_write_ppbuf" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "rtsx_usb");

MODULE_ALIAS("platform:rtsx_usb_sdmmc");

MODULE_INFO(srcversion, "8BC56801D29C5B2CF2AF257");
