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
	{ 0x38d85c39, "nft_dump_register" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe2b8cc13, "nft_parse_register_load" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables");


MODULE_INFO(srcversion, "B79BACD4F841BF86563E451");
