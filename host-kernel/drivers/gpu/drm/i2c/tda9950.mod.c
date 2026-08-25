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
	{ 0x829f24af, "cec_notifier_cec_adap_unregister" },
	{ 0x9697bfc0, "cec_unregister_adapter" },
	{ 0xdc9b6a1, "cec_delete_adapter" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x69acdf38, "memcpy" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf9a482f9, "msleep" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x17f9a366, "cec_transmit_done_ts" },
	{ 0x60241a95, "cec_received_msg_ts" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2aed0676, "cec_allocate_adapter" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x2587f789, "_dev_info" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x994ff8f2, "cec_notifier_cec_adap_register" },
	{ 0x4403b369, "cec_register_adapter" },
	{ 0x79bdf3e9, "devm_remove_action" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cec");

MODULE_ALIAS("i2c:tda9950");

MODULE_INFO(srcversion, "61ADD718A2DCD16A1CD1C7A");
