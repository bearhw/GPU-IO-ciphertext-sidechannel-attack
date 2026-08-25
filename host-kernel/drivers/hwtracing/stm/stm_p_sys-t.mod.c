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
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd12082b3, "stm_register_protocol" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x69e683de, "uuid_gen" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x4e6a8d5, "stm_data_write" },
	{ 0xea717ac4, "to_pdrv_policy_node" },
	{ 0xb67fec0e, "uuid_parse" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6410ff6a, "stm_unregister_protocol" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "stm_core");


MODULE_INFO(srcversion, "80488C6FA17ACD30A967618");
