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
	{ 0x92997ed8, "_printk" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa5bda8a1, "efi_capsule_supported" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0x800473f, "__cond_resched" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x2aadad1a, "efi_capsule_update" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0xed2a2b32, "vmap" },
	{ 0x94961283, "vunmap" },
	{ 0x1f1821ae, "efi" },
	{ 0x4708008a, "misc_register" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x636a2492, "no_llseek" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2D543EC5DDEC76814D05DFA");
