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

SYMBOL_CRC(nf_dup_ipv4, 0x596b8dc0, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x70c52dc5, "nf_skb_duplicated" },
	{ 0x9fa78973, "__pskb_copy_fclone" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0x8a60e5c8, "ip_local_out" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xe05b6928, "dst_release" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D349050B58ADAABC15B08A7");
