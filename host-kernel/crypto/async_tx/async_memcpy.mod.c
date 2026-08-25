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

SYMBOL_CRC(async_memcpy, 0xe86a06f1, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x60d8ea72, "__async_tx_find_channel" },
	{ 0x3c9842b6, "dmaengine_get_unmap_data" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe981687c, "async_tx_submit" },
	{ 0x12788e99, "async_tx_quiesce" },
	{ 0x86490580, "current_task" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x69acdf38, "memcpy" },
	{ 0x8849c1c3, "dmaengine_unmap_put" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "async_tx");


MODULE_INFO(srcversion, "6B1E7FF95EAC2758C9CD924");
