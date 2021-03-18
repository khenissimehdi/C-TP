#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"

void fillArray(int* array,int size)
{
	int i;
	for (i = 0; i <= size-1; ++i) { 
		array[i] = i;
	}
		
}
int main(void)
{
	
	int * result;
		
	result = allocate_integer_array(13);
	
	fillArray(result,13);
	print(result,13);

	putchar('\n');

	free(result);
	return EXIT_SUCCESS;
}
					
