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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1de23e95, "module_put" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xbb5600e2, "xt_check_match" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa916b694, "strnlen" },
	{ 0x8520a781, "nla_put" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xedbaee5e, "nla_strcmp" },
	{ 0x98202308, "xt_request_find_match" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x4699ca54, "tcf_em_register" },
	{ 0xb874ef43, "tcf_em_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "DB0BD9DF65564FFA8069B40");
