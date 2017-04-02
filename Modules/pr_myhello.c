// To test stack_dump function - to dump user stack

#include<linux/module.h>		//kmap interface
#include<linux/init.h>

void func(void)
{
	printk("%s : Hello World\n", __func__);
}

int init_module(void)
{
	printk("%s : Module Inserted\n", __func__);
	dump_stack();
	return 0;	
}

void cleanup_module(void)
{
	printk("%s : Module Removed\n", __func__);
	dump_stack();
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Dumping user stack");
MODULE_AUTHOR("Deeps");
