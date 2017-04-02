//Accessing function exported by other module realtime

#include<linux/module.h>
#include<linux/init.h>


int (*ptr)(void);
void (*fptr)(int);

int init_module(void)
{
	int counter;
	fptr = __symbol_get("set_counter");
	if(fptr)
	{
		counter = 400;
		(fptr)(counter);	// Calling function
	}
	else
	{
		pr_err("%s : Symbol not available\n", __func__);
	}
	
	ptr = __symbol_get("get_counter");
	if(ptr)
	{
		counter = (ptr)();	// Calling function
		pr_info("%s : value of counter = %d\n", __func__, counter);
		__symbol_put("get_counter");
	}
	else
	{
		pr_err("%s : Symbol not available\n", __func__);
	}
	return 0;
}

void cleanup_module(void)
{
	pr_info("%s : Module Removed\n", __func__);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Accessing exported function");
MODULE_AUTHOR("Deeps");
