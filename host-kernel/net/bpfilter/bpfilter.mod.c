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
	{ 0xa5d7a210, "thread_group_exited" },
	{ 0x5f04125a, "bpfilter_umh_cleanup" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x35e30821, "fork_usermode_driver" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xd57fac67, "kill_pid" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x86490580, "current_task" },
	{ 0x135f5ae8, "bpfilter_ops" },
	{ 0x8d70148e, "kernel_read" },
	{ 0xf5b1b6ba, "umd_unload_blob" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd1655628, "umd_load_blob" },
	{ 0xdd6a20bc, "kernel_write" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "187ECF99A1659D8D96C6EC6");
