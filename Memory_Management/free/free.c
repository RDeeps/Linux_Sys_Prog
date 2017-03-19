// Freeing dynamic memory using free()

#include<stdio.h>
#include<stdlib.h>

void print_chars(int n, char c);

int main(void)
{

	print_chars(5, 'X');
	return 0;
}

void print_chars(int n, char c)
{
	int i;
	//printf("%c\n", c);	
	for (i =0; i<n; i++){
		char *s;
		int j;
		
		/* Allocate and zero an i+2 element array
		 * of chars. Note that 'sizeof(char)'
		 * is always 1.
		 */
	
		s = calloc(i+2, sizeof(char));
		if(!s){
			perror("calloc");
			break;
		}
		
		for(j=0; j <i+1; j++)
			s[j] = c;
		
		printf("%s\n", s);
		
		free(s);		// All done, free back the memory
	}
}
