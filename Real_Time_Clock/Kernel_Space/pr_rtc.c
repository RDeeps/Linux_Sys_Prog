#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/delay.h>
#include"rtc.h"
#include<asm/io.h>


static unsigned char getrtc(unsigned char addr)
{
	outb(addr, ADDRESS_REG);
	return(inb(DATA_REG));	
}

/*
staic void setrtc(unsinged char addr, unsigned char val)
{
	outb(addr, ADDRESS_REG);
	outb(val, DATA_REG);
}
*/

static int __init rtc_init(void)
{
	pr_info("rtc_module loaded\n");

	pr_info("hr:mm:ss : %x:%x:%x\n", getrtc(HOUR), getrtc(MINUTE), getrtc(SECOND));
	pr_info("DD/MM/YY : %x/%x/%x\n", getrtc(DAY), getrtc(MONTH), getrtc(YEAR));

	return 0;
}

static void __exit rtc_exit(void)
{
	
	pr_info("rtc module unloaded\n");

}

module_init(rtc_init);
module_exit(rtc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Getting RTC Values");
MODULE_AUTHOR("RDeeps");
