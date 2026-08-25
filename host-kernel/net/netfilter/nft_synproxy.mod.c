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
	{ 0xae47eb8d, "nft_chain_validate_hooks" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xca9fc082, "synproxy_net_id" },
	{ 0xce386e7, "nf_synproxy_ipv4_fini" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0x1024bb, "nf_synproxy_ipv6_fini" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x66e22319, "nf_synproxy_ipv4_init" },
	{ 0x6a118145, "nf_synproxy_ipv6_init" },
	{ 0xad14ca49, "nf_ip_checksum" },
	{ 0x6bc0a249, "synproxy_parse_options" },
	{ 0x750ccab, "synproxy_recv_client_ack_ipv6" },
	{ 0xbd505649, "consume_skb" },
	{ 0x65eb9bd0, "synproxy_recv_client_ack" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xda58ffd4, "synproxy_send_client_synack_ipv6" },
	{ 0xe12d99b5, "synproxy_send_client_synack" },
	{ 0x1f099794, "synproxy_init_timestamp_cookie" },
	{ 0x61688841, "nft_register_obj" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x497d4d0e, "nft_unregister_obj" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables,nf_synproxy_core,nf_conntrack");


MODULE_INFO(srcversion, "6949A7D0D408C18F3C84B22");
