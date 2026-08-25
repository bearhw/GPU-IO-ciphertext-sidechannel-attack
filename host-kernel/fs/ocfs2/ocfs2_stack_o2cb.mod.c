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
	{ 0x289b00f3, "dlm_print_one_lock" },
	{ 0xb6ebf62a, "o2nm_this_node" },
	{ 0x37a0cba, "kfree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x11d31eb2, "dlmlock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a0c3847, "__mlog_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe1290457, "ocfs2_stack_glue_register" },
	{ 0xd859ac8c, "o2net_fill_node_map" },
	{ 0xd2af0919, "ocfs2_stack_glue_unregister" },
	{ 0xd8fa57a6, "dlm_unregister_eviction_cb" },
	{ 0x69dd3b5b, "crc32_le" },
	{ 0xbfd7d7a2, "o2hb_global_heartbeat_active" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x3486c833, "dlm_unregister_domain" },
	{ 0x126ae7d7, "dlm_register_domain" },
	{ 0x7a46fa27, "dlm_register_eviction_cb" },
	{ 0x1b89c6ee, "o2hb_fill_node_map" },
	{ 0x7a1211f8, "dlm_setup_eviction_cb" },
	{ 0x21f99940, "dlmunlock" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ocfs2_dlm,ocfs2_nodemanager,ocfs2_stackglue");


MODULE_INFO(srcversion, "80674EC32EDBE9DB4F32E7E");
