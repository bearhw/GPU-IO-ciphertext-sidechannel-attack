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

SYMBOL_CRC(fpga_bridge_enable, 0xc225df3a, "_gpl");
SYMBOL_CRC(fpga_bridge_disable, 0x40c721a4, "_gpl");
SYMBOL_CRC(of_fpga_bridge_get, 0xc0344638, "_gpl");
SYMBOL_CRC(fpga_bridge_get, 0xb4240d3b, "_gpl");
SYMBOL_CRC(fpga_bridge_put, 0x6ee66a6d, "_gpl");
SYMBOL_CRC(fpga_bridges_enable, 0x0633c4b9, "_gpl");
SYMBOL_CRC(fpga_bridges_disable, 0x2c8167cf, "_gpl");
SYMBOL_CRC(fpga_bridges_put, 0x0b2b884c, "_gpl");
SYMBOL_CRC(of_fpga_bridge_get_to_list, 0xb5d3a138, "_gpl");
SYMBOL_CRC(fpga_bridge_get_to_list, 0x0beae26f, "_gpl");
SYMBOL_CRC(fpga_bridge_register, 0xf3643ec5, "_gpl");
SYMBOL_CRC(fpga_bridge_unregister, 0xba5e0275, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x3197c4e3, "put_device" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x95d472ce, "device_match_of_node" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x1de23e95, "module_put" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xffb7c514, "ida_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x754d539c, "strlen" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x422066d2, "device_register" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BD8CB1D5AABC02FB5015E1A");
