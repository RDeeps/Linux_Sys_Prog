//To access to real time clock values of the pc

#include<unistd.h>
#include<sys/io.h>
#include<stdio.h>

#define ADDRESS_REG 		0x70
#define DATA_REG 		0x71
#define ADDRESS_REG_MASK 	0xE0

#define  SECOND         0x00  //Second       (00..59) 
#define  MINUTE         0x02  //Minute       (00..59)
#define  HOUR           0x04  //Hour         (00..23) 
#define  DAY_IN_WEEK    0x06  //Day of week  (01..0DAY)
#define  DAY            0x07  //Day          (01..31) 
#define  MONTH          0x08  //Month        (01..12) 
#define  YEAR           0x09 // Year         (00..99)

int main()
{
	int res, a, b;

	res = ioperm(ADDRESS_REG, 0x04, 1);
	printf("res= %d\n", res);

	
	outb(HOUR, ADDRESS_REG);
	printf("hour= %x\n", inb(DATA_REG));

	outb(MINUTE, ADDRESS_REG);
	printf("minute= %x\n", inb(DATA_REG));
	
	outb(SECOND, ADDRESS_REG);
	printf("second = %x\n", inb(DATA_REG));

}
