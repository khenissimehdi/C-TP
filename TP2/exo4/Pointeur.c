#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void print_var(int n){
  printf("Value of the variable : %d\n",n);
}
void print_pointer(int* p){
  printf("Value of the variable : %d\n",p,*p);
}
void set_pointer(int* p,int n){
  *p = n ;
}
