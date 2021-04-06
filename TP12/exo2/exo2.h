
#ifndef H_GL_HELLO
#define H_GL_HELLO
typedef struct cell
{
    char *first_name;
    char *last_name;
    int age;
    struct cell *next;
} Cell, *List;

void print_list(List *list);
Cell *allocate_cell(char *first, char *last, int age);
void ordered_insertion(List *l, Cell *new, int order_func(Cell *, Cell *));
int age_order(Cell *p1, Cell *p2);
int name_order(Cell *p1, Cell *p2);
#endif
