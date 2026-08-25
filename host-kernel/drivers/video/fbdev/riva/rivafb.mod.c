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
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x61198ff3, "fb_validate_mode" },
	{ 0xfe32014a, "fb_ddc_read" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x61ea189b, "fb_pad_aligned_buffer" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0xce4cdb8e, "fb_find_best_mode" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xc7c9abe5, "fb_get_mode" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0xe7a2620e, "save_vga" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x78041b8f, "byte_rev_table" },
	{ 0x686de290, "restore_vga" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x4351577a, "fb_parse_edid" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fb_ddc,i2c-algo-bit,vgastate");

MODULE_ALIAS("pci:v000012D2d00000018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000029sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000002Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000002Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000103sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000110sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000113sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000151sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000152sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000153sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000170sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000171sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000001F0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000172sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000174sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000175sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000176sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000178sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000179sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000017Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000017Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000017Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000001A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000200sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000201sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000202sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000203sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000250sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000251sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000253sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000258sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000259sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000025Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000329sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "1AA4CD78590D6B9D344DF6A");
