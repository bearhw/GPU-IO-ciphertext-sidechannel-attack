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
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0x1f42e417, "crypto_ahash_setkey" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xfb578fc5, "memset" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xae4cc05, "release_sock" },
	{ 0xecc4f8fd, "af_alg_accept" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa0552c2d, "sk_free" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x506a7c48, "sock_kzfree_s" },
	{ 0x1fdaa754, "sock_kfree_s" },
	{ 0xe2c152, "af_alg_release_parent" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x7e9b64ed, "crypto_ahash_final" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x83bc8b71, "crypto_ahash_finup" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x3498d552, "crypto_stats_ahash_update" },
	{ 0x347da517, "crypto_ahash_digest" },
	{ 0x22683c63, "af_alg_free_sg" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0xbac78ae2, "af_alg_make_sg" },
	{ 0xe7268936, "af_alg_register_type" },
	{ 0xa9c44ed4, "af_alg_unregister_type" },
	{ 0xdafa55a9, "af_alg_release" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "af_alg");


MODULE_INFO(srcversion, "1D0C28D24FB7FB163BE04BA");
