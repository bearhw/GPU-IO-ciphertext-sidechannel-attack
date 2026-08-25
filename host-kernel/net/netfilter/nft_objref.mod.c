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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x754d539c, "strlen" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6ca5c4b2, "nft_obj_lookup" },
	{ 0x81038d2f, "nf_tables_destroy_set" },
	{ 0xd2ff380f, "nf_tables_deactivate_set" },
	{ 0x7202e3e1, "nft_set_lookup_global" },
	{ 0xe2b8cc13, "nft_parse_register_load" },
	{ 0x247dca3c, "nf_tables_bind_set" },
	{ 0x7a2c13de, "nft_set_do_lookup" },
	{ 0x84cf13b7, "nft_set_catchall_lookup" },
	{ 0x38d85c39, "nft_dump_register" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables");


MODULE_INFO(srcversion, "52B7FAB4FDFCA03B5F1D93A");
