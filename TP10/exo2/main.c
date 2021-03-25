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
  List pred = NULL;
  while (current->next != NULL && strcmp(current->next->first_name, current->first_name))
  {
    /* printf(" %s %s \n", current->first_name, current->next->first_name);
      swap_mem(current, current->next, 1);*/
    current = current->next;
  }
  //new->next = new ;
  current->next = new;
  swap_mem(current, current->next, 1);

  current->next->next = NULL;
}
void list_appends(List *list, Cell *new)
{
  List current = (*list);
  List pred = NULL;
  while (current->next != NULL)
  {
    if (strcmp(current->next->first_name, current->first_name))
    {
      printf(" %s %s \n", current->first_name, current->next->first_name);
      swap_mem(current, current->next, 1);
    }

    current = current->next;
  }
  current->next = new;

  current->next->next = NULL;
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

  char *firstName = "C";
  char *lastName = "Khenissi";
  int age = 21;

  Cell *testCell = allocate_cell(firstName, lastName, age);
  Cell *testCell2 = allocate_cell("B", lastName, age);
  Cell *testCell3 = allocate_cell("A", lastName, age);
  Cell *testCell4 = allocate_cell("D", lastName, age);
  List head = testCell;
  head->next = NULL;
  list_append(&head, testCell);
  list_append(&head, testCell2);
  list_append(&head, testCell3);
  list_append(&head, testCell4);
  print_list(&head);

  char *test1 = "zlex";
  char *test2 = "arafffh";
  if (strcmp(test2, test1))
  {
    swap_mem(&test2, &test1, 1);
  }
  printf(" %s \n", test1);
  printf(" %s  \n", test2);

  printf(" my name is %s \n", head->next->first_name);

  return EXIT_SUCCESS;
}
