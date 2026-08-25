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
	{ 0x5d0bd002, "generic_fillattr" },
	{ 0xac9965ea, "clear_nlink" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0x83d070e8, "clear_inode" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4747dec3, "generic_file_splice_read" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x2796b2, "init_special_inode" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x7f4ed11, "task_active_pid_ns" },
	{ 0x881f764b, "d_make_root" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x46ed28d8, "fget" },
	{ 0x7f4d1ae1, "sync_filesystem" },
	{ 0x807a3d35, "d_splice_alias" },
	{ 0x87e815bc, "current_time" },
	{ 0x90576ec4, "vmemdup_user" },
	{ 0x69acdf38, "memcpy" },
	{ 0xddce9b72, "ihold" },
	{ 0xd08f3d14, "page_get_link" },
	{ 0x37a0cba, "kfree" },
	{ 0xbcd4b433, "iput" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xe9666fb2, "init_pid_ns" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x409f23d1, "path_put" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbb12069a, "shrink_dcache_parent" },
	{ 0x81b463c7, "d_prune_aliases" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa0a14f90, "d_drop" },
	{ 0x5eeb0c4d, "unlock_new_inode" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x441920fc, "vfs_iter_read" },
	{ 0xfb6af58d, "recalc_sigpending" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd691c6a9, "unregister_sysctl_table" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x2e95a259, "truncate_inode_pages_final" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x7d126ffe, "ilookup5" },
	{ 0xc9ff5b23, "__task_pid_nr_ns" },
	{ 0x43c5c4c1, "inode_nohighmem" },
	{ 0xd28f6a7f, "fput" },
	{ 0x57bc19d2, "down_write" },
	{ 0x8feb4ca3, "shrink_dcache_sb" },
	{ 0xce807a25, "up_write" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0x1f1f589c, "device_create" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x5a921311, "strncmp" },
	{ 0x7f78fd7e, "from_kgid" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x402830fd, "from_kuid" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x4838be6d, "vfs_iter_write" },
	{ 0x8d70148e, "kernel_read" },
	{ 0x47e04fe2, "__insert_inode_hash" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xe9d210b0, "mount_nodev" },
	{ 0x258cbc5d, "super_setup_bdi" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0x2bd37371, "vfs_fsync" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x20d9c475, "d_find_alias" },
	{ 0x3d8122aa, "inc_nlink" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x7f8f3ec6, "dput" },
	{ 0x8353fa86, "touch_atime" },
	{ 0x5fb705d5, "__percpu_down_read" },
	{ 0x33c57e62, "is_bad_inode" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x711f8854, "rcuwait_wake_up" },
	{ 0x82b7c307, "kill_anon_super" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0x990dce4e, "iget5_locked" },
	{ 0x41c5bdad, "filemap_write_and_wait_range" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x6206a904, "__remove_inode_hash" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xb99f272d, "user_path_at_empty" },
	{ 0x6a449c4f, "register_sysctl_table" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x53b954a2, "up_read" },
	{ 0xca415961, "drop_nlink" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "74E6BB9575F45D5EE7D0516");
