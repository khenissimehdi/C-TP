#include <stdio.h>
#include <stdlib.h>
#include "syracuse.h"


int main(void)
{
	static unsigned long int seen[200000000];
	putchar('\n');
	flyCountMemo(12,seen);
	printf("%ld",seen[12]);
	putchar('\n');
	return EXIT_SUCCESS;
}
					
