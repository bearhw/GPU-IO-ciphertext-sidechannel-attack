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

SYMBOL_CRC(nfsacl_encode, 0x1f801a3d, "_gpl");
SYMBOL_CRC(nfs_stream_encode_acl, 0x98ffd38e, "_gpl");
SYMBOL_CRC(nfsacl_decode, 0x0631cb59, "_gpl");
SYMBOL_CRC(nfs_stream_decode_acl, 0x0f18c08d, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xea61792, "xdr_decode_array2" },
	{ 0xb0e602eb, "memmove" },
	{ 0x68af92a9, "xdr_inline_decode" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xb7c0f443, "sort" },
	{ 0x9b496b21, "posix_acl_alloc" },
	{ 0x7f78fd7e, "from_kgid" },
	{ 0x402830fd, "from_kuid" },
	{ 0x6a797b3b, "xdr_encode_word" },
	{ 0xbf59c419, "posix_acl_init" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x16239ec4, "xdr_reserve_space" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xac67e608, "xdr_encode_array2" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x5f210060, "xdr_decode_word" },
	{ 0xc1e98764, "xdr_stream_pos" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sunrpc");


MODULE_INFO(srcversion, "1F1B1CE4983D855AB3967E3");
