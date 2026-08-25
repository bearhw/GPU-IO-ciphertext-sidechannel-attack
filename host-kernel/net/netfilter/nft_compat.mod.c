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
	{ 0x1de23e95, "module_put" },
	{ 0x37a0cba, "kfree" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xad115d2, "nla_reserve" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfb578fc5, "memset" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x3251d762, "nf_tables_trans_destroy_flush_work" },
	{ 0xbb5600e2, "xt_check_match" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc7b94877, "xt_check_target" },
	{ 0xc49d60a2, "nft_request_module" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xddf68fc6, "xt_find_revision" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x754d539c, "strlen" },
	{ 0x8520a781, "nla_put" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x92997ed8, "_printk" },
	{ 0xb6115b4e, "xt_request_find_target" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x98202308, "xt_request_find_match" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables,x_tables,nfnetlink");


MODULE_INFO(srcversion, "932845B6241131C55E31D99");
