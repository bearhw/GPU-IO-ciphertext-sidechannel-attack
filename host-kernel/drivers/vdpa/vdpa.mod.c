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

SYMBOL_CRC(vdpa_set_status, 0x38ed7cee, "");
SYMBOL_CRC(__vdpa_alloc_device, 0xe40f4ed3, "_gpl");
SYMBOL_CRC(_vdpa_register_device, 0x886e3a2d, "_gpl");
SYMBOL_CRC(vdpa_register_device, 0x9313759a, "_gpl");
SYMBOL_CRC(_vdpa_unregister_device, 0x905cef39, "_gpl");
SYMBOL_CRC(vdpa_unregister_device, 0x7ec684b2, "_gpl");
SYMBOL_CRC(__vdpa_register_driver, 0x37cee29e, "_gpl");
SYMBOL_CRC(vdpa_unregister_driver, 0xc23532a7, "_gpl");
SYMBOL_CRC(vdpa_mgmtdev_register, 0xe48d6275, "_gpl");
SYMBOL_CRC(vdpa_mgmtdev_unregister, 0x541125c9, "_gpl");
SYMBOL_CRC(vdpa_get_config, 0x732207b7, "_gpl");
SYMBOL_CRC(vdpa_set_config, 0xf727c217, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xffb7c514, "ida_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x74dbf6d5, "driver_set_override" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x84909a73, "bus_find_device" },
	{ 0x48098f3, "device_add" },
	{ 0x3197c4e3, "put_device" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0x668b19a1, "down_read" },
	{ 0x53b954a2, "up_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x1b556d75, "netlink_capable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0x754d539c, "strlen" },
	{ 0x8520a781, "nla_put" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xc487b792, "bus_register" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "93E577DBA7552F62002675F");
