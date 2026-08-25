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
	{ 0x944375db, "_totalram_pages" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x4c75845f, "bpf_trace_run6" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x785a93b4, "si_mem_available" },
	{ 0x26520970, "vm_memory_committed" },
	{ 0x2fd90375, "vmbus_sendpacket" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xa8b0b7d3, "adjust_managed_page_count" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xa3afc2c1, "vmbus_close" },
	{ 0x3478065a, "generic_online_page" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x92997ed8, "_printk" },
	{ 0xa2f7487f, "hv_is_hibernation_supported" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x722009f5, "set_online_page_callback" },
	{ 0xa770832, "register_memory_notifier" },
	{ 0x77f9ae61, "vmbus_open" },
	{ 0x26e298e0, "unregister_memory_notifier" },
	{ 0xeaa89d52, "restore_online_page_callback" },
	{ 0xa52c511, "hv_query_ext_cap" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x764ffefa, "page_reporting_register" },
	{ 0x99dd730c, "page_reporting_unregister" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0xc2f5bb2f, "split_page" },
	{ 0xf9a482f9, "msleep" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c0e8050, "hyperv_pcpu_input_arg" },
	{ 0x87b8798d, "sg_next" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0xc4ae915e, "arch_touch_nmi_watchdog" },
	{ 0x6fcb87a1, "touch_softlockup_watchdog" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x9bad141d, "hv_hypercall_pg" },
	{ 0xa6257a2f, "complete" },
	{ 0x638a9653, "memory_add_physaddr_to_nid" },
	{ 0xbd7aaaee, "add_memory" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xa94a09bb, "mem_section" },
	{ 0x37a0cba, "kfree" },
	{ 0xd64660db, "vmbus_recvpacket" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8f4947c8, "__vmbus_driver_register" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hv_vmbus");

MODULE_ALIAS("vmbus:dc7450528589e2468057a307dc18a502");

MODULE_INFO(srcversion, "99977894CDB70F8A68A5925");
