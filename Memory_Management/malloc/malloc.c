// Allocating dynamic memory using malloc

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

	char *p;							// to hold the address of allocated memory location

	p = malloc(2048);						// allocate 2KB of memory
	if(!p)
		perror("malloc");
	else	
		//strcpy(p, "Deepak");
		//printf("String: %s, Address: %u\n", p, p);		
		printf("Address of memory allocated: %u\n", p);		// the address stored in 'p' will be typecated to unsigned lont int
	
	free(p);
	return 0;
}
