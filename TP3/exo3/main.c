#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "charconv.h"


int main(int argc, char *argv[])
{

    char str = 'a';

	int res = charconv(str);
	printf("%d\n",res);
	return EXIT_SUCCESS;
}
					
