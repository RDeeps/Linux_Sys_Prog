// Allocating anonymous memory (mem > 128KB); allocated memory will be zeroed identical to calloc() call

#include<stdio.h>
#include<sys/mman.h>

int main(void)
{
	void *p;
	int ret ;

	p = mmap(NULL,				// do not care where
		  512 * 1024, 			// 512KB
		  PROT_READ | PROT_WRITE,	// read/write
		  MAP_ANONYMOUS | MAP_PRIVATE,	// anonymous, private
		  -1,				// fd(ignored)
		  0);				// offset(ignored)

	if(p == MAP_FAILED)
		perror("mmap");
	else
		printf("Address of allocated memory block : %p\n", p);

	
	ret = munmap(p, 512 * 1024);		// returning memory back to system
	if(ret)
		perror("munmap"); 

}
