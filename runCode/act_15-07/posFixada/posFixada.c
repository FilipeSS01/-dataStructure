// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERATION 100

typedef struct stack
{
    float value;
    struct stack *next;
} Stack;

void initialize(Stack *stack);
void push(Stack *stack, float value);
float pop(Stack *stack);
void print(Stack stack);

float calcNumbers(float number1, float number2, char *operator);
void checkOperation(char operation[MAX_OPERATION], Stack *stack);

int main()
{
    Stack stack;
    char operation[MAX_OPERATION];
    initialize(&stack);
    fgets(operation, sizeof(operation), stdin);
    checkOperation(operation, &stack);
    print(stack);
    return 0;
}

void initialize(Stack *stack)
{
    // stack->value = NULL;
    stack->next = NULL;
}
void push(Stack *stack, float value)
{
    Stack *new = (Stack *)malloc(sizeof(Stack));

    if (new == NULL)
        return;

    new->value = value;
    new->next = stack->next;
    stack->next = new;
}
float pop(Stack *stack)
{
    Stack *aux = stack->next;
    float value = aux->value;

    stack->next = stack->next->next;
    free(aux);

    return value;
}
void print(Stack stack)
{
    Stack *aux = stack.next;

    if (aux == NULL)
    {
        printf("\nPilha esta vazia !");
        return;
    }
    while (aux != NULL)
    {
        printf("%.2f", aux->value);
        aux = aux->next;
    }
}
float calcNumbers(float number1, float number2, char *operator)
{
    if (strncmp(operator, "+", 1) == 0)
    {
        return number1 + number2;
    }
    else if (strncmp(operator, "-", 1) == 0)
    {
        return number1 - number2;
    }
    else if (strncmp(operator, "*", 1) == 0)
    {
        return number1 * number2;
    }
    else if (strncmp(operator, "/", 1) == 0)
    {
        return number1 / number2;
    }
    return 0;
}
void checkOperation(char operation[MAX_OPERATION], Stack *stack)
{
    const char space[2] = " ";
    char *token;
    float number1, number2, result;
    token = strtok(operation, space);
    while (token)
    {
        if ((strncmp(token, "+", 1) == 0) || (strncmp(token, "-", 1) == 0) || (strncmp(token, "*", 1) == 0) || (strncmp(token, "/", 1) == 0))
        {
            number2 = pop(&*(stack));
            number1 = pop(&*(stack));
            result = calcNumbers(number1, number2, token);
            push(&*(stack), result);
        }
        else
            push(&*(stack), atof(token));
        token = strtok(NULL, space);
    }
}
