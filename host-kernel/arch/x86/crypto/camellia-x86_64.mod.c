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

SYMBOL_CRC(__camellia_enc_blk, 0xfe729ed6, "_gpl");
SYMBOL_CRC(camellia_dec_blk, 0xff09bd65, "_gpl");
SYMBOL_CRC(__camellia_enc_blk_2way, 0x69f4ff25, "_gpl");
SYMBOL_CRC(camellia_dec_blk_2way, 0x0b901549, "_gpl");
SYMBOL_CRC(__camellia_setkey, 0x8d725052, "_gpl");
SYMBOL_CRC(camellia_decrypt_cbc_2way, 0x8d9b761c, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xa0fa90e0, "crypto_unregister_alg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfa72c345, "crypto_register_alg" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xe6a9a548, "crypto_register_skciphers" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x27eee3d8, "crypto_unregister_skciphers" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "90010F3F0C47876E78DF533");
