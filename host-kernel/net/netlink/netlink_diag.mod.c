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
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x37a5d32, "sock_diag_save_cookie" },
	{ 0x37a0cba, "kfree" },
	{ 0xe5ce1a56, "rhashtable_walk_enter" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa731f387, "nl_table_lock" },
	{ 0xcbbcad3c, "nl_table" },
	{ 0x8520a781, "nla_put" },
	{ 0x9a5dce5c, "rhashtable_walk_start_check" },
	{ 0x9cd7551a, "rhashtable_walk_stop" },
	{ 0xb2a212e7, "sock_diag_register" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x45de6f4f, "sock_diag_unregister" },
	{ 0x54651f9b, "rhashtable_walk_next" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3e78a68, "sock_diag_put_meminfo" },
	{ 0xf188a662, "rhashtable_walk_exit" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3B4F6D51AC00C115A4E10B5");
