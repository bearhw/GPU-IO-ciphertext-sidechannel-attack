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

SYMBOL_CRC(mux_chip_alloc, 0x7ef786a7, "_gpl");
SYMBOL_CRC(mux_chip_register, 0x810f789b, "_gpl");
SYMBOL_CRC(mux_chip_unregister, 0x74d8d54c, "_gpl");
SYMBOL_CRC(mux_chip_free, 0x9af49272, "_gpl");
SYMBOL_CRC(devm_mux_chip_alloc, 0xc1ee0772, "_gpl");
SYMBOL_CRC(devm_mux_chip_register, 0xb414d0f3, "_gpl");
SYMBOL_CRC(mux_control_states, 0x260cd67d, "_gpl");
SYMBOL_CRC(mux_control_select_delay, 0xe8a4e73d, "_gpl");
SYMBOL_CRC(mux_state_select_delay, 0xfa76e911, "_gpl");
SYMBOL_CRC(mux_control_try_select_delay, 0xc65ae76c, "_gpl");
SYMBOL_CRC(mux_state_try_select_delay, 0x0a65c89f, "_gpl");
SYMBOL_CRC(mux_control_deselect, 0xb9b15b4d, "_gpl");
SYMBOL_CRC(mux_state_deselect, 0x7cf08396, "_gpl");
SYMBOL_CRC(mux_control_get, 0x23a77538, "_gpl");
SYMBOL_CRC(mux_control_put, 0xa010ca0e, "_gpl");
SYMBOL_CRC(devm_mux_control_get, 0x4f2a2047, "_gpl");
SYMBOL_CRC(devm_mux_state_get, 0x106beb48, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xcf2a6966, "up" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x37a0cba, "kfree" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xea900f57, "devres_add" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x3197c4e3, "put_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x48098f3, "device_add" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xffb7c514, "ida_free" },
	{ 0x70cc876b, "class_unregister" },
	{ 0xe9ffc063, "down_trylock" },
	{ 0x3312881b, "device_del" },
	{ 0xe93e49c3, "devres_free" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x36b6ebbf, "down_killable" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A78BB6D2C28B016C676EBBA");
