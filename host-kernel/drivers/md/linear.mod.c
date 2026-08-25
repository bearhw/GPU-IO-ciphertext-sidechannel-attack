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
	{ 0x2287440d, "set_capacity_and_notify" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x273aff5c, "__SCT__tp_func_block_bio_remap" },
	{ 0x21d6e3b6, "register_md_personality" },
	{ 0x5ef68429, "md_integrity_register" },
	{ 0x7c04c00f, "md_check_no_bitmap" },
	{ 0x50b2239f, "mddev_resume" },
	{ 0x37a0cba, "kfree" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xac25495b, "md_set_array_sectors" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x1cd42933, "__SCK__tp_func_block_bio_remap" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x9f218161, "bio_chain" },
	{ 0x90d27bc3, "disk_stack_limits" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x2c4354fc, "md_flush_request" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4f2e94e7, "unregister_md_personality" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xba97195a, "__tracepoint_block_bio_remap" },
	{ 0x342ca964, "mddev_suspend" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x54366892, "bio_split" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "927FC615E125E50F6661536");
