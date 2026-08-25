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
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xf62c7092, "ip_sock_set_tos" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x78074d80, "nvmet_req_complete" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xbd9acb3b, "kernel_bind" },
	{ 0xd72a9f53, "sock_create" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xf4206108, "kernel_accept" },
	{ 0xbbd13bd3, "kernel_recvmsg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x52155e60, "sock_set_priority" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x35c7353, "nvmet_sq_destroy" },
	{ 0x92997ed8, "_printk" },
	{ 0x88e1d0f0, "page_frag_free" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3a13f54a, "sgl_alloc" },
	{ 0x91ba0c4b, "kernel_sendpage" },
	{ 0x6508aecd, "nvmet_unregister_transport" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x2de125c0, "page_frag_alloc_align" },
	{ 0x92cc0704, "nvmet_req_init" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x7c6024bd, "init_net" },
	{ 0x61e01a92, "kernel_getpeername" },
	{ 0x26ad0377, "kernel_getsockname" },
	{ 0xf1969a8e, "__usecs_to_jiffies" },
	{ 0xf43e05f3, "kernel_sock_shutdown" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2e47c67f, "nvmet_register_transport" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0xffb7c514, "ida_free" },
	{ 0x8d6713c, "inet_pton_with_scope" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xd319981b, "tcp_stream_memory_free" },
	{ 0x71afa9ed, "sock_set_reuseaddr" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x347da517, "crypto_ahash_digest" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x7e81267f, "__page_frag_cache_drain" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xcd89d757, "kernel_listen" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3214b0a8, "nvmet_sq_init" },
	{ 0x87b8798d, "sg_next" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x66b5d182, "sock_recvmsg" },
	{ 0x6e5c0971, "sock_release" },
	{ 0xb2340e65, "tcp_sock_set_nodelay" },
	{ 0x5663ba06, "nvmet_ctrl_fatal_error" },
	{ 0x8ee4e8a, "nvmet_req_uninit" },
	{ 0xc7a1840e, "llist_add_batch" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xe613a798, "inet_addr_is_any" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0x840342c6, "sgl_free" },
	{ 0x3e0ef07a, "nvmet_wq" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xb916ab62, "sock_no_linger" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nvmet");


MODULE_INFO(srcversion, "5C581DCF179430252DE477E");
