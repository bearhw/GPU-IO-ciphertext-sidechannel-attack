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
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xed477587, "dev_mc_del" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x8942405e, "dev_mc_add" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb55bbd45, "proc_remove" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0x37a0cba, "kfree" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xa906274e, "seq_putc" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x92997ed8, "_printk" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x5e06bc5c, "refcount_dec_and_lock" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x6d606913, "pv_ops" },
	{ 0x23d8225b, "seq_open" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x60e68b98, "nf_unregister_net_hook" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x56a53f51, "seq_release" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0xa916b694, "strnlen" },
	{ 0xd70cb50a, "nf_register_net_hook" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x2bf33597, "proc_create_data" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x67a704bf, "xt_register_target" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xa5d0ece2, "xt_unregister_target" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xf2b11959, "seq_read" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,x_tables");


MODULE_INFO(srcversion, "815ED0986C727050296B17D");
