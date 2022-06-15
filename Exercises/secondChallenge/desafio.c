// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int dado;
    struct node *next;
} Node;

typedef struct list
{
    struct node *start;
    struct node *end;
} List;

void initializeList(List *list);
void insertStart(List *list, int dado, bool isCircular);
void insertEnd(List *list, int dado, bool isCircular);

int main()
{
    List list, listCircular;
    initializeList(&list);
    initializeList(&listCircular);
    return 0;
}

void initializeList(List *list)
{
    list->start = NULL;
    list->end = NULL;
}

void insertStart(List *list, int dado, bool isCircular)
{
    Node *new = malloc(sizeof(List));
    if (new == NULL)
    {
        return;
    }
    new->dado = dado;
    if (list->start == NULL)
    {
        list->start = new;
        list->end = new;
        (isCircular) ? (list->end->next = list->start) : (list->end->next = NULL);
    }
    else
    {
        new->next = list->start;
        list->start = new;
        if (isCircular)
            list->end->next = list->start;
    }
    return;
}

void insertEnd(List *list, int dado, bool isCircular)
{
    Node *new = malloc(sizeof(List));
    if (new == NULL)
    {
        return;
    }
    new->dado = dado;
    if (list->start == NULL)
    {
        list->start = new;
        list->end = new;
        (isCircular) ? (list->end->next = list->start) : (list->end->next = NULL);
    }
    else
    {
        list->end->next = new;
        list->end = new;
        (isCircular) ? (list->end->next = list->start) : (list->end->next = NULL);
    }
    return;
}