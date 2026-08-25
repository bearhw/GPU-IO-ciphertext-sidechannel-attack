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

SYMBOL_CRC(to_nfit_uuid, 0x06848c60, "");
SYMBOL_CRC(acpi_nfit_ctl, 0x854da578, "_gpl");
SYMBOL_CRC(nfit_get_smbios_id, 0x499bbf57, "_gpl");
SYMBOL_CRC(__acpi_nvdimm_notify, 0x858a85e5, "_gpl");
SYMBOL_CRC(acpi_nfit_init, 0x61297f16, "_gpl");
SYMBOL_CRC(acpi_nfit_desc_init, 0x9b1bd5e4, "_gpl");
SYMBOL_CRC(acpi_nfit_shutdown, 0x4639bcda, "_gpl");
SYMBOL_CRC(__acpi_nfit_notify, 0x2419cda9, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x1d12c54d, "nvdimm_region_notify" },
	{ 0x6d2e899d, "mce_usable_address" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x5652cdaf, "nd_region_provider_data" },
	{ 0xd14edfb1, "nvdimm_bus_add_badrange" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0xa01a8d9b, "nd_cmd_bus_desc" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xea155036, "to_nvdimm" },
	{ 0xf2d7d87, "mce_unregister_decode_chain" },
	{ 0x32688245, "__nvdimm_create" },
	{ 0xda86dacb, "to_nd_region" },
	{ 0xdc133195, "nvdimm_bus_check_dimm_count" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x36173c1d, "phys_to_target_node" },
	{ 0x1b074f, "mce_is_correctable" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb78b21b, "kernfs_notify" },
	{ 0x96dfa7d1, "to_nvdimm_bus" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x9e52e1b8, "acpi_find_child_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x638a9653, "memory_add_physaddr_to_nid" },
	{ 0x2587f789, "_dev_info" },
	{ 0xc6cbbc89, "capable" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb2db2d5, "remove_resource" },
	{ 0xc2c5802, "work_busy" },
	{ 0x92b99a33, "acpi_put_table" },
	{ 0x9975dc22, "acpi_get_handle" },
	{ 0xb5df7cf4, "to_nd_desc" },
	{ 0xae5a04bb, "acpi_evaluate_dsm" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x5bb22dfb, "nd_cmd_out_size" },
	{ 0xb7c0f443, "sort" },
	{ 0xb501b2df, "nd_cmd_dimm_desc" },
	{ 0xf97831, "nvdimm_bus_unregister" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x590b666e, "kernfs_find_and_get_ns" },
	{ 0xd4fe0a6b, "nvdimm_name" },
	{ 0xf0815b37, "to_nvdimm_bus_dev" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xd32fab80, "nvdimm_volatile_region_create" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x9912093f, "nvdimm_provider_data" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5f23e3fa, "insert_resource" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xc7487a4a, "nvdimm_in_overwrite" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xbd652f6a, "nvdimm_to_bus" },
	{ 0x6d606913, "pv_ops" },
	{ 0x58ac4016, "nvdimm_bus_register" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xc6986ae0, "nd_region_dev" },
	{ 0x16cdc340, "acpi_get_table" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf0674527, "nd_cmd_in_size" },
	{ 0x6790ebd3, "mce_is_memory_error" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0xb89b6e6b, "guid_parse" },
	{ 0x5c52bf15, "kernfs_put" },
	{ 0xe091c977, "list_sort" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0xe26efb67, "nvdimm_pmem_region_create" },
	{ 0xf5733269, "nvdimm_kobj" },
	{ 0x56470118, "__warn_printk" },
	{ 0xb8b2b1f7, "mce_register_decode_chain" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x1cd8438b, "pxm_to_node" },
	{ 0x8f2703b7, "wbinvd_on_all_cpus" },
	{ 0xdd18a993, "acpi_check_dsm" },
	{ 0x170ddf79, "acpi_install_notify_handler" },
	{ 0x4939ebcd, "numa_map_to_online_node" },
	{ 0xaf076aec, "nd_fletcher64" },
	{ 0xf6a28554, "region_intersects" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77358855, "iomem_resource" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1c58427f, "acpi_remove_notify_handler" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x287c53fe, "nvdimm_cmd_mask" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:ACPI0012:*");

MODULE_INFO(srcversion, "7E785DCDB17C23937CB89C1");
