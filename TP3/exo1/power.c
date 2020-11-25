#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int power(int entier1,int entier2)
{
    int res = 1;
    int i;
    for (i = 0; i < entier2; i++)
    {
        res*=entier1;
    }
    
  
    
  
  
    printf("%d\n",res);
 
  
    return 0;
	
}

