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

SYMBOL_CRC(failover_slave_unregister, 0x7faa87de, "_gpl");
SYMBOL_CRC(failover_register, 0x5292e932, "_gpl");
SYMBOL_CRC(failover_unregister, 0xa362c0cb, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcc5cdacd, "netdev_info" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x37a0cba, "kfree" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa042c7c5, "netdev_rx_handler_unregister" },
	{ 0x65da0a40, "netdev_upper_dev_unlink" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xe27e26c2, "netdev_rx_handler_register" },
	{ 0x9d742740, "netdev_master_upper_dev_link" },
	{ 0x5891f551, "netdev_err" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6D15E3682C5DAE7915A81A0");
