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
	{ 0x96848186, "scnprintf" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd28544d1, "pwm_apply_state" },
	{ 0x2085b347, "devm_pwm_get" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x6d97917a, "devm_regulator_get_optional" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x7bd671b3, "acpi_match_device" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:XMCC0001:*");
MODULE_ALIAS("i2c:lp8550");
MODULE_ALIAS("i2c:lp8551");
MODULE_ALIAS("i2c:lp8552");
MODULE_ALIAS("i2c:lp8553");
MODULE_ALIAS("i2c:lp8555");
MODULE_ALIAS("i2c:lp8556");
MODULE_ALIAS("i2c:lp8557");
MODULE_ALIAS("of:N*T*Cti,lp8550");
MODULE_ALIAS("of:N*T*Cti,lp8550C*");
MODULE_ALIAS("of:N*T*Cti,lp8551");
MODULE_ALIAS("of:N*T*Cti,lp8551C*");
MODULE_ALIAS("of:N*T*Cti,lp8552");
MODULE_ALIAS("of:N*T*Cti,lp8552C*");
MODULE_ALIAS("of:N*T*Cti,lp8553");
MODULE_ALIAS("of:N*T*Cti,lp8553C*");
MODULE_ALIAS("of:N*T*Cti,lp8555");
MODULE_ALIAS("of:N*T*Cti,lp8555C*");
MODULE_ALIAS("of:N*T*Cti,lp8556");
MODULE_ALIAS("of:N*T*Cti,lp8556C*");
MODULE_ALIAS("of:N*T*Cti,lp8557");
MODULE_ALIAS("of:N*T*Cti,lp8557C*");

MODULE_INFO(srcversion, "B1B0E7BD9A2FF1BD26D1245");
