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

SYMBOL_CRC(xen_privcmd_fops, 0xf30577ef, "_gpl");
SYMBOL_CRC(xen_privcmdbuf_fops, 0x6c081e04, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0x1a6702cf, "xen_xlate_remap_gfn_array" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xd8cef6e1, "clear_user" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xe1eb907a, "unpin_user_pages_dirty_lock" },
	{ 0xb285b8f8, "xen_in_preemptible_hcall" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x87706d4e, "__put_user_nocheck_8" },
	{ 0x4940ba3b, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x37a0cba, "kfree" },
	{ 0x704ea0a4, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x6d334118, "__get_user_8" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xfd98a590, "find_vma" },
	{ 0xd4b4b56f, "xen_free_unpopulated_pages" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x162b6f97, "xen_remap_vma_range" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4f537213, "apply_to_page_range" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x2b886214, "xen_unmap_domain_gfn_range" },
	{ 0x4708008a, "misc_register" },
	{ 0x24f14039, "__mmap_lock_do_trace_start_locking" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xba47624e, "xen_remap_pfn" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x1f9907f7, "__tracepoint_mmap_lock_start_locking" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0x8d6aff89, "__put_user_nocheck_4" },
	{ 0x4b931968, "xen_features" },
	{ 0xbfb8b1ce, "xen_alloc_unpopulated_pages" },
	{ 0xbda2916c, "vm_map_pages_zero" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x45d14bdf, "hypercall_page" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9ABE07D354E36C70BDFE5D0");
