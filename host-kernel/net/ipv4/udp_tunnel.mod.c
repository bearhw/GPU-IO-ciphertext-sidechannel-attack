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

SYMBOL_CRC(udp_sock_create4, 0x70852ca3, "");
SYMBOL_CRC(setup_udp_tunnel_sock, 0x458fde4a, "_gpl");
SYMBOL_CRC(udp_tunnel_push_rx_port, 0x35fc65f1, "_gpl");
SYMBOL_CRC(udp_tunnel_drop_rx_port, 0xec4f636d, "_gpl");
SYMBOL_CRC(udp_tunnel_notify_add_rx_port, 0xd768ab1d, "_gpl");
SYMBOL_CRC(udp_tunnel_notify_del_rx_port, 0xc9cffe75, "_gpl");
SYMBOL_CRC(udp_tunnel_xmit_skb, 0xd95624a7, "_gpl");
SYMBOL_CRC(udp_tunnel_sock_release, 0xbffe826a, "_gpl");
SYMBOL_CRC(udp_tun_rx_dst, 0x63f24cfc, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xbd9acb3b, "kernel_bind" },
	{ 0xadfa871d, "udp_set_csum" },
	{ 0x37a0cba, "kfree" },
	{ 0x87549110, "netdev_warn" },
	{ 0x49ae9be6, "udp_tunnel_nic_ops" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe35d19bb, "ipv6_stub" },
	{ 0x99517682, "udp_encap_enable" },
	{ 0xf43e05f3, "kernel_sock_shutdown" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x3e3005b, "iptunnel_xmit" },
	{ 0x8520a781, "nla_put" },
	{ 0x288ef7e1, "kernel_connect" },
	{ 0xfb578fc5, "memset" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0xa540cd94, "call_netdevice_notifiers" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x672bdf0d, "metadata_dst_alloc" },
	{ 0x6e5c0971, "sock_release" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xf0ee15f5, "sock_bindtoindex" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x349cba85, "strchr" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D1420DEF9E5883D99F55D74");
