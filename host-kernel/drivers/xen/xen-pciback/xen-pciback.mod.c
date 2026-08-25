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
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1cb9a1c8, "xenbus_gather" },
	{ 0xa9cec9e6, "bus_unregister_notifier" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7bdff18e, "driver_remove_file" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x4fe00144, "xenbus_dev_fatal" },
	{ 0xc6572a90, "xenbus_read_unsigned" },
	{ 0x96848186, "scnprintf" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x20d8d10f, "pci_disable_msi" },
	{ 0x37a0cba, "kfree" },
	{ 0xb2b904aa, "pci_clear_mwi" },
	{ 0x6aa2a877, "xenbus_printf" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0x24fec4ac, "xenbus_switch_state" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x54bf0e65, "pci_intx" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xdf82259a, "pci_enable_msix_range" },
	{ 0xf19f134f, "driver_create_file" },
	{ 0x9bca0eb0, "xen_unregister_device_domain_owner" },
	{ 0x3318cdf8, "bus_register_notifier" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd72feba2, "xenbus_read_driver_state" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3248d20, "pci_set_mwi" },
	{ 0x800473f, "__cond_resched" },
	{ 0x82d4f86b, "pci_find_capability" },
	{ 0xa452f2a4, "xen_pirq_from_irq" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0x7dea3485, "__pci_reset_function_locked" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce807a25, "up_write" },
	{ 0x750122e9, "pci_load_saved_state" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x54ea6dfe, "xen_start_flags" },
	{ 0x732852fe, "xenbus_transaction_end" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x343f9361, "xen_find_device_domain_owner" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x9918881c, "xen_register_device_domain_owner" },
	{ 0xea5cbce, "xen_irq_lateeoi" },
	{ 0x9ee2b870, "xenbus_unregister_driver" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xcb51b6b3, "bind_interdomain_evtchn_to_irqhandler_lateeoi" },
	{ 0x74e12a8d, "__xenbus_register_backend" },
	{ 0xae0ebf2f, "pci_store_saved_state" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x84eef1ef, "xenbus_watch_path" },
	{ 0x86623fd7, "notify_remote_via_irq" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x911c42d, "xenbus_unmap_ring_vfree" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6502d9c2, "xenbus_scanf" },
	{ 0x52431348, "xenbus_transaction_start" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xa6b3c164, "pci_dev_get" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4cdaa56b, "pci_load_and_free_saved_state" },
	{ 0xa5f5614b, "pci_disable_msix" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x51b8ecf8, "xenbus_dev_is_online" },
	{ 0x870e16b7, "xen_test_irq_shared" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x31795ba9, "device_release_driver" },
	{ 0x754d539c, "strlen" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xbceddac4, "xenbus_map_ring_valloc" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x5cab9945, "unregister_xenbus_watch" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x791a408b, "pci_bus_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x45d14bdf, "hypercall_page" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F8ECC75B891E6035443C4B2");
