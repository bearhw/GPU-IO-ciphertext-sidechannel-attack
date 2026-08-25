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

SYMBOL_CRC(slimbus_bus, 0x55e99707, "_gpl");
SYMBOL_CRC(__slim_driver_register, 0xace98960, "_gpl");
SYMBOL_CRC(slim_driver_unregister, 0xaf4e5117, "_gpl");
SYMBOL_CRC(slim_register_controller, 0x8f2b0c85, "_gpl");
SYMBOL_CRC(slim_unregister_controller, 0xec04e37a, "_gpl");
SYMBOL_CRC(slim_report_absent, 0xddd6045e, "_gpl");
SYMBOL_CRC(slim_get_device, 0x488e9d0f, "_gpl");
SYMBOL_CRC(of_slim_get_device, 0xc1b1335e, "_gpl");
SYMBOL_CRC(slim_device_report_present, 0xbac257df, "_gpl");
SYMBOL_CRC(slim_get_logical_addr, 0xfa3c4c36, "_gpl");
SYMBOL_CRC(slim_msg_response, 0xbf72cdba, "_gpl");
SYMBOL_CRC(slim_alloc_txn_tid, 0xa2922d3c, "_gpl");
SYMBOL_CRC(slim_free_txn_tid, 0x08e7b173, "_gpl");
SYMBOL_CRC(slim_do_transfer, 0x67c3268b, "_gpl");
SYMBOL_CRC(slim_xfer_msg, 0xebfbfe0d, "_gpl");
SYMBOL_CRC(slim_read, 0xf46726a9, "_gpl");
SYMBOL_CRC(slim_readb, 0x46d576c4, "_gpl");
SYMBOL_CRC(slim_write, 0x3269bedf, "_gpl");
SYMBOL_CRC(slim_writeb, 0xb92d6527, "_gpl");
SYMBOL_CRC(slim_ctrl_clk_pause, 0x05ea191c, "_gpl");
SYMBOL_CRC(slim_stream_allocate, 0x97493371, "_gpl");
SYMBOL_CRC(slim_stream_prepare, 0x08605688, "_gpl");
SYMBOL_CRC(slim_stream_enable, 0xf6b26a8b, "_gpl");
SYMBOL_CRC(slim_stream_disable, 0xf13b3bee, "_gpl");
SYMBOL_CRC(slim_stream_unprepare, 0xc8a373ff, "_gpl");
SYMBOL_CRC(slim_stream_free, 0x1c01fe4c, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x20978fb9, "idr_find" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0xa6257a2f, "complete" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x37a0cba, "kfree" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x91f44510, "idr_alloc_cyclic" },
	{ 0x422066d2, "device_register" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9582041F83AF7B811C1A4A2");
