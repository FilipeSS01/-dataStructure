// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    float dado;
    struct stack *next;
} Stack;

void initialize(Stack *stack);
int push(Stack *stack, float dado);
int pop(Stack *stack);

int main()
{

    return 0;
}

void initialize(Stack *stack)
{
    // stack->dado = NULL;
    stack->next = NULL;
}
int push(Stack *stack, float dado)
{
    Stack *new = (Stack *)malloc(sizeof(Stack));

    if (new == NULL)
        return 0;

    new->dado = dado;
    new->next = stack->next;
    stack->next = new;

    return 1;
}