#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(int argc, char *argv[])
{

	int size ;
	int n = 4;
	stack_init();
	
	/* TDD */
	printf("size %d\n", stack_size());//3
	printf("check if its empty %d\n", stack_is_empty());//0
	printf("top value of the stack %d\n", stack_top());//1
	printf("pop %d\n", stack_pop());//1
	printf("size %d\n", stack_size());//2
	stack_push(6);
    printf("push %d\n",6);//6
	printf("size %d\n", stack_size());//3
	stack_display();// 4 5 6 
     
	
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
					
