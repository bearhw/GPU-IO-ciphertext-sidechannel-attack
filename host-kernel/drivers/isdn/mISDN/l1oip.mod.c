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
	{ 0x1a8bd555, "try_module_get" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb6e0a005, "mISDN_freedchannel" },
	{ 0xbd505649, "consume_skb" },
	{ 0xd5a938fc, "mISDN_initdchannel" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xd72a9f53, "sock_create" },
	{ 0xc5339c64, "mISDN_register_device" },
	{ 0x222d708e, "mISDN_freebchannel" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9ce1309f, "mISDN_initbchannel" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x24d273d1, "add_timer" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xd822b137, "mISDN_unregister_device" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0x86490580, "current_task" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x999e8297, "vfree" },
	{ 0xbb3fc6f8, "recv_Dchannel" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x66b5d182, "sock_recvmsg" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x86f76de7, "queue_ch_frame" },
	{ 0xe71c4fef, "send_sig" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core");


MODULE_INFO(srcversion, "0D84E84043D0E8A70747B94");
