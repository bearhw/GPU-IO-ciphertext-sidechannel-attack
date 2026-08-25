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
	{ 0xc243b27a, "ip_set_get_ip6_port" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa293f8a6, "ip_set_get_ipaddr4" },
	{ 0x67dd76de, "ip_set_get_extensions" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7924b6de, "ip_set_hostmask_map" },
	{ 0x1a30617d, "ip_set_get_ip4_port" },
	{ 0x9e98722b, "ip_set_get_ipaddr6" },
	{ 0xe24187de, "ip_set_extensions" },
	{ 0x37a0cba, "kfree" },
	{ 0x397f6231, "ip_set_free" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x8520a781, "nla_put" },
	{ 0x800473f, "__cond_resched" },
	{ 0x9641c5c6, "ip_set_put_extensions" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x92997ed8, "_printk" },
	{ 0x51fa242b, "ip_set_put_flags" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xf3b4d4ae, "ip_set_alloc" },
	{ 0x8202224c, "ip_set_elem_len" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xd1c17ba8, "ip_set_match_extensions" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x5922420e, "ip_set_init_comment" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x5328c5ae, "ip_set_type_register" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x2276f00e, "ip_set_type_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_set");


MODULE_INFO(srcversion, "6281A14DCEF5F160DC37A99");
