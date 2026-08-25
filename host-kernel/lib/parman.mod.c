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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(parman_create, 0xc3e2d892, "");
SYMBOL_CRC(parman_destroy, 0xca39ae6a, "");
SYMBOL_CRC(parman_prio_init, 0x0f518717, "");
SYMBOL_CRC(parman_prio_fini, 0xc6a3d260, "");
SYMBOL_CRC(parman_item_add, 0x7b03d378, "");
SYMBOL_CRC(parman_item_remove, 0x8b7e26f5, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CD0E20D3A294F9ABBFAD85C");
