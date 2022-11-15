#include "queue.h"

int init(Queue* q){
    q->front = -1;
    q->rear = -1;
    q->size = MAX_QUEUE_SIZE;
}

int isEmpty(Queue *q)
{
    return q->front==q->rear;
}

int isFull(Queue *q){
    return q->rear==q->size-1;
}

struct QueueDatum dequeue(Queue *q)
{
    if (isEmpty(q) == 0)
    {
        return q->data[++(q->front)];
    }
}
void enqueue(Queue *q, struct QueueDatum *datum)
{
    if (isFull(q) == 0)
    {
        q->data[++q->rear] = *datum;
    }
}