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

SYMBOL_CRC(virtio_dma_buf_export, 0x96143fde, "");
SYMBOL_CRC(virtio_dma_buf_attach, 0x74921884, "");
SYMBOL_CRC(is_virtio_dma_buf, 0x40fa40dd, "");
SYMBOL_CRC(virtio_dma_buf_get_uuid, 0xe758aaa8, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xba6e4b5e, "dma_buf_export" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "948E819AB0475A85666144F");
