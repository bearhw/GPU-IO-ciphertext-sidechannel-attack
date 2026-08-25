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
	{ 0x905cef39, "_vdpa_unregister_device" },
	{ 0x3684d8af, "vringh_complete_iotlb" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xc0bb1581, "vringh_need_notify_iotlb" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x4690a6f6, "vdpasim_create" },
	{ 0x886e3a2d, "_vdpa_register_device" },
	{ 0x3197c4e3, "put_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x61e3831b, "vringh_getdesc_iotlb" },
	{ 0xc46f5fb, "vringh_iov_pull_iotlb" },
	{ 0x18f3ddc2, "vringh_iov_push_iotlb" },
	{ 0x37a0cba, "kfree" },
	{ 0x5a921311, "strncmp" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x422066d2, "device_register" },
	{ 0xe48d6275, "vdpa_mgmtdev_register" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x541125c9, "vdpa_mgmtdev_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vdpa,vringh,vdpa_sim");


MODULE_INFO(srcversion, "9959191F85F52960D01A509");
