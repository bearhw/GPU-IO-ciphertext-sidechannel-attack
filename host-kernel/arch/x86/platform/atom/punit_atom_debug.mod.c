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
	{ 0xb82ba28c, "single_open" },
	{ 0x391de184, "seq_puts" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x86c7272b, "iosf_mbi_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xf2b11959, "seq_read" },
	{ 0xbb2b861a, "single_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0037:feature:*0083*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004A:feature:*0083*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004C:feature:*0083*");

MODULE_INFO(srcversion, "7A4A7540A874FBCABD35EF2");
