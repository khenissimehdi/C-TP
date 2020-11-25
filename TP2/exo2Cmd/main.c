#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "add.h"

int main(int argc, char *argv[])
{
	char *a = argv[1];
    int num = atoi(a);
	char *b = argv[2];
    int num2 = atoi(b);

	add(num,num2);
	return EXIT_SUCCESS;
}
					
