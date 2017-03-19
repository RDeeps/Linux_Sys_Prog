// Resizing allocated memory using realloc

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	struct map{
		int subject;
		int marks;
	};

	struct map *p;

	/* Allocate memory for 2 map structures */
	p = calloc(2, sizeof(struct map));
	if(!p){
		perror("calloc");
		return -1;
	}
	printf("Memory is allocated for 2 map structure\n");
	getchar();

	struct map *r;

	/* we now need memory for only one map */
	r = realloc(p, sizeof(struct map));
	if(!r){
		// note that p is still valid
		perror("realloc");
		return -1;
	}
	printf("Now the memory is shrinked for only 1 map structure\n");
	getchar();
	
	free(r);

}
