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

SYMBOL_CRC(__vmbus_driver_register, 0x8f4947c8, "_gpl");
SYMBOL_CRC(vmbus_driver_unregister, 0xcaff6dc5, "_gpl");
SYMBOL_CRC(vmbus_allocate_mmio, 0xc9a35505, "_gpl");
SYMBOL_CRC(vmbus_free_mmio, 0x31e2e77f, "_gpl");
SYMBOL_CRC(vmbus_connection, 0x2339f1b1, "_gpl");
SYMBOL_CRC(vmbus_proto_version, 0x46a417ca, "_gpl");
SYMBOL_CRC(vmbus_set_event, 0x974aef0d, "_gpl");
SYMBOL_CRC(vmbus_setevent, 0x42fe3e3b, "_gpl");
SYMBOL_CRC(vmbus_free_ring, 0xd4761b7e, "_gpl");
SYMBOL_CRC(vmbus_alloc_ring, 0xf56ae69b, "_gpl");
SYMBOL_CRC(vmbus_send_tl_connect_request, 0x4b2210b8, "_gpl");
SYMBOL_CRC(vmbus_send_modifychannel, 0x953f44ab, "_gpl");
SYMBOL_CRC(vmbus_establish_gpadl, 0xd8715d23, "_gpl");
SYMBOL_CRC(vmbus_connect_ring, 0xfff6cecc, "_gpl");
SYMBOL_CRC(vmbus_open, 0x77f9ae61, "_gpl");
SYMBOL_CRC(vmbus_teardown_gpadl, 0x1c5df67f, "_gpl");
SYMBOL_CRC(vmbus_disconnect_ring, 0xdf064b28, "_gpl");
SYMBOL_CRC(vmbus_close, 0xa3afc2c1, "_gpl");
SYMBOL_CRC(vmbus_sendpacket_getid, 0xa205065c, "");
SYMBOL_CRC(vmbus_sendpacket, 0x2fd90375, "");
SYMBOL_CRC(vmbus_sendpacket_pagebuffer, 0x4b38b344, "_gpl");
SYMBOL_CRC(vmbus_sendpacket_mpb_desc, 0x28c42fa9, "_gpl");
SYMBOL_CRC(vmbus_recvpacket, 0xd64660db, "");
SYMBOL_CRC(vmbus_recvpacket_raw, 0x261ce3f8, "_gpl");
SYMBOL_CRC(vmbus_next_request_id, 0xeff80c3f, "_gpl");
SYMBOL_CRC(__vmbus_request_addr_match, 0xb78c6323, "_gpl");
SYMBOL_CRC(vmbus_request_addr_match, 0x95559393, "_gpl");
SYMBOL_CRC(vmbus_request_addr, 0x938f9a6e, "_gpl");
SYMBOL_CRC(vmbus_prep_negotiate_resp, 0x321055cb, "_gpl");
SYMBOL_CRC(vmbus_hvsock_device_unregister, 0x008d0809, "_gpl");
SYMBOL_CRC(vmbus_set_sc_create_callback, 0x99e4fa6b, "_gpl");
SYMBOL_CRC(vmbus_set_chn_rescind_callback, 0x79510029, "_gpl");
SYMBOL_CRC(hv_ringbuffer_get_debuginfo, 0x674e657e, "_gpl");
SYMBOL_CRC(hv_pkt_iter_first, 0x530b2628, "_gpl");
SYMBOL_CRC(__hv_pkt_iter_next, 0xd048f90f, "_gpl");
SYMBOL_CRC(hv_pkt_iter_close, 0xbd88cc07, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8a35b432, "sme_me_mask" },
	{ 0x211130c1, "alloc_cpumask_var" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xd5f3bb7b, "set_memory_encrypted" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xddf6ad7a, "completion_done" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xbdb2217d, "hv_is_isolation_supported" },
	{ 0xb6261484, "register_die_notifier" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x31128b8e, "hv_remove_kexec_handler" },
	{ 0xae9852a0, "housekeeping_cpumask" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x8cafebc5, "driver_attach" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x96848186, "scnprintf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x7aff77a3, "__cpu_present_mask" },
	{ 0xa2f7487f, "hv_is_hibernation_supported" },
	{ 0x480305ca, "kmsg_dump_rewind" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfa1eb910, "unregister_syscore_ops" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0xda0947de, "kmsg_dump_unregister" },
	{ 0x3f7b09fb, "kset_unregister" },
	{ 0x39b52d19, "__bitmap_and" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x16dfbf36, "add_interrupt_randomness" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x18fb2caf, "cpus_read_unlock" },
	{ 0xa40a8382, "get_device" },
	{ 0x9bad141d, "hv_hypercall_pg" },
	{ 0x4d924f20, "memremap" },
	{ 0xc3876c1a, "hv_isolation_type_snp" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0xb75041d1, "hv_stimer_legacy_init" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xee518148, "kmsg_dump_get_buffer" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x8df9dd10, "guid_null" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7ceeac9, "panic_notifier_list" },
	{ 0x92997ed8, "_printk" },
	{ 0xb87ae6a4, "hv_ghcb_msr_write" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xc8827b75, "sysctl_vals" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2b9997fb, "atomic_notifier_chain_register" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xd691c6a9, "unregister_sysctl_table" },
	{ 0x3197c4e3, "put_device" },
	{ 0x2e7a17d4, "vmap_pfn" },
	{ 0x37b8b39e, "screen_info" },
	{ 0x618911fc, "numa_node" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x20899467, "hv_stimer0_isr" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xc9f1828e, "device_get_dma_attr" },
	{ 0x74dbf6d5, "driver_set_override" },
	{ 0xa04f945a, "cpus_read_lock" },
	{ 0x121d958a, "unregister_die_notifier" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x1f1821ae, "efi" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0x5c0eaf31, "acpi_dev_resource_interrupt" },
	{ 0xd8027d3, "hv_setup_dma_ops" },
	{ 0x7bb045a7, "__request_percpu_irq" },
	{ 0xc25b8971, "hv_remove_crash_handler" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0x65704d22, "hv_stimer_cleanup" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9e9fdd9d, "memunmap" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xed2a2b32, "vmap" },
	{ 0xc392bf7, "kobject_init_and_add" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xa965ca81, "reciprocal_value" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x7d0e1d95, "hv_setup_crash_handler" },
	{ 0x422066d2, "device_register" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xba01ec83, "hv_stimer_global_cleanup" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0x8b89f01c, "hv_ghcb_hypercall" },
	{ 0x8c3f1630, "__alloc_pages" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xb9c425de, "register_syscore_ops" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xbc6bec66, "free_percpu_irq" },
	{ 0x6b0eaa18, "hv_ghcb_msr_read" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xab1e0e93, "hv_setup_kexec_handler" },
	{ 0xf6fc8791, "__bitmap_xor" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x7181db30, "atomic_notifier_chain_unregister" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xc683da81, "set_memory_decrypted" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcb8a461c, "hv_stimer_legacy_cleanup" },
	{ 0x335c570f, "enable_percpu_irq" },
	{ 0x3fae6ab0, "hv_vp_index" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0xb89b6e6b, "guid_parse" },
	{ 0x90a9d8cc, "hv_is_hyperv_initialized" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x4c8adfe1, "hv_root_partition" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x59f8b7c6, "ms_hyperv" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0x7bbccd05, "nr_node_ids" },
	{ 0x3af578f5, "hyperv_report_panic" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xa96e8b4e, "hv_setup_vmbus_handler" },
	{ 0xebb550b2, "set_primary_fwnode" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77358855, "iomem_resource" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0x6c5ad0cd, "kmsg_dump_register" },
	{ 0x6a449c4f, "register_sysctl_table" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0x45d246da, "node_to_cpumask_map" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x85bd1608, "__request_region" },
	{ 0xf21e1f9b, "disable_percpu_irq" },
	{ 0x6be3a96b, "hv_remove_vmbus_handler" },
	{ 0xc487b792, "bus_register" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0x7233a2e6, "kset_create_and_add" },
	{ 0x71dfc095, "acpi_walk_resources" },
	{ 0x7c181721, "kobject_put" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:VMBUS:*");
MODULE_ALIAS("acpi*:VMBus:*");

MODULE_INFO(srcversion, "728F6538E8CA95C8F782DDB");
