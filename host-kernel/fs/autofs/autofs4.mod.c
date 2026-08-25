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
	{ 0xe914e41e, "strcpy" },
	{ 0xac9965ea, "clear_nlink" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x83d070e8, "clear_inode" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xf1129c56, "follow_down_one" },
	{ 0x29d1b6da, "new_inode" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x460cabd0, "simple_statfs" },
	{ 0xf62aa54d, "__kernel_write" },
	{ 0x881f764b, "d_make_root" },
	{ 0x46ed28d8, "fget" },
	{ 0xbd8bbd97, "fd_install" },
	{ 0x87e815bc, "current_time" },
	{ 0x69acdf38, "memcpy" },
	{ 0x637bb11c, "follow_up" },
	{ 0x37a0cba, "kfree" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x3baffd06, "dcache_dir_close" },
	{ 0xe953b21f, "get_next_ino" },
	{ 0x6a2f7542, "dcache_dir_open" },
	{ 0x81b038dd, "find_get_pid" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xe9666fb2, "init_pid_ns" },
	{ 0x6595b85b, "d_lookup" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x388a5624, "register_filesystem" },
	{ 0xdefd51b3, "dcache_readdir" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x60caa98a, "simple_empty" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x409f23d1, "path_put" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0x3455e9fa, "may_umount_tree" },
	{ 0xa0a14f90, "d_drop" },
	{ 0x92997ed8, "_printk" },
	{ 0xfb6af58d, "recalc_sigpending" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xc6cbbc89, "capable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4f7a696f, "path_has_submounts" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc9ff5b23, "__task_pid_nr_ns" },
	{ 0xb6fde909, "close_fd" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xd28f6a7f, "fput" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x4e3567f7, "match_int" },
	{ 0xa07a37f0, "memchr" },
	{ 0x1ae11974, "dentry_path_raw" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xf93eb9c0, "set_nlink" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1f7a9338, "kill_litter_super" },
	{ 0x106bdb90, "kern_path" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x4708008a, "misc_register" },
	{ 0x98dc5726, "dcache_dir_lseek" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x728727b4, "may_umount" },
	{ 0x7b2f421, "path_get" },
	{ 0xe9d210b0, "mount_nodev" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x77be7425, "generic_read_dir" },
	{ 0xf77feee, "d_add" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0xf25bbf52, "dentry_open" },
	{ 0x3d8122aa, "inc_nlink" },
	{ 0x44e9a829, "match_token" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x7f8f3ec6, "dput" },
	{ 0xd9b85ef6, "lockref_get" },
	{ 0x391de184, "seq_puts" },
	{ 0x12d2c8c8, "pid_vnr" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x48bb0f0f, "path_is_mountpoint" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x754d539c, "strlen" },
	{ 0x5fd62d78, "get_task_pid" },
	{ 0x349cba85, "strchr" },
	{ 0x2d8ca4a3, "put_pid" },
	{ 0xca415961, "drop_nlink" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F50F226713E458265DE82A5");
