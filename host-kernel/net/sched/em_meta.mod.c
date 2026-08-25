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
	{ 0xf1e98c74, "avenrun" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x8520a781, "nla_put" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x37a0cba, "kfree" },
	{ 0xfd381298, "__skb_get_hash" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4699ca54, "tcf_em_register" },
	{ 0xb874ef43, "tcf_em_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "53A2A86D7B845838C731050");
