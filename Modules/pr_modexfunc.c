//Exporting function

#include<linux/module.h>
#include<linux/init.h>

static int deeps_counter;

int set_counter(int a)
{
	deeps_counter = a;
	return 0;
}

int get_counter(void)
{
	return deeps_counter;
}

int init_module(void)
{
	pr_info("%s : Initializing Counter\n", __func__);
	deeps_counter = 500;
	return 0;
}

void cleanup_module(void)
{
	pr_info("%s : Value of deeps counter= %d\n", __func__, deeps_counter);
}

EXPORT_SYMBOL_GPL(set_counter);
EXPORT_SYMBOL_GPL(get_counter);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Exporting Function");
MODULE_AUTHOR("Deeps");
