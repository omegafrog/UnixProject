#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../header/msg.h"

#define MAX_QUEUE_SIZE 50
struct QueueDatum{
    Msg data;
    int userDesc;
}QueueDatum;

typedef struct Queue{
    int front;
    int rear; 
    int size; 
    struct QueueDatum data[MAX_QUEUE_SIZE];
}Queue;

int init(Queue* q);

int isEmpty(Queue* q);

int isFull(Queue* q);

struct QueueDatum dequeue(Queue* q);

void enqueue(Queue* q, struct QueueDatum* datum);

#endif