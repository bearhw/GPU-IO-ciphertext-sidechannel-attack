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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x37a0cba, "kfree" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x92997ed8, "_printk" },
	{ 0xcdc90c64, "matroxfb_var2my" },
	{ 0x668b19a1, "down_read" },
	{ 0x53b954a2, "up_read" },
	{ 0xcd594daf, "DAC1064_global_init" },
	{ 0x64188710, "DAC1064_global_restore" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xb861f595, "matroxfb_wait_for_sync" },
	{ 0xa3b2aa, "matroxfb_enable_irq" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xa4bd5528, "fb_set_var" },
	{ 0xab781570, "fb_get_options" },
	{ 0xc27638a0, "matroxfb_register_driver" },
	{ 0x6690493, "matroxfb_unregister_driver" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "matroxfb_misc,matroxfb_DAC1064,matroxfb_base");


MODULE_INFO(srcversion, "60794CFD6FEB94EF63F16D3");
