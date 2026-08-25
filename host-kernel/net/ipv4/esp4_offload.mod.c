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
	{ 0x4eb6f185, "skb_push" },
	{ 0xc6e82f17, "esp_input_done2" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x98d44663, "xfrm_parse_spi" },
	{ 0x5d556d05, "secpath_set" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0xce1ac14a, "__skb_ext_del" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xac5845b, "esp_output_head" },
	{ 0x2124474, "ip_send_check" },
	{ 0xde7e2837, "skb_ext_add" },
	{ 0x2d0558c9, "esp_output_tail" },
	{ 0x69b3475e, "inet_offloads" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9e57e788, "skb_eth_gso_segment" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0xa12541de, "xfrm_register_type_offload" },
	{ 0x92997ed8, "_printk" },
	{ 0x57f2c8f3, "inet_add_offload" },
	{ 0x447026f7, "xfrm_unregister_type_offload" },
	{ 0x60581158, "inet_del_offload" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "esp4");


MODULE_INFO(srcversion, "862A243D7E52704605EF8A0");
