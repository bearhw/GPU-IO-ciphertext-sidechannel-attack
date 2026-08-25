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

SYMBOL_CRC(zstd_min_clevel, 0x4f20d80b, "");
SYMBOL_CRC(zstd_max_clevel, 0x665e2513, "");
SYMBOL_CRC(zstd_compress_bound, 0xb80b4a18, "");
SYMBOL_CRC(zstd_get_params, 0x6315c42c, "");
SYMBOL_CRC(zstd_cctx_workspace_bound, 0xbe6a8c96, "");
SYMBOL_CRC(zstd_init_cctx, 0x0a84b15d, "");
SYMBOL_CRC(zstd_compress_cctx, 0xf2628676, "");
SYMBOL_CRC(zstd_cstream_workspace_bound, 0x9d26675e, "");
SYMBOL_CRC(zstd_init_cstream, 0xc078d22c, "");
SYMBOL_CRC(zstd_reset_cstream, 0x39d95ca4, "");
SYMBOL_CRC(zstd_compress_stream, 0xffc4f200, "");
SYMBOL_CRC(zstd_flush_stream, 0xdad1fc3f, "");
SYMBOL_CRC(zstd_end_stream, 0x0d333b64, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb0e602eb, "memmove" },
	{ 0x69acdf38, "memcpy" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xb2f35c6a, "xxh64" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe32ab4d8, "xxh64_digest" },
	{ 0xfb578fc5, "memset" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x658ce1a8, "xxh64_reset" },
	{ 0x3f0eabd2, "xxh64_update" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "002792252D1D002FE77C2C1");
