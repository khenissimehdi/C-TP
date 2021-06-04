#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "operation.h"

void addition(stack *s)
{
    long a = pop_stack(s);
    long b = pop_stack(s);
    long res = a + b;
    push_stack(s, res);
    printf("%ld \n", res);
}

void soustraction(stack *s)
{
    long a = pop_stack(s);
    long b = pop_stack(s);
    long res = a - b;
    push_stack(s, res);
    printf("%ld \n", res);
}
void product(stack *s)
{
    long a = pop_stack(s);
    long b = pop_stack(s);
    long res = a * b;
    push_stack(s, res);
    printf("%ld \n", res);
}

void quotient(stack *s)
{
    long a = pop_stack(s);
    long b = pop_stack(s);
    long res = a / b;
    push_stack(s, res);
    printf("%ld \n", res);
};

void expo(stack *s)
{
    long a = pop_stack(s);
    long b = pop_stack(s);
    long res = (long)pow(b, a);
    push_stack(s, res);
    printf("%ld \n", res);
}

void modulo(stack *s)
{
    long a = pop_stack(s);
    long b = pop_stack(s);
    long res = a % b;
    push_stack(s, res);
    printf("%ld \n", res);
}

void factorial(stack *s)
{
    long accum = 1;
    long n = pop_stack(s);

    while (n >= 2)
        accum *= n--;
    push_stack(s, accum);
    printf("%ld \n", accum);
}