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

SYMBOL_CRC(esp6_output_head, 0x94a0683d, "_gpl");
SYMBOL_CRC(esp6_output_tail, 0xf589389a, "_gpl");
SYMBOL_CRC(esp6_input_done2, 0x967421c0, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a02412, "xfrm_aalg_get_byname" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x5eaeadb, "ip6_update_pmtu" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x54afee, "ip6_redirect" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0xf13f3c44, "km_new_mapping" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0x3499aa91, "___pskb_trim" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x1aa799ac, "xfrm_input_resume" },
	{ 0x9e73a62, "skb_cow_data" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x1abb51ae, "skb_to_sgvec" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x87b8798d, "sg_next" },
	{ 0x10795da2, "__put_page" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x8ef690f7, "xfrm_dev_resume" },
	{ 0xfa226f9f, "xfrm_output_resume" },
	{ 0xce1ac14a, "__skb_ext_del" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x5bc40a30, "xfrm_trans_queue_net" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xf341ee35, "tcp_hashinfo" },
	{ 0xc55c35e3, "__inet6_lookup_established" },
	{ 0x21b9b789, "tcp_is_ulp_esp" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6e3197e6, "espintcp_push_skb" },
	{ 0x6d606913, "pv_ops" },
	{ 0x851e1fb7, "espintcp_queue_out" },
	{ 0xed206e2d, "pskb_put" },
	{ 0xfb578fc5, "memset" },
	{ 0xce609ee2, "skb_page_frag_refill" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xdab6848c, "xfrm_state_mtu" },
	{ 0x24c60e49, "xfrm_register_type" },
	{ 0x816f7600, "xfrm6_protocol_register" },
	{ 0x844bd2de, "xfrm_unregister_type" },
	{ 0x1909477e, "xfrm6_protocol_deregister" },
	{ 0x32050f48, "xfrm6_rcv" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_algo");


MODULE_INFO(srcversion, "2776B75B68DAD120576ACF6");
