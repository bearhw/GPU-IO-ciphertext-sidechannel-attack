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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x754d539c, "strlen" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xcf62688d, "target_remove_session" },
	{ 0x37a0cba, "kfree" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x86490580, "current_task" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x590775d8, "core_tpg_deregister" },
	{ 0xa6257a2f, "complete" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xfbad3cf0, "scsi_normalize_sense" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x86623fd7, "notify_remote_via_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9db2f5e1, "target_execute_cmd" },
	{ 0x5a42c937, "sbitmap_queue_clear" },
	{ 0x5a207c8d, "transport_generic_free_cmd" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0x911c42d, "xenbus_unmap_ring_vfree" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xe73f8b67, "gnttab_unmap_refs" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x4b931968, "xen_features" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x10795da2, "__put_page" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xdbf086cf, "gnttab_page_cache_put" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x5a921311, "strncmp" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x3464c940, "core_tpg_register" },
	{ 0x1e6d26a8, "strstr" },
	{ 0xa916b694, "strnlen" },
	{ 0x3d4912de, "target_setup_session" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x17001b5e, "gnttab_map_refs" },
	{ 0x94e55f96, "gnttab_page_cache_get" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa100f5bc, "gnttab_page_cache_shrink" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x92c1db22, "gnttab_page_cache_init" },
	{ 0x6aa2a877, "xenbus_printf" },
	{ 0x24fec4ac, "xenbus_switch_state" },
	{ 0xf969b534, "xenbus_dev_error" },
	{ 0x4fe00144, "xenbus_dev_fatal" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xd20e5487, "target_submit_tmr" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x3288b93b, "__sbitmap_queue_get" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xf2c36958, "target_init_cmd" },
	{ 0xa695b5fc, "target_submit_prep" },
	{ 0x61fa78b, "target_submit" },
	{ 0x87b8798d, "sg_next" },
	{ 0xea5cbce, "xen_irq_lateeoi" },
	{ 0x4ed847b6, "target_put_sess_cmd" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9f984513, "strrchr" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6502d9c2, "xenbus_scanf" },
	{ 0xecd8f23d, "xenbus_read" },
	{ 0xce0a4020, "xenbus_directory" },
	{ 0x1cb9a1c8, "xenbus_gather" },
	{ 0xbceddac4, "xenbus_map_ring_valloc" },
	{ 0x16985b4f, "bind_interdomain_evtchn_to_irq_lateeoi" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x51b8ecf8, "xenbus_dev_is_online" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x74e12a8d, "__xenbus_register_backend" },
	{ 0xd2719129, "target_register_template" },
	{ 0x9ee2b870, "xenbus_unregister_driver" },
	{ 0x5085599b, "target_unregister_template" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "target_core_mod");


MODULE_INFO(srcversion, "F98FBFC528066E4CF159005");
