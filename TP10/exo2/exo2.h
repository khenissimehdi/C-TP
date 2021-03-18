
#ifndef H_GL_HELLO
#define H_GL_HELLO
typedef struct cell
{
    char *first_name;
    char *last_name;
    int age;
    struct cell *next;
} Cell, *List;

void print(int *array, int s);
int *allocate_integer_array(int size);
Cell *allocate_integer_cell(char *first, char *last, int age);
void ordered_insertion(List *l, Cell *new);
#endif
