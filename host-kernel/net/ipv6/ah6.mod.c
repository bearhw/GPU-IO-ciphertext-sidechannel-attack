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
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xfa226f9f, "xfrm_output_resume" },
	{ 0xb0e602eb, "memmove" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x92997ed8, "_printk" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x1aa799ac, "xfrm_input_resume" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0x1f42e417, "crypto_ahash_setkey" },
	{ 0x37a02412, "xfrm_aalg_get_byname" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x5eaeadb, "ip6_update_pmtu" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x54afee, "ip6_redirect" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0x9e73a62, "skb_cow_data" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xfb578fc5, "memset" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x8e54873a, "skb_to_sgvec_nomark" },
	{ 0x347da517, "crypto_ahash_digest" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x24c60e49, "xfrm_register_type" },
	{ 0x816f7600, "xfrm6_protocol_register" },
	{ 0x844bd2de, "xfrm_unregister_type" },
	{ 0x1909477e, "xfrm6_protocol_deregister" },
	{ 0x32050f48, "xfrm6_rcv" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_algo");


MODULE_INFO(srcversion, "65D976691D9ABC03C2FF84D");
