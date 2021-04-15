#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"

int main(void)
{

  int z1 = 2;
  int z2 = 3;
  void *a = &z1;
  void *b = &z2;
  swap_mem(a, b, 1);

  printf(" Im z1 %d", z1);
  printf(" Im z2 %d", z2);

  return EXIT_SUCCESS;
}
