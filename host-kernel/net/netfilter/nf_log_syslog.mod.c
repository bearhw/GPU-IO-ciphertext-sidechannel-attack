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
	{ 0x27871be6, "nf_log_unset" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xcd6f2dc9, "nf_log_buf_add" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x65424333, "nf_log_set" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7c6024bd, "init_net" },
	{ 0x9aaeefce, "sysctl_nf_log_all_netns" },
	{ 0xd4961de, "nf_log_buf_open" },
	{ 0x80c68137, "nf_log_buf_close" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2d492902, "nf_log_register" },
	{ 0xa8f4170f, "nf_log_unregister" },
	{ 0x92997ed8, "_printk" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "905ECD7158ECDFF39AB7E18");
