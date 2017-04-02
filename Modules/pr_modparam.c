//Dynamically Changing Module Parameters 

#include<linux/module.h>
#include<linux/init.h>
#include<linux/moduleparam.h>

static int irq;			// single integer
static int base_port[5];	// array of integers
static char *name = 0;		// string

module_param(irq, int, 0644);
MODULE_PARM_DESC(irq, "Integer");

module_param(name, charp, 0644);
MODULE_PARM_DESC(name, "Device Name");

module_param_array(base_port, int, NULL, 0);
MODULE_PARM_DESC(base_port, "Int. base port");

int init_module(void)
{
	int i;
	pr_info("IRQ = %d, Device Name: %s\n", irq, name);
	for(i = 0; i<5; ++i)
		pr_info("Base port %d = %x\n", i, base_port[i]);
	return 0;
}

void cleanup_module(void)
{	
	int i;
	pr_info("Unloading...\n");
	pr_info("IRQ = %d, Device Name: %s\n", irq, name);
        for(i =0; i<5; ++i)
                pr_info("Base port %d = %x\n", i, base_port[i]);

}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Dynamically changing module parameters");
MODULE_AUTHOR("Deeps");

