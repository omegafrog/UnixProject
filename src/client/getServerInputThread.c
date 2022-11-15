#include "getServerInputThread.h"

extern struct ClientArgs args;
extern pthread_mutex_t mutex;
extern sem_t sem;
extern Queue q;
extern int receivedKey;
extern int id;

void *getServerInput(void *arguments)
{
    Msg msg;    
    
    while (1)
    {
        int size = 0;
        
        if ((size = msgrcv(receivedKey, &msg, sizeof(Msg), MSG_TO_CLI, 0)) > 0)
        {
            struct QueueDatum datum = {msg, id};
            pthread_mutex_lock(&mutex);
            #ifdef DEBUG
            printf("get message, size:%d", size);
            #endif
            enqueue(&q, &datum);
            pthread_mutex_unlock(&mutex);
        }
    }
}