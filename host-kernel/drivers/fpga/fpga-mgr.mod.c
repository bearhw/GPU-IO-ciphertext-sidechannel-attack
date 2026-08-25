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

SYMBOL_CRC(fpga_image_info_alloc, 0x624e770f, "_gpl");
SYMBOL_CRC(fpga_image_info_free, 0x80a93eb3, "_gpl");
SYMBOL_CRC(fpga_mgr_load, 0x3dcf2833, "_gpl");
SYMBOL_CRC(fpga_mgr_get, 0xdec2b03f, "_gpl");
SYMBOL_CRC(of_fpga_mgr_get, 0x3a527401, "_gpl");
SYMBOL_CRC(fpga_mgr_put, 0xc274e043, "_gpl");
SYMBOL_CRC(fpga_mgr_lock, 0x7a71d3cd, "_gpl");
SYMBOL_CRC(fpga_mgr_unlock, 0x711428e5, "_gpl");
SYMBOL_CRC(fpga_mgr_register_full, 0x8ee70c22, "_gpl");
SYMBOL_CRC(fpga_mgr_register, 0xd772282b, "_gpl");
SYMBOL_CRC(fpga_mgr_unregister, 0x01a8d8c2, "_gpl");
SYMBOL_CRC(devm_fpga_mgr_register_full, 0xe4508275, "_gpl");
SYMBOL_CRC(devm_fpga_mgr_register, 0x634f7f45, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa40a8382, "get_device" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3197c4e3, "put_device" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x1de23e95, "module_put" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xffb7c514, "ida_free" },
	{ 0x2587f789, "_dev_info" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x754d539c, "strlen" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x422066d2, "device_register" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xea900f57, "devres_add" },
	{ 0xe93e49c3, "devres_free" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x558e68f5, "sg_alloc_table_from_pages_segment" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x95d472ce, "device_match_of_node" },
	{ 0x92997ed8, "_printk" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C70AD2F46DB6D55519158A0");
