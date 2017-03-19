// Allocating aligned memory using POSIX function

#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	char *buf;
	int ret;
	
	// Allocate 1KB along 256-byte memory
	ret = posix_memalign(&buf, 256, 1000);
	if(ret){
		fprintf(stderr, "posix_memalign: %s\n", strerror(ret));
		return -1;
	}
	
	free(buf);

}
