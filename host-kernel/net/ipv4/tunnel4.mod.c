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

SYMBOL_CRC(xfrm4_tunnel_register, 0xfdd81ad2, "");
SYMBOL_CRC(xfrm4_tunnel_deregister, 0x52ca7990, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x9def366f, "__icmp_send" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x1e208bf5, "inet_add_protocol" },
	{ 0xe71edfc0, "inet_del_protocol" },
	{ 0x6052bd93, "xfrm_input_register_afinfo" },
	{ 0x92997ed8, "_printk" },
	{ 0xbea31caf, "xfrm_input_unregister_afinfo" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "32170CA64B000CA5E9607B0");
