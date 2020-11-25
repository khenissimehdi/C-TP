#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int show1(int entier1)
{ 
  printf(" %d ", entier1); 
  if (entier1 == 1)
  {
     return 0;
  }
  show1(entier1-1);
  

}
int show2(int entier1,int fix)
{ 

  printf(" %d ", entier1); 

  if (entier1 == fix)
  {
     return 0;
  }
  show2(entier1+1,fix);
  

}
int showN(int entier1)
{ 
 show1(entier1);
 show2(entier1-entier1+1,entier1);
 printf("\n");

}

