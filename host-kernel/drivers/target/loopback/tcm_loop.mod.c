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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x5a921311, "strncmp" },
	{ 0x8c5933d7, "core_allocate_nexus_loss_ua" },
	{ 0xcf62688d, "target_remove_session" },
	{ 0x37a0cba, "kfree" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x69ab51db, "scsi_device_lookup" },
	{ 0xb363452c, "scsi_remove_device" },
	{ 0x12e047bb, "scsi_device_put" },
	{ 0x4e6c5045, "scsi_add_device" },
	{ 0x590775d8, "core_tpg_deregister" },
	{ 0x3464c940, "core_tpg_register" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xb27eb5df, "scsi_remove_host" },
	{ 0x6ec3e817, "scsi_host_put" },
	{ 0x391de184, "seq_puts" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xd20e5487, "target_submit_tmr" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x4ed847b6, "target_put_sess_cmd" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x9d05c15c, "scsi_done" },
	{ 0xe2cad31b, "scsi_host_alloc" },
	{ 0x816fc9e7, "scsi_add_host_with_dma" },
	{ 0xa6257a2f, "complete" },
	{ 0x9db2f5e1, "target_execute_cmd" },
	{ 0x5a207c8d, "transport_generic_free_cmd" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x1c6dbfe, "root_device_unregister" },
	{ 0xf2c36958, "target_init_cmd" },
	{ 0xa695b5fc, "target_submit_prep" },
	{ 0x497f6a4d, "target_queue_submission" },
	{ 0xbe158d83, "scmd_printk" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x754d539c, "strlen" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x422066d2, "device_register" },
	{ 0xa916b694, "strnlen" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x3d4912de, "target_setup_session" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x27352a9d, "__root_device_register" },
	{ 0xc487b792, "bus_register" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xd2719129, "target_register_template" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x5085599b, "target_unregister_template" },
	{ 0x17cef504, "scsi_change_queue_depth" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "target_core_mod");


MODULE_INFO(srcversion, "C75FD9D7A6F7FBCE1C814A0");
