#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"
#include <string.h>

void print_list(Node *tab[])
{

  unsigned current = 0;
  while (current < 4096)
  {
    if (tab[current] != NULL)
    {

      printf("%s\n", tab[current]->word);
    }

    current++;
  }
}
int len(List *list)
{
  int len = 0;
  List current = (*list);
  while (current != NULL)
  {
    len++;
    current = current->next;
  }
  return len;
}

Node *create_node(char *word)
{
  Node *n = (Node *)malloc(sizeof(Node));
  char *f = (char *)malloc((strlen(word) + 1) * sizeof(char)); /*we don't need sizeof cause a char is one byte*/
  strcpy(f, word);
  n->word = f;
  return n;
}
int check_exist(List *lst, char *word)
{
  List current = (*lst);

  while (current != NULL)
  {

    if (strcmp(current->word, word) == 0)
    {
      return 1;
    }

    current = current->next;
  }
  return 0;
}

int check_existTAB(Node *tab[], unsigned hashcode)
{

  if (tab[hashcode] != NULL)
  {
    return 1;
  }

  return 0;
}

unsigned hash(char *elt)
{
  int i;
  unsigned h;

  h = 0;

  for (i = 0; elt[i] != '\0'; i++)
  {
    h += ((i + 1) * elt[i]);
  }

  return h % 4096;
}
void fill_list(List *lst, FILE *f, Node *tab[])
{
  char x[1024];

  Node *new;
  Node *ptr;
  /*const char *separators = " 16;:!,.?\"\0";*/
  unsigned hashcode;

  while (fscanf(f, "%s", x) == 1 /*&& strtok(x, separators)*/)
  {

    new = create_node(x);

    if (*lst == NULL)
    {
      (*lst) = new;
      ptr = (*lst);
      hashcode = hash(new->word);

      tab[hashcode] = *lst;
    }
    else
    {
      hashcode = hash(new->word);

      if (check_existTAB(tab, hashcode) != 1)
      {

        tab[hashcode] = new;
      }
      else
      {
        Node *current = tab[hashcode];
        while (current->next != NULL)
        {
          current = current->next;
        }
        current->next = new;
        current = current->next;
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
