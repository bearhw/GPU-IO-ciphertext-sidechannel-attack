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
	{ 0xca9fc082, "synproxy_net_id" },
	{ 0x1024bb, "nf_synproxy_ipv6_fini" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x6a118145, "nf_synproxy_ipv6_init" },
	{ 0xf6a9ff1d, "nf_ip6_checksum" },
	{ 0x6bc0a249, "synproxy_parse_options" },
	{ 0x750ccab, "synproxy_recv_client_ack_ipv6" },
	{ 0xbd505649, "consume_skb" },
	{ 0xda58ffd4, "synproxy_send_client_synack_ipv6" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x1f099794, "synproxy_init_timestamp_cookie" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x67a704bf, "xt_register_target" },
	{ 0xa5d0ece2, "xt_unregister_target" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_synproxy_core,nf_conntrack,x_tables");


MODULE_INFO(srcversion, "A65220212D1F6A380653B93");
