// calloc wrapper function identical to malloc, but memory is zeroed

#include<stdlib.h>
#include<stdio.h>

void * malloc0(size_t size);

int main(void)
{
	int addr;

	addr = malloc0(512);		// Allocating 512 bytes

	printf("Address pointer: %u\n", addr);
}

void * malloc0(size_t size)
{
	void *p;
	
	p = calloc(1, size);		
	if(!p){
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	
	return p;
}
