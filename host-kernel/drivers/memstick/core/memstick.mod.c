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

SYMBOL_CRC(memstick_detect_change, 0x63c2cc99, "");
SYMBOL_CRC(memstick_next_req, 0xa9aba759, "");
SYMBOL_CRC(memstick_new_req, 0xe6475b21, "");
SYMBOL_CRC(memstick_init_req_sg, 0x4a4e5778, "");
SYMBOL_CRC(memstick_init_req, 0xae50437c, "");
SYMBOL_CRC(memstick_set_rw_addr, 0x767817c7, "");
SYMBOL_CRC(memstick_alloc_host, 0x9c25bc16, "");
SYMBOL_CRC(memstick_add_host, 0x1cb50365, "");
SYMBOL_CRC(memstick_remove_host, 0xd0582469, "");
SYMBOL_CRC(memstick_free_host, 0x6240a29e, "");
SYMBOL_CRC(memstick_suspend_host, 0x68136d78, "");
SYMBOL_CRC(memstick_resume_host, 0x4570d708, "");
SYMBOL_CRC(memstick_register_driver, 0x792a60e5, "");
SYMBOL_CRC(memstick_unregister_driver, 0x8935728c, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa6257a2f, "complete" },
	{ 0x37a0cba, "kfree" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa40a8382, "get_device" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x422066d2, "device_register" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x954f099c, "idr_preload" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x6d606913, "pv_ops" },
	{ 0x48098f3, "device_add" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x3312881b, "device_del" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xc487b792, "bus_register" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F88689FB9AEC62AA355F271");
