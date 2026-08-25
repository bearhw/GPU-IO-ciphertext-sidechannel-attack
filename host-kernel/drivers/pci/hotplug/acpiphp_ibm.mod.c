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
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x74754435, "acpi_bus_generate_netlink_event" },
	{ 0x72f14ff7, "acpi_get_object_info" },
	{ 0x92997ed8, "_printk" },
	{ 0xf04429b4, "acpi_bus_get_status_handle" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0xdb1d68d3, "pci_slots_kset" },
	{ 0xec2b8a42, "acpi_walk_namespace" },
	{ 0x4087b19f, "acpi_fetch_acpi_dev" },
	{ 0x5391c97e, "acpiphp_register_attention" },
	{ 0x170ddf79, "acpi_install_notify_handler" },
	{ 0xbdc452c4, "acpiphp_unregister_attention" },
	{ 0xd5d074ec, "sysfs_create_bin_file" },
	{ 0x1c58427f, "acpi_remove_notify_handler" },
	{ 0x2eca9998, "sysfs_remove_bin_file" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E7AB1E0F4F435F1473C7480");
