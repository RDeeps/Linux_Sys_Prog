// Allocating aligned memory using BSD and SunOS interface (valloc() & memalign())

#include<stdlib.h>
#include<malloc.h>

int main(void)
{
	struct ship{
		char *captain_name;
		int no_of_members; 
	}*pirate, *hms;

	pirate = valloc(sizeof (struct ship));
	if(!pirate){
		perror("valloc");
		return -1;
	}

	hms = memalign(getpagesize(), sizeof(struct ship));
	if(!hms){
		perror("memalign");
		return -1;
	}

	printf("Memory is allocated to hold struct ship and aligned along a page boundary\n");
	
	free(hms);
	free(pirate);
}
