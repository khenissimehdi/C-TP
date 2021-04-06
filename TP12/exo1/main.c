#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo1.h"
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

  FILE *ptr = fopen("TD1-cyber-secu.txt", "r");
  List head = NULL;
  if (ptr == NULL)
  {
    printf("no such file.");
    return 0;
  }
  fill_list(&head, ptr);

  print_list(&head);
  /*int check = check_exist(&head, "non");
  printf("%d\n", check);*/

  return EXIT_SUCCESS;
}
