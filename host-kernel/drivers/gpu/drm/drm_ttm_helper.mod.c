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

SYMBOL_CRC(drm_gem_ttm_print_info, 0xd2a5db47, "");
SYMBOL_CRC(drm_gem_ttm_vmap, 0x85d31dc3, "");
SYMBOL_CRC(drm_gem_ttm_vunmap, 0xe396e71b, "");
SYMBOL_CRC(drm_gem_ttm_mmap, 0xab86734c, "");
SYMBOL_CRC(drm_gem_ttm_dumb_map_offset, 0x16b1be0b, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2330f595, "drm_gem_object_lookup" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x1c83ef36, "ttm_bo_vunmap" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0x32a0cc37, "drm_print_bits" },
	{ 0x28779e52, "drm_printf" },
	{ 0xb1f929e6, "ttm_bo_mmap_obj" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xe2ae3814, "ttm_bo_vmap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,ttm");


MODULE_INFO(srcversion, "BA1DC862AF57F41D9149F88");
