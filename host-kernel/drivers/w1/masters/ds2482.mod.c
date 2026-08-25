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
	{ 0xf2a22dc6, "w1_remove_master_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x34b8e6d6, "i2c_smbus_read_byte" },
	{ 0x92997ed8, "_printk" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x7447bbf1, "i2c_smbus_write_byte" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xcf9384e, "w1_add_master_device" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");

MODULE_ALIAS("i2c:ds2482");

MODULE_INFO(srcversion, "1C173C7E9AA7A1128CB4188");
