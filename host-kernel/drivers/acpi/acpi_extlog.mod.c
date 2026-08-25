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
	{ 0xa50bcff0, "x86_cpu_to_apicid" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xcdb6adcc, "ras_userspace_consumers" },
	{ 0x8df9dd10, "guid_null" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x92997ed8, "_printk" },
	{ 0xe4248980, "cper_estatus_print" },
	{ 0xe501c207, "__tracepoint_extlog_mem_event" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x8b47ea1d, "__SCT__tp_func_extlog_mem_event" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6d606913, "pv_ops" },
	{ 0xb89b6e6b, "guid_parse" },
	{ 0x9975dc22, "acpi_get_handle" },
	{ 0xdd18a993, "acpi_check_dsm" },
	{ 0xae5a04bb, "acpi_evaluate_dsm" },
	{ 0x37a0cba, "kfree" },
	{ 0x77358855, "iomem_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0x603d0d51, "acpi_os_map_iomem" },
	{ 0x6b3ae022, "acpi_os_unmap_iomem" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xb8b2b1f7, "mce_register_decode_chain" },
	{ 0xf2d7d87, "mce_unregister_decode_chain" },
	{ 0x97d1630e, "__SCK__tp_func_extlog_mem_event" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1B6741781539625119A59A6");
