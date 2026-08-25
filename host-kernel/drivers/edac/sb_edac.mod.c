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
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x37a0cba, "kfree" },
	{ 0x92997ed8, "_printk" },
	{ 0xfe295174, "edac_mc_del_mc" },
	{ 0x2c39ca93, "edac_mc_free" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3c7181, "edac_mc_handle_error" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe914e41e, "strcpy" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x5ab09745, "edac_get_owner" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0xb51fbd64, "edac_op_state" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa6b3c164, "pci_dev_get" },
	{ 0x7a537036, "edac_mc_alloc" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xbfbb39b8, "edac_mc_add_mc_with_groups" },
	{ 0xb8b2b1f7, "mce_register_decode_chain" },
	{ 0xf2d7d87, "mce_unregister_decode_chain" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0056:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0057:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0085:feature:*");

MODULE_INFO(srcversion, "B7B5288A293928BDABBF136");
