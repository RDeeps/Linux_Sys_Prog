// Allocating dynamic memory using calloc

#include<stdlib.h>
#include<stdio.h>

int main(void)
{

	int *x, *y;

	x = malloc(50 * sizeof(int));
	if(!x){
		perror("malloc");		/* Allocating memory dynamically to 50 members, 
						 * but allocated memory will contain garbage value
						 */
		return -1;
	}

	y = calloc(50, sizeof(int));
	if(!y){
		perror("calloc");		/* calloc() provides an advantage over malloc all. 
                                                 * memory allocated contains all 0's
                                                 */
		return -1;
	}

	free(x);
	free(y);
	
}
