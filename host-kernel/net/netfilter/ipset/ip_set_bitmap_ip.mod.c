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
	{ 0x7924b6de, "ip_set_hostmask_map" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe24187de, "ip_set_extensions" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x5922420e, "ip_set_init_comment" },
	{ 0xd1c17ba8, "ip_set_match_extensions" },
	{ 0xfb578fc5, "memset" },
	{ 0x397f6231, "ip_set_free" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x24d273d1, "add_timer" },
	{ 0xa293f8a6, "ip_set_get_ipaddr4" },
	{ 0x67dd76de, "ip_set_get_extensions" },
	{ 0x8520a781, "nla_put" },
	{ 0x800473f, "__cond_resched" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9641c5c6, "ip_set_put_extensions" },
	{ 0x8202224c, "ip_set_elem_len" },
	{ 0xf3b4d4ae, "ip_set_alloc" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x51fa242b, "ip_set_put_flags" },
	{ 0x5328c5ae, "ip_set_type_register" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x2276f00e, "ip_set_type_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_set");


MODULE_INFO(srcversion, "CA84A0103F6F1CEA1CD5C78");
