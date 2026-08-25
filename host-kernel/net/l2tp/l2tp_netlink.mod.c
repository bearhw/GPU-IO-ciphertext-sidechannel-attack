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

SYMBOL_CRC(l2tp_nl_register_ops, 0x5d4aa0a9, "_gpl");
SYMBOL_CRC(l2tp_nl_unregister_ops, 0x337f2432, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2b9da7a4, "genl_lock" },
	{ 0x2d140a58, "genl_unlock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xaa750062, "l2tp_session_get_by_ifname" },
	{ 0x5f4375c2, "l2tp_tunnel_get" },
	{ 0x44e8a412, "l2tp_tunnel_get_session" },
	{ 0x7c90c120, "l2tp_tunnel_dec_refcount" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8520a781, "nla_put" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xa916b694, "strnlen" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x3195783f, "l2tp_session_dec_refcount" },
	{ 0x7b0a3df8, "l2tp_session_get_nth" },
	{ 0x58ac7f2e, "l2tp_tunnel_get_nth" },
	{ 0xf07e285d, "genlmsg_multicast_allns" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4f7c2e55, "l2tp_tunnel_create" },
	{ 0xc59ed1d6, "l2tp_tunnel_inc_refcount" },
	{ 0xeb9dec00, "l2tp_tunnel_register" },
	{ 0x37a0cba, "kfree" },
	{ 0x2c1a0516, "l2tp_tunnel_delete" },
	{ 0xebf0ff1e, "l2tp_session_set_header_len" },
	{ 0x92997ed8, "_printk" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "l2tp_core");


MODULE_INFO(srcversion, "3326FBAA007165FC90EA19F");
