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

SYMBOL_CRC(free_rs, 0xfd581da1, "_gpl");
SYMBOL_CRC(init_rs_gfp, 0xeb2f825c, "_gpl");
SYMBOL_CRC(init_rs_non_canonical, 0x561835eb, "_gpl");
SYMBOL_CRC(encode_rs8, 0x63adbf92, "_gpl");
SYMBOL_CRC(decode_rs8, 0x1d29b9e1, "_gpl");
SYMBOL_CRC(decode_rs16, 0xa32f3d9e, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0xb0e602eb, "memmove" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xfb578fc5, "memset" },
	{ 0x69acdf38, "memcpy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "10919B26B9BB58A5A743D6F");
