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
	{ 0xc541eca1, "sock_kmalloc" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x1fdaa754, "sock_kfree_s" },
	{ 0xe2c152, "af_alg_release_parent" },
	{ 0xacfa2c7c, "crypto_rng_reset" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe9b7102c, "crypto_stats_rng_generate" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9f68a25e, "crypto_alloc_rng" },
	{ 0x37a0cba, "kfree" },
	{ 0xe7268936, "af_alg_register_type" },
	{ 0xa9c44ed4, "af_alg_unregister_type" },
	{ 0xdafa55a9, "af_alg_release" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x16eef981, "sock_no_sendmsg" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "af_alg");


MODULE_INFO(srcversion, "C2EE585A86B2D95CD64DC74");
