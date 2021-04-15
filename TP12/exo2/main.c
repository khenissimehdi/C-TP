#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo2.h"
#define NB_PACK 4096

Node *tab[NB_PACK];
void initTab(Node *tab[])
{
  int i;
  for (i = 0; i < NB_PACK; i++)
  {
    tab[i] = NULL;
  }
}
void readd_words(FILE *f)
{
  char x[1024];

  while (fscanf(f, " %s", x) == 1)
  {
    puts(x);
  }
}

int main(void)
{

  FILE *ptr = fopen("Germinal.txt", "r");
  List head = NULL;
  if (ptr == NULL)
  {
    printf("no such file.");
    return 0;
  }
  initTab(tab);
  fill_list(&head, ptr, tab);

  /*print_list(tab);*/
  /*printf(" %d different words found in %s \n", len(&head), head->word);*/
  /*int check = check_exist(&head, "non");*/
  /*printf("%s\n", tab[2755]->next->word);*/

  return EXIT_SUCCESS;
}
