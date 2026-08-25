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
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x37a0cba, "kfree" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x25cf8049, "matroxfb_PLL_calcclock" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x888382b3, "i2c_smbus_write_word_data" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "matroxfb_misc");

MODULE_ALIAS("i2c:maven");

MODULE_INFO(srcversion, "A8046C4861F4D6D17C6BB75");
