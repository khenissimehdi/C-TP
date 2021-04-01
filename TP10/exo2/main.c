#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"
#include <string.h>

int main(void)
{

  /*char *firstName = "C";
  char *lastName = "Khenissi";
  int age = 21;

  Cell *testCell = allocate_cell(firstName, lastName, age);
  Cell *testCell2 = allocate_cell("B", lastName, age);
  Cell *testCell3 = allocate_cell("A", lastName, age);
  Cell *testCell4 = allocate_cell("E", lastName, age);
  Cell *testCell5 = allocate_cell("D", lastName, age);
  List head = testCell;
  head->next = NULL;
  list_append(&head, testCell2);
  list_append(&head, testCell3);
  list_append(&head, testCell4);
  list_append(&head, testCell5);
  print_list(&head);*/
  List head = NULL;
  char first[50];
  char last[50];
  int age;

  FILE *ptr = fopen("liste_nom.txt", "r");
  if (ptr == NULL)
  {
    printf("no such file.");
    return 0;
  }
  while (fscanf(ptr, "%s %s %d", first, last, &age) == 3)
  {
    ordered_insertion(&head, allocate_cell(first, last, age), name_order);
  }
  print_list(&head);

  return EXIT_SUCCESS;
}
