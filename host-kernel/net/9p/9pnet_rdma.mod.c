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
	{ 0x1430723c, "p9_req_put" },
	{ 0xa6257a2f, "complete" },
	{ 0x79dc9a81, "__ib_alloc_pd" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x578b8953, "rdma_resolve_addr" },
	{ 0xcf2a6966, "up" },
	{ 0x37a0cba, "kfree" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x244428fe, "rdma_disconnect" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfbc7a528, "__rdma_create_kernel_id" },
	{ 0xe39434a8, "rdma_resolve_route" },
	{ 0x4df0478c, "rdma_bind_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x920d6f4e, "rdma_create_qp" },
	{ 0x7c6024bd, "init_net" },
	{ 0xe648df3b, "__ib_alloc_cq_any" },
	{ 0x4e3567f7, "match_int" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x2499aa4f, "ib_destroy_qp_user" },
	{ 0xbd07c956, "p9_tag_lookup" },
	{ 0x442f8ad5, "rdma_connect" },
	{ 0xb79f25fd, "p9_parse_header" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1f3896d5, "ib_free_cq" },
	{ 0x6ef9fac8, "rdma_destroy_id" },
	{ 0x16cd7ad4, "v9fs_register_trans" },
	{ 0x44e9a829, "match_token" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0x391de184, "seq_puts" },
	{ 0x1b6314fd, "in_aton" },
	{ 0x259099b2, "ib_dealloc_pd_user" },
	{ 0xed1b5526, "v9fs_unregister_trans" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x28ac4d9b, "p9_client_cb" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x984c5e73, "p9_fcall_fini" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "9pnet,ib_core,rdma_cm");


MODULE_INFO(srcversion, "F945FCCEE053BBA7042BA5F");
