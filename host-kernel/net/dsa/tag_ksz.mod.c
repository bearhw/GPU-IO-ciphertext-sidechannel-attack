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
	{ 0xbe888b32, "skb_put" },
	{ 0xf652d653, "skb_checksum_help" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0xe489931, "dsa_tag_drivers_register" },
	{ 0xf69aec4a, "dsa_tag_drivers_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dsa_core");


MODULE_INFO(srcversion, "132DE4D75CDE395CD44E3CB");
