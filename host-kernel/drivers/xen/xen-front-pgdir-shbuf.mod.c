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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(xen_front_pgdir_shbuf_get_dir_start, 0xa633a415, "_gpl");
SYMBOL_CRC(xen_front_pgdir_shbuf_map, 0xc6352942, "_gpl");
SYMBOL_CRC(xen_front_pgdir_shbuf_unmap, 0x9b995b3c, "_gpl");
SYMBOL_CRC(xen_front_pgdir_shbuf_free, 0x63208031, "_gpl");
SYMBOL_CRC(xen_front_pgdir_shbuf_alloc, 0xae84b03f, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xe1f7ab96, "gnttab_end_foreign_access" },
	{ 0x37a0cba, "kfree" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x4b931968, "xen_features" },
	{ 0xe73f8b67, "gnttab_unmap_refs" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xf27d0a7b, "gnttab_grant_foreign_access_ref" },
	{ 0x31dca4d8, "gnttab_claim_grant_reference" },
	{ 0x3362b03c, "xen_p2m_size" },
	{ 0x25f02c87, "xen_p2m_addr" },
	{ 0x3a7d80f9, "xen_max_p2m_pfn" },
	{ 0xfe727411, "get_phys_to_machine" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd27f215d, "gnttab_alloc_grant_references" },
	{ 0x93d1d424, "gnttab_free_grant_references" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17001b5e, "gnttab_map_refs" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E7C89FBA180BA241BDFA7FB");
