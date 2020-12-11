#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include "fabrication.h"


int* allocate_int_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}
int* fill_array(void){
 
    

    int size;
    int count = 0 ;
    int element;
    int* table;
    
    printf("welcome Sir !\n");
    printf("Enter a size for your array please: \n");
    scanf("%d", &size);

    table = allocate_int_array(size);
    printf("Memory have been alocated\n");
    printf("Enter  %d elements for your array please: \n",size);
    while (count != size)
    {
        printf("Enter an element please: \n");
        scanf(" %d", &element);
        table[count] = element;
        count+=1;
    }
    table[size] = -1;
    printf(" %d",table[0]);
    printf("your table is finished enjoy our service \n");
    return table ;                         

}
int* random_array(int size, int max_entry){
    int i;
    int* table;
    table = allocate_int_array(size);
    srand(time(0));
    for(i=0;i<=size;i++){
     if( i == size){
         table[i]=-1;
     }
     else
     {
        table[i]=(rand()%max_entry); 
     }
     
     
    }
    return table;
}
int* concat_array(int* first, int* second){
      int* table;
      int size ; 
      int sizeF,sizeS;
      int i;
      int j;

      sizeF = array_size(first);
      sizeS = array_size(second);
      size  = array_size(first) + array_size(second);
      table = allocate_int_array(size);
      for ( i = 0; i < sizeF; i++)
      {
          table[i] = first[i];
      }
      for ( j = 0; j < sizeS; j++)
      {
          
          table[sizeF++] = second[j];
      }
      table[size] = -1;
      return table;
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
   int* deepCopy;
   
   
   size =  array_size(array);
   
   
    deepCopy = allocate_int_array(size);
	for (i = 0; i <= size; ++i) { 
			if(i == size){
			   deepCopy[4] = -1;
			   break;
			}
            deepCopy[i] = i + 1; 
        } 
   
   return deepCopy;
}

