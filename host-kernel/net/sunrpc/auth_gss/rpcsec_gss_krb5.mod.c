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


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xb28c35c8, "xdr_buf_trim" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x482ac5a4, "g_token_size" },
	{ 0xb0e602eb, "memmove" },
	{ 0x5aeb548d, "xdr_process_buf" },
	{ 0x416cd128, "read_bytes_from_xdr_buf" },
	{ 0x1f42e417, "crypto_ahash_setkey" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x31a725c8, "gss_mech_unregister" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x86490580, "current_task" },
	{ 0xfb578fc5, "memset" },
	{ 0x31a89d59, "rpc_debug" },
	{ 0x879cf980, "xdr_buf_subsegment" },
	{ 0xd7673035, "g_verify_token_header" },
	{ 0x79e8fe8c, "crypto_alloc_sync_skcipher" },
	{ 0x7e9b64ed, "crypto_ahash_final" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x8dba9065, "gss_mech_register" },
	{ 0xf54bd49b, "lcm" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x3498d552, "crypto_stats_ahash_update" },
	{ 0x2dcc9fda, "write_bytes_to_xdr_buf" },
	{ 0x38d3dce5, "g_make_token_header" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sunrpc,auth_rpcgss");


MODULE_INFO(srcversion, "683A26EF9EC7FA9DE7D2024");
