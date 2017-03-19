// Wrapper function xmalloc() which terminates on failure and prints the message


#include<stdlib.h>
#include<stdio.h>
void * xmalloc(size_t size);

int main(void)
{

	int addr;

	addr = xmalloc(512);		//allocating 512 bytes of memory
	
	printf("Address: %u\n", addr);

}

void * xmalloc(size_t size){

	void *p;
	
	p = malloc(size);
	if(!p)
	{
		perror("xmalloc:");
		exit(EXIT_FAILURE);
	}
	
	return p;
}
