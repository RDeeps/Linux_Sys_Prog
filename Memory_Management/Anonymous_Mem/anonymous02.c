/* Anonymous memory mapping in BSD systems that do not have MAP_ANONYMOUS flag.
 * Mapping /dev/zero
 */

#include<stdio.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<fcntl.h>

int main(void)
{
	void *p;
	int fd, ret;

	// open file for reading and writing
	fd = open("/dev/zero", O_RDWR);	
	if(fd<0){
		perror("open");
		return -1;
	}
	
	// map [0, page size] of /dev/zero
	p = mmap(NULL,				// do not care where
		 getpagesize(),			// map one page
		 PROT_READ | PROT_WRITE,		// map read and write
		 MAP_PRIVATE,			// private mapping
		 fd,					// map /dev/zero
		 0);					// offset (ignored)

	if(p == MAP_FAILED){
		perror("mmap");
		if(close(fd))
			perror("close");
		return -1;
	}

	// close /dev/zero, no longer needed
	if(close(fd))
		perror("close");
	
	
	// p points to one page memory, we can use it
	printf("Address: %p\n", p);
	
	
	// Memory unmap using munmap()
	ret = munmap(p, getpagesize());
	if(ret)
		perror("munmap");
}
