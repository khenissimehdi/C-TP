#include <stdio.h>
#include <stdlib.h>

void print(int* array,int s){
    int i,size;
    size = s;
    for ( i = 0; i < size; i++)
    {
        printf("%d\t",array[i]);
    }
    
}
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

		