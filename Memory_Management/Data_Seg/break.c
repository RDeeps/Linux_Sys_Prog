// Obtaining current break point using sbrk()

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	void  *brkpnt;
	brkpnt = sbrk(0);
	printf("Current break point: %p\n", brkpnt);
	malloc(10);
	brkpnt = sbrk(0);
	printf("Break point after allocating 10 byets:%p\n", brkpnt); 

}
