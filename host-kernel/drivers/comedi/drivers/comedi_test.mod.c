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
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x2587f789, "_dev_info" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xf1969a8e, "__usecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xb8f1eb1f, "comedi_nscans_left" },
	{ 0xe741a6bb, "comedi_buf_read_alloc" },
	{ 0x6d840572, "comedi_buf_read_free" },
	{ 0x4ea2cf27, "comedi_inc_scan_progress" },
	{ 0x369058ca, "comedi_buf_read_samples" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x24d273d1, "add_timer" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6ed165e0, "comedi_nsamples_left" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x1f1f589c, "device_create" },
	{ 0xa1ed73ab, "comedi_auto_config" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x5575ac06, "comedi_auto_unconfig" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "391336BBC51BE6AEEF4C1EC");
