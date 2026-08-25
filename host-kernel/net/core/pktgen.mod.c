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
	{ 0x167e7f9d, "__get_user_1" },
	{ 0xab6d5b3b, "hex_to_bin" },
	{ 0xb82ba28c, "single_open" },
	{ 0x391de184, "seq_puts" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x754d539c, "strlen" },
	{ 0x5a921311, "strncmp" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x425c1db9, "xfrm_state_lookup_byspi" },
	{ 0x3573c691, "xfrm_stateonly_find" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x618911fc, "numa_node" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x92997ed8, "_printk" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0xb55bbd45, "proc_remove" },
	{ 0x2bf33597, "proc_create_data" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x86490580, "current_task" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x1de23e95, "module_put" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x999e8297, "vfree" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x10795da2, "__put_page" },
	{ 0x37a0cba, "kfree" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x84aa95fc, "__put_task_struct" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xbe888b32, "skb_put" },
	{ 0xfb578fc5, "memset" },
	{ 0x8c3f1630, "__alloc_pages" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0x60eda3b5, "proc_create" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x142a899d, "kthread_bind" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xc6cbbc89, "capable" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x5f454dc5, "softnet_data" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x4cd99e34, "hrtimer_init_sleeper" },
	{ 0x5827b2a0, "hrtimer_sleeper_start_expires" },
	{ 0x1000e51, "schedule" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x2124474, "ip_send_check" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x7c25b1cd, "pktgen_xfrm_outer_mode_output" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0x8d6706dc, "netif_receive_skb" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0x2f10dc0c, "udp4_hwcsum" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xa6257a2f, "complete" },
	{ 0x9e61bb05, "set_freezable" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7ab88a45, "system_freezing_cnt" },
	{ 0xec507773, "freezing_slow_path" },
	{ 0x4482cdb, "__refrigerator" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0xa916b694, "strnlen" },
	{ 0x1b6314fd, "in_aton" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x9e0c711d, "vzalloc_node" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x41482d8b, "strndup_user" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0x652032cb, "mac_pton" },
	{ 0x609bcd98, "in6_pton" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x9493fc86, "node_states" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xf2b11959, "seq_read" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xbb2b861a, "single_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B36214BBFB75CFEBC4FE6A3");
