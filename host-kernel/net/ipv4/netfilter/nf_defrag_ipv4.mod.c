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

SYMBOL_CRC(nf_defrag_ipv4_enable, 0x3ba8a9f3, "_gpl");
SYMBOL_CRC(nf_defrag_ipv4_disable, 0xbab6e799, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x1de7493b, "ip_defrag" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "52E1D82824810B71BC94219");
