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
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xd539673b, "__seq_open_private" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xa906274e, "seq_putc" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0x37a0cba, "kfree" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x48012e28, "xt_check_proc_name" },
	{ 0x18e60984, "__do_once_start" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xbe38f709, "__do_once_done" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xa916b694, "strnlen" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x2bf33597, "proc_create_data" },
	{ 0x9ad2c4fe, "proc_set_user" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4841bdee, "strnchr" },
	{ 0x609bcd98, "in6_pton" },
	{ 0xac5fcec0, "in4_pton" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x7ec922ce, "xt_register_matches" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x4bb1f65e, "xt_unregister_matches" },
	{ 0xf2b11959, "seq_read" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x9f186838, "seq_release_private" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "7B5E4592A1EACD55A00FB6C");
