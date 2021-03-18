#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

void fillArray(int* array,int size)
{
	int i;
	for (i = 0; i <= size-1; ++i) { 
		array[i] = i;
	}
		
}
int main(void)
{
	
	char ** result;
     int i;
	result = allocate_char2D_array(7,10);
	init_tab_2d(result,7,10);
	
	print(result,7,10);

	putchar('\n');

    free_2D_char(result,7);
	
	

	
	return EXIT_SUCCESS;
}
					
