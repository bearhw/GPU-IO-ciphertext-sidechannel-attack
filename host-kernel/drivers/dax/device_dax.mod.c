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

SYMBOL_CRC(dev_dax_probe, 0x7e151b6e, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x187b6a95, "noop_dirty_folio" },
	{ 0x27b018c8, "vmf_insert_pfn_pud_prot" },
	{ 0x8d7844c, "dax_driver_unregister" },
	{ 0x8b910be2, "errseq_sample" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x7376be01, "static_dev_dax" },
	{ 0x8eee3399, "dax_read_unlock" },
	{ 0x8057ff4, "cdev_add" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x2544fc35, "linear_hugepage_index" },
	{ 0xe0eaa287, "dax_inode" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x5f6f1e9e, "dax_get_private" },
	{ 0x86490580, "current_task" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9f850ce8, "__dax_driver_register" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xd84d35bd, "dax_read_lock" },
	{ 0xf0850137, "devm_memremap_pages" },
	{ 0xd0db0f12, "run_dax" },
	{ 0xe21f5278, "vmf_insert_pfn_pmd_prot" },
	{ 0x3f84bcd7, "dax_alive" },
	{ 0xc0bea473, "vmf_insert_mixed" },
	{ 0x77358855, "iomem_resource" },
	{ 0xe95babcf, "kill_dev_dax" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xab3b38d9, "inode_dax" },
	{ 0x113f6db6, "cdev_del" },
	{ 0xbdb2ad11, "cdev_set_parent" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E46793F7805794094267319");
