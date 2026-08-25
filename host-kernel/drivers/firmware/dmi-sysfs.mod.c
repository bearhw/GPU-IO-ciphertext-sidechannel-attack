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
	{ 0x7c983a5d, "dmi_walk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7c181721, "kobject_put" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xc6cbbc89, "capable" },
	{ 0x37a0cba, "kfree" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4d924f20, "memremap" },
	{ 0x9e9fdd9d, "memunmap" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc392bf7, "kobject_init_and_add" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd5d074ec, "sysfs_create_bin_file" },
	{ 0x6b980b08, "kobject_del" },
	{ 0x65e0d6d7, "memory_read_from_buffer" },
	{ 0x495b4bf6, "dmi_kobj" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x7233a2e6, "kset_create_and_add" },
	{ 0x3f7b09fb, "kset_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "37BC7212CC2237BD0F7D465");
