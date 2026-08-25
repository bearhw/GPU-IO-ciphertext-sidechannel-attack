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
	{ 0xa0fa90e0, "crypto_unregister_alg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfa72c345, "crypto_register_alg" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xe6a9a548, "crypto_register_skciphers" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xa77b3b62, "des3_ede_expand_key" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x27eee3d8, "crypto_unregister_skciphers" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libdes");


MODULE_INFO(srcversion, "7219AA0F612596FF15E6207");
