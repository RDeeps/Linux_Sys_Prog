/* Controlling anonymous mapping threshold
 * using M_MMAP_THRESHOLD flag of mallopt()
 * default value is 128 * 1024 
 * change it to 64 * 1024
 */

#include<stdio.h>
#include<malloc.h>
#include<sys/mman.h>


int main(void)
{
	int ret;
	void *p;

	ret = mallopt(M_MMAP_THRESHOLD, 64 * 1024);
	if(!ret)
		fprintf(stderr, "mallopt failed!\n");

	// Now we can allocate anonymous block of memory above 64KB using mmap
	 p= mmap(NULL,
		 128 * 1024,
		 PROT_READ | PROT_WRITE,
		 MAP_ANONYMOUS | MAP_PRIVATE,
		 -1,
		 0);
	if(p == MAP_FAILED)
		perror("mmap");
	else
		printf("128KB memory is allocated, now deallocate the same\n");
		getchar();
	
	// Deallocate the anonymous block using munmap
	if(munmap(p, 128 * 1024))
		perror("munmap");

}
