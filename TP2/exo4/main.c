#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pointeur.h"

int main(int argc, char *argv[])
{
    int a;
    int* p = &a;
    print_var(a);
    a = 53;
    print_var(a);
    print_pointer(p);
    set_pointer(p,42);
    print_pointer(p);
    print_var(a);
	return EXIT_SUCCESS;
}
					
