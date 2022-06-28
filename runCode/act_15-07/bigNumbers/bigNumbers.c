// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int dado;
    struct Node *next;
} Node;

typedef struct List
{
    Node *start;
    Node *end;
} List;

void initialize(List *list);
int insert(List *list, int dado);

int main()
{
    List *numbers1;
    List *numbers2;

    initialize(&numbers1);
    initialize(&numbers2);
    return 0;
}

void initialize(List *list)
{
    list->start = NULL;
    list->end = NULL;
}