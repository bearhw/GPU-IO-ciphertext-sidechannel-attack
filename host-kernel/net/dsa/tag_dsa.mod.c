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
	{ 0x4eb6f185, "skb_push" },
	{ 0xb0e602eb, "memmove" },
	{ 0x99311936, "br_vlan_enabled" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xe489931, "dsa_tag_drivers_register" },
	{ 0xf69aec4a, "dsa_tag_drivers_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bridge,dsa_core");


MODULE_INFO(srcversion, "593AEFC91A35CCF31D82A6A");
