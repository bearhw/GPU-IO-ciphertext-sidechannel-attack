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
	{ 0xcb0890e3, "crypto_register_aead" },
	{ 0xea91e76, "crypto_unregister_aead" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x86490580, "current_task" },
	{ 0x9f0c3bd, "skcipher_walk_aead_encrypt" },
	{ 0xfb578fc5, "memset" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x845dbf3b, "scatterwalk_map_and_copy" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x87b8798d, "sg_next" },
	{ 0x1a10c32b, "crypto_ft_tab" },
	{ 0xd7f34d89, "skcipher_walk_aead_decrypt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "93109E3932999C30B1E98C2");
