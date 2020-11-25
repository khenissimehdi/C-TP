#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wc.h"


int main(int argc, char *argv[])
{

    char str[] = "windobe     hello\n hi\tbye ";

	int res = wc(str);
	printf("%d\n",res);
	return EXIT_SUCCESS;
}
					
