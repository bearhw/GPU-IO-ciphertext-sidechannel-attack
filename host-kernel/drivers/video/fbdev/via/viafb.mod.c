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

SYMBOL_CRC(viafb_find_i2c_adapter, 0x8af7c456, "_gpl");
SYMBOL_CRC(viafb_irq_enable, 0xcd538333, "_gpl");
SYMBOL_CRC(viafb_irq_disable, 0xb4606f8d, "_gpl");
SYMBOL_CRC(viafb_request_dma, 0x30cc9311, "_gpl");
SYMBOL_CRC(viafb_release_dma, 0xcaefb732, "_gpl");
SYMBOL_CRC(viafb_dma_copy_out_sg, 0x0e1cee08, "_gpl");
SYMBOL_CRC(viafb_pm_register, 0xb4f863e6, "_gpl");
SYMBOL_CRC(viafb_pm_unregister, 0x31469540, "_gpl");
SYMBOL_CRC(viafb_gpio_lookup, 0xfff2dfd2, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x60eda3b5, "proc_create" },
	{ 0xa6257a2f, "complete" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0x37a0cba, "kfree" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc07b0863, "fb_destroy_modedb" },
	{ 0x397edd5, "fb_edid_to_monspecs" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x5a921311, "strncmp" },
	{ 0xa906274e, "seq_putc" },
	{ 0x47155238, "platform_device_add" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc631580a, "console_unlock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x6513a3fa, "fb_get_color_depth" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x87b8798d, "sg_next" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x391de184, "seq_puts" },
	{ 0xbb2b861a, "single_release" },
	{ 0xa6aa1711, "proc_create_single_data" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xb82ba28c, "single_open" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i2c-algo-bit");

MODULE_ALIAS("pci:v00001106d00003122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00007205sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003108sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003118sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003344sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003157sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003225sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003230sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003343sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003371sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00001122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00005122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00007122sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "A4EB959CB4E87372D45467A");
