#ifndef _QUEUE_H_
#define _QUEUE_H

#include <stdbool.h>

typedef int QueueElementType;
typedef struct QueueNode *PtrToQueueNode;
typedef struct QueueHead *Queue;
struct QueueNode;
struct QueueHead;

Queue createQueue();
void enQueue(Queue q, QueueElementType x);
QueueElementType deQueue(Queue q);
void deleteQueue(Queue q);
bool isQueueEmpty(Queue);

#endif
