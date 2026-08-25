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

SYMBOL_CRC(i3c_device_do_priv_xfers, 0x4d05bdf9, "_gpl");
SYMBOL_CRC(i3c_device_get_info, 0x4dfe7958, "_gpl");
SYMBOL_CRC(i3c_device_disable_ibi, 0x37a203d6, "_gpl");
SYMBOL_CRC(i3c_device_enable_ibi, 0x6d1b58df, "_gpl");
SYMBOL_CRC(i3c_device_request_ibi, 0xa053feb9, "_gpl");
SYMBOL_CRC(i3c_device_free_ibi, 0xdb665891, "_gpl");
SYMBOL_CRC(i3cdev_to_dev, 0x036a4a79, "_gpl");
SYMBOL_CRC(dev_to_i3cdev, 0xd6efc1e6, "_gpl");
SYMBOL_CRC(i3c_device_match_id, 0x036e00d7, "_gpl");
SYMBOL_CRC(i3c_driver_register_with_owner, 0xeeab4cd5, "_gpl");
SYMBOL_CRC(i3c_driver_unregister, 0x9b9e44e5, "_gpl");
SYMBOL_CRC(i3c_master_get_free_addr, 0xbb126c9a, "_gpl");
SYMBOL_CRC(i3c_master_entdaa_locked, 0xeb0790dc, "_gpl");
SYMBOL_CRC(i3c_master_disec_locked, 0xfdc0f64c, "_gpl");
SYMBOL_CRC(i3c_master_enec_locked, 0x9033a0c5, "_gpl");
SYMBOL_CRC(i3c_master_defslvs_locked, 0xbec87f8f, "_gpl");
SYMBOL_CRC(i3c_master_do_daa, 0x0d856bf7, "_gpl");
SYMBOL_CRC(i3c_master_set_info, 0x009f4099, "_gpl");
SYMBOL_CRC(i3c_master_add_i3c_dev_locked, 0xeddeb948, "_gpl");
SYMBOL_CRC(i3c_master_queue_ibi, 0x223b920c, "_gpl");
SYMBOL_CRC(i3c_generic_ibi_free_pool, 0x76fe3e05, "_gpl");
SYMBOL_CRC(i3c_generic_ibi_alloc_pool, 0x694af998, "_gpl");
SYMBOL_CRC(i3c_generic_ibi_get_free_slot, 0x7ad4242b, "_gpl");
SYMBOL_CRC(i3c_generic_ibi_recycle_slot, 0x6cee69e8, "_gpl");
SYMBOL_CRC(i3c_master_register, 0x6b7080dd, "_gpl");
SYMBOL_CRC(i3c_master_unregister, 0x6c94fa3e, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa9cec9e6, "bus_unregister_notifier" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x5087e9ca, "i2c_client_type" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x37a0cba, "kfree" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x3318cdf8, "bus_register_notifier" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce807a25, "up_write" },
	{ 0x48098f3, "device_add" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9166fada, "strncpy" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x73965ef6, "i2c_new_client_device" },
	{ 0xde37f64f, "i2c_bus_type" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x422066d2, "device_register" },
	{ 0x3312881b, "device_del" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x668b19a1, "down_read" },
	{ 0x6b7bb67b, "i2c_add_adapter" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x53b954a2, "up_read" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A797DB7BD457E9509B7F9E0");
