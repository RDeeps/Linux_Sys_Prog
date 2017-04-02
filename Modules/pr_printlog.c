// Printing kernel ring buffer (e.g. appn-> dmesg)

#include<sys/klog.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int len, level;
	char *buf;
	int last = '\n';
	int in = 0;

	len = klogctl(10, NULL, 0);		//READ RING BUFFER LENGTH
	if(len < 16 * 1024)
		len = 16 * 1024;
	if(len > 16 * 1024 * 1024)
		len = 16 * 1024 * 1024;
	
	buf = malloc(len);
	if(!buf)
	{
		printf("Cannot allocate memory\n");
		return 0;
	}

	len = klogctl(3, buf, len);
	if(len<0)
	{
		printf("Cannot read the buffer\n");
		free(buf);
		return 0;
	}
	if(len == 0)
	{
		return 0;
	}
	
	//skip <#> at start of lines
	while(1)
	{
		if(last == '\n' && buf[in] == '<'){
			in += 3;
			if(in >= len)
				break;
		}
		last = buf[in];
		putchar(last);
		in++;
		if(in >= len)
			break;
	}

	if(last != '\n')
		putchar('\n');
	
	free(buf);
	
	return 0;

}
