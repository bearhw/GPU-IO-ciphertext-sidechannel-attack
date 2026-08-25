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

SYMBOL_CRC(sis_malloc, 0x3037658e, "");
SYMBOL_CRC(sis_free, 0xfe963115, "");
SYMBOL_CRC(sis_malloc_new, 0x0377a04e, "_gpl");
SYMBOL_CRC(sis_free_new, 0x13a00a40, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xedc03953, "iounmap" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x92997ed8, "_printk" },
	{ 0x96b29254, "strncasecmp" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa916b694, "strnlen" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x2587f789, "_dev_info" },
	{ 0xc6cbbc89, "capable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x5a921311, "strncmp" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x779447df, "pci_map_rom" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x999e8297, "vfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xc6eed989, "pci_get_class" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x65162719, "pci_get_slot" },
	{ 0xa4191c0b, "memset_io" },
	{ 0x979833d1, "pci_unmap_rom" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x77358855, "iomem_resource" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x85bd1608, "__request_region" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001039d00000300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00005300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00006300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000315sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000325sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00005315sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00006325sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000330sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00006330sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000018CAd00000020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000018CAd00000040sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "82A85B8BA181F7164DFBA4C");
