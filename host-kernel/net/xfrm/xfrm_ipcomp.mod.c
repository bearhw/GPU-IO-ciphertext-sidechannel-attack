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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(ipcomp_input, 0x4e419ac5, "_gpl");
SYMBOL_CRC(ipcomp_output, 0x93d9e272, "_gpl");
SYMBOL_CRC(ipcomp_destroy, 0x7726f66a, "_gpl");
SYMBOL_CRC(ipcomp_init_state, 0x0a67c380, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37a0cba, "kfree" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x999e8297, "vfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xaab23340, "xfrm_calg_get_byname" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x618911fc, "numa_node" },
	{ 0x23fd3028, "vmalloc_node" },
	{ 0x8f7b8ada, "crypto_alloc_base" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x25825770, "crypto_comp_compress" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x3499aa91, "___pskb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeef197f4, "xfrm_state_delete_tunnel" },
	{ 0x46f34d5c, "crypto_comp_decompress" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_algo");


MODULE_INFO(srcversion, "22BD1E28CF5F084553C1EB9");
