#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

static Stack stack;

void stack_init(void){
   
    stack.values[0] = 1;
    stack.values[1] = 4;
    stack.values[2] = 5;
     stack.size = 3;
}
int stack_size(void){
   
    return stack.size;
}
int stack_is_empty(void){
    if(stack_size() == 0){
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int stack_top(void){
    return stack.values[0];
}
int stack_pop(void){
    int top_element = stack.values[0];
    int i;
     for(i=0; i<MAX_SIZE-1; i++)
        {
            stack.values[i] = stack.values[i + 1];
        }
    stack.size -=1;
    return top_element;
}
void stack_push(int n){
    printf("%d\n",stack.size);
    stack.values[stack.size] = n;
    stack.size +=1;
}
void stack_display(void){
int i ;
for(i=0; i<MAX_SIZE; i++)
 {
    printf("%d\t", stack.values[i]);
}
printf("\n");
}
