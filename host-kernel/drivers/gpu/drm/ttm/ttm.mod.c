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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(ttm_tt_init, 0x7f4fc901, "");
SYMBOL_CRC(ttm_tt_fini, 0x3b91c516, "");
SYMBOL_CRC(ttm_sg_tt_init, 0x94c6f681, "");
SYMBOL_CRC(ttm_tt_populate, 0xa8e5b27d, "");
SYMBOL_CRC(ttm_kmap_iter_tt_init, 0xbb025aad, "");
SYMBOL_CRC(ttm_bo_move_to_lru_tail, 0x30f7d8d0, "");
SYMBOL_CRC(ttm_bo_set_bulk_move, 0x1fdb397e, "");
SYMBOL_CRC(ttm_bo_put, 0x504aff0f, "");
SYMBOL_CRC(ttm_bo_lock_delayed_workqueue, 0xff06df37, "");
SYMBOL_CRC(ttm_bo_unlock_delayed_workqueue, 0xdf6feb47, "");
SYMBOL_CRC(ttm_bo_eviction_valuable, 0x214e9884, "");
SYMBOL_CRC(ttm_bo_pin, 0x020ee561, "");
SYMBOL_CRC(ttm_bo_unpin, 0x270b039f, "");
SYMBOL_CRC(ttm_bo_mem_space, 0xa047c1fd, "");
SYMBOL_CRC(ttm_bo_validate, 0xcad20cf7, "");
SYMBOL_CRC(ttm_bo_init_reserved, 0x87bae58b, "");
SYMBOL_CRC(ttm_bo_init, 0xcc94d006, "");
SYMBOL_CRC(ttm_bo_unmap_virtual, 0x3045b44d, "");
SYMBOL_CRC(ttm_bo_wait, 0x2683bf95, "");
SYMBOL_CRC(ttm_move_memcpy, 0x1a71d30c, "");
SYMBOL_CRC(ttm_bo_move_memcpy, 0xcbcd095f, "");
SYMBOL_CRC(ttm_io_prot, 0xcf0c0f61, "");
SYMBOL_CRC(ttm_bo_kmap, 0xded32ea9, "");
SYMBOL_CRC(ttm_bo_kunmap, 0x8b59c4e8, "");
SYMBOL_CRC(ttm_bo_vmap, 0xe2ae3814, "");
SYMBOL_CRC(ttm_bo_vunmap, 0x1c83ef36, "");
SYMBOL_CRC(ttm_bo_move_accel_cleanup, 0xce214ed5, "");
SYMBOL_CRC(ttm_bo_move_sync_cleanup, 0x0213fc45, "");
SYMBOL_CRC(ttm_bo_vm_reserve, 0x0f881a8b, "");
SYMBOL_CRC(ttm_bo_vm_fault_reserved, 0xe5db3426, "");
SYMBOL_CRC(ttm_bo_vm_dummy_page, 0x5d2ee6d8, "");
SYMBOL_CRC(ttm_bo_vm_fault, 0x5c31c663, "");
SYMBOL_CRC(ttm_bo_vm_open, 0x5f947ff5, "");
SYMBOL_CRC(ttm_bo_vm_close, 0xa12673be, "");
SYMBOL_CRC(ttm_bo_vm_access, 0x48091b40, "");
SYMBOL_CRC(ttm_bo_mmap_obj, 0xb1f929e6, "");
SYMBOL_CRC(ttm_eu_backoff_reservation, 0x3d463af9, "");
SYMBOL_CRC(ttm_eu_reserve_buffers, 0x228fe49f, "");
SYMBOL_CRC(ttm_eu_fence_buffer_objects, 0xcf3cfbce, "");
SYMBOL_CRC(ttm_range_man_init_nocheck, 0xb2c7417f, "");
SYMBOL_CRC(ttm_range_man_fini_nocheck, 0x2522a243, "");
SYMBOL_CRC(ttm_lru_bulk_move_init, 0x8faef057, "");
SYMBOL_CRC(ttm_lru_bulk_move_tail, 0xbc835e6c, "");
SYMBOL_CRC(ttm_resource_init, 0xbf66365c, "");
SYMBOL_CRC(ttm_resource_fini, 0x3b5d3474, "");
SYMBOL_CRC(ttm_resource_free, 0x3277b8f2, "");
SYMBOL_CRC(ttm_resource_compat, 0x2a0ed2fa, "");
SYMBOL_CRC(ttm_resource_manager_init, 0x2b9bf108, "");
SYMBOL_CRC(ttm_resource_manager_evict_all, 0x70be8cc2, "");
SYMBOL_CRC(ttm_resource_manager_usage, 0xf7019105, "");
SYMBOL_CRC(ttm_resource_manager_debug, 0xc5048d22, "");
SYMBOL_CRC(ttm_kmap_iter_iomap_init, 0x5a7874e4, "");
SYMBOL_CRC(ttm_resource_manager_create_debugfs, 0xa012d2b1, "");
SYMBOL_CRC(ttm_pool_alloc, 0x0983b9cc, "");
SYMBOL_CRC(ttm_pool_free, 0xe09013ee, "");
SYMBOL_CRC(ttm_pool_debugfs, 0x16a53381, "");
SYMBOL_CRC(ttm_glob, 0x0bb3f494, "");
SYMBOL_CRC(ttm_global_swapout, 0x35d77bc8, "");
SYMBOL_CRC(ttm_device_swapout, 0xefc8d020, "");
SYMBOL_CRC(ttm_device_init, 0x98f6a292, "");
SYMBOL_CRC(ttm_device_fini, 0x3ef2485d, "");
SYMBOL_CRC(ttm_device_clear_dma_mappings, 0xb35e608e, "");
SYMBOL_CRC(ttm_agp_bind, 0xac48b9f5, "");
SYMBOL_CRC(ttm_agp_unbind, 0x0eb85853, "");
SYMBOL_CRC(ttm_agp_is_bound, 0xcd4dfb7d, "");
SYMBOL_CRC(ttm_agp_destroy, 0x5016cb0a, "");
SYMBOL_CRC(ttm_agp_tt_create, 0xf08ae40d, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8a35b432, "sme_me_mask" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x10795da2, "__put_page" },
	{ 0xcef6fc7a, "ww_mutex_lock_interruptible" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0xd0f9fa29, "dma_resv_reserve_fences" },
	{ 0x4b7ebf95, "drm_mm_remove_node" },
	{ 0xf824c7db, "__drm_printfn_debug" },
	{ 0xe16db2ce, "agp_bind_memory" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x53245c91, "dma_resv_init" },
	{ 0x9c35a889, "dma_resv_wait_timeout" },
	{ 0x57698a50, "drm_mm_takedown" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xb4032484, "drm_mm_insert_node_in_range" },
	{ 0x556422b3, "ioremap_cache" },
	{ 0x2e80b5ac, "ww_mutex_unlock" },
	{ 0xedc03953, "iounmap" },
	{ 0xff0ab6da, "debugfs_create_atomic_t" },
	{ 0xeee3ef31, "register_shrinker" },
	{ 0x79cc14e8, "unmap_mapping_range" },
	{ 0x2f2f1e5a, "dma_resv_add_fence" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xe8a0e334, "drm_vma_offset_add" },
	{ 0xfeb953b1, "__drm_printfn_seq_file" },
	{ 0x4d924f20, "memremap" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x98c039dc, "dma_fence_wait_timeout" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf7acb66, "drm_mm_print" },
	{ 0xc2bb8c22, "set_pages_wb" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x92997ed8, "_printk" },
	{ 0xf20b7eac, "ww_mutex_trylock" },
	{ 0x7e754496, "__drmm_add_action_or_reset" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x33b84f74, "copy_page" },
	{ 0x231b2691, "unregister_shrinker" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x23b4e0d7, "clear_page_rep" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xc32503b3, "mark_page_accessed" },
	{ 0xce286cf0, "shmem_file_setup" },
	{ 0x98378a1d, "cc_mkdec" },
	{ 0xd73c8c2b, "synchronize_shrinkers" },
	{ 0xd28f6a7f, "fput" },
	{ 0x838286d5, "agp_free_memory" },
	{ 0x731c4a9c, "dma_fence_signal" },
	{ 0xdec64e96, "dma_resv_fini" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x9e9fdd9d, "memunmap" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x925493f, "clear_page_orig" },
	{ 0x593b6030, "ww_mutex_lock" },
	{ 0x6dcda273, "shmem_read_mapping_page_gfp" },
	{ 0x9084b044, "clear_page_erms" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xed2a2b32, "vmap" },
	{ 0xde80cd09, "ioremap" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x86490580, "current_task" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x3186e5dd, "vmf_insert_pfn_prot" },
	{ 0xf0517d7a, "drm_mm_init" },
	{ 0x50d1f870, "pgprot_writecombine" },
	{ 0x7a6e3c44, "agp_allocate_memory" },
	{ 0x140c98db, "agp_unbind_memory" },
	{ 0x513072fe, "__drm_puts_seq_file" },
	{ 0x2e3a154f, "dma_resv_copy_fences" },
	{ 0xa57ddaa1, "set_page_dirty" },
	{ 0x6d606913, "pv_ops" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0xf2b11959, "seq_read" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xa38c4c94, "drm_memcpy_from_wc" },
	{ 0x8d9ca0e6, "dma_fence_enable_sw_signaling" },
	{ 0x823d28fd, "set_pages_array_wc" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x28779e52, "drm_printf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8fe0f200, "dma_resv_iter_next_unlocked" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x87b8798d, "sg_next" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xb4e20839, "dma_resv_iter_first_unlocked" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x391de184, "seq_puts" },
	{ 0xbb2b861a, "single_release" },
	{ 0x9833be65, "set_pages_array_uc" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xb91fc7c5, "dma_resv_test_signaled" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0xe123f3d9, "dma_fence_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcc328a5c, "reservation_ww_class" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xb82ba28c, "single_open" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x53b954a2, "up_read" },
	{ 0x4831da6e, "drm_vma_offset_remove" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm");


MODULE_INFO(srcversion, "3E84B96B4D8847B5F2BFFA0");
