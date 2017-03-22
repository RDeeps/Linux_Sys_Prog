// Setting real time clock values

#include<unistd.h>
#include<sys/io.h>
#include<stdio.h>

#define ADDRESS_REG	0x70
#define DATA_REG 	0x71

unsigned char getval(int what){
	outb(what, ADDRESS_REG);
	return(inb(DATA_REG));
}


int main()
{
	int res, a, b;

	res = ioperm(ADDRESS_REG, 0x04, 1);
	
	printf("year :%x\n", getval(9)); //year
	printf("month:%x\n", getval(8)); //month
	printf("day :%x\n", getval(7)); //day
	printf("day of week: %x\n", getval(6)); //day in week
	return 0;
}
