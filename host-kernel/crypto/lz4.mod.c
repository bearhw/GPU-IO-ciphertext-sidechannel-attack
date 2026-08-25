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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc7c1107a, "LZ4_decompress_safe" },
	{ 0x4f4d78c5, "LZ4_compress_default" },
	{ 0x999e8297, "vfree" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xfa72c345, "crypto_register_alg" },
	{ 0xb608e41d, "crypto_register_scomp" },
	{ 0xa0fa90e0, "crypto_unregister_alg" },
	{ 0xe8e83c25, "crypto_unregister_scomp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "lz4_compress");


MODULE_INFO(srcversion, "05E0F81959B2010C32AD2EE");
