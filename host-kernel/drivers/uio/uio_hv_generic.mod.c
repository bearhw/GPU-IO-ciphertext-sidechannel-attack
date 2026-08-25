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
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x6612cb1, "vm_iomap_memory" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xdf064b28, "vmbus_disconnect_ring" },
	{ 0x79510029, "vmbus_set_chn_rescind_callback" },
	{ 0x99e4fa6b, "vmbus_set_sc_create_callback" },
	{ 0xfff6cecc, "vmbus_connect_ring" },
	{ 0xaa50bea4, "uio_event_notify" },
	{ 0x77f9ae61, "vmbus_open" },
	{ 0xd5d074ec, "sysfs_create_bin_file" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa3afc2c1, "vmbus_close" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf56ae69b, "vmbus_alloc_ring" },
	{ 0x2339f1b1, "vmbus_connection" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xd8715d23, "vmbus_establish_gpadl" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x9061f154, "__uio_register_device" },
	{ 0x999e8297, "vfree" },
	{ 0xd4761b7e, "vmbus_free_ring" },
	{ 0x1c5df67f, "vmbus_teardown_gpadl" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0x2eca9998, "sysfs_remove_bin_file" },
	{ 0xf14a7a00, "uio_unregister_device" },
	{ 0x8f4947c8, "__vmbus_driver_register" },
	{ 0xcaff6dc5, "vmbus_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hv_vmbus,uio");


MODULE_INFO(srcversion, "835A04E6F359A95E8A1148C");
