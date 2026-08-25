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
	{ 0x4db36a35, "tcf_block_put_ext" },
	{ 0x46013233, "net_dec_ingress_queue" },
	{ 0x86f85114, "net_dec_egress_queue" },
	{ 0x2c3054f9, "net_inc_ingress_queue" },
	{ 0x7be6905, "net_inc_egress_queue" },
	{ 0x9478211d, "mini_qdisc_pair_init" },
	{ 0xb995ec9d, "tcf_block_get_ext" },
	{ 0x901b7c4b, "mini_qdisc_pair_block_init" },
	{ 0x7cdf8aa4, "mini_qdisc_pair_swap" },
	{ 0x8520a781, "nla_put" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EBF77A2FC1E32262EB9808E");
