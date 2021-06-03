#include <stdio.h>
#include <stdlib.h>
#ifndef H_GL_HELLO
#define H_GL_HELLO
/**
 * @brief  .h file that conatains the methods and and struct of cell 
 * @note   
 * @retval 
 */
typedef struct _link
{
    long elt;
    struct _link *next;
} link;
typedef struct _stack
{
    link *top;
    int size;
} stack;
stack *create_stack(long first_elt);
/**
 * @brief  take a const pathname and a size. allocate a cell and return  pointer to a cell .
 * @note   
 * @param  *path_name: 
 * @param  size: 
 * @retval 
 */
link *allocate_link(long elt);

void push_stack(stack *s, long elt);
long pop_stack(stack *s);

/**
 * @brief  free the Stack 
 * @note   
 * @param  *Stack: 
 * @retval None
 */
void free_Stack(stack *Stack);
/**
 * @brief  show the pile 
 * @note   
 * @param  *tab[]: 
 * @retval None
 */

void print_Stack(stack *Stack);

#endif
