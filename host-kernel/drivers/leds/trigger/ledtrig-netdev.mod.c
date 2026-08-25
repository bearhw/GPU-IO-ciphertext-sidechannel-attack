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
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x37a0cba, "kfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x43744e2f, "led_set_brightness" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x69acdf38, "memcpy" },
	{ 0x7c6024bd, "init_net" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x25659fc1, "dev_get_stats" },
	{ 0x8a381ba4, "led_stop_software_blink" },
	{ 0xeef4283a, "led_blink_set_oneshot" },
	{ 0x57f2ad3d, "led_trigger_register" },
	{ 0xea1972a0, "led_trigger_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1C44EC413586473C4054D4D");
