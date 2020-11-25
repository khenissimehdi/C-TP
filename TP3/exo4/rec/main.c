#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dicSearch.h"


int main(int argc, char *argv[])
{
	int value = 8;
	int tablo[6] = { 0,1, 2, 3, 4, 5};
	
    dicSearch(tablo,value);
	
	
	return EXIT_SUCCESS;
}
					
