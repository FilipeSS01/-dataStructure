// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int dado;
    struct node *next;
} Node;

typedef struct queue
{
    struct node *start;
    struct node *end;
} Queue;

void initializeQueue(Queue *queue);
void insertStart(Queue *queue, int dado, bool isCircular);
void insertEnd(Queue *queue, int dado, bool isCircular);

int main()
{
    Queue queue;
    initializeQueue(&queue);
    return 0;
}

void initializeQueue(Queue *queue)
{
    queue->start = NULL;
    queue->end = NULL;
}

void insertStart(Queue *queue, int dado, bool isCircular)
{
    Node *new = malloc(sizeof(Queue));
    if (new == NULL)
    {
        return;
    }
    new->dado = dado;
    if (queue->start == NULL)
    {
        queue->start = new;
        queue->end = new;
        (isCircular) ? (queue->end->next = queue->start) : (queue->end->next = NULL);
    }
    else
    {
        new->next = queue->start;
        queue->start = new;
        if (isCircular)
            queue->end->next = queue->start;
    }
    return;
}

void insertEnd(Queue *queue, int dado, bool isCircular)
{
    Node *new = malloc(sizeof(Queue));
    if (new == NULL)
    {
        return;
    }
    new->dado = dado;
    if (queue->start == NULL)
    {
        queue->start = new;
        queue->end = new;
        (isCircular) ? (queue->end->next = queue->start) : (queue->end->next = NULL);
    }
    else
    {
        queue->end->next = new;
        queue->end = new;
        (isCircular) ? (queue->end->next = queue->start) : (queue->end->next = NULL);
    }
    return;
}