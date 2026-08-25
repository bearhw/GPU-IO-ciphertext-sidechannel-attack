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
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x47d3c97f, "psp_check_tee_status" },
	{ 0x3ca4771c, "tee_device_register" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x703d5a9d, "tee_device_alloc" },
	{ 0xeb1aab81, "tee_device_unregister" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xaa04056c, "psp_tee_process_cmd" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ccp,tee");


MODULE_INFO(srcversion, "427A88C75DE91F02F6762C2");
