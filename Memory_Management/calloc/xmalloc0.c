// Wrapper function xmalloc0() using calloc which terminates on failure and prints the message


#include<stdlib.h>
#include<stdio.h>
void * xmalloc0(size_t size);

int main(void)
{

	int addr;

	addr = xmalloc0(512);		//allocating 512 bytes of memory
	
	printf("Address: %u\n", addr);

}

void * xmalloc0(size_t size){

	void *p;

	p = calloc(1, size);
	if(!p)
	{
		perror("xmalloc0:");
		exit(EXIT_FAILURE);
	}
	
	return p;
}
