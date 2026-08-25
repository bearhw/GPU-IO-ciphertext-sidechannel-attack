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

SYMBOL_CRC(drm_sched_dependency_optimized, 0xc81ac9fd, "");
SYMBOL_CRC(drm_sched_fault, 0x2557cec4, "");
SYMBOL_CRC(drm_sched_suspend_timeout, 0x19188f3f, "");
SYMBOL_CRC(drm_sched_resume_timeout, 0xb242014e, "");
SYMBOL_CRC(drm_sched_increase_karma, 0x714758a6, "");
SYMBOL_CRC(drm_sched_reset_karma, 0x12dff28a, "");
SYMBOL_CRC(drm_sched_stop, 0x34d85f84, "");
SYMBOL_CRC(drm_sched_start, 0x6aa20a82, "");
SYMBOL_CRC(drm_sched_resubmit_jobs, 0x37b00400, "");
SYMBOL_CRC(drm_sched_resubmit_jobs_ext, 0xcb1ad332, "");
SYMBOL_CRC(drm_sched_job_init, 0x2d6931b8, "");
SYMBOL_CRC(drm_sched_job_arm, 0x4daa750d, "");
SYMBOL_CRC(drm_sched_job_add_dependency, 0xb0829da9, "");
SYMBOL_CRC(drm_sched_job_add_implicit_dependencies, 0x6c4f1f98, "");
SYMBOL_CRC(drm_sched_job_cleanup, 0x2ceb7f28, "");
SYMBOL_CRC(drm_sched_pick_best, 0x6472c126, "");
SYMBOL_CRC(drm_sched_init, 0x3ab83a50, "");
SYMBOL_CRC(drm_sched_fini, 0x946f4172, "");
SYMBOL_CRC(drm_sched_increase_karma_ext, 0xe4d6af35, "");
SYMBOL_CRC(to_drm_sched_fence, 0xde913a0e, "");
SYMBOL_CRC(drm_sched_entity_init, 0xd5ae4903, "");
SYMBOL_CRC(drm_sched_entity_modify_sched, 0x1ad236c2, "");
SYMBOL_CRC(drm_sched_entity_flush, 0xb11364ca, "");
SYMBOL_CRC(drm_sched_entity_fini, 0xc12d7c13, "");
SYMBOL_CRC(drm_sched_entity_destroy, 0x3cc58122, "");
SYMBOL_CRC(drm_sched_entity_set_priority, 0xe69b5422, "");
SYMBOL_CRC(drm_sched_entity_push_job, 0x87587652, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe914e41e, "strcpy" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0xa6257a2f, "complete" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x4b6c991a, "irq_work_queue" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xf95322f4, "kthread_parkme" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x8e21c9a1, "dma_fence_add_callback" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x781b12e8, "kthread_park" },
	{ 0xe5084537, "sched_set_fifo_low" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x79defbe1, "kthread_should_park" },
	{ 0x98c039dc, "dma_fence_wait_timeout" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x896ca658, "dma_resv_iter_next" },
	{ 0x3b20fb95, "dma_fence_remove_callback" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xe43186d1, "drm_dev_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x132f2fb1, "kthread_unpark" },
	{ 0x800473f, "__cond_resched" },
	{ 0x9114b616, "__xa_alloc" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x14605535, "dma_fence_context_alloc" },
	{ 0x731c4a9c, "dma_fence_signal" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x16dee44d, "dma_fence_init" },
	{ 0x86490580, "current_task" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x745a981, "xa_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xd9491c14, "xa_destroy" },
	{ 0x8fa25c24, "xa_find" },
	{ 0x5b3e282f, "xa_store" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x97820a51, "dma_resv_iter_first" },
	{ 0xdf36914b, "xa_find_after" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xe123f3d9, "dma_fence_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm");


MODULE_INFO(srcversion, "95E17C3EE4F8C2568550F01");
