#include <stdio.h>
#include <stdlib.h>
#include "exo3.h"


void print(char* array,int s){
    int i;
   
    for ( i = 0; i < s-1; i++)
    {
      printf("%s",array[i]);
    }
    
}


void free_2D_char(char* tab){ 
  int i ;
  for ( i = 0; i < SIZE_STRING; i++)
  {
     free(tab);
  }
  
 
}


		