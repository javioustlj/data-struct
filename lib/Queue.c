#include <stdlib.h>

#include "Queue.h"

struct QueueNode
{
    QueueElementType element;
    PtrToQueueNode next;
};

struct QueueHead
{
    PtrToQueueNode front;
    PtrToQueueNode rear;
};

Queue createQueue()
{
    return malloc(sizeof(struct QueueHead));
}

void enQueue(Queue q, QueueElementType x)
{
    PtrToQueueNode p = malloc(sizeof(struct QueueNode));
    p->element = x;
    p->next = NULL;
    q->front = p;
}

QueueElementType deQueue(Queue q)
{
    PtrToQueueNode tmp = q->rear;
    QueueElementType result = q->rear->element;
    q->rear = q->rear->next;
    free(tmp);
    return result;
}

bool isQueueEmpty(Queue q)
{
    return q->rear;
}

void deleteQueue(Queue q)
{
    PtrToQueueNode tmp;
    while (q->rear) {
        tmp = q->rear;
        q->rear = q->rear->next;
        free(q->rear);
    }
    free(q);
}
