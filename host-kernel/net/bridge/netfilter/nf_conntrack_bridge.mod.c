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
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3b120344, "br_dev_queue_push_xmit" },
	{ 0xdba43280, "nf_ct_frag6_gather" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x1de7493b, "ip_defrag" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x64175a25, "nf_conntrack_in" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x9739d19f, "__nf_conntrack_confirm" },
	{ 0xf5bdc7aa, "nf_confirm" },
	{ 0xbaeddd05, "nf_ct_deliver_cached_events" },
	{ 0x7951d4f, "ip_frag_init" },
	{ 0x6940d1c8, "ip_frag_next" },
	{ 0x394bc7d8, "br_ip6_fragment" },
	{ 0xf652d653, "skb_checksum_help" },
	{ 0x36172a2d, "ip_fraglist_init" },
	{ 0x56450d15, "ip_fraglist_prepare" },
	{ 0xd01cc0c4, "kfree_skb_list_reason" },
	{ 0xbd505649, "consume_skb" },
	{ 0xf3a9ffe3, "nf_ct_bridge_register" },
	{ 0xdaba6bed, "nf_ct_bridge_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bridge,nf_defrag_ipv6,nf_conntrack");


MODULE_INFO(srcversion, "D4F771F56A9FD34BAA7293C");
