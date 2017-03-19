/* Controlling program should respond various errors 
 * using M_CHECK_ACTION parameter of mallopt()
 * call mallopt() before executing any memory allcoation calls
 */

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	void *p;
	int ret;
	
	ret = mallopt(M_CHECK_ACTION, 3);		// value can be 0-7, check man page of mallopt()
	if(ret != 1){
		perror("mallopt");
		exit(EXIT_FAILURE);
	}

	p = malloc(1024);
	if(!p){
		perror("malloc");
		return -1;
	}
	printf("Address of allocated memory: %p\n", p);
	getchar();	
	
	free(p);
	printf("%s: returned from first free() call\n", __func__);
	
	free(p);
	printf("%s: returned from second free() call\n", __func__);
	
	exit(EXIT_FAILURE);
	
		
}
