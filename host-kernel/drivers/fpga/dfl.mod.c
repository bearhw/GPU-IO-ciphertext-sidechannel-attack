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

SYMBOL_CRC(dfl_fpga_port_ops_get, 0xbc584623, "_gpl");
SYMBOL_CRC(dfl_fpga_port_ops_put, 0xf21650b3, "_gpl");
SYMBOL_CRC(dfl_fpga_port_ops_add, 0x58f7df48, "_gpl");
SYMBOL_CRC(dfl_fpga_port_ops_del, 0x61960744, "_gpl");
SYMBOL_CRC(dfl_fpga_check_port_id, 0x1eeae15c, "_gpl");
SYMBOL_CRC(__dfl_driver_register, 0x467b27e7, "");
SYMBOL_CRC(dfl_driver_unregister, 0xaf4e4c1f, "");
SYMBOL_CRC(dfl_fpga_dev_feature_uinit, 0x0264dafe, "_gpl");
SYMBOL_CRC(dfl_fpga_dev_feature_init, 0x9a788c05, "_gpl");
SYMBOL_CRC(dfl_fpga_dev_ops_register, 0x7ded4891, "_gpl");
SYMBOL_CRC(dfl_fpga_dev_ops_unregister, 0x38255d3f, "_gpl");
SYMBOL_CRC(dfl_fpga_enum_info_alloc, 0x54b3a267, "_gpl");
SYMBOL_CRC(dfl_fpga_enum_info_free, 0xe4f698c9, "_gpl");
SYMBOL_CRC(dfl_fpga_enum_info_add_dfl, 0x91d2a494, "_gpl");
SYMBOL_CRC(dfl_fpga_enum_info_add_irq, 0x4f6c4917, "_gpl");
SYMBOL_CRC(dfl_fpga_feature_devs_enumerate, 0x87afd48d, "_gpl");
SYMBOL_CRC(dfl_fpga_feature_devs_remove, 0x60ad8607, "_gpl");
SYMBOL_CRC(__dfl_fpga_cdev_find_port, 0x5a0548e2, "_gpl");
SYMBOL_CRC(dfl_fpga_cdev_release_port, 0x1bc1808e, "_gpl");
SYMBOL_CRC(dfl_fpga_cdev_assign_port, 0x45bbd3c8, "_gpl");
SYMBOL_CRC(dfl_fpga_cdev_config_ports_pf, 0x022ae580, "_gpl");
SYMBOL_CRC(dfl_fpga_cdev_config_ports_vf, 0xd8ebbd2a, "_gpl");
SYMBOL_CRC(dfl_fpga_set_irq_triggers, 0x0a84f915, "_gpl");
SYMBOL_CRC(dfl_feature_ioctl_get_num_irqs, 0xb3c12465, "_gpl");
SYMBOL_CRC(dfl_feature_ioctl_set_irq, 0xe0e3dc52, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x1de23e95, "module_put" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xc5e74216, "release_resource" },
	{ 0xffb7c514, "ida_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x43f839fa, "cdev_init" },
	{ 0x8057ff4, "cdev_add" },
	{ 0x113f6db6, "cdev_del" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xa40a8382, "get_device" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3197c4e3, "put_device" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x387521b, "devm_kmemdup" },
	{ 0x77358855, "iomem_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x941f2aaa, "eventfd_ctx_put" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xd67364f7, "eventfd_ctx_fdget" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x5f23e3fa, "insert_resource" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x48098f3, "device_add" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x47155238, "platform_device_add" },
	{ 0xfc1b46aa, "platform_device_del" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x782d0c53, "fpga_region_unregister" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x2587f789, "_dev_info" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0xd22db78e, "fpga_region_register" },
	{ 0xf8c2f2bb, "devm_iounmap" },
	{ 0x576efa0c, "__devm_release_region" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xc487b792, "bus_register" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-region");


MODULE_INFO(srcversion, "C6F980FFF28ACB796F325A0");
