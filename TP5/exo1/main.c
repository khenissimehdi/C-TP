#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tableaux.h"


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
void fillArray(int* array,int a)
{
	int i;
	for (i = 0; i <= 5; ++i) { 
			if(i == 5){
			   array[4] = -1;
			   break;
			}
            array[i] = i + 1; 
        } 
	if(a == 1){
		 array[2] = 6;
	}
}
/* An empty main to test the compilation of the allocation and free
   functions. */
int main()
{		
		
		int* array = allocate_integer_array(5);
		int* array2 = allocate_integer_array(5);
		
		int* copyArray;
		int res,same,notSame; 
    	
		fillArray(array,0);
		fillArray(array2,1);
		
		res = array_size(array);

		printf(" the size array is %d\n",res);
		printf(" the array is\n");
		print_array(array);
		putchar('\n');

		same = are_arrays_equal(array,array);
		if(same == 1){
			printf("yes it's the same !");
		}
		else
		{
			printf("no its not the same  !");
		}
		putchar('\n');
		notSame = are_arrays_equal(array,array2);
		if(notSame == 1){
			printf("yes it's the same !");
		}
		else
		{
			printf("no its not the same  !");
		}
		putchar('\n');
		copyArray = copy_array(array);
		putchar('\n');
		print_array(copyArray);
		putchar('\n');
	
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
					
