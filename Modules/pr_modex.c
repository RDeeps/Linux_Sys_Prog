//Exporting variable

#include<linux/module.h>
#include<linux/init.h>

int deeps_counter;

int myinit(void)
{
	printk("%s : Initializing Counter\n", __func__);
	deeps_counter = 500;
	return 0;
}

void myexit(void)
{
	printk(KERN_INFO "%s : value of counter %d \n", __func__, deeps_counter);
}

module_init(myinit);
module_exit(myexit);

EXPORT_SYMBOL_GPL(deeps_counter);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Exporting Variable");
MODULE_AUTHOR("Deeps");
