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
	{ 0x3e2da886, "init_user_ns" },
	{ 0x7ce18c9f, "from_kqid" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x5240ee7, "percpu_counter_batch" },
	{ 0x6f915a45, "dqstats" },
	{ 0xe138fb8c, "percpu_counter_add_batch" },
	{ 0x5a728446, "__quota_error" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x668b19a1, "down_read" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x53b954a2, "up_read" },
	{ 0x92997ed8, "_printk" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x2bb6099e, "dq_data_lock" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x75e54a03, "register_quota_format" },
	{ 0x482c2141, "unregister_quota_format" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5B003A30B0FA4C7E052D085");
