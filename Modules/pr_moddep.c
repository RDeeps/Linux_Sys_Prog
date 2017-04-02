//Importing variable exported by other module

#include<linux/module.h>
#include<linux/init.h>

extern int deeps_counter;

int myinit(void)
{
	deeps_counter = 100;
	pr_info("%s : Initializing imported variable", __func__);
	dump_stack();
	return 0;
}

void myexit(void)
{

}

module_init(myinit);
module_exit(myexit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Importing variable exported by other module");
MODULE_AUTHOR("Deeps");
