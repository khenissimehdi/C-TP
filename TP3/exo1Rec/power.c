#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int power(int entier1,int entier2)
{
    if( entier2 == 0 ){
        return 1;
    }
    else {
        return entier1 * power(entier1,entier2-1);
        
    }
    
}

