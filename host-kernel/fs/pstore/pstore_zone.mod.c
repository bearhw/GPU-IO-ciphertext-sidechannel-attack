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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(register_pstore_zone, 0x9ec02558, "_gpl");
SYMBOL_CRC(unregister_pstore_zone, 0xd63a73f4, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc8dcc62a, "krealloc" },
	{ 0xd445577, "pstore_register" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfb578fc5, "memset" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xa5d7c388, "pstore_type_to_name" },
	{ 0xe765a2a3, "pstore_unregister" },
	{ 0x989074ff, "kmsg_dump_reason_str" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A70EA48DF0E4F45475E4CF7");
