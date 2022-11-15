#include "printReceivedThread.h"

extern struct QueueDatum datum;
extern sem_t sem;
extern pthread_mutex_t mutex;
void *printReceived(void *arguments)
{

    while (1)
    {
        sem_wait(&sem);
        struct QueueDatum buffer;
        pthread_mutex_lock(&mutex);
        memcpy(&buffer, &datum, sizeof(QueueDatum));
        pthread_mutex_unlock(&mutex);

        time_t tcurrent;
        char timeString[100];

        tcurrent = time(NULL);
        ctime_r(&tcurrent, timeString);
        timeString[strlen(timeString)-1]='\0';
        
       
        if (buffer.userDesc == 1)
            printf("[client2 -> client1 : %s] :%s\n", timeString, buffer.data.msg);
        else
            printf("[client1 -> client2 : %s] :%s\n", timeString, buffer.data.msg);
    }
}