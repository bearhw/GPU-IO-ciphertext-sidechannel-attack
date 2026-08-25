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
	{ 0x2cebc3c, "__bio_release_pages" },
	{ 0xa0fa8103, "inode_init_owner" },
	{ 0x83aab84f, "iomap_readahead" },
	{ 0xba177c19, "setattr_prepare" },
	{ 0x44a21f8e, "vfs_fsync_range" },
	{ 0x5d92bb8e, "iomap_migrate_page" },
	{ 0xc6a174ea, "iocb_bio_iopoll" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0x788957f4, "blkdev_nr_zones" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0x1663b2e5, "filemap_map_pages" },
	{ 0xe8bddeca, "iomap_file_buffered_write" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x8d66bc39, "d_alloc_name" },
	{ 0x881f764b, "d_make_root" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xf03e6584, "sb_set_blocksize" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x8cb92043, "d_genocide" },
	{ 0xea4a64c2, "generic_error_remove_page" },
	{ 0x87e815bc, "current_time" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x483002c6, "inode_dio_wait" },
	{ 0x37a0cba, "kfree" },
	{ 0xbcd4b433, "iput" },
	{ 0xbe61631a, "iter_file_splice_write" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x388a5624, "register_filesystem" },
	{ 0xd57267c, "dquot_transfer" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0xfdabb08d, "bio_iov_iter_get_pages" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0xceaeafba, "iomap_invalidate_folio" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xdb61ac9a, "iomap_dio_rw" },
	{ 0x2e376f58, "iomap_writepage" },
	{ 0xe24c3ee2, "kill_block_super" },
	{ 0x92997ed8, "_printk" },
	{ 0xbb3021a7, "blkdev_zone_mgmt" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x95b79998, "fs_kobj" },
	{ 0x2af8a570, "simple_dir_operations" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xc82b6cf0, "iomap_page_mkwrite" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0xb8cb7ba2, "file_write_and_wait_range" },
	{ 0x800473f, "__cond_resched" },
	{ 0xa09dd780, "bio_put" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xd8d474c1, "generic_file_read_iter" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x79309710, "setattr_copy" },
	{ 0x69dd3b5b, "crc32_le" },
	{ 0xad72f7d2, "file_update_time" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x32455a6b, "iomap_swapfile_activate" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xc392bf7, "kobject_init_and_add" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xc005bb87, "bio_init" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xe40c37ea, "down_write_trylock" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x668b19a1, "down_read" },
	{ 0x11295008, "truncate_setsize" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0xe50b494a, "iomap_read_folio" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xeea75081, "noop_direct_IO" },
	{ 0x6b980b08, "kobject_del" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xf77feee, "d_add" },
	{ 0x85df9b6c, "strsep" },
	{ 0x1618a3b1, "mount_bdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x1681cdc1, "iomap_writepages" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x3d8122aa, "inc_nlink" },
	{ 0x44e9a829, "match_token" },
	{ 0x7f8f3ec6, "dput" },
	{ 0x8353fa86, "touch_atime" },
	{ 0x2211a4c0, "blk_op_str" },
	{ 0x5fb705d5, "__percpu_down_read" },
	{ 0x667cf055, "simple_lookup" },
	{ 0xafc325c9, "generic_file_open" },
	{ 0xfbe0e228, "filemap_dirty_folio" },
	{ 0x6b9f01cd, "blkdev_issue_flush" },
	{ 0x391de184, "seq_puts" },
	{ 0x711f8854, "rcuwait_wake_up" },
	{ 0xe71c4fef, "send_sig" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x3d801700, "generic_file_llseek_size" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0x1829ff26, "filemap_fault" },
	{ 0xff80dd9c, "iomap_release_folio" },
	{ 0xecb05983, "iomap_is_partially_uptodate" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x53b954a2, "up_read" },
	{ 0x2f7faaac, "iov_iter_npages" },
	{ 0xbf529047, "submit_bio_wait" },
	{ 0x264fc44e, "blkdev_report_zones" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x7c181721, "kobject_put" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "53EE9AF6CE23834DCA357AA");
