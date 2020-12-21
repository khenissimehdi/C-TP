#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PASS   0
#define BLOCK  1


int wc(char* str)
{
    unsigned int count = 0;
    int etat =  PASS;
    while(*str){
        
        if (*str == ' ' || *str == '\n' || *str == '\t'){
            etat = PASS;
        }
        else if(etat == PASS){
            etat = BLOCK;
            count+=1;
        }
    /* don't forget to go through the string  */
    ++str;
    }
    return count;
}

/* return 1 if the argument c is a delimiter, return 0 otherwise. */
int is_delimiter(char c){
  if ((c == ' ') || (c == '\t') || (c == '\n'))
    return 1;
  return 0;
}

/* proceed a word counting on standard input */
int wc2(void){
  char c;
  /* We initialise the previous non existant char to a delimiter since
     first non delimiter char will start a real word. */
  char prev=' '; 
  int nb_word = 0;

  while((c = getchar()) != EOF){
    if (is_delimiter(prev) && !is_delimiter(c))
      nb_word++;
    prev = c;
  }
  return nb_word;
}
