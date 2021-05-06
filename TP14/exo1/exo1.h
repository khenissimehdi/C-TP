#include <stdio.h>
#include <stdlib.h>
#ifndef H_GL_HELLO
#define H_GL_HELLO
/**
 * @brief  .h file that conatains the methods and and struct of cell 
 * @note   
 * @retval 
 */
typedef struct cell
{
    char *path_name;
    int size;
    struct cell *next;
} Cell, *List;
/**
 * @brief  take a list and print the first biggest ten files .
 * @note   
 * @param  *list: 
 * @retval None
 */
void print_first_10(List *list);

/**
 * @brief  take a const pathname and a size. allocate a cell and return  pointer to a cell .
 * @note   
 * @param  *path_name: 
 * @param  size: 
 * @retval 
 */
Cell *allocate_cell(const char *path_name, int size);

/**
 * @brief  take a List pointer a new cell and a pointer to a function 
 * * and order the list using it.
 * @note   
 * @param  *l: 
 * @param  *newcell: 
 * @param  *: 
 * @param  *: 
 * @retval None
 */
void ordered_insertion(List *l, Cell *newcell, int order_func(Cell *, Cell *));

/**
 * @brief  take two pointers to cells and return 1 if p1 is bigger
 * * than p2 0 if its not the case. 
 * @note   
 * @param  *p1: 
 * @param  *p2: 
 * @retval 
 */
int great_order(Cell *p1, Cell *p2);

/**
 * @brief  free the list 
 * @note   
 * @param  *list: 
 * @retval None
 */
void free_list(List *list);

#endif
