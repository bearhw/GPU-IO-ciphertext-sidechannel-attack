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

SYMBOL_CRC(drm_gem_shmem_create, 0x7e8ea9a9, "_gpl");
SYMBOL_CRC(drm_gem_shmem_free, 0x1c09fbdf, "_gpl");
SYMBOL_CRC(drm_gem_shmem_get_pages, 0xbffc3fd4, "");
SYMBOL_CRC(drm_gem_shmem_put_pages, 0x3efb431d, "");
SYMBOL_CRC(drm_gem_shmem_pin, 0x223cdf29, "");
SYMBOL_CRC(drm_gem_shmem_unpin, 0x58a53fcc, "");
SYMBOL_CRC(drm_gem_shmem_vmap, 0xa1d7f1e7, "");
SYMBOL_CRC(drm_gem_shmem_vunmap, 0xed76f357, "");
SYMBOL_CRC(drm_gem_shmem_madvise, 0x0d2d8218, "");
SYMBOL_CRC(drm_gem_shmem_purge_locked, 0xc7c79e5c, "");
SYMBOL_CRC(drm_gem_shmem_purge, 0x4071ba17, "");
SYMBOL_CRC(drm_gem_shmem_dumb_create, 0x480d14ca, "_gpl");
SYMBOL_CRC(drm_gem_shmem_vm_ops, 0xb577b705, "_gpl");
SYMBOL_CRC(drm_gem_shmem_mmap, 0x350a72c6, "_gpl");
SYMBOL_CRC(drm_gem_shmem_print_info, 0x54054dd1, "");
SYMBOL_CRC(drm_gem_shmem_get_sg_table, 0xae9a8182, "_gpl");
SYMBOL_CRC(drm_gem_shmem_get_pages_sgt, 0xae9865f1, "_gpl");
SYMBOL_CRC(drm_gem_shmem_prime_import_sg_table, 0x1a3b73ee, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xd5094b5a, "vmf_insert_pfn" },
	{ 0x472d1bb0, "drm_gem_get_pages" },
	{ 0xe501e91d, "dma_buf_vmap" },
	{ 0x494e3393, "vm_get_page_prot" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x1371d6dc, "invalidate_mapping_pages" },
	{ 0x79cc14e8, "unmap_mapping_range" },
	{ 0x94961283, "vunmap" },
	{ 0x5800ce0c, "dma_buf_mmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x1d6db591, "drm_gem_create_mmap_offset" },
	{ 0xef3c4945, "drm_gem_object_init" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x98d94cee, "drm_gem_private_object_init" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe81c5a77, "set_pages_array_wb" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0xdc905b62, "drm_gem_vm_close" },
	{ 0x75f96800, "drm_gem_vm_open" },
	{ 0xa15e1675, "drm_gem_object_release" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xed2a2b32, "vmap" },
	{ 0x435f223e, "drm_gem_handle_create" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x51587db2, "drm_prime_pages_to_sg" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x50d1f870, "pgprot_writecombine" },
	{ 0x43b6f11e, "dma_buf_vunmap" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0x411def1b, "shmem_truncate_range" },
	{ 0x823d28fd, "set_pages_array_wc" },
	{ 0x28779e52, "drm_printf" },
	{ 0x93636f65, "dma_map_sgtable" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xaed2c6b9, "drm_gem_free_mmap_offset" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xe02e38c0, "drm_gem_put_pages" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x3122d93a, "drm_prime_gem_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm");


MODULE_INFO(srcversion, "490B2AE459A34BC11F7E59F");
