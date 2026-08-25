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
	{ 0x668b19a1, "down_read" },
	{ 0xcc428db3, "qtree_get_next_id" },
	{ 0x53b954a2, "up_read" },
	{ 0x57bc19d2, "down_write" },
	{ 0x2637c352, "qtree_release_dquot" },
	{ 0xce807a25, "up_write" },
	{ 0x3d1c5388, "qtree_write_dquot" },
	{ 0x657bfdb5, "qtree_read_dquot" },
	{ 0x37a0cba, "kfree" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x5a728446, "__quota_error" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x7ce18c9f, "from_kqid" },
	{ 0x42129ba, "qtree_entry_unused" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xfa656cfa, "make_kprojid" },
	{ 0x8d55bb8a, "qid_eq" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x2bb6099e, "dq_data_lock" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x75e54a03, "register_quota_format" },
	{ 0x482c2141, "unregister_quota_format" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "quota_tree");


MODULE_INFO(srcversion, "346A40DE11699FE3101DD7C");
