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

SYMBOL_CRC(acpi_smbus_read, 0x4f6c2360, "_gpl");
SYMBOL_CRC(acpi_smbus_write, 0x96eb492d, "_gpl");
SYMBOL_CRC(acpi_smbus_register_callback, 0x87bd07bd, "_gpl");
SYMBOL_CRC(acpi_smbus_unregister_callback, 0x1c8984c7, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x27810361, "acpi_os_wait_events_complete" },
	{ 0x24a735c6, "acpi_ec_remove_query_handler" },
	{ 0x37a0cba, "kfree" },
	{ 0xfc4152fc, "ec_read" },
	{ 0xc708f1fe, "ec_write" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xd70f62b6, "acpi_os_execute" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xdd68a17d, "acpi_ec_add_query_handler" },
	{ 0x2587f789, "_dev_info" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:ACPI0001:*");
MODULE_ALIAS("acpi*:ACPI0005:*");

MODULE_INFO(srcversion, "261C35263F1EA0626300926");
