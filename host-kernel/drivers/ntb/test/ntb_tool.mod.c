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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x47cfd825, "kstrtouint_from_user" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x96848186, "scnprintf" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x37a0cba, "kfree" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xbb4f4766, "simple_write_to_buffer" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7d74d522, "kstrtoull_from_user" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xa0f4e4b8, "ntb_default_port_number" },
	{ 0x248efd3, "kstrtobool_from_user" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x58e4bd20, "ntb_default_peer_port_number" },
	{ 0xedc03953, "iounmap" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x88455b22, "ntb_set_ctx" },
	{ 0x7cc2e6ed, "ntb_default_peer_port_count" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xaedc404e, "ntb_clear_ctx" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0x3dc25e18, "__ntb_register_client" },
	{ 0xd20d562, "ntb_unregister_client" },
	{ 0x6a59169d, "simple_open" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb");


MODULE_INFO(srcversion, "28B21AEAE107B31B5DB981B");
