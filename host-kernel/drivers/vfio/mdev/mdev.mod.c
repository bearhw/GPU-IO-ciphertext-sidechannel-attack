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

SYMBOL_CRC(mdev_parent_dev, 0x14e257d2, "");
SYMBOL_CRC(mdev_get_type_group_id, 0xe207aabc, "");
SYMBOL_CRC(mtype_get_type_group_id, 0x304a3551, "");
SYMBOL_CRC(mtype_get_parent_dev, 0xf5224fea, "");
SYMBOL_CRC(mdev_register_device, 0x73d8f0e9, "");
SYMBOL_CRC(mdev_unregister_device, 0x562ab2b2, "");
SYMBOL_CRC(mdev_bus_type, 0xe15b9ad8, "_gpl");
SYMBOL_CRC(mdev_register_driver, 0x90001ca2, "");
SYMBOL_CRC(mdev_unregister_driver, 0x8f046d48, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xc72d9306, "device_remove_file_self" },
	{ 0x63799c0f, "sysfs_create_file_ns" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x3e4e64c9, "device_driver_attach" },
	{ 0xe5883bd9, "class_compat_unregister" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x37a0cba, "kfree" },
	{ 0x3f7b09fb, "kset_unregister" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x34880f3a, "sysfs_remove_files" },
	{ 0x32c3cb4e, "class_compat_register" },
	{ 0xa40a8382, "get_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0xdca09c91, "sysfs_remove_file_ns" },
	{ 0x2587f789, "_dev_info" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x48098f3, "device_add" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x1e964ca2, "class_compat_remove_link" },
	{ 0xc392bf7, "kobject_init_and_add" },
	{ 0x99a2fae, "class_compat_create_link" },
	{ 0x3312881b, "device_del" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x6b980b08, "kobject_del" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb89b6e6b, "guid_parse" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x631ba0f2, "sysfs_create_files" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x53b954a2, "up_read" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x929d9ed2, "kobject_get" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x7233a2e6, "kset_create_and_add" },
	{ 0x7c181721, "kobject_put" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3513E87C48651A47CB21FF7");
