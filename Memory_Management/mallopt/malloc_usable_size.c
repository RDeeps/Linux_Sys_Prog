/* Advance memory allocation 
 * Fine tuning with malloc_usable_size() & malloc_trim()
 */

#include<stdio.h>
#include<malloc.h>
#include<unistd.h>


int main(void)
{
	size_t len = 21;
	size_t size;
	char *buf;
	
	buf = malloc(len);
	if(!buf){
		perror("malloc");
		return -1;
	}
	
	// Get usable bytes
	size = malloc_usable_size(buf);

	printf("Requested bytes: %d & Bytes allocated by system: %d\n", len, size);
	getchar();
	
	/* Return freeable memory to kernel, 
	 * shrinks the data segment as much as possible
	 */
	printf("heap break before trim:%p\n", sbrk(0));
	
	if(malloc_trim(1)!= 1){
		perror("malloc_trim");
		return -1;
	}

	getchar();
	size = malloc_usable_size(buf);
	printf("heap break after trim:%p\n", sbrk(0));
	

	free(buf);
}
