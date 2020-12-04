#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tableaux.h"

int* allocate_int_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

int array_size(int* array){
    int y = 0; 
    while (array[y] != - 1)
    {
     y+=1;
     
    } 
    
    return y;

}

void print_array(int* array){
    int i,size;
    size = array_size(array);
    for ( i = 0; i < size; i++)
    {
        printf("%d\t",array[i]);
    }
    
}

int are_arrays_equal(int* first, int* second){
    int i,firstSize,secondSize;
    firstSize = array_size(first);
    secondSize = array_size(second);

    if (firstSize != secondSize)
    {
        return 0 ;
    }
    

    for ( i = 0; i < firstSize; i++)
    {
        if (first[i] != second[i])
        {
           return 0;
        }
        
    }
    return 1;
    
}
int* copy_array(int* array){
   int i,size;
   
   
   
   size =  array_size(array);
   
   
   int* deepCopy = allocate_int_array(5);
	for (i = 0; i <= 5; ++i) { 
			if(i == 5){
			   deepCopy[4] = -1;
			   break;
			}
            deepCopy[i] = i + 1; 
        } 
   
   return deepCopy;
}

