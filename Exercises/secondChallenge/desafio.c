// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

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
