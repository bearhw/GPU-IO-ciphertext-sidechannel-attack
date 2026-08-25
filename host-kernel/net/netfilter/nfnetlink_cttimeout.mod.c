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
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xa916b694, "strnlen" },
	{ 0x8520a781, "nla_put" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x5a921311, "strncmp" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x37a0cba, "kfree" },
	{ 0x2e0a33ae, "nf_ct_l4proto_find" },
	{ 0x754d539c, "strlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x1de23e95, "module_put" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x27fd6cee, "nf_ct_untimeout" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc6f3b3fc, "refcount_dec_if_one" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xc2ad8480, "nf_ct_timeout_hook" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0xf126880c, "nf_ct_iterate_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfnetlink,nf_conntrack");


MODULE_INFO(srcversion, "506707930D46805CD1459C7");
