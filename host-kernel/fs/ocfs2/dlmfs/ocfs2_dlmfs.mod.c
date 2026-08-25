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
	{ 0xa0fa8103, "inode_init_owner" },
	{ 0xba177c19, "setattr_prepare" },
	{ 0x90a2441f, "simple_rmdir" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x8a25d3e4, "d_instantiate" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x83d070e8, "clear_inode" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x29d1b6da, "new_inode" },
	{ 0xcfd3fc5, "ocfs2_cluster_connect_agnostic" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x460cabd0, "simple_statfs" },
	{ 0x881f764b, "d_make_root" },
	{ 0xcafdd707, "ocfs2_dlm_lock_status" },
	{ 0x87e815bc, "current_time" },
	{ 0x37a0cba, "kfree" },
	{ 0xbcd4b433, "iput" },
	{ 0xe953b21f, "get_next_ino" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0x2af8a570, "simple_dir_operations" },
	{ 0x9b262413, "simple_unlink" },
	{ 0xd344e4ee, "ocfs2_stack_glue_set_max_proto_version" },
	{ 0x6a0c3847, "__mlog_printk" },
	{ 0x79079915, "simple_getattr" },
	{ 0xa9f756cd, "inode_init_once" },
	{ 0x800473f, "__cond_resched" },
	{ 0xaf969565, "ocfs2_dlm_lock" },
	{ 0x1475f64b, "ocfs2_dlm_lvb_valid" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xc5196999, "ocfs2_dlm_unlock" },
	{ 0x79309710, "setattr_copy" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x86490580, "current_task" },
	{ 0x23af578f, "default_llseek" },
	{ 0x1f7a9338, "kill_litter_super" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6d606913, "pv_ops" },
	{ 0xe9d210b0, "mount_nodev" },
	{ 0x551e5727, "igrab" },
	{ 0x76f40744, "ocfs2_dlm_lvb" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x3d8122aa, "inc_nlink" },
	{ 0xd9b85ef6, "lockref_get" },
	{ 0x4462fd8a, "generic_delete_inode" },
	{ 0x667cf055, "simple_lookup" },
	{ 0x9507547f, "ocfs2_cluster_disconnect" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xe7566868, "kmem_cache_alloc_lru" },
	{ 0xb801a7cb, "__mark_inode_dirty" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ocfs2_stackglue,ocfs2_nodemanager");


MODULE_INFO(srcversion, "B6ED8B02BD7CA0D727786D2");
