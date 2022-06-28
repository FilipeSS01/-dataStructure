// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List
{
    Node *start;
    Node *end;
} List;

void initialize(List *list);
int insert(List *list);
int print(List list);

int main()
{
    List numbers1;
    List numbers2;
    initialize(&numbers1);
    initialize(&numbers2);

    insert(&numbers1);
    insert(&numbers2);

    print(numbers1);
    print(numbers2);
    return 0;
}

void initialize(List *list)
{
    list->start = NULL;
    list->end = NULL;
}
int insert(List *list)
{
    int value = 0;
    do
    {
        scanf("%d", &value);
        if (value != -1)
        {
            Node *aux = malloc(sizeof(Node));
            if (aux == NULL)
                return -1;
            aux->value = value;
            if (list->start == NULL)
            {
                list->start = aux;
                list->end = aux;
                aux->next = NULL;
                aux->prev = NULL;
            }
            else
            {
                list->end->next = aux;
                aux->prev = list->end;
                aux->next = NULL;
                list->end = aux;
            }
        }
    } while (value != -1);
    return 0;
}
int print(List list)
{
    Node *aux;

    if (list.start == NULL)
        return -1;
    aux = list.start;

    while (aux != NULL)
    {
        printf("%d", aux->value);
        aux = aux->next;
    }
    printf("\n");

    return 0;
}
