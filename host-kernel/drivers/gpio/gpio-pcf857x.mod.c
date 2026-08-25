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
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x34b8e6d6, "i2c_smbus_read_byte" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x8ed93f5d, "gpiochip_disable_irq" },
	{ 0xa7bacb0b, "gpiochip_enable_irq" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7447bbf1, "i2c_smbus_write_byte" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x764d9ae7, "__irq_resolve_mapping" },
	{ 0x549525ef, "handle_nested_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xd84b9a76, "handle_level_irq" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x5986a03b, "gpiochip_irq_reqres" },
	{ 0xcd995a5b, "gpiochip_irq_relres" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:pcf8574");
MODULE_ALIAS("i2c:pcf8574a");
MODULE_ALIAS("i2c:pca8574");
MODULE_ALIAS("i2c:pca9670");
MODULE_ALIAS("i2c:pca9672");
MODULE_ALIAS("i2c:pca9674");
MODULE_ALIAS("i2c:pcf8575");
MODULE_ALIAS("i2c:pca8575");
MODULE_ALIAS("i2c:pca9671");
MODULE_ALIAS("i2c:pca9673");
MODULE_ALIAS("i2c:pca9675");
MODULE_ALIAS("i2c:max7328");
MODULE_ALIAS("i2c:max7329");

MODULE_INFO(srcversion, "7151AEAB23FA9529F9FB04F");
