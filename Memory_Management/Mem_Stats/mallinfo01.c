/* Obtaining statics related to the memory allocation
 * A call to mallinfo() returns the statics in mallinfo structure.
 * The structure is returned by value not pointer
 */

#include<malloc.h>
#include<stdio.h>

int main(void)
{
	struct mallinfo m;

	m = mallinfo();
	
	printf("Size of data segment used by malloc: 		%10d\n", m.arena);
	printf("Number of free chunks:				%10d\n", m.ordblks);
	printf("Number of fastbins:	                        %10d\n", m.smblks);
	printf("Number of anonymous mappings:                   %10d\n", m.hblks);
	printf("Size of anonymous mappings:                     %10d\n", m.hblkhd);
	printf("Maximum total allocated size:                   %10d\n", m.usmblks);
	printf("Size of available fastbins                      %10d\n", m.fsmblks);
	printf("Size of total allocated space:                  %10d\n", m.uordblks);
	printf("Size of available chunks:                       %10d\n", m.fordblks);
	printf("Size of trimmable space:                        %10d\n", m.keepcost);
}

