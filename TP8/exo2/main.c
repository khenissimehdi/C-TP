#include <stdio.h>
#include <stdlib.h>
#include "syracuse.h"


int main(void)
{
	static unsigned long int seen[200000000];
	unsigned long result;
	putchar('\n');
	
	result = flyCountMemo(27,seen);

	printf("%ld",result);
	putchar('\n');
	return EXIT_SUCCESS;
}
					
