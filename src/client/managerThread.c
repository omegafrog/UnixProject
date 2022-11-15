#include "managerThread.h"

extern pthread_mutex_t mutex;
extern struct QueueDatum datum;
extern sem_t sem;
extern Queue q;
extern pthread_t printReceivedThread;


void* manage(void* arguments){


    int semVal = 0;
    while (1)
    {
        sem_getvalue(&sem, &semVal);
        if (semVal == 0)
        {
            if (isEmpty(&q) == 0)
            {
                #ifdef DEBUG
                printf("dequeue\n");
                #endif
                pthread_mutex_lock(&mutex);
                datum = dequeue(&q);
                pthread_mutex_unlock(&mutex);
                sem_post(&sem);
            }
        }
        

    }
}