// Accessing exported variable on runtime

#include<linux/module.h>
#include<linux/init.h>

static int *ptr;

int init_module(void)
{
	
	printk("%s : Module Inserted\n", __func__);
	
	ptr = (int*) __symbol_get("deeps_counter");
	
	if(ptr)
	{
		*ptr = 800;
		__symbol_put("deeps_counter");
		return 0;
	}
	else
	{
		pr_err("%s : Symbol not available\n", __func__);
	}
	return 0;
}

void cleanup_module(void)
{
	printk("%s : Module Removed\n", __func__);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Accessing exportd variable on runtime");
MODULE_AUTHOR("Deeps");
