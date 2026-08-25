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

SYMBOL_CRC(rpmsg_class, 0x915696d8, "");
SYMBOL_CRC(rpmsg_create_channel, 0xa3561db2, "");
SYMBOL_CRC(rpmsg_release_channel, 0xdcc3d2e3, "");
SYMBOL_CRC(rpmsg_create_ept, 0x598e2047, "");
SYMBOL_CRC(rpmsg_destroy_ept, 0x1ccc39c3, "");
SYMBOL_CRC(rpmsg_send, 0xd9f95029, "");
SYMBOL_CRC(rpmsg_sendto, 0x11fcc82b, "");
SYMBOL_CRC(rpmsg_send_offchannel, 0x54f6f0a4, "");
SYMBOL_CRC(rpmsg_trysend, 0xe9c39b47, "");
SYMBOL_CRC(rpmsg_trysendto, 0x1e472d9e, "");
SYMBOL_CRC(rpmsg_poll, 0x7588fbe5, "");
SYMBOL_CRC(rpmsg_trysend_offchannel, 0x5c12f909, "");
SYMBOL_CRC(rpmsg_get_mtu, 0xa83a99a4, "");
SYMBOL_CRC(rpmsg_find_device, 0xe58ef434, "");
SYMBOL_CRC(rpmsg_register_device_override, 0xa46f34a4, "");
SYMBOL_CRC(rpmsg_register_device, 0xe483dc39, "");
SYMBOL_CRC(rpmsg_unregister_device, 0xb16952e2, "");
SYMBOL_CRC(__register_rpmsg_driver, 0x0c045240, "");
SYMBOL_CRC(unregister_rpmsg_driver, 0xcde91d2c, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa2c36d08, "device_find_child" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x5a921311, "strncmp" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x754d539c, "strlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x74dbf6d5, "driver_set_override" },
	{ 0x48098f3, "device_add" },
	{ 0x37a0cba, "kfree" },
	{ 0x3197c4e3, "put_device" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0x1ac5d3cb, "strcspn" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xbea9f813, "dev_pm_domain_detach" },
	{ 0x44b0ffb1, "dev_pm_domain_attach" },
	{ 0x9166fada, "strncpy" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x92997ed8, "_printk" },
	{ 0xc487b792, "bus_register" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5112F8A7057A2FB1586D288");
