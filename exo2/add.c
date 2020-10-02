#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int add()
{
    int entier1;
    int entier2;
    int sum;
    printf("Enter two integer: ");
    
  
    switch(scanf("%d %d", &entier1, &entier2))
   {
   case 2 : sum = entier1 + entier2;printf("%d + %d = %d\n", entier1, entier2, sum); break;
   default : printf("your input is not an integer n");
   }
    return 0;
	
}

