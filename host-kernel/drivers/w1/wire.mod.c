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

SYMBOL_CRC(w1_add_master_device, 0x0cf9384e, "");
SYMBOL_CRC(w1_remove_master_device, 0xf2a22dc6, "");
SYMBOL_CRC(w1_register_family, 0x31aa6211, "");
SYMBOL_CRC(w1_unregister_family, 0x56f5a4a1, "");
SYMBOL_CRC(w1_touch_bit, 0x6ca43304, "_gpl");
SYMBOL_CRC(w1_write_8, 0xfccee5f1, "_gpl");
SYMBOL_CRC(w1_triplet, 0xfe23200a, "_gpl");
SYMBOL_CRC(w1_read_8, 0x94ea671e, "_gpl");
SYMBOL_CRC(w1_write_block, 0x0e5cf19c, "_gpl");
SYMBOL_CRC(w1_touch_block, 0xab9eae4f, "_gpl");
SYMBOL_CRC(w1_read_block, 0xd9d87f1c, "_gpl");
SYMBOL_CRC(w1_reset_bus, 0x58c0c366, "_gpl");
SYMBOL_CRC(w1_calc_crc8, 0x63757e92, "_gpl");
SYMBOL_CRC(w1_reset_select_slave, 0x5c945c57, "_gpl");
SYMBOL_CRC(w1_reset_resume_command, 0xd18e830d, "_gpl");
SYMBOL_CRC(w1_next_pullup, 0xc5aa4706, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xd1606395, "sysfs_remove_groups" },
	{ 0x593cec66, "sysfs_create_groups" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dd9d14d, "cn_netlink_send_mult" },
	{ 0x3197c4e3, "put_device" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x2587f789, "_dev_info" },
	{ 0x61e876a5, "flush_signals" },
	{ 0xa6c4041, "cn_netlink_send" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x6297f232, "hwmon_device_register_with_info" },
	{ 0xf1969a8e, "__usecs_to_jiffies" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x422066d2, "device_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x7483e13, "cn_del_callback" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0x7be82b14, "hwmon_device_unregister" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x77346fe8, "cn_add_callback" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "63C56DB5BB3AD7563B538DE");
