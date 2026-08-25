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

SYMBOL_CRC(cfag12864b_buffer, 0xc48e9d95, "_gpl");
SYMBOL_CRC(cfag12864b_getrate, 0x9522a342, "_gpl");
SYMBOL_CRC(cfag12864b_enable, 0x3389f926, "_gpl");
SYMBOL_CRC(cfag12864b_disable, 0x0ecb2e5d, "_gpl");
SYMBOL_CRC(cfag12864b_isenabled, 0x305dc3c6, "_gpl");
SYMBOL_CRC(cfag12864b_isinited, 0x02ff9464, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xbf4774db, "ks0108_writecontrol" },
	{ 0x14102f23, "ks0108_displaystate" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x4f506333, "ks0108_startline" },
	{ 0xedde6df2, "ks0108_page" },
	{ 0xfee8ef7b, "ks0108_address" },
	{ 0x48a70518, "ks0108_writedata" },
	{ 0x6edae968, "ks0108_isinited" },
	{ 0x92997ed8, "_printk" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x37a0cba, "kfree" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ks0108");


MODULE_INFO(srcversion, "A7B3650BE508E9CDC4EFF89");
