#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"
#include <string.h>

void print_list(List *list)
{

  List current = (*list);
  while (current != NULL)
  {
    printf("%s %s %d\n", current->first_name, current->last_name, current->age);
    current = current->next;
  }
}
int *allocate_integer_array(int size)
{
  int *new_tab;

  new_tab = (int *)malloc((size + 1) * sizeof(int));
  if (new_tab == NULL)
  {
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

Cell *allocate_cell(char *first, char *last, int age)
{
  Cell *c = (Cell *)malloc(sizeof(Cell));
  char *f = (char *)malloc(sizeof(char));
  char *l = (char *)malloc(sizeof(char));
  if (c == NULL)
  {
    printf("no memory");
    exit(1);
  }
  strcpy(f, first);
  strcpy(l, last);
  c->first_name = f;
  c->last_name = l;
  c->age = age;
  return c;
}
void ordered_insertion(List *l, Cell *new, int order_func(Cell *, Cell *))
{
  Cell *ptr;
  if (*l == NULL)
  {
    *l = new;
    return;
  }
  else if (order_func(*l, new))
  {
    new->next = *l;
    *l = new;
    return;
  }
  else
  {
    ptr = *l;
    while (ptr->next != NULL && !order_func(ptr->next, new))
      ptr = ptr->next;

    new->next = ptr->next,
    ptr->next = new;
  }
}

int age_order(Cell *p1, Cell *p2)
{
  if (p1->age > p2->age)
    return 1;
  else if (p1->age == p2->age)
    return name_order(p1, p2);
  else
    return 0;
}

int name_order(Cell *p1, Cell *p2)
{
  int cmp_last_name = strcmp(p1->last_name, p2->last_name);
  int cmp_first_name;

  if (cmp_last_name > 0)
    return 1;
  else if (cmp_last_name == 0)
  {
    cmp_first_name = strcmp(p1->first_name, p2->first_name);

    if (cmp_first_name > 0)
      return 1;
    else if (cmp_first_name == 0)
    {
      if (p1->age >= p2->age)
        return 1;
      else
        return 0;
    }
    else
      return 0;
  }
  else
  {
    return 0;
  }
}
