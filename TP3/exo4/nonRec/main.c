#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dicSearch.h"


int main(int argc, char *argv[])
{
	int value = 2;
	int tablo[6] = { 0,1, 2, 3, 4, 5};
	
    int trouver = dicSearch(tablo,value);
	if (trouver == 1)
	{
		 printf("Trouver\n");
	}
	else
	{
		printf("non Trouver\n");
	}
	
	
	return EXIT_SUCCESS;
}
					
