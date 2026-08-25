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
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1ee4784d, "ib_unregister_client" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x2318e9ae, "rdma_reject_msg" },
	{ 0x22f14e5a, "rdma_rw_ctx_destroy" },
	{ 0x907df803, "rdma_event_msg" },
	{ 0xafc3f02f, "rdma_rw_mr_factor" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x79dc9a81, "__ib_alloc_pd" },
	{ 0x78074d80, "nvmet_req_complete" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0x55866301, "nvmet_req_free_sgls" },
	{ 0x37a0cba, "kfree" },
	{ 0x9522d335, "rdma_rw_ctx_post" },
	{ 0xf6ed3334, "ib_event_msg" },
	{ 0x16cbd24, "rdma_reject" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x244428fe, "rdma_disconnect" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x8fad0d89, "ib_destroy_srq_user" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x35c7353, "nvmet_sq_destroy" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfbc7a528, "__rdma_create_kernel_id" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xa22509d8, "rdma_rw_ctx_destroy_signature" },
	{ 0x6508aecd, "nvmet_unregister_transport" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x4df0478c, "rdma_bind_addr" },
	{ 0x9207cc50, "ib_register_client" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x92cc0704, "nvmet_req_init" },
	{ 0x920d6f4e, "rdma_create_qp" },
	{ 0x86f3b3, "ib_create_srq_user" },
	{ 0xb971681c, "rdma_rw_ctx_wrs" },
	{ 0x7c6024bd, "init_net" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x99274299, "ib_cq_pool_put" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2e47c67f, "nvmet_register_transport" },
	{ 0xee218ed3, "rdma_notify" },
	{ 0xc8f8cd24, "rdma_set_afonly" },
	{ 0xffb7c514, "ida_free" },
	{ 0x8d6713c, "inet_pton_with_scope" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x24a5a427, "rdma_listen" },
	{ 0xe590a1df, "rdma_destroy_qp" },
	{ 0xaf38448e, "ib_check_mr_status" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x2499aa4f, "ib_destroy_qp_user" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0xaa4e6414, "rdma_rw_ctx_signature_init" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x61ebd57d, "ib_cq_pool_get" },
	{ 0x6d606913, "pv_ops" },
	{ 0xe5840ec6, "ib_wc_status_msg" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xbdcfbf20, "nvmet_req_alloc_sgls" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x825b201, "param_set_int" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x6ef9fac8, "rdma_destroy_id" },
	{ 0x3214b0a8, "nvmet_sq_init" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0x3e019d42, "rdma_accept" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xf5c084e2, "ib_drain_qp" },
	{ 0x5663ba06, "nvmet_ctrl_fatal_error" },
	{ 0x259099b2, "ib_dealloc_pd_user" },
	{ 0x8ee4e8a, "nvmet_req_uninit" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x47c333ea, "param_get_int" },
	{ 0xe613a798, "inet_addr_is_any" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x3e0ef07a, "nvmet_wq" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xb8f644cd, "rdma_rw_ctx_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ib_core,rdma_cm,nvmet");


MODULE_INFO(srcversion, "030DEEA85456A85BB3759EA");
