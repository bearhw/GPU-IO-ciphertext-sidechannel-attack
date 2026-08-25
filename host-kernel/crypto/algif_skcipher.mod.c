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
	{ 0x48493cfb, "af_alg_sendmsg" },
	{ 0x3544b84a, "af_alg_pull_tsgl" },
	{ 0x506a7c48, "sock_kzfree_s" },
	{ 0x1fdaa754, "sock_kfree_s" },
	{ 0xe2c152, "af_alg_release_parent" },
	{ 0xc541eca1, "sock_kmalloc" },
	{ 0xfb578fc5, "memset" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x6a4924c, "crypto_alloc_skcipher" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x73b13ff, "af_alg_count_tsgl" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xb2c56ab6, "af_alg_async_cb" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x7f15ffaf, "af_alg_free_resources" },
	{ 0x927ddaf5, "af_alg_wait_for_data" },
	{ 0x189235a6, "af_alg_alloc_areq" },
	{ 0x33377986, "af_alg_get_rsgl" },
	{ 0xb357a569, "af_alg_wmem_wakeup" },
	{ 0xae4cc05, "release_sock" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9a75855a, "af_alg_sendpage" },
	{ 0xe7268936, "af_alg_register_type" },
	{ 0xa9c44ed4, "af_alg_unregister_type" },
	{ 0xdafa55a9, "af_alg_release" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xc4608a2b, "af_alg_poll" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "af_alg");


MODULE_INFO(srcversion, "190A33BF4F1D68180B21D49");
