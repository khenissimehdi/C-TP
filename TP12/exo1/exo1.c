#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"
#include <string.h>

void print_list(List *list)
{

  List current = (*list);
  while (current != NULL)
  {
    printf("%s\n", current->word);
    current = current->next;
  }
}

Node *create_node(char *word)
{
  Node *n = (Node *)malloc(sizeof(Node));
  char *f = (char *)malloc((strlen(word) + 1) * sizeof(char)); //we don't need sizeof cause a char is one byte
  strcpy(f, word);
  n->word = f;
  return n;
}
int check_exist(List *lst, char *word)
{
  List current = (*lst);

  while (current->next != NULL)
  {

    if (strcmp(current->word, word) == 0)
    {
      return 1;
    }

    current = current->next;
  }
  return 0;
}
void fill_list(List *lst, FILE *f)
{
  char x[1024];

  Node *new;
  Node *ptr;
  const char *separators = " 16;:!,.?\"\0";

  while (fscanf(f, "%s", x) == 1 && strtok(x, separators))
  {

    new = create_node(x);
    if (*lst == NULL)
    {
      (*lst) = new;
      ptr = (*lst);
    }
    else
    {

      // printf("%s\n", new->word);
      if (check_exist(lst, new->word) != 1)
      {

        ptr->next = new;
        ptr = ptr->next;
      }
    }
  }
}
void read_words(FILE *f)
{
  char x[1024];

  while (fscanf(f, " %s", x) == 1)
  {
    puts(x);
  }
}
