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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6d606913, "pv_ops" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xce9da695, "device_get_child_node_count" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xb053cfac, "fwnode_property_read_string" },
	{ 0xd1f7b726, "fwnode_property_match_string" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0x1e223da8, "fwnode_get_name" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cti,tca6507");
MODULE_ALIAS("of:N*T*Cti,tca6507C*");
MODULE_ALIAS("i2c:tca6507");

MODULE_INFO(srcversion, "6FC05192269E37FAEE574B8");
