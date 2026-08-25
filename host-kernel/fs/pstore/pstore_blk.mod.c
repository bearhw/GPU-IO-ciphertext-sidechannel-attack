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

SYMBOL_CRC(register_pstore_device, 0xf206fb31, "_gpl");
SYMBOL_CRC(unregister_pstore_device, 0x2fb56695, "_gpl");
SYMBOL_CRC(pstore_blk_get_config, 0x43cc3d4b, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x751e692e, "filp_open" },
	{ 0xd542d474, "param_ops_long" },
	{ 0x37a0cba, "kfree" },
	{ 0x13d4a8af, "I_BDEV" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xd28f6a7f, "fput" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9ec02558, "register_pstore_zone" },
	{ 0x9166fada, "strncpy" },
	{ 0x8d70148e, "kernel_read" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xd63a73f4, "unregister_pstore_zone" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xdd6a20bc, "kernel_write" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pstore_zone");


MODULE_INFO(srcversion, "6662ED1E3C78451085DB8C2");
