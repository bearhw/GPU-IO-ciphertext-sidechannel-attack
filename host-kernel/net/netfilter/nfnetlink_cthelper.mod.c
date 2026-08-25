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
	{ 0x8520a781, "nla_put" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc6cbbc89, "capable" },
	{ 0x5a921311, "strncmp" },
	{ 0xc6f3b3fc, "refcount_dec_if_one" },
	{ 0x924f2ced, "nf_conntrack_helper_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xa916b694, "strnlen" },
	{ 0x754d539c, "strlen" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xc40f284c, "nf_ct_helper_hsize" },
	{ 0x693c3961, "nf_ct_helper_hash" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xedbaee5e, "nla_strcmp" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0x3f9abf02, "nf_conntrack_helper_register" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,nfnetlink");


MODULE_INFO(srcversion, "648BDCF396531C114CFE21A");
