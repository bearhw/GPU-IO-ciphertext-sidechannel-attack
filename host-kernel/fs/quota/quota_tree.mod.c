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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(qtree_entry_unused, 0x042129ba, "");
SYMBOL_CRC(qtree_write_dquot, 0x3d1c5388, "");
SYMBOL_CRC(qtree_delete_dquot, 0xa7987cfd, "");
SYMBOL_CRC(qtree_read_dquot, 0x657bfdb5, "");
SYMBOL_CRC(qtree_release_dquot, 0x2637c352, "");
SYMBOL_CRC(qtree_get_next_id, 0xcc428db3, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfb578fc5, "memset" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x37a0cba, "kfree" },
	{ 0x5a728446, "__quota_error" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x71b1aa08, "mark_info_dirty" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x7ce18c9f, "from_kqid" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xfa656cfa, "make_kprojid" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x5240ee7, "percpu_counter_batch" },
	{ 0x6f915a45, "dqstats" },
	{ 0xe138fb8c, "percpu_counter_add_batch" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0B14E0765BDE107B41D056E");
