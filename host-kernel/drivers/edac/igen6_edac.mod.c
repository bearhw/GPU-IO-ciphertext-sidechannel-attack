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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xfe295174, "edac_mc_del_mc" },
	{ 0x37a0cba, "kfree" },
	{ 0x2c39ca93, "edac_mc_free" },
	{ 0xedc03953, "iounmap" },
	{ 0xe64ad8ea, "unregister_nmi_handler" },
	{ 0x63327e90, "irq_work_sync" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x6c224cda, "gen_pool_destroy" },
	{ 0xf2d7d87, "mce_unregister_decode_chain" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2b593aa8, "gen_pool_alloc_algo_owner" },
	{ 0xc7a1840e, "llist_add_batch" },
	{ 0x4b6c991a, "irq_work_queue" },
	{ 0x28cd87ac, "x86_platform" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a537036, "edac_mc_alloc" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xbfbb39b8, "edac_mc_add_mc_with_groups" },
	{ 0xced0f4d4, "gen_pool_create" },
	{ 0xbefa51a3, "gen_pool_add_owner" },
	{ 0xde4eeab5, "__register_nmi_handler" },
	{ 0xb8b2b1f7, "mce_register_decode_chain" },
	{ 0x92997ed8, "_printk" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3c7181, "edac_mc_handle_error" },
	{ 0x60ba97c, "gen_pool_free_owner" },
	{ 0x5ab09745, "edac_get_owner" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb51fbd64, "edac_op_state" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d00004514sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004528sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000452Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004516sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000452Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000452Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004532sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004518sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000451Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004534sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004536sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004581sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004585sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004589sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000458Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009A14sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004601sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004602sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004621sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004641sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "16AE5532A0949B8EBECAE95");
