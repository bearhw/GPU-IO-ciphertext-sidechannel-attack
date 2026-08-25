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

SYMBOL_CRC(af_alg_register_type, 0xe7268936, "_gpl");
SYMBOL_CRC(af_alg_unregister_type, 0xa9c44ed4, "_gpl");
SYMBOL_CRC(af_alg_release, 0xdafa55a9, "_gpl");
SYMBOL_CRC(af_alg_release_parent, 0x00e2c152, "_gpl");
SYMBOL_CRC(af_alg_accept, 0xecc4f8fd, "_gpl");
SYMBOL_CRC(af_alg_make_sg, 0xbac78ae2, "_gpl");
SYMBOL_CRC(af_alg_free_sg, 0x22683c63, "_gpl");
SYMBOL_CRC(af_alg_count_tsgl, 0x073b13ff, "_gpl");
SYMBOL_CRC(af_alg_pull_tsgl, 0x3544b84a, "_gpl");
SYMBOL_CRC(af_alg_wmem_wakeup, 0xb357a569, "_gpl");
SYMBOL_CRC(af_alg_wait_for_data, 0x927ddaf5, "_gpl");
SYMBOL_CRC(af_alg_sendmsg, 0x48493cfb, "_gpl");
SYMBOL_CRC(af_alg_sendpage, 0x9a75855a, "_gpl");
SYMBOL_CRC(af_alg_free_resources, 0x7f15ffaf, "_gpl");
SYMBOL_CRC(af_alg_async_cb, 0xb2c56ab6, "_gpl");
SYMBOL_CRC(af_alg_poll, 0xc4608a2b, "_gpl");
SYMBOL_CRC(af_alg_alloc_areq, 0x189235a6, "_gpl");
SYMBOL_CRC(af_alg_get_rsgl, 0x33377986, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x57bc19d2, "down_write" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xce807a25, "up_write" },
	{ 0x37a0cba, "kfree" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0x4139b7fe, "iov_iter_get_pages" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc541eca1, "sock_kmalloc" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0x668b19a1, "down_read" },
	{ 0x53b954a2, "up_read" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xae4cc05, "release_sock" },
	{ 0x1de23e95, "module_put" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xda10ec3, "security_sock_graft" },
	{ 0xe06141e9, "security_sk_clone" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x69acdf38, "memcpy" },
	{ 0x506a7c48, "sock_kzfree_s" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x86490580, "current_task" },
	{ 0xd0654aba, "woken_wake_function" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xba220db7, "__wake_up_sync_key" },
	{ 0x894f2745, "sock_wake_async" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x10795da2, "__put_page" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x1fdaa754, "sock_kfree_s" },
	{ 0x87b8798d, "sg_next" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x92997ed8, "_printk" },
	{ 0x68764184, "proto_register" },
	{ 0x50171cd6, "sock_register" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x16eef981, "sock_no_sendmsg" },
	{ 0x5928b1b, "sock_no_recvmsg" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6DF4668ACF6C4BFACBA9724");
