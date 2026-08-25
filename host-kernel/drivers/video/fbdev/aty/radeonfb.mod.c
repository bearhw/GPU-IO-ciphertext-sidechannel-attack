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
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x61198ff3, "fb_validate_mode" },
	{ 0xfe32014a, "fb_ddc_read" },
	{ 0x7cb8cb5f, "pci_request_region" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xd5d074ec, "sysfs_create_bin_file" },
	{ 0xedc03953, "iounmap" },
	{ 0xaa897f18, "fb_set_cmap" },
	{ 0x37a0cba, "kfree" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x50a4698c, "fb_videomode_to_modelist" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x40d04664, "console_trylock" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0xa916b694, "strnlen" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xb1c3a01a, "oops_in_progress" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xdffc80fc, "vesa_modes" },
	{ 0x70249af6, "pci_platform_power_transition" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x96c17136, "fb_var_to_videomode" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x65e0d6d7, "memory_read_from_buffer" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x779447df, "pci_map_rom" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb9056bb6, "remove_conflicting_framebuffers" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xc631580a, "console_unlock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x4351577a, "fb_parse_edid" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0xee58e970, "fb_add_videomode" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x4672e5, "fb_pan_display" },
	{ 0xea7a175, "fb_bl_default_curve" },
	{ 0x979833d1, "pci_unmap_rom" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xf34989c, "pci_release_region" },
	{ 0x2eca9998, "sysfs_remove_bin_file" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fb_ddc,i2c-algo-bit");

MODULE_ALIAS("pci:v00001002d00005955sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005975sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C59sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C5Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005159sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000515Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000515Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004336sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004136sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004337sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004137sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004437sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004237sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004242sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004243sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000514Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000514Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C57sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C58sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005157sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005158sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C64sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C65sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C66sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C67sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004966sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004967sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005A62sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005834sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007834sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005C61sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005C63sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005960sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005961sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005962sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005964sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004145sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004146sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004147sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E44sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E45sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E46sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E47sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E51sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E52sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E53sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E54sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E56sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004151sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004152sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004153sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004154sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004156sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004149sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000414Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000414Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E48sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E49sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E4Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E4Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003E50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003E54sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003154sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B62sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B63sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B64sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B65sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005460sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005464sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A48sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A49sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005548sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005549sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000554Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000554Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005551sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005552sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005554sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005D57sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005145sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005146sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005147sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "BC121DB1686292DF2F5892D");
