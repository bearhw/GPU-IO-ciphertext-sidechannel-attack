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
	{ 0xfe3b788b, "efivar_entry_find" },
	{ 0x69acdf38, "memcpy" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xc8a5339c, "__efivar_entry_get" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x968f9a23, "efivar_entry_iter_begin" },
	{ 0xa6a3df04, "__efivar_entry_iter" },
	{ 0xd7399d2a, "efivar_entry_iter_end" },
	{ 0x37a0cba, "kfree" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x702946da, "ucs2_strlen" },
	{ 0x9d61e994, "ucs2_strncmp" },
	{ 0x65e9da2e, "__efivar_entry_delete" },
	{ 0x81b03377, "efivar_entry_set_safe" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1de23e95, "module_put" },
	{ 0x4eac709d, "efivar_entry_add" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xad5737fc, "efivar_init" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xfda6e666, "efivars_kobject" },
	{ 0x18615d35, "efivar_supports_writes" },
	{ 0xd445577, "pstore_register" },
	{ 0xe765a2a3, "pstore_unregister" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2244D32EA01321D0CF7144C");
