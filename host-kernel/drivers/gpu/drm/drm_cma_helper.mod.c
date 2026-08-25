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

SYMBOL_CRC(drm_gem_cma_create, 0x2c56e175, "_gpl");
SYMBOL_CRC(drm_gem_cma_free, 0xe5ef5d83, "_gpl");
SYMBOL_CRC(drm_gem_cma_dumb_create_internal, 0x1d6cae6a, "_gpl");
SYMBOL_CRC(drm_gem_cma_dumb_create, 0x9b930703, "_gpl");
SYMBOL_CRC(drm_gem_cma_vm_ops, 0x3addd02a, "_gpl");
SYMBOL_CRC(drm_gem_cma_print_info, 0xcc9d1e44, "");
SYMBOL_CRC(drm_gem_cma_get_sg_table, 0x239a4caf, "_gpl");
SYMBOL_CRC(drm_gem_cma_prime_import_sg_table, 0xb34eac41, "_gpl");
SYMBOL_CRC(drm_gem_cma_vmap, 0x90c546ea, "_gpl");
SYMBOL_CRC(drm_gem_cma_mmap, 0x73f7d974, "_gpl");
SYMBOL_CRC(drm_gem_cma_prime_import_sg_table_vmap, 0x978e3a7b, "");
SYMBOL_CRC(drm_fb_cma_get_gem_obj, 0x52536c83, "_gpl");
SYMBOL_CRC(drm_fb_cma_get_gem_addr, 0x49e07805, "_gpl");
SYMBOL_CRC(drm_fb_cma_sync_non_coherent, 0xc5a10f11, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb11ac7a7, "__drm_err" },
	{ 0xe501e91d, "dma_buf_vmap" },
	{ 0x59148456, "drm_dev_dbg" },
	{ 0x494e3393, "vm_get_page_prot" },
	{ 0x6b5c2b06, "drm_atomic_helper_damage_iter_next" },
	{ 0xbd6d3059, "dma_mmap_pages" },
	{ 0x1d773d47, "dma_free_pages" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x1d6db591, "drm_gem_create_mmap_offset" },
	{ 0xef3c4945, "drm_gem_object_init" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6a44103, "drm_atomic_helper_damage_iter_init" },
	{ 0xa7740ca9, "dma_alloc_pages" },
	{ 0x98d94cee, "drm_gem_private_object_init" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0xdc905b62, "drm_gem_vm_close" },
	{ 0x75f96800, "drm_gem_vm_open" },
	{ 0xa15e1675, "drm_gem_object_release" },
	{ 0xccc59759, "drm_format_info_block_width" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xd05fda43, "drm_prime_get_contiguous_size" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x435f223e, "drm_gem_handle_create" },
	{ 0xe3ca4fc5, "drm_gem_fb_get_obj" },
	{ 0x43b6f11e, "dma_buf_vunmap" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x28779e52, "drm_printf" },
	{ 0xae5917ce, "dma_mmap_attrs" },
	{ 0xd82c1aa0, "dma_get_sgtable_attrs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xca190085, "drm_format_info_block_height" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x3122d93a, "drm_prime_gem_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper");


MODULE_INFO(srcversion, "F5C2CDEB35DDD2A681F7C3F");
