#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fabrication.h"


/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

/* Free an integer array */
void free_integer_array(int* tab){
  free(tab);
}

/* An empty main to test the compilation of the allocation and free
   functions. */
int main()
{		


		int*array ;
		
		array = fill_array();
		putchar('\n');
		
		
		
       
    	
    	
		/*putchar('\n');
		free_integer_array(array);*/
	return EXIT_SUCCESS;
}
/* printf cheat sheet 
	%c 	character
	%d 	decimal (integer) number (base 10)
	%e 	exponential floating-point number
	%f 	floating-point number
	%i 	integer (base 10)
	%o 	octal number (base 8)
	%s 	a string of characters
	%u 	unsigned decimal (integer) number
	%x 	number in hexadecimal (base 16)
	%% 	print a percent sign
	\% 	print a percent sign

	example:
	printf("%-3d", 0);
*/
					
