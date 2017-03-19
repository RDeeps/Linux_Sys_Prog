// Allocating memory enough to hold the structure

#include<stdio.h>
#include<stdlib.h>

int main(void)
{

	struct course {
		int marks;
   		char subject[30];
	};
	
	struct course *x;

	x = malloc(sizeof(struct course));
	if(!x)
		perror("malloc");
	else
		printf("Address: %u\n", x);

	free(x);
	return 0;
}
