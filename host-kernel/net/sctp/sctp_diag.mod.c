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
	{ 0xefc35200, "netlink_net_capable" },
	{ 0x1c0824b1, "sctp_for_each_endpoint" },
	{ 0x29862c12, "sctp_get_sctp_info" },
	{ 0xff703b81, "sctp_transport_traverse_process" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x720d3ca3, "inet_diag_register" },
	{ 0xad115d2, "nla_reserve" },
	{ 0x37a5d32, "sock_diag_save_cookie" },
	{ 0x2ec631e3, "sock_diag_check_cookie" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xf2f426ad, "inet_diag_msg_common_fill" },
	{ 0xa8d4fe3e, "nla_reserve_64bit" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8520a781, "nla_put" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xb20739b0, "inet_diag_msg_attrs_fill" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x915a0c88, "inet_diag_unregister" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x310ea3ed, "sctp_transport_lookup_process" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sctp,inet_diag");


MODULE_INFO(srcversion, "A065C894CB3A07E6CD8CAC7");
