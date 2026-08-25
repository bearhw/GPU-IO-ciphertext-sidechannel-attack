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
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x21d6e3b6, "register_md_personality" },
	{ 0x7c04c00f, "md_check_no_bitmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xac25495b, "md_set_array_sectors" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa09dd780, "bio_put" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x90d27bc3, "disk_stack_limits" },
	{ 0x53c25af3, "bio_alloc_clone" },
	{ 0x4f2e94e7, "unregister_md_personality" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C0D02343AB2D30CE70FFC04");
