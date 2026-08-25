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

SYMBOL_CRC(nci_spi_send, 0x02acd0d8, "_gpl");
SYMBOL_CRC(nci_spi_allocate_spi, 0x1b10ce87, "_gpl");
SYMBOL_CRC(nci_spi_read, 0x26c07824, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xbe888b32, "skb_put" },
	{ 0xa6257a2f, "complete" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x52ecbc75, "crc_ccitt" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x8b51deca, "spi_sync" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8D095BA7208A66C45BCFDDD");
