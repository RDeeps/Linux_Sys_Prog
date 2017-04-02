// First kernel module

#include<linux/module.h>

int init_module(void)
{
	printk("%s : Module Inserted\n", __func__);
	return 0;
}

void cleanup_module(void)
{
	printk("%s : Module Removed\n", __func__);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("First Kernel Module");
MODULE_AUTHOR("Deeps");

