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
    //don't forget to go through the string  
    ++str;
    }
    return count;
}

