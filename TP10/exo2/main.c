#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"
#include <string.h>
void swap_mem(void *a, void *b, size_t len)
{
  char *p = a, *q = b, tmp;
  size_t i;
  for (i = 0; i != len; ++i)
  {
    tmp = p[i];
    p[i] = q[i];
    q[i] = tmp;
  }
}

void list_append(List *list, Cell *new)
{
  List current = (*list);
  
  if( strcmp(current->first_name ,new->first_name) && current->next == NULL ){
      printf(" im the current %s \n",current->first_name );
    current->next = new;
  }
  else{
  
  while (current->next != NULL  && strcmp(current->next->first_name ,new->first_name)  < 0 )
  {
     
    printf(" im the current %s %s %d\n",current->first_name,new->first_name,strcmp(current->first_name ,new->first_name)  );
    if(current->next != NULL){
      current = current->next ;
    }
    
    
     
       
  }

 
  new->next = current->next;
  new = current;

  current->next->next = NULL;
  }

  
}


void print_list(List *list)
{

  List current = (*list);
  while (current != NULL)
  {
    printf(" my name is %s \n", current->first_name);
    current = current->next;
  }
}

int main(void)
{

  char *firstName = "A";
  char *lastName = "Khenissi";
  int age = 21;

  Cell *testCell = allocate_cell(firstName, lastName, age);
  Cell *testCell2 = allocate_cell("C", lastName, age);
  Cell *testCell3 = allocate_cell("B", lastName, age);
  Cell *testCell4 = allocate_cell("E", lastName, age);
  Cell *testCell5 = allocate_cell("D", lastName, age);
  List head = testCell;
  head->next = NULL;
  list_append(&head, testCell2);
  list_append(&head, testCell3);
  list_append(&head, testCell5);
  list_append(&head, testCell4);
  print_list(&head);



  return EXIT_SUCCESS;
}
