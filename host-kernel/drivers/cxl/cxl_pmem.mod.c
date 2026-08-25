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
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x7611bbce, "is_cxl_nvdimm_bridge" },
	{ 0x121a49d, "cxl_mbox_send_cmd" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1fe97fc1, "clear_exclusive_cxl_commands" },
	{ 0x32688245, "__nvdimm_create" },
	{ 0x69acdf38, "memcpy" },
	{ 0xa40a8382, "get_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0x6f4f0be3, "to_cxl_nvdimm_bridge" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xf97831, "nvdimm_bus_unregister" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xf0330cff, "cxl_find_nvdimm_bridge" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd6ececba, "set_exclusive_cxl_commands" },
	{ 0x7f00d276, "__cxl_driver_register" },
	{ 0x66a3f1ee, "is_cxl_nvdimm" },
	{ 0xff3966fe, "nvdimm_delete" },
	{ 0x9912093f, "nvdimm_provider_data" },
	{ 0x17f55d32, "bus_rescan_devices" },
	{ 0x58ac4016, "nvdimm_bus_register" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x571f27af, "cxl_bus_type" },
	{ 0xbc31bd33, "cxl_driver_unregister" },
	{ 0xc77c36bf, "to_cxl_nvdimm" },
	{ 0x31795ba9, "device_release_driver" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x287c53fe, "nvdimm_cmd_mask" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cxl_core");


MODULE_INFO(srcversion, "53FC7520CE591F2A1DDAACE");
