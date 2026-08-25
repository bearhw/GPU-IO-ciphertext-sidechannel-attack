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

SYMBOL_CRC(nf_fwd_netdev_egress, 0xdae9e638, "_gpl");
SYMBOL_CRC(nf_dup_netdev_egress, 0x65eb6b1a, "_gpl");
SYMBOL_CRC(nft_fwd_dup_netdev_offload, 0x0faaba80, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F59154AE8C5199DA992F066");
