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
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7a70b72e, "qdisc_watchdog_cancel" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x4cadb74b, "qdisc_watchdog_init_clockid" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xca9360b5, "rb_next" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x9953813d, "rtnl_kfree_skbs" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x56470118, "__warn_printk" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xf29a39af, "sock_queue_err_skb" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xe401049, "qdisc_watchdog_schedule_range_ns" },
	{ 0xd01cc0c4, "kfree_skb_list_reason" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "741D6D29A86E928B15D94D0");
