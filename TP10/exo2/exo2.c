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

typedef struc cell{
  char * first_name;
  char * last_name;
  int age;
  struct cell* next;
}Cell, *List 


Cell* allocate_integer_cell(char* first, char* last, int age){
   Cell* c = (Cell*)malloc(sizeof(Cell));
  if(c == NULL){
    printf("no memory");
    exit(1);
  }
  c->first_name = first;
  c->last_name = last;
  c->age = age;
  return c; 
  } 

   


void swap_mem(void * a, void * b, size_t len)
{
    char * p = a, * q = b, tmp;
    size_t i ;
    for ( i = 0; i != len; ++i)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

		
		