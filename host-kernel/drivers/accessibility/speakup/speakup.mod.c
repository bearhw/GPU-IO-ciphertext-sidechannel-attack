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

SYMBOL_CRC(speakup_start_ttys, 0xbbd15a51, "_gpl");
SYMBOL_CRC(synth_buffer_empty, 0x41a160e5, "_gpl");
SYMBOL_CRC(synth_buffer_getc, 0x84dad068, "_gpl");
SYMBOL_CRC(synth_buffer_peek, 0xaadb0612, "_gpl");
SYMBOL_CRC(synth_buffer_skip_nonlatin1, 0x76d40046, "_gpl");
SYMBOL_CRC(synth_buffer_clear, 0x4449e1dd, "_gpl");
SYMBOL_CRC(spk_var_show, 0x0810dd5c, "_gpl");
SYMBOL_CRC(spk_var_store, 0x47aba2b1, "_gpl");
SYMBOL_CRC(spk_ttyio_ops, 0x0eada697, "_gpl");
SYMBOL_CRC(spk_ttyio_synth_probe, 0x19f17e10, "_gpl");
SYMBOL_CRC(spk_ttyio_release, 0x10492de0, "_gpl");
SYMBOL_CRC(spk_ttyio_synth_immediate, 0x1ea2033a, "_gpl");
SYMBOL_CRC(speakup_info, 0xd93829dd, "_gpl");
SYMBOL_CRC(spk_do_catch_up, 0x1991dd20, "_gpl");
SYMBOL_CRC(spk_do_catch_up_unicode, 0xc98298ec, "_gpl");
SYMBOL_CRC(spk_synth_flush, 0x8561d071, "_gpl");
SYMBOL_CRC(spk_synth_get_index, 0x01daf7a4, "_gpl");
SYMBOL_CRC(spk_synth_is_alive_nop, 0xd8a38626, "_gpl");
SYMBOL_CRC(spk_synth_is_alive_restart, 0xb5a3d79e, "_gpl");
SYMBOL_CRC(synth_printf, 0xe194d0ef, "_gpl");
SYMBOL_CRC(synth_putwc, 0x466f5eb7, "_gpl");
SYMBOL_CRC(synth_putwc_s, 0x8fe0db01, "_gpl");
SYMBOL_CRC(synth_putws, 0x1e39eb14, "_gpl");
SYMBOL_CRC(synth_putws_s, 0xc319c604, "_gpl");
SYMBOL_CRC(synth_request_region, 0x8c82dfca, "_gpl");
SYMBOL_CRC(synth_release_region, 0xd8fd86cf, "_gpl");
SYMBOL_CRC(synth_add, 0xf9993d87, "_gpl");
SYMBOL_CRC(synth_remove, 0x2ab6f6f9, "_gpl");
SYMBOL_CRC(synth_current, 0xa0d7b21e, "_gpl");
SYMBOL_CRC(speakup_event, 0xb734cb9d, "_gpl");
SYMBOL_CRC(spk_get_var, 0xc6a06d16, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x3da716bf, "input_allocate_device" },
	{ 0x93e6fd06, "paste_selection" },
	{ 0xe914e41e, "strcpy" },
	{ 0x7d819d8d, "tty_set_termios" },
	{ 0xbf041102, "register_vt_notifier" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x3aa0ab72, "tty_lock" },
	{ 0x13110126, "request_resource" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x9f63718c, "tty_register_ldisc" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xca454a34, "vt_get_leds" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xe7fe12cf, "tty_kopen_exclusive" },
	{ 0x9ed2b1f3, "tty_flip_buffer_push" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xf83864d9, "inverse_translate" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x1e91687d, "tty_kref_put" },
	{ 0x96848186, "scnprintf" },
	{ 0xaf468156, "set_user_nice" },
	{ 0x4e6e8ea7, "fg_console" },
	{ 0xb71589f0, "skip_spaces" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x84ddca63, "input_unregister_device" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xb1ce1fca, "tty_kclose" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x148653, "vsnprintf" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb01b1514, "tty_write_room" },
	{ 0x17ef5814, "stop_tty" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x7f24de73, "jiffies_to_usecs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe42878c7, "input_free_device" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xaddf64b0, "input_register_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x64bbc288, "string_unescape" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb3f548ad, "kmemdup_nul" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x9166fada, "strncpy" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x744e71e7, "tty_ldisc_flush" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x11089ac7, "_ctype" },
	{ 0x9ed554b3, "unregister_keyboard_notifier" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xb11d9000, "tty_dev_name_to_number" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x4708008a, "misc_register" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xc2261e62, "input_event" },
	{ 0xc631580a, "console_unlock" },
	{ 0x22b325d5, "kd_mksound" },
	{ 0xd4dc6d88, "vc_cons" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x264c5f6c, "tty_unregister_ldisc" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x55417264, "unregister_vt_notifier" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x96554810, "register_keyboard_notifier" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x38374815, "clear_selection" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x7ec07e28, "set_selection_kernel" },
	{ 0x897193d6, "tty_set_ldisc" },
	{ 0x4e8c4a85, "screen_pos" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc5e74216, "release_resource" },
	{ 0x754d539c, "strlen" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x349cba85, "strchr" },
	{ 0x8e6c160b, "start_tty" },
	{ 0x21ef374c, "try_wait_for_completion" },
	{ 0xab1ac88e, "tty_unlock" },
	{ 0x53b954a2, "up_read" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x7c181721, "kobject_put" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "88E33AF9E0F436F24F167EF");
