#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int charconv(char str)
{
   int res ;
   res = str - 'a';
   return res;
}


/* Convert a string (considered as a base 26 number) to an int */
int str_to_decimal(char* s){
  int res = 0;
  int i;

  for (i=0 ; s[i]!='\0' ; i++){
    res = 26*res + (s[i] - 'a');
  }
  return res;
}

/* Print the integer `n` in argument as a base 26 number using latin alphabet */
void print_base_26(int n){
  if (n >= 26)
    print_base_26(n/26);
  printf("%c", 'a'+(n%26));
}

/* Return 1 if `s` describe a positive number in base 10 */
int is_number(char* s){
  int i;

  for (i=0 ; s[i]!='\0' ; i++){
    if ((s[i] < '0') || (s[i] > '9'))
      return 0;
  }
  return 1;
}
