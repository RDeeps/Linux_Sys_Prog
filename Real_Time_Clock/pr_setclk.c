// Setting real time clock values

#include<unistd.h>
#include<sys/io.h>
#include<stdio.h>

#define ADDRESS_REG	0x70
#define DATA_REG 	0x71

void setval(int what, unsigned val){
	outb(what, ADDRESS_REG);
	outb(val, DATA_REG);

}
int main()
{
	int res, a, b;

	res = ioperm(ADDRESS_REG, 0x04, 1);
	
	setval(4, 0x07); //hour
	setval(2, 0x23); //minute
	setval(0, 0x00); //second
	return 0;
}
