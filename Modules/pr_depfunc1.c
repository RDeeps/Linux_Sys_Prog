//Accessing function exported by other module

#include<linux/module.h>
#include<linux/init.h>

extern void set_counter(int);
extern int get_counter(void);

int init_module(void)
{
	int a;
	set_counter(200);
	a = get_counter();
	pr_info("%s: counter set to = %d\n", __func__, a);
}

void cleanup_module(void)
{
	pr_info("%s : Dependent module removed\n", __func__);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Accessing exported function");
MODULE_AUTHOR("Deeps");
