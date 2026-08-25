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

SYMBOL_CRC(fpga_region_class_find, 0x33604920, "_gpl");
SYMBOL_CRC(fpga_region_program_fpga, 0x18b9f6d4, "_gpl");
SYMBOL_CRC(fpga_region_register_full, 0xe6d147e3, "_gpl");
SYMBOL_CRC(fpga_region_register, 0xd22db78e, "_gpl");
SYMBOL_CRC(fpga_region_unregister, 0x782d0c53, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x1de23e95, "module_put" },
	{ 0x3197c4e3, "put_device" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa40a8382, "get_device" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x7a71d3cd, "fpga_mgr_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2c8167cf, "fpga_bridges_disable" },
	{ 0x3dcf2833, "fpga_mgr_load" },
	{ 0x633c4b9, "fpga_bridges_enable" },
	{ 0x711428e5, "fpga_mgr_unlock" },
	{ 0xb2b884c, "fpga_bridges_put" },
	{ 0xffb7c514, "ida_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x422066d2, "device_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-mgr,fpga-bridge");


MODULE_INFO(srcversion, "C7BB04C3472BB3352E58B9B");
