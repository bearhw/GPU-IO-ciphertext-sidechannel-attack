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

SYMBOL_CRC(async_gen_syndrome, 0x29ab38fb, "_gpl");
SYMBOL_CRC(async_syndrome_val, 0x45cc22a6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x60d8ea72, "__async_tx_find_channel" },
	{ 0x3c9842b6, "dmaengine_get_unmap_data" },
	{ 0x8849c1c3, "dmaengine_unmap_put" },
	{ 0x12788e99, "async_tx_quiesce" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xb0d904b7, "raid6_empty_zero_page" },
	{ 0x804a5b70, "raid6_call" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x17f54263, "raid6_gfexp" },
	{ 0xe981687c, "async_tx_submit" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe258926e, "async_xor_offs" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x92997ed8, "_printk" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "async_tx,raid6_pq,async_xor");


MODULE_INFO(srcversion, "6135C3A1A03DA6A7CCBE102");
