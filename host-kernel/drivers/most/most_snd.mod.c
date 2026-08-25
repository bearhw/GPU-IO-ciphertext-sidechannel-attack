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
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0x336e0c41, "snd_card_free" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x68a24153, "snd_pcm_format_physical_width" },
	{ 0x4f816e9b, "snd_pcm_format_big_endian" },
	{ 0x69acdf38, "memcpy" },
	{ 0x796322e0, "most_stop_channel" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xe268024a, "most_start_channel" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x92997ed8, "_printk" },
	{ 0x1aa27e97, "snd_card_register" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x800473f, "__cond_resched" },
	{ 0x624e5609, "most_get_mbo" },
	{ 0xfb578fc5, "memset" },
	{ 0x693294db, "most_submit_mbo" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x5056d77f, "snd_pcm_period_elapsed" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa916b694, "strnlen" },
	{ 0xdd64e639, "strscpy" },
	{ 0x85df9b6c, "strsep" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x5ec82f95, "snd_card_new" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xbb6284a7, "snd_pcm_new" },
	{ 0xdb9bf988, "snd_pcm_set_ops" },
	{ 0x3f1179aa, "snd_pcm_set_managed_buffer_all" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x4e66de1e, "most_put_mbo" },
	{ 0x48cfb9b7, "most_register_component" },
	{ 0x5bbab859, "most_register_configfs_subsys" },
	{ 0xcbd95f6c, "most_deregister_component" },
	{ 0x46bfdd77, "most_deregister_configfs_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "snd,snd-pcm,most_core");


MODULE_INFO(srcversion, "9871B688F7E88C1E6B99275");
