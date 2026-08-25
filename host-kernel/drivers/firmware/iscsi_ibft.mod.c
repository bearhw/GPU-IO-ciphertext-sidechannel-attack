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
	{ 0x37a0cba, "kfree" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x92997ed8, "_printk" },
	{ 0xcf672d78, "iscsi_boot_destroy_kset" },
	{ 0xb26066fe, "ibft_phys_addr" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x16cdc340, "acpi_get_table" },
	{ 0x331bd41f, "iscsi_boot_create_kset" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xf1f21c39, "iscsi_boot_create_initiator" },
	{ 0xdd5426c, "iscsi_boot_create_ethernet" },
	{ 0x199fb7a7, "iscsi_boot_create_target" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xd9582100, "iscsi_boot_create_acpitbl" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "iscsi_boot_sysfs");


MODULE_INFO(srcversion, "819F7C004F3AFDDBCDB4917");
