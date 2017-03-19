/* Memory statics using malloc_stats()
 * this function prints the statistics to stderr
 * to redirect the output to stdout use: executable > 2 > 1
 */

#include<malloc.h>
#include<stdlib.h>

int main(void)
{
	char *buf;
	
	buf = malloc(100);
	if(!buf){
		perror("malloc");
		return -1;
	}

	fprintf(stderr, "\nStatistics after allocating memory:\n");
	malloc_stats();

	free(buf);

	fprintf(stderr, "\nStatistics after allocated memory is returned:\n");
	malloc_stats();

}
