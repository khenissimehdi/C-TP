#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

void list_append(List *list, Cell *new)
{
  List current = (*list);
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = new;
  current->next->next = NULL;
}

int main(void)
{

  char *firstName = "Mehdi";
  char *lastName = "Khenissi";
  int age = 21;

  Cell *testCell = allocate_integer_cell(firstName, lastName, age);
  Cell *testCell2 = allocate_integer_cell("Mohamed", lastName, age);
  List head = testCell;
  head->next = NULL;
  list_append(&head, testCell);
  list_append(&head, testCell2);

  return EXIT_SUCCESS;
}
