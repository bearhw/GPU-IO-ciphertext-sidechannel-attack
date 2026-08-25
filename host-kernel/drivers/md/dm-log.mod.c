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

SYMBOL_CRC(dm_dirty_log_type_register, 0xe6064208, "");
SYMBOL_CRC(dm_dirty_log_type_unregister, 0x238bd255, "");
SYMBOL_CRC(dm_dirty_log_create, 0xe43ddd3e, "");
SYMBOL_CRC(dm_dirty_log_destroy, 0x2fd31db6, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x96848186, "scnprintf" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x999e8297, "vfree" },
	{ 0x9e4faeef, "dm_io_client_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x601f665f, "dm_io_client_create" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xfb578fc5, "memset" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2d8750e5, "dm_io" },
	{ 0x2bf609c5, "dm_table_event" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x1de23e95, "module_put" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x9f984513, "strrchr" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3fe2ccbe, "memweight" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B374EF99000F56D12883169");
