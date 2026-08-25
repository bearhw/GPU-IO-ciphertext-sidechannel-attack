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

SYMBOL_CRC(__async_tx_find_channel, 0x60d8ea72, "_gpl");
SYMBOL_CRC(async_tx_submit, 0xe981687c, "_gpl");
SYMBOL_CRC(async_trigger_callback, 0xc1ce938a, "_gpl");
SYMBOL_CRC(async_tx_quiesce, 0x12788e99, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfccd2998, "dma_find_channel" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6cf89373, "dma_wait_for_async_tx" },
	{ 0xf1e046cc, "panic" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x923b1276, "dmaengine_get" },
	{ 0x92997ed8, "_printk" },
	{ 0x57575f08, "dmaengine_put" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "08915ACF300183F5A43051C");
