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
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x46bd24c2, "ipmi_get_smi_info" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa40a8382, "get_device" },
	{ 0xae71627d, "ipmi_create_user" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf388b18b, "ipmi_destroy_user" },
	{ 0x3197c4e3, "put_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa6257a2f, "complete" },
	{ 0x80aa4656, "ipmi_free_recv_msg" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4c2054d7, "ipmi_request_settime" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0xdbcf041a, "acpi_install_address_space_handler" },
	{ 0x92997ed8, "_printk" },
	{ 0x3ef3d9d3, "ipmi_smi_watcher_register" },
	{ 0x92e26bf, "acpi_remove_address_space_handler" },
	{ 0xa5ab594b, "ipmi_smi_watcher_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ipmi_msghandler");


MODULE_INFO(srcversion, "23E8467A2458DF0E6477327");
