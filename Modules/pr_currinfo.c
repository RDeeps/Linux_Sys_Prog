// Getting current process info

#include<linux/module.h>
#include<linux/init.h>
#include<asm/current.h>
#include<linux/sched.h>

int init_module(void)
{
	pr_info("Caller process name: %s\n", current->comm);
	pr_info("Caller pid: %ld\n", (long int)current->pid);
	pr_info("Stack start address: %p\n", current->stack);
	return 0;
}

void cleanup_module(void)
{
	pr_info("Caller process name: %s\n", current->comm);
	pr_info("Caller pid: %ld\n", (long int)current->pid);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Getting current process info");
MODULE_AUTHOR("Deeps");
